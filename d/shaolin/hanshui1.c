// Room: /d/shaolin/hanshui1.c
#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
	set("short", "汉水南岸");
	set("long", @LONG
面前是一条波涛翻滚的大江(river)。浊流滚滚，万舟竞发。
两岸渡船来来往往，江边一长溜摆满了鱼摊。过
去不远，是有名的老河口，不少过江客都在这里等待渡船摆渡。
LONG );
	set("exits", ([
		"south" : __DIR__"yidao2",
		"north" : "/d/death/sky/tianmen",
		
	]));

	set("item_desc", ([
		"【岸边】" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n"
			ZJOBACTS2"叫船:yell boat"ZJSEP"一苇渡江:cross\n",
	]));

	set("resource/fish", ({ "/clone/fish/liyu",
				"/clone/fish/jiyu",
				"/clone/fish/qingyu",
				"/clone/fish/caoyu", }));

	set("objects", ([
		__DIR__"npc/chuanfu1" : 1,
	]));

	set("outdoors", "nanyang");
	setup();
}

/* 在此付钱摆渡或买鱼吃 */
/*（等）渡船靠了岸，付了钱，船家一声吆喝，客人们一涌
 * 而入，小小渡船片刻间便越过波澜涛涛的汉江，靠上北岸
 */
void init()
{
	add_action("do_yell", "yell");
	add_action("do_cross", "cross");
}

void check_trigger()
{
	object room;

	if (! query("exits/enter"))
	{
		if (! (room = find_object(__DIR__"duchuan")))
			room = load_object(__DIR__"duchuan");
		if (room = find_object(__DIR__"duchuan"))
		{
			if ((int)room->query("yell_trigger") == 0)
			{
				room->set("yell_trigger", 1);
				set("exits/enter", __DIR__"duchuan");
				room->set("exits/out", __FILE__);
				message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
						  "板搭上堤岸，以便乘客上下。\n",
					this_object());
				message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
						  "的阶梯。\n", room);
				remove_call_out("on_board");
				call_out("on_board", 15);
			} else
				message("vision", "只听得江面上隐隐传来：“别急嘛，"
					"这儿正忙着呐……”\n",this_object());
		} else
		       message("vision", "ERROR: boat not found\n", this_object());
	} else 
		message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
			this_object());
}

void on_board()
{
	object room;

	if (! query("exits/enter")) return;

	message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向江心驶去。\n",
			  this_object());

	if (room = find_object(__DIR__"duchuan"))
	{
		room->delete("exits/out");
		message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
				  "竹篙一点，扁舟向江心驶去。\n", room );
	}
	delete("exits/enter");

	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;

	if (room = find_object(__DIR__"duchuan"))
	{
		room->set("exits/out", __DIR__"hanshui2");
		message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
				  "搭上堤岸。\n",room );
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;

	if (room = find_object(__DIR__"duchuan"))
	{
		room->delete("exits/out");
		message("vision","艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
		room->delete("yell_trigger"); 
	}
}

int do_yell(string arg)
{
	string dir;

	if (! arg || arg == "" ) return 0;

	if (arg == "boat" ) arg = "船家";
	if ((int)this_player()->query("age") < 16)
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
			       this_player());
	else
	if ((int)this_player()->query("neili") > 500)
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
			       "了出去。\n", this_player());
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
			       this_player());
	if (arg == "船家")
	{
		check_trigger();
		return 1;
	} else
		message_vision("江面上远远传来一阵回声：“" + arg +
			       "～～～”\n", this_player());
	return 1;
}

void reset()
{
	object room;

	::reset();
	if (room = find_object(__DIR__"duchuan"))
		room->delete("yell_trigger"); 
}

int do_cross()
{
	object me;

	me = this_player();
	if (! me->query_skill("shaolin-shenfa", 1))
	{
		tell_object(me, "你大眼一瞪？干什么，跳河自杀么？\n");
		return 1;
	}

	if (me->query_skill("shaolin-shenfa", 1) < 150)
	{
		tell_object(me, "你掂量了一下，觉得自己一苇"
			    "渡江的绝技还没有炼到家。\n");
		return 1;
	}

	if (me->query("neili") < 120)
	{
		tell_object(me, "你的内力不够，还是休息一下再说吧。\n");
		return 1;
	}

	me->add("neili", -90);

	message_sort(HIW "$N" HIW"身形一晃，轻飘飘的落入汉水"
		     "，只见$P" HIW"轻踩水面，甚是逍遥，竟然"
		     "是达摩祖师传下的少林绝技“一苇渡江”！"
		     "众人不及惊叹，$N" HIW "已经踏波远去。"NOR"\n", me);
	tell_object(me, "你顺利的到达了彼岸！\n");
	me->move(__DIR__"hanshui2");
	message("vision", "忽见水面上雾气散开，一人踏波逐浪，"
		"竟然大踏步掠过江来！\n", environment(me), ({ me }));
	return 1;
}
