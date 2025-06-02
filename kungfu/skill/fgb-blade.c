// This is player's own skill (Write by Lonely@nt2)
// Create by �Ǻ�(Z3414932604) at Thu Oct  1 07:34:20 2020
// ��ǿ����ɾ�(fgb-blade.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "Y",
	"attack" : 176,
	"damage" : 172,
	"force" : 171,
	"dodge" : 184,
	"parry" : 171,
	"lvl" : 0,
	"damage_type" : "����",
	"skill_name" : "��Х����"
 ]),
// ZHAOSHI : 1
([      "action" : "Y",
	"attack" : 176,
	"damage" : 172,
	"force" : 171,
	"dodge" : 184,
	"parry" : 171,
	"lvl" : 12,
	"damage_type" : "����",
	"skill_name" : "̤������"
 ]),
// ZHAOSHI : 2
([      "action" : "Y",
	"attack" : 176,
	"damage" : 172,
	"force" : 171,
	"dodge" : 184,
	"parry" : 171,
	"lvl" : 20,
	"damage_type" : "����",
	"skill_name" : "���Ӻ���"
 ]),
// ZHAOSHI : 3
([      "action" : "Y",
	"attack" : 176,
	"damage" : 172,
	"force" : 171,
	"dodge" : 184,
	"parry" : 171,
	"lvl" : 30,
	"damage_type" : "����",
	"skill_name" : "��������"
 ]),
// ZHAOSHI : 4
([      "action" : "Y",
	"attack" : 176,
	"damage" : 172,
	"force" : 171,
	"dodge" : 184,
	"parry" : 171,
	"lvl" : 40,
	"damage_type" : "����",
	"skill_name" : "��������"
 ]),
// ZHAOSHI : 5
([      "action" : "Y",
	"attack" : 176,
	"damage" : 172,
	"force" : 171,
	"dodge" : 184,
	"parry" : 171,
	"lvl" : 50,
	"damage_type" : "����",
	"skill_name" : "�ƽ���"
 ]),
// ZHAOSHI : 6
([      "action" : "Y",
	"attack" : 176,
	"damage" : 172,
	"force" : 171,
	"dodge" : 184,
	"parry" : 171,
	"lvl" : 60,
	"damage_type" : "����",
	"skill_name" : "��������"
 ]),
// ZHAOSHI : 7
([      "action" : "Y",
	"attack" : 176,
	"damage" : 172,
	"force" : 171,
	"dodge" : 184,
	"parry" : 171,
	"lvl" : 80,
	"damage_type" : "����",
	"skill_name" : "ѩ������"
 ]),
// ZHAOSHI : 8
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade") 
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���" + "��ǿ����ɾ�" + "��\n");
		
	return 1;
}

int valid_enable(string usage) { 
	return usage == "blade" || 
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
	level = (int)me->query_skill("fgb-blade",1);
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

	lvl = me->query_skill("fgb-blade", 1);
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
		(string)weapon->query("skill_type") != "blade") 
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
	return __DIR__ + "fgb-blade" + "/" + action; 
}
