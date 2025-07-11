#include <ansi.h>

string query_name() { return "满天"ZJBR"血影"; }
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !me->is_fighting() )
        return notify_fail("「"+HIR"满天血影"NOR+"」只能对战斗中的对手使用。\n");


    if( (int)me->query_skill("feixue-quan", 1) < 300 )
          return notify_fail("你的飞血拳不够熟练，不会使用「满天血影」。\n"); 

    if( (int)me->query_skill("huaxue-dafa", 1) < 300 )
          return notify_fail("你的化血大法不够熟练，不会使用「满天血影」。\n"); 

    if((int)me->query_skill("cuff",1) < 300)
                return notify_fail("你的基本拳法的修为不够, 不能使用这一绝技 !\n");

    if( (int)me->query("max_neili") < 12000 )
           return notify_fail("你的内力修为还不够高。\n");

    if( (int)me->query("neili") < 12000 )
           return notify_fail("你的内力不够了。\n");

    if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");     

      if ((int)me->query("neili")<5000)
        {
        return notify_fail(HIC"你现在内力不够，没能将「满天血影」使完！\n"NOR);
        }
      msg  = HIR"只见$N双目赤红，全身衣襟无动，口中长啸一声，\n"NOR;
      msg += HIR"$N把内力注入双臂，猛地一动，双臂血花爆射，\n"NOR;
      msg += HIR"顿时只见空气中血雾弥漫，双眼难开，随即又听见\n"NOR;
      msg += HIR"$N骨骼 噼里啪啦 一阵爆响，双臂顺着喷出的血舞，\n"NOR;
      msg += HIR"使劲一推，刹那间一座丈来高的血墙拔地而起，\n"NOR;
      msg += HIR"接而带着排山倒海之势向$n涌去！\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                me->start_busy(3);
                target->start_busy(random(3));
                damage = (int)me->query_skill("feixue-quan", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage*10);
                target->receive_wound("qi", damage*10);
                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage/1);
      msg += HIG"$n见状连忙提运内力，双臂猛地推出，顿时"+HIW"掌风"NOR+""+HIG"汹涌澎湃!\n"NOR;
      msg += HIG"没想到强大的气流竟然对"+HIR"血墙"NOR+""+HIG"丝毫没影响，\n"NOR;
      msg += HIG"刹那间$n就被"+HIR"血墙"NOR+""+HIG"吞没。\n"NOR;
                me->add("neili", -10000);
        } else
        {
                me->start_busy(4);
        msg += HIY"$n浑然不放在眼里，衣袖轻轻一拂，便将血墙熄灭。\n"NOR;
                me->add("neili", -2000);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        if(userp(target)) target->fight_ob(me);
        else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}

