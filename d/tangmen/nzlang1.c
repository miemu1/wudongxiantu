//nzlang1.c		�Ĵ����š�����

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
			"south" : __DIR__"lianyunge",
			"north" : __DIR__"neiyuan",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
