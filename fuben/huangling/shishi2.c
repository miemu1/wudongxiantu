//by ��ʼ�� qsh ednpc tools.
// shishi2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"ʯ��"NOR);
	set("long","������ʯ�ң�����Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"huangling6",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/lihun":5,	
	]));
	setup();
}

