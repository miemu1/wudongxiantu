// leidong �׶�����
// by winder 98.12

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "��Ӱ"ZJBR"����"; }

int perform(object me)
{
	int skill, count, count1;

	if ((int)me->query_temp("guiying"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	if ((int)me->query("neili") < 5000)
		return notify_fail("�����ڵ�����������\n");

	skill = me->query_skill("force");
	if (skill < 300)
		return notify_fail("���ħ����Ϊ��������\n");

	me->add("neili", -1000);
	message_combatd(HIM "$N" HIM "��������һ��������Ӱ�����˷����"
			"����"NOR"\n", me);

	count = skill / 9;

	if (me->is_fighting())
		me->start_busy(4);

	//me->add_temp("str", count);
	me->add_temp("dex", count);
	me->set_temp("guiying", 1);
	me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("guiying"))
	{
		//me->add_temp("str", -amount);
		me->add_temp("dex", -amount);
		me->delete_temp("guiying");
		tell_object(me, CYN "��Ĺ�Ӱ����������ϡ�"NOR"\n");
	}
}
