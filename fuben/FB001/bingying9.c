//by ��ʼ�� qsh ednpc tools.
// bingying9.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ɹű�Ӫ");
	set("long","�������ɹű�Ӫ������Ա��δ�趨������ϸ������");
	set("exits", ([
		"south" : __DIR__"bingying11",
		"north" : __DIR__"bingying10",
		"west" : __DIR__"qianshao2",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/bing":2,
	]));
	setup();
}

