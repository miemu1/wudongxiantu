
#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIB "��������" NOR; }
string query_name() { return "����"ZJBR"����"; }
inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ���������ɾ��������Լ���ս������\n");

        if( me->query_temp("shield") )
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("sword");

        message_combatd(HIR "$N" HIR "���������ֻ�������������ֻ������ƿ���ȥ��������ʣ�һ���������������Χ����$N" HIR "���ܡ�\n" NOR, me);

        // ��ͨBREAKUP���Ч������10%
        if( me->query("breakup"))skill=skill+skill*1/10;
     
        me->add_temp("apply/armor", skill*2/3);
        me->add_temp("apply/parry", skill*2/3);
		me->add_temp("apply/attack", skill*2/3);
        me->add_temp("apply/damage", skill*2/3);
        me->set_temp("shield", 1);
        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill :), skill / 2);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (! objectp(me))return;

        if( me->query_temp("shield") )
        {
                me->add_temp("apply/armor", -(amount*2/3));
                me->add_temp("apply/parry", -(amount*2/3));
		        me->add_temp("apply/attack", -(amount*2/3));
                me->add_temp("apply/damage", -(amount*2/3));
                me->delete_temp("shield");
                tell_object(me, HIW "��������ɾ����������ġ�������ϣ��������ջص��\n" NOR);
        }


}