//by ��ʼ�� qsh ednpc tools.
// huangling11.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ĺ��");
	set("long","�����ǻ���Ĺ��������Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"shishi3",
		"west" : __DIR__"huangling10",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/ehun":5,
	]));
	setup();
}

