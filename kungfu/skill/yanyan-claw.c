// This is player's own skill (Write by Lonely@nt2)
// Create by ������(Owoi) at Mon Jan  4 02:09:10 2021
// �����ݽ���צ(yanyan-claw.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : ".",
	"attack" : 225,
	"damage" : 225,
	"force" : 220,
	"dodge" : 229,
	"parry" : 220,
	"lvl" : 0,
	"damage_type" : "����",
	"skill_name" : "�������滨"
 ]),
// ZHAOSHI : 1
});

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�����ݽ���צ"+"��\n");
	return 1;
}

int valid_enable(string usage) { 
	return usage == "claw" || 
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
	level = (int)me->query_skill("yanyan-claw",1);
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

	lvl = me->query_skill("yanyan-claw", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}
 
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} 

string perform_action_file(string action) 
{
	return __DIR__ + "yanyan-claw" + "/" + action; 
}

string query_description()
{
	return
 "" ; 
}
