//by ��ʼ�� qsh ednpc tools.
// huangling.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ĺ��");
	set("long","�����ǻ���Ĺ��������Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"huangling3",
		"south" : __DIR__"huangling2",
		"west" : __DIR__"enter",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/ehun":5,
	]));
	setup();
}

