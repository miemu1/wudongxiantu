//by ��ʼ�� qsh ednpc tools.
// xiaolu3.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","¬����");
	set("long","������¬���ţ�����Ա��δ�趨������ϸ������");
	set("exits", ([
		"west" : __DIR__"xiaolu4",
		"south" : __DIR__"xiaolu2",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/mitan":2+random(2),
	]));
	setup();
}

