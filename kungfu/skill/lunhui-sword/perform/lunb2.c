#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "�ֻؽ�" NOR; } 
string query_name() { return "�ֻؽ�"; }
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

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if ((int)me->query_skill("lunhui-sword", 1) < 250)
                return notify_fail("��������ɾ�������죬����ʩչ" + name() + "��\n");

        if( me->query("neili")<2000 )
                return notify_fail("�����������������ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("sword") != "lunhui-sword")
                return notify_fail("��û�м��������ɾ�������ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "��������" + weapon->name() + HIG "����������䣬�����������䣬�����ɾ������� ����\n" NOR;

        ap = me->query_skill("sword"); 
        dp = target->query_skill("dodge"); 

        attack_time = 6;
        count = ap / 10;
        
        if (me->query_skill("lunhui-sword", 1) >= 800)
                count *= 2;

        if (me->query_skill("lunhui-sword", 1) >= 1600)
                count *= 2;
                
        me->add_temp("apply/attack", count/2);
        me->add_temp("apply/damage", count/2);
        
        message_combatd(msg, me, target);

        me->add("neili", -3000);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (! target->is_busy()) target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count/2);
        me->add_temp("apply/damage", -count/2);
        
        me->start_busy(3 + random(2));

        return 1;
}
