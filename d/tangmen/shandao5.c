//shandao5.c		�Ĵ����š���ɽɽ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long",
"������ͨ��ɽ����С�����涸�ޱȣ�һ��С�ľͻ�ˤ��ȥ�������Ǹ�\n"
"�����ƵĲ��������Խ�ӽ�ɽ���¶�Խ���ˣ���۽��½��Ըе��������ˣ�\n"
"�����Ͼ����������ˡ�\n"
);
	set("exits", ([
	        "southdown" : __DIR__"shandao4",
		"northup" : __DIR__"liexingya",
	]));
	set("area", "����");
	set("objects", ([
	        __DIR__"npc/duwang" : 1,
	        __DIR__"npc/wolf" : 1,
	]));
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
