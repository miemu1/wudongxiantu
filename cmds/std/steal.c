// steal.c

#include <ansi.h>
#include <config.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object env;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	env = environment(me);
	if (env->query("no_fight"))
		return notify_fail("这里禁止行窃。\n");

	if (env->query("no_steal"))
		return notify_fail("这里禁止行窃。\n");

	if (me->query_temp("stealing"))
		return notify_fail("你已经在找机会下手了！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙，没有时间。\n");

	if (! arg )
		return notify_fail("你要偷谁？\n");

	if (sscanf(arg, "%s from %s", what, who) != 2)
	{
		who = arg;
		what = "money";
	}
	victim = present(who, environment(me));
	if (! victim || victim == me)
		return notify_fail("你想行窃的对象不在这里。\n");

	if (! victim->is_character() || victim->is_corpse())
		return notify_fail("你看清楚了，那不是活人！");

	if (victim->query_competitor())
		return notify_fail("人家正在比武，你捣什么乱？\n");

	if (! wizardp(me) && wizardp(victim))
		return notify_fail("玩家不能偷巫师身上的东西。\n");

	if ((me->query("age")<10 || me->query("combat_exp",1)<200000) && userp(victim))
		return notify_fail("小小年纪就学人偷东西？还是少干点缺德事吧。\n");

	if ((victim->query("age")<10 || victim->query("combat_exp",1)<200000) && userp(victim))
		return notify_fail("连小朋友的东西都要偷？你还真是缺德呀。\n");

	if (me->query("jing") < 80)
		return notify_fail("你现在难以集中精神，不敢贸然下手偷窃。\n");

	if (! ob = present(what, victim))
	{
		object *inv;
		inv = all_inventory(victim);
		if (! sizeof(inv))
			return notify_fail(victim->name() + "身上看起来没有什麽值钱的东西好偷。\n");
		ob = inv[random(sizeof(inv))];
	}

	sp = (int)me->query_skill("stealing") * 5 - (int)me->query("thief") * 20;

	if ((myfam = me->query("family")) && myfam["family_name"] == "丐帮")
		sp = (int)me->query_skill("stealing") * 10 - (int)me->query("thief") * 20;

	if (sp < 1) sp = 1;

	if (me->is_fighting())
	{
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("jing") * 2 + (int)ob->weight() / 25;
	if (victim->is_fighting()) dp *= 10;
	if (ob->query("equipped")) dp *= 20;

	write("你不动声色地慢慢靠近" + victim->name() + "，等待机会下手 ...\n\n");

	me->set_temp("stealing", 1);
	me->start_call_out((: call_other, __FILE__, "compelete_steal", me, victim, ob, sp, dp :), 3);

	return 1;
}

void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
	mapping myfam, vtfam;
	int steal_level;

	if (! objectp(me))
		return;

	me->delete_temp("stealing");

	if (! objectp(victim) || environment(victim) != environment(me))
	{
		tell_object(me, "太可惜了，你下手的目标已经走了。\n");
		return;
	}

	if (! objectp(ob))
		return;

	if (environment(ob) != victim)
	{
		tell_object(me, "你摸了半天，发现" + ob->name() +
			    "已经不在那里了。\n");
		return;
	}

	if (! living(victim) || (random(sp + dp) > dp))
	{
		if (victim->query_temp("is_riding") == ob)
		{
			tell_object(me, "你摸到了" + victim->name() + "坐骑" + ob->name() +
				    "，想了想，还是老老实实的放了手。\n");
			return;
		}

		if (!ob->query("is_money"))
		{
			tell_object(me, "你摸到一" + ob->query("unit") + ob->name() +
				    "，可是你突然作贼心虚，居然不敢下手，真是可惜了。\n");
			return;
		}

		if (sizeof(all_inventory(me)) >= MAX_ITEM_CARRIED)
		{
			tell_object(me, "眼看你就要得手，可惜身上的东"
				    "西太多，实在拿不了了。\n");
			ob->move(environment(me));
			return;
		}

		if (! ob->move(me))
		{
			tell_object(me, "你摸到一" + ob->query("unit") + ob->name() +
				    "，可是对你而言太重了，不得不放弃。\n");
			return;
		}

		tell_object(me, HIW "得手了！"NOR"\n");
		tell_object(me, "你成功地偷到一" + ob->query("unit") +
			    ob->name() + "！\n");
		steal_level = (int)me->query_skill("stealing",1);

		if (living(victim))
		{
			if (me->can_improve_skill("stealing"))
				me->improve_skill("stealing", random(me->query("int")));

			if ((int)me->query("potential") < me->query_potential_limit())
			me->add("potential", 1);

			me->add("thief", 1);
			me->receive_damage("jing", 10);
			me->add("combat_exp",1);
		}

		if (random(sp) < dp / 2)
			message("vision", "你看到" + me->name() + "鬼鬼祟祟地从" +
				victim->name() + "身上偷走了一" + ob->query("unit") +
				ob->name() + "！\n", environment(me), ({ me, victim }));
	} else
	{
		if (random(sp) > dp / 2)
		{
			tell_object(me, victim->name() + "不经意地一转头，你"
				    "急忙将手缩了回去！\n还好，没有被发现！\n");
			return;
		}

		tell_object(me, HIR "糟糕！你失手了！"NOR"\n");
		message_vision("$N一回头，正好发现$n的手正抓着$P身上的" +
			       ob->name() + "！\n$N喝道：「干什么！」\n",
			       victim, me);
		me->improve_skill("stealing", 1, 1);

		if (userp(victim))
		{
			message_vision("$N狠狠的敲着$n的头，吓得$n呜呜直叫。\n",
				       victim, me);
		} else
		{
			victim->kill_ob(me);
			me->fight_ob(victim);
		}

		if (! me->is_busy()) me->start_busy(3);
		me->add("thief", 1);
		me->receive_damage("jing", 15 + random(10));
	}
}

int help(object me)
{
	write(@HELP
指令格式 : steal <某物> from <某人>

这个指令让你有机会偷到他人身上的东西。成功了, 当然你就能获得
该样物品。可是, 马有失蹄, 人总有失风的时候, 当你失败时当然就
得付出代价, 至於是什么代价......靠你自己去发掘罗。
HELP );
	return 1;
}
