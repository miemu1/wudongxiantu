//by ���� ranger's ednpc tools.
// lianwuchangf.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���䳡");
	set("long","���������䳡������Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"east" : __DIR__"lianwuchangi",
		"west" : __DIR__"lianwuchangg",
		"south" : __DIR__"yanwutai",
	]));
	set("objects", ([
		__DIR__"npc/wuguan_dizi":4+random(2),
	]));
	setup();
}

