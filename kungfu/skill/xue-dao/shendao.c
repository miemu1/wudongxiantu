// shendao.c  Ѫ������Ѫ�񵶡�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "��Ѫ"ZJBR"��"; }
string *pfm_type() { return ({ "blade", }); }

int perform(object me, object target)
{
	int  daogang, zhenshang,damage;
	string msg;
	object weapon;

	if (userp(me) && ! me->query("can_perform/xue-dao/shendao"))
		return notify_fail("�㻹����ʹ�á���Ѫ�񵶡���\n");

	if (! target)
		target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("����Ѫ�񵶡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("װ��������ʹ�á���Ѫ�񵶡���\n");

	if ((int)me->query_skill("xue-dao", 1) < 100)
		return notify_fail("��Ѫ��������죬ʹ��������Ѫ�񵶡���\n");

	if ((int)me->query_skill("force") < 100 )
		return notify_fail("���ڹ���򲻹�������ʩչ����Ѫ�񵶡���\n");

	if ((int)me->query("max_neili") < 1200)
		return notify_fail("���������Ϊ���㣬�޷�����������\n");

	if ((int)me->query("neili") < 400)
		return notify_fail("�����������������޷�������Ѫ�񵶡�ʹ�꣡\n");

	if ((int)me->query("qi") < 100)
		return notify_fail("�㻹��ʹ���У���������\n");

	if ((int)me->query("shen") > -1000)
		return notify_fail("��Ϊ�˲����ײУ����޷���ᡸ��Ѫ�񵶡��İ��\n");

	if (me->query_skill_mapped("blade") != "xue-dao")
		return notify_fail("��û�м���Ѫ��������ʹ�á���Ѫ�񵶡���\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "���ֳֵ������һ�գ�һ��Ѫ�齦�����棬�������ұ��ճ���һƬѪ��"
	      "��ס��Ӱ��$n" HIR "��ͷ���䡣"NOR"\n";

	if (random(me->query_skill("blade")) > (int)target->query_skill("force") / 2)
	{
	    daogang = me->query_skill("xueying-daogang", 1);
		damage = me->query_skill("blade");
		damage = damage + random(damage / 2);
		damage = damage*(daogang+100)/100;
		if (me->query("character") == "�ĺ�����")
			damage += damage * 2 / 10;
		me->add("neili", -350);
		me->start_busy(3);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
					   HIR "$n" HIR "��æ������ã���Ѫ��������ֻ����"
					   "ǰһ��Ѫ�죬����������£���Ѫ��"
					   "�������������󺿣�"NOR"\n");
	if (daogang > 49) {
	zhenshang = me->query_skill("xue-dao", 1)*daogang/50;
		msg += HIR "$P" HIR "����һ����Ѫ��ħ����ת�����£������߳������"NOR"\n"HIR"��ʵ�˺� "+zhenshang+"�㡣"NOR"\n";
	target->receive_wound("qi", zhenshang);
	}
	} else
	{
		me->start_busy(3);
		msg += CYN "����$n" CYN "������ã����Ų�æ�������$N"
		       CYN "�ı�ɱһ����"NOR"\n";
		me->add("neili", -100);
	}
	// me->receive_wound("qi", 50);
	message_combatd(msg, me, target);
	return 1;
}
