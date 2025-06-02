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
	set_name(HIR"��Ʒ���뵤"NOR, ({"xianqilin dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 150);
                set("give",1);
				set("drop",1);
				set("get",1); 
                set("no_sell", 1);
                set("no_steal", 1);
                set("no_beg", 1);
		set("unit", "��");
				set("tianji1", 10000);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 10000);
		set("long","����һ����Ʒ���뵤����������һ���µ��屶��Ϊ����ʦ��������Ч��Ч�����Ժ����鵤�����鵤���棩��\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob1;

	me->apply_condition("db_exp3", 259200+me->query_condition("db_exp3"));

	write(YEL"�����һ��"HIY"��Ʒ���뵤"YEL"����ʱ����������ˬ����ʲô���鶼�������!"NOR"\n");
	add_amount(-1);
	return 1;
}

