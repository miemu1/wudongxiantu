//ycailiao.c		�Ĵ����š����Ϸ�

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���Ϸ�");
	set("long",
"���������Ŵ�������ҩ����ϵķ��䡣���Ű���������˫�����˰���\n"
"�ַ�֮�⣬�������Ƹ���ҩ��Ĳ��ϣ��ǹ�����û��������ȡ�ߵģ�����\n"
"ͨ��ҩ����ϣ�����Щ�����߳����ŵ�ʱ�򣬶��������ľ�������������\n"
"��һ����ʯС·��\n"
);
	set("exits", ([
			"northeast" : __DIR__"houroad2",
	]));
	set("objects", ([
	        __DIR__"npc/yjiading" : 1,
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
