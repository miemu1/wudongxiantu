// gold.c

#include <ansi.h>

inherit MONEY;
void create()
{
        set_name(HIW "���粹��1" NOR , ({"jjbc1",}));
        set_weight(400);
        if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("base_value", 100000000);
            set("no_sell",1);
			set("no_sell",1);
			set("no_give",1);
		 set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("long","����һ�ž��粹���ĵ�ҩ"NOR"��\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
if (me->query("jingjie/yiliu"))
			
			me->add("max_qi",50000);
			me->add("max_jingli",50000);
	add_amount(-1);
	return 1;
	}