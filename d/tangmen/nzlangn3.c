//nzlangn3.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long",
"����һ����ʯ�̾͵�С·��������������������̫�࣬�ֲڵ���ʯ��\n"
"����ĥ�Ĺ⻬�羵��һЩ���ŵĵ��������������ﻹ���Ǻ����֡�����\n"
"��ͨ��������������������Ů���ӵ���Ϣ���ˡ�\n"
);
	set("exits", ([
			"west"  : __DIR__"nzlangw1",
			"south" : __DIR__"nzlangn2",
			"east"  : __DIR__"nzlange1",
	]));
	set("area", "����");
        set("outdoors", "����"); 
        setup();
	replace_program(ROOM);
}

