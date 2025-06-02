#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

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
	set_name(HIM"����"NOR, ({"z0925"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);

		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","����һ������ެ������ԭ��"HIG"����"NOR"���������ᷢ����ֵ����飡(Ǳ��+2000)\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
  	me->add("combat_exp", 1555);	
	me->add("potential", 1555);
	me->add("experience", 1555/4);
	me->add("score", 1555/4);
	me->add("weiwang", 1555/4);
	me->add("gongxian",1);
    me->add("shimen/today",1);
    TOP_D->add_shimen(me);
	return 1;
}