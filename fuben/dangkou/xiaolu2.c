//by ��ʼ�� qsh ednpc tools.
// xiaolu2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","¬����");
	set("long","������¬���ţ�����Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"xiaojiuguan",
		"north" : __DIR__"xiaolu3",
		"west" : __DIR__"xiaolu",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/mitan":2+random(2),
	]));
	setup();
}

