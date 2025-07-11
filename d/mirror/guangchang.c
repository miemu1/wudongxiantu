// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "中央广场");
    set("long", @LONG
    这里是城市的正中心，一个很宽阔的广场，铺着青石地面。一些游手好闲
的人在这里溜溜达达，经常有艺人在这里表演。中央有一棵大榕树，盘根错节，据
传已有千年的树龄，是这座城市的历史见证。树干底部有一个很大的洞(shudong)。
你可以看到北边有来自各地的行人来来往往，南面人声鼎沸，一派繁华景象，东边
不时地传来朗朗的读书声，西边则见不到几个行人，一片肃静。大树上挂一块大牌

                        　[1;33mＮＯＴＩＣＥ[2;37;0m

LONG
    );
        set("outdoors", "city");
    set("item_desc", ([
        "shudong" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n",
        "榕树"  :   "一棵枝叶茂盛的大榕树，看来似乎可以爬(climb)上去。\n",
        "大榕树":   "一棵枝叶茂盛的大榕树，看来似乎可以爬(climb)上去。\n",
        "树"    :   "一棵枝叶茂盛的大榕树，看来似乎可以爬(climb)上去。\n",
        "tree"  :   "一棵枝叶茂盛的大榕树，看来似乎可以爬(climb)上去。\n",
    ]));
    set("exits", ([
        "east" : __DIR__"dongdajie1",
        "south" : __DIR__"nandajie1",
        "west" : __DIR__"xidajie1",
        "north" : __DIR__"beidajie1",
	"down" : __DIR__"drop",
    ]));
    setup();
}

void init()
{
        add_action("do_climb", "climb");
}
  
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
    me=this_player();
        if( !arg || arg!="up") return notify_fail("你要往哪个方向爬？\n");

    if (me->query("gender")!="女性")
    message("vision",
        me->name() + "战战兢兢地拉着大榕树的盘根，屁股一扭一扭地往上爬。\n",
        environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "轻轻一跳，衣裙飘飘，象仙子般飞上大榕树。\n",
        environment(me), ({me}) );
    else message("vision",
        me->name() + "战战兢兢的抓住树干往上爬去。\n", environment(me), ({me}) );
                me->move(__DIR__"chatroom");
    if (me->query("gender")!="女性")
        message("vision",
        me->name() + "气喘嘘嘘地爬了上来。\n",
                environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision","一阵清香飞来，你定眼一看，"+
        me->name() + "已经婷婷玉立在你眼前。\n",
        environment(me), ({me}) );
    else  message("vision", me->name() + "战战兢兢地从下面爬了上来。\n", environment(me), ({me}) );   
    return 1;
}
//是镜像
int is_mirror() { return 1; }
