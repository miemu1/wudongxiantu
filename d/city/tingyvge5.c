

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�һ���");
	set("long","���ַ������Һθɣ������ڴ�̸���۵ء�");
	set("close_vip666", 1);
	set("no_fight", 1);
	set("close_room", 1);

	set("valid_startroom", 1);
	set("action_list", ([
		HIY"���������"NOR:"update /d/city/tingyvge",
	]));
	set("exits", ([
		"north": __DIR__"tingyvge2",


	]));
	set("no_sleep_room",1);
	setup();
}
