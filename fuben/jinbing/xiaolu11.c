//by ��ʼ�� qsh ednpc tools.
// xiaolu11.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����С·");
	set("long","�����ǹ���С·������Ա��δ�趨������ϸ������");
	set("exits", ([
		"south" : __DIR__"xiaolu12",
		"west" : __DIR__"xiaolu10",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":4+random(2),
	]));
	setup();
}

