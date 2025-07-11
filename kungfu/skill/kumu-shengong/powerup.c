// powerup.c
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;
	if( target != me )
		return notify_fail("你只能用枯木神功提升自己的战斗力。\n");
	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");
	if ( !wizardp(me) && me->query_skill_mapped("force") != "kumu-shengong")
		return notify_fail(HIC"不使用本门内功，如何使用本门绝学!\n"NOR);
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");	
	skill = me->query_skill("force");//2016.5.30阿飞改，按照内功有效等级添加
	me->add("neili", -100);
//	me->receive_damage("qi",10);

	message_vision(HIW"$N闷哼一声，突然容颜枯槁，全身潜力激发，似乎苍老了不少。\n" NOR, me);
	me->add_temp("apply/attack", skill); 
//	tell_object(me,HIG"你的命中提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/damage", skill); 
//	tell_object(me,HIG"你的伤害提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/dodge", skill);
//    tell_object(me,HIG"你的闪避提高了"+chinese_number(skill)+"点!\n"NOR);	
	me->add_temp("apply/strength",skill);
//	tell_object(me,HIG"你的力量提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/dexerity",skill);
//	tell_object(me,HIG"你的速度提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/constitution",skill);
//	tell_object(me,HIG"你的根骨提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/intelligence",skill);
//	tell_object(me,HIG"你的悟性提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/armor", skill); 
//	tell_object(me,HIG"你的防御提高了"+chinese_number(skill)+"点!\n"NOR);
	tell_object(me,HIG"你的战斗属性临时提高了！\n"NOR);
	me->set_temp("powerup", 1);
    me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),600);
//	if( me->is_fighting() ) me->start_busy(1);
	 me->start_busy(1);
	return 1;
}

void remove_effect(object me, int amount)
{
	if (!me) return;
	if ( (int)me->query_temp("powerup") )
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/damage", - amount);
		me->add_temp("apply/dodge", - amount);
		me->add_temp("apply/strength", -amount);
		me->add_temp("apply/intelligence", -amount);
		me->add_temp("apply/constitution", -amount);
		me->add_temp("apply/dexerity", -amount);
		me->add_temp("apply/armor", -amount);
		me->delete_temp("powerup");
		tell_object(me, HIG"你的枯木神功运行完毕，将内力收回丹田。\n"NOR);
}
}
