//nzlange2.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long",
"����һ����ʯ�̾͵�С·��������������������̫�࣬�ֲڵ���ʯ��\n"
"����ĥ�Ĺ⻬�羵��һЩ���ŵĵ��������������ﻹ���Ǻ����֡�\n"
);
	set("exits", ([
	        "north" : __DIR__"bingqifang",
		"south" : __DIR__"fangjvfang",
	        "east"  : __DIR__"nzlange3",
	        "west"  : __DIR__"nzlange1",
	]));
        set("objects", ([
                CLASS_D("tangmen") + "/tangjue" : 1,
        ]));
	set("area", "����");
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
