// SKILL liuyang-zhang.c

inherit SKILL;

mapping *action = ({
([	"action" : "$N一招「落日熔金」，左掌叠于右掌之上，劈向$n",
	"force" : 300,
	"attack": 152,
	"dodge" : 30,
	"parry" : 1,
	"damage": 180,
	"lvl"   : 0,
	"skill_name" : "落日熔金",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「安禅制毒龙」，面色凝重，双掌轻飘飘地拍向$n",
	"force" : 300,
	"attack": 158,
	"dodge" : 25,
	"parry" : 3,
	"damage": 180,
	"lvl"   : 20,
	"skill_name" : "安禅制毒龙",
	"damage_type" : "内伤"
]),
([	"action" : "$N一招「日斜归路晚霞明」，双掌幻化一片掌影，将$n笼罩于内。",
	"force" : 300,
	"attack": 162,
	"dodge" : 43,
	"parry" : 4,
	"damage": 180,
	"lvl"   : 30,
	"skill_name" : "日斜归路晚霞明",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N一招「阳关三叠」，向$n的$l连击三掌",
	"force" : 310,
	"attack": 165,
	"dodge" : 55,
	"parry" : 8,
	"damage": 180,
	"lvl"   : 40,
	"skill_name" : "阳关三叠",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「阳春一曲和皆难」，只见一片掌影攻向$n",
	"force" : 350,
	"attack": 172,
	"dodge" : 52,
	"parry" : 0,
	"damage": 180,
	"lvl"   : 60,
	"skill_name" : "阳春一曲和皆难",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N双掌平挥，一招「云霞出海曙」击向$n",
	"force" : 400,
	"attack": 173,
	"dodge" : 65,
	"parry" : 11,
	"damage": 180,
	"lvl"   : 80,
	"skill_name" : "云霞出海曙",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「白日参辰现」，只见一片掌影攻向$n",
	"force" : 410,
	"attack": 178,
	"dodge" : 63,
	"parry" : 5,
	"damage": 180,
	"lvl"   : 100,
	"skill_name" : "白日参辰现",
	"damage_type" : "内伤"
]),

([	"action" : "$N左掌虚晃，右掌一记「云霞出薛帷」击向$n的头部",
	"force" : 430,
	"attack": 185,
	"dodge" : 77,
	"damage": 290,
	"parry" : 12,
	"lvl"   : 120,
	"skill_name" : "云霞出薛帷",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N施出「青阳带岁除」，右手横扫$n的$l，左手攻向$n的胸口",
	"force" : 460,
	"attack": 191,
	"dodge" : 80,
	"parry" : 15,
	"damage": 310,
	"lvl"   : 140,
	"skill_name" : "青阳带岁除",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N施出「阳歌天钧」，双掌同时击向$n的$l",
	"force" : 500,
	"attack": 202,
	"dodge" : 81,
	"parry" : 10,
	"damage": 330,
	"lvl"   : 160,
	"skill_name" : "阳歌天钧",
	"damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="parry" || usage=="strike"; }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天山六阳掌必须空手。\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("你的内功火候不够，无法练六阳掌。\n");

	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练六阳掌。\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("liuyang-zhang", 1))
		return notify_fail("你的基本掌法水平有限，无法领会更高深的天山六阳掌。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("liuyang-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够练天山六阳掌。\n");

	me->receive_damage("qi", 61);
	me->add("neili", -57);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 6)
	{
		victim->receive_wound("qi", damage_bonus / 6, me);
		return HIR "" + victim->name() +  HIR "受不了六阳掌劲忽冷忽热的煎熬受了严重的内伤！"NOR"\n"HIR"打气血上限 -"+damage_bonus/6+"。"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"liuyang-zhang/" + action;
}
