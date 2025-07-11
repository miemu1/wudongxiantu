// powerup.c
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_CLEAN_UP;
string query_name() { return "归元"ZJBR"大法"; }
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;
	if( target != me )
		return notify_fail("你只能用归元大法提升自己的战斗力。\n");
	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");
	if ( !wizardp(me) && me->query_skill_mapped("force") != "guiyuan-dafa")
		return notify_fail(HIC"不使用本门内功，如何使用本门绝学!\n"NOR);
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");	
	skill = me->query_skill("force")/1;//2016.5.30阿飞改，按照内功有效等级添加
	me->add("neili", -100);


	message_vision(HIW"$N长啸一声,手划阴阳，三分归元气汇聚手心,顿时六月飞雪，寒气大涨！\n" NOR, me);
	me->add_temp("apply/attack", skill); 
//	tell_object(me,HIG"你的命中提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/damage", skill); 
//	tell_object(me,HIG"你的伤害提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/dodge", skill);
	me->add_temp("apply/parry", skill);
//    tell_object(me,HIG"你的闪避提高了"+chinese_number(skill)+"点!\n"NOR);	
	me->add_temp("apply/strength",skill/100);
//	tell_object(me,HIG"你的力量提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/dexerity",skill/100);
//	tell_object(me,HIG"你的速度提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/constitution",skill/100);
//	tell_object(me,HIG"你的根骨提高了"+chinese_number(skill)+"点!\n"NOR);
//	me->add_temp("apply/intelligence",skill);
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
		me->add_temp("apply/parry", - amount);
		me->add_temp("apply/strength", -amount/100);
	//	me->add_temp("apply/intelligence", -amount/100);
		me->add_temp("apply/constitution", -amount/100);
		me->add_temp("apply/dexerity", -amount/100);
		me->add_temp("apply/armor", -amount);
		me->delete_temp("powerup");
		tell_object(me, HIG"你的归元大法运行完毕，将内力收回丹田。\n"NOR);
}
}
