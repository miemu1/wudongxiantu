// shield.c 紫徽心法之护体神功
//

#include <ansi.h>
string query_name() { return "护体"ZJBR"真气"; }
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if (target != me)
                return notify_fail("你只能用紫徽心法来提升自己的防御力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("zihui-xinfa",1) < 50)
                return notify_fail("你的紫徽心法修为不够。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

        message_combatd(HIW "$N" HIW "手指扣成北斗七星图形，运起紫徽心法，"
                        "顿时全身紫蕴朦胧，衣袖飘扬！\n" NOR, me);

        me->add_temp("apply/armor", skill/2);
	me->set_temp("shield", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shield"))
        {
        	me->add_temp("apply/armor", -(amount/2));
        	me->delete_temp("shield");
                tell_object(me, "你的紫徽心法运行完"
                            "毕，将内力收回丹田。\n");
        }
}
