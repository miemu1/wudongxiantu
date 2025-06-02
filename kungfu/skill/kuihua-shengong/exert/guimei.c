// gui.c ������

#include <ansi.h>

inherit F_CLEAN_UP;
void remove_effect(object me, int amount);

string query_name() { return "����"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	string msg;
	int skill;

	if (target != me)
		return notify_fail("��ֻ���ù����������Լ�������\n");
	
	if (userp(me) && !me->query("special_skill/ghost"))
		return notify_fail("��û�й������ԣ��޷����á����ȡ���\n");
	
	if (userp(me) && me->query_skill_mapped("force") != "kuihua-shengong")
		return notify_fail("��û�м���������Ϊ�ڹ�������ʩչ�����ȡ���\n");
			
	if (userp(me) && (int)me->query_skill("kuihua-shengong", 1) < 150)
		return notify_fail("��Ŀ����񹦻�򲻹�������ʹ�ù��ȡ�\n");

	msg = HIR "$N" HIR "���Ӻ������ˣ����ι����쳣������Ʈ��������"NOR"\n";

	if ((int)me->query_temp("guimei"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("kuihua-shengong", 1);
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(msg, me);

	me->add_temp("apply/dodge", skill/20);
	me->set_temp("guimei", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (!me) return;

	me->add_temp("apply/dodge", -(amount/20));
	me->delete_temp("guimei");
	tell_object(me, "��Ĺ���������ϣ��������ջص��\n");
}

