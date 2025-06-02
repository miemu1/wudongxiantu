// jingang.c ���ӡ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "���ӡ"; }

int perform(object me, object target)
{
	string msg;
	int skill, ap, dp, damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("�����ӡ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	skill = me->query_skill("dashou-yin", 1);

	if (skill < 100)
		return notify_fail("��Ĵ���ӡ��Ϊ����, ����ʹ�á����ӡ����\n");

	if (me->query("neili") < 150)
		return notify_fail("��������������޷����á����ӡ����\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "����ׯ�أ������ĳ����������ھ�ѧ�����ӡ����"NOR"\n";

	ap = me->query_skill("hand") + me->query("con")*10;
	dp = target->query_skill("parry");
	if (dp < 1) dp = 1;
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -100);
		me->start_busy(2);
		damage = ap + random(ap/2);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "���$p" HIR "�мܲ�������$P" HIR
					   "��һ�´���������̣���Ѫ������"NOR"\n");
	} else
	{
		me->add("neili",-40);
		msg += CYN "����$p" CYN "���Ų�æ������ļܿ���$P"
		       CYN "�Ľ��ӡ��"NOR"\n";
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}

