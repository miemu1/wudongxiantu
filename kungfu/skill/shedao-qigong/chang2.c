// ���ɷ�

#include <ansi.h>

string query_name() { return "����"ZJBR"����"; }

int perform(object me)
{
	int skill;
	string msg;

	if (! me->is_fighting())
		return notify_fail("���ɷ�ֻ����ս����ʹ�á�\n");

	if ((int)me->query_skill("shedao-qigong", 1) < 80)
		return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ���\n");

	if ((int)me->query_temp("chang") <= -20)
		return notify_fail("���Ѿ�����̫���ˣ������ٳ��ˡ�\n");

	message_combatd(HIR "ֻ��$N" HIR "���������дʣ����֮���������ǣ�"NOR"\n", me);
	me->add_temp("apply/attack", -2);
	me->add_temp("apply/dodge", -2);
	me->add_temp("apply/defense", -2);
	me->add_temp("chang", -2);
	me->add("neili", 500);

	return 1;
}
