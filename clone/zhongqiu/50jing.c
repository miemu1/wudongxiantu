// gold.c

#include <ansi.h>

inherit MONEY;
void create()
{
        set_name(HIW "+50����ʯ" NOR , ({"50jinglianshi",}));
        set_weight(400);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("money_id", "lm");
                set("long", "ʹ�ÿ�ʹ����װ���ܼӳɵȼ�����50����\n");
                set("base_value", 500000000 );
                set("base_unit", "��");
                set("base_weight", 80);
				set("no_drop1", 1);

				set("no_drop", 1);
				set("no_sell", 1);
				set("no_give", 1);
				set("no_get", 1);
				set("no_steal", 1);
				set("tianji1", 100);
				set("only_do_effect", 1);
        }
        set_amount(1);
}

int do_effect(object me)
{

        message_vision("$Nʹ����һ��+50����ʯ����װ���ܼӳɵȼ�������50�������µ�¼��Ч��\n" NOR, me);

        me->add("taozhuang/lv",50);
        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}