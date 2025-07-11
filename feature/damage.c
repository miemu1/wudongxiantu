// damage.c

#include <ansi.h>
#include <dbase.h>
#include <move.h>
#include <login.h>
#include <action.h>
#include <condition.h>

static object last_damage_from = 0;
static string last_damage_name = 0;
static object defeated_by      = 0;
static string defeated_by_who  = 0;

object query_last_damage_from() { return last_damage_from; }
string query_last_damage_name() { return last_damage_name; }
object query_defeated_by()      { return defeated_by; }
string query_defeated_by_who()  { return defeated_by_who; }

int ghost = 0;
int PVP_DAMAGE_SCALE = 70;
int PVP_WOUND_SCALE  = 60;

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, object who)
{
	
int val, n;
        int avoid;
        function f;
        int a, r;
        object *bugs, jcg;
	if (damage < 0) error("F_DAMAGE: 伤害值为负值。\n");
	if (type != "jing" && type != "qi")
		error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");
 if( (query_temp("buffup/backfire") == type || query_temp("buffup/backfire") == "all") 
            && who && !query_temp("bonus/backfire_damage") ) {
           
                set_temp("bonus/backfire_msg",1);
          
                if( a < 0 ) a = 0;
                if( a > 100 ) a = 100;
                who->receive_damage(type,damage / 100 * a, this_object()); // 防止负值
             
          
        }
	if (who != last_damage_from)
	{
		last_damage_name = (who ? who->name(1) : 0);
		last_damage_from = who;
	}

	if (who && damage > 150)
		this_object()->improve_craze(damage / 5);

	val = (int)query(type) - damage;

	if (val >= 0) set(type, val);
	else set(type, -1);

	set_heart_beat(1);

	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
	int val, n;
        int avoid;
        function f;
        int a, r;
        object *bugs, jcg;

	if (damage < 0) error("F_DAMAGE: 伤害值为负值。\n");
	if (type != "jing" && type != "qi")
		error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");
if( (query_temp("buffup/backfire") == type || query_temp("buffup/backfire") == "all") 
            && who && !query_temp("bonus/backfire_damage") ) {
           
                set_temp("bonus/backfire_msg",1);
          
                if( a < 0 ) a = 0;
                if( a > 100 ) a = 100;
                who->receive_damage(type,damage / 100 * a, this_object()); // 防止负值
             
          
        }
	if (who != last_damage_from)
	{
		last_damage_name = (who ? who->name(1) : 0);
		last_damage_from = who;
	}

	if (who && damage > 150)
		this_object()->improve_craze(damage / 3);

	val = (int)query("eff_" + type) - damage;

	if (val >= 0) set("eff_" + type, val);
	else
	{
		set( "eff_" + type, -1 );
		val = -1;
	}

	if ((int)query(type) > val) set(type, val);

	set_heart_beat(1);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if (heal < 0) error("F_DAMAGE: 恢复值为负值。\n");
	if (type != "jing" && type != "qi")
		error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");

	val = (int)query(type) + heal;

	if (val > (int)query("eff_" + type))
		set(type, (int)query("eff_" + type));
	else set(type, val);

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if (heal < 0) error("F_DAMAGE: 恢复值为负值。\n");
	if (type != "jing" && type != "qi")
		error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");

	val = (int)query("eff_" + type);
	if(type == "qi")
		max = (int)query("max_" + type)+this_object()->query_gain_qi();
	else if(type == "jing")
		max = (int)query("max_" + type)+this_object()->query_gain_jing();
	else
		max = (int)query("max_" + type)+query("gain/max_" + type);

	if (val + heal > max)
	{
		set("eff_" + type, max);
		return max - val;
	} else
	{
		set( "eff_" + type, val + heal);
		return heal;
	}
}

int dps_count()
{
	int i;
	object *dp;

	dp = query_temp("defeat_player");
	if (! dp) return 0;
	for (i = 0; i < sizeof(dp); i++)
		if (dp[i] && living(dp[i])) dp[i] = 0;
	dp -= ({ 0 });
	set_temp("defeat_player", dp);
	return sizeof(dp);
}

void record_dp(object ob)
{
	object *dp;

	if (! this_object()->is_want_kill(ob->query("id")))
		// only if I want kill ob, I will record it.
		return;

	dp = query_temp("defeat_player");
	if (! dp) dp = ({ });
	dp += ({ ob });
	set_temp("defeat_player", dp);
}

void remove_dp(object ob)
{
	object *dp;

	if (! ob)
	{
		// remove all player defeated by me
		delete_temp("defeat_player");
		return;
	}

	dp = query_temp("defeat_player");
	if (! dp) return;
	dp -= ({ ob, 0 });
	set_temp("defeat_player", dp);
}

void unconcious()
{
	object me;
	object ob;
	object room, *inv;
	object riding;
	string applyer;
	string owner_id;
	int n;
	int i;
	mapping my;

	me = this_object();
	if (! living(me)) return;
	if (wizardp(me) && query("env/immortal")) return;

	// I am lost if in competition with others
	if (objectp(ob = me->query_competitor()) && ! ob->is_killing(me->query("id")))
	{
		ob->win();
		me->lost();
	}

	if (me->is_busy()) me->interrupt_me();

	if (run_override("unconcious")) return;

	if (userp(me)&&environment(me)->query("out_room"))
	{
		if(me->query("qi")<1) me->set("qi",1);
		if(me->query("eff_qi")<1) me->set("eff_qi",1);
		if(me->query("jing")<1) me->set("jing",1);
		if(me->query("eff_jing")<1) me->set("eff_jing",1);
		environment(me)->no_die(me);
		me->move(environment(me)->query("out_room"));
		return;
	}

	if (! last_damage_from && (applyer = query_last_applyer_id()))
	{
		last_damage_from = UPDATE_D->global_find_player(applyer);
		last_damage_name = query_last_applyer_name();
	}

	defeated_by_who = last_damage_name;
	if (defeated_by = last_damage_from)
	{
		object *dp;

		// 如果此人有主，则算主人打晕的
		if (objectp(defeated_by->query_temp("owner")))
		{
			defeated_by = defeated_by->query_temp("owner");
			defeated_by_who = defeated_by->name(1);
		} else
		if (stringp(owner_id = defeated_by->query_temp("owner_id")))
		{
			defeated_by = UPDATE_D->global_find_player(owner_id);
			if (objectp(defeated_by))
				defeated_by_who = defeated_by->name(1);
		}

		if (query("qi") < 0 || query("jing") < 0)
			COMBAT_D->winner_reward(defeated_by, me);

		// 如果对方有意杀害我，则我愤怒，并且对方累积杀气。
		if (playerp(me) && defeated_by->is_want_kill(me->query("id")))
		{
			defeated_by->record_dp(me);
			me->craze_of_defeated(defeated_by->query("id"));
			n = 100 + random(100) + me->query_skill("force");
			if (n > defeated_by->query_skill("force"))
				n = defeated_by->query_skill("force") / 2 +
				    random(defeated_by->query_skill("force") / 2);
			defeated_by->add("total_hatred", n);
		}
	}

	me->remove_all_enemy(0);

	// notice the write_prompt function: do not show prompt
	me->clear_written();

	message("vision", HIR "\n你的眼前一黑，进入昏死状态...."NOR"\n",me);
	
	me->disable_player(" <昏迷不醒>");
	me->delete_temp("sleeped");
	 
	if (objectp(riding = me->query_temp("is_riding")))
	{
		message_vision("$N一头从$n上面栽了下来！\n",
			      me, riding);
		me->delete_temp("is_riding");
		riding->delete_temp("is_rided_by");
		riding->move(environment(me));
	}

	set("jing", 0);
	set("qi", 0);
//	set_temp("block_msg/all", 1);

	call_out("revive", random(100 - query("con")) + 30);
	COMBAT_D->announce(me, "unconcious");

	// remove the user if loaded by updated
	UPDATE_D->global_destruct_player(defeated_by, 1);
}

varargs void revive(int quiet)
{
	int i;
	object me;
	object env;

	me = this_object();

	remove_call_out("revive");
	env = environment();
	if (env)
	{
		while (env->is_character() && environment(env))
			env = environment(env);
		if (env != environment())
			me->move(env);
	}
	delete("disable_type");
	set_temp("block_msg/all", 0);
	me->enable_player();

	// write the prompt
	me->write_prompt();

	if (objectp(defeated_by))
		defeated_by->remove_dp(me);

	if (! quiet)
	{
		defeated_by = 0;
		defeated_by_who = 0;
		COMBAT_D->announce(this_object(), "revive");
		message("vision", HIY "\n慢慢地你终于又有了知觉...."NOR"\n",
			me);
	}

	last_damage_from = 0;
	last_damage_name = 0;
}

varargs void die(object killer)
{
	object me;
	object corpse, room, obj, *inv;
	object riding;
	object dob;
	object ob,kuilei;
	string dob_name;
	string killer_name;
	string applyer,startroom;
	object tmp_load;
	int direct_die;
	int i,time;
	int duration;

	me = this_object();       
	me->delete_temp("sleeped");
	me->delete("last_sleep");

	if (ob = me->query_competitor())
	{
		ob->win();
		me->lost();
	}

	if (wizardp(me) && query("env/immortal"))
	{
		delete_temp("die_reason");
		return;
	}

	if (me->is_busy()) me->interrupt_me();

	if (run_override("die")) return;

	if (userp(me)&&environment(me)->query("out_room"))
	{
		if(!living(me)) revive(1);
		if(me->query("qi")<1) me->set("qi",1);
		if(me->query("eff_qi")<1) me->set("eff_qi",1);
		if(me->query("jing")<1) me->set("jing",1);
		if(me->query("eff_jing")<1) me->set("eff_jing",1);
		environment(me)->no_die(me);
		me->move(environment(me)->query("out_room"));
		return;
	}

	if(me->query("combat_exp")>=1500000&&objectp(kuilei=present("tishen kuilei",me)))
	{
		kuilei->add_amount(-1);
		me->set_temp("kuilei_used",1);
		me->add("kuilei_used",1);
	}

	if (! last_damage_from && (applyer = query_last_applyer_id()))
	{
		tmp_load = UPDATE_D->global_find_player(applyer);
		last_damage_from = tmp_load;
		last_damage_name = query_last_applyer_name();
	}

	if (! killer)
	{
		killer = last_damage_from;
		killer_name = last_damage_name;
	} else
		killer_name = killer->name(1);

	// record defeater first, because revive will clear it
	if (! living(me))
	{
		direct_die = 0;
		if (userp(me) || playerp(me))
			revive(1);
		else
			me->delete("disable_type");
	} else
		direct_die = 1;

	if (direct_die && killer)
		// direct to die ? call winner_reward
		COMBAT_D->winner_reward(killer, me);

	if (objectp(riding = me->query_temp("is_riding")))
	{
		message_vision("$N一头从$n上面栽了下来！\n",
			       me, riding);
		me->delete_temp("is_riding");
		riding->delete_temp("is_rided_by");
		riding->move(environment(me));
	}

	// Check how am I to die
	dob = defeated_by;
	dob_name = defeated_by_who;
	if (! query_temp("die_reason"))
	{
		if (userp(me) && dob_name && killer_name &&
		    (dob_name != killer_name || dob != killer))
		{
			// set the die reason
			set_temp("die_reason", "被" +
		      		 dob_name + "打晕以后，被" +
		      		 (dob_name == killer_name ? "另一个" : "") +
		      		 killer_name + "趁机杀掉了");
		} else
		if (userp(me) && killer_name && ! killer)
		{
			set_temp("die_reason", "被" + killer_name + HIM "杀害了");
		}
	}

	if (COMBAT_D->player_escape(killer, this_object()))
	{
		UPDATE_D->global_destruct_player(tmp_load, 1);
		return;
	}

	if(me->query_temp("kuilei_used"))
		COMBAT_D->announce(me, "kuilei");
	else
		COMBAT_D->announce(me, "dead");

	if (objectp(killer))
		set_temp("my_killer", killer->query("id"));

	COMBAT_D->killer_reward(killer, me);

	// remove the user if loaded by updated
	UPDATE_D->global_destruct_player(tmp_load, 1);

	if(!me->query_temp("kuilei_used"))
		me->add("combat/dietimes", 1);

	if (!me->query_temp("kuilei_used")&&objectp(corpse = CHAR_D->make_corpse(me, killer)))
		corpse->move(environment());

	defeated_by = 0;
	defeated_by_who = 0;
	me->remove_all_killer();
	all_inventory(environment())->remove_killer(me);

	me->dismiss_team();
	if (userp(me) || playerp(me))
	{
		if (me->is_busy())
			me->interrupt_me();
		set("jing", 1); set("eff_jing", 1);
		set("qi", 1);   set("eff_qi", 1);
		if(me->query_temp("kuilei_used"))
		{
			me->move("/d/city/wumiao");
			me->delete_temp("kuilei_used");
		}
		else
		{
			ghost = 1;
			me->move(DEATH_ROOM);
			DEATH_ROOM->start_death(me);
		}
		me->delete_temp("die_reason");
		me->craze_of_die(killer ? killer->query("id") : 0);

		// add by chenzzz，死亡保护
		me->set("die_protect/last_dead", time());
		me->set("die_protect/duration", 2 * 60 * 60);
	}
	else
	{
		if(objectp(room=me->query("resetroom"))&&!clonep(room))
		{
			if(!(time=me->query("load_time")))
			{
				time = 900;
			}
			room->load_npc(base_name(me),time);
		}
		destruct(me);
	}
}

void reincarnate()
{
	ghost = 0;
	set("eff_jing", query("max_jing"));
	set("eff_qi", query("max_qi")+this_object()->query_gain_qi());
}

int max_food_capacity() { return query("str") * 10 + 100; }

int max_water_capacity() { return query("str") * 10 + 100; }

int heal_up()
{
	int update_flag, i;
	int scale;
	int is_user;
	mapping my;
	object me;
	mixed guard;

	// Update the affect of nopoison
	if (query_temp("nopoison"))
		delete_temp("nopoison");

	me = this_object();
	// Am I in prison ?
	if (me->is_in_prison())
	{
		me->update_in_prison();
		return 1;
	}

	is_user = playerp(me);
	scale = living(me) ? 1 : (is_user ? 4 : 8);
	update_flag = 0;
	my = query_entire_dbase();

	if (! is_user || environment() && ! environment()->is_chat_room() && (! stringp(my["doing"]) && interactive(me) ))
	{
		if (my["water"] > 0) { my["water"] -= 1; update_flag++; }
		if (my["food"] > 0 ) { my["food"] -= 1; update_flag++; }

		if (my["water"] < 1 && is_user)
			return update_flag;

		if ((guard = me->query_temp("guardfor")) && (! objectp(guard) || ! guard->is_character()))
		{
			if (my["jing"] * 100 / my["max_jing"] < 50)
			{
				tell_object(me, "你觉得太累了，需要放松放松了。\n");
				command("guard cancel");
				return update_flag;
			}

			my["jing"] -= 30 + random(20);
			switch (random(8))
			{
			case 0: message_vision("$N紧张的盯着四周来往的行人。\n", me);
				break;

			case 1: message_vision("$N打了个哈欠，随即振作精神继续观察附近情况。\n", me);
				break;

			case 2: message_vision("$N左瞅瞅，右看看，不放过一个可疑的人物。\n", me);
				break;

			case 3: message_vision("$N打起精神细细的观察周围。\n", me);
				break;
			}
			update_flag++;
			return update_flag;
		}

		my["jing"] += (my["con"] + my["max_jingli"] / 10) / scale;
		if (my["jing"] >= my["eff_jing"])
		{
			my["jing"] = my["eff_jing"];
			if (my["eff_jing"] < my["max_jing"])
			{
				my["eff_jing"] ++;
				update_flag++;
			}
		} else update_flag++;

		if (! me->is_busy())
			my["qi"] += (my["con"] * 2 + my["max_neili"] / 20) / scale;

		if (my["qi"] >= my["eff_qi"])
		{
			my["qi"] = my["eff_qi"];
			if (my["eff_qi"] < (my["max_qi"]+me->query_gain_qi()))
			{
				my["eff_qi"] ++;
				update_flag++;
			}
		} else update_flag++;

		if (my["food"] < 1 && is_user)
			return update_flag;

		if (my["max_jingli"] && my["jingli"] < my["max_jingli"])
		{
			my["jingli"] += my["con"] + (int)me->query_skill("force") / 6;
			if (my["jingli"] > my["max_jingli"])
				my["jingli"] = my["max_jingli"];
			update_flag++;
		}

		if (my["max_neili"] && my["neili"] < my["max_neili"])
		{
			my["neili"] += my["con"] * 2 + (int)me->query_skill("force") / 3;
			if (my["neili"] > my["max_neili"])
				my["neili"] = my["max_neili"];
			update_flag++;
		} 

	}

	return update_flag;
}
