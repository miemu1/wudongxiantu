// shenliwan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC "�׺���" NOR, ({ "canghai dan", "dan"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һС���׺����������������,��Ч�����ɡ�\n");
		set("spectxt", "һС���׺����������������,��Ч�����ɡ�\n");
		set("yuanbao", 1);
		set("unit", "��");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
	mapping my;
      if (me->is_fighting()&&playerp(me->query("competitor"))) 
		return notify_fail("���������ں����ս����\n");

	message_vision("$Nһ������������һ��" + this_object()->name() +"��\n", me);

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	me->set("qi",me->query("max_qi")+me->query("gain/max_qi"));

	me->set("eff_qi",me->query("max_qi")+me->query("gain/max_qi"));

	my["neili"]  = my["max_neili"];
	my["food"]   = 77*me->max_food_capacity();
	my["water"]  = 77*me->max_water_capacity();
	me->start_busy(2);
	return 1;
}
int query_autoload() { return 1; }