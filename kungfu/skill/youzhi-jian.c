// youzhi-jian.c 草薙剑

inherit SKILL;

mapping *action = ({
([      "action": "$N蹒跚提步，踉踉跄跄来至$n面前，随即手中$w微震，"
		   "剑尖疾点向$n的$l",
	"force" : 320,
	"attack": 141,
	"parry" : 40,
	"dodge" : 31,
	"damage": 160,
	"lvl"   : 0,
	"damage_type" : "刺伤"
]),
([      "action": "$N斜走一步，随手挥剑舞出两道一长一短的光影"
		   "直刺$n的$l",
	"force" : 340,
	"attack": 152,
	"parry" : 41,
	"dodge" : 42,
	"damage": 162,
	"lvl"   : 10,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招刺出，$w突然出鞘又发现插不回剑鞘中，随即转身逃跑"
		   "离去。$n这时才感觉到有一股尴尬逼向自己的$l",
	"force" : 350,
	"attack": 158,
	"parry" : 45,
	"dodge" : 43,
	"damage": 170,
	"lvl"   : 20,
	"damage_type" : "刺伤"
]),
([      "action": "$N双手举剑向天，一招「初生牛犊不怕虎」，$w带起阵阵丫丫学语，自上而下向"
		   "$n的头颅削去",
	"force" : 370,
	"attack": 161,
	"parry" : 48,
	"dodge" : 48,
	"damage": 165,
	"lvl"   : 40,
	"damage_type" : "刺伤"
]),
([      "action": "$N施展出「为最可爱」，手握$w颔首微微一笑，$n只看得一呆，却见"
		   "一道剑影犹如龙游般袭向自己的$l，而自己却没看清$N何时出的手！！",
	"force" : 390,
	"attack": 168,
	"parry" : 51,
	"dodge" : 50,
	"damage": 170,
	"lvl"   : 60,
	"damage_type" : "刺伤"
]),
([      "action": "$N左脚踏实，右脚踩空，一招「狗吃屎」，$w带着一团剑花，飘浮"
		   "不定地逼向$n的$l",
	"force" : 400,
	"attack": 171,
	"parry" : 55,
	"dodge" : 55,
	"damage": 175,
	"lvl"   : 80,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「对牛弹琴」，左手轻抚$w，随即猛地一弹，右手向前一递，"
		   "只见一道闪烁不定的剑影迅速刺向$n的$l",
	"force" : 400,
	"attack": 178,
	"parry" : 60,
	"dodge" : 62,
	"damage": 170,
	"lvl"   : 100,
	"damage_type" : "刺伤"
]),
([      "action": "$N回身低首，神色黯然，一招「你们欺负我」，$w剑尖游移不定地刺向"
		   "$n的$l",
	"force" : 350,
	"attack": 181,
	"parry" : 64,
	"dodge" : 65,
	"damage": 170,
	"lvl"   : 110,
	"damage_type" : "刺伤"
]),
([      "action": "$N坐手掩面，一招「我哭给你们看」，右手$w斜向下划出，$n微觉奇怪，正迟"
		   "疑间，却见$N手中的$w已反挑而上，直刺自己的咽喉",
	"force" : 380,
	"attack": 184,
	"parry" : 68,
	"dodge" : 75,
	"damage": 169,
	"lvl"   : 120,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 900)
		return notify_fail("你的内力不够，无法学习草薙剑。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候不够，无法学习草薙剑。\n");

	if ((int)me->query_skill("sword", 1) < 100)
		return notify_fail("你的基本剑法火候不够，无法学习草薙剑。\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("youzhi-jian", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的草薙剑。\n");

		if (me->query("int") < 26)
		return notify_fail("你先天悟性太差，无法学习草薙剑。\n");

    return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level = (int) me->query_skill("youzhi-jian", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力不够练草薙剑。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的体力不够练草薙剑。\n");

	me->receive_damage("qi", 45);
	me->add("neili", -66);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 7)
	{
		victim->receive_wound("qi", damage_bonus / 6);
		return HIW "$n听到耳边传来一阵阵萧声，顿时血气翻滚，一股热流穿心而过！"NOR"\n"HIR"打气血上限 -"+damage_bonus/6+"。"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"youzhi-jian/" + action;
}
