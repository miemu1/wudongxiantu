//jingshi1.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
"����һ�侲�ҡ����������ŵ������ɡ������ĵط�������ǳ�������\n"
"û��һ˿����������û���κΰ��裬ֻ���ڵ�������ʮ���������м�����\n"
"������������������������\n"
);
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
	        "south" : __DIR__"nzlangw2",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
