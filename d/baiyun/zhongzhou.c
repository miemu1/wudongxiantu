// Room: /d/fuzhou/zhongzhou.c

inherit ROOM;

void create()
{
	set("short", "皇宫后花园");
	set("long", @LONG
这里很久以前开满了无数野花。不知道什么时候起，花落了一次。再也没有开过。再往南就是禁地了，不过除了特定的几人谁也不知道入口在哪里，里面有什么。
LONG );
	set("exits", ([
		"north" : __DIR__"nanmen",
		//"south" : __DIR__"puxian",
	]));

	set("objects", ([
		"/kungfu/class/baiyun/ye" :1,
	]));
set("outdoors", "by");
	setup();
}

