// Room: /city/kedian2.c

inherit ROOM;

void create()
{
	set("short", "���¥");
	set("long", @LONG
�����������������¥����˵ÿ��һ��ʱ�䣬������˾ͻ�����һ�Ρ�
LONG );
	set("exits", ([
		"north"  : __DIR__"kedian",
	]));

	set("no_fight", 1);
	set("objects", ([
		 "/d/city/npc/tianji"    : 1,

	]));


	setup();
}