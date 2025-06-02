// Room: /city/ymdongting.c
// YZC 1995/12/04 
#include <localtime.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���϶����������ס������һ������������������ϸ������ǽ������һ����
�ң����顰����������ĸ���������Ĵ��֡�֪���������İ����������飬ʦү
�����ں�
LONG );
	set("exits", ([
		"east"  : __DIR__"dongting",
		"west"  : __DIR__"xiting",
		"north" : __DIR__"neizhai",
		"south" : __DIR__"yamen",
	]));
	set("item_desc", ([
		"����������" : "�ٸ��Ĺ������������ڴ˲鿴���������Ϣ��\n"ZJOBACTS2"�˷�:look_jiaofei\n",
		]));
	set("objects", ([
		__DIR__"npc/cheng" : 1,
		__DIR__"npc/shiye" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_start_jiaofei_fuben", "start_jiaofei_fuben");
	add_action("do_look_jiaofei", "look_jiaofei");
}

int do_look_jiaofei()
{
	string str;
	object who = this_player();
	int jiaofei_count, last_time;
	
	last_time = who->query("fuben_jiaofei/last_time");
	if((last_time/86400) == (time()/86400))
	{
	jiaofei_count = who->query("fuben_jiaofei/count");
	str = "������Ѿ������" + jiaofei_count + "�ν˷˸�����\n";
	}
	else
	str = "����컹û����ս������\n";
	write(ZJOBLONG + str + ZJOBACTS2 + "��ʼ�˷�:start_jiaofei_fuben\n");
	
	return 1;	
}

int do_start_jiaofei_fuben()
{
	object who = this_player();
	
	"/d/fuben_jiaofei/fb_main"->main(who);
	
	return 1;
}