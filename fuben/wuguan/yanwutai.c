//by ���� ranger's ednpc tools.
// yanwutai.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����̨");
	set("long","����������̨������Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"east" : __DIR__"lianwuchangj",
		"north" : __DIR__"lianwuchangf",
		"south" : __DIR__"lianwuchange",
	]));
	set("objects", ([
	__DIR__"npc/wuguan_jiaotou":5,
	//__DIR__"obj/baoxiang":1,	
	]));
	setup();
}

