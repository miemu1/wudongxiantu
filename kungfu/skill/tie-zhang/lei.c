#include <ansi.h>
#include <combat.h>

string name() { return HIR "������" NOR; }
string query_name() { return "������"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "ֻ�ܿ���ʩչ��\n");
			
			if(me->query("family/family_name")!="�����")
                return notify_fail("���Ǿ���ȵĲ�����ʹ�ã�\n");

        if ((int)me->query_skill("tie-zhang", 1) < 160)
                return notify_fail("�������Ʒ���򲻹�������ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" + name() + "��\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force") < 240)
                return notify_fail("����ڹ���Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("max_neili")<2500 )
                return notify_fail("���������Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("neili")<300 )
                return notify_fail("�����ڵ��������㣬����ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "��ת����ʩ����" HIR "������" NOR +
              WHT "��������˫�Ʒ��죬������գ���$n" WHT "��"
              "Ȼ�ĳ���\n" NOR;

        ap=me->query_skill("strike")+me->query_str()*10;
        dp=target->query_skill("parry")+target->query_con()*10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap;
                damage+= me->query("jiali");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 85,
                                           HIR "���ֻ��$n" HIR "һ���ƺߣ���$N"
                                           HIR "һ���������ţ�������Ѫ���������"
                                           "\n" NOR);
                me->add("neili", -250);
                me->start_busy(2);
        } else
        {
                msg += CYN "$n" CYN "�ۼ�$N" CYN "������ӿ��˿��"
                       "����С���æ������һ�ԡ�\n" NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}