//by ���� ranger's ednpc tools.
// lianwuchangk.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���䳡");
	set("long","���������䳡������Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"south" : __DIR__"lianwuchangl",
		"north" : __DIR__"lianwuchangj",
	]));
	set("objects", ([
	__DIR__"npc/wuguan_dizi":3+random(2),
	]));
	setup();
}

