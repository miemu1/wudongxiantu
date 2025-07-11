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
		tell_object(me, "你运起内功，帮助" + ob->name() + "化解体内的寒毒。\n");  
	else
		tell_object(me, "你运起内功，开始化解体内的寒毒。\n");  
	
	return 1;
}

int update_condition(object me)
{
	int limit;

	if (! living(me) && (me->query("eff_qi") < 20 || me->query("eff_jing") < 10))
	{
		me->set_temp("身中玄冥掌毒，不治身亡了"); 
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
		tell_object(me, MAG"你中的玄冥神掌之毒发作了。"NOR"\n");
		message("vision", MAG + me->name() + MAG "牙齿直打冷颤，浑身抖个不停。"NOR"\n",environment(me), ({ me }));
	}
	
	return 1;
}
