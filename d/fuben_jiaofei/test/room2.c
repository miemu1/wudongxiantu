inherit ROOM;

void create()
{
	set("short", "���Է����");
	set("long", @LONG
���Է��䡣
LONG);

	set("exits", ([
		"west" : __DIR__"room1",
		"south" : __DIR__"room3",
		]));
	
	setup();
}