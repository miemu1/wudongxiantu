// Room: /d/fuzhou/nanmendou.c
inherit ROOM;
void create()
{
	set("short", "皇宫");
	set("long", @LONG
这里便是白云城城主所在。不意外，一片冷清。你感受到阵阵孤独。
LONG );
	set("exits", ([ /* sizeof() == 1 */
	    "north"  : __DIR__"nandajie",
	    "south"  : __DIR__"nanmen",
	    //"west"   : __DIR__"shiqiao",
	   // "east"   : __DIR__"xiaochang",
	]));
	set("item_desc", ([
	  //  "【榕树】"   : "一颗巨大的古榕，下边树根部有一个深邃幽暗的洞穴。\n"
		//ZJOBACTS2"钻洞:enter dong\n",
	]));
	set("outdoors", "by");
	setup();
}

void init()
{
	//add_action("do_enter", "enter");
	//add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;

	me = this_player();
	if (! arg || arg == "") return 0;
	if (arg == "dong")
	{
		if (me->query("family/family_name") == "丐帮")
		{
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
				environment(me), me);
			me->move("/d/gaibang/underfz");
			message("vision",
				me->name() + "从洞里走了进来。\n",
				environment(me), ({me}) );
			return 1;
		} else
			return notify_fail("这么小的洞，你钻得进去吗？\n");
       }
}
