// made by lks
 
#include <ansi.h>

 string query_name() { return "Ѫ��"; }

inherit F_SSERVER;
 
int exert(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp,damage;


        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("huaxue-dafa",1);

        if( !me->is_fighting())
                return notify_fail("��Ѫ��ֻ����ս�������ڶ������ϡ�\n");
 
        if( skill < 80)
                return notify_fail("��Ļ�Ѫ�󷨲�������, ����ʹ�á�Ѫ����\n");

        if( me->query("neili") < 300 )
                return notify_fail("��������������޷����á�Ѫ����\n");
 
                
        msg = HIC "$N���ᵤ�ҧ����⣬�³�һ��Ѫ������$n��\n"NOR;

        ap = (me->query_skill("force") + skill)/2;
        dp = target->query_skill("force") / 2 + target->query_skill("lonely-sword") / 10;
        if( random(ap) > dp / 2)
        {
                if(userp(me))
            me->add("neili",-200);
		me->start_call_out((: call_other, __FILE__, "remove_effect",
				   me, skill :), skill);
		me->receive_damage("qi", me->query("max_qi") / 2000);

		           me->receive_damage("qi", me->query("max_qi") / 20);
                  msg += WHT"$nһ����������Ѫ��������ȫ��ֻ����$n��Ѫ���вҽ�����!\n"NOR;

                damage = (int)me->query_skill("force", 1);
                damage += (int)me->query_skill("huaxue-dafa", 1);                
                target->receive_damage("qi", damage * 3);
                target->receive_wound("qi", damage);
                me->start_busy(2);
        }
        else
        {
                if(userp(me))
                 me->add("neili",-100);
                 msg += YEL"����$p���Ա߲���һ��,�����Ѫ��\n"NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

