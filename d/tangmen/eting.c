//eting.c		�Ĵ����š���ƫ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ƫ��");
	set("long",
"���������Ƹ󶫲��ƫ����һЩ���ŵ���ϲ�������ﺣ����գ�����\n"
"��̸�����ڰ������������Σ�����Ϫ����������ľ�дС�һ��д�������\n"
"��Ϣ������Ʈ��������е�����Ϊ֮һˬ��\n"
);
	set("exits", ([
             "west" : __DIR__"lianyunge",
	]));
        set("objects", ([
                CLASS_D("tangmen") + "/tangque" : 1,
        ]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
