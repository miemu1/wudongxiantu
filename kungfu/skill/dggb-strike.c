// This is player's own skill (Write by Lonely@nt2)
// Create by 渡大(Lin111) at Thu Aug 13 20:02:41 2020
// 动感光波掌(dggb-strike.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N两脚点地，屁股用力，一招[动感波波]",
	"attack" : 183,
	"damage" : 193,
	"force" : 196,
	"dodge" : 191,
	"parry" : 196,
	"lvl" : 0,
	"damage_type" : "内伤",
	"skill_name" : "怪物充能"
 ]),
// ZHAOSHI : 1
([      "action" : "Y",
	"attack" : 264,
	"damage" : 274,
	"force" : 277,
	"dodge" : 272,
	"parry" : 277,
	"lvl" : 12,
	"damage_type" : "内伤",
	"skill_name" : "是"
 ]),
// ZHAOSHI : 2
([      "action" : "$N两腿一蹬，屁股用力，手一指天。一舵粑粑天上来",
	"attack" : 264,
	"damage" : 274,
	"force" : 277,
	"dodge" : 272,
	"parry" : 277,
	"lvl" : 20,
	"damage_type" : "内伤",
	"skill_name" : "一舵粑粑天上来"
 ]),
// ZHAOSHI : 3
([      "action" : "满头冒星星",
	"attack" : 264,
	"damage" : 274,
	"force" : 277,
	"dodge" : 272,
	"parry" : 277,
	"lvl" : 30,
	"damage_type" : "内伤",
	"skill_name" : "响亮的一耳瓜子"
 ]),
// ZHAOSHI : 4
([      "action" : "往死了干",
	"attack" : 264,
	"damage" : 274,
	"force" : 277,
	"dodge" : 272,
	"parry" : 277,
	"lvl" : 40,
	"damage_type" : "内伤",
	"skill_name" : "大金链子勒脖子"
 ]),
// ZHAOSHI : 5
([      "action" : "名字很长很长~",
	"attack" : 264,
	"damage" : 274,
	"force" : 277,
	"dodge" : 272,
	"parry" : 277,
	"lvl" : 50,
	"damage_type" : "内伤",
	"skill_name" : "天灵灵地灵灵我家小猫快显灵嘛哩嘛哩哄小狗小猫都显灵地下冒个牙签崽扎到坏人指甲缝"
 ]),
// ZHAOSHI : 6
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"动感光波掌"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"动感光波掌"+"。\n");
	return 1;
}

int valid_enable(string usage) { 
	return usage == "strike" || 
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
	level = (int)me->query_skill("dggb-strike",1);
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

	lvl = me->query_skill("dggb-strike", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
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
	return __DIR__ + "dggb-strike" + "/" + action; 
}
