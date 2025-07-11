//飞仙剑诀	上乘武学400~1000
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;
mapping *action = ({
    ([
      "action":
"$N手腕一抖，$w剑尖化为五道白光，分别向$n的咽喉、左右肩、和左右脚腕疾刺",
			"force" : 400,
	        "attack": 180,
	            "dodge" : 110,
	        "parry" : 120,
	        "damage": 170,
			 "sword": 100,
      "damage_type":    "刺伤",
      ]),
    ([
      "action":
"$N脚下步步生莲，手中$w在身前一划,一片扇形白光向$n扑去。\n"
"$n识得这招「轻罗小扇」的威力，连忙躲避不迭",
		"force" : 380,
	        "attack": 190,
	            "dodge" : 150,
	        "parry" : 130,
	        "damage": 160,
			 "sword": 110,
      "damage_type":    "割伤",
      ]),
    ([
      "action":
"$N纵身跃起，手中$w带起万道银光，向$n的面门点去。\n"
"这招「乱洒星罗」果然把$n逼得手忙脚乱",
		"force" : 450,
	        "attack": 185,
	            "dodge" : 130,
	        "parry" : 150,
	        "damage": 200,
			 "sword": 150,
      "damage_type":    "刺伤",
      ]),
        
    ([
      "action":
"$N身如被狂风所吹,裙裾飘飘，手中$w向$n轻点数下！\n"
"这招「姑射仙人」玄妙非常，大有仙气,$n简直惊呆了",
		"force" : 500,
	        "attack": 200,
	            "dodge" : 180,
	        "parry" : 170,
	        "damage": 190,
			 "sword": 170,
      "damage_type":    "刺伤",
      ]),
    ([
      "action":
"$N长袖飘舞,身形急转,转眼间就成了一片白雾。一道剑光从白雾中击向$n!\n"
"这招「月下轻舞」先保己,后伤敌,已立于不败之地",
		"force" : 550,
	        "attack": 180,
	            "dodge" : 200,
	        "parry" : 200,
	        "damage": 200,
			 "sword": 230,
      "damage_type":    "刺伤",
      ]),
    ([
      "action":
"$N身随剑走，迅速无伦地在$n周围布下一道剑网。\n"
"$n只见周围无数人影，随时都有可能有一柄$w从意想不到的\n"
"位置刺来，实在是危机重重",
		"force" : 600,
	        "attack": 230,
	            "dodge" : 210,
	        "parry" : 220,
	        "damage": 270,
			 "sword": 260,
      "damage_type":    "刺伤",
      ]),
});

int valid_learn(object me)
{
    object ob;
// 	if (!wizardp(me))
//		return notify_fail("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	   
    if (me->query("family/family_name")!="白云城" && me->query("family/family_name")!="白云城")
        return notify_fail("你不是白云传人,无法修习这种玄妙剑法。\n");
    if ((int)me->query("int",1) < 30)
        return notify_fail("飞仙剑诀非悟性绝顶之人，是无法领悟的！\n");	
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的真气不足，难以领悟剑法的精妙之处。\n");
 	if ((int)me->query_skill("jingyi-shengong", 1) < 100)
		return notify_fail("你的净衣神功不够，学不了飞仙剑诀。\n");   
    if (!(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword" )
        return notify_fail("你必须先找一把剑才能练剑法。\n");
	
	
    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("feixian-jian",1)) > 399 && me->query("neili") > 150 && me->query("jiali")>1000 && random(20)>15 )
        {
                me->add("neili", -150);
                return ([
        "action": ""HIB"忽然$N顿悟飞仙剑诀的无上剑意，使出「天外飞仙」，手中$w"HIG"紫气浩荡。\n"
        "$n"HIG"只见紫气浩荡几万里，一剑西来！这一剑妙到毫巅，根本无法抵御。\n"NOR"",
		"dodge":	230,
		"parry":	300,	
		"attack":	280,	
        "force":	700,
        "damage":	270,
		 "sword":	400,
        "damage_type": "刺伤"]);
		
        }
	
        return action[random(sizeof(action))];
}
/*
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
*/
int practice_skill(object me)
{
//		if (!wizardp(me))
//		return notify_fail("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
    if (me->query("family/family_name")!="白云城" && me->query("family/family_name")!="白云城")
        return notify_fail("你不是白云弟子,无法修习这种武功。\n");
    if ((int)me->query("int",1) < 30)
        return notify_fail("飞仙剑诀非悟性绝顶之人，是无法领悟的！\n");	
    if ((int)me->query("qi") < 30)
        return notify_fail("你的气太低，再练下去会有危险的！\n");
    if ((int)me->query("neili") < 35)
        return notify_fail("你的内力不够，没有办法运用飞仙剑诀。\n");
//	       if( (string)me->query("gender") != "女性" )
//                return notify_fail("自从白云城主消失之后，飞仙剑诀就只传女不传男了。\n");   
    me->receive_damage("qi", 40);
        me->add("neili", -45);

    return 1;
}


string perform_action_file(string action)
{
return __DIR__"feixian-jian/"+action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int ap,dp,damage2;
	ap = me->query("int",1) * me->query_skill("feixian-jian",1);
	dp = victim->query("dex",1) * victim->query_skill("parry",1);
	damage2 = (int)me->query_skill("feixian-jian",1)+(int)me->query_skill("sword",1);
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("jingyi-shengong",1) < 100)	 return 0;
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || me->query_skill_mapped("force") != "jingyi-shengong") return 0;	
	if (damage2<10) damage2=10;
    if( random(ap) > dp/10 && random(6)==0 && me->query("jiali")>0) 
	{
        victim->receive_wound("qi", damage2+damage_bonus,me );
		victim->receive_damage("qi", damage2+damage_bonus,me );
		me->add("neili",-100);
        return HIW "$n耳边响起" HIC"“月圆之夜”" HIM"“紫禁之巅”" HIB"“一剑西来”" HIY"“天外飞仙”！"MAG"$n已被$N的天外飞仙剑气所伤！\n"NOR;
    }
}
