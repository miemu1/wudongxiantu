//tuxin.c -���������š�
// Modified by Venus Oct.1997
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "����"ZJBR"����"; }
int perform(object me, object target)
{
	int extra,damage;
	object weapon;
	string msg;
	extra=me->query_skill("qingmang-jian",1);
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á��������š���\n");
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if( (int)me->query_skill("qingmang-jian",1) < 100)
		return notify_fail("��Ŀǰ������ʹ�������������š���\n");
	if (!objectp(weapon = me->query_temp("weapon"))|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query_skill_mapped("sword") != "qingmang-jian")
		return notify_fail("��û��ȷ�����ü��� ��\n");
	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");
	me->add("neili", -100);
	msg = HIC"$N�������һ��������������������������һ�㣬ˢˢˢ�������У�"NOR;
	message_vision(msg, me, target);
	damage = extra + random(extra);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		target->receive_damage("qi", damage,me);
//		target->receive_wound("qi", damage);
	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"��\n" NOR);
	me->start_busy(2);
	
	return 1;
}

