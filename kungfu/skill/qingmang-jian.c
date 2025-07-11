// qingmang-jian.c 青蟒剑(刀)法
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;

string *dodge_msg = ({
"似乎$N每一招都能制$n的死命，可是$n总是或反打、或闪避，一一拆解开去。\n",
"却见$n一低头，从$N底下扑了上去，左臂随势格向$n的右臂。\n",
"那知$n身形一幌，轻轻巧巧地避过了$N的攻击。\n",
"$n飞起右足，踢向$N手腕，一招「叶底飞燕」反攻为守。\n"
});

string  *msg = ({
"$N刷刷刷连出三招，使出「青蟒吐信」，但见$w闪动，犹如蟒蛇吐信一般，不知要劈向何处",
"$N得理不让人，又是一招，$w直挥$n面门，逼得$n急忙侧头避让",
"$N左脚又在$n小腿上一扫，想将$n拌倒，跟着$w一抖，已指住$n咽喉",
"$N一声冷笑，手中$w迎面砍下，直劈$n$l",
"$N一下冲到$n身前，突然之间拔出$w，便往$n头上砍了下去",
"$N突然一下拔$w挥击，既是突如其来，行动又是快极，$n全无闪避的馀裕",
"$N$w挺出，一招「毒蛇出洞」，向$n当胸劈去，势道甚是劲急",
"$N叫声：「好！」$w圈转，削向$n$l",
"$N一招「灵舌吐信」，$w尖快绝无比点向$n的$l"
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry" ;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(3)+2)*50,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge":random(50),
                "force":200+random(200)
        ]);
}

string query_dodge_msg(object weapon)
{        
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 300)
    return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("force", 1) < 60)
    return notify_fail("你的内功心法火候太浅。\n");
    if ((int)me->query_skill("sword", 1) < 60)
    return notify_fail("你的基本剑法火候太浅。\n");
    if ((int)me->query_dex() < 25)
    return notify_fail("你的身法还不够灵活。\n");
    return 1;
}
int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 30)
    return notify_fail("你的体力不够练刀法。\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"qingmang-jian/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	int ap,dp,damage2;
	ap = me->query_skill("qingmang-jian",1) + me->query_skill("unarmed",1) + me->query_skill("force",1);
	dp = victim->query_skill("parry",1);
	damage2 = (int)me->query_skill("qingmang-jian",1);
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || damage_bonus < 100) return 0;
	if( random(ap) > dp/8 && me->query("jiali")>0 && random(6)==1) 
	{
		victim->receive_damage("qi", damage2+damage_bonus/2 ,me);
		victim->receive_wound("qi", damage2+damage_bonus/2 ,me);
		me->add("neili",-100);
//		if (!victim->is_busy()) victim->start_busy(1);
		return HIR "只见$N剑尖如同蟒蛇一般，招招剑走螺旋，剑光越缠越紧！$n喘不过气来，胸闷不已。\n" NOR;
	}
}