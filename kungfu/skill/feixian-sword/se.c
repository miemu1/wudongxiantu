// ci.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "���Ŵ�"; }

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp;


	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	skill = me->query_skill("feixian-sword", 1);

	if (! target || ! me->is_fighting(target))
		return notify_fail("���Ŵ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û��ʹ�ñ��������������Ŵ�Ҳû�á�\n");

	if (skill < 125)
		return notify_fail("��ķ��ɽ����ȼ�����, �޷�ʩչ���Ŵ̡�\n");

	if (me->query("neili") < 500)
		return notify_fail("��������������޷�ʩչ���Ẉ̂�\n");

	if (me->query_skill_mapped("sword") != "feixian-sword")
		return notify_fail("������û�м������ɽ������޷�ʩչ�ξ�����\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "ͻȻ$N" HIY "һ����ߣ�����" + weapon->name() + NOR HIY
		  "�й�ֱ����ֱ��$n���ŵ�" +weapon2->name() + NOR HIY "��"
		  "�֡�"NOR"\n";
	message_combatd(msg, me, target);

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");

	if (dp < 1) dp = 1;

	if (ap + random(ap) > dp)
	{
		me->add("neili", -500);
		msg = HIR "$n" HIR "ֻ������һ���ʹ������" + weapon2->name() + HIR
		      "��Ҳ����ס�����ֶ��ɣ�"NOR"\n";
		me->start_busy(2 + random(1));
		weapon2->move(environment(target));
	} else
	{
		me->add("neili", -500);
		msg = CYN "����$n" CYN "������$N" CYN "����ͼ�������б��л�"
		      "����ܲ�͸�磬������$N" CYN "�ı�����"NOR"\n";
		me->start_busy(4);
	}

	message_combatd(msg, me, target);
	return 1;
}
