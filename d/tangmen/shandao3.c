//shandao3.c		�Ĵ����š���ɽɽ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long",
"������ͨ��ɽ����С�����涸�ޱȣ�һ��С�ľͻ�ˤ��ȥ�������Ǹ�\n"
"�����ƵĲ��������Խ�ӽ�ɽ���¶�Խ���ˣ���۽��½��Ըе��������ˡ�\n"
);
	set("exits", ([
		"northeast" : __DIR__"shandao4",
		"westdown" : __DIR__"shandao2",
		"southdown" : __DIR__"shanshi5",
	]));
	set("area", "����");
	set("objects", ([
	        __DIR__"npc/wugong" : 1,
	        __DIR__"npc/fushe" : 1,
	]));
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
