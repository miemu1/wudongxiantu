//shandao4.c		�Ĵ����š���ɽɽ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long",
"������ͨ��ɽ����С�����涸�ޱȣ�һ��С�ľͻ�ˤ��ȥ�������Ǹ�\n"
"�����ƵĲ��������Խ�ӽ�ɽ���¶�Խ���ˣ���۽��½��Ըе��������ˡ�\n"
);
	set("exits", ([
			"northup" : __DIR__"shandao5",
			"southwest" : __DIR__"shandao3",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/qingshe" : 1,__DIR__"npc/jinshe" : 1,]));
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
