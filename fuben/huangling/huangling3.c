//by ��ʼ�� qsh ednpc tools.
// huangling3.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ĺ��");
	set("long","�����ǻ���Ĺ��������Ա��δ�趨������ϸ������");
	set("exits", ([
		"north" : __DIR__"huangling4",
		"west" : __DIR__"huangling",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/ehun":5,	
	]));
	setup();
}

