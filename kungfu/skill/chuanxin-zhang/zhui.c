#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "����׶" NOR; }
string query_name() { return "����׶"; }
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("chuanxin-zhang", 1) < 100)
                return notify_fail("��Ĵ����Ʋ�����죬����ʹ��" + name() + "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("neili")<200 )
                return notify_fail("�����������������޷�ʹ��" + name() + "��\n");

        if (me->query_skill_mapped("strike") != "chuanxin-zhang")
                return notify_fail("��û�м��������ƣ��޷�ʹ��" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "\n$N" HIY "һ����Ц��˫��һ����Ȼʩ��һ��"
              "��" HIW "����׶" HIY "�����ó�ǧ��֮����һ��"
              "����$n" HIY "��" NOR;

        ap=me->query_skill("strike");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(2);
                damage = ap;
                me->add("neili", -150);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45,
                                          HIR "���$p" HIR "û�ܱܿ�$P" HIR
                                          "���Ī����Ʒ����ƾ���ʱ͸�ض�����"
                                          "������Ѫ������ˤ����\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -50);
                msg = CYN "����$p" CYN "ʶ����$P"
                      CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}