#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIG "剑灵之力" NOR, ({ "jianling zhili", "zhili"}) );
        set_weight(1);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("unit", "张");
                set("long", HIG "这是一张淡蓝色的护符，其外形有如蝴蝶翅膀一般。\n" NOR);
                set("xy_money", 300);
                set("armor_prop/int", 10);              
        }
        setup();
}

int query_autoload()
{
        return 1;
}
