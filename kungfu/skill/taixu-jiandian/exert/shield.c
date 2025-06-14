// shield.c 九阳护体神功

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "太虚"ZJBR"剑体"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用太虚剑气来提升自己的防御力。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的真气不够。\n");

        if ((int)me->query_skill("taixu-jiandian", 1) < 40)
                return notify_fail("你的太虚剑气等级不够。\n");

        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIC "$N" HIC "回想太虚剑气：神者，"
                            "变化之极也。无剑亦有剑，凭神化"
                            "剑，剑气自成，乃通神蕴\n只是瞬间$N" 
                        HIC "全身浮现了一道道剑意，将$P"
                        HIC "牢牢护住。\n" NOR, me);

        me->add_temp("apply/armor", skill);
        me->set_temp("shield", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill:), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shield"))
        {
                me->add_temp("apply/armor", -amount);
                me->delete_temp("shield");
                tell_object(me, "你的太虚剑气运行完毕，将内力收回丹田。\n");
        }
}

