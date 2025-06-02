// youzhi-jian.c ���S��

inherit SKILL;

mapping *action = ({
([      "action": "$N�����Ჽ��������������$n��ǰ���漴����$w΢��"
		   "���⼲����$n��$l",
	"force" : 320,
	"attack": 141,
	"parry" : 40,
	"dodge" : 31,
	"damage": 160,
	"lvl"   : 0,
	"damage_type" : "����"
]),
([      "action": "$Nб��һ�������ֻӽ��������һ��һ�̵Ĺ�Ӱ"
		   "ֱ��$n��$l",
	"force" : 340,
	"attack": 152,
	"parry" : 41,
	"dodge" : 42,
	"damage": 162,
	"lvl"   : 10,
	"damage_type" : "����"
]),
([      "action": "$Nһ�д̳���$wͻȻ�����ַ��ֲ岻�ؽ����У��漴ת������"
		   "��ȥ��$n��ʱ�Ÿо�����һ�����α����Լ���$l",
	"force" : 350,
	"attack": 158,
	"parry" : 45,
	"dodge" : 43,
	"damage": 170,
	"lvl"   : 20,
	"damage_type" : "����"
]),
([      "action": "$N˫�־ٽ����죬һ�С�����ţ�����»�����$w��������ѾѾѧ����϶�����"
		   "$n��ͷ­��ȥ",
	"force" : 370,
	"attack": 161,
	"parry" : 48,
	"dodge" : 48,
	"damage": 165,
	"lvl"   : 40,
	"damage_type" : "����"
]),
([      "action": "$Nʩչ����Ϊ��ɰ���������$w���΢΢һЦ��$nֻ����һ����ȴ��"
		   "һ����Ӱ�������ΰ�Ϯ���Լ���$l�����Լ�ȴû����$N��ʱ�����֣���",
	"force" : 390,
	"attack": 168,
	"parry" : 51,
	"dodge" : 50,
	"damage": 170,
	"lvl"   : 60,
	"damage_type" : "����"
]),
([      "action": "$N���̤ʵ���ҽŲȿգ�һ�С�����ʺ����$w����һ�Ž�����Ʈ��"
		   "�����ر���$n��$l",
	"force" : 400,
	"attack": 171,
	"parry" : 55,
	"dodge" : 55,
	"damage": 175,
	"lvl"   : 80,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С���ţ���١��������ḧ$w���漴�͵�һ����������ǰһ�ݣ�"
		   "ֻ��һ����˸�����Ľ�ӰѸ�ٴ���$n��$l",
	"force" : 400,
	"attack": 178,
	"parry" : 60,
	"dodge" : 62,
	"damage": 170,
	"lvl"   : 100,
	"damage_type" : "����"
]),
([      "action": "$N������ף���ɫ��Ȼ��һ�С������۸��ҡ���$w�������Ʋ����ش���"
		   "$n��$l",
	"force" : 350,
	"attack": 181,
	"parry" : 64,
	"dodge" : 65,
	"damage": 170,
	"lvl"   : 110,
	"damage_type" : "����"
]),
([      "action": "$N�������棬һ�С��ҿ޸����ǿ���������$wб���»�����$n΢����֣�����"
		   "�ɼ䣬ȴ��$N���е�$w�ѷ������ϣ�ֱ���Լ����ʺ�",
	"force" : 380,
	"attack": 184,
	"parry" : 68,
	"dodge" : 75,
	"damage": 169,
	"lvl"   : 120,
	"damage_type" : "����"
]),
});


int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 900)
		return notify_fail("��������������޷�ѧϰ���S����\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ���򲻹����޷�ѧϰ���S����\n");

	if ((int)me->query_skill("sword", 1) < 100)
		return notify_fail("��Ļ���������򲻹����޷�ѧϰ���S����\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("youzhi-jian", 1))
		return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ĳ��S����\n");

		if (me->query("int") < 26)
		return notify_fail("����������̫��޷�ѧϰ���S����\n");

    return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level = (int) me->query_skill("youzhi-jian", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 60)
		return notify_fail("����������������S����\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("����������������S����\n");

	me->receive_damage("qi", 45);
	me->add("neili", -66);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 7)
	{
		victim->receive_wound("qi", damage_bonus / 6);
		return HIW "$n�������ߴ���һ������������ʱѪ��������һ���������Ķ�����"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"youzhi-jian/" + action;
}
