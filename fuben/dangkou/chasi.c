//by ��ʼ�� qsh ednpc tools.
// chasi.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"��ʾ�"NOR);
	set("long","��������ʾ�ס��������Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"xiaolu7",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/shouling":1,
		//"fuben/wuguan/obj/baoxiang2":1,	
	]));
	setup();
}

