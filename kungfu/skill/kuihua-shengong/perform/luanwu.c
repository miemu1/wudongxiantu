// luanwu.c ��ħ����

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return HIR"��ħ����"NOR; }

int perform(object me, object target)
{
	string msg;
	object weapon;
	int i;
	int skill;
	int count;
	int isGhost;
	int num;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("����ħ���衹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	skill = me->query_skill("kuihua-shengong", 1);
	if (userp(me)) {
		if (! me->query("can_perform/kuihua-shengong/luanwu"))
			return notify_fail("�㻹û��ͨ����ħ����İ��ء�\n");
		
		if (skill < 200)
			return notify_fail("��Ŀ�������Ϊ���ޣ����ڲ���ʹ�á���ħ���衹��\n");
		
		if (me->query_skill_mapped("sword") != "kuihua-shengong")
			return notify_fail("��û�м���������Ϊ����������ʩչ����ħ���衹��\n");
		
		if (!me->query("special_skill/ghost"))
			return notify_fail("��û�й������ԣ��޷����á���ħ���衹��\n");
	}
	if (me->query("neili") < 100)
		return notify_fail("��������������޷����á���ħ���衹��\n");

	weapon = me->query_temp("weapon");

	if (weapon &&
	    weapon->query("skill_type") != "pin")
		return notify_fail("�����ʹ�á��롱���ֱ���ʩչ����ħ���衹��\n");

    if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	if (weapon)
	{
		msg = HIR "$N" HIR "���κ�Ȼ��죬��ĳ���$n"
		      HIR "�����е�" + weapon->name() + HIR "ָָ��㣬��ͬ"
		      HIR "��ҹ����һ�㣬����â����$p" HIR "��"NOR"\n";
	} else
	{
		msg = HIR "$N" HIR "��Ȼ����$n" HIR "�������"
		      HIR "����˼�飬�������ȣ����־�����������$n" HIR "��"NOR"\n";
	}

	message_combatd(msg, me, target);
	count = skill / 8;
	isGhost = me->query("special_skill/ghost");
	num = 7+random(4);
	if (num > 20)
		num = 20;
	
	if (isGhost && random(2))
		count *= 4;

	me->add_temp("apply/attack", count);

	for (i = 0; i < num; i++)
	{
		if (! me->is_fighting(target))
			break;
		if ((random(3) == 0 || (isGhost && random(2))) && ! target->is_busy())
			target->start_busy(1);
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->start_busy(3 +random(num -3));
	me->add_temp("apply/attack", -count);

	return 1;
}

