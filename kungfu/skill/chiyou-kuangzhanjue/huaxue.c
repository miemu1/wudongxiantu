// This program is a part of NITAN MudLIB
// huaxue.c

#include <ansi.h>

#define HUAXUE "��" HIR "�񵶻�Ѫ" NOR "��"
string query_name() { return "��"ZJBR"��Ѫ"; }
inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        object weapon;
        string msg;
        int skill;

        if ((int)me->query_temp("huaxue"))
                return notify_fail(HIG "���Ѿ�����" + HUAXUE + HIG "�ˡ�\n");

        /*
        if (! me->is_fighting())
                return notify_fail(HUAXUE + "ֻ����ս����ʹ�á�\n");
        */

        if ((int)me->query("neili") < 200)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("�����ȿ�ս����Ϊ����������ʹ��" + HUAXUE + "��\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon) || weapon->query("skill_type") != "blade")
                return notify_fail("��û��װ����������ʩչ" + HUAXUE + "��\n");

        msg = HIR "$N" HIR "�����Ŀ�����ֳֵ�������˳��" + weapon->name() +
              HIR "����һĨ����Ѫ��ʱ��" + weapon->name() + HIR "Ⱦ�졣����$N"
              HIR "˫Ŀ��������ʱɱ�����죡\n" NOR;

        skill = (int)me->query_skill("moshen-xinfa", 1);

        me->add("neili", -150);
        me->add_temp("apply/damage", skill*5/4);
        me->add_temp("apply/unarmed_damage", skill*5/4);
        me->add_temp("apply/blade", skill*5/4);
        me->set_temp("huaxue", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                           me, skill :), skill);

        message_combatd(msg, me);
        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("huaxue"))
        {
                me->add_temp("apply/damage", -amount*5/4);
                me->add_temp("apply/unarmed_damage", -amount*5/4);
                me->add_temp("apply/blade", -amount*5/4);
                me->delete_temp("huaxue");
                tell_object(me, "���" + HUAXUE + "������ϣ��������ջص��\n");
        }
}

