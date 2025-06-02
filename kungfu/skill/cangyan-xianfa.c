// cangyan-xianfa.c �����ɷ�

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С����ƺ�����$w�ƻó�ƬƬ���ɫ���ƣ�����˷�������$n",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 0,
	"skill_name" : "���ƺ�",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ӿ����������ָ������$n��$n�������ֱܷ�$w����·",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 20,
	"skill_name" : "����ӿ",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ���������衹��$w��һ������������һ�ɺ�������$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 40,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С����ƶ���������$w����һ�Ž���������$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 60,
	"skill_name" : "���ƶ�",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С������١������Ծ����أ�����$w�ó�һ�����ɫ���ٲ���ɨ��$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 80,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С����Ƽš�������������ɫ�������Ĵ���$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 100,
	"skill_name" : "���Ƽ�ɫ",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С������ҡ���������ָ������$n��$n�������ֱܷ�$w����·",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1000,
	"lvl"    : 120,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ��������֮Ϣ����$w��һ������������һ������������$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1500,
	"lvl"    : 140,
	"skill_name" : "����֮Ϣ",
	"damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С�������׹��������$w����һ�Ž���������$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1500,
	"lvl"    : 160,
	"skill_name" : "������׹",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С������޺ۡ������Ծ����أ�����$w�ó�һ�����ɫ�Ľ��ۣ�ɨ��$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 1500,
	"lvl"    : 180,
	"skill_name" : "�����޺�",
	"damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С����׽�Ϣ��������������ɫ�������Ĵ���$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 2000,
	"lvl"    : 200,
	"skill_name" : "���׽�Ϣ",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С��������𡹣�$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
	"force"  : 100,
	"attack" : 100,
	"dodge"  : 100,
	"parry"  : 100,
	"damage" : 3000,
	"lvl"    : 220,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100000)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force") < 600)
		return notify_fail("����ڹ����̫ǳ��\n");

	if ((int)me->query_skill("sword", 1) < 600)
		return notify_fail("��Ļ���������򲻹����޷�ѧϰ�����ɷ���\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("cangyan-xianfa", 1))
		return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ĳ����ɷ���\n");

	return 1;
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
	level   = (int) me->query_skill("cangyan-xianfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 100000)
		return notify_fail("�������Ŀǰû�а취��ϰ�����ɷ���\n");

	if ((int)me->query("neili") < 10000)
		return notify_fail("��������������޷���ϰ�����ɷ���\n");
	
	me->add("qi", -10000);
	me->add("neili", -10000);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"cangyan-xianfa/" + action;
}


