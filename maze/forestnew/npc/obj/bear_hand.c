
#include <ansi.h>

inherit COMBINED_ITEM;
#include "/clone/quarry/item/meat.h"

void create()
{
        set_name("����", ({ "bear hand" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ɢ���������������⡣\n" NOR);
                set("base_unit", "��");
                set("base_value", 80);
        }
        set("maze_item", 1);
	setup();
        set_amount(1);
}
