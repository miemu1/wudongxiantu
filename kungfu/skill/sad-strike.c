inherit SKILL;

#include <ansi.h>

mapping *action = ({
([      "action" : "$Nһ�С�"HIW"�������"NOR"��̧ͷ���죬��������������һ��"
		   "���Լ�ͷ���տ��ĳ�������б�£��������ɻ�\n"
		   "�Σ���ɢ��������$n��$l",
	"force"  : 450,
	"attack" : 140,
	"dodge"  : 40,
	"damage" : 150,
	"lvl"    : 0,
	"skill_name" : "�������",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIG"��������"NOR"���ֱ��´������ް�������ʽ��"
		   "ͻȻ�������붯���������䡢˫��ͷ��������\n"
		   "�ر�������������ʽ����ײ��$n",
	"force"  : 460,
	"attack" : 145,
	"dodge"  : 45,
	"damage" : 155,
	"lvl"    : 10,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIB"�����ˮ"NOR"����������Ʈ����������ˮ������"
		   "ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬����\n"
		   "�빥$n",
	"force"  : 480,
	"attack" : 150,
	"dodge"  : 50,
	"damage" : 150,
	"lvl"    : 20,
	"skill_name" : "�����ˮ",
	"damage_type": "����"
]),

([      "action" : "$Nһ�С�"HIY"��������"NOR"�������ո���ͷ�������£��Ų���"
		   "�أ����������������$n��$l",
	"force"  : 500,
	"attack" : 155,
	"dodge"  : 55,
	"damage" : 155,
	"lvl"    : 40,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIR"��ʬ����"NOR"���߳�һ�š���һ�ŷ���ʱ�л��"
		   "㱣�����ԼԼ���������޵�����$n",
	"force"  : 430,
	"attack" : 160,
	"dodge"  : 60,
	"damage" : 150,
	"lvl"    : 60,
	"skill_name" : "��ʬ����",
	"damage_type": "����"
]),
([      "action" : "$N˫��ƽ�У�һ�С�"HIM"ӹ������"NOR"��û����ɵ�����$n��$l",
	"force"  : 360,
	"attack" : 170,
	"dodge"  : 65,
	"damage" : 155,
	"lvl"    : 80,
	"skill_name" : "ӹ������",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"RED"������ʩ"NOR"��ͻȻ�������࣬ͷ�½��ϣ�����"
		   "���ӣ�һ������$n��$l",
	"force"  : 390,
	"attack" : 180,
	"dodge"  : 70,
	"damage" : 150,
	"lvl"    : 100,
	"skill_name" : "������ʩ",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"YEL"�ľ�����"NOR"����ĿԶ���������鸡����ǰ�Ż�"
		   "������ȫ����ʽ����ѧ�и������޲��Ǻ�",
	"force"  : 420,
	"attack" : 190,
	"dodge"  : 75,
	"damage" : 155,
	"lvl"    : 120,
	"skill_name" : "�ľ�����",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"BLU"������ʳ"NOR"�������鸡�����缸�첻�Բ�˯��"
		   "�ĽŲ��ʲյ�Ϯ��$n�����ԣ����ƺ���ȭ��\n"
		   "��$n��$l",
	"force"  : 460,
	"attack" : 200,
	"dodge"  : 80,
	"damage" : 150,
	"lvl"    : 140,
	"skill_name" : "������ʳ",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIC"�ǻ��չ�"NOR"�����Ҵ�����ʵʵ�Ĺ���$n��$l",
	"force"  : 490,
	"attack" : 210,
	"dodge"  : 85,
	"damage" : 155,
	"lvl"    : 160,
	"skill_name" : "�ǻ��չ�",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"CYN"��������"NOR"������������״������бб����$n��$l",
	"force"  : 520,
	"attack" : 225,
	"dodge"  : 90,
	"damage" : 150,
	"lvl"    : 70,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"MAG"���񲻰�"NOR"���������ݼ�ת��չ���ṦΧ��$n"
		   "�������ߣ���Ȼ�����������$n��$l",
	"force"  : 550,
	"attack" : 240,
	"dodge"  : 95,
	"damage" : 155,
	"lvl"    : 200,
	"skill_name" : "���񲻰�",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"WHT"��;ĩ·"NOR"������$n���ԣ����ƾٵ���ǰƽ"
		   "�ƶ�������������бб����$n��$l",
	"force"  : 570,
	"attack" : 250,
	"dodge"  : 100,
	"damage" : 150,
	"lvl"    : 220,
	"skill_name" : "��;ĩ·",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIY"����ľ��"NOR"��˫Ŀֱֱ�Ķ���$n�����嶯Ҳ��"
		   "��һ�µķ���$n",
	"force"  : 590,
	"attack" : 255,
	"dodge"  : 105,
	"damage" : 155,
	"lvl"    : 240,
	"skill_name" : "����ľ��",
	"damage_type": "����"
]),
([      "action" : "$N��ͷڤ�룬һ�С�"HIB"������ʧ"NOR"����������ƽƽ����$n"
		   "��$l",
	"force"  : 620,
	"attack" : 260,
	"dodge"  : 110,
	"damage" : 150,
	"lvl"    : 260,
	"skill_name" : "������ʧ",
	"damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIB"��ͨ�˴�"NOR"��˫�ƻγ�ǧ����Ӱ��$n��������"
		   "��֮��",
	"force"  : 650,
	"attack" : 265,
	"dodge"  : 115,
	"damage" : 155,
	"lvl"    : 280,
	"skill_name" : "��ͨ�˴�",
	"damage_type": "����"
]),
([      "action" : "$N����ǰ��һ�С�"HIB"¹��˭��"NOR"���������ȣ��Կ������"
		   "һ��ת���Ѿ�ת����$n�������ָ����\n"
		   "��$n�Ĵ�׵Ѩ",
	"force"  : 680,
	"attack" : 270,
	"dodge"  : 120,
	"damage" : 150,
	"lvl"    : 300,
	"skill_name" : "¹��˭��",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query("gender") == "����") 
		return notify_fail("��Ϊ̫�࣬������Ȼ���ꣿ\n");

	if (! stringp(me->query("couple/id")))
		return notify_fail("��û�а��£�������Ȼ���ꣿ\n");

	//if (me->query("static/marry") > 1)
		//return notify_fail("��������Ѳ��������ﻹ�����Ե�������Ȼ����ĸо���\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ�����Ʊ�����֡�\n");

	if ((int)me->query("max_neili") < 2000)
		return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");

	if ((int)me->query_str() < 45)
		return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");

	if ((int)me->query_skill("unarmed", 1) < 150)
		return notify_fail("��Ļ���ȭ�Ų�����죬�޷�����Ȼ�����ơ�\n");

	if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("sad-strike", 1))
		return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷������������Ȼ�����ơ�\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
/* 	int i, level;
	level = (int) me->query_skill("sad-strike", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level)]; */
		
	if (random(5) == 0)
	{
	return ([
	"action": HIC  "$N" HIC"���쳤Х��������ɽ�鱬������������Ѹ���α�ȫ���Ʒ��������ų�ӿ֮����һ���ĳ��������п�ӿ����"NOR"\n",
	"attack": 300,
	"dodge" : 150,
	"parry" : 150,
    "damage": 450,
	"force" : 680,
	"damage_type": "����"]);
	}

	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int cost;

	cost = me->query_skill("sad-strike", 1) / 3 + 80;
	if ((int)me->query("qi") < 160)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("���������������Ȼ�����ơ�\n");

	me->receive_damage("qi", 150);
	me->add("neili", -cost);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) >= 5||me->query("family/family_name") == "��Ĺ��")
	{
		victim->receive_wound("qi", damage_bonus / 6, me);
		return HIR "ֻ��" + victim->name() +  HIR "һ���ƺߣ����ۡ��������һ�����Ѫ��"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"sad-strike/" + action;
}
