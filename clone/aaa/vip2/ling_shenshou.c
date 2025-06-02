
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
	set_name(HIY "��֮����[��]" NOR, ({ "shenshou ling" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����ƣ�ƾ�����ƿ�����ս������һ�Σ�\n");
		set("base_unit", "��");
		set("base_value", 500000);
		set("yuanbao", 100);
        set("max_buy",1);
		 set("no_give",1);
		 set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
		set("value", 20000);
		set("base_weight", 1);
	}
	setup();
}

