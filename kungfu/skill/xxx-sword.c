// This is player's own skill (Write by Lonely@nt2)
// Create by �ҹ(Aaa12345_1) at Tue May 23 15:09:05 2023
// ���ɽ�(xxx-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$NһԾ��������һ�������һ�����Ī��Ľ���������$n��ֻ��$N�˽���һ������$n��$nֻ��һ���������Ķ�������ͷһ����Ѫ���������",
	"attack" : 206,
	"damage" : 205,
	"force" : 207,
	"dodge" : 205,
	"parry" : 207,
	"lvl" : 0,
	"damage_type" : "����",
	"skill_name" : "¾��"
 ]),
// ZHAOSHI : 1
([      "action" : "$Nһ������������$w����ʱһ�С����¹�һ����׼$n��$l�̳���",
	"attack" : 1270,
	"damage" : 1337,
	"force" : 1267,
	"dodge" : 1270,
	"parry" : 1267,
	"lvl" : 12,
	"damage_type" : "����",
	"skill_name" : "���¹�һ"
 ]),
// ZHAOSHI : 2
([      "action" : "$Nһ������������$w����ʱһ�С��򽣹��ڡ���׼$n��$l�̳�������Ӱ",
	"attack" : 1280,
	"damage" : 1347,
	"force" : 1277,
	"dodge" : 1280,
	"parry" : 1277,
	"lvl" : 20,
	"damage_type" : "����",
	"skill_name" : "¾��"
 ]),
// ZHAOSHI : 3
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���" + "���ɽ�" + "��\n");
		
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
	return __DIR__ + "xxx-sword" + "/" + action; 
}
