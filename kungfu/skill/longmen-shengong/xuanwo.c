// made by lks
 
#include <ansi.h>

 string query_name() { return "旋涡劲"; }

inherit F_SSERVER;
 
int exert(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, b,damage;

if( me->query("family/family_name") != "血河派" ) 
            return notify_fail("你不理解血河派的信念，怎么用的出他们的武功。\n"); 

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("longmen-shengong",1);

        if( !me->is_fighting())
                return notify_fail("「旋涡劲」只能在战斗中用在对手身上。\n");
 
        if( skill < 80)
                return notify_fail("你的龙门神功不够纯熟, 不能使用「旋涡劲」！\n");

        if( me->query("neili") < 300 )
                return notify_fail("你的内力不够，无法运用「旋涡劲」！\n");
 
        
        msg = HIY "$N默气贯丹田，双掌齐出，推出一股带着旋涡的气流。罩向$n。\n";
        ap = (me->query_skill("force") + skill)/2;
        dp = target->query_skill("force") / 2 + target->query_skill("lonely-sword") / 10;
        if( random(ap) > dp / 2)
        {
                if(userp(me))
                        me->add("neili",-200);
                  msg += "$n只觉人如舟子在掀天巨浪中颠簸起落，全不能自己！\n" NOR;
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
                 msg += "可是$n向旁边侧身一闪,跳出了旋涡的攻击范围。\n"NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

