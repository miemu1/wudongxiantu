#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

string name() { return HIW "СŲ��" NOR; }
string query_name() { return "С"ZJBR"Ų��"; }
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage,ap,dp;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HIW "��СŲ�ơ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	if( me->query_temp("weapon"))
		return notify_fail("���ȷ������е�������˵�ɣ���\n");
	if( (int)me->query_skill("tiexian-quan",1) < 300)
		return notify_fail(HIW "��ġ�����ȭ���������ң��޷�ʹ�á�СŲ�ơ���\n"NOR);
	if( (int)me->query_skill("guiyuan-dafa",1) < 300 )
		return notify_fail(HIW "��ġ���Ԫ�󷨡��������ң��޷�ʹ�á�СŲ�ơ���\n"NOR);
	if( me->query_skill_mapped("force")!="guiyuan-dafa")
		return notify_fail(HIW "��δʹ�á���Ԫ�󷨡����޷�ʹ�á�СŲ�ơ���\n"NOR);	
	if (me->query_skill_mapped("unarmed") != "tiexian-quan")
		return notify_fail("��û��ȷ�����ü��� ��\n");
	if (me->query("max_neili")<=10000) 
		return notify_fail(HIW "�������̫�����㣬����Ų�Ʋ����Է���\n"NOR);

	if (me->query("neili")<=1000) 
		return notify_fail(HIW "����������㣬�޷��������˹��ƣ�\n"NOR);

	me->add("neili",-500);
	message_vision(HIR "\n$Nʹ��佻����ɵĲ���֮�ء�СŲ�ơ�\n\n"NOR,me);
	ap = me->query("xyzx_sys/level") + me->query_skill("tiexian-quan", 1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");	
	damage = me->query_skill("tiexian-quan",1);
	damage = damage*2 + random(damage*2);
	if (random(ap)>dp/3)
	{
		message_vision(HIY "$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target->name()+"��\n" NOR,me,target);
		COMBAT_D->do_attack(target,target, target->query_temp("weapon"));
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage +"��\n" NOR);
	//	if (!target->is_busy()) target->start_busy(3);
	}
	else
	{
		message_vision(HIR "��$n����$N����ͼ�����Ʒ���������\n"NOR,me,target);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
	}
	 me->start_busy(3);
	return 1;
}
