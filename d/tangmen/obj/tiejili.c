#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name("����޼", ({ "tie jili", "jili" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1000);
                set("base_unit", "��");
                set("base_weight", 100);
                set("base_value", 40);
                set("material", "steel");
                set("long", "һ����â�̵�����\n");
                
        }
       set_amount(25);
       init_throwing(10);
       setup();
}
