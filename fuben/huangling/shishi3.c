//by ��ʼ�� qsh ednpc tools.
// shishi3.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"ʯ��"NOR);
	set("long","������ʯ�ң�����Ա��δ�趨������ϸ������");
	set("exits", ([
		"west" : __DIR__"huangling11",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/lihun":5,	
	]));
	setup();
}

