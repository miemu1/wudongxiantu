//by ��ʼ�� qsh ednpc tools.
// huangling4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ĺ��");
	set("long","�����ǻ���Ĺ��������Ա��δ�趨������ϸ������");
	set("exits", ([
		"north" : __DIR__"huangling6",
		"west" : __DIR__"huangling5",
		"south" : __DIR__"huangling3",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/ehun":5,
	]));
	setup();
}

