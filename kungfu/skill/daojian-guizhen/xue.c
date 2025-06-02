// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIW "������" HIR "Ѫ" NOR; }
string query_name() { return "����"ZJBR"��Ѫ"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string type1, type2, msg;
        object weapon1, weapon2;
        int i, count, damage;
        int ap, dp;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon1 = me->query_temp("weapon");
        weapon2 = me->query_temp("secondary_weapon") || me->query_temp("handing");

        type1 = weapon1->query("skill_type");
        type2 = weapon2->query("skill_type");

        if ((type1 != "sword" && type1 != "blade")
           || (type2 != "sword" && type2 != "blade"))
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if ((type1 == "sword" && type2 != "blade")
           || (type1 == "blade" && type2 != "sword"))
                return notify_fail("��û��ͬʱװ������������ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("sword") != "daojian-guizhen"
           || me->query_skill_mapped("blade") != "daojian-guizhen")
                return notify_fail("��û�м����������棬����ʩչ" + name() + "��\n");

        if (me->query_skill("daojian-guizhen", 1) < 250)
                return notify_fail("��Ľ�����ȼ�����������ʩչ" + name() + "��\n");

        if( me->query("neili")<500 )
                return notify_fail("�����ڵ���������������ʩչ" + name() + "��\n");
			if( me->query_skill("lengyue-shengong")<500 )
                return notify_fail("�����ڵ��ڹ�����������ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����" + weapon1->name() + HIW "���һ��"
              "������" NOR + WHT "���ҵ���" HIW "������" NOR + WHT
              "��ҽ���" HIW "������ʩ������ʱ��\n���㣬����ҹ��"
              "���գ�����ǵ�����$n" HIW "������һ�С�" HIW "����"
              "��" HIR "Ѫ" HIW "����\n" NOR;

        ap = me->query_skill("blade", 1) ;
        dp = target->query_skill("parry", 1);

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIW "$n" HIW "ֻ���������⽣Ӱ���Լ���"
                       "�����ٸ��ۻ����ң��ĵ׺�����Ȼ������\n" NOR;
                count = ap / 15;
                me->set_temp("daojian-guizhen/max_pfm", 1);
        } else
        {
                msg += HIG "$n" HIG "ͻȻ�����Լ����ܽԱ�����"
                       "��Ӱ����Χ����֪�����æС���мܡ�\n" NOR;
                count = ap / 30;
        }
        message_combatd(msg, me, target);

        me->add("neili", -300);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count*2/3);

        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, (random(2) ? weapon1:weapon2), 100);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count*2/3);
        me->delete_temp("daojian-guizhen/max_pfm");
        me->start_busy(2 + random(2));
        return 1;
}
