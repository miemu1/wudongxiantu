// gold.c

#include <ansi.h>

inherit MONEY;
void create()
{
        set_name(HIW "8000��ʯ" NOR , ({"80yb",}));
        set_weight(400);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("money_id", "lm");
                set("long", "ʹ�û��8000��ʯ��\n");
                set("base_value", 500000000 );
                set("base_unit", "��");
                set("base_weight", 80);
				set("no_drop1", 1);

				set("no_drop", 1);
				set("no_sell", 1);
				set("no_give", 1);
				set("no_get", 1);
				set("no_steal", 1);
				set("tianji1", 1);
				set("only_do_effect", 1);
        }
        set_amount(1);
}

int do_effect(object me)
{

        message_vision("$N������8000��ʯ��\n" NOR, me);

        me->add("yuanbao",8000);
        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}