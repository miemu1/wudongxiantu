//by ��ʼ�� qsh ednpc tools.
// xiaolu5.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","¬����");
	set("long","������¬���ţ�����Ա��δ�趨������ϸ������");
	set("exits", ([
		"west" : __DIR__"xiaolu8",
		"south" : __DIR__"xiaolu6",
		"north" : __DIR__"xiaojiuguan",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":2+random(2),
	]));
	setup();
}

