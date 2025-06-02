
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
	set_name("���Ե�", ( {"cheshi dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ�Ų��Ե����������busy�����ǻ�����1000Ѫ��\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 10);
		set("no_sell", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{		
		message_vision("$N����һ" + query("unit") + name() + "����ʱ��Ϣ˳����ࡣ\n", me);
		me->start_busy(-101);
		me->add("qi",1000);
		add_amount(-1);
		return 1;	
}
