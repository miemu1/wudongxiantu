//by ��ʼ�� qsh ednpc tools.
// bingying.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ɹű�Ӫ");
	set("long","�������ɹű�Ӫ������Ա��δ�趨������ϸ������");
	set("exits", ([
		"north" : __DIR__"qianshao",
		"south" : __DIR__"bingying2",
		"west" : __DIR__"enter",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/bing":2,
	]));
	setup();
}

