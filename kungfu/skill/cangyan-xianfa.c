// cangyan-xianfa.c 苍炎仙法

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「火云海」，$w似幻出片片火红色的云，四面八方的罩向$n",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 0,
	"skill_name" : "火云海",
	"damage_type" : "烧伤"
]),
([      "action" : "$N一招「火云涌」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 20,
	"skill_name" : "火云涌",
	"damage_type" : "烧伤"
]),
([      "action" : "$N使出「火云舞」，$w幻一条飞练，带着一股寒气划向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 40,
	"skill_name" : "火云舞",
	"damage_type" : "烧伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「火云动」，右手$w带着一团剑花，逼向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 60,
	"skill_name" : "火云动",
	"damage_type" : "烧伤"
]),
([      "action" : "$N一招「火云瀑」，左脚跃步落地，右手$w幻成一条火红色的瀑布，扫向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 80,
	"skill_name" : "火云瀑",
	"damage_type" : "烧伤"
]),
([      "action" : "$N右腿半屈般蹲，$w平指，一招「火云寂」，剑尖无声无色的慢慢的刺向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 100,
	"skill_name" : "火云寂色",
	"damage_type" : "烧伤"
]),
([      "action" : "$N一招「火云乱」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 120,
	"skill_name" : "火云乱",
	"damage_type" : "烧伤"
]),
([      "action" : "$N使出「苍炎之息」，$w幻一条飞练，带着一股灼热气划向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1500,
	"lvl"    : 140,
	"skill_name" : "苍炎之息",
	"damage_type" : "烧伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「苍炎天坠」，右手$w带着一团剑花，逼向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1500,
	"lvl"    : 160,
	"skill_name" : "苍炎天坠",
	"damage_type" : "烧伤"
]),
([      "action" : "$N一招「苍炎无痕」，左脚跃步落地，右手$w幻成一条火红色的剑痕，扫向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1500,
	"lvl"    : 180,
	"skill_name" : "苍炎无痕",
	"damage_type" : "烧伤"
]),
([      "action" : "$N右腿半屈般蹲，$w平指，一招「苍炎剑息」，剑尖无声无色的慢慢的刺向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 2000,
	"lvl"    : 200,
	"skill_name" : "苍炎剑息",
	"damage_type" : "烧伤"
]),
([      "action" : "$N一招「苍炎万灭」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 3000,
	"lvl"    : 220,
	"skill_name" : "苍炎万灭",
	"damage_type" : "烧伤"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100000)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 600)
		return notify_fail("你的内功火候太浅。\n");

	if ((int)me->query_skill("sword", 1) < 600)
		return notify_fail("你的基本剑法火候不够，无法学习苍炎仙法。\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("cangyan-xianfa", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的苍炎仙法。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("cangyan-xianfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 100000)
		return notify_fail("你的体力目前没有办法练习苍炎仙法。\n");

	if ((int)me->query("neili") < 10000)
		return notify_fail("你的内力不够，无法练习苍炎仙法。\n");
	
	me->add("qi", -10000);
	me->add("neili", -10000);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"cangyan-xianfa/" + action;
}


