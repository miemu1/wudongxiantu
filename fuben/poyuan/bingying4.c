//by ��ʼ�� qsh ednpc tools.
// bingying4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ɹű�Ӫ");
	set("long","�������ɹű�Ӫ������Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"bingying5",
		"south" : __DIR__"bingying3",
	]));
	set("fuben2", 1);
	set("objects", ([
				__DIR__"npc/bing":2,
	]));
	setup();
}

