#include <ansi.h>
#include <combat.h>
string query_name() { return "[火魔法]"ZJBR"火之护盾"; }
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法召唤火魔法·火之护盾");
	if((int)me->query("neili")< 300)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("huozhi-shengdian",1)< 250)
	return notify_fail("你的火之圣典太差了！\n");
        if ((int)me->query("magicgift")==1)
        return notify_fail("你已经使用火魔法·火之护盾了！\n");
	me->add("neili",-250);
	me->start_busy(2);
        me->set("magicgift",1);
	message_vision(HIR "\n$N念动咒语 [伟大的火之精灵，撒拉曼達，成为吾之盾牌!] !!\n" NOR, me);
	message_vision(HIR "\n$N的周围出来了无形的火之护盾!\n" NOR, me);
	return 1;
}
