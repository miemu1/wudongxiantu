//nzlangw2.c		�Ĵ����š���ʯС·

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
			"east" : __DIR__"nzlangw1",
			"west" : __DIR__"nzlangw3",
			"north" : __DIR__"jingshi1",
			"south" : __DIR__"jingshi2",
	]));
	set("area", "����");
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
