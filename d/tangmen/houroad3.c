//houroad3.c		�Ĵ����š���ʯС·

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
			"east" : __DIR__"houroad2",
			"west" : __DIR__"houroad4",
			"northwest" : __DIR__"biaofang",
			"southwest" : __DIR__"bcailiao",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
