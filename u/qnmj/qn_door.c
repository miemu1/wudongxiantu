#include <ansi.h>
inherit ITEM;

void create()
{
                
        set_name(HIY"初级潜能"NOR, ({ "qn1 door","door"}) );
        set_weight(99999);
        set("no_sun",1);
set("value", 5000);
set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"从这个入口可以进入初级潜能。(enter door)\n"NOR); 
                set("long","挑战每次需要100点券"ZJURL("cmds:enter door")ZJSIZE(15)""HIR"进入"NOR"修为最低进入条件武学修养 > 400级!\n");
                set("unit", "个");
                set("lore",1);
        }
        setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg) 
{
        int time;
        object me = this_player();
        if (arg!="door")
                return 0;

	if (me->query("combat_exp")<1000000) 
             return notify_fail("你的修为不足一百万,别去送死了。\n");
	if (me->query_skill("martial-cognize", 1) < 200)
             return notify_fail("武学修养不足400,无法进入。\n");
	if (me->query("suit_jifeng")<10) 
             return notify_fail("你的点券不足,无法进入。\n");
	//if (me->query("gongji")<30) 
            // return notify_fail("你的功绩不足,无法进入。\n");

	

        me->add("suit_point", -(100));
        me->add("gongji", -(30));
        this_player()->delete_temp("maze");
        time = this_player()->query_temp("maze/time")+180-time();
        if(time>0)
                return notify_fail("你还需要等"+CHINESE_D->chinese_period(time)+"才能进入副本。\n");
        MAZE_D->enter_maze(this_player(), "qnmj");
        return 1;
}

