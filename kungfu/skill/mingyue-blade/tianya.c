// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define TIANYA "��" HIY "����"HIW"����" NOR "��"
string query_name() { return "����"ZJBR"����"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, wn;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TIANYA "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" TIANYA "��\n");

        if ((int)me->query_skill("mingyue-blade", 1) < 200)
                return notify_fail("���������µ�������죬����ʩչ" TIANYA "��\n");

        if ((int)me->query_skill("force") < 280 )
                return notify_fail("����ڹ���򲻹�������ʩչ" TIANYA "��\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ����������ʩչ" TIANYA "��\n");

        if ((int)me->query("neili") < 600)
                return notify_fail("��������������������ʩչ" TIANYA "��\n");

        if (me->query_skill_mapped("blade") != "mingyue-blade")
                return notify_fail("��û�м����������µ�������ʩչ" TIANYA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIC "$N" HIC "���е� " + weapon->name() +  HIC "��Ȼ̽�����仯��ͻȻ�վ���$nһʱ���飬���ζ�ʱ��$N��" + weapon->name() + HIC"��ס��\n"
                  "ֻ��$Nһ������ĺ�����" + weapon->name() + HIC"��$nͷ��λ������������\n "NOR;


        ap =  me->query_skill("blade");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap*2) > dp)
        {
                me->start_busy(2);
                damage = me->query_skill("blade")*2;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                           HIR "$n" HIR "��ʱ��ʧɫ������ľ��,���޿ɱܣ�"
                                           "��ʱ������Ѫ��ģ������Ѫ������\n" NOR);
                me->add("neili", -500);
                me->add("shen",-100);
        } else
        {
                me->start_busy(3);
                msg += HIC "$p" HIC "��$P������ӿ����֪�����ɵ����������������ߣ����ڶ���������\n" NOR;
                me->add("neili", -400);
        }
        message_combatd(msg, me, target);
        return 1;
}

