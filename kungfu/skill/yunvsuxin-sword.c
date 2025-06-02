// This is player's own skill (Write by Lonely@nt2)
// Create by ¶ÎÇàÖñ(Owoi) at Sun Nov 22 11:08:18 2020
// ÓñÅ®ËØÐÄ½£(yunvsuxin-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "[1;32m$N×ÝÉíÒ»Ô¾£¬ÊÖÎÕ$w½££¬¶ÙÊ±Ò»Ê½[»¨ÎèéäÇé]¶Ô×¼[1;32m$n[1;32mÐ¡¸¹ÇáÇáµØ´ÌÁËÈý½£",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 0,
	"damage_type" : "´ÌÉË",
	"skill_name" : "»¨Ð»éäÇé"
 ]),
// ZHAOSHI : 1
([      "action" : "[1;37m$N×ÝÉíÒ»Ô¾£¬ÊÖÎÕ$w[1;37m£¬¶ÙÊ±Ò»Ê½[ÔÂÎè¶àÇé]¶Ô×¼$n[1;37mÐ¡¸¹ÇáÇáµØ´ÌÁË¾ÅÊ®¾Å½£¡£",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 12,
	"damage_type" : "´ÌÉË",
	"skill_name" : "ÔÂÎè¶àÇé"
 ]),
// ZHAOSHI : 2
([      "action" : "[1;35m$N×ÝÉíÒ»Ô¾£¬ÊÖÎÕ$w[1;35m£¬¶ÙÊ±Ò»Ê½[»¨ÎèÎÞÇé]¶Ô×¼$n[1;35mÉñÁéÑ¨ÇáÇáµØ´ÌÁË¾ÅÊ®¾Å½£",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 20,
	"damage_type" : "´ÌÉË",
	"skill_name" : "»¨ÎèÎÞÇé"
 ]),
// ZHAOSHI : 3
([      "action" : "[1;37m$N×ÝÉíÒ»Ô¾£¬ÊÖÎÕ$w[1;37m£¬¶ÙÊ±Ò»Ê½[»¨Ð»éäÇé]¶Ô×¼$n[1;31mÐÄ¿ÚÖØÖØµØ´ÌÁË¾Å½£",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 30,
	"damage_type" : "´ÌÉË",
	"skill_name" : "»¨Ð»éäÇé"
 ]),
// ZHAOSHI : 4
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·" + "ÓñÅ®ËØÐÄ½£" + "¡£\n");
		
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
	level = (int)me->query_skill("yunvsuxin-sword",1);
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

	lvl = me->query_skill("yunvsuxin-sword", 1);
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
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");     
	
	if( (int)me->query("qi") < 25 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
		
	if( (int)me->query("neili") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
		
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} 

string perform_action_file(string action) 
{
	return __DIR__ + "yunvsuxin-sword" + "/" + action; 
}
