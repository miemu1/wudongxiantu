//nzlange1.c		�Ĵ����š���ʯС·

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
	        "north" : __DIR__"chaifang",
	        "west"  : __DIR__"nzlangn3",
	        "east"  : __DIR__"nzlange2",
	]));
	set("area", "����");
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
