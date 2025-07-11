
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "禁术"ZJBR"附体"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
        int skill = me->query_skill("force") /3*100 ;

        if (target != me)
                return notify_fail("你只能用暗夜葬经来提升自己的防御力。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够。\n");

        if (skill < 40)
                return notify_fail("你的暗夜葬经等级不够。\n");

        if ((int)me->query_temp("shou"))
                return notify_fail("你已经在运功中了。\n");

        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_vision(HIY "$N" HIY "默运暗夜葬经，顿觉体表多出了一层霸道的护体刚劲。"NOR"\n", me);

        if (me->query("breakup"))
        {
			me->add_temp("apply/dodge", skill);
			me->add_temp("apply/parry", skill);
            me->add_temp("apply/armor", skill);
        }
        else
        {
			me->add_temp("apply/dodge", skill / 2*100*100);
			me->add_temp("apply/parry", skill / 2*100*100);
            me->add_temp("apply/armor", skill / 2*100*100);
        }
        me->set_temp("shou", 1);
        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shou"))
        {
                if (me->query("breakup")) {
                    me->add_temp("apply/armor", -amount);
					me->add_temp("apply/dodge", -amount);
					me->add_temp("apply/parry", -amount);
                }
                else {               
                    me->add_temp("apply/armor", -amount / 2*100*100);
					me->add_temp("apply/dodge", -amount / 2*100*100);
					me->add_temp("apply/parry", -amount / 2*100*100);
                }
		    me->delete_temp("shou");
                tell_object(me, "你的暗夜葬经运行完毕，将内力收回丹田。\n");
        }
       
}
