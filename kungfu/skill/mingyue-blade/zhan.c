// This program is a part of NITAN MudLIB
// �������µ���ն.����

#include <ansi.h>
#include <combat.h>

#define ZHAN "��" HIY "ն"HIR"."HIY"��" NOR "��"
string query_name() { return "ն��"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHAN "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" ZHAN "��\n");

        if (me->query_skill("mingyue-blade", 1) < 120)
                return notify_fail("����������µ���Ϊ����������ʩչ" ZHAN "��\n");

        if (me->query("neili") < 1200)
                return notify_fail("�����������������ʩչ" ZHAN "��\n");

        if (me->query_skill_mapped("blade") != "mingyue-blade")
                return notify_fail("��û�м����������µ�������ʩչ" ZHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");


        msg= HIC "$N" HIC "����ӿ��������������۳�ɳ����ɱ����ǧ������֮���׳���黳��һ����Х����ض��𣬼����������$n��ȥ��\n"
             HIC "ͬʱ������" + weapon->name() + HIC"�ɺ�ڱ��ֱָ��ǿ���ɭ�����ǵĵ�����$n��ӿ��ȥ��\n" NOR;

        ap =  me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("blade")*2;
                me->add("neili", -240);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                           HIR "$n" HIR "����������˸����ĵ�����"
                                           "��ʱ������ǰһƬ���⣬��Ȼ��֪��ζ�ܣ�\n" NOR);
                me->start_busy(2);
                if (ap / 3 + random(ap / 2) > dp && ! target->is_busy())
                        target->start_busy(3);
        } else
        {
                msg += CYN "$p" CYN "���һ����Ҳ���мܣ��������"
                       "�������ߣ��ܿ���$P" CYN "��һ�С�\n" NOR;
                me->add("neili", -120);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
        return 1;
}


