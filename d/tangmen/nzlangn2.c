//nzlangn2.c		�Ĵ����š���ʯС·

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
			"south" : __DIR__"nzlangn1",
			"north" : __DIR__"nzlangn3",
	]));
	set("area", "����");
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
