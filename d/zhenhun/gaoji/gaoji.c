// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "高级区入口");
	set("long", "500-1000w");
	set("exits", ([
	"west" : "d/zhenhun/zhongji/zhongji",
	"north" : __DIR__"gaoji1",
	]));
	set("objects", ([
	]));
	setup();
}

/*int valid_leave(object me, string dir)
{
	if (dir == "north" &&  me-> query("combat_exp") < 5000000 && me->query("combat_exp") < 10000000)
		return notify_fail(HIY"只有500-1000w才可进入！！\n"NOR);
	return ::valid_leave(me, dir);
}*/