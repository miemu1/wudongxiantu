// This program is a part of NT MudLIB

#include <ansi.h>

inherit NPC;
int ask_job();
int ask_job1();
int ask_job2();
void create()
{
        set_name(HIW "����������" NOR, ({ "dragon guardian"}) );
        set("long", HIY "����һλ�������°׷��ԲԵ����ˡ��㿴����������Ŀ��\n" NOR);
	set("gender", "����");
	set("age", 2000);
	set("nokill", 1);
	set("no_kill", 1);
	set("shen_type", 1);
	set("str", 80);
	set("int", 80);
	set("con", 80);
	set("dex", 80);
	set("vendetta/authority",1);
	set("qi", 1000000);
	set("max_qi", 1000000);
	set("jing", 50000000);
	set("max_jing", 50000000);
	set("neili", 50000000);
	set("max_neili", 50000000);
	set("jiali", 300);
	set("combat_exp", 100000000);
	set("score", 600000);
	set("shen", 200000);
	set("inquiry", ([
        	"����������" : (: ask_job :),
			"����" : (: ask_job1 :),
			"����" : (: ask_job2 :),
            ]));
	setup();
}

int ask_job()
{
	object me;
	int i,size;
	me = this_player();

	tell_object(me, HIW"�����������������ʼ�������ı�������������������������ǿ��������ϧ�Ѿ����Ϲ�֮սʱ�������ˣ���Ƭ������������ɽ�������Ѩ������л�ԵѰ�����Ϸ������л����ȥһ̽�����ɣ������ˡ�\n"NOR);

	return 1;
}
int ask_job1()
{
	object me;
	int i,size;
	me = this_player();

	tell_object(me, HIW"���������������˯��ǧ���������ʵ�����֮�ۡ���ֻ�ܸ�������ô���ˡ�\n"NOR);

	return 1;
}
int ask_job2()
{
	object me;
	int i,size;
	me = this_player();
	//tell_object(me, HIW"����������û�뵽�㽫����������Ѱ�����ˣ�����������ۺ�ǧ������ס�ǧ������������Ұɣ��������¸������ǹ�ʣ���\n"NOR);
	//���������ḧ���е���������ۺ�ǧ������ף�Ĭ��������������������ǧ�������һ�����£����������������һ�Ż���ȼ�������е���������ۺ�ǧ�������֮�ϣ�һ����۵Ĺ⻪��ҫ����......�㻺�������۾���
	//���������� ����ӡ ������ �����������������㣬�����ˣ�ֻ������������������壬�����ˡ�ȥ�ɣ���������ӡ������ؼ�˭�����赲��ĽŲ���

	tell_object(me, HIW"��δ���š�\n"NOR);

	return 1;
}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
        this_object()->clear_condition();
}

void die()
{
	unconcious();
}