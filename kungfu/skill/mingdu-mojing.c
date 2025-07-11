#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action": "$N使出一招「毒霸天下」，运掌如飞，招招直打$n的$l",
    "force" : 100,
    "attack": 100,
    "dodge" : 100,
    "parry" : 100,
    "damage": 350,
    "lvl"   : 0,
    "skill_name" : "毒霸天下" ,
    "damage_type" : "毒伤"
]),
([  "action": "$N使出一招「万物寂灭」，双掌急运内力，带着凛冽的掌风直拍$n的$l",
    "force" : 200,
    "attack": 200,
    "dodge" : 200,
    "parry" : 200,
    "damage": 355,
    "lvl"   : 30,
    "skill_name" : "万物寂灭" ,
    "damage_type" : "毒伤"
]),
([  "action": "$N飞身一跃而起，一声怪叫，一招「魂飞魄散」，双掌铺天盖地般拍向$n",
    "force" : 300,
    "attack": 300,
    "dodge" : 300,
    "parry" : 300,
    "damage": 355,
    "lvl"   : 60,
    "skill_name"  : "魂飞魄散" ,
    "damage_type" : "毒伤"
]),
([  "action": "$N惨然一声长啸，一招「收魂摄魄」，双掌猛然击下，直扑$n的要脉",
    "force" : 400,
    "attack": 400,
    "dodge" : 400,
    "parry" : 400,
    "damage": 400,
    "lvl"   : 90,
    "skill_name" : "收魂摄魄" ,
    "damage_type" : "毒伤"
]),
([  "action": "$N大叫一声，骨骼一阵暴响，双臂忽然暴长数尺，一招「六阴追魂」直直攻向$n的$l",
    "force" : 500,
    "attack": 500,
    "dodge" : 500,
    "parry" : 500,
    "damage": 500,
    "lvl"   : 120,
    "skill_name" : "六阴追魂" ,
    "damage_type" : "毒伤"
]),
([  "action": "$N一招「蚀骨摧心」，双掌缤纷拍出，化出满天掌影，陡然间一掌已迅捷无比的拍向$n",
    "force" : 600,
    "attack": 600,
    "dodge" : 600,
    "parry" : 600,
    "damage": 600,
    "lvl"   : 150,
    "skill_name" : "蚀骨摧心" ,
    "damage_type" : "毒伤"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo=="jiuyin-baiguzhao"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	    return notify_fail("练溟毒魔经必须空手。\n");

	if ((int)me->query("max_neili") < 1000)
	    return notify_fail("你的内力修为太浅，无法练习溟毒魔经。\n");

	if ((int)me->query_skill("force") < 1200)
	    return notify_fail("你的内功太差，无法练习溟毒魔经。\n");

	if ((int)me->query_skill("strike", 1) < 1200)
	    return notify_fail("你的基本掌法太差，无法领会溟毒魔经。\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("mingdu-mojing", 1))
	    return notify_fail("你的基本掌法火候不够，无法领会更高深的溟毒魔经。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action); i > 0; i--)
		if (level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("mingdu-mojing",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 5, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 1000)
		return notify_fail("你的内力不够。\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能练功。\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("这里不能练功。\n");

	me->receive_damage("qi", 100);
	me->add("neili", -1000);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lvl;
	int flvl;

	lvl  = me->query_skill("mingdu-mojing", 1);
	flvl = me->query("jiali");
	if (lvl < 80 || flvl < 10 || ! damage_bonus)
		return;

	if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
	    victim->affect_by("ming-du",
			      ([ "level" : flvl + random(flvl),
				 "id"    : me->query("id"),
				 "duration" : lvl / 100 + random(lvl / 10) ])))
	{
		return HIR "只听$n闷哼了一声，看来是受到了溟毒的干扰！"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"mingdu-mojing/" + action;
}

