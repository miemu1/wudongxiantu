#include <armor.h>
#include <ansi.h>

inherit HEAD;
 
void create()
{
        set_name(HIG "剑灵之怒" NOR, ({ "jianling zhinu", "zhinu", }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("long", HIG "这是由黑曜石和剑灵的怒气结晶而成的头箍，阵阵光芒令人生畏。\n" NOR);
                set("xy_money", 300);
                set("armor_prop/dex", 10);
                set("armor_prop/str", 10);               
        }
        setup();
}

int query_autoload()
{
        return 1;
}
