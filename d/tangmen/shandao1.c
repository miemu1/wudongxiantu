//shandao1.c		�Ĵ����š���ɽɽ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long",
"������ͨ��ɽ����С�����涸�ޱȣ�һ��С�ľͻ�ˤ��ȥ�������Ǹ�\n"
"�����ƵĲ�����������д���Ұ�޵�˺ҧ��������ë���Ȼ������������\n"
"��ȫ���ע������Ұ��������\n"
);
	set("exits", ([
			"westdown" : __DIR__"houshan",
			"northeast" : __DIR__"shandao2",
	]));
	set("area", "����");
	set("objects", ([
	        __DIR__"npc/xiezi" : 1,
	        __DIR__"npc/snake" : 1,
	]));
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
