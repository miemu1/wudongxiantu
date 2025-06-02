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
	set_name(HIR"���뵤"NOR, ({"qilin dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 150);
                set("no_get", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_sell", 1);
                set("no_steal", 1);
                set("no_beg", 1);
		set("unit", "��");
				set("tianji1", 100);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 10000);
		set("long","����һ�����뵤����������һСʱ���屶��Ϊ����ʦ��������Ч��Ч�����Ժ����鵤�����鵤���棩��\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob1;

	me->apply_condition("db_exp3", 360+me->query_condition("db_exp3"));

	write(YEL"�����һ��"HIY"���뵤"YEL"����ʱ����������ˬ����ʲô���鶼�������!"NOR"\n");
	add_amount(-1);
	return 1;
}

