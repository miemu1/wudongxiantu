// jingang-buhuaiti.c

#include <ansi.h>

inherit SHAOLIN_SKILL;

int valid_enable(string usage) { return usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功火候不够，难以修习这等神功。\n");

	if ((int)me->query("max_neili") < 3000)
		return notify_fail("你的内力还不足以修习这等神功。\n");

	if ((int)me->query_skill("force", 1) < (int)me->query_skill("jingang-buhuaiti", 1))
		return notify_fail("你的基本内功水平有限，无法领会更高深的金刚不坏体神功。\n");

	return 1;
}

string query_txt()
{
	return "要求：内功激发300，内力3000，等级不能高于基本内功"ZJBR
	"特效：以内力化解攻击者伤害，内力消耗=伤害/4，对比自身(内功激发*12+最大内/2)和攻击者(内功激发*12+内力/2)，同数值1/2概率触发"
	"，内力低于最大内/3不触发，受不败神功破解";
}

mixed valid_damage(object ob, object me, int damage, object weapon) 
{ 
	mixed result; 
	int ap, dp, mp, ratio; 
  	int cost;
	cost = damage / 4;  
		if (! living(me) ||
	    (int)me->query_skill("jingang-buhuaiti", 1) < 100 ||
	    (int)me->query("neili") < cost ||
	    (int)me->query("neili") < me->query("max_neili")/3)
		return;
		
	mp = ob->query_skill("never-defeated", 1) ;
	ap = ob->query_skill("force") * 12 + ob->query("max_neili")/2;
	dp = me->query_skill("force") * 12 + me->query("neili")/2;	    
	if (ap / 2 + random(ap) < dp)
	{
		me->add("neili", -cost);
        tell_object(me,"你使出金刚不坏体神功，用"+cost+"内力抵消了"+damage+"伤害。"NOR"\n");
		result = ([ "damage": -damage ]);

		switch (random(5))
		{
		case 0:
			result += (["msg" : HIY "$n" HIY "身前仿佛有一道无形气墙，让$N"
					    HIY "再难前进一步。"NOR"\n"]);
			break;
		case 1:
			result += (["msg" : HIY "只见$N" HIY "这一招打了个正中！然而$n"
					    HIY "毫不在意，并没有放在心上。"NOR"\n"]);
			break;
		case 2:
			result += (["msg" : HIY "$N" HIY "一招正好打在$n" HIY "身上，可"
					    "力量犹如石沉大海，丝毫不起作用。"NOR"\n"]);
			break;
		case 3:
			result += (["msg" : HIY "$N" HIY "一招击在$n" HIY "身上，可听$n"
					    HIY "一声大喝，$N" HIY "反被护体罡气震退了"
					    "数步。"NOR"\n"]);
			break;
		default:
			result += (["msg" : HIY "$n" HIY "浑若无事的接下了$N"
					    HIY "这一招，却没有受到半点伤害。"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(4))
		{
		case 0:
			result = HIY "$N" HIY "精通破解之法早已看破，$n" HIY "的抵挡。\n";
			break;
		case 1:
			result = HIY "$N" HIY "精通破解之法早已看破，$n" HIY "的抵挡。\n";
			break;
		case 2:
			result = HIY "$N" HIY "精通破解之法早已看破，$n" HIY "的抵挡。\n";
			break;
		default:
			result = HIY "$N" HIY "精通破解之法早已看破，$n" HIY "的抵挡。\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	} 
} 

int query_effect_parry(object attacker, object me)
{
	int lvl;

	lvl = me->query_skill("jingang-buhuaiti", 1);
	if (lvl < 100) return 0;
	if (lvl < 150) return 50;
	if (lvl < 200) return 60;
	if (lvl < 250) return 70;
	if (lvl < 300) return 80;
	if (lvl < 350) return 90;
	if (lvl < 400) return 100;
	return 120;
}

int practice_skill(object me)
{
	int cost;
	int lvl;

	if ((lvl = me->query_skill("jingang-buhuaiti", 1)) < 100)
		return notify_fail("你对这门护体神功的了解甚浅，还不足以自行锻炼。\n");

	cost = 85 + (lvl - 100) / 3;
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("你的内力不够练护体神功。\n");

	me->receive_damage("qi", 50);
	me->add("neili", -cost);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jingang-buhuaiti/" + action;
}

