// ����׷��(gouhun)

#include <ansi.h>
#include <combat.h>

#define PFM "��" HIW "���촵ѩ" NOR "��"

inherit F_SSERVER;

string *weapon_sk = ({
	"sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

string query_name() { return "����"ZJBR"��ѩ"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int count;
	int i, attack_time;


	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail(PFM "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	
	
	if ((int)me->query_skill("chuixue-jian", 1) < 100)
		return notify_fail("��" + to_chinese("chuixue-jian") + "������죬����ʩչ" PFM "��\n");

	
	if (me->query("neili") < 300)
		return notify_fail("�����ڵ���������������ʩչ" PFM "��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N���������������ˣ�����˺�ѿ�����ƬƬѩ��Ʈ�䣬��δ�����ȼ���$nüë�������˱�����˪��" + "\n" + NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");
	attack_time = 6;

	if (ap * 2 / 3 + random(ap * 2) > dp)
	{
		msg += HIM "���$n���ܲ�����$N�Ľ�����ʱ͸����룬$n������Ѫ���磬����������" + ""NOR"\n";
		count = ap / 10;
		me->add_temp("apply/attack", count);
		me->add_temp("apply/damage", count);
	} else
	{
		msg += NOR + CYN "$p���Ʋ�������ˣ����ձܹ�$P�����ɱ�У����������У������ѿ���һ������ӣ�" + ""NOR"\n";
		count = 0;
	}

	message_sort(msg, me, target);

	attack_time += me->query("jieti/times") * 2;
	if (attack_time > 13)
		attack_time = 13;

	me->add("neili", -attack_time * 20);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;

		if (random(2) && ! target->is_busy()) target->start_busy(1);

		COMBAT_D->do_attack(me, target, (member_array("sword", weapon_sk) == -1 ? 0 : weapon), 0);
	}
	me->add_temp("apply/attack", -count);
	me->add_temp("apply/damage", -count);
	me->start_busy(3 + random(attack_time/ 3));

	return 1;
}


