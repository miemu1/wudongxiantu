inherit SKILL;

#include <ansi.h>

mapping *action = ({
([      "action" : "$N一招「"HIW"杞人忧天"NOR"」抬头向天，浑若不见，呼的一掌"
		   "向自己头顶空空拍出，手掌斜下，掌力化成弧\n"
		   "形，四散落下拍向$n的$l",
	"force"  : 450,
	"attack" : 140,
	"dodge"  : 40,
	"damage" : 150,
	"lvl"    : 0,
	"skill_name" : "杞人忧天",
	"damage_type": "内伤"
]),
([      "action" : "$N一招「"HIG"无中生有"NOR"」手臂下垂，绝无半点防御姿式，"
		   "突然间手足齐动，左掌右袖、双足头锤、连得\n"
		   "胸背腰腹尽皆有招式发出撞向$n",
	"force"  : 460,
	"attack" : 145,
	"dodge"  : 45,
	"damage" : 155,
	"lvl"    : 10,
	"skill_name" : "无中生有",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIB"拖泥带水"NOR"」右手云袖飘动，宛若流水，左掌"
		   "却重滞之极，便似带着几千斤泥沙一般，左右\n"
		   "齐攻$n",
	"force"  : 480,
	"attack" : 150,
	"dodge"  : 50,
	"damage" : 150,
	"lvl"    : 20,
	"skill_name" : "拖泥带水",
	"damage_type": "内伤"
]),

([      "action" : "$N一招「"HIY"力不从心"NOR"」含胸收腹，头缓缓低下，脚步沉"
		   "重，右掌软绵绵的拍向$n的$l",
	"force"  : 500,
	"attack" : 155,
	"dodge"  : 55,
	"damage" : 155,
	"lvl"    : 40,
	"skill_name" : "力不从心",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIR"行尸走肉"NOR"」踢出一脚。这一脚发出时恍恍惚"
		   "惚，隐隐约约，若有若无的踢向$n",
	"force"  : 430,
	"attack" : 160,
	"dodge"  : 60,
	"damage" : 150,
	"lvl"    : 60,
	"skill_name" : "行尸走肉",
	"damage_type": "瘀伤"
]),
([      "action" : "$N双掌平托，一招「"HIM"庸人自扰"NOR"」没精打采的拍向$n的$l",
	"force"  : 360,
	"attack" : 170,
	"dodge"  : 65,
	"damage" : 155,
	"lvl"    : 80,
	"skill_name" : "庸人自扰",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"RED"倒行逆施"NOR"」突然纵起丈余，头下脚上，倒过"
		   "身子，一掌拍向$n的$l",
	"force"  : 390,
	"attack" : 180,
	"dodge"  : 70,
	"damage" : 150,
	"lvl"    : 100,
	"skill_name" : "倒行逆施",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"YEL"心惊肉跳"NOR"」凝目远眺，脚下虚浮，胸前门户"
		   "洞开，全身姿式与武学中各项大忌无不吻合",
	"force"  : 420,
	"attack" : 190,
	"dodge"  : 75,
	"damage" : 155,
	"lvl"    : 120,
	"skill_name" : "心惊肉跳",
	"damage_type": "内伤"
]),
([      "action" : "$N一招「"BLU"废寝忘食"NOR"」脚下虚浮，有如几天不吃不睡后"
		   "的脚步朗舱的袭到$n的身旁，左掌和右拳攻\n"
		   "向$n的$l",
	"force"  : 460,
	"attack" : 200,
	"dodge"  : 80,
	"damage" : 150,
	"lvl"    : 140,
	"skill_name" : "废寝忘食",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIC"徘徊空谷"NOR"」左攻右打，虚虚实实的攻向$n的$l",
	"force"  : 490,
	"attack" : 210,
	"dodge"  : 85,
	"damage" : 155,
	"lvl"    : 160,
	"skill_name" : "徘徊空谷",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"CYN"饮恨吞声"NOR"」左手做饮酒状，右掌斜斜劈向$n的$l",
	"force"  : 520,
	"attack" : 225,
	"dodge"  : 90,
	"damage" : 150,
	"lvl"    : 70,
	"skill_name" : "饮恨吞声",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"MAG"六神不安"NOR"」身如陀螺急转，展开轻功围着$n"
		   "快速游走，忽然飞身而起，拍向$n的$l",
	"force"  : 550,
	"attack" : 240,
	"dodge"  : 95,
	"damage" : 155,
	"lvl"    : 200,
	"skill_name" : "六神不安",
	"damage_type": "内伤"
]),
([      "action" : "$N一招「"WHT"穷途末路"NOR"」闪身到$n身旁，左掌举到胸前平"
		   "推而出，接着右掌斜斜劈向$n的$l",
	"force"  : 570,
	"attack" : 250,
	"dodge"  : 100,
	"damage" : 150,
	"lvl"    : 220,
	"skill_name" : "穷途末路",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIY"呆若木鸡"NOR"」双目直直的盯着$n，身体动也不"
		   "动一下的飞向$n",
	"force"  : 590,
	"attack" : 255,
	"dodge"  : 105,
	"damage" : 155,
	"lvl"    : 240,
	"skill_name" : "呆若木鸡",
	"damage_type": "内伤"
]),
([      "action" : "$N低头冥想，一招「"HIB"若有所失"NOR"」右掌向外平平推向$n"
		   "的$l",
	"force"  : 620,
	"attack" : 260,
	"dodge"  : 110,
	"damage" : 150,
	"lvl"    : 260,
	"skill_name" : "若有所失",
	"damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIB"四通八达"NOR"」双掌晃出千万掌影将$n笼罩在掌"
		   "力之下",
	"force"  : 650,
	"attack" : 265,
	"dodge"  : 115,
	"damage" : 155,
	"lvl"    : 280,
	"skill_name" : "四通八达",
	"damage_type": "内伤"
]),
([      "action" : "$N错步上前，一招「"HIB"鹿死谁手"NOR"」招招抢先，以快打慢，"
		   "一个转身已经转到了$n的身后，运指如风点\n"
		   "向$n的大椎穴",
	"force"  : 680,
	"attack" : 270,
	"dodge"  : 120,
	"damage" : 150,
	"lvl"    : 300,
	"skill_name" : "鹿死谁手",
	"damage_type": "内伤"
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query("gender") == "无性") 
		return notify_fail("身为太监，何以黯然销魂？\n");

	if (! stringp(me->query("couple/id")))
		return notify_fail("你没有伴侣，何以黯然销魂？\n");

	//if (me->query("static/marry") > 1)
		//return notify_fail("你感情早已不纯，哪里还能领略到那种黯然销魂的感觉？\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然销魂掌必须空手。\n");

	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太弱，无法练黯然销魂掌。\n");

	if ((int)me->query_str() < 45)
		return notify_fail("你的膂力太弱，无法练黯然销魂掌。\n");

	if ((int)me->query_skill("unarmed", 1) < 150)
		return notify_fail("你的基本拳脚不够娴熟，无法练黯然销魂掌。\n");

	if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("sad-strike", 1))
		return notify_fail("你的基本拳脚水平有限，无法领会更高深的黯然销魂掌。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
/* 	int i, level;
	level = (int) me->query_skill("sad-strike", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level)]; */
		
	if (random(5) == 0)
	{
	return ([
	"action": HIC  "$N" HIC"仰天长啸，气势如山洪爆发，丹田内力迅速游遍全身，掌风隐隐带着潮涌之声，一掌拍出，竟似有狂潮涌来！"NOR"\n",
	"attack": 300,
	"dodge" : 150,
	"parry" : 150,
    "damage": 450,
	"force" : 680,
	"damage_type": "震伤"]);
	}

	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int cost;

	cost = me->query_skill("sad-strike", 1) / 3 + 80;
	if ((int)me->query("qi") < 160)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("你的内力不够练黯然消魂掌。\n");

	me->receive_damage("qi", 150);
	me->add("neili", -cost);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) >= 5||me->query("family/family_name") == "古墓派")
	{
		victim->receive_wound("qi", damage_bonus / 6, me);
		return HIR "只听" + victim->name() +  HIR "一声闷哼，“哇”的喷出了一大口鲜血！"NOR"\n"HIR"打气血上限 -"+damage_bonus/6+"。"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"sad-strike/" + action;
}
