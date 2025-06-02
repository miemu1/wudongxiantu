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
	set_name(HIW "��ʯ��Ƭ" NOR, ({ "gem suipian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�����ϳɱ�ʯ�ı�ʯ��Ƭ��\n");
		set("base_unit", "��");
		set("base_value", 500);
		set("yuanbao", 10);
		set("base_weight", 1);
	}
	setup();
}

