// bai ����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "����"ZJBR"����"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
	int delta;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("�����ܼ��Ρ�ֻ����ս���жԶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");


	if (me->query_skill("sword", 1) < 200)
		return notify_fail("��Ľ�����Ϊ������Ŀǰ����ʹ�á����ܼ��Ρ���\n");

	if (me->query_skill("feixian-sword", 1) < 125)
		return notify_fail("��ķ��ɽ�������Ϊ����������ʹ����һ������\n");

	if (me->query_skill("dodge") < 200)
		return notify_fail("����Ṧ��Ϊ�������޷�ʹ�á����ܼ��Ρ���\n");
 
	if (me->query("neili") < 350)
		return notify_fail("�������������\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	if (me->query("gender") == "Ů��" &&
	    target->query("gender") != "����")
		delta =  me->query("per") - target->query("per") / 2;
	else
		delta = 0;

	msg = HIR "$N" HIR "���㡣�����������޵������𡣡����е�" + weapon->name() +
	      HIG "����������ʽ��Ŀ��������̡�����ÿ�λӽ�������Ī������ζ��"NOR"\n";
	if (delta > 0)
		msg += HIY "$n" HIY "ֻ����$N" HIY "��������Ȼ͸��"
		       "һ�ɺ��⣬���в���һ����"NOR"\n";
	else
		delta = 0;

	me->add("neili", -250);
	ap = (me->query_skill("feixian-sword") + me->query_skill("sword")) / 2;
	dp = target->query_skill("dodge");
	me->start_busy(5);
	if (ap * 2 + random(ap) > dp )
	{
		damage = ap * 4 + random(ap * 2) + delta * 50;
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
					   HIR "$n" HIR "��о�һ���������Լ����崩�����������˼��㣡\n" NOR);
		if (objectp(weapon = me->query_temp("weapon")) &&
		    ap / 2 + random(ap) > dp)
		{
			damage /= 2;
			msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
						   HIW "$nĿ����Ͳ�֪��Ϧ���ꡣ$P"
						   HIW "����" + weapon->name() +
						   HIW "��â��ʤ����������\n" HIR "ֻ��$p"
						   HIR "�۵�һ��������ֱ�롣"NOR"\n");
		}
	} else
	{
		  msg += "$N�����˿�ȥ���ܿ���$n��һ������Ŀ�������ù��򡣺ù��򣡡�\n"NOR;
              
	}

	message_combatd(msg, me, target);

	return 1;
}
