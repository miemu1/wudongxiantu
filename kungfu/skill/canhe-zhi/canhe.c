// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

string name() { return HIW "�κϽ���" NOR; }
string query_name() { return "�κ�"ZJBR"����"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp, slv, clv,p;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ��" + name() + "��\n");

        if (clv = (int)me->query_skill("canhe-zhi", 1) < 180)
                return notify_fail("��Ĳκ�ָ��Ϊ���ޣ�����ʩչ" + name() + "��\n");

        if (me->query_skill_prepared("finger") != "canhe-zhi")
                return notify_fail("������û��׼��ʹ�òκ�ָ������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���Ϊ̫�����ʩչ" + name() + "��\n");

        if( me->query("max_neili")<3000 )
                return notify_fail("���������Ϊ���㣬����ʩչ" + name() + "��\n");

        if( me->query("neili")<900 )
                return notify_fail("�����������������ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        damage = me->query_skill("finger");
        slv = target->query_skill("six-finger", 1);

        ap = me->query_skill("finger");
        dp = target->query_skill("dodge");
		damage =damage+random(ap)*2;
        msg = HIW "ֻ��$N" HIW "ʮָ��̯����ʱ�ƿ������죬���ɽ�����ָ�⼤"
              "���������$n" HIW "��ֱ��ȥ��\n" NOR;

        if (slv >= 140
            && random(5) == 0
            && slv >= clv - 60 // ����κ�ָ�ȼ��������񽣵ȼ���60������ȡ������Ч��
            &&! target->is_busy()
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n����$n" HIY "ббһָ�����ָ����磬�����ݺᣬ��Ȼ"
                       "���죬����$N" HIY "�Ľ���ȫ���ۻأ������Լ���ȥ��\n" NOR +
                       HIR "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

                me->receive_wound("qi", slv / 3 + random(slv / 4), target);
                p=me->query("qi")*100/me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";

        } else
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 150,
                                           HIR "\n��ʱֻ������������һ����$n" HIR
                                           "����������������ʱ���ض���������һ��"
                                           "Ѫ�ꡣ\n" NOR);
        } else
        {
                msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ��"
                       "�𣬱ܿ�����һ����\n" NOR;
        }

        ap = me->query_skill("finger");
        dp = target->query_skill("force");

        if (slv >= 160
            && random(8) == 0
            && slv >= clv - 60  // ����κ�ָ�ȼ��������񽣵ȼ���60������ȡ������Ч��
            &&! target->is_busy()
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n����$n" HIY "����Сָһ�죬һ�С����󽣡���ָ��͸��"
                       "�������ĵ�������Ѹ�٣��ٽ�$N" HIY "�����ƻأ�\n" NOR + HIR
                       "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

                me->receive_wound("qi", slv / 2 + random(slv / 4), target);
                p=me->query("qi")*100/me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";

        } else
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 155,
                                           HIR "\nֻ��$n" HIR "һ���Һ�����$N" HIR
                                           "�Ľ���������Ҫ����Ѫ��ģ������Ѫ������"
                                           "ֹ��\n" NOR);
        } else
        {
                msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ��"
                       "�𣬱ܿ�����һ����\n" NOR;
        }

        ap = me->query_skill("finger");
        dp = target->query_skill("parry");

        if (slv >= 180
            && random(10) == 0
            && slv >= clv - 50  // ����κ�ָ�ȼ��������񽣵ȼ���50������ȡ������Ч��
            &&! target->is_busy()
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n�ɵ���ʯ֮�䣬$n" HIY "��Ȼ���ƣ����ֶ�Ȼ̽������"
                       "ָ���г彣����$N" HIY "һ�����ǽ��κϽ����������Σ�\n" NOR
                       + HIR "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

                me->receive_wound("qi", slv / 2 + random(slv / 2), target);
                p=me->query("qi")*100/me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";
                me->start_busy(6);

        } else
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 160,
                                           HIR "\n$n" HIR "�����мܣ����ǲ��У�$N"
                                           "��" HIR "���ν�����͸����룬��Ѫ����"
                                           "��������ս��\n" NOR);
        } else
        {
                msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ��"
                       "�𣬱ܿ�����һ����\n" NOR;
        }
        me->start_busy(3+random(2));
        me->add("neili", -400-random(100));
        message_combatd(msg, me, target);
        return 1;
}