
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
	set_name(HIR "�ظ���" NOR, ({ "hiu dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�Թ�֮���ھ�����ȫ���ָ���\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		//set("base_value", 30000);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("yuanbao", 100);
            set("no_sell", 1);
		set("suit_point", 50000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	mapping my;
      if (me->is_fighting()) 
		return notify_fail("����������ս����\n");

	message_vision("$Nһ������������һ��" + this_object()->name() +"��\n", me);

	my = me->query_entire_dbase();
    my["jing"]  = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["eff_qi"] = my["max_qi"]+me->query_gain_qi();
	my["qi"] = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];
	add_amount(-1);
	return 1;
}