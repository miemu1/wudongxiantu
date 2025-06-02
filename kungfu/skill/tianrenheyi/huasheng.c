#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount, int amount1);

string query_name() { return "����"ZJBR"����"; }

int perform(object me, object target)
{
	object weapon;  
	string msg;
	int count, skill;

	if ((int)me->query_temp("ling_long"))
		return notify_fail("���Ѿ��������˻������ˡ�\n");

	if ((int)me->query_skill("tianrenheyi", 1) < 600)
		return notify_fail("��Ĺ��������������죬����ʩչ���������\n");

	if ((int)me->query_dex() < 40)
		return notify_fail("���������ʹ�á����˻�����������\n");

	if ((int)me->query_skill("force", 1) < 600)
		return notify_fail("����ڹ���򲻹�������ʩչ���������\n");

	if ((int)me->query_skill("dodge", 1) < 600)
		return notify_fail("����Ṧ��Ϊ����������ʹ�ô��������\n");

	if ((int)me->query("max_neili") < 2500)
		return notify_fail("���������Ϊ����ʹ�á����˻�������\n");

	if ((int)me->query("neili") < 2500)
		return notify_fail("���ʱ���������㣡\n");

	msg =BLK HBCYN "$N" BLK HBCYN "˫����ץ���ó�ǧ���ҫ�۵Ľ�⣬��ʱ������Х�����������ж�ʱ����һ��̶��ı���һ��������������ʱ����ӿ������"NOR"\n";
	
	message_combatd(msg, me, target);
	skill = me->query_skill("tianrenheyi", 1);

	count = skill / 100;

	if (me->is_fighting())
		me->start_busy(2);

	//me->add_temp("str", count);
	me->add_temp("dex", count);
	me->set_temp("ling_long", 1);
	me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 1);

	me->add("neili", -2500);
	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ((int)me->query_temp("ling_long"))
	{
		//me->add_temp("str", -amount);
		me->add_temp("dex", -amount);
		me->delete_temp("ling_long");
		tell_object(me, "��ġ����˻������˹���ϣ��������ջص��\n");
	}
}
