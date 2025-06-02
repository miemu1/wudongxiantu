#include <ansi.h>
#include <combat.h>

#define WU "��" HIR "������ץ" NOR "��"

inherit F_SSERVER;
 
string query_name() { return "����"ZJBR"��ץ"; }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int count;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail(WU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("�������ֲ���ʩչ" WU "��\n");

	if (me->query_skill_mapped("claw") != "sanyin-wugongzhao")
		return notify_fail("��û�м�������צΪ���ּ��ܣ��޷�ʩչ" WU "��\n");

	if (me->query_skill_prepared("claw") != "sanyin-wugongzhao")
		return notify_fail("������û��׼��ʹ������צ���޷�ʩչ" WU "��\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("�������צ��򲻹����޷�ʩչ" WU "��\n");

	if ((int)me->query_skill("claw", 1) < 200)
		return notify_fail("��Ļ���צ����򲻹����޷�ʩչ" WU "��\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("���������Ϊ���㣬�޷�ʩչ" WU "��\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("��������������޷�ʩչ" WU "��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "˫��ͨ�죬������������$n" HIR "����������"NOR"\n";

	ap = me->query_skill("claw") + me->query("str") * 10;
	dp = target->query_skill("dodge") + target->query("dex") * 10;

	if (ap / 2 + random(ap) > dp)
	{
		count = ap / 10;
		msg += HIR "$n" HIR "���$P" HIR "���������ƣ������������⣬����������������"NOR"\n";
	} else
	{
		msg += HIC "$n" HIC "΢һ�������$P" HIC "�⹥��ȴ˿�����ң�С���мܡ�"NOR"\n";
		count = 0;
	}

	message_combatd(msg, me, target);
	me->add_temp("apply/attack", count);

	me->add("neili", -200);
	if (me->query_skill("hanmo-xuangong", 1) > 49) 
	{
	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, 0, 0);
	}
	me->start_busy(2 + random(7));
	}
	else {
	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, 0, 0);
	}
	me->start_busy(1 + random(6));
	}

	me->add_temp("apply/attack", -count);

	return 1;
}

