// jiubu.c �Ų�ʽ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "�Ų�ʽ"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp, count, i;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("���Ų�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("zhemei-shou", 1) < 120)
		return notify_fail("�����÷�ַ�������죬����ʹ�á��Ų�ʽ����\n");
				
	if ((int)me->query_skill("force") < 200)
		return notify_fail("����ڹ���Ϊ�����ߣ��������á��Ų�ʽ����\n");
			
	if ((int)me->query("neili") < 100)
		return notify_fail("��������������������ʹ�á��Ų�ʽ����\n");

	if (me->query_skill_mapped("hand") != "zhemei-shou")
		return notify_fail("��û��׼����ɽ��÷�֣�����ʹ�á��Ų�ʽ����\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	if (me->query_skill("tianchang-dijiu", 1) > 49||me->query_skill("tiandi-xiaoyao", 1) > 49)
	{
	msg = HIC "$N" HIC "˫������ʵʵ��ץ��$n"HIC "��Ҫ��������翣���ʽ���أ���������׽����"NOR"\n";

	ap = me->query_skill("hand");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		count = ap / 12;
		msg += HIY "$n" HIY "��$P" HIY "��һ������쳣�����ɴ��һ��������������������"NOR"\n";
	} else
	{
		msg += HIC "$n" HIC "����С��$P" HIC
		       "�����У���Ų������С���мܡ�"NOR"\n";
		count = 0;
	}

	message_combatd(msg, me, target);
	me->add_temp("apply/attack", count);

	me->add("neili", -200);
	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(3) == 0 && ! target->is_busy())
			target->start_busy(1);

		COMBAT_D->do_attack(me, target, 0, 0);
	}

	me->start_busy(2 + random(7));
	me->add_temp("apply/attack", -count);
	}
else
{
	msg = HIC "$N" HIC "˫������ʵʵ��ץ��$n"
	      HIC "��Ҫ��������翣���ʽ���أ���������׽����"NOR"\n";

	me->add("neili", -50);
	ap = me->query_skill("hand");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("zhemei-shou", 1);
		damage += random(damage);
		me->add("neili", -100);

		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
					   HIR "$p" HIR "һ�����ܲ����������$P"
					   HIR "ץ�˸����У�������Ϣ���ɵ�һ�ͣ���Ѫ��ӿ��"NOR"\n");
		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "�������ݣ�����Ķ����$P"
		       HIC "�Ĺ�����"NOR"\n";
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}

	return 1;
}
