//by ��ʼ�� qsh ednpc tools.
// junying.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"�ɹž�Ӫ"NOR);
	set("long","�������ɹž�Ӫ������Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"bingying3",
		"north" : __DIR__"bingying2",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/tongling":1,	
   // "fuben/wuguan/obj/baoxiang2":1,	
	]));
	setup();
}

