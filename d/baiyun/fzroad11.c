// Room: /d/fuzhou/fzroad11.c
inherit ROOM;

void create()
{
	set("short", "吹雪居");
	set("long", @LONG
这里便是阴森的源头。原来有人在练剑。剑法无比的冷。孤独，仔细一看原来是个剑影，却不知主人如今何在!
LONG );
	set("exits", ([
		"north"   : __DIR__"ximen",
	]));
	set("objects", ([
			"/kungfu/class/baiyun/ximen" : 1,
	]));

	setup();
}

