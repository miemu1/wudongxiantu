//by ��ʼ�� qsh ednpc tools.
// bingying7.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ɹű�Ӫ");
	set("long","�������ɹű�Ӫ������Ա��δ�趨������ϸ������");
	set("exits", ([
		"north" : __DIR__"bingying6",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/bing":1,
	]));
	setup();
}

