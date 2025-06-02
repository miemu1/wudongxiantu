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
	set_name(YEL"500������"NOR, ({"n d"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("kedian", 2000);
            set("no_sell",1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","����һ�ż�500�����ĵ�ҩ"NOR"��\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->add("max_neili",500);
	write(YEL"��������500������!"NOR"\n");
	add_amount(-1);
	return 1;
}