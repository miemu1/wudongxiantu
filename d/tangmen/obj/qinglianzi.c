#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name("������", ({ "qing lianzi", "lianzi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",2000);
                set("base_unit", "��");
                set("base_weight",20);
                set("base_value", 80);
                set("material", "stone");
                set("long", "һ������������һ����Բʯͷ��\n");
                
        }
       set_amount(25);
       init_throwing(20);
       setup();
}
