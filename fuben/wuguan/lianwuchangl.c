//by ���� ranger's ednpc tools.
// lianwuchangl.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���䳡");
	set("long","���������䳡������Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"east" : __DIR__"chukou",
		"north" : __DIR__"lianwuchangk",
	]));
	set("objects", ([
	__DIR__"npc/wuguan_dizi":3+random(2),
	]));
	setup();
}

