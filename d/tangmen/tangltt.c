//tangltt.c		�Ĵ����š���̫̫����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
"����������������̫̫�����ң��ܼ򵥣�û��ʲô�ر�\n"
);
	set("exits", ([
			"south" : __DIR__"nzlang3",
	]));
	set("area", "����");
        set("objects", ([
                CLASS_D("tangmen") + "/tangltt" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
