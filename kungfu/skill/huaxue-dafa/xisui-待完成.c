// xishui.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

string query_name() { return "����"ZJBR"��"; }

int exert(object me, object target)
{
	int ap;
	int dp;
	int damage;
	string msg;

	if (target == me || ! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
                return notify_fail("������󷨡�ֻ����ս�������ڶ������ϡ�\n");

	if (me->query_skill("huaxue-dafa", 1) < 100)
                return notify_fail("��Ļ�Ѫ�󷨲�������, ����ʹ�á�����󷨡���\n");


	if ((int)me->query("neili") < 1000)
		return notify_fail("�������������");


	 msg = HIC "$N���ᵤ���ʱ����һƬ���࣬˫���Ƴ�һ�������ޱȵ�����������$n��\n"NOR;

	ap = me->query_skill("force");
	dp = target->query_skill("force");

	me->start_busy(2);

	if( random(ap) > dp / 2)
	{
		damage = ap;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3 , me);
		if (target->query("neili") > damage * 3)
			target->add("neili", damage * 3);
		else
			target->set("neili", 0);

		 msg += WHT"$nֻ����һ������Ϯ����һ�ɺ���ֱ�������衢���衢Ѫ�衢���衣������\n"NOR;
		if (! target->is_busy())
			target->start_busy(1);

		target->set_temp("huaxue-dafa_xishui", 1);
		target->start_call_out((: call_other, __FILE__, "remove_effect", target :),
				       me->query_skill("huaxue-dafa") / 5);

	} else
		
msg += YEL"����$p���Ա߲���һ��,�������������ޱȵ�������\n"NOR;


	message_combatd(msg, me, target);

	return 1;
}

string finala(object me, object target, int damage)
{
        int lvl;
        lvl = me->query_skill("force");

        target->affect_by("tiezhang_yin",
                       (["level":me->query("jiali")+random(me->query("jiali")/2),
                          "id":me->query("id"),
                          "duration" : lvl / 50 + random(lvl / 50) ]));

        return HIW "���Ǽ�$n" HIW "�ѱ�$N" HIW "����󷨷���Ҫ"
               "�������ɵû���һ��������֮����\n" NOR;
}

