// Room: /lingzhou/xuanhebao.c
#include <room.h>

inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
	set("short", "宣和堡");
	set("long", @LONG
这里就是西北小镇宣和堡，南面是黄河，西面是沙漠，只有这里
有一片不大的绿洲，住户们都是从关内迁移过来的，大多以经营手工
艺品为生, 这里的手织羊毛挂毯颇有名气。每逢初一、十五附近的百
姓都来到这摆渡过河到关内去赶集。河案边熙熙攘攘，人们都在挣着
叫(yell)船过河。
LONG	);
	set("exits", ([
		"northeast" : __DIR__"mingshazhou",
		"west"  : "d/xuanminggu/xiaolu1",
	]));
	set("item_desc", ([
		"【岸边】" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n"
			ZJOBACTS2"叫船:yell boat\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
}

void init()
{
	add_action("do_yell", "yell");
}

void check_trigger()
{
	object room;

    if(!query("exits/enter") ) {
	if( !(room = find_object("/d/huanghe/duchuan")) )
	    room = load_object("/d/huanghe/duchuan");
	if( room = find_object("/d/huanghe/duchuan") ) {
	    if((int)room->query("yell_trigger")==0 ) {
		room->set("yell_trigger", 1);
		set("exits/enter", "/d/huanghe/duchuan");
		room->set("exits/out", __FILE__);
		message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
		    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
		message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
		    "的阶梯。\n", room);
		remove_call_out("on_board");
		call_out("on_board", 15);
	    }
	    else
		message("vision", "只听得风浪中隐隐传来：“别急嘛，"
		    "这儿正忙着呐……”\n",this_object() );
	}
	else
	    message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
	message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
	    this_object() );
}

void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向河中撑去。\n",
	this_object() );

    if( room = find_object("/d/huanghe/duchuan") )
    {
	room->delete("exits/out");
	message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
	    "竹篙一点，扁舟向\n河中撑去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object("/d/huanghe/duchuan") )
    {
	room->set("exits/out", "/d/huanghe/guchangcheng");
	message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
	    "搭上堤岸。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object("/d/huanghe/duchuan") ) {
	room->delete("exits/out");
	message("vision","艄公把踏脚板收起来，把扁舟撑向河近岸。\n", room);
	room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "船家";
    if( (int)this_player()->query("age") < 16 )
	message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
	    this_player());
    else if( (int)this_player()->query("neili") > 500 )
	message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
	    "了出去。\n", this_player());
    else
	message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
	    this_player());
    if( arg=="船家")
    {
	check_trigger();
	return 1;
    }
    else
	message_vision("风浪中远远传来一阵回声：“" + arg +
	    "～～～”\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object("/d/huanghe/duchuan") )
	room->delete("yell_trigger"); 
}
