//biaofang.c		�Ĵ����š��ڷ�

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",
"���������ŵİ�������һ̤�����ű�е�һ������ӭ��������������\n"
"�еļ����޴��������Ŀ�����������������������ţ������漤������\n"
"�ߣ����ŵ����ڸ�����������ȫ���ע�Ĵ�����ʲô��\n"
);
	set("exits", ([
			"southeast" : __DIR__"houroad3",
	]));
	set("objects", ([
	        __DIR__"npc/tangbiao" : 1,
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
