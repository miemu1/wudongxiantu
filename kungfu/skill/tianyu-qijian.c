// tianyu-qijian.c 天羽奇剑

inherit SKILL;

mapping *action = ({
([	"action":"$N使一式「海天一线」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"force" : 360,
	"dodge" : 50,
	"damage": 150,
	"lvl" : 0,
	"skill_name" : "海天一线",
	"damage_type":	"割伤"
]),
([	"action":"$N错步上前，使出「闪电惊虹」，手中$w划出一道剑光劈向$n的$l",
	"force" : 370,
	"dodge" : 60,
	"damage": 155,
	"lvl" : 30,
	"skill_name" : "闪电惊虹",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w一抖，一招「日在九天」，斜斜一剑反腕撩出，攻向$n的$l",
	"force" : 380,
	"dodge" : 65,
	"damage": 160,
	"lvl" : 40,
	"skill_name" : "日在九天",
	"damage_type":	"割伤"
]),
([	"action":"$N手中剑锵啷啷长吟一声，一式「咫尺天涯」，一道剑光飞向$n的$l",
	"force" : 390,
	"dodge" : 70,
	"damage": 165,
	"lvl" : 50,
	"skill_name" : "咫尺天涯",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「怒剑狂花」，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
	"force" : 420,
	"dodge" : 75,
	"damage": 160,
	"lvl" : 60,
	"skill_name" : "怒剑狂花",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w斜指苍天，剑芒吞吐，一式「九弧震日」，对准$n的$l斜斜击出",
	"force" : 440,
	"dodge" : 85,
	"damage": 165,
	"lvl" : 70,
	"skill_name" : "九弧震日",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「漫天风雪」，手腕急抖，挥洒出万点金光，刺向$n的$l",
	"force" : 460,
	"dodge" : 95,
	"damage": 160,
	"lvl" : 80,
	"skill_name" : "漫天风雪",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「天河倒泻」，$w飞斩盘旋，如疾电般射向$n的胸口",
	"force" : 490,
	"dodge" : 105,
	"damage": 255,
	"lvl" : 100,
	"skill_name" : "天河倒泻",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「天外飞仙」，$w突然从天而降，一片金光围掠$n全身",
	"force" : 510,
	"dodge" : 115,
	"damage": 300,
	"lvl" : 120,
	"skill_name" : "天外飞仙",
	"damage_type":	"刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_skill("force") < 40)
		return notify_fail("你的内功火候不够，不能学习天羽奇剑。\n");

	if (me->query("max_neili") < 200)
		return notify_fail("你的内力不够，不能学习天羽奇剑。\n");

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
	// int i, level;
	// level = (int) me->query_skill("tianyu-qijian",1);
	// for(i = sizeof(action); i > 0; i--)
		// if(level > action[i-1]["lvl"])
			// return action[NewRandom(i, 20, level/5)];
		
	if (random(5) == 0)
	{
	return ([
    "action": HIW "只听一声龙吟，$N身法陡然加快，剑尖青芒吞吐不定，身外化身，剑外化剑，"
		      "手中$w如飞龙一般递出。"NOR"\n",
	"attack": 300,
	"dodge" : 100,
	"parry" : 100,
    "damage": 400,
	"force" : 580,
	"damage_type": "刺伤"]);
	}

	return action[random(sizeof(action))];	
		
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon;
	
	if (random(10) < 6)
	{
			victim->receive_wound("qi", damage_bonus / 6, me);
		return HIC "$N" HIC "默运真气，剑尖陡然生出半尺吞吐不定的青芒，$n" HIC "一个不察，已被剑芒所伤！"NOR"\n"HIR"打气血上限 -"+damage_bonus/6+"。"NOR"\n";
	}
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练天羽奇剑。\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练天羽奇剑。\n");

	me->receive_damage("qi", 40);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}
