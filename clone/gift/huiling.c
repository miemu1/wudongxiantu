inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIM"���鵤"NOR, ({"huiling dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		//set("no_shop", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("unit", "��");
		set("only_do_effect", 1);
		set("long","����һ�Ż��鵤��"ZJURL("cmds:fu huiling dan")ZJSIZE(22)"����"NOR"֮������ʱ����1000���������ޣ���1000����Ϊһ��ʹ�á�\n");
	}
	set_amount(1);
}

int do_effect(object me)
{
	object ob1;
    int times;

	if (me->query("combat_exp")>10000000)
	{
		tell_object(me,"�ѳ������ʹ����Ϊ[1000��]�����鵤�Զ����٣�\n");
		destruct(this_object());
      	return 1;  
	}

	if (me->query("combat_exp")>10000000)
	{
		tell_object(me,"�ѳ������ʹ����Ϊ[1000��]������ʹ���ˣ�\n");
      	return 1;  
	}

	if(time() < (me->query_temp("last_huiling")+3))
      	return notify_fail("������ԣ���ҭ���ˡ�\n"); 
	if (me->query("max_neili") > 10000) {
		tell_object(me,"����������޳���10���޷�ʹ�á�\n");
      	return 1; 
	}
	me->set_temp("last_huiling",time());
	me->add("max_neili", 1000);

	message_vision(me->query("name")+"����һ��"HIM"���鵤"NOR"���پ��������޴�����"NOR"\n",me);
	add_amount(-1);
	return 1;
}

