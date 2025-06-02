#include <ansi.h>
#include <combat.h>

string name() { return HIR "����ȭ" NOR; }
string query_name() { return "����ȭ"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;        
        int level, b;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((level = (int)me->query_skill("tiandaoquan", 1)) < 100)
                return notify_fail("�����ȭ����򲻹�������ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("unarmed") != "tiandaoquan")
                return notify_fail("��û�м������ȭ��������ʩչ" + name() + "��\n");

        if (me->query_skill_prepared("unarmed") != "tiandaoquan")
                return notify_fail("��û��׼�����ȭ��������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("max_neili")<100 )
                return notify_fail("���������Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("neili")<100 )
                return notify_fail("�����ڵ��������㣬����ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "˫ȭ����ʩ�����ȭ������" HIR "����ȭ" NOR +
              WHT "�����������Ӱ������$n" WHT "�ķ���\n" NOR;

        me->add("neili", -100);
        if (level + random(level)  > (int)target->query_skill("parry", 1))
        {
                msg += HIR "��Ӱ�ζ���$n" HIR "��ʽ��Ȼһ��������$N"
                       HIR "��ȭ��ǣ������æ���ң�\n" NOR;
                b = level / 20;
                target->start_busy(b);
                me->start_busy(1);
        } else

        {
                msg += CYN "����$n" CYN "������$N"
                       CYN "����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}