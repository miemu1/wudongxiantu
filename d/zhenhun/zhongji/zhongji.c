// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "中级区入口");
	set("long", "100-500w");
	set("exits", ([
	"west" : "d/zhenhun/chuji/chuji",
	"east" : "d/zhenhun/gaoji/gaoji",
	"north" : __DIR__"zhongji1"
	]));
	set("objects", ([
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" &&  me-> query("combat_exp") < 1000000 && me->query("combat_exp") < 5000000)
		return notify_fail(HIY"只有100-500w才可进入！！\n"NOR);
	return ::valid_leave(me, dir);
}