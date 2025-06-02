// tianyu-qijian.c �����潣

inherit SKILL;

mapping *action = ({
([	"action":"$Nʹһʽ������һ�ߡ�������$w����΢�񣬻ó�һ���������$n��$l",
	"force" : 360,
	"dodge" : 50,
	"damage": 150,
	"lvl" : 0,
	"skill_name" : "����һ��",
	"damage_type":	"����"
]),
([	"action":"$N����ǰ��ʹ�������羪�硹������$w����һ����������$n��$l",
	"force" : 370,
	"dodge" : 60,
	"damage": 155,
	"lvl" : 30,
	"skill_name" : "���羪��",
	"damage_type":	"����"
]),
([	"action":"$N����$wһ����һ�С����ھ��졹��ббһ�������ó�������$n��$l",
	"force" : 380,
	"dodge" : 65,
	"damage": 160,
	"lvl" : 40,
	"skill_name" : "���ھ���",
	"damage_type":	"����"
]),
([	"action":"$N���н����ॳ���һ����һʽ��������ġ���һ���������$n��$l",
	"force" : 390,
	"dodge" : 70,
	"damage": 165,
	"lvl" : 50,
	"skill_name" : "�������",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ��ŭ���񻨡�������$w�������������ʹ$n�Ѷ���ʵ���޿ɶ��",
	"force" : 420,
	"dodge" : 75,
	"damage": 160,
	"lvl" : 60,
	"skill_name" : "ŭ����",
	"damage_type":	"����"
]),
([	"action":"$N����$wбָ���죬��â���£�һʽ���Ż����ա�����׼$n��$lбб����",
	"force" : 440,
	"dodge" : 85,
	"damage": 165,
	"lvl" : 70,
	"skill_name" : "�Ż�����",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ�������ѩ�������󼱶�������������⣬����$n��$l",
	"force" : 460,
	"dodge" : 95,
	"damage": 160,
	"lvl" : 80,
	"skill_name" : "�����ѩ",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ����ӵ�к����$w��ն�������缲�������$n���ؿ�",
	"force" : 490,
	"dodge" : 105,
	"damage": 255,
	"lvl" : 100,
	"skill_name" : "��ӵ�к",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ��������ɡ���$wͻȻ���������һƬ���Χ��$nȫ��",
	"force" : 510,
	"dodge" : 115,
	"damage": 300,
	"lvl" : 120,
	"skill_name" : "�������",
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_skill("force") < 40)
		return notify_fail("����ڹ���򲻹�������ѧϰ�����潣��\n");

	if (me->query("max_neili") < 200)
		return notify_fail("�����������������ѧϰ�����潣��\n");

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
	// int i, level;
	// level = (int) me->query_skill("tianyu-qijian",1);
	// for(i = sizeof(action); i > 0; i--)
		// if(level > action[i-1]["lvl"])
			// return action[NewRandom(i, 20, level/5)];
		
	if (random(5) == 0)
	{
	return ([
    "action": HIW "ֻ��һ��������$N����Ȼ�ӿ죬������â���²��������⻯�����⻯����"
		      "����$w�����һ��ݳ���"NOR"\n",
	"attack": 300,
	"dodge" : 100,
	"parry" : 100,
    "damage": 400,
	"force" : 580,
	"damage_type": "����"]);
	}

	return action[random(sizeof(action))];	
		
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon;
	
	if (random(10) < 6)
	{
			victim->receive_wound("qi", damage_bonus / 6, me);
		return HIC "$N" HIC "Ĭ�����������ⶸȻ����������²�������â��$n" HIC "һ�����죬�ѱ���â���ˣ�"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("������������������潣��\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("������������������潣��\n");

	me->receive_damage("qi", 40);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}
