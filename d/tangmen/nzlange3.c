//nzlange3.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long",
"����һ����ʯ�̾͵�С·��һЩ���ŵĵ��������������ﻹ���Ǻ�\n"
"���֡�������\n"
);
	set("exits", ([
			"west"  : __DIR__"nzlange2",
			"east"  : __DIR__"lianparry",
			"north" : __DIR__"lianthrow",
			"south" : __DIR__"liandodge",
	]));
	set("area", "����");
	set("outdoors", "����");
	setup();
//	replace_program(ROOM);
}
