#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
	int damage;
	object target;
	string msg;

	target = me->select_opponent();

	if (!target || !me->is_fighting(target))
		return 1;

	msg = HIR "$N����һ�䣬˲������$n" HIR "�����壬һȭ��$n" HIR "���ؿڴ�ȥ��" NOR "\n";

	if (!random(3))
	{
		damage = me->query("max_skill_level") * 5;
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 180, 
			HIR "$N" HIR "����һȭ����$n" HIR "��$n" HIR "�Ŀ����³�һ����Ѫ��" NOR "\n");
	}
	else
	{
		msg += HIC "$n���Ա�һ���������$N�Ĺ�����\n";
	}

	message_combatd(msg, me, target);
	return 1;
}