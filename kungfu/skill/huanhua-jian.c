//
// huanhua-jian.c 浣花剑法
//
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;
mapping *action = ({
([      "action" : "只见白芒一闪,$N使出一招「长虹贯日」，手中$w一抖，直刺$n的$l  ",
        "skill_name" : "长虹贯日",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 0,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「旭日飞升」，剑光在长空中划起半道弧型，剑芒向$n的$l飞贯而来  ",
        "skill_name" : "旭日飞升",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 8,
        "damage" : 50,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「飞星刺月」，纵身跃入半空，$w如流星般劈向$n的$l  ",
        "skill_name" : "飞星刺月",
        "force" : 180,
        "dodge" : -10,
        "lvl" : 16,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出「一星抛月」，$w的剑光舞得如圆月，忽然一剑刺向$n的$l  ",
        "skill_name" : "一星抛月",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 24,
        "damage" : 70,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「天际长江」，全身劲气贯于$w中，剑气直指$n的$l  ",
        "skill_name" : "天际长江",
        "force" : 250,
        "dodge" : 10,
        "lvl" : 32,
        "damage" : 80,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「紫气万象」，一排剑光如白影般向$n的$l扫去  ",
        "skill_name" : "紫气万象",
        "force" : 280,
        "dodge" : 15,
        "lvl" : 40,
        "damage" : 90,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「花雨点点」，手中$w一抖,$n只觉得漫天剑光扑面而来  ",
        "skill_name" : "花雨点点",
        "force" : 300,
        "dodge" : 20,
        "lvl" : 48,
        "damage" : 100,
        "damage_type" : "割伤",
]),
([      "action" : "$N飞身一跃，居高临下使出「漫天花雨」，顿时剑尖如雨刺向$n的$l  ",
        "skill_name" : "漫天花雨",
        "force" : 320,
        "dodge" : 25,
        "lvl" : 56,
        "damage" : 110,
        "damage_type" : "刺伤",
]),
([      "action" : "$N猛然跃起,使出一招「花落无凭」，在半空中向$n徐徐劈去一剑  ",
        "skill_name" : "花落无凭",
        "force" : 340,
        "dodge" : 20,
        "lvl" : 66,
        "damage" : 120,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「梅花三弄」，$w舞出三朵剑花,正在$n茫然的时候,剑花中心一道剑光向$n的$l扫去  ",
        "skill_name" : "梅花三弄",
        "force" : 360,
        "dodge" : 25,
        "lvl" : 84,
        "damage" : 130,
        "damage_type" : "割伤",
]),
([      "action" : "$N纵身轻轻跃起，一式「满天星斗」，剑光如水，一泻千里，洒向$n全身",
        "skill_name" : "满天星斗",
        "force" : 380,
        "dodge" : 20,
        "lvl" : 92,
        "damage" : 140,
        "damage_type" : "割伤",
]),
([      "action" : "$N轻抬$w，一招「移花接玉」，竟把$n的全部攻击力转向了$n  ",
        "skill_name" : "移花接玉",
        "force" : 400,
        "dodge" : 25,
        "lvl" : 100,
        "damage" : 150,
        "damage_type" : "刺伤",
]),
([      "action" : HIY "$N剑尖斜指，一式「生亦何欢，死亦何患」,手中$w藉着真力一吐，铺天剑光向$n飞去。"NOR,
        "skill_name" : "生亦何欢，死亦何患",
        "force" : 400,
        "dodge" : 25,
        "lvl" : 100,
        "damage" : 180,
        "damage_type" : "刺伤",
]),
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query("family/family_name")!="浣花剑派")
   return notify_fail("你不加入本派，休想学习本派技能。\n");		
if ((int)me->query_skill("guiyuan-dafa", 1) < 150)    
        return notify_fail("你的归元大法火侯太浅。\n");
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
    level   = (int) me->query_skill("huanhua-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if (me->query("family/family_name")!="浣花剑派")
   return notify_fail("你从哪里偷学的本派绝技？我要去掌门哪里打小报告。\n");			
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够，练不了浣花剑法。\n");
    me->receive_damage("qi", 20);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"huanhua-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int weap_damage,damage2,ap,dp;	
	object weapon;
	weapon = me->query_temp("weapon");
	weap_damage = weapon->query("weapon_prop/damage");
	damage2 = (int)me->query_skill("huanhua-jian",1);
	ap = me->query_skill("huanhua-jian",1);
	dp = victim->query_skill("parry",1);
	if (weap_damage < 0) return 0;		
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("guiyuan-dafa",1) < 100)	 return 0;
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || me->query_skill_mapped("force") != "guiyuan-dafa") return 0;	
	if (damage2<10) damage2=10;	

	if(	me->query_skill("force",1) >300
	    && random(ap) > dp/10
		&& random(5)==0 
		&& me->query_skill_mapped("force")=="guiyuan-dafa"
		&& me->query("jiali") > 0)
	{
		victim->receive_damage("qi", damage2 + weap_damage+damage_bonus/2,me );
		victim->receive_wound("qi", damage2 + weap_damage+damage_bonus/2 ,me);		
//		if (!victim->is_busy()) victim->start_busy(1);
		me->add("neili", -100 );
		return HIW "$N运转归元大法，三分归元气在" + weapon->name() + " 聚集，寒光一闪，"HIB"雪花"HIW"，"HIM"桃花"HIW"，"HIC"血花"HIW"！\n" NOR;
	}
}