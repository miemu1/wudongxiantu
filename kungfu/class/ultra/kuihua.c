// kuihua 葵花太监

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;

mixed ask_opinion();

#define ULTRA_OPINION   "宗师"
#define OPINION_TYPE    HIY "轻身功夫" NOR 
#define MY_OPINION      "dodge"

string  *my_opinions = ({ "dodge" });

// 该头文件必须在这里嵌入
#include "ultra.h"

void create()
{
	set_name("葵花太监", ({ "kuihua taijian", "kuihua", "taijian" }) );
	set("title", HIR "四大天王" NOR);
	set("gender", "无性");
	set("age", 99);
	set("long", "此人脸型瘦削，满是阴骛，不知是喜是怒。\n");
	set("attitude", "peaceful");
	set("str", 99);
	set("int", 99);
	set("con", 99);
	set("dex", 99);

	set("max_qi", 999999);
	set("max_jing", 999999);
	set("neili", 999999);
	set("max_neili", 999999);
	set("jiali", 999999);

	set("combat_exp", 999999999);

	set("inquiry", ([
		"葵花宝典" : "那是我写的一本关于轻功方面的心得，怎么，你有兴趣？",
		"评价"     : (: ask_opinion :),
		"武学修养" : "学习深奥武功，没有深厚的武学修养(martial-cognize)，提也休提！",
	]));

	set_skill("unarmed", 9999);
	set_skill("finger", 9999);
	set_skill("parry", 9999);
	set_skill("dodge", 9999);
	set_skill("force", 9999);
	set_skill("xinfa", 9999);
	set_skill("sword", 9999);
	set_skill("kuihua-mogong", 9999);
	set_skill("martial-cognize", 9999);
	set_skill("literate", 9999);

	map_skill("xinfa", "kuihua-mogong");

	set("opinion/ultra",  1);
	set("opinion/master", 1);

	set("rank_info/self", "本宫");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/misc/spin")->wield();

	set("startroom", "/d/beijing/shanlu3");
	check_clone();
}

void init()
{
	object me;

	if (! interactive(me = this_player()))
		return;

	me->delete_temp("want_opinion");
	if (ultrap(me))
		message_vision("$N扫了$n一眼。\n", this_object(), me);
}

mixed ask_opinion()
{
	object me;
	object ob;

	me = this_player();

	if (me->query("combat_exp") < 5000000)
		return "嘿，你这点武功只好抓抓老鼠。";

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
		return "嗯，你轻功方面的修为已经称得上是宗师了！要是有兴趣咱们过两招？";

	if (is_fighting(me))
		return "哈哈，废什么话，打赢了我，你自己给自己评价吧！";

	if (me->is_fighting())
		return "你等会儿吧！待我赶走他们。";

	if (objectp(ob = query_temp("opinion")))
	{
		if (ob == me)
		{
			command("say 你着什么急？不要烦我。");
			return 1;
		}

		message_vision("$N颇为恼怒的对$n道：“没看我正忙着吗？”\n",this_object(), me);
		return 1;
	}
	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	message_vision("\n$N一摆手道：“且慢，待我想想。”\n",this_object(), me);

	return 1;
}

int calc_level(object me, string skill)
{
	int lvl;
	string sp;

	lvl = me->query_skill(skill, 1) / 2;
	sp = me->query_skill_mapped(skill);
	if (! sp) return lvl;

	lvl += me->query_skill(sp, 1);
	lvl += 20;
	return lvl;
}

void do_congration(object me)
{
	command("chat* heihei " + me->query("id"));
}

int accept_hit(object me)
{
	command("heng");
	command("say 你活得不耐烦了！");
	kill_ob(me);
	return 1;
}

int accept_fight(object me)
{
	object weapon;

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
	{
		message_vision("$N对$n道：“很好，你也算是顶尖高手了，"
			       "来吧！咱们比划一下！”\n",
			       this_object(), me);
		return 1;
	}

	if (! me->query_temp("want_opinion/kuihua"))
	{
		command("say 你干什么要和我动手？");
		return 0;
	}

	command("look " + me->query("id"));
	COMBAT_D->do_attack(this_object(), me, 0);

	if (me->query("qi") <= 0)
	{
		message_vision("\n$N摇摇头对$n道：“你现在的武功"
			       "还差得远，连我一招都接不住！”\n",
			       this_object(), me);
		return notify_fail("看来要好好的修炼功夫了。\n");
	}

	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	me->delete_temp("want_opinion");
	message_vision("\n$N一摆手道：“且慢，待我想想。”\n",this_object(), me);

	return notify_fail("看来不能心急，还得等一会儿。\n");
}

int accept_kill(object me)
{
	if (me->query("combat_exp") < 500000)
	{
		message_vision("$N大怒道：“无名小辈捣什么"
			       "乱？给我滚！”说罢一掌把$n劈倒在地。\n",
			       this_object(), me);
		me->unconcious();
		return -1;
	}
	command("sigh");
	command("say 很好！近年还真没有遇到什么敢和我较量的高手！");
	return 1;
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("character") != "阴险奸诈")
	{
		command("say 你这人没有领会立世的精妙之理，还"
			"是回去吧！");
		return -1;
	}

	if (skill == "martial-cognize")
		return 1;

	if (! ultrap(me))
	{
		command("say 想学我的葵花神功？你还不够资格，"
			"等你成了大宗师再说吧！");
		return -1;
	}

	if (me->query_skill(skill, 1) >= 180)
	{
		command("say 够了！我就教你到这里吧，武功还是"
			"要靠自己多研究才是！");
		return -1;
	}

	if (skill != "kuihua-mogong")
		return 1;

	if (me->query_temp("can_learn/kuihua/kuihua-mogong"))
		return 1;

	me->set_temp("can_learn/kuihua/kuihua-mogong", 1);
	command("nod");
	command("say 不错，我就传你葵花神功吧，不要读什么葵花"
		"宝典，那是我拿去害人的！");
	return 1;
}

void unconcious()
{
	message("vision", "\n"HIR + name() + "脸色一变，吐了一口鲜"
		"血，身形一闪，消逝不见。"NOR"\n", environment());
	command("chat 罢！罢！罢！老夫去也！");
	destruct(this_object());
}

void die()
{
	message("vision", "\n"HIR + name() + "大叫一声，狂吐了一口鲜"
		"血，身形一闪，就此不见。"NOR"\n", environment());
	command("chat 老夫去也！");
	destruct(this_object());
}
