// shedan.c

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
string *rices=({"����","����","����"});
int i=random(sizeof(rices));
void create()
{
	set_name("���ʵ�"+rices[i], ({"youzhi rice", "rice"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "��");
		set("long", "����һͨ������õ������ʵ�"+rices[i]+"��\n");
		set("base_value", 5000);
		set("base_weight", 1);
	}
	setup();
}
