inherit ROOM;

void create()
{
	set("short", "���Է���һ");
	set("long", @LONG
���Է��䡣
LONG);

	set("exits", ([
		"east" : __DIR__"room2",
		"south" : __DIR__"room4"
		]));
	
	setup();
}