// lianyu-mojing 炼狱魔经

inherit SKILL;

mapping *action = ({
([	"action" : "只见$对着$n使出一招碎颅",
	"force"  : 100,
	"dodge"  : 100,
	"damage" : 1000,
	"lvl"    : 0,
	"skill_name" : "碎颅",
	"damage_type" : "死气侵蚀"
]),
([	"action" : "$N对着$n使出一招断骨",
	"force"  : 200,
	"dodge"  : 200,
	"damage" : 2000,
	"lvl"    : 20,
	"skill_name" : "断骨",
	"damage_type" : "死气侵蚀"
]),
([	"action" : "$N对着$n使出一招灭魂",
	"force"  : 300,
	"dodge"  : 300,
	"damage" : 3000,
	"lvl"    : 40,
	"skill_name" : "灭魂",
	"damage_type" : "死气侵蚀"
]),
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

//int valid_combine(string combo) { return combo == "canhe-zhi"; }

int valid_learn(object me)
{
	if (objectp(me))
		return notify_fail("炼狱魔经不能升级。\n");
	if ((int)me->query_skill("force") < 600)
		return notify_fail("你的内功火候不够，无法练炼狱魔经。\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力太弱，无法练炼狱魔经。\n");
	if (me->query_skill("cuff", 1) < me->query_skill("lianyu-mojing", 1))
		return notify_fail("你的基本拳法造诣有限，无法领会更高深的炼狱魔经。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("lianyu-mojing", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 20, level * 5 /1)];
}

int practice_skill(object me)
{

if (objectp(me))
		return notify_fail("炼狱魔经不能升级。\n");

	if ((int)me->query("qi") < 15000)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 1500)
		return notify_fail("你的内力不够练炼狱魔经。\n");

	me->receive_damage("qi", 50);
	me->add("neili", -1500);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"lianyu-mojing/" + action;
}

