inherit ROOM;

void create()
{
	set("short", "���Է�����");
	set("long", @LONG
���Է��䡣
LONG);

	set("exits", ([
		"west" : __DIR__"room4",
		"north" : __DIR__"room2",
		]));
	
	setup();
}