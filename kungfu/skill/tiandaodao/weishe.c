// chan.c ���嵶

#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "����"ZJBR"��"; }
int perform(object me, object target)
{
        object weapon;
        int level, b;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("�����嵶��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if (!living(target))
                return notify_fail("�Է��Ѿ�����ս���ˣ�\n");

        if ((level = me->query_skill("tiandaodao", 1)) < 100)
                return notify_fail("��������������죬����ʹ�á����嵶����\n");

        if (me->query("neili") < 100)
                return notify_fail("�����������������޷�ʹ�á����嵶����\n");

        msg = HIM "$N" HIM "ʹ������������嵶����Ĭ�˿ھ���������"
              + weapon->name() + HIM "һ������ʱ����һ�������Ļ��������\n" NOR;

        me->add("neili", -100);
        if (level + random(level)  > (int)target->query_skill("parry", 1))
        {
                msg += HIR "���$p" HIR "�پ����ǲ������������ң�"
                       "ȫȻ��֪���ںδ�������������\n" NOR;
                b = level / 20;
                target->start_busy(b);
                me->start_busy(1);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ����æ"
                       "�˹�������ס��\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}

