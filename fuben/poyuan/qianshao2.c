//by ��ʼ�� qsh ednpc tools.
// qianshao2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"�ɹ�ǰ��"NOR);
	set("long","�������ɹ�ǰ�ڣ�����Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"bingying9",
		"north" : __DIR__"bingying8",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/duizhang":1,
 // "fuben/wuguan/obj/baoxiang":1,			
	]));
	setup();
}

