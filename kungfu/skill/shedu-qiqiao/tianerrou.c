// leidong �׶�����
// by winder 98.12

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "���"ZJBR"��"; }
//string *pfm_type() { return ({ "force", }); }

int perform(object me)
{
	int skill, count, count1;

	if ((int)me->query_temp("tianerrou"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("�����ڵ�����������\n");
	
	if ((int)me->query_skill("hamagong", 1) < 30)
		return notify_fail("��ĸ�󡹦����Ϊ���� !\n");

	skill = (int)me->query_skill("shedu-qiqiao", 1);
	//if ((int)me->query_skill("shedu-qiqiao", 1) < 80)
	if (skill < 300)
		return notify_fail("�����Ϊ��������\n");

	me->add("neili", -400);
	message_combatd(HIM "$N" HIM "�������һ������⣬"
			"������Խ��Խ�أ�"NOR"\n", me);

	count = skill / 10;

	if (me->is_fighting())
		me->start_busy(3);

	me->add_temp("str", count*2);
	//me->add_temp("dex", count);
	me->set_temp("tianerrou", 1);
	me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("tianerrou"))
	{
		me->add_temp("str", -amount);
		//me->add_temp("dex", -amount);
		me->delete_temp("tianerrou");
		tell_object(me, CYN "��ĸ�󡹦������ϣ��������ջص��"NOR"\n");
	}
}
