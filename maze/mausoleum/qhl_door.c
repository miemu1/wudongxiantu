#include <ansi.h>
inherit ITEM;

void create()
{

        set_name(HIY"秦皇陵"NOR, ({ "qinhuang door","door"}) );
        set_weight(99999);
        set("no_sun",1);
set("value", 5000);
set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"从这个入口可以进入秦皇陵。(enter door)\n"NOR);
                set("long","挑战每次需要300阅历300威望"ZJURL("cmds:enter door")ZJSIZE(15)""HIR"进入"NOR"修为最低进入条件all sk > 150级!\n");
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
	if (me->query("score")<300)
             return notify_fail("你的江湖阅历太低,无法进入。\n");
	if (me->query("combat_exp")<1000000)
             return notify_fail("你的修为不足百万,别去送死了。\n");
	if (me->query("weiwang")<300)
             return notify_fail("你的江湖威望太低,无法进入。\n");

        me->add("score", -(300));
        me->add("weiwang", -(300));
        this_player()->delete_temp("maze");
        time = this_player()->query_temp("maze/time")+180-time();
        if(time>0)
                return notify_fail("你还需要等"+CHINESE_D->chinese_period(time)+"才能进入副本。\n");
        MAZE_D->enter_maze(this_player(), "qhl");
        return 1;
}

