
#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name("�ɻ�ʯ", ({ "feihuang shi", "shi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("base_unit", "��");
                set("base_weight", 100);
                set("base_value", 25);
                set("material", "stone");
                set("long", "һ�������нǵ�ʯͷ��\n");
                
        }
       set_amount(20);
       init_throwing(5);
       setup();
}

