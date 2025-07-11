#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "普渡"ZJBR"众生"; }

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("普渡众生只能对战斗中的对手使用。\n");

        if((int)me->query("neili") < 500)
                return notify_fail("你的真气不够！\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 100)
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("lianyu-mojing", 1) < 300)
                return notify_fail("你的炼狱魔经等级不够，无法使用『普渡众生』！\n");
 
           weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N飞身跃起，使出炼狱魔经终极绝技「普渡众生」!n"NOR, me);
           message_vision(HIB"\n突然只见$N使出炼狱魔经终极绝技『普渡众生』！\n"NOR, me);
           me->delete("env/brief_message");
   target->delete("env/brief_message");
message_vision(HIC"\n$N飞身跃起，使出炼狱魔经终极绝技『普渡众生』!\n"NOR,me,target);
message_vision(HBMAG"$N举拳长啸：“普！！”\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 2); 
message_vision(HBMAG"$N举拳长啸：“渡！！”\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 3);
message_vision(HBMAG"$N举拳长啸：“众！！”！\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 4);
message_vision(HBMAG"$N举拳长啸：“生！！”！\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 5);
message_vision(HIW"\n$N乘招势未收,劲吐内力，狂风暴雨般的拳罡向$n卷去！\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 6);
message_vision(HBMAG"$N旧力未消,新力又生.拳罡忽左忽右,飘摇四起”！\n"NOR,me,target);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 9);
message_vision(HIC"\n$N无法控制内息流动，只好后跃收招。\n"NOR, me, weapon);


           me->add("neili", -500);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(1);
   return 1;
}


