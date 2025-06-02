// kuang.c ��罣

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "����"ZJBR"��ӿ"; }

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
		return notify_fail("����罣��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("����罣����ʼʱ��������һ�ѽ���\n");
		
	if (weapon = me->query_temp("weapon"))
	{
		if (weapon->query("skill_type") != "sword"||
		me->query_skill_mapped("sword") != "kuangfeng-jian")
			return notify_fail("�㲢û�м������콣Ϊ��������ôʩչ��罣��\n");
	}

	if ((int)me->query("neili") < 150)
		return notify_fail("��������������޷�ʩչ��罣����\n");

	if ((int)me->query_skill("kuangfeng-jian", 1) < 100)
		return notify_fail("��Ŀ�罣���������ң��޷�ʩչ����罣����\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
	  
        msg = HIW "$N" HIW "�����������ת����" + weapon->name() + HIW "��ɲ�Ǽ�����\n"
              "������𣬷���������" + weapon->name() + HIW "�͵ؾ���$n" HIW "��\n" NOR;
			

	msg = HIC "$N" HIC "���һ�������е�" + weapon->name() +
	      HIC "�����缲��һ��������$n" HIC "��\n"
	      HIC "��ʱ��ֻ�������������粨�˰���ӿ����$n"
	      HIC "ֻ���ú�����ʱ������"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -150);

	count = me->query_skill("sword") / 2;
	me->add_temp("apply/attack", count);

	if (me->query_skill("jianxin-tongming", 1) > 49 ) 
	{
	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
	me->start_busy(2+random(7));
	}
	else {
	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
	me->start_busy(1 + random(6));
	}

	me->add_temp("apply/attack", -count);
	return 1;
}
