// made by lks
 
#include <ansi.h>

 string query_name() { return "���о�"; }

inherit F_SSERVER;
 
int exert(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, b,damage;

if( me->query("family/family_name") != "Ѫ����" ) 
            return notify_fail("�㲻���Ѫ���ɵ������ô�õĳ����ǵ��书��\n"); 

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("longmen-shengong",1);

        if( !me->is_fighting())
                return notify_fail("�����о���ֻ����ս�������ڶ������ϡ�\n");
 
        if( skill < 80)
                return notify_fail("��������񹦲�������, ����ʹ�á����о�����\n");

        if( me->query("neili") < 300 )
                return notify_fail("��������������޷����á����о�����\n");
 
        
        msg = HIY "$NĬ���ᵤ�˫��������Ƴ�һ�ɴ������е�����������$n��\n";
        ap = (me->query_skill("force") + skill)/2;
        dp = target->query_skill("force") / 2 + target->query_skill("lonely-sword") / 10;
        if( random(ap) > dp / 2)
        {
                if(userp(me))
                        me->add("neili",-200);
                  msg += "$nֻ��������������������е������䣬ȫ�����Լ���\n" NOR;
               b = skill / 30 + 1;
               damage = (int)me->query_skill("force", 1);
                damage += (int)me->query_skill("longmen-shengong", 1);                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -200);
                target->start_busy(b);
                me->start_busy(1);
        }
        else
        {
                if(userp(me))
                        me->add("neili",-100);
                 msg += "����$n���Ա߲���һ��,���������еĹ�����Χ��\n"NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

