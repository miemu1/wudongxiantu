//by ���� ranger's ednpc tools.
// xiuxishi.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"��Ϣ��"NOR);
	set("long","��������Ϣ�ң�����Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"east" : __DIR__"lianwuchangb",
		"north" : __DIR__"lianwuchanga",
	]));
	set("objects", ([
	__DIR__"npc/wuguan_jiaotou":5,
	//__DIR__"obj/baoxiang":1,	
	]));
	setup();
}

