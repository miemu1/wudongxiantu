#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "天雷"ZJBR"战气"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用天雷神功来提升自己的战斗力。\n");

        if( me->query("neili")<150 )
                return notify_fail("你的内力不够。\n");

        if( me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);
        message_combatd(YEL "$N" YEL "微一凝神，运起天雷神功，真气顿时灌满全身，整"
                        "个身体竟呈现出古铜色的光泽。\n" NOR, me);
        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/defense", skill/3);
		me->add_temp("apply/parry", skill / 3);
		me->add_temp("apply/dodge", skill / 3);
		me->add_temp("apply/unarmed_damage", skill);
        me->set_temp("powerup", 1);

        me->start_call_out((:call_other, __FILE__, "remove_effect", me,
                           skill / 3:), skill);
        if (me->is_fighting()) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        if( me->query_temp("powerup") )
        {
                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/defense", -amount);
				me->add_temp("apply/parry", -amount);
				me->add_temp("apply/dodge",-amount);
				me->add_temp("apply/unarmed_damage", -(amount*3));
                me->delete_temp("powerup");
                tell_object(me, "你的天雷神功运行完毕，将内力收回丹田。\n");
        }
}