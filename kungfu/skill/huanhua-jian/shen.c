// shen.c  庭院深深深几许

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "庭院深深深"ZJBR"几许"; }
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;
	int ap,dp;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「庭院深深深几许」诀只能对战斗中的对手使用。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
    if((int)me->query_skill("guiyuan-dafa",1)<300)
        return notify_fail("你的归元大法不够深厚，不能使用「庭院深深深几许」诀。\n");	
    if( (int)me->query_skill("huanhua-jian", 1) < 450 )      	
         return notify_fail("你的浣花剑法不够娴熟，不会使用「庭院深深深几许」诀。\n");
	if (me->query_skill_mapped("force")!="guiyuan-dafa" )
		return notify_fail("你未使用本门内功，不能使用绝技！\n");	
	if (me->query_skill_mapped("sword")!="huanhua-jian" )
		return notify_fail("你未使用浣花剑法，不能使用绝技！\n");		
		
        msg = HIY "$N使出浣花剑法「庭院深深深几许」诀，招式陡然变快，疯狂的扑向对方。\n";
	ap = me->query("xyzx_sys/level") + me->query_skill("huanhua-jian", 1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
     if( random(ap) > dp/4 )
	{
		attack_time = (int)me->query_skill("huanhua-jian", 1) / 60;	
		if(attack_time < 1) attack_time = 1;
        if(attack_time > 50) attack_time = 50;
		me->add_temp("lianzhao", attack_time);	 //2016.6.1阿飞改，增加连招标记，用于削弱连招伤害		
		msg += CYN " 庭院深深深几许？ 杨柳堆烟，帘幕无重数！\n" NOR;
		for(i = 0; i < attack_time; i++)
		{
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}
		me->add("neili", -100*attack_time);
		me->delete_temp("lianzhao");  //2016.6.1阿飞改，连招结束取消连招标记		
	}
	else
	{
		msg += "可是$n看透了$N的帘幕，并没有上当。\n" NOR;
	}
	message_vision(msg, me, target);
	me->start_busy(3);
	return 1;
}
