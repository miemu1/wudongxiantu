#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload()
{
	return query_amount() + "";
}

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
        set_name(HIC "元神果" NOR, ({"yuanshen guo", "guo"}));
      set("suit_point", 100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIC "这是一颗蓝色的仙果，服用后能增强元神修为。\n" NOR);
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
				set("no_sell", 1);
				set("no_steal", 1);
                        set("no_give",1);
                        set("no_drop",1);
				set("jifeng",200);
                set("no_put", 1);
		set("unique",1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
        int exp;
        exp = 1000;

        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
			

        me->add("yuanshen/exp", exp);

        me->save();

        tell_object(me, HIG "你服下一颗元神果，元神修为增加：" + sprintf("%d", exp) + "点。\n");

        log_file("yuanshen-guoo", me->query("id") + " at " + ctime(time()) + " use yuanshen guo.\n");

	add_amount(-1);
	        if (query_amount() < 1)
                destruct(this_object());
	return 1;
}
