#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "�ٻ�"ZJBR"����"; }

string query_txt()
{
	return "Ҫ�󣺰ٻ���ȭ200����ȭ�š�ȭ�����Ʒ���צ�����ַ�ȫ������Ϊ�ٻ���ȭ���ٻ���ȭ�ȼ����ܸ���5�ֿ��ֻ�������������1000"ZJBR
			"Ч�����ֱ�Ա�����5�ֿ��ּ����ȼ���Ŀ����мܼ����ȼ�����Ŀ�������5�ֵ����˺���"
			"ÿ����һ�£����� busy +1������ -100��";
}

int perform(object me, object target)
{
	string msg;
	int damage;
	int lvl;
	int n,ap,dp;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("�ٻ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_skill_prepared("unarmed") != "baihua-quan" &&
	    me->query_skill_prepared("cuff") != "baihua-quan" &&
	    me->query_skill_prepared("strike") != "baihua-quan" &&
	    me->query_skill_prepared("claw") != "baihua-quan" &&
	    me->query_skill_prepared("hand") != "baihua-quan")
		return notify_fail("������û��׼��ʹ�ðٻ���ȭ���޷�ʩչ�ٻ����ң�\n");
 
	if (me->query_temp("weapon"))
		return notify_fail("�ٻ��������ǿ��ֲ���ʩչ��\n");

	if (me->query("neili") < 1000)
		return notify_fail("��������������޷�ʩչ�ٻ����ҡ�\n");

	if ((lvl = me->query_skill("baihua-quan", 1)) < 200)
		return notify_fail("��İٻ���ȭ���������죡\n");

    if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "ֻ��$Nʹ���ٻ���ȭ�ľ���ٻ����ң��������м���ӥצ�������ֲ�ȭ���������ơ���\n"
		  "��ȥ�ǰ����ƣ��ջ�ʱ����̫��ȭ������ӳ£����޹��ɣ�ֻ��$n�ۻ����ҡ�"NOR"\n";

	n = 1;
	// ��һ��
	ap = me->query_skill("unarmed");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += "\n" HIC "$N" HIC "��������һ����������һԾ��˫�Ƚ�������$n" HIC "��"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "�����ֵ���ȴ�����мܵ�ס����$P"
					   HIR "��һ�����У�����һ����Ѫ��"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "�ٵ�һ����Ӳ������$P" CYN "��һ�żܿ���˿������"NOR"\n";
	}

	// �ڶ���
	ap = me->query_skill("strike");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += HIC "$N" HIC "�漴һ����Ц��˫�ֱ�������ʵʵ�����Ī�⣬����$n��"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "��󲻽⣬һʱ���Կ�͸���а�����м��ƣ�����������"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "����һЦ����Ȼ����$P" CYN "����������������У����⽫֮�ܿ���"NOR"\n";
	}

	// ������
	ap = me->query_skill("cuff");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += HIC "$N" HIC "����һ�����ȣ�˫�ֱ�ȭһʽ����ȭ����$nֱ�����£�"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "�����ֵ���Ȼ����һȭȴ�����벻���ĽǶ�ʵʵ���ڵĴ���$n��"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "һ�����Ե�������������$P"
		CYN "Ӳ������ס���⾫���һȭ��"NOR"\n";
	}

	// ������
	ap = me->query_skill("hand");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += "\n" HIC "$N" HIC "�Ų�һ�Σ���Ȼ��������������죬˫�ֺ�Ȼ�仯����Ȼ��һʽ�ַ���ֱָ$n" HIC "Ҫ����"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "ֻ������һ������ʱ��$P"
					   HIR "��һ�����У���ʱ�ƺ�һ����"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "��ȴ�Ǹ��죬ֻ��һ�ˣ���$P" CYN "��һ�п���������Ч��"NOR"\n";
	}

	// ������
	ap = me->query_skill("claw");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += "\n" HIC "$N" HIC "����һ�䣬����ת����צ��ץ��$n�ؿڼ�����Ѩ��"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "һʱ����$P������������ס��æ�����ؿں�Ȼһ�飡"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "�侲�Ƿ�����Ϊ����������ֵ�����©���������"NOR"\n";
	}

	me->start_busy(n);
	me->add("neili", -100);
	message_combatd(msg, me, target);

	return 1;
}
