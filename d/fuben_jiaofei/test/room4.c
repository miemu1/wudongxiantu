inherit ROOM;

void create()
{
	set("short", "���Է�����");
	set("long", @LONG
���Է��䡣
LONG);

	set("exits", ([
		"east" : __DIR__"room3",
		"north" : __DIR__"room1",
		]));
	
	setup();
}