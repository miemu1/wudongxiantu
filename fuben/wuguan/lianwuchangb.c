//by ���� ranger's ednpc tools.
// lianwuchangb.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���䳡");
	set("long","���������䳡������Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"east" : __DIR__"lianwuchangd",
		"north" : __DIR__"lianwuchangc",
		"west" : __DIR__"xiuxishi",
	]));
	set("objects", ([
		__DIR__"npc/wuguan_dizi":5+random(2),
	]));
	setup();
}

