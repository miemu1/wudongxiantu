//by ���� ranger's ednpc tools.
// lianwuchangd.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���䳡");
	set("long","���������䳡������Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"north" : __DIR__"lianwuchange",
		"west" : __DIR__"lianwuchangb",
	]));
	set("objects", ([
		__DIR__"npc/wuguan_dizi":5+random(2),
	]));
	setup();
}

