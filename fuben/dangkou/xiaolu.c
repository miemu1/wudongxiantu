//by ��ʼ�� qsh ednpc tools.
// xiaolu.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","¬����");
	set("long","������¬���ţ�����Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"xiaolu2",
		"west" : __DIR__"enter",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/mitan":random(2),
	]));
	setup();
}

