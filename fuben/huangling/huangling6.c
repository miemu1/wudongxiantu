//by ��ʼ�� qsh ednpc tools.
// huangling6.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ĺ��");
	set("long","�����ǻ���Ĺ��������Ա��δ�趨������ϸ������");
	set("exits", ([
		"west" : __DIR__"shishi2",
		"east" : __DIR__"huangling7",
		"south" : __DIR__"huangling4",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/ehun":5,	
	]));
	setup();
}

