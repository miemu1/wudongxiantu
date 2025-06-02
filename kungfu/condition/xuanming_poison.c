// xuanming_poison.c
// by jeeny

#include <ansi.h>

inherit F_CLEAN_UP;

int dispel(object me, object ob, int duration)
{
	int n;

	n = ob->query_condition("xuanming_poison") - (int)me->query_skill("jiuyang-shengong", 1) - (int)me->query_skill("force") / 100;

	if (n < 1)
		ob->clear_condition("xuanming_poison");
	else
		ob->apply_condition("xuanming_poison", n);

	if (me != ob)
		tell_object(me, "�������ڹ�������" + ob->name() + "�������ڵĺ�����\n");  
	else
		tell_object(me, "�������ڹ�����ʼ�������ڵĺ�����\n");  
	
	return 1;
}

int update_condition(object me)
{
	int limit;

	if (! living(me) && (me->query("eff_qi") < 20 || me->query("eff_jing") < 10))
	{
		me->set_temp("������ڤ�ƶ�������������"); 
		me->die();
		return 0;
	} else
	{
		me->receive_wound("qi", 3000);
		me->receive_wound("jing", 3000);
		if (me->query("potential")>=-1000000)
		me->add("potential", -80000);
		if (me->query("magic_points")>=-1000000)
		me->add("magic_points", -30000);
		if (me->query("combat_exp")>=-1000000)
		me->add("combat_exp", -30000);
		if (me->query("max_jingli")>=1000)
		{me->add("max_jingli", -1000);
		me->add("jingli", -3000);}
		if (me->query("max_neili")>=1000)
		{me->add("max_neili", -1000);	
		me->add("neili", -2000);}
		if (me->query("gain/max_qi")>=2000)
		{me->add("gain/max_qi", -1000);	
		me->add("qi", -2000);}
		tell_object(me, MAG"���е���ڤ����֮�������ˡ�"NOR"\n");
		message("vision", MAG + me->name() + MAG "����ֱ���������������ͣ��"NOR"\n",environment(me), ({ me }));
	}
	
	return 1;
}
