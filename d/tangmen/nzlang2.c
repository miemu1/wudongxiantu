//nzlang2.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
"���������Ƹ󱱲�����ȡ������Ǳ��̵ĺ�ˮ�������ɻ��������ţ�\n"
"��������������������ֹ����ǰ������ͨ�����Ƹ��լ��\n"
);
	set("exits", ([
			"south" : __DIR__"houzhai",
			"north" : __DIR__"nzlang3",
			"west" : __DIR__"tangwen",
			"east" : __DIR__"tanggan",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
