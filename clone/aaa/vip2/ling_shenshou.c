
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
	set_name(HIY "神之令牌[绑]" NOR, ({ "shenshou ling" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一块令牌，凭此令牌可以挑战四神兽一次！\n");
		set("base_unit", "块");
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

