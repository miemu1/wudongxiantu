// diezhang.c 昆山叠掌
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	string msg, *limbs;
	int p,count, damage,skill1,skill2;
	int arg,ap,dp;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「昆山叠掌」只能在战斗中对对手使用。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能施展「昆山叠掌」。\n");

	if( me->query_skill_mapped("unarmed") != "kunlun-zhang" )
		return notify_fail("你没有用昆仑掌法。\n");

	if( (int)me->query_skill("kunlun-zhang", 1) < 300 )
		return notify_fail("你的掌法不够娴熟，不会使用「昆山叠掌」。\n");

	if( (int)me->query_skill("xuantian-wuji", 1) < 300 )
		return notify_fail("你的玄天无极功等级不够，不能使用「昆山叠掌」。\n");

	if( (int)me->query("str",) < 25 )
		return notify_fail("你的先天膂力不够强，不能使用「昆山叠掌」。\n");

	if(me->query_skill_mapped("force") != "xuantian-wuji" )
		return notify_fail("你没有用玄天无极。\n");
	if (me->query_skill_mapped("unarmed") != "kunlun-zhang")
		return notify_fail("你没正确激发该技能 。\n");	
	if( (int)me->query("max_neili", 1) < 10000 )
		return notify_fail("你内力修为不够，不能使用「昆山叠掌」。\n");

	if( (int)me->query("neili", 1) < 5000 )
		return notify_fail("你现在的内力施展不了那么多招。\n");
	arg=(int)(me->query_skill("kunlun-zhang", 1) / 60);
	if ( arg > 50) arg = 50;	
	skill1 = (int)me->query_skill("kunlun-zhang", 1);
	skill2 = (int)me->query_skill("xuantian-wuji", 1);
	message_vision(HIG"$N深吸一口气，大喝一声，连续击出"HIW+ chinese_number(arg) +HIG"掌，后招推着前招，掌力叠合在一起扑向$n！\n\n"NOR, me, target);
	ap = me->query("xyzx_sys/level") + me->query_skill("kunlun-zhang", 1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");	
	if( random(ap) > dp/3 )
	{
		limbs = target->query("limbs");
//		me->add_temp("lianzhao", arg);	 //2016.6.1阿飞改，增加连招标记，用于削弱连招伤害，但是貌似昆仑叠掌不是连招	
		for(count = 0; count < arg; count++)
		{
			message_vision( replace_string(HIG+SKILL_D("kunlun-zhang")->query_action(me, me->query_temp("weapon"))["action"],
			                   "$l", limbs[random(sizeof(limbs))]) + "！\n"NOR, me, target);
			damage = skill1+random(skill2);
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg = damage_msg(damage, "内伤");
			msg += "( $n"+eff_status_msg(p)+" )\n\n";
			//if (damage >1250) damage =1250;
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/2,me);
			message_vision(msg, me, target);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		}
		me->add("neili", -100 * arg);

//		me->delete_temp("lianzhao");  //2016.6.1阿飞改，连招结束取消连招标记
	}
	else
	{

		me->add("neili", -200);
		msg =HIY"\n$n身型急速后退，顺着掌风就势一跳，躲开了这攻击。\n" NOR;
		message_vision(msg, me, target);
	}
	 me->start_busy(3);
	return 1;
}
