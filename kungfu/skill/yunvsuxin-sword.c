// This is player's own skill (Write by Lonely@nt2)
// Create by ������(Owoi) at Sun Nov 22 11:08:18 2020
// ��Ů���Ľ�(yunvsuxin-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "[1;32m$N����һԾ������$w������ʱһʽ[��������]��׼[1;32m$n[1;32mС������ش�������",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 0,
	"damage_type" : "����",
	"skill_name" : "��л����"
 ]),
// ZHAOSHI : 1
([      "action" : "[1;37m$N����һԾ������$w[1;37m����ʱһʽ[�������]��׼$n[1;37mС������ش��˾�ʮ�Ž���",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 12,
	"damage_type" : "����",
	"skill_name" : "�������"
 ]),
// ZHAOSHI : 2
([      "action" : "[1;35m$N����һԾ������$w[1;35m����ʱһʽ[��������]��׼$n[1;35m����Ѩ����ش��˾�ʮ�Ž�",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 20,
	"damage_type" : "����",
	"skill_name" : "��������"
 ]),
// ZHAOSHI : 3
([      "action" : "[1;37m$N����һԾ������$w[1;37m����ʱһʽ[��л����]��׼$n[1;31m�Ŀ����صش��˾Ž�",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 30,
	"damage_type" : "����",
	"skill_name" : "��л����"
 ]),
// ZHAOSHI : 4
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���" + "��Ů���Ľ�" + "��\n");
		
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
		return notify_fail("��ʹ�õ��������ԡ�\n");     
	
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
	return __DIR__ + "yunvsuxin-sword" + "/" + action; 
}
