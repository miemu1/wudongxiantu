//by ��ʼ�� qsh ednpc tools.
// bingying3.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ɹű�Ӫ");
	set("long","�������ɹű�Ӫ������Ա��δ�趨������ϸ������");
	set("exits", ([
		"north" : __DIR__"bingying4",
		"west" : __DIR__"junying",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/bing":2,
	]));
	setup();
}

