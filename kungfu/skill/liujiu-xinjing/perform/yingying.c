// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string query_name() { return "����"ZJBR"��ȭ"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;

		if (! target) target = offensive_target(me);
        if (! target || ! me->is_fighting(target))
                return notify_fail("������ȭֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭֻ�ܿ���ʩչ��\n");

        if (me->query("max_neili") < 6000)
                return notify_fail("�����������Ϊ�����������޷�ʹ��������ȭ��\n");

        if (me->query_skill("liujiu-xinjing", 1) < 200)
                return notify_fail("��������ľ���������죬����ʩչ������ȭ��\n");

        if (me->query_skill_mapped("unarmed") != "liujiu-xinjing")
                return notify_fail("������û�м��������ľ�Ϊȭ�ţ�����ʩչ������ȭ��\n");

        if (me->query_skill_mapped("force") != "liujiu-xinjing")
                return notify_fail("������û�м��������ľ�Ϊ�ڹ�������ʩչ������ȭ��\n");

        if (me->query_skill_prepared("unarmed") != "liujiu-xinjing")
                return notify_fail("������û��׼��ʹ�������ľ�������ʩչ������ȭ��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�����������ȭ��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIR "���ӹֽ�һ����˫ȭ"
              "�������������$n" HIR "����ȥ��\n" NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("parry");

        if (ap*2/3 + random(ap) > dp)
        {
                count = ap*20;
                msg += HIY "$n" HIY "ֻ���Է�������Ȥ��"
                       "һʱ���飬��Ȼ���������¡�\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "����$N" HIY "һ���ֽУ�"
                       "��æ��ס���ӣ������ܿ���\n" NOR;
                count = ap*5;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/unarmed_damage", count);

        me->add("neili", -300);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/unarmed_damage", -count);

        return 1;
}

