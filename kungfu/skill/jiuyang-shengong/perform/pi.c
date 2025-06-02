// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define PO "��" HIW "��������" NOR "��"
string query_name() { return "����"ZJBR"����"; }
inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/jiuyang-shengong/pi"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" PO "��\n");

        if (userp(me) && (me->query_temp("weapon") || me->query_temp("secondary_weapon")))
                return notify_fail( "ֻ�ܿ���ʩչ" PO "��\n");
        
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < 220)
                return notify_fail("��ľ����񹦲�����죬����ʩչ" PO "��\n");

        if ((int)me->query_skill("force", 1) < 260)
                return notify_fail("����ڹ���������������ʩչ" PO "��\n");

        if (me->query_skill_mapped("unarmed") != "jiuyang-shengong")
                return notify_fail("������û�м���������Ϊȭ�ţ�����ʩչ" PO "��\n");

        if (me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("������û�м���������Ϊ�ڹ�������ʩչ" PO "��\n");

        if (me->query_skill_prepared("unarmed") != "jiuyang-shengong")
                return notify_fail("������û��׼��ʹ�þ����񹦣�����ʩչ" PO "��\n");

        if ((int)me->query("max_neili") < 5500)
                return notify_fail("���������Ϊ���㣬����ʩչ" PO "��\n");

        if (me->query("neili") < 400)
                return notify_fail("��������������������ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n$N" HIW "��Ȼ�������𣬰����һ����Х������ԴԴ������ӿ"
              "����" HIW "ɲ�Ǽ��â��Ŀ��������£�˫ȭ��Ϯ��$n" HIW "��\n" NOR;

        me->add("neili", -150);
        ap = me->query_skill("unarmed") + me->query_skill("force", 1);
        dp = target->query_skill("parry") + target->query_skill("force", 1);

        me->start_busy(2 + random(2));
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("unarmed");
                me->add("neili", -200);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 85 + random(5),
                                           (: final, me, target, damage :));
        } else
        {
                msg += HIC "����$n" HIC "��͸$P" HIC "����֮�е���������"
                       "����㣬ȫ��Ӧ�����硣\n" NOR;
        }
        message_sort(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        target->add("neili", -(damage / 4));
        target->add("neili", -(damage / 8));
        return  HIR "$n" HIR "ֻ����������ӿ������ԥ��ȭâ�ѻ���$n" HIR "���壬��ʱ"
                "��Ѫ��ӿ����Ϣɢ�ҡ�\n" NOR;
}


