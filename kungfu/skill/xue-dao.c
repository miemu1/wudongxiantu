// xue-dao.c 血刀
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N高举手中$w,使出一招「磨牙吮血」，一刀斜劈$n的$l  ",
	"skill_name" : "磨牙吮血",
	"force" : 300,
	"attack": 170,
	"dodge" : 30,
	"parry" : 25,
	"lvl" : 0,
	"damage" : 170,
	"damage_type" : "割伤",
]),
([      "action" : "$N就地一滚，使一招「刺血满地」，手中$w卷向$n的大腿  ",
	"skill_name" : "刺血满地",
	"force" : 340,
	"attack": 175,
	"dodge" : 45,
	"parry" : 35,
	"lvl" : 40,
	"damage" : 175,
	"damage_type" : "割伤",
]),
([      "action" : "$N足尖一点，使出「血海茫茫」，刀锋自上而下直插$n的$l  ",
	"skill_name" : "血海茫茫",
	"force" : 380,
	"attack": 190,
	"dodge" : 52,
	"parry" : 40,
	"lvl" : 60,
	"damage" : 180,
	"damage_type" : "割伤",
]),
([      "action" : "$N使出一招「呕心沥血」，将$w舞得如白雾一般压向$n  ",
	"skill_name" : "呕心沥血",
	"force" : 420,
	"attack": 195,
	"dodge" : 58,
	"parry" : 42,
	"lvl" : 80,
	"damage" : 190,
	"damage_type" : "割伤",
]),
([      "action" : "$N低吼一声，使出「血口喷人」，举$w直劈$n的$l  ",
	"skill_name" : "血口喷人",
	"force" : 350,
	"attack": 200,
	"dodge" : 65,
	"parry" : 45,
	"lvl" : 90,
	"damage" : 200,
	"damage_type" : "割伤",
]),
([      "action" : "$N使出「血迹斑斑」，飞身斜刺，忽然反手一刀横斩$n的腰部  ",
	"skill_name" : "血迹斑斑",
	"force" : 380,
	"attack": 205,
	"dodge" : 70,
	"parry" : 60,
	"lvl" : 100,
	"damage" : 210,
	"damage_type" : "割伤",
]),
([      "action" : "$N使一式「以血还血」，挥刀直指$n的胸口",
	"skill_name" : "以血还血",
	"force" : 400,
	"attack": 210,
	"dodge" : 80,
	"parry" : 55,
	"lvl" : 120,
	"damage" : 230,
	"damage_type" : "割伤",
]),
([      "action" : "$N刀锋虚点，使出一招「血流满面」，转身举$w横劈$n的面门",
	"skill_name" : "血流漫面",
	"force" : 420,
	"attack": 220,
	"dodge" : 90,
	"parry" : 60,
	"lvl" : 150,
	"damage" : 235,
	"damage_type" : "割伤",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候太浅。\n");

	if ((int)me->query_skill("blade", 1) < 80)
		return notify_fail("你的基本刀法火候不够，无法修习血刀。\n");

	if ((int)me->query_skill("blade", 1) < (int)me->query_skill("xue-dao", 1))
		return notify_fail("你的基本刀法水平有限，无法修习更加高深的血刀。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
/* 	int i, level;
	level = (int) me->query_skill("xue-dao",1);
	for(i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)]; */
    if (random(5) == 0)
	{
	return ([
	"action": HIM  "$N" HIM"邪性大发，攻势一转，顿时刀罡大胜，刀刀急出，竟似血海潮涌！"NOR"\n",
	"attack": 300,
	"dodge" : 150,
	"parry" : 150,
    "damage": 400,
	"force" : 680,
	"damage_type": "割伤"]);
	}

	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力不够，练不了血刀。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够，练不了血刀。\n");

	me->receive_damage("qi", 60);
	me->add("neili", -63);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 7)
	{
		victim->receive_wound("qi", damage_bonus / 6, me);
		return HIR "只听" + victim->name() +  HIR "一声惨叫，已被血刀刀罡所伤！"NOR"\n"HIR"打气血上限 -"+damage_bonus/6+"。"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"xue-dao/" + action;
}
