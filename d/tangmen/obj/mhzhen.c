//mhzhen.c

#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name("÷����", ({ "meihua zhen", "zhen" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("base_unit", "��");
                set("base_weight", 100);
                set("base_value", 200);
                set("material", "steel");
                set("long", "һ��ϸ��ţë���롣\n");
                                
        }
       set_amount(50);
       init_throwing(50);
       setup();
}
