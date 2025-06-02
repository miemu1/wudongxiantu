// luan.c

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "���־�"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
	int count;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("ʩչ���־���������һ�ѽ���\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("��������������޷�ʩչ���־���\n");

	if (me->query_skill("surge-force", 1) < 250)
		return notify_fail("��ľ��ι���򲻹�������ʩչ������͵��书��\n");

	if ((int)me->query_skill("xuantie-jian", 1) < 250)
		return notify_fail("������������������ң��޷�ʹ�����־���\n");

	if (me->query_skill("martial-cognize", 1) < 120)
		return notify_fail("�����ѧ�������ޣ�����ʩչ�����־��еľ�΢����֮����\n");

	if (me->query_skill_mapped("sword") != "xuantie-jian")
		return notify_fail("��û�м��������������޷�ʹ�����־���\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "���쳤Х������" + weapon->name() +
	      HIY "��ͷ���Եı�$n" HIY "��ȥ����ʱ����������������\n"
	      "���¿����������������纣�����ε�������$n"
	      HIY "���ž������У�"NOR"\n";
	me->add("neili", -100);

	count = (me->query_skill("martial-cognize", 1) -
		 target->query_skill("martial-cognize", 1)) / 3;
	if (count < -10)
		msg += HIG "Ȼ��$n" HIG "����ѧ��ң��Դ���ӿ��"
		       "�ȵĹ���˿�����壬�ڽ����н������硣"NOR"\n";
	else
	if (count < 30)
		msg += HIC "Ȼ��$n" HIC "��ʶ�Ƿ�������$N"
		       HIC "֮�£�������ӿ�볱�Ĺ����������磬���ݵֵ���"NOR"\n";
	else
	{
		msg += HIR "$n" HIR "���һ����ֻ����$N"
		       HIR "�������糱ˮ��ӿ������ǰ�����������ڰ��ѱ档"NOR"\n";
	}
	message_combatd(msg, me, target);
	me->add_temp("apply/attack", count);

	if (me->query_skill("taishang-wangqing", 1) > 49)
	{
	for (i = 0; i < 15; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
	me->start_busy(2 + random(6));
	}
else
{
	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
	me->start_busy(1 + random(5));
}

	me->add_temp("apply/attack", -count);
	return 1;
}
