// Room: /d/fuzhou/ximen.c
inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
传出阵阵阴森的感觉，细细品味又使人宁静，十分怪异。
LONG );
	set("exits", ([
		"east" : __DIR__"ximendajie",
		"south" : __DIR__"fzroad11",
	]));
	set("outdoors", "by");
	setup();
}

