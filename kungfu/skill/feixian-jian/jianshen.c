// jianshen.c 剑神一笑

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "剑神"ZJBR"一笑"; }
int perform(object me, object target)
{
	string msg;
	int i,extra,attack_time;
	object weapon;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("剑神一笑只能对战斗中的对手使用。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if ( me->query_skill("feixian-jian",1) < 240) 
		return notify_fail("你的飞仙剑诀还不够纯熟！\n");
	if ( me->query_skill("jingyi-shengong",1) < 240) 
		return notify_fail("你的净衣神功还不够纯熟！\n");		
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("使用剑神一笑必须拿着一把剑！\n");
	if (target && target->query_temp("apply/shade_vision")) 
		return notify_fail("对方隐身了，你看不到"+target->query("name")+"。\n"); 	
	if ( me->query_skill_mapped("force") != "jingyi-shengong")
		return notify_fail("你必须激发净衣神功才能使用「剑神一笑」！\n");   	 
	if( (int)me->query("neili") < me->query_skill("feixian-jian",1)*4  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("jingli") < 100 )
		return notify_fail("你的精力不够。\n");		
	if( (int)me->query("max_neili") < 100  ) 
		return notify_fail("你的内力修为不够。\n");
	if (me->query_skill_mapped("sword") != "feixian-jian")
		return notify_fail("你没正确激发该技能 。\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	extra = me->query_skill("feixian-jian",1) ;

	msg = RED  "$N脚踏［飞仙步］，同时使出［飞仙剑诀］的精髓－－【剑神一笑】，手中的"+ weapon->name() +"划出一道长虹，闪电般的击向$n！" NOR;
	me->set_temp("cooldown", 2);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;	
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	me->add_temp("apply/strength", extra);
	attack_time = me->query_skill("feixian-jian",1)/600;
	if (attack_time < 1) attack_time= 1;
	if (me->query("jm/nanhai")) 
	{
		if (attack_time > 100) attack_time= 100;
	} else 
	{
		if (attack_time > 50) attack_time= 50;
	}	
	
//		me->add_temp("lianzhao", attack_time);	 //2016.6.1阿飞改，增加连招标记，用于削弱连招伤害	
	for(i=0;i < attack_time;i++)
	{
	msg = RED "$N身形突转，御剑回飞！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add_temp("apply/strength", -extra);
	me->add("neili", -(100*attack_time));
//	me->delete_temp("lianzhao");  //2016.6.1阿飞改，连招结束取消连招标记	
	me->start_busy(1);
	return 1;
}

void del_cooldown(object me)	//CD写法1
{ 
	if ( !objectp(me) ) return;
	if ( me->query_temp("cooldown") )	
	{
		me->delete_temp("cooldown");
		tell_object(me, HIM"你呼出一口气，缓缓的将内力收回丹田。\n"NOR);
	}	
}