//houyuan.c		�Ĵ����š���Ժ

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long",
"���������Ƹ��Ժ������徰�ĵ�԰����������һ�غ��������ѵ�ˮ\n"
"���۵����ƣ����ⷺ����׹ɺɺ����ѿ�ƾɣ������к��������żţ���Ҷ\n"
"һҡ�������Ƕ�һƬһƬ�ķָ��Ӱ������ͨ�����ŵ��ڷ��Ͷ�����\n"
);
	set("exits", ([
                "east" : __DIR__"houroad4",
                "north" : __DIR__"mishi",
	]));
	set("objects", ([
                 CLASS_D("tangmen") + "/tangao" : 1,
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
