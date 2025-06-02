// Room: /d/mingjiao/donglu.c

#include <room.h>
inherit ROOM;

int query_rate();

void create()
{
	set("short", "�����ľ�");
	set("long", @LONG
���ﶼ��һЩǧ���ľ������ߴ�ïʢ���˼������������ޱȡ�
������Ȼ�о���Щ�������Ĳ���������ǸϿ��뿪����Ϊ�á�
LONG );
	set("exits", ([
		"south" : __DIR__"donglu",
	]));

	set("insects/bingcan", (: query_rate :));
	set("action_list",([
		"̽��":"tanyou",
	]));
	set("outdoors", "mingjiao");
	setup();
}

void init()
{
	add_action("do_tanyou","tanyou");
}
 
int do_tanyou(string arg)
{
	return notify_fail("��δ���ţ�\n");
}

int query_rate()
{
	object me;

	if (present("shenmu wangding", this_object()))
		return 3000;
	else
		return 500;

	return 0;
}
