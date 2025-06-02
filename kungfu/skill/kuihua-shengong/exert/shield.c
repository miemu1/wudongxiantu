// shield.c ������
//

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "а������"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("��ֻ����а�������������Լ��ķ�������\n");
	
	if (userp(me) && !me->query("special_skill/ghost"))
		return notify_fail("��û�й������ԣ��޷�����а�����塣\n");
	
	if ((int)me->query("neili") < 100)
		return notify_fail("�������������\n");

	if (userp(me) && (int)me->query_skill("kuihua-shengong", 1) < 100)
		return notify_fail("��Ŀ�������Ϊ������\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIW "$N" HIW "���Ӻ�ǰ���󣬺�����ң�һ"
			"������˵�崷�ӿ����סȫ��"NOR"\n", me);

	me->add_temp("apply/armor", skill*150/100);
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (!me) return;

	me->add_temp("apply/armor", -(amount*150/100));
	me->delete_temp("shield");
	tell_object(me, "��Ŀ�����������ϣ��������ջص��\n");
}

