// by jjyy

inherit ROOM;

void create()
{
	set("short", "南街一号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nanjie2",
	]));
	set("objects", ([
"/HELL4/GuaiWu3/G/guais" : 6,
	]));
	setup();
}