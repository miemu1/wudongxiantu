// This is player's own skill (Write by Lonely@nt2)
// Create by 李长夜(Aaa12345_1) at Tue May 23 15:09:05 2023
// 诛仙剑(xxx-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N一跃而起，手腕一抖，挽出一个神鬼莫测的剑花，飞向$n。只见$N人剑合一，穿向$n，$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！",
	"attack" : 206,
	"damage" : 205,
	"force" : 207,
	"dodge" : 205,
	"parry" : 207,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "戮仙"
 ]),
// ZHAOSHI : 1
([      "action" : "$N一声剑来，手握$w，顿时一招「天下归一」对准$n的$l刺出万剑",
	"attack" : 1270,
	"damage" : 1337,
	"force" : 1267,
	"dodge" : 1270,
	"parry" : 1267,
	"lvl" : 12,
	"damage_type" : "刺伤",
	"skill_name" : "天下归一"
 ]),
// ZHAOSHI : 2
([      "action" : "$N一声剑来，手握$w，顿时一招「万剑归宗」对准$n的$l刺出无数剑影",
	"attack" : 1280,
	"damage" : 1347,
	"force" : 1277,
	"dodge" : 1280,
	"parry" : 1277,
	"lvl" : 20,
	"damage_type" : "刺伤",
	"skill_name" : "戮仙"
 ]),
// ZHAOSHI : 3
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练" + "诛仙剑" + "。\n");
		
	return 1;
}

int valid_enable(string usage) { 
	return usage == "sword" || 
	       usage == "parry"; 
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
	level = (int)me->query_skill("xxx-sword",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed *query_actions() { return action; }

int query_effect_parry(object attacker, object me)
{
	int lvl;

	if (me->query_temp("weapon"))
		return 0;

	lvl = me->query_skill("xxx-sword", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
	object weapon; 
	if (!objectp(weapon = me->query_temp("weapon")) || 
		(string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");     
	
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
		
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
		
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} 

string perform_action_file(string action) 
{
	return __DIR__ + "xxx-sword" + "/" + action; 
}
