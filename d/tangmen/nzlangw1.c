//nzlangw1.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long",
"����һ����ʯ�̾͵�С·��������������������̫�࣬�ֲڵ���ʯ��\n"
"����ĥ�Ĺ⻬�羵��һЩ���ŵĵ��������������ﻹ���Ǻ����֡�������\n"
);
	set("exits", ([
			"north" : __DIR__"houroad1",
//			"south" : __DIR__"liangong",
			"west" : __DIR__"nzlangw2",
			"east" : __DIR__"nzlangn3",
	]));
	set("area", "����");
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
