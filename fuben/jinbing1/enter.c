// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG

LONG
	);
	set("fuben2",1);	
	set("exits", ([
		"east" : __DIR__"xiaolu",
	]));
	set("no_clean_up", 1);
	set("objects", ([
	]));
	setup();
}
int no_reset() {return 1;}


