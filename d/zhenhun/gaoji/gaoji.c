// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "�߼������");
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
		return notify_fail(HIY"ֻ��500-1000w�ſɽ��룡��\n"NOR);
	return ::valid_leave(me, dir);
}*/