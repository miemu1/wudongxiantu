#include <ansi.h>
#include <combat.h>

string name() { return HIB "��������" NOR; }
string query_name() { return "����"ZJBR"����"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage,ran, ndam;
        string sexs;

        if (! target) target = offensive_target(me);
        
        if (! target || ! me->is_fighting(target))
                return notify_fail(name()+ "ֻ����ս���жԶ���ʹ�á�\n");
        
        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");
        
        if (me->query_skill("wushang-jianjingsAA", 1) < 600)
                return notify_fail("������Ͻ�����Ϊ����������ʩչ" +name()+ "��\n");
        
        if (me->query_skill_mapped("sword") != "wushang-jianjingsAA")
                return notify_fail("��û�м������Ͻ���������ʩչ" +name()+ "��\n");
        
        if (me->query_skill_mapped("sword") != "wushang-jianjingsAA")
                return notify_fail("��û�м������Ͻ���������ʩչ" +name()+ "��\n");
        
        if( me->query("neili")<2000 )
                return notify_fail("�����������������ʩչ" +name()+ "��\n");
        
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
        
        msg = HIC "$N" HIC "��Хһ��������" + weapon->name() + HIC "ƽƽһ���̳����ٶ�֮�죬�����������һ�㣡\n" NOR;
        
        ap=me->query_skill("sword")+me->query("force")+me->query_skill("martial-cognize",1);
        dp=target->query_skill("parry")+target->query("force")+target->query_skill("martial-cognize",1);
        
        if (1)
        {
                damage = ap / 4 + random(ap / 3);
                //damage += weapon->apply_damage(); // ׷��һ���������˺�
                me->add("neili", -1000);
                me->start_busy(3);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "ֻ��$n" HIR "һ���ҽУ�$N" HIR +
                                           weapon->name() + HIR "����֮����һ����ɫ�����"
                                           "��$p" HIR "���ڡ�\n"
                                           NOR);
                
                // ׷��һ�������˺�
                ran = 35;
                ndam = 10;
                if (me->query_skill("wushang-jianjingsAA", 1) >= 5000)
                {
                        ran = 100;
                        ndam = 5;
                }
                else if (me->query_skill("wushang-jianjingsAA", 1) >= 4000)
                {
                        ndam = 7;
                }
                else if (me->query_skill("wushang-jianjingsAA", 1) >= 3000)
                {
                        ran = 50;
                }
                else if (me->query_skill("wushang-jianjingsAA", 1) >= 2000)
                {
                        ran = 50;
                }
                // ׷��һ�������˺�
                if (random(100) < ran || wizardp(me))
                {
                        msg = msg + HIG + weapon->name() + HIG "�����������������������һ�������ٴδ�͸" +
                              target->name() + HIG "���塭��\n" NOR +
                              HIR "һ����Ѫ˳��" + weapon->name() + HIR "���������\n" NOR;
                        target->receive_damage("qi", weapon->apply_damage() / 2, me);
                        target->receive_wound("qi", weapon->apply_damage() / 2, me);
                }
        
                if( !target->query_temp("wushang-jianjingsAA/jinglei") )
                {
                        // ��һ��ֱ��10%�����Ѫ�˺�
                        target->receive_damage("qi",target->query("max_qi")/ndam,me);
                        target->receive_wound("qi",target->query("max_qi")/ndam,me);
                        msg = msg + target->name() +  HIM "�ƺ�һ������Ѫ������������ܵ�����һ���Ľ������ˡ�\n" NOR;
                        target->set_temp("wushang-jianjingsAA/jinglei", 1);
                }
        } else
        {
                me->add("neili", -5000);
                me->start_busy(4);
                msg += CYN "$n" CYN "��$P" CYN "������ӿ���������׵�"
                       "������æ������Ų������������\n" NOR;
        }
        message_combatd(sort_msg(msg), me, target);
        
        return 1;
}

