// leiting.c ������һ����

#include <ansi.h>
#include <combat.h>

#define LEITING "��" HIY "����һ��" NOR "��"

inherit F_SSERVER;

string query_name() { return "����"ZJBR"һ��"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(LEITING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("force") < 250)
		return notify_fail("����ڹ���򲻹���ʹ����" LEITING "��\n");

	if ((int)me->query_skill("dragon-strike", 1) < 170)
		return notify_fail("��Ľ���ʮ���Ʋ�������������ʹ��" LEITING "��\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("��������������޷�ʹ��" LEITING "��\n");

	if (me->query_skill_mapped("strike") != "dragon-strike")
		return notify_fail("��û�м�������ʮ���ƣ��޷�ʹ��" LEITING "��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "Ĭ���ڹ���ʩչ��" LEITING HIC "��ȫ����ת��������"
	      "Խ��Խ�죬������һ�����磬��Ȼ�䣬$N" HIC "�Ѿ�������"
	      "�÷�����" HIC "$n��"NOR"\n";  

	ap = me->query_skill("strike")+me->query_skill("taiji-shengong")+me->query_skill("liangyi-yinyangjue");
	dp = target->query_skill("force")+target->query_skill("taoism")+target->query_skill("liangyi-yinyangjue");
	me->start_busy(3);
	if (ap / 2 + random(ap) > dp)
	{ 
		damage = ap + random(ap / 2);
		me->add("neili", -400);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90,
					   HIR "$p" HIR "ֻ��һ������Ӱ�ж�Ȼ�ֳ�$P"
					   HIR "��˫�ƣ�������������ܣ������ػ��У���"
					   "���������ڲ��ݣ�������Ѫ��������������"NOR"\n");
	} else
	{
		msg += HIG "����$p" HIG "������$P" HIG "����ͼ��û"
		       "���ܵ��Ի�������һ�ߡ�"NOR"\n";
	}
	message_combatd(msg, me, target);
	
	if (me->query_skill("bixue-danxin", 1) > 49 ) 
	{
        msg = HIW "$N" HIW "����б�ӣ�ǰ������δ�������������ֵ�����Ȼ�ֹ���һ�С�" HIR "�����л�" HIW "�����Ƽз��ƣ���������"
              HIW "����һ��������ǽ����ǰ�����ȥ��$n" HIW "ֻ����Ѫ��ӿ����Ϣ���ǡ�\n" NOR;

	if (ap / 2 + random(ap) > dp)
	{
		damage = (ap + random(ap / 2))*(me->query_skill("bixue-danxin", 1)+100)/100;
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                          HIR "���$n" HIR "�����������ƾ���ʱ���ض�����������Ѫ���硣\n" NOR);

		me->add("neili", -300);
		message_combatd(msg, me, target);

		return 1;
	}

                msg += HIC "$p�ۼ��������ͣ����μ��ˣ�˲��"
                       "Ʈ�����ɣ��ѳ�����֮�⡣\n" NOR;
	message_combatd(msg, me, target);
	}

	return 1;
}

