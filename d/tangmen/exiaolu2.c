//exiaolu2.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long",
"�����Ǻ�ɽС·����·Խ��Խխ���Ӳ�ȴ����ï���Ѿ������߰���ʱ\n"
"��Զ������������Х������ͷƤ���飬С·������������ǰ��ȥͨ�����\n"
"�����ĺ�ɽ��\n"
);
	set("exits", ([
			"west" : __DIR__"exiaolu1",
			"eastup" : __DIR__"houshan",
	]));
	set("area", "����");
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
