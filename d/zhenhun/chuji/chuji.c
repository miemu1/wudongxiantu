// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "初级区入口");
	set("long", "100w以下");
	set("exits", ([
	"south" : "d/zhenhun/enter",
	"east" : "d/zhenhun/zhongji/zhongji",
	"north" : __DIR__"chuji1",
	]));
	set("objects", ([
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" &&  me->query("combat_exp")>1000000)
		return notify_fail(HIY"100w修为以下！！！\n"NOR);
	return ::valid_leave(me, dir);
}