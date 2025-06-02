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
		return notify_fail("��ֻ���ÿ�ľ�������Լ���ս������\n");
	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if ( !wizardp(me) && me->query_skill_mapped("force") != "kumu-shengong")
		return notify_fail(HIC"��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n"NOR);
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");	
	skill = me->query_skill("force");//2016.5.30���ɸģ������ڹ���Ч�ȼ����
	me->add("neili", -100);
//	me->receive_damage("qi",10);

	message_vision(HIW"$N�ƺ�һ����ͻȻ���տ��£�ȫ��Ǳ���������ƺ������˲��١�\n" NOR, me);
	me->add_temp("apply/attack", skill); 
//	tell_object(me,HIG"������������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/damage", skill); 
//	tell_object(me,HIG"����˺������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/dodge", skill);
//    tell_object(me,HIG"������������"+chinese_number(skill)+"��!\n"NOR);	
	me->add_temp("apply/strength",skill);
//	tell_object(me,HIG"������������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/dexerity",skill);
//	tell_object(me,HIG"����ٶ������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/constitution",skill);
//	tell_object(me,HIG"��ĸ��������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/intelligence",skill);
//	tell_object(me,HIG"������������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/armor", skill); 
//	tell_object(me,HIG"��ķ��������"+chinese_number(skill)+"��!\n"NOR);
	tell_object(me,HIG"���ս��������ʱ����ˣ�\n"NOR);
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
		tell_object(me, HIG"��Ŀ�ľ��������ϣ��������ջص��\n"NOR);
}
}
