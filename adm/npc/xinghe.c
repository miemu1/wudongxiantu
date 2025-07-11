// chuniang.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

string ask_job();

int  do_cook(string arg);
int  cooking(object me);
int  halt_cooking(object me);

void create()
{
	set_name("鸽鸽公主", ({"xinghe", "xing", "he"}));
	set("long", "她长得方离柳坞，乍出花房。但行处，
	鸟惊庭树；将到时，影度回廊。仙袂乍飘兮，闻麝岚之馥郁；
	荷衣欲动兮，听环佩之铿锵。靥笑春桃兮，云堆翠髻；唇绽樱颗兮，
	榴齿含香。纤腰之楚楚兮，回风舞雪；珠翠之辉辉兮，满额鹅黄。出没花间兮，
	宜嗔宜喜；徘徊池上兮，若飞若扬。蛾眉颦笑兮，将言而未语；莲步乍移兮，待止而欲行。
	羡彼之良质兮，冰清玉润；慕彼之华服兮，烧灼文章。爱彼之貌容兮，香培玉琢；美彼之态度兮，
	凤翥龙翔。其素若何，春梅绽雪。其洁若何，秋菊被霜。其静若何，松生空谷。其艳若何，霞映澄塘。
	其文若何，龙游曲沼。其神若何，月射寒江。应惭西子，实愧王嫱。" );
	set("gender", "女性");
	set("age", 14);
	set("no_get", 1);
	set("attitude", "friendly");

	set("inquiry",([
		"双修" : (: ask_job :),
	]));

	set("age", 30);

	set("str", 21);
	set("skill_chuniang", 1);
	set("int", 22);
	set("con", 30);
	set("dex", 21);

	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);

	set("vendor_goods", ({
		"/clone/misc/TT",
	}));

	setup();
}

void init()
{
	add_action("do_cook", "cook");
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void auto_cook(object me)
{
	if(!me||!interactive(me)) return;
	if(!me->query_temp("pending/auto_cook"))
		return;
	if(me->is_busy())
		call_out("auto_cook",1,me);
	else if( (int)me->query("jing") < me->query("eff_jing"))
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < me->query("eff_jing"))
			{
				tell_object(me,"精力不足，等待恢复中。。。\n");
				call_out("auto_cook",1,me);
			}
			else
			{
				call_out("auto_cook",1,me);
			}
		}
		else
		{
			tell_object(me,"精力不足，等待恢复中。。。\n");
			call_out("auto_cook",1,me);
		}
	}
	else
	{
		tell_object(me,"托管中，继续双修。。。。。。\n");
		tell_object(me,ZJFORCECMD("ask "+this_object()->query("id")+" about 双修"));
	}
}

string ask_job()
{
	object me;
	object *obs;

	me = this_player();

	if (me->query("combat_exp") < 1000)
		return "呦，你这点本事啊，还能动吗么？";

	if (me->query("jing") < 50) 
		return "你还是休息会儿吧，小心把身子累垮了！";

	if (me->query("combat_exp") > 2500000)
		return "这位女侠，你这不是折杀小的吗！";

	if (me->query_skill("cooking") < 30)
		return "你的技术那么差，那里能帮我？";

	if (me->query_skill_mapped("cooking") != "chuancai-jiyi")
		return "我说你知不知道我可是很挑剔的，亮出你绝活再说！";

	if (! interactive(me))
		return "...";

	obs = filter_array(all_inventory(environment()),
			   (: interactive($1) &&
			      $1 != $(me) &&
			      $1->query_temp("job/cook") &&
			      query_ip_number($1) == query_ip_number($(me)) :));
	//if (sizeof(obs) > 0)
	//	return "这儿有" + obs[0]->name() + "呢，你还是别费心了。";

	me->set_temp("job/cook", 1);
	tell_object(me,ZJFORCECMD("cook"));
	tell_object(me,ZJEXIT"northwest:"RED"中断双修"NOR":halt\n");
	return "好吧，你就帮我"ZJURL("cmds:cook")ZJSIZE(15)"解决一下吧"NOR"(cook)吧！TT在这儿，床在那边。";
}

int recognize_apprentice(object ob, string skill)
{
	if ((int)ob->query_temp("mark/星河") < 1)
		return 0;

	if (skill != "cooking" && skill != "chuancai-jiyi")
	{
		command("say 你打住。");
		return -1;
	}

	ob->add_temp("mark/星河", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();

	if ((int)who->query_temp("mark/星河") < 1)
		who->set_temp("mark/星河", 0);

	if (ob->query("money_id") && ob->value() >= 2000)
	{
		message_vision("星河同意指点$N一些关于双修常识和技巧。\n", who);
		who->add_temp("mark/星河", ob->value() / 50);
		destruct(ob);
		return 1;
	}

	command("say 虽说对闯荡江湖没什么用，我也不能白白教你"
		"啊！拿来，辛苦费纹银二十两，童叟无欺！");
	return 0;
}

int do_cook(string arg)
{
	object me;

	me = this_player();
	if (me->is_busy())
		return notify_fail("你正忙着呢，别着急。\n");

	if (! me->query_temp("job/cook"))
	{
		tell_object(me, "星河喝道：你要干什么？不要来捣乱，我忙着呢！\n");
		return 1;
	}

	me->set_temp("job/step", 1);
	me->set_temp("pending/auto_cook", 1);
	me->start_busy(bind((: call_other, __FILE__, "cooking" :), me),
		       bind((: call_other, __FILE__, "halt_cooking" :), me));
	tell_object(me, "你双手怀抱着星河，给了她一个无限温柔的吻。\n");
	return 1;
}

int cooking(object me)
{
	string msg;
	int finish;
	int gain_exp, gain_pot, gain_money;

	if (! me->query_temp("job/step"))
		me->set_temp("job/step", 1);

	if (! living(me))
	{
		me->delete_temp("job/cook");
		me->delete_temp("job/step");
		return 0;
	}

	finish = 0;
	me->receive_damage("jing", 8);
	switch (me->query_temp("job/step"))
	{
	case 1:
		msg = "$N轻轻的褪去星河的衣裳。";
		break;
	case 2:
		msg = "你的双手轻柔的按上了她的胸膛............。";
		break;
	case 3:
		msg = "$N慢慢的伏下身去........。";
		break;
	case 4:
	case 6:
		msg = "$N开始享受那极乐的感觉。";
		break;
	case 5:
		msg = "你逐渐加快速度";
		break;
	case 7:
		msg = "$N。爽的昏了过去";
		break;
	default:
		msg = "$N醒了，深情的看着$n。";
		finish = 1;
		break;
	}
	msg += "\n";

	if (finish)
	{
		object ob;
		msg += "$n看了$N，轻轻的给了你一个吻，满意的点点头"
		       "这是给你的报酬！你可以在我这里学点技术。\n";
		me->delete_temp("job/cook");
		me->delete_temp("job/step");
		gain_money = 2+random(6);
		me->add_temp("mark/厨娘", random(30));
		me->improve_skill("cooking", 10 + random(10));

		// 奖励的修为为10加20的随机数（较多）， money为100加炒菜技
		// 术的等级取随机数（较多），潜能为不超过3点，主要还是以加
		// silver为主。
		ob = new("/clone/money/coin");
		ob->set_amount(gain_money);
		ob->move(me, 1);
		call_out("auto_cook",2,me);
	}

	msg = replace_string(msg, "$N", "你");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

	if (finish)
	{
		if (me->query("combat_exp") >= 50000)
		{
			write(MAG "你隐隐约约的发现居然和武功有一些相通之处，真是奇妙。"NOR"\n");
			gain_exp = 150 + random(11);
			gain_pot = (gain_exp);
			me->add("combat_exp", gain_exp);
			me->improve_potential(gain_pot);
			msg = HIC "你获得了"+chinese_number(gain_money)+"个铜板、" + chinese_number(gain_exp) + "点修为";
			if (gain_pot)
				msg += "和" + chinese_number(gain_pot) + "点潜能。"NOR"\n";
			else
				msg += "。"NOR"\n";
			tell_object(me,  msg);
		}
		return 0;
	}

	me->add_temp("job/step", 1);
	return 1;
}

int halt_cooking(object me)
{
	message_vision("$N揉揉腰部，又扭了扭，叹到：这也太难了，我还是去闯荡江湖吧！\n", me);
	me->delete_temp("job/cook");
	me->delete_temp("pending/auto_cook");
	me->delete_temp("job/step");
	return 1;
}
