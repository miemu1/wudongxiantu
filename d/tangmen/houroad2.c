//houroad2.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long",
"�����Ǻ�լ�������ʯС·�������Ŀ�������Զ������������ˮ��\n"
"��չĿ��ȥ�Ѿ����Կ����ڷ���ҡ�ڵ�ƬƬ��Ҷ��һ����紵������һ��\n"
"�ɻ����㡣\n"
);
	set("exits", ([
			"west" : __DIR__"houroad3",
			"east" : __DIR__"houroad1",
			"northwest" : __DIR__"yaofang",
			"southwest" : __DIR__"ycailiao",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
