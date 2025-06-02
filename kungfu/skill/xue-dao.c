// xue-dao.c Ѫ��
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N�߾�����$w,ʹ��һ�С�ĥ��˱Ѫ����һ��б��$n��$l  ",
	"skill_name" : "ĥ��˱Ѫ",
	"force" : 300,
	"attack": 170,
	"dodge" : 30,
	"parry" : 25,
	"lvl" : 0,
	"damage" : 170,
	"damage_type" : "����",
]),
([      "action" : "$N�͵�һ����ʹһ�С���Ѫ���ء�������$w����$n�Ĵ���  ",
	"skill_name" : "��Ѫ����",
	"force" : 340,
	"attack": 175,
	"dodge" : 45,
	"parry" : 35,
	"lvl" : 40,
	"damage" : 175,
	"damage_type" : "����",
]),
([      "action" : "$N���һ�㣬ʹ����Ѫ��ãã�����������϶���ֱ��$n��$l  ",
	"skill_name" : "Ѫ��ãã",
	"force" : 380,
	"attack": 190,
	"dodge" : 52,
	"parry" : 40,
	"lvl" : 60,
	"damage" : 180,
	"damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�Ż����Ѫ������$w��������һ��ѹ��$n  ",
	"skill_name" : "Ż����Ѫ",
	"force" : 420,
	"attack": 195,
	"dodge" : 58,
	"parry" : 42,
	"lvl" : 80,
	"damage" : 190,
	"damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ����ʹ����Ѫ�����ˡ�����$wֱ��$n��$l  ",
	"skill_name" : "Ѫ������",
	"force" : 350,
	"attack": 200,
	"dodge" : 65,
	"parry" : 45,
	"lvl" : 90,
	"damage" : 200,
	"damage_type" : "����",
]),
([      "action" : "$Nʹ����Ѫ���߰ߡ�������б�̣���Ȼ����һ����ն$n������  ",
	"skill_name" : "Ѫ���߰�",
	"force" : 380,
	"attack": 205,
	"dodge" : 70,
	"parry" : 60,
	"lvl" : 100,
	"damage" : 210,
	"damage_type" : "����",
]),
([      "action" : "$Nʹһʽ����Ѫ��Ѫ�����ӵ�ֱָ$n���ؿ�",
	"skill_name" : "��Ѫ��Ѫ",
	"force" : 400,
	"attack": 210,
	"dodge" : 80,
	"parry" : 55,
	"lvl" : 120,
	"damage" : 230,
	"damage_type" : "����",
]),
([      "action" : "$N������㣬ʹ��һ�С�Ѫ�����桹��ת���$w����$n������",
	"skill_name" : "Ѫ������",
	"force" : 420,
	"attack": 220,
	"dodge" : 90,
	"parry" : 60,
	"lvl" : 150,
	"damage" : 235,
	"damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ����̫ǳ��\n");

	if ((int)me->query_skill("blade", 1) < 80)
		return notify_fail("��Ļ���������򲻹����޷���ϰѪ����\n");

	if ((int)me->query_skill("blade", 1) < (int)me->query_skill("xue-dao", 1))
		return notify_fail("��Ļ�������ˮƽ���ޣ��޷���ϰ���Ӹ����Ѫ����\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
/* 	int i, level;
	level = (int) me->query_skill("xue-dao",1);
	for(i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)]; */
    if (random(5) == 0)
	{
	return ([
	"action": HIM  "$N" HIM"а�Դ󷢣�����һת����ʱ���ʤ����������������Ѫ����ӿ��"NOR"\n",
	"attack": 300,
	"dodge" : 150,
	"parry" : 150,
    "damage": 400,
	"force" : 680,
	"damage_type": "����"]);
	}

	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("�������������������Ѫ����\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("�������������������Ѫ����\n");

	me->receive_damage("qi", 60);
	me->add("neili", -63);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 7)
	{
		victim->receive_wound("qi", damage_bonus / 6, me);
		return HIR "ֻ��" + victim->name() +  HIR "һ���ҽУ��ѱ�Ѫ��������ˣ�"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"xue-dao/" + action;
}
