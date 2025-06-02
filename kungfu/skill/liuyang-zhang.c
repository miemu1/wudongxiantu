// SKILL liuyang-zhang.c

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С������۽𡹣����Ƶ�������֮�ϣ�����$n",
	"force" : 300,
	"attack": 152,
	"dodge" : 30,
	"parry" : 1,
	"damage": 180,
	"lvl"   : 0,
	"skill_name" : "�����۽�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������ƶ���������ɫ���أ�˫����ƮƮ������$n",
	"force" : 300,
	"attack": 158,
	"dodge" : 25,
	"parry" : 3,
	"damage": 180,
	"lvl"   : 20,
	"skill_name" : "�����ƶ���",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���б��·��ϼ������˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
	"force" : 300,
	"attack": 162,
	"dodge" : 43,
	"parry" : 4,
	"damage": 180,
	"lvl"   : 30,
	"skill_name" : "��б��·��ϼ��",
	"damage_type" : "����"
]),

([	"action" : "$Nһ�С���������������$n��$l��������",
	"force" : 310,
	"attack": 165,
	"dodge" : 55,
	"parry" : 8,
	"damage": 180,
	"lvl"   : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����һ���ͽ��ѡ���ֻ��һƬ��Ӱ����$n",
	"force" : 350,
	"attack": 172,
	"dodge" : 52,
	"parry" : 0,
	"damage": 180,
	"lvl"   : 60,
	"skill_name" : "����һ���ͽ���",
	"damage_type" : "����"
]),

([	"action" : "$N˫��ƽ�ӣ�һ�С���ϼ���������$n",
	"force" : 400,
	"attack": 173,
	"dodge" : 65,
	"parry" : 11,
	"damage": 180,
	"lvl"   : 80,
	"skill_name" : "��ϼ������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����ղγ��֡���ֻ��һƬ��Ӱ����$n",
	"force" : 410,
	"attack": 178,
	"dodge" : 63,
	"parry" : 5,
	"damage": 180,
	"lvl"   : 100,
	"skill_name" : "���ղγ���",
	"damage_type" : "����"
]),

([	"action" : "$N������Σ�����һ�ǡ���ϼ��Ѧᡡ�����$n��ͷ��",
	"force" : 430,
	"attack": 185,
	"dodge" : 77,
	"damage": 290,
	"parry" : 12,
	"lvl"   : 120,
	"skill_name" : "��ϼ��Ѧ�",
	"damage_type" : "����"
]),
([	"action" : "$Nʩ��������������������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 460,
	"attack": 191,
	"dodge" : 80,
	"parry" : 15,
	"damage": 310,
	"lvl"   : 140,
	"skill_name" : "���������",
	"damage_type" : "����"
]),
([	"action" : "$Nʩ���������������˫��ͬʱ����$n��$l",
	"force" : 500,
	"attack": 202,
	"dodge" : 81,
	"parry" : 10,
	"damage": 330,
	"lvl"   : 160,
	"skill_name" : "�������",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="parry" || usage=="strike"; }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ�����Ʊ�����֡�\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("����ڹ���򲻹����޷��������ơ�\n");

	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷��������ơ�\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("liuyang-zhang", 1))
		return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷������������ɽ�����ơ�\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("liuyang-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("���������������ɽ�����ơ�\n");

	me->receive_damage("qi", 61);
	me->add("neili", -57);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 6)
	{
		victim->receive_wound("qi", damage_bonus / 6, me);
		return HIR "" + victim->name() +  HIR "�ܲ��������ƾ�������ȵļ尾�������ص����ˣ�"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"liuyang-zhang/" + action;
}
