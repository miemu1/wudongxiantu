#include <ansi.h>
#include <combat.h>

string name() { return HIR "����ĥ" NOR; }
string query_name() { return "����ĥ"; }
inherit F_SSERVER;

string finala(object me, object target, int damage);
string finalb(object me, object target, int damage);

int perform(object me, object target)
{
        string msg;
        int ap, dp, dd;
        int damage;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "ֻ�ܿ���ʩչ��\n");
			
			if(me->query("family/family_name")!="�����")
                return notify_fail("���Ǿ���ȵĲ�����ʹ�ã�\n");

        if ((int)me->query_skill("tie-zhang", 1) < 220)
                return notify_fail("�������Ʒ���򲻹�������ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" + name() + "��\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("max_neili")<3500 )
                return notify_fail("���������Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("neili")<500 )
                return notify_fail("�����ڵ��������㣬����ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʩ�����ƾ�����" HIR "����ĥ"
              HIW "�������Ʋ��Ű��������Я����������$n"
              HIW "��ȥ��\n" NOR;

        ap=me->query_skill("strike")+me->query_str()*15;
        dp=target->query_skill("parry")+target->query_con()*15;
        dd=target->query_skill("dodge")+target->query_dex()*15;

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 75,
                                           (: finala, me, target :));
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "�Ƴ���磬��֪"
                       "���к��ż�������������б��������\n" NOR;
        }

        msg += HIR "\n������$N" HIR "����һ���Ʒ��������ϯ"
               "����һ�����ˣ���$n" HIR "��ǰ��Ȼ���䡣\n" NOR;

        if (ap / 2 + random(ap) > dd)
        {
                damage = me->query_skill("strike");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80,
                                           (: finalb, me, target :));
        } else
        {
                msg += CYN "$n" CYN "���ź�Х���������ۼ�$N" CYN
                       "������磬��æ��Ծ��ܿ�����\n" NOR;
        }
        me->start_busy(2 + random(2));
        me->add("neili", -400);
        message_combatd(msg, me, target);
        return 1;
}

string finala(object me, object target, int damage)
{
        int lvl;
        lvl = me->query_skill("strike");

        target->affect_by("tiezhang_yin",
                       (["level":me->query("jiali")+random(me->query("jiali")/2),
                          "id":me->query("id"),
                          "duration" : lvl / 50 + random(lvl / 50) ]));

        return HIW "���Ǽ�$n" HIW "�ѱ�$N" HIW "�����ƾ�����Ҫ"
               "�������ɵû���һ��������֮����\n" NOR;
}

string finalb(object me, object target, int damage)
{
        int lvl;
        lvl = me->query_skill("strike");

        target->affect_by("tiezhang_yang",
                       (["level":me->query("jiali")+random(me->query("jiali")/2),
                          "id":me->query("id"),
                          "duration" : lvl / 50 + random(lvl / 50) ]));

        return HIR "ֻ���͵�һ����$N" HIR "��������ܸ����"
               "$n" HIR "�ؿڣ�����������߹ǡ�\n" NOR;
}