//bcailiao.c		�Ĵ����š��ڷ�

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���Ϸ�");
	set("long",
"���������Ŵ������찵�����ϵķ��䡣���ڣ����룬�ɻ�ʯ������޼\n"
"�������⣬���裬�ɵ���û��������붤�ȵȵȵȣ����п���˵��������\n"
"�������������ϣ�������������Ѱ��������Ӱ����������һ����ʯС·��\n"
);
	set("exits", ([
                "northeast" : __DIR__"houroad3",
	]));
	set("objects", ([
	        __DIR__"npc/bjiading" : 1,
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
