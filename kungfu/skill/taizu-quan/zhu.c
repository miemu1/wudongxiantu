//changduan.c -����Ӱ������
// Modified by Venus Oct.1997
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int extra,damage;
	string msg;
	extra=me->query_skill("taizu-quan",1);
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á���Ӱ��������\n");
	if (me->query_skill_mapped("unarmed") != "taizu-quan")
		return notify_fail("��û��ȷ�����ü��� ��\n");
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if( (int)me->query_skill("taizu-quan",1) < 100)
		return notify_fail("��Ŀǰ������ʹ��������Ӱ��������\n");
    if( objectp(me->query_temp("weapon")) )
        return notify_fail("�������ֲ���ʹ�á���Ӱ��������\n");  
	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");
	me->add("neili", -100);
	msg = HIC"ֻ��$n��ǰһ��������˶���ȭͷ�ͻ����ˣ���ͨ������"NOR;
	message_vision(msg, me, target);
	damage = extra + random(extra);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		target->receive_damage("qi", damage,me);
//		target->receive_wound("qi", damage,me);
	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"��\n" NOR);
	me->start_busy(2);
	//if (!target->is_busy()) target->start_busy(random(2));
	
	return 1;
}

