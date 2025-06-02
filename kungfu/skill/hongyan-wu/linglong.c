#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount, int amount1);

string query_name() { return "��"ZJBR"��"; }

int perform(object me, object target)
{
	object weapon;  
	string msg;
	int count, skill;

	if ((int)me->query_temp("ling_long"))
		return notify_fail("���Ѿ��������硹�ˡ�\n");

	if ((int)me->query_skill("hongyan-wu", 1) < 120)
		return notify_fail("��ĺ��������軹������죬����ʩչ���������\n");

	if ((int)me->query_dex() < 30)
		return notify_fail("���������ʹ�á����硹������\n");

	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("����ڹ���򲻹�������ʩչ���������\n");

	if ((int)me->query_skill("dodge", 1) < 50)
		return notify_fail("����Ṧ��Ϊ����������ʹ�ô��������\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("���������Ϊ����ʹ�á����硹��\n");

	if ((int)me->query("neili") < 250)
		return notify_fail("���ʱ���������㣡\n");

	msg = HBCYN "$N" HBCYN "���������������촽������Ȼһ����쳾�����շ�������������������һչ���������裬���ν��飬�����˺����ѽ�����һ����ء�"NOR"\n";
	
	message_combatd(msg, me, target);
	skill = me->query_skill("hongyan-wu", 1);

	count = skill / 30;

	if (me->is_fighting())
		me->start_busy(2);

	//me->add_temp("str", count);
	me->add_temp("dex", count);
	me->set_temp("ling_long", 1);
	me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 1);

	me->add("neili", -200);
	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ((int)me->query_temp("ling_long"))
	{
		//me->add_temp("str", -amount);
		me->add_temp("dex", -amount);
		me->delete_temp("ling_long");
		tell_object(me, "��ġ����硹�˹���ϣ��������ջص��\n");
	}
}
