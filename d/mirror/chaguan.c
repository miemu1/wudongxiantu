// Room: /city/chaguan.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "春来茶馆");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字排开，
坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，这里是个好
所在。老板娘不时从旁边的一口小水井(well)中取水上来，烧水冲茶。
LONG
	);
	set("resource/water", 1);
	set("item_desc", ([
		"well" : "井虽小，如果有容器盛(fill)点清凉的井水，相信阿庆嫂也不会反对的。\n",
	]));
	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	setup();
}
//是镜像
int is_mirror() { return 1; }