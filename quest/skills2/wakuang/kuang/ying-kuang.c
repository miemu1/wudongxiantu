// ying-kuang.c 银矿石
// 星星lywin 2000/6/15

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"银矿石"NOR,({"ying kuang", "kuang"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
				set("no_put",1);
				set("no_get",1);
				set("no_give",1);
				set("no_steal",1);
				set("kuang",1);
				set("power_point",3);
                set("long", "这是一块沉重的银矿石，"ZJURL("cmds:zhuanhuan ying kuang")ZJSIZE(15)""HIY"熔炼"NOR"。\n");
             }
        setup();
}
