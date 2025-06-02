// lianyu-mojing ����ħ��

inherit SKILL;

mapping *action = ({
([	"action" : "ֻ��$����$nʹ��һ����­",
	"force"  : 100,
	"dodge"  : 100,
	"damage" : 1000,
	"lvl"    : 0,
	"skill_name" : "��­",
	"damage_type" : "������ʴ"
]),
([	"action" : "$N����$nʹ��һ�жϹ�",
	"force"  : 200,
	"dodge"  : 200,
	"damage" : 2000,
	"lvl"    : 20,
	"skill_name" : "�Ϲ�",
	"damage_type" : "������ʴ"
]),
([	"action" : "$N����$nʹ��һ�����",
	"force"  : 300,
	"dodge"  : 300,
	"damage" : 3000,
	"lvl"    : 40,
	"skill_name" : "���",
	"damage_type" : "������ʴ"
]),
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

//int valid_combine(string combo) { return combo == "canhe-zhi"; }

int valid_learn(object me)
{
	if (objectp(me))
		return notify_fail("����ħ������������\n");
	if ((int)me->query_skill("force") < 600)
		return notify_fail("����ڹ���򲻹����޷�������ħ����\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������̫�����޷�������ħ����\n");
	if (me->query_skill("cuff", 1) < me->query_skill("lianyu-mojing", 1))
		return notify_fail("��Ļ���ȭ���������ޣ��޷��������������ħ����\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("lianyu-mojing", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 20, level * 5 /1)];
}

int practice_skill(object me)
{

if (objectp(me))
		return notify_fail("����ħ������������\n");

	if ((int)me->query("qi") < 15000)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 1500)
		return notify_fail("�����������������ħ����\n");

	me->receive_damage("qi", 50);
	me->add("neili", -1500);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"lianyu-mojing/" + action;
}

