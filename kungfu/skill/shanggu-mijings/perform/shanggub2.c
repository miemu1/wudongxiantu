#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "[古秘术]"ZJBR"天地葬礼"; }

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『[古秘术]天地葬礼』只能对战斗中的对手使用。\n");

        if((int)me->query("neili") < 1000)
                return notify_fail("你的真气不够！\n");

        if((int)me->query("qi") < 1000)
                return notify_fail("你的真气不够！\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 100)
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("shanggu-mijings", 1) < 300)
                return notify_fail("你的上古秘经等级不够，无法使用『[古秘术]天地葬礼』！\n");
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N飞身跃起，使出上古秘经终极绝技「[古秘术]天地葬礼」!n"NOR, me);
           message_vision(HIB"\n突然只见$N使出上古秘经终极绝技『[古秘术]天地葬礼』！\n"NOR, me);
                      me->delete("env/brief_message");
   target->delete("env/brief_message");
message_vision(HIC"\n$N飞身跃起，使出上古秘经终极绝技『[古秘术]天地葬礼』!\n"NOR,me,target);
message_vision(HBMAG"$N举拳长啸：“无！！”\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HBMAG"$N举拳长啸：“双！！”\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N举拳长啸：“一！！”！\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N举拳长啸：“击！！”！\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n$N乘招势未收,劲吐内力，狂风暴雨般的拳罡向$n卷去！\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N旧力未消,新力又生.拳罡忽左忽右,飘摇四起”！\n"NOR,me,target);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"\n$N无法控制内息流动，只好后跃收招。\n"NOR, me, weapon);
           me->add("neili", -1000);
		   me->add("qi", -1000);
		   me->add("jing", -1000);
          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
   me->start_busy(3);
   return 1;
}


