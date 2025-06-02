#include <ansi.h>
#include <combat.h>

#define LUO "��" HIW "Ⱥ������" NOR "��"
string query_name() { return "Ⱥ������"; }
string name() { return HIR "Ⱥ������" NOR; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;

        me = this_player();

       /*  if( userp(me) && !me->query("can_perform/wuyin-jianjing/luo") )
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n"); */

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LUO "ֻ����ս���жԶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LUO "��\n");

        if ((int)me->query_skill("wuyin-jianjing", 1) < 200)
                return notify_fail("�����󽣾�������죬����ʩչ" LUO "��\n");

        if (me->query_skill_mapped("sword") != "wuyin-jianjing")
                return notify_fail("��û�м������󽣾�������ʩչ" LUO "��\n");

        if ((int)me->query_skill("force") < 600)
                return notify_fail("����ڹ���򲻹�������ʩչ" LUO "��\n");

        if( me->query("neili")<2000 )
                return notify_fail("�����ڵ���������������ʩչ" LUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIW "\n$N" HIW "��" + wn + HIW "бָ���գ��͵ط���Ծ��"
              + wn + HIW "����һ������������������һ���������ն��£�һ��"
              "��" HIG "Ⱥ������" HIW "����ʹ������ǧ�����ɵ�֮��Ϯ��$n" HIW
              "��" NOR;

        message_sort(msg, me, target);

        ap = me->query_skill("sword")*8;
        dp = target->query_skill("sword");

        if (ap * 7 / 2 + random(ap) > dp)
        {
                damage = ap + random(ap * 9 / 2);
                 msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 350,
                                          HIR "$n" HIR "ֻ��һ�����Ӱ��Ϯ����"
                                          "���о������ѣ�����Ѫ�Ѵ�$n�ؿ������\n"
                                          NOR);
                 me->start_busy(2 + random(4));
                 me->add("neili", -2000);
        } else
        {
                 msg = CYN "Ȼ��$n" CYN "�����ֿ죬����һ��"
                      "���$N" CYN "��һ����\n" NOR;

                 me->start_busy(2);
				 me->add("qi", -10000);
                 me->add("neili", -10000);
        }
        message_combatd(msg, me, target);

        return 1;
}

