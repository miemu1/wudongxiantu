//wting.c		�Ĵ����š���ƫ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ƫ��");
	set("long",
"���������Ƹ������ƫ����һЩ���ŵ���ϲ�������ﺣ����գ�����\n"
"��̸�����ڰ������������Σ�����Ϫ����������ľ�дС���˵��������Ư\n"
"������λŮ���ӣ����������ǻ���ĬĬ��˼������Զ�������ɡ�\n"
);
	set("exits", ([
                "east" : __DIR__"lianyunge",
	]));
        set("objects", ([
                CLASS_D("tangmen") + "/tangfang" : 1,
        ]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
