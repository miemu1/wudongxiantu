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
	set_name(HIR"�������֥"NOR, ({"huo lingzhi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 200);
        set("no_sell",1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
				set("no_drop1", 1);

				set("no_drop", 1);
				set("no_sell", 1);
				set("no_give", 1);
				set("no_get", 1);
				set("no_steal", 1);
		set("base_value", 10000);
		set("long","����һ���������֥����������2000���������ޡ�\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob1;
	int times;

	times = time();


	me->add("max_neili", 2000);
	message_vision(YEL+me->query("name")+"����һ��"HIR"�������֥"YEL"���پ�����������"NOR"\n",me);

	add_amount(-1);
	return 1;
}

