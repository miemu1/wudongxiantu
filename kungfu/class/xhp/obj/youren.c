#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name(HIC"���̼�"NOR, ({ "youren jian", "arrow" }) );
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("long", "���̼�����������Ƶ����͡�\n");
                set("unit", "��");
                set("base_value", 2100);
                set("material", "steel");
		    set("no_sell", 1);
                set("base_unit", "ö");
                set("base_weight", 10);
        }
        set_amount(10);
        init_throwing(600);
        setup();
}

