//by ��ʼ�� qsh ednpc tools.
// bingying11.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ɹű�Ӫ");
	set("long","�������ɹű�Ӫ������Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"chukou",
		"south" : __DIR__"bingying12",
		"north" : __DIR__"bingying9",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/bing":2,
	]));
	setup();
}

