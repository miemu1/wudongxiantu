// qinglian-jiange.c 青莲剑歌 
// 增加不同技能级别相应的学习和能使出的招数名, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()
// Updated by Doing

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「"+RED+"揽雀尾"+NOR+"」，执剑划了个半圈，刺向$n的$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : RED"揽雀尾"NOR,
	"lvl" : 0,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N使一招「"+GRN+"单鞭"+NOR+"」，执剑向外挥出，劈向$n的$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : GRN"单鞭"NOR,
	"lvl" : 5,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N使一招「"+YEL+"挥剑上撩"+NOR+"」，向$n的$l刺去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : YEL"提手上式"NOR,
	"lvl" : 10,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N手中剑划弧，使一招「"+HIC+"白鹤亮翅"+NOR+"」，刺向$n的面门和$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIC"白鹤亮翅"NOR,
	"lvl" : 15,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N身体微转，使一招「"+HIW+"搂膝拗步"+NOR+"」，刺向$n的$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIW"搂膝拗步"NOR,
	"lvl" : 20,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑由下上挑，右手格挡，一招「"+MAG+"手挥琵琶"+NOR+"」，向$n的$l打去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : MAG"手挥琵琶"NOR,
	"lvl" : 25,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑由肘下穿出，一招「"+RED+"肘底看锤"+NOR+"」，砍向$n的$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : RED"肘底看锤"NOR,
	"lvl" : 30,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N左脚前踏半步，执剑使一招「"+YEL+"海底针"+NOR+"」，指由下向$n的$l戳去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : YEL"海底针"NOR,
	"lvl" : 35,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N招「"+GRN+"闪通臂"+NOR+"」，左脚一个弓箭步，执剑向$n的$l挥去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : GRN"闪通臂"NOR,
	"lvl" : 40,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N两手由相对，执剑使一招「"+HIC+"斜飞式"+NOR+"」，挥向$n的$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIC"斜飞式"NOR,
	"lvl" : 45,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N左手虚按，执剑使一招「"+YEL+"白蛇吐信"+NOR+"」，向$n的$l插去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : YEL"白蛇吐信"NOR,
	"lvl" : 50,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑向前向后划弧，一招「"+HIC+"双峰贯耳"+NOR+"」打向$n的$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIC"双风贯耳"NOR,
	"lvl" : 55,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N左手虚划，执剑一记「"+WHT+"指裆锤"+NOR+"」击向$n的裆部",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : WHT"指裆锤"NOR,
	"lvl" : 60,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N施出「"+MAG+"伏虎剑"+NOR+"」，执剑击向$n的$l，左手攻向$n的裆部",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : MAG"伏虎剑"NOR,
	"lvl" : 65,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N由臂带剑，缓缓划过，一招「"+RED+"云剑"+NOR+"」，挥向$n的$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : RED"云剑"NOR,
	"lvl" : 70,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N左腿收起，执剑使一招「"+YEL+"金鸡独立"+NOR+"」，向$n的$l击去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : YEL"金鸡独立"NOR,
	"lvl" : 75,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑向上，推出一招「"+HIC+"高探剑"+NOR+"」",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIC"高探剑"NOR,
	"lvl" : 80,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑使一式招「"+MAG+"玉女穿剑"+NOR+"」，扑身向$n的$l插去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : MAG"玉女穿剑"NOR,
	"lvl" : 85,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑经腹前撇出，使一招「"+HIG+"反身撇剑"+NOR+"」，向$n的$l锤去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIG"反身撇剑"NOR,
	"lvl" : 90,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N左手虚按，执剑使一招「"+HIB+"反身剑"+NOR+"」，向$n的$l刺去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIB"反身蹬剑"NOR,
	"lvl" : 100,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N左手向上划弧，执剑使一招「"+RED+"白蛇吐信"+NOR+"」，向$n的$l撩去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 102,
	"skill_name" : RED"白蛇吐信"NOR,
	"lvl" : 120,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N使一招「"+YEL+"栽锤剑"+NOR+"」，左手搂左膝，执剑向下砍向$n的$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 115,
	"skill_name" : YEL"栽锤剑"NOR,
	"lvl" : 140,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N双手握剑，，一招「"+MAG+"野马分鬃"+NOR+"」，向$n的$l和面门砍去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 119,
	"skill_name" : MAG"野马分鬃"NOR,
	"lvl" : 160,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑一挥，一招「"+HIC+"抱虎剑"+NOR+"」，向$n的$l砍去",
	"force" : 100,
	"dodge" : 100,
	"parry" : 115,
	"skill_name" : HIC"抱虎剑"NOR,
	"lvl" : 180,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑后仰前刺，一式「"+HIY+"十字刺"+NOR+"」，向$n的$l刺去",
	"force" : 100,
	"dodge" : 102,
	"parry" : 122,
	"skill_name" : HIY"十字刺"NOR,
	"lvl" : 200,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑前刺脚踏七星，一招「"+HIM+"进步七星"+NOR+"」，向$n的$l刺去",
	"force" : 100,
	"dodge" : 110,
	"parry" : 133,
	"skill_name" : HIM"进步七星"NOR,
	"lvl" : 210,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N身体向后腾出执剑刺出，使一招「"+HIG+"倒撵猴剑"+NOR+"」，向$n的$l和面门刺去",
	"force" : 115,
	"dodge" : 132,
	"parry" : 121,
	"skill_name" : HIG"倒撵猴剑"NOR,
	"lvl" : 220,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N以腰为轴，一招「"+HIC+"转身摆莲"+NOR+"」，将$n笼罩剑影之中",
	"force" : 120,
	"dodge" : 154,
	"parry" : 145,
	"skill_name" : HIC"转身摆莲"NOR,
	"lvl" : 230,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑前突如箭，一招「"+HIR+"弯弓射虎"+NOR+"」，直奔$n心窝而去",
	"force" : 115,
	"dodge" : 166,
	"parry" : 175,
	"skill_name" : HIR"弯弓射虎"NOR,
	"lvl" : 240,
	"damage_type" : "剑气伤"
]),
([	"action" : "$N执剑后劈，一招「"+GRN+"如封似闭"+NOR+"」，一股劲风直逼$n",
	"force" : 120,
	"dodge" : 178,
	"parry" : 185,
	"skill_name" : GRN"如封似闭"NOR,
	"lvl" : 250,
	"damage_type" : "剑气伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo)
{
	return combo == "wudang-zhang" || combo == "paiyun-shou";
}

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 600)
		return notify_fail("你的内功火候不够，无法学青莲剑歌。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练青莲剑歌。\n");

	if ((int)me->query_skill("sword", 1) < 600)
		return notify_fail("你的基本剑法火候不够，无法学青莲剑歌。\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("qinglian-jiange", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的青莲剑歌。\n");

	return 1;
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
	level = (int) me->query_skill("qinglian-jiange", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 5, level / 5)];
}

string query_txt()
{
	return "要求：剑法，内力1000，内功激发600，基本剑法6000，技能等级不能高于基本剑法"ZJBR
	"特效：剑招化解对手的空手攻击，对比自身(招架激发/4+技能等级)和攻击者内功激发，同等级1/3概率触发，受阴阳八卦克制";
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp,mp2;

	if ((int)me->query_skill("qinglian-jiange", 1) < 100 ||
	    ! living(me))
		return;
    mp2 = ob->query_skill("never-defeated", 1)/2;
	mp = ob->query_skill("count", 1)+mp2;
	ap = ob->query_skill("force") + mp;
	dp = me->query_skill("parry") / 4 + me->query_skill("qinglian-jiange", 1);

	if (ap / 2 + random(ap) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(3))
		{
		case 0:
			result += (["msg" : HIC "$n" HIC "面含微笑，用剑划出了"
					    "一个圆圈，竟然让$N" +
					    HIC "的攻击全不着力。"NOR"\n"]);
			break;

		case 1:
			result += (["msg" : HIC "$n" HIC "挥剑左右格挡，"
					    "化解$N" HIC "的攻势于无形。"NOR"\n"]);
			break;

		default:
			result += (["msg" : HIC "$n" HIC "慢慢出剑"
					    HIC "，动作虽然缓慢，却让$N"
					    HIC "感到浑身粘滞，甚不舒畅。"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(3))
		{
		case 0:
			result = HIY "$n" HIY "面含微笑，用剑划出了"
				 "一个圆圈，然而$N" +
				 HIY "理也不理，随手挥招直入，进袭$n"
				 HIY "！"NOR"\n";
			break;

		case 1:
			result = HIY "$n" HIY "挥剑左右格挡，"
				 "可是$N" HIY "攻势却是变化无方，不遵循常理。"NOR"\n";
			break;

		default:
			result = HIY "$n" HIY "慢慢出剑"
				 HIY "，动作缓慢却让$N"
				 HIY "感到粘滞，可是$N"
				 HIY "立刻变化节奏，出奇招快速进击$n"
				 HIY "！"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

int query_effect_parry(object attacker, object me)
{
	int lvl;

	if (me->query_temp("weapon"))
		return 0;

	lvl = me->query_skill("qinglian-jiange", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练青莲剑歌。\n");

	me->receive_damage("qi", 50);
	me->add("neili", -100);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qinglian-jiange/" + action;
}
//等级提升，是否学会新的招式
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}