//by ��ʼ�� qsh ednpc tools.
// zhudian.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY"��������"NOR);
	set("long","�����ǻ����������Ա��δ�趨������ϸ������");
	set("exits", ([
		"north" : __DIR__"chukou",
		"east" : __DIR__"huangling12",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/dihun":5,	
	]));
	setup();
}

