#include <ansi.h>

inherit F_SSERVER;

#define LIAN "��" HIW "����" NOR "��"
 string query_name() { return "����"ZJBR"��"; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԣ�\n");

        if( me->query("neili")<300 )
                return notify_fail("��������������޷�ʩչ" LIAN "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹�������ʩչ" LIAN "��\n");

        if ((int)me->query_skill("anyezangdi-jing", 1) < 100)
                return notify_fail("��İ�ҹ�ᾭ�����������ң��޷�ʩչ" LIAN "��\n");

        if (me->query_skill_mapped("blade") != "anyezangdi-jing")
                return notify_fail("��û�м�����ҹ�ᾭ���޷�ʩչ" LIAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "ʹ����ҹ�ᾭ�ľ�����" HIW "����" HIY"����������Ȼ�ӿ죬գ�ۼ䣬�����˶�ʮ�˵���\n" NOR;

        message_combatd(msg, me);
        me->add("neili", -60);

        count = me->query_skill("blade") / 3*100;
        me->add_temp("apply/damage", count);

        for (i = 0; i < 28; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/damage", -count);
        me->start_busy(2 + random(3));
        return 1;
}