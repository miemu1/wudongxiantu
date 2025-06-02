// zhu.c ����

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

string ask_job();
int do_answer();

void create()
{
	set_name("��ʦѧͽ", ({ "chushi xuetu" }));
	set("long", "��ʦ�ո��������õ�һ��ѧͽ��\n");
	set("gender", "����");
	set("age", 65);
	set("no_get", 1);
	set("teacher",1);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	set("inquiry", ([
	    "����" : (: ask_job :),
	]));
	setup();

	set("chat_chance", 1);
}

string ask_job()
{
	object me;
	object *obs;

	me = this_player();
	if (me->query("afk/file")=="chaocai")
		return "�˳����ˣ�";

	if (me->query_temp("pending/afk")||me->query("afk"))
		return "����æ���أ�";

	if (me->query("jing") < 50) 
		return "�㻹����Ϣ����ɣ�С�İ������ۿ��ˣ�";

	if (! interactive(me))
		return "...";

	me->delete("afk");
	me->set("afk/file","chaocai");
	me->set("afk/room",environment(me));
	return "�ðɣ���Ͱ��ҳ��˰ɣ������������̨���Ǳߡ�";
}