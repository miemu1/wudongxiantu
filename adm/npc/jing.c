// NPC jiuyi.c

#include <ansi.h>

inherit NPC;

mixed ask_fofa();

void create()
{
	set_name(HIW"��"NOR, ({ "jing"}));
	set("long","���Ǿ������ڷ�֪ʶ��\n");
	set("title", HIC"�����һ"NOR);
	set("gender", "Ů��");
	set("nickname", HIR "��Ψһ" NOR);
	set("age", 25);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("max_qi", 99999999);
 	set("qi", 99999999);
	set("jing", 99999999);
	set("max_jing", 99999999);
	set("neili",99999999);
	set("max_neili", 99999999);
	set("jiali", 5000);
	
	set_skill("strike", 1000);
	set_skill("rulai-shenzhang", 1000);

	map_skill("strike", "rulai-shenzhang");

	prepare_skill("strike", "rulai-shenzhang");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "strike.wofo" :),
	}));

	set_temp("apply/attack", 1000);
	set_temp("apply/defense", 1000);
	set_temp("apply/damage", 1000);
	set_temp("apply/unarmed_damage", 1000);
	set_temp("apply/armor", 20000);


	set("combat_exp", 1600000);
	set("score", 1500);
	
	set("inquiry", (["��": (:ask_fofa:)]));
	
	setup();
}

mixed ask_fofa()
{
	object ob;
	object me;
	
	me = this_player();
	if (me->query_temp("last_ask/jing") + 10 > time())
		return HIR"��Ʒ����ϸϸ��Ʒ������һ����Ĺ���~~~~~~~"NOR;

	message_vision("$N����$n������"HIW"���ðɣ��Ҿ�����̸̸���ڷ𷨷������ᣬ���Ҫ�ú����š���\n"NOR,
		       this_object(), me);
	
	tell_object(me, HIG "���������л�Ȼ���ʣ�ͨ���˲��ٹ��ڷ𷨵İ��"NOR"\n"+
	HIC"������ģ������ķ��������ķ��������ķ�����ʶ�����ˣ�\n"NOR);
	me->set_temp("last_ask/jing", time());
	me->improve_skill("sanscrit", 10);
	me->improve_skill("buddhism",10);
	me->improve_skill("lamaism",10);
	me->improve_skill("taoism",10);
	return 1;
}

int accept_fight()
{
	command("say ���ɱɱ�ɺ���ͳ��");
	return notify_fail("�㻹�����˰ɣ�\n");
}

int accept_hit()
{
	command("say ���ɱɱ�ɺ���ͳ��");
	return notify_fail("�㻹�����˰ɣ�\n");
}

int accept_kill()
{
	command("say ѽ�������ʲô��");
	return 1;
}

void unconcious()
{
	die();
}

void die()
{
	command("chat �������ˣ��޴������ࡣ");
	message_vision("$N�������Ʈɢ��\n", this_object());
	this_object()->set("qi",99999999);
	this_object()->set("jing",99999999);
}


