#include <ansi.h>
//�������㷨
inherit ITEM;

void create()
{
	set_name(HIR "BT��" NOR, ({ "bt dan"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�Թ�֮���ھ�����ȫ���ָ�\n");
		set("spectxt", "�Թ�֮���ھ�����ȫ���ָ�\n");
        set("no_sell", 1);
	    set("value", 500);
		set("unit", "��");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
	mapping my;
      if (me->is_fighting()) 
		return notify_fail("����������ս����\n");

//	message_vision("$Nһ������������һ��" + this_object()->name() +"��\n", me);
    tell_object(me,"��һ������������һ��" + this_object()->name() +"\n");
/*
	my = me->query_entire_dbase();
    my["jing"]  = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["eff_qi"] = my["max_qi"]+me->query_gain_qi();
	my["qi"] = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];
	/**/
	 me->set("eff_qi", me->query("max_qi")+me->query_gain_qi());
	 me->set("qi", me->query("max_qi")+me->query_gain_qi());
     me->set("eff_jing", me->query("max_jing")+me->query_gain_jing());
     me->set("jing", me->query("max_jing")+me->query_gain_jing());
     me->set("neili",me->query("max_neili"));
     me->set("jingli",me->query("max_jingli"));
	me->start_busy();
	return 1;
}
int query_autoload() { return 1; }