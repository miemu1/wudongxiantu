// Room: /d/city/zuixianlou.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "醉仙楼");
	set("long", @LONG
	方圆数百里内提起醉仙楼可以说是无人不知，无人不晓。当年苏学士云
游到此，对醉仙楼的花雕酒赞不绝口，欣然为其题匾，流下一段传遍海内的佳话，
从此醉仙楼名声大震。楼下布置简易，顾客多是匆匆的行人，买点包子、鸡腿、
米酒就赶路去了。楼上是雅座。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"beidajie2",
  	"up" : __DIR__"zuixianlou2",
]));
	setup();
}

//是镜像
int is_mirror() { return 1; }