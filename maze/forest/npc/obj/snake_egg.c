#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name("�ߵ�", ({"snake egg"}) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "�ߵ���\n" NOR);
                set("base_unit", "��");
                set("base_value", 20000);
                set("base_weight", 600);
        }
        set("maze_item", 1);
	setup();
        set_amount(1);
}
