//by ���� ranger's ednpc tools.
// lianwuchangg.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���䳡");
	set("long","���������䳡������Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"west" : __DIR__"lianwuchangh",
		"east" : __DIR__"lianwuchangf",
	]));
	set("objects", ([
	__DIR__"npc/wuguan_dizi":3+random(2),
	]));
	setup();
}

