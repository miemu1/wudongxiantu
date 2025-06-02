// kuang.c ���⽣

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "����"ZJBR"��"; }

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
		return notify_fail("�����⽣��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("�����⽣����ʼʱ��������һ�ѽ���\n");


	if ((int)me->query("neili") < 100)
		return notify_fail("��������������޷�ʩչ���⽣��\n");

	if (me->query_skill("martial-cognize") < 300)
		return notify_fail("�����ѧ�����������ң��޷�ʹ�á����⽣����\n");

	if ((int)me->query_skill("force") < 100 )
		return notify_fail("����ڹ���򲻹���\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "���һ�������е�" + weapon->name() +
	      HIC "�����缲��һ������$n" HIC "��\n"
	      HIC "��ʱ��ֻ��ʮ�˵������������粨�˰���ӿ����$n"
	      HIC "ֻ���ú�����ʱ������"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -100);

	count = me->query_skill("sword") / 2;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 18; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}


	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(6));
	return 1;
}
