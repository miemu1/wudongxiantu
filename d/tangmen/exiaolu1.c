//exiaolu1.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long",
"�����Ǻ�ɽС·��ֻ��һ��ͨ���������Ӳݴ�������ʱ����ϤϤ����\n"
"�Ĳ�������ż������һ��ֻС��������ǰ�ӹ���С·������������ǰ��ȥ��\n"
"ͨ����������ĺ�ɽ��\n"
);
	set("exits", ([
			"south" : __DIR__"chaifang",
			"east" : __DIR__"exiaolu2",
	]));
	set("area", "����");
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
