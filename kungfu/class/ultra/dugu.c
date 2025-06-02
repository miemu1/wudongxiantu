// huang ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;

mixed ask_opinion();

#define ULTRA_OPINION   "��ʦ"
#define OPINION_TYPE    HIY "��������" NOR 
#define MY_OPINION      "weapon"

string  *my_opinions = ({ "sword", "blade", "staff", "hammer",
			  "club", "whip",  "dagger", });

// ��ͷ�ļ�����������Ƕ��
#include "ultra.h"

void check_weapon();

void create()
{
	set_name("�������", ({ "dugu qiubai", "dugu" }) );
	set("title", HIC "�Ĵ�����" NOR);
	set("gender", "����");
	set("age", 48);
	set("long", "���˳ϿҶغ�üĿ��Ƿ���������������\n");
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
		"���¾Ž�" : "�Ұ������书�ı仯����ھŽ�֮�У��㲻���ǽ����������������ƾ��޷�������а��",
		"����"     : (: ask_opinion :),
		"��ѧ����" : "��ѧ����(martial-cognize)���������壬��ν����һͨͨ��ͨ��",
	]));

	set_skill("unarmed", 9999);
	set_skill("sword", 9999);
	set_skill("blade", 9999);
	set_skill("staff", 9999);
	set_skill("hammer", 9999);
	set_skill("club", 9999);
	set_skill("whip", 9999);
	set_skill("dagger", 9999);
	set_skill("throwing", 9999);
	set_skill("parry", 9999);
	set_skill("dodge", 9999);
	set_skill("xinfa", 9999);
	set_skill("force", 9999);
	set_skill("never-defeated", 9999);
	set_skill("martial-cognize", 9999);

	map_skill("xinfa", "never-defeated");

	set("opinion/ultra",  1);
	set("opinion/master", 1);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: check_weapon :),
	}) );

	set("rank_info/self", "����");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/zhujian")->wield();

	set("startroom", "/d/huashan/shandong");
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
		message_vision("$N΢΢һЦ����$n���˵�ͷ��\n", this_object(), me);
	}
}

void check_weapon()
{
	if (objectp(query_temp("weapon")))
		return;

	message_vision("$N��̾һ����������$N��������������δ����֣��գ����ˣ���ȥҲ��\n", this_object());
	destruct(this_object());
}

mixed ask_opinion()
{
	object me;
	object ob;

	me = this_player();

	if (me->query("combat_exp") < 5000000)
		return "�Ǻǣ�������书��̸ʲô���ۣ�";

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
		return "������������������Ϊ�Ѿ��Ƶ�������ʦ�ˣ�����Ҫ��Ҫ�����У�";

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

		message_vision("$N���ڳ�˼��û�лش�$n��ֻ�ǰ��˰��֡�\n", this_object(), me);
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
	action = SKILL_D(sp)->query_action(me, me->query_temp("weapon")); 
	if (mapp(action))
		lvl += (action["force"] + action["parry"] + action["dodge"] - 250) / 10;
	return lvl;
}

void do_congration(object me)
{
	command("chat ��λ" + RANK_D->query_respect(me) + "��Ҫ�������أ���֪ǿ�и���ǿ���֡�");
}

int accept_hit(object me)
{
	if (me->query_temp("want_hit/dugu") >= 2)
	{
		command("heng");
		command("say �²���������Ҫ�����Ǿ�ȥ���ɣ�");
		kill_ob(me);
		return 1;
	}

	command("shake");
	command("say ��λ" + RANK_D->query_respect(me) + "������֮���м�óȻ���ơ�");
	me->add_temp("want_hit/dugu", 1);
	return 0;
}

int accept_fight(object me)
{
	object weapon;

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
	{
		message_vision("$N��ϲ����$n�������ܺã������һ�û�к���ʦ���ֹ����У����ɣ���\n",
			       this_object(), me);
		return 1;
	}

	if (! me->query_temp("want_opinion/dugu"))
	{
		command("say ƽ���޹ʶ�ʲô�֣�");
		return 0;
	}

	if (! objectp(weapon = me->query_temp("weapon")))
	{
		command("say û�����㶯ʲô�֣�");
		return 0;
	}

	if (me->query("qi") * 100 / me->query("max_qi") < 80||
	    me->query("jing") * 100 / me->query("max_jing") < 80)
	{
		command("say ������״̬���ѣ�����Ϣ������˵�ɣ�");
		return 0;
	}

	command("nod");
	COMBAT_D->do_attack(me, this_object(), weapon);
	COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));

	if (me->query("qi") <= 0)
	{
		message_vision("\n$Nҡҡͷ��$n�����������ڵ��书�����Զ������һ�ж��Ӳ�ס����\n",this_object(), me);
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
		message_vision("$N��ŭ����������С����ʲô"
			       "�ң����ҹ�����˵��һ�ư�$n�����ڵء�\n",
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
	if (me->query("character") != "������")
	{
		command("say �ҿ�����Ը񲻹�����������������ѧϰ�书���������˰ɣ�");
		return -1;
	}

	if (skill == "martial-cognize")
		return 1;

	if (! ultrap(me))
	{
		command("say ��ѧ�ҵĲ����񹦣��㻹�����ʸ񣬵�����˴���ʦ��˵�ɣ�");
		return -1;
	}

	if (me->query_skill(skill, 1) >= 180)
	{
		command("say ���ˣ��Ҿͽ��㵽����ɣ��书����Ҫ���Լ����о����ǣ�");
		return -1;
	}

	if (skill != "never-defeated")
		return 1;

	if (me->query_temp("can_learn/dugu/never-defeated"))
		return 1;

	me->set_temp("can_learn/dugu/never-defeated", 1);
	command("nod");
	command("say �ҿ��Խ����Ҷ�����������Ĳ����񹦣��������ܲ���ѧ����Ҫ����Ļ�Ե�ˣ�");
	return 1;
}

void unconcious()
{
	message("vision", "\n"HIR + name() + "��ɫһ�䣬����һ����"
		"Ѫ������һ�������Ų�����"NOR"\n", environment());
	command("chat �գ��գ��գ�����ȥҲ��");
	destruct(this_object());
}

void die()
{
	message("vision", "\n"HIR + name() + "���һ����������һ����"
		"Ѫ������һ�����ʹ˲�����"NOR"\n", environment());
	command("chat ����ȥҲ��");
	destruct(this_object());
}
