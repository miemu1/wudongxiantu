// huang ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;

mixed ask_opinion();

#define ULTRA_OPINION   "��ʦ"
#define OPINION_TYPE    HIY "ȭ�Ź���" NOR 
#define MY_OPINION      "unarmed"

string  *my_opinions = ({ "unarmed", "finger",
			  "strike", "cuff", "hand", "claw" });

// ��ͷ�ļ�����������Ƕ��
#include "ultra.h"

void create()
{
	set_name("����", ({ "huang shang", "huang" }) );
	set("title", HIY "�Ĵ�����" NOR);
	set("gender", "����");
	set("age", 92);
	set("long", "�����������ţ��������书�ߵ͡�\n");
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
		"�����澭" : "����������д��һ�������ڹ�צ��������ĵá�",
		"�����澭" : "��...��...... �Ҳ�̫�����",
		"����"     : (: ask_opinion :),
		"��ѧ����" : "��ѧ����(martial-cognize)�����ң���̸ʲô�书�أ�",
	]));

	set_skill("unarmed", 9999);
	set_skill("finger", 9999);
	set_skill("claw", 9999);
	set_skill("strike", 9999);
	set_skill("hand", 9999);
	set_skill("cuff", 9999);
	set_skill("parry", 9999);
	set_skill("dodge", 9999);
	set_skill("xinfa", 9999);
	set_skill("force", 9999);
	set_skill("jiuyin-shengong", 9999);
	set_skill("martial-cognize", 9999);
	set_skill("literate", 9999);

	map_skill("xinfa", "jiuyin-shengong");

	set("opinion/ultra",  1);
	set("opinion/master", 1);

	set("rank_info/self", "ĳ��");

	setup();
	carry_object("/clone/cloth/cloth")->wear();

	set("startroom", "/d/dali/lushui");
	check_clone();
}

void init()
{
	object me;

	if (! interactive(me = this_player()))
		return;

	me->delete_temp("want_opinion");
	if (ultrap(me))
	{
		message_vision("$N��Ц��$n���˵�ͷ��\n",this_object(), me);
	}
}

mixed ask_opinion()
{
	object me;
	object ob;

	me = this_player();

	if (me->query("combat_exp") < 200000)
		return "�Ǻǣ�������书��̸ʲô���ۣ�";

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
		return "��������ȭ�ŷ������Ϊ�Ѿ��Ƶ�������ʦ�ˣ�����Ҫ��Ҫ�����У�";

	if (is_fighting(me))
		return "��������ʲô������Ӯ���ң����Լ����Լ����۰ɣ�";

	if (me->is_fighting())
		return "��Ȼ���ɣ����Ҹ������ǡ�";

	if (objectp(ob = query_temp("opinion")))
	{
		if (ob == me)
		{
			command("say ����ʲô������Ҫ���ҡ�");
			return 1;
		}

		message_vision("$N���ڳ�˼��û�лش�$n��ֻ�ǰ��˰��֡�\n",
			       this_object(), me);
		return 1;
	}
	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	message_vision("\n$N���ͷ���������ˣ����ȵȻ�����������롣��\n",this_object(), me);

	return 1;
}

int calc_level(object me, string skill)
{
	int lvl;
	string sp;
	mapping action;

	lvl = me->query_skill(skill, 1) / 2;
	sp = me->query_skill_mapped(skill);
	if (! sp) return lvl;

	lvl += me->query_skill(sp, 1);
	action = SKILL_D(sp)->query_action(me, 0);
	if (mapp(action))
		lvl += (action["force"] + action["attack"] +
			action["parry"] + action["dodge"] - 150) / 15;
	return lvl;
}

void do_congration(object me)
{
	command("chat ��ϲ��λ" + RANK_D->query_respect(me) + "�������������ֹ������������Ŭ������");
}

int accept_hit(object me)
{
	if (me->query_temp("want_hit/huang") >= 2)
	{
		command("heng");
		command("say �²���������Ҫ�����Ǿ�ȥ���ɣ�");
		kill_ob(me);
		return 1;
	}

	command("shake");
	command("say ��λ" + RANK_D->query_respect(me) + "��"
		"����֮���м�óȻ���ơ�");
	me->add_temp("want_hit/huang", 1);
	return 0;
}

int accept_fight(object me)
{
	object weapon;

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
	{
		message_vision("$N��ϲ����$n�������ܺã������һ�û��"
			       "����ʦ���ֹ����У����ɣ���\n",
			       this_object(), me);
		return 1;
	}

	if (! me->query_temp("want_opinion/huang"))
	{
		command("say ƽ���޹ʶ�ʲô�֣�");
		return 0;
	}

	if (objectp(weapon = me->query_temp("weapon")))
	{
		command("say �������е�" + weapon->name() + "���ҷ��£�");
		return 0;
	}

	if (me->query("qi") * 100 / me->query("max_qi") < 80||
	    me->query("jing") * 100 / me->query("max_jing") < 80)
	{
		command("say ������״̬���ѣ�����Ϣ������˵�ɣ�");
		return 0;
	}

	command("nod");
	COMBAT_D->do_attack(me, this_object(), 0);
	COMBAT_D->do_attack(this_object(), me, 0);

	if (me->query("qi") <= 0)
	{
		message_vision("\n$Nҡҡͷ��$n�����������ڵ��书"
			       "�����Զ������һ�ж��Ӳ�ס����\n",
			       this_object(), me);
		return notify_fail("����Ҫ�úõ����������ˡ�\n");
	}

	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	me->delete_temp("want_opinion");
	message_vision("\n$N���ͷ���������ˣ����ȵȻ�����������롣��\n",this_object(), me);

	return notify_fail("���������ļ������õ�һ�����\n");
}

int accept_kill(object me)
{
	if (me->query("combat_exp") < 500000)
	{
		message_vision("$N��ŭ����������С����ʲô�ң����ҹ�����˵��һ�ư�$n�����ڵء�\n",
			       this_object(), me);
		me->unconcious();
		return -1;
	}
	command("sigh");
	command("say �ܺã����껹��û������ʲô�Һ��ҽ����ĸ��֣�");
	return 1;
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("character") != "��������")
	{
		command("say ���ɷ����������ƶ�����һ��Ҫ�������䣬�����Բ��������ˡ�");
		return -1;
	}

	if (skill == "martial-cognize")
		return 1;

	if (! ultrap(me))
	{
		command("say ��ѧ�ҵľ����񹦣��㻹�����ʸ񣬵�����˴���ʦ��˵�ɣ�");
		return -1;
	}

	if (me->query_skill(skill, 1) >= 180)
	{
		command("say ���ˣ��Ҿͽ��㵽����ɣ��书����Ҫ���Լ����о����ǣ�");
		return -1;
	}

	if (skill != "jiuyin-shengong")
		return 1;

	if (me->query_temp("can_learn/huang/jiuyin-shengong"))
		return 1;

	me->set_temp("can_learn/huang/jiuyin-shengong", 1);
	command("nod");
	command("say �ܺã��Ҿʹ�������񹦰ɣ��ɲ�Ҫ�������˵ĸ�����");
	return 1;
}

void unconcious()
{
	message("vision", "\n"HIR + name() + "��ɫһ�䣬����һ����"
		"Ѫ������һ�������Ų�����"NOR"\n", environment());
	command("chat �գ��գ��գ��Ϸ�ȥҲ��");
	destruct(this_object());
}

void die()
{
	message("vision", "\n"HIR + name() + "���һ����������һ����"
		"Ѫ������һ�����ʹ˲�����"NOR"\n", environment());
	command("chat �Ϸ�ȥҲ��");
	destruct(this_object());
}
