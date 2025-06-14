#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount, int amount1);

string query_name() { return "天人"ZJBR"化生"; }

int perform(object me, object target)
{
	object weapon;  
	string msg;
	int count, skill;

	if ((int)me->query_temp("ling_long"))
		return notify_fail("你已经运起「天人化生」了。\n");

	if ((int)me->query_skill("tianrenheyi", 1) < 600)
		return notify_fail("你的归真道经还不够娴熟，难以施展此项绝技！\n");

	if ((int)me->query_dex() < 40)
		return notify_fail("你的身法不够使用「天人化生」绝技！\n");

	if ((int)me->query_skill("force", 1) < 600)
		return notify_fail("你的内功火候不够，难以施展此项绝技！\n");

	if ((int)me->query_skill("dodge", 1) < 600)
		return notify_fail("你的轻功修为不够，不会使用此项绝技！\n");

	if ((int)me->query("max_neili") < 2500)
		return notify_fail("你的内力修为不够使用「天人化生」！\n");

	if ((int)me->query("neili") < 2500)
		return notify_fail("你此时的内力不足！\n");

	msg =BLK HBCYN "$N" BLK HBCYN "双手齐抓，幻出千万道耀眼的金光，顿时气流呼啸而至，空气中顿时传来一阵刺耳的暴响一股凛冽的气流顿时澎湃涌而至。"NOR"\n";
	
	message_combatd(msg, me, target);
	skill = me->query_skill("tianrenheyi", 1);

	count = skill / 100;

	if (me->is_fighting())
		me->start_busy(2);

	//me->add_temp("str", count);
	me->add_temp("dex", count);
	me->set_temp("ling_long", 1);
	me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 1);

	me->add("neili", -2500);
	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ((int)me->query_temp("ling_long"))
	{
		//me->add_temp("str", -amount);
		me->add_temp("dex", -amount);
		me->delete_temp("ling_long");
		tell_object(me, "你的「天人化生」运功完毕，将内力收回丹田。\n");
	}
}
