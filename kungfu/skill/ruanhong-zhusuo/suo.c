// suolong.c ������

#include <ansi.h>
#include <combat.h>

string name() { return HIW "������" NOR; }
string query_name() { return "������"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (userp(me) && ! me->query("can_perform/ruanhong-zhusuo/suolong"))
		return notify_fail("�㻹����ʹ����һ�У�\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
              weapon->query("skill_type") != "whip" )
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" + name() + "��\n");

        if (me->query_skill("ruanhong-zhusuo", 1) < 150)
                return notify_fail("����������������죬�޷�ʩչ" + name() + "��\n");

        if( me->query("neili")<350 )
                return notify_fail("��������������޷�ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("��û�м�������������޷�ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʹ������������������" + weapon->name() +
              HIW "һ������ʱ�ó������Ӱ����������ͨ�죬һ��Ϯ��$n"
              HIW "��ȥ��\n\n" NOR;

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");
        attack_time = 4;
        if (ap / 2 + random(ap * 2) > dp)
        {
                msg += HIC "���$p" HIC "��$P" HIC
                       "���˸����ֲ�����Ŀ�Ӳ�Ͼ��ƣ�ڱ�����\n" NOR;
                count = ap / 12;
                me->add_temp("apply/attack", count);
                attack_time += random(ap / 45);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "���ƻֺ룬������Ȼ������Ӧ����\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        if (attack_time > 8)
                attack_time = 8;

        me->add("neili", -attack_time*20);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(3));
        return 1;
}
