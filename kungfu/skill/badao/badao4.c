#include <ansi.h>
#include <combat.h>

#define CHAN "��" HIC "�Ͽ�" NOR "��"
string query_name() { return "�Ͽ�"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int level;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԣ�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((level = me->query_skill("badao", 1)) < 200)
                return notify_fail("��Ŀ����ɾ�������죬����ʩչ" CHAN "��\n");

        if (me->query_skill_mapped("blade") != "badao")
                return notify_fail("��û�м��������ɾ�������ʩչ" CHAN "��\n");

        if( me->query("neili")<1000 )
                return notify_fail("��������������������ʩչ" CHAN "��\n");

        if( me->query("qi")<1000 )
                return notify_fail("��������Ѫ����������ʩչ" CHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "������������Ȼ�䣬����һת��һ��ǿ���ĵ������ڶ�����˲������˺�ѣ���$n" HIC "���֡�\n" NOR;

        me->add("neili", -1000);
		me->add("qi", -1000);
        if (random(level) + 1000 > (int)target->query_skill("dodge", 1) * 1 / 2)
        {
                msg += HIR "���$p" HIR "��$P" HIR "�ָ���æ���ң�"
                       "����ʧ�룬���ڵ�������֪���Ӧ�ԣ�\n" NOR;
                target->start_busy(random(3) + 5);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ����"
                       "����㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}