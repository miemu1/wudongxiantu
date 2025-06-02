// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;

string query_name() { return "����"ZJBR"һ��"; }

#define HUN "��" HIW "����һ��" NOR "��"

string final(object me, object target, int damage);

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;

        if (! target)target = me->select_opponent();

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUN "ֻ�ܿ���ʩչ��\n");

        if (me->query_skill("taixuan-gong", 1) < 120)
                return notify_fail("���̫������������죬����ʩչ" HUN "��\n");

        if (me->query_skill_mapped("unarmed") != "taixuan-gong")
                return notify_fail("������û�м���̫����Ϊȭ�ţ�����ʩչ" HUN "��\n");

        if (me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("������û�м���̫����Ϊ�ڹ�������ʩչ" HUN "��\n");

        if (me->query_skill_prepared("unarmed") != "taixuan-gong")
                return notify_fail("������û��׼��ʹ��̫����������ʩչ" HUN "��\n");

        if (me->query("neili") < 600)
                return notify_fail("�����������������ʩչ" HUN "��\n");
 
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "\n$N" HIG "˫�ֺ�ʮ��˫Ŀ΢�գ�̫���������ĵ�ӿ������Ȼ�䣬$N"
              HIG "˫����ǰ�Ƴ���һ��ǿ��������Ϯ��$n " HIG "��\n" NOR;
 
        ap = me->query_skill("unarmed") + me->query("con")*10;

        dp = target->query_skill("force") + target->query("con")*10;

        me->add("neili", -300);

        if (ap / 2 + random(ap) < dp)
        {
                msg += HIY "Ȼ��$n" HIY "ȫ���ֵ������ڽ�$N" HIY "������������ס��\n" NOR;
                me->start_busy(2);
        } else
        {
                me->start_busy(3);
                damage = ap + random(ap/2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90 + random(5),
                                           (: final, me, target, damage :));

        }
        message_combatd(msg, me, target);
        return 1;
}

string final(object me, object target, int damage)
{
        target->receive_damage("jing", damage / 5, me);
        target->receive_wound("jing", damage / 8, me);
        target->busy(1);
        return  HIR "$n" HIR "��æ������ˣ�����������"
                "�ø��죬ֻ��$p" HIR "һ���ҽУ�һ����"
                "���Ѿ�͸���������Ѫ�ɽ���$n" HIR "��"
                "��������ɢ���޷����С�\n" NOR;
}

