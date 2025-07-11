// powerup.c 

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "蚩尤"ZJBR"战意"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用蚩尤狂战决来提升自己的战斗力。\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);
        
        message_combatd(HIY "$N" HIY "深吸一口气，待到呼出之时，双目已经射出赤红的光芒，周围的空气中弥漫着阵阵的战意！\n" NOR, me);
        me->add_temp("apply/attack", skill / 5);
        me->add_temp("apply/defense", skill / 5);
        me->set_temp("powerup", 1);

        me->start_call_out((:call_other, __FILE__, "remove_effect", me,
                           skill / 2:), skill);
        if (me->is_fighting()) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/defense", -amount);
                me->delete_temp("powerup");
                tell_object(me, "你的蚩尤狂战决运行完毕，将内力收回丹田。\n");
        }
}


