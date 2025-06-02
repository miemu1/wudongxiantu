#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "���졤"ZJBR"����һ��"; }
string *pfm_type() { return ({ "club", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int count;
	int i, attack_time;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("�����졤����һ����ֻ����ս���жԶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (me->query_skill_mapped("club") != "douzhan-shengjing")
		return notify_fail("�����ڲ�δ���ö�սʥ����ʹ���������졤����һ������\n");

       if(me->query_skill("douzhan-shengjing", 1) < 300 )
		return notify_fail("��Ķ�սʥ����������죬ʹ���������졤����һ������\n");

       if( (int)me->query_skill("force") < 600 )
		return notify_fail("����ڹ��ȼ�������ʹ���������졤����һ������\n");

	if( (int)me->query("max_neili") < 3000 )
		return notify_fail("����������̫����ʹ���������졤����һ������\n");      

	if( (int)me->query("neili") < 3000 )
		return notify_fail("����������̫����ʹ���������졤����һ������\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "\n$N" HIW "�����е�" + weapon->name() + HIW "������$n"
	      HIW "ѹȥ�����˾��������з���֮�������Ƕ�սʥ����ɱ�š�"
	      NOR + HIR "���졤����һ��" NOR + HIW "����\n��Ȼ����˹�â��"
	      "�ǣ��ó�������" + weapon->name() + HIW "�����籼�׳���"
	      "������ǵ���$n" HIW "ϯ���ȥ��"NOR"\n";

	ap = me->query_skill("club");
	dp = target->query_skill("parry");
	attack_time = 5;
	if (ap *25 / 2 + random(ap * 25) > dp)
	{
		msg += HIR "\n���$n" HIR "��$N" HIR
		       "���˸����ֲ�����Ŀ�Ӳ�Ͼ��ƣ�ڱ�����"NOR"\n";
		count = ap *25 / 2;
		me->add_temp("apply/attack", count);
		attack_time += random(ap * 25 / 6);
	} else
	{
		msg += HIC "$n" HIC "��$N" HIC "������磬������Ȼ������Ӧ����"NOR"\n";
		count = 0;
	}
		
	message_combatd(msg, me, target);

	if (attack_time > 10)
		attack_time = 10;

	me->add("neili", -attack_time * 88);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(attack_time));
	return 1;
}

