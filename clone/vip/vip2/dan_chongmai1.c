// jinsha.c

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
	set_name(HIW "������[��Ʒ]" NOR, ({ "chongmai dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������������澭�����ĵ��ߡ�\n");
		set("base_unit", "��");
		set("base_value", 500);
		set("yuanbao", 10);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);		
		set("needle/level",5);
		set("base_weight", 1);
	}
	setup();
}

