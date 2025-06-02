//xiantian-qiangjue.c ��ƽǹ��

#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N˫��һ�𣬾���ǰ�죬ʹ��һ�С��ƿա�������$wƽƽֱ��������$n��$l",
	"force" : 100,
	"dodge": -5,
	"damage": 1000,
	"skill_name" : "�ƿ�",
	"damage_type": "����"
]),
([	"action": "$N����$w������ת���������������¶ף�����һ�С����ɡ�������$n��$l��ȥ",
	"force" : 200,
	"dodge": -10,
	"damage": 2000,
	"skill_name" : "����",
	"damage_type": "����"
]),
([	"action": "$N����$w������һ��ǹ����һ�С���ŭ����$n��ǰ��ȥ",
	"force" : 300,
	"dodge": -15,
	"damage": 3000,
	"skill_name" : "��ŭ",
	"damage_type": "����"
]),
([	"action": "$Nһ�С�������������$w����СȦ��ȥ$n�ĺ��У�����$w΢̧��ָ��$n��$l",
	"force" : 400,
	"dodge": -25,
	"damage": 4000,
	"skill_name" : "����",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="spear" ||  usage=="parry"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 100)
		return notify_fail("�����������������ǹ����\n");

	me->receive_damage("qi", 50);
	return 1;
}
