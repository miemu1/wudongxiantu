#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define LONG "��" HIY "��������ն" NOR "��"
string query_name() { return "����"ZJBR"����ն"; }
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LONG "ֻ����ս���жԶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԣ�\n");

        if ((int)me->query_skill("xiuluo-daojing", 1) < 200)
                return notify_fail("�����޵���������죬�޷�ʩչ" LONG "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("���ڹ���򲻹����޷�ʩչ" LONG "��\n");

        if( me->query("neili")<1000 )
                return notify_fail("�����������������޷�ʩչ" LONG "��\n");

        if( me->query("qi")<3000 )
                return notify_fail("�����Ѫ�������޷�ʩչ" LONG "��\n");

        if (me->query_skill_mapped("blade") != "xiuluo-daojing")
                return notify_fail("��û�м������޵������޷�ʩչ" LONG "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "\n$N" HIC "��¶��ɫ������һ�������϶��£�ɲ�Ǽ䣬��ؿ޺�����ǧ����������ǧ��������"
              "�޿��Ӳ죬����ǵص���ǰ�������Ȼ������������Ϊһ����â���������������$n" HIC "��\n" NOR;

        ap=me->query_skill("blade")*1/3+me->query_skill("martial-cognize",1)*1/2;
        dp=target->query_skill("blade")*1/3+target->query_skill("martial-cognize",1)*1/2;
        if (ap * 5 / 3 + random(ap) > dp)
        {
                me->start_busy(3);
                damage = ap * 1/2 + random(ap * 1/2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 1000 + random(500),
                                           HIR "�����������ޱȵĵ������������Ĵ�$n" HIR "�ؿ�͸�����������ë���Ȼ��\n" NOR);
                me->add("qi", -3000);
				me->add("neili", -1000);
        } else
        {
                me->start_busy(3);
                msg += CYN "Ȼ��$n" CYN "����һЦ������������������л��⡣\n" NOR;
                me->add("qi", -10000);
				me->add("neili", -10000);
        }

        message_combatd(sort_msg(msg), me, target);

        return 1;
}
