// 闪电术

#include <ansi.h>
string query_name() { return "[冰魔法]"ZJBR"寒冰风暴"; }
inherit F_SSERVER;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
    int damagic;
	spells = me->query_skill("spells");
	if((int)me->query("neili")< 2000)
	return notify_fail("你的法力太差了！\n");
msg = HIW"   呼*****呼  \n"NOR;
msg += HIW"\n一个冰魔法·寒冰风暴突破天空打向$n"HIW"!!\n"NOR;
if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
{
damage = (int)me->query_skill("bingzhi-shengdian", 1);
//对水属性目标无作用
if ((int)target->query("bingzhi-shengdian")==2)
{
damagic=12500+damage;
target->receive_damage("qi", damagic);
damagic=12500+damage;
target->receive_wound("qi", damagic);
}
//对火属性目标强大
else  if ((int)target->query("bingzhi-shengdian")==1)
{
damagic=20000+damage*75;
target->receive_damage("qi", damagic);
damagic=20000+damage*75;
target->receive_wound("qi", damagic);
}
else
{
damagic=16500+damage*50;
target->receive_damage("qi", 16500+damage*50);
target->receive_wound("qi", 16500+damage*50);
}
msg += HIW"$n"HIW"的附近成为了一片冻土!!\n"NOR;
target->start_busy(1);
message_combatd(msg, me, target);
COMBAT_D->report_status(target);
} else
{
msg += HIW"$n"HIW"飞身跃起，逃过了一难。\n"NOR;
message_combatd(msg, me, target);
}
if (target->query("qi") < 3)target->set("qi",1);
if (target->query("eff_qi") < 3)target->set("eff_qi",1);
if (target->query("max_qi") < 3)target->set("max_qi",1);
if (target->query("jing") < 3)target->set("jing",1);
if (target->query("eff_jing") < 3)target->set("eff_jing",1);
if (target->query("max_jing") < 3)target->set("max_jing",1);
if (target->query("neili") < 3)target->set("neili",1);
if (target->query("max_neili") < 3)target->set("max_neili",1);
me->add("neili",-450);
if (wizardp(me))
tell_object(me, "基本杀伤为"+damagic+"点。\n" NOR);
return 1;
}
int perform(object me, object target)
{
string 	msg;
object	env;
object	*inv;
int	i;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIW"「冰魔法·寒冰风暴」只能对战斗中的对手使用。\n"NOR);

	if((int)me->query("neili")< 2000)
	return notify_fail("你的法力太差了！\n");

	if((int)me->query_skill("bingzhi-shengdian",1)< 300)
	return notify_fail("你的冰之圣典太差了！\n");


	msg = HIW "$N"HIW"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += HIW"$N"HIW"念到 冥王啊，令所有至高无上的力量集于我身！！\n"NOR;
       msg += HIW"$N"HIW"念到 翻起死亡的冷冻风暴！如今籍着新的契约收集冰雪之力到来吧!!\n"NOR;
       msg += HIW"突然变得雪白的天空，对着$n"HIW"所处的地方卷起了冰魔法·寒冰风暴！\n"NOR;
       msg += HIW"  「冰魔法·寒冰风暴」 \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(3);
	return 1;
}


