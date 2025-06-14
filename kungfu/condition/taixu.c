// xuanming_poison.c
// by jeeny

#include <ansi.h>

inherit F_CLEAN_UP;

int dispel(object me, object ob, int duration)
{
	int n;

	n = ob->query_condition("taixu") - (int)me->query_skill("taixu-jiandian", 1) - (int)me->query_skill("force") / 100;

	if (n < 1)
		ob->clear_condition("taixu");
	else
		ob->apply_condition("taixu", n);

	if (me != ob)
		tell_object(me, "你运起内功，帮助" + ob->name() + "化解体内的剑气。\n");  
	else
		tell_object(me, "你运起内功，开始化解体内的寒毒。\n");  
	
	return 1;
}

int update_condition(object me)
{
	int limit;

	if (! living(me) && (me->query("eff_qi") < 20 || me->query("eff_jing") < 10))
	{
		me->set_temp("身中太虚剑气，剑气攻心而死"); 
		me->die();
		return 0;
	} else
	{
		me->receive_wound("qi", 500);
		me->receive_wound("jing", 5000);
		tell_object(me, MAG"你中的太虚剑气发作了。"NOR"\n");
		message("vision", HC + me->name() + HIC "身体不住颤抖，仿佛承受了莫大的痛苦。"NOR"\n",environment(me), ({ me }));
	}
	
	return 1;
}
