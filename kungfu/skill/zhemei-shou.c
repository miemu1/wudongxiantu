// SKILL zhemei-shou.c

inherit SKILL;

mapping *action = ({
([	"action": "$Nһ�С�"+HIG+"��÷��Թ"+NOR+"����˫�ֺ�ӣ�ץ��$n",
	"force" : 380,
	"attack": 150,
	"dodge" : 20,
	"parry" : 25,
	"damage": 180,
	"lvl"   : 0,
	"skill_name" : HIG "��÷��Թ" NOR,
	"damage_type" : "����"
]),
([	"action": "$Nһ�С�"+RED+"�ƻ���Գ�"+NOR+"��������ԾȻ����ץ��$n��ͷ��",
	"force" : 380,
	"attack": 150,
	"dodge" : 20,
	"parry" : 25,
	"damage": 180,
	"lvl"   : 30,
	"skill_name" : RED "�ƻ���Գ�" NOR,
	"damage_type" : "����"
]),
([	"action": "$Nһ�С�"+GRN+"��ɽһ�����ı�"+NOR+"����˫�ַ׷ɣ�$nֻ���ۻ�����",
	"force" : 380,
	"attack": 150,
	"dodge" : 20,
	"parry" : 25,
	"damage": 180,
	"lvl"   : 60,
	"skill_name" : GRN "��ɽһ�����ı�" NOR,
	"damage_type" : "����"
]),
([	"action": "$Nһ�С�"+YEL+"÷��ѩ�串��ƻ"+NOR+"����˫�ֺϻ���$nֻ���޴��ɱ�",
	"force" : 380,
	"attack": 150,
	"dodge" : 20,
	"parry" : 25,
	"damage": 180,
	"lvl"   : 80,
	"skill_name" : YEL "÷��ѩ�串��ƻ" NOR,
	"damage_type" : "����"
]),
([	"action": "$Nһ�С�"+HIC+"������÷��ѩ��"+NOR+"����˫��ƮȻץ��$n",
	"force" : 380,
	"attack": 36,
	"dodge" : 30,
	"parry" : 37,
	"damage": 180,
	"lvl"   : 100,
	"skill_name" : HIC "������÷��ѩ��" NOR,
	"damage_type" : "����"
]),

([	"action": "$N˫��ƽ�٣�һ�С�"+HIW+"����������ŪӰ"+NOR+"������$n",
	"force" : 380,
	"attack": 42,
	"dodge" : 35,
	"parry" : 45,
	"damage": 180,
	"lvl"   : 120,
	"skill_name" : HIW "����������ŪӰ" NOR,
	"damage_type" : "����"
]),
([	"action": "$Nһ�С�"+WHT+"��������ֱ����"+NOR+"��������$n���ƺ�$n��ȫ��������",
	"force" : 380,
	"attack": 47,
	"dodge" : 30,
	"parry" : 41,
	"damage": 185,
	"lvl"   : 140,
	"skill_name" : WHT "��������ֱ����" NOR,
	"damage_type" : "����"
]),

([	"action": "$N������Σ�����һ�ǡ�"+MAG+"����δ�϶��Ⱦ�"+NOR+"������$n��ͷ��",
	"force" : 380,
	"attack": 46,
	"dodge" : 30,
	"parry" : 47,
	"damage": 190,
	"lvl"   : 160,
	"skill_name" : MAG "����δ�϶��Ⱦ�" NOR,
	"damage_type" : "����"
]),
([	"action": "$Nʩ����"+RED+"����Ц��"+NOR+"�������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 380,
	"attack": 58,
	"dodge" : 10,
	"parry" : 55,
	"damage": 350,
	"lvl"   : 170,
	"skill_name" : RED "����Ц��" NOR,
	"damage_type" : "����"
]),
([	"action": "$Nʩ����"+YEL+"��ʯ���"+NOR+"��������һ������$n",
	"force" : 430,
	"attack": 62,
	"dodge" : 20,
	"parry" : 52,
	"damage": 380,
	"lvl"   : 180,
	"skill_name" : YEL "��ʯ���" NOR,
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="parry"|| usage=="hand"; }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ��÷�ֱ�����֡�\n");

	if ((int)me->query("max_neili") < 900)
		return notify_fail("�������̫�����޷�����ɽ��÷�֡�\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("����ڹ���򲻹����޷�����ɽ��÷�֡�\n");

	if ((int)me->query_skill("hand", 1) < 100)
		return notify_fail("��Ļ����ַ���򲻹����޷�����ɽ��÷�֡�\n");

	if ((int)me->query_skill("hand", 1) < (int)me->query_skill("zhemei-shou", 1))
		return notify_fail("��Ļ����ַ�ˮƽ���ޣ��޷������������ɽ��÷�֡�\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("zhemei-shou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("���������������ɽ��÷�֡�\n");

	me->receive_damage("qi", 65);
	me->add("neili", -62);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 6)
	{
		victim->receive_wound("qi", damage_bonus / 6, me);
		return HIC "һ�����죬�·���÷֦�۶ϵ�������"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
//�ȼ��������Ƿ�ѧ���µ���ʽ
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}