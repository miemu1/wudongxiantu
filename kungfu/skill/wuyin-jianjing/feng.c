#include <ansi.h>
#include <combat.h>

#define FENG "��" HIW "�������" NOR "��"
string query_name() { return "�������"; }
string name() { return HIR "�������" NOR; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, wn;
        object weapon;
        int level;

      /*   if( userp(me) && !me->query("can_perform/wuyin-jianjing/feng") )
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n"); */

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" FENG "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("wuyin-jianjing", 1) < 100)
                return notify_fail("�����󽣾�������죬����ʩչ" FENG "��\n");

        if (me->query_skill_mapped("sword") != "wuyin-jianjing")
                return notify_fail("��û�м������󽣾�������ʩչ" FENG "��\n");

        if (me->query_skill("dodge") < 600)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" FENG "��\n");

        if( me->query("neili")<1500 )
                return notify_fail("�����ڵ���������������ʩչ" FENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIC "\n$N" HIC "��" + wn + HIC "������ǰ���������ڽ���"
              "��Ȼ��" + wn + HIC "��һ��������ӳ�����ʱ��ɳ���죬��"
              "�˷�����˼��" NOR;

        message_sort(msg, me, target);

        level = me->query_skill("sword");

        me->add("neili", -1500);

        if (level * 1 / 3 + random(level) > target->query_skill("dodge"))
        {
                msg = HIY "$N" HIY "������$n" HIY "��ʽ�е���ʵ����æ"
                      "��ס�Լ�ȫ��һʱ������Ӧ�ԣ�\n" NOR;
                target->start_busy(1 + random(level / 200));
                me->start_busy(random(2));
        } else
        {
                msg = CYN "����$N" CYN "��������С�Ĳ��У�û�б�"
                      "$n" NOR + CYN "��ʽ������\n" NOR;

                me->start_busy(2);
        }
        message_combatd(msg, target, me);

        return 1;
}