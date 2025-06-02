// kuang.c ���½���

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "����"ZJBR"����"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("�����½��衹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("�����½��衹��ʼʱ��������һ�ѽ���\n");


	if ((int)me->query("neili") < 200)
		return notify_fail("��������������޷�ʩչ���½��裡\n");

	if (me->query_skill("lonely-sword") < 200)
		return notify_fail("��Ķ��¾Ž��������ң��޷�ʹ�á����½��衹��\n");

	if ((int)me->query_skill("force") < 100 )
		return notify_fail("����ڹ���򲻹���\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "���һ�������е�" + weapon->name() +
	      HIC "�����缲��һ������$n" HIC "��\n"
	      HIC "��ʱ��ֻ��ʮ�������������粨�˰���ӿ����$n"
	      HIC "ֻ���ú�����ʱ������"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -200);

	count = me->query_skill("sword") / 2;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}


	me->add_temp("apply/attack", -count);
	me->start_busy(2 + random(4));
	return 1;
}
