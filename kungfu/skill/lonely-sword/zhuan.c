// yi.c ��ת����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "��ת"ZJBR"����"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�þ��С�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("�޽�������ý�ת���ƣ�\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("�����ڵ������������޷�ʹ�ý�ת���ƣ�\n");

	if ((int)me->query_skill("lonely-sword", 1) < 320)
		return notify_fail("��Ķ��¾Ž��������ң��޷�ʹ�ý�ת���ƣ�\n");
		
	//		if ((int)me->query_skill("martial-cognize", 1) < 220)
		//return notify_fail("�����ѧ����������220�����޷�ʹ�ý�ת���ƣ�\n");

	if (me->query_skill_mapped("sword") != "lonely-sword") 
		return notify_fail("��û�м������¾Ž����޷�ʹ�ý�ת���ƣ�\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	switch (random(3))
	{
	case 0:
		msg = HIM "$N" HIM "Ŀ��һ����������ʽ�����⾫��֮����Ϊһ��������$n��"NOR"\n";
		break;

	case 1:
		msg = HIM "$N" HIM "����" + weapon->name() +
		       HBRED"����$N���裬����������Ӱ���γ�������ӿ��$n������"NOR"\n";
		break;

	default:
		msg = HIM "$N" HIR "�������еĽ����ڿ��л�������Ȧ��Ȧ�������������������뱼��$n"NOR"\n";
		break;
	}

	ap = me->query_skill("lonely-sword", 1) + me->query_skill("martial-cognize", 1) ;
	dp = target->query_skill("parry", 1) + target->query_skill("martial-cognize", 1) +
	     target->query_skill("lonely-sword", 1);
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap * 4 + random(ap);
		me->add("neili", -400);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
					   HIR "$n" HIR "�Ѿ��㲻��$P"
					   HIR "��Ⱥ��޴�������������ֻ��Ӳ����"NOR"\n");
		me->start_busy(5);
	} else
	if (target->query_skill("martial-cognize", 1) + target->query_skill("lonely-sword", 1) > 350)
	{
		msg += CYN "Ȼ��$n" CYN "��������мܱ��������о�$N"
		       CYN "�Ĺ���������$n���½ǡ�\n";
		me->add("neili", -400);
		me->start_busy(2);
	} else
	{
		msg += CYN "$n" CYN "$N������$P"
		       CYN "����ʽ������������мܣ���$n�Ĺ�������ж������"NOR"\n";
		me->add("neili", -400);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
