//kuangfeng-jian 狂风快剑

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N纵身跃起手中$w轻挥，斩向$n后颈",
	"force"  : 380,
	"attack" : 35,
	"parry"  : 10,
	"dodge"  : 30,
	"damage" : 175,
	"lvl"    : 0,
	"skill_name" : "风平浪静",
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w连话三个弧形，向$n的右臂齐肩斩落",
	"force"  : 400,
	"attack" : 45,
	"parry"  : 22,
	"dodge"  : 45,
	"damage" : 188,
	"lvl"    : 30,
	"skill_name" : "风起云涌",
	"damage_type" : "刺伤"
]),
([      "action" : "$N轻吁一声，刷刷刷刷四剑，向$n胸，腹，腰，肩四处连刺",
	"force"  : 420,
	"attack" : 51,
	"parry"  : 18,
	"dodge"  : 53,
	"damage" : 295,
	"lvl"    : 60,
	"skill_name" : "风卷残云",
	"damage_type" : "刺伤"
]),
([      "action" : "$N仰天一声清啸，斜行向前，$w横削直击，迅捷无比，击向$n的$l",
	"force"  : 450,
	"attack" : 58,
	"parry"  : 20,
	"dodge"  : 52,
	"damage" : 310,
	"lvl"    : 90,
	"skill_name" : "风流云散",
	"damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够，无法修习狂风快剑。\n");

	if ((int)me->query_skill("dodge") < 90)
		return notify_fail("你的轻功火候太浅，无法修习狂风快剑。\n");

	if ((int)me->query_dex() < 25)
		return notify_fail("你的身法还不够灵活，无法修习狂风快剑。\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("kuangfeng-jian", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的狂风快剑。\n");

	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int lvl;
	int i;

	lvl = me->query_skill("sword-cognize", 1);
	i = random(lvl);

	if (me->query("family/family_name") == "华山剑宗" && random(10) < 7)
	{
		if (i < 100)
		{
			victim->receive_wound("qi", damage_bonus / 8);
			return HIC "只见$N" HIC "身形一探，剑芒陡涨，正中$n！"NOR"\n";
		}
		if (i < 200)
		{
			victim->receive_wound("qi", damage_bonus / 6);
			return HIY "只看$N" HIY "一声清啸，剑气横飞，$n" HIY "连连中招！"NOR"\n";
		} else
		{
			victim->receive_wound("qi", damage_bonus / 4);
			return HIW "但见$N" HIW "微微一笑，缓缓移动长剑，$n" HIW "已然中招！"NOR"\n";
		}
	}
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	int j;

	level = (int) me->query_skill("kuangfeng-jian",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
		{
			j = me->query_skill("sword-cognize", 1);

			if (me->query("family/family_name") == "华山剑宗" && 
    			    random(j) > 180 &&
    			    random(level) > 180 && random(3) == 0)
			{
				return ([ "action" : WHT "$N" WHT "双目忽地精光四射，一招「" HIY 
    						     "狂风骤雨" NOR WHT "」势不可挡地攻向$n",
					  "force"  : (j - 50),
					  "attack" : j / 5,
					  "parry"  : (level / 2 + 50),
					  "dodge"  : (level / 2),
					  "damage" : j / 2,
					  "skill_name" : "狂风骤雨",
					  "damage_type" : "割伤",
					]);
			}
			else return action[NewRandom(i, 20, level / 5)];
		}
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 65)
		return notify_fail("你的体力不够练狂风快剑。\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练狂风快剑。\n");

	me->receive_damage("qi", 60);
	me->add("neili", -16);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"kuangfeng-jian/" + action;
}

