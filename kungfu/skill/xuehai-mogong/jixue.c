// jixue.c Ѫ��ħ����Ѫ��

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

string query_name() { return "��Ѫ"ZJBR"��"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{  
	object weapon = me->query_temp("weapon");
	string msg;
	int skill;

	if ((int)me->query_temp("jixue"))
		return notify_fail("���Ѿ������Ѫ���ˡ�\n");
	
if ((int)me->query_temp("jixue-zheng"))
		return notify_fail("���Ѿ������Ѫ���ˡ�\n");
	
	if ((int)me->query("neili") < 300)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("���Ѫ��ħ������Ϊ����������ʹ�ü�Ѫ�󷨣�\n");

	msg = HIR "$N" HIR "ʹ��Ѫ��ħ������Ѫ�󷨡���ɲʱ����ɫ���"
	      "Ѫ�죬"HIR "$N" HIR "����ҧ����⣬���һ����Ѫ��"NOR"\n";

	skill = (int)me->query_skill("xuehai-mogong", 1);

	
	
	if (me->query("qi") > me->query("max_qi") / 2 )
	{
		if (!me->query_temp("weapon")==0 && weapon->query("magic/skill/xuehai-mogong"))
	{
		me->add_temp("apply/damage",skill*2);
		me->add_temp("apply/unarmed_damage",skill*2);
		me->set_temp("jixue-zheng", 1);
		me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), 2 + skill/50);
		me->add("neili", -500);
		me->receive_damage("qi", me->query("max_qi") / 2);
		msg = HIR "$N" HIR "ʹ����Ѫ��������ˮ����������ʹ�󷨵���������һ��¥��"NOR"\n";
		message_combatd(msg, me);
	return 1;
	} 
		me->add_temp("apply/damage", skill);
		me->add_temp("apply/unarmed_damage", skill);
		me->set_temp("jixue", 1);
		me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), 2 + skill/50);
		me->add("neili", -250);
		me->receive_damage("qi", me->query("max_qi") / 3);
	} else
		msg = HIR "$N" HIR "�����Լ��������ã�û�������Ѫ�󷨡�"NOR"\n";

	message_combatd(msg, me);
	return 1;
}

void remove_effect(object me, int amount)
{
	object weapon = me->query_temp("weapon");
	int skill = (int)me->query_skill("xuehai-mogong", 1);
	if ((int)me->query_temp("jixue-zheng") && (weapon->query("magic/skill/xuehai-mogong")))
	{
		me->add_temp("apply/damage", -skill *2);
		me->add_temp("apply/unarmed_damage", -skill*2);
		me->delete_temp("jixue-zheng");
		tell_object(me, "��ˮ���������𽥼��������޷�����ά�ִ󷨡�\n");
	}
	
	
	if ((int)me->query_temp("jixue"))
	{
		me->add_temp("apply/damage", -amount);
		me->add_temp("apply/unarmed_damage", -amount);
		me->delete_temp("jixue");
		tell_object(me, "��ļ�Ѫ��������ϣ��������ջص��\n");
	}
}
