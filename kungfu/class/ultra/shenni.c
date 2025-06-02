// shenni �Ϻ�����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;

mixed ask_opinion();

#define ULTRA_OPINION   "��ʦ"
#define OPINION_TYPE    HIY "�ڼҹ���" NOR 
#define MY_OPINION      "force"

string  *my_opinions = ({ "force" });

// ��ͷ�ļ�����������Ƕ��
#include "ultra.h"

void create()
{
	set_name("�Ϻ�����", ({ "nanhai shenni", "shenni", "nanhai" }) );
	set("title", HIG "�Ĵ�����" NOR);
	set("gender", "Ů��");
	set("age", 91);
	set("long", "����һλ�������ᣬ��������ʲô��ͬ��\n");
	set("attitude", "peaceful");
	set("class", "bonze");
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
		"��ָ��ͨ" : "�����ұ̺��񹦹���ָ������ı仯�������ҵ��������������ڸ�һ�ˡ�",
		"����"     : (: ask_opinion :),
		"��ѧ����" : "�ú�����Լ�����ѧ����(martial-cognize)����ʱ��ʲô�书����С���ƣ�",
	]));

	set_skill("strike", 9999);
	set_skill("finger", 9999);
	set_skill("parry", 9999);
	set_skill("dodge", 9999);
	set_skill("force", 9999);
	set_skill("xinfa", 9999);
	set_skill("staff", 9999);
	set_skill("bluesea-force", 9999);
	set_skill("martial-cognize", 9999);
	set_skill("literate", 9999);

	map_skill("xinfa", "bluesea-force");

	set("opinion/ultra",  1);
	set("opinion/master", 1);

	set("rank_info/self", "����");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/zhubang")->wield();

	set("startroom", "/d/xiakedao/zhuwu2");
	check_clone();
}

void init()
{
	object me;

	if (! interactive(me = this_player()))
		return;

	me->delete_temp("want_opinion");
	if (ultrap(me))
		message_vision("$Nü��΢΢һ����\n", this_object(), me);
}

mixed ask_opinion()
{
	object me;
	object ob;

	me = this_player();

	if (me->query("combat_exp") < 200000)
		return "�ߣ�������书Ҳ�����������ۣ�";

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
		return "�����ˣ����ڹ��������Ϊ�Ѿ��Ƶ�������ʦ�ˣ�Ҫ�Ǻ�ƶ����ϼ���Ҳ����";

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

		message_vision("$N��Ϊ��ŭ�Ķ�$n������û������æ���𣿡�\n",this_object(), me);
		return 1;
	}
	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	message_vision("\n$Nһ���ֵ��������ˣ��������롣��\n", this_object(), me);

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
	if (me->query("max_neili") > 4000) lvl += 20;
	return lvl;
}

void do_congration(object me)
{
	command("chat �����������ǲ���");
}

int accept_hit(object me)
{
	command("heng");
	command("say �����" + RANK_D->query_rude(me) + "���������ҵ������ˣ�");
	kill_ob(me);
	return 1;
}

int accept_fight(object me)
{
	object weapon;

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
	{
		message_vision("$N��$n�������ܺã���Ҳ������ʦ�����ˣ�"
			       "���ɣ����ǱȻ�һ�£���\n",
			       this_object(), me);
		return 1;
	}

	if (! me->query_temp("want_opinion/shenni"))
	{
		command("say ���ʲôҪ���Ҷ��֣�");
		return 0;
	}

	command("look " + me->query("id"));

	COMBAT_D->do_attack(this_object(), me, 0);

	if (me->query("qi") <= 0)
	{
		message_vision("\n$Nҡҡͷ��$n�����������ڵ��书"
			       "�����Զ������һ�ж��Ӳ�ס����\n",
			       this_object(), me);
		return notify_fail("����Ҫ�úõ����������ˡ�\n");
	}

	message_combatd("$N�������������$n������ԣ�����ͬʱ����������"
		       "��һ���ֻ������ͷ������������������Ȼ$N����"
		       "һ�����ջع�����û��һ�����ͣ�������$n��Ϊ�Ȼ��\n",
		       this_object(), me);
	if (me->query("neili") < 3000)
	{
		message_vision("$Nҡҡͷ��$n�������ʲ����������㣬����"
			       "�Ժ��������㽫�����������������ɣ���\n",
			       this_object(), me);
		return notify_fail("�������ǻ�ȥ����һ�������ɣ�\n");
	}
	me->set("neili", 0);
	

	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	me->delete_temp("want_opinion");
	message_vision("\n$Nһ���ֵ��������ˣ��������롣��\n", this_object(), me);

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
	if (me->query("character") != "�ĺ�����")
	{
		command("say ���������Բ����������²��˺��ģ�"
			"��û����Ȥ���㣡");
		return -1;
	}

	if (skill == "martial-cognize")
		return 1;

	if (! ultrap(me))
	{
		command("say ��ѧ�ҵı̺��񹦣��㻹�����ʸ�"
			"������˴���ʦ��˵�ɣ�");
		return -1;
	}

	if (me->query_skill(skill, 1) >= 180)
	{
		command("say ���ˣ��Ҿͽ��㵽����ɣ��书����"
			"Ҫ���Լ����о����ǣ�");
		return -1;
	}

	if (skill != "bluesea-force")
		return 1;

	if (me->query_temp("can_learn/shenni/bluesea-force"))
		return 1;

	me->set_temp("can_learn/dugu/bluesea-force", 1);
	command("nod");
	command("say �����ҽ����ҵľ�ѧ�̺��񹦣��ܲ���ѧ��"
		"�Ϳ�����컯�ˣ�");
	return 1;
}

void unconcious()
{
	message("vision", "\n"HIR + name() + "��ɫһ�䣬����һ����"
		"Ѫ������һ�������Ų�����"NOR"\n", environment());
	command("chat �գ��գ��գ�ƶ��ȥҲ��");
	destruct(this_object());
}

void die()
{
	message("vision", "\n"HIR + name() + "���һ����������һ����"
		"Ѫ������һ�����ʹ˲�����"NOR"\n", environment());
	command("chat ƶ��ȥҲ��");
	destruct(this_object());
}
