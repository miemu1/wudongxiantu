#include <ansi.h>

inherit F_SSERVER;

string name() { return "����ɲ��"; }
string query_name() { return "���"ZJBR"��ɲ��"; }
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("������ɲ�ơ�ֻ����ս���жԶ���ʹ�á�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("������ɲ�ơ�ֻ�ܿ���ʹ�á�\n");
			if(me->query("family/family_name")!="�����")
                return notify_fail("���Ǿ���ȵĲ�����ʹ�ã�\n");

        if( me->query("max_neili")<2200 )
                return notify_fail("���������Ϊ���������޷�ʩչ������ɲ�ơ���\n");

        if( me->query("neili")<500 )
                return notify_fail("�������������\n");

        if ((int)me->query_skill("tie-zhang", 1) < 200)
                return notify_fail("������ƻ�򲻹����޷�ʹ�á�����ɲ�ơ���\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á�����ɲ�ơ���\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ������ɲ�ơ���\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("������û��׼��ʹ�������Ʒ�������ʩչ������ɲ�ơ���\n");

        if (me->query_skill_prepared("cuff") == "tiexian-quan"
            || me->query_skill_prepared("unarmed") == "tiexian-quan" )
                return notify_fail("ʩչ������ɲ�ơ�ʱ�����Ʒ����˺�����ȭ������\n");

        
        if ((string)me->query_skill_mapped("force") != "tianlei-shengong")
                return notify_fail("����뼤�������񹦲���ʩչ��������ɲ�ơ���\n");
       

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ��ŭ�ȣ���Ȼʩ�������Ʒ�������" NOR + WHT
              "����ɲ��" NOR + HIR "����������������������ת��˫�۶�"
              "Ȼ\n�������ߡ�ֻ���ƿ�֮�����죬˫�ƻó�������Ӱ������"
              "�ǵ���$n" HIR "�����ĳ���\n\n" NOR;

        ap=me->query_skill("strike")+me->query_str()*20;
        dp=target->query_skill("parry")+target->query_dex()*20;
        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 3;
                msg += RED "$n" RED "���$P" RED "����ɽ�������ƣ���ȫ"
                       "�޷��ֵ���Ψ���˺�\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "����Ӧս���߾����ܻ���$P" HIC "��"
                       "���ơ�\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/unarmed_damage", count*2);

        me->add("neili", -300);
        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(3));
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/unarmed_damage", -(count*2));

        return 1;
}