// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", "100w����");
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
		return notify_fail(HIY"100w��Ϊ���£�����\n"NOR);
	return ::valid_leave(me, dir);
}