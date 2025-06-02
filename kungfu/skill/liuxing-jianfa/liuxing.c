// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define LIU "��" HIY "��������" NOR "��"
string query_name() { return "����"ZJBR"����"; }
inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIU "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" LIU "��\n");

        if (me->query_skill("force") < 120)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" LIU "��\n");

        if (me->query_skill("liuxing-jianfa", 1) < 120)
                return notify_fail("������ǽ�����Ϊ����������ʩչ" LIU "��\n");

        if (me->query("neili") < 250)
                return notify_fail("�����������������ʩչ" LIU "��\n");

        if (me->query_skill_mapped("sword") != "liuxing-jianfa")
                return notify_fail("��û�м������ǽ���������ʩչ" LIU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$n" HIY "�����ǰ�⻪��ʢ��$N" HIY "����" + weapon->name() + HIY
              "�����������������ǣ�ֻ��$n" HIY "��ȥ����һ˲��Ĺ�â���ٶȣ�û��һ�������赲��\n" NOR;
              

		ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");
                me->add("neili", -150);
                
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                           HIR "$n" HIR "��δ��Ӧ���ѱ�$N" HIR "���е�" + weapon->name() + 
                                           HIR "�������У���Ѫ�ɽ���\n" NOR);
                me->start_busy(2);
        } else
        {
                me->add("neili", -60);
                
                msg += CYN "����$p" CYN "�������ң�������������񵲿���$P"
                       CYN "�Ľ��С�\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

