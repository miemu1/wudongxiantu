//by ��ʼ�� qsh ednpc tools.
// huangling10.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ĺ��");
	set("long","�����ǻ���Ĺ��������Ա��δ�趨������ϸ������");
	set("exits", ([
		"north" : __DIR__"huangling12",
		"east" : __DIR__"huangling11",
		"west" : __DIR__"huangling9",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/ehun":5,
	]));
	setup();
}

