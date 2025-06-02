#include <ansi.h>
#include <combat.h>

string name() { return HIY "������" NOR; }
string query_name() { return "������"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, wn;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ����ս���жԶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "staff" )
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if ((int)me->query_skill("feilong-zhang", 1) < 160)
                return notify_fail("������ȷ�������죬����ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("staff") != "feilong-zhang")
                return notify_fail("��û�м��������ȷ�������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force") < 240)
                return notify_fail("����ڹ���򲻹�������ʩչ" + name() + "��\n");

        if( me->query("max_neili")<2500 )
                return notify_fail("���������Ϊ����������ʩչ" + name() + "��\n");

        if(me->query("neili")<500 )
                return notify_fail("�����ڵ��������㣬����ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIW "$N" HIW "��Ŀ��ȣ���ȫ���������ұۣ�����" + wn +
              HIW "��ʱ�����������$n" HIW "��ȥ��\n" NOR;

        ap = me->query_skill("staff");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                           HIR "$n" HIR "ֻ��һ�ɾ���Ϯ��������"
                                           "�������Ǹ�" + wn + HIR "���û����ؿ�"
                                           "��ײ�������߹ǡ�\n" NOR);
                me->start_busy(2);
                me->add("neili", -300);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "������磬����Ӳ"
                       "�ӣ��������������ߣ�����������\n" NOR;
                me->start_busy(3);
                me->add("neili", -200);
        }

        msg += HIY "ֻ���Ǹ�" + wn + HIY "���Ʋ���������ǰ�ɳ���"
               "�ɣ�����û�����С�\n" NOR;
        weapon->move(environment(me));

        message_combatd(msg, me, target);
        return 1;
}
