// hamagong.c ��󡹦

#include <ansi.h>
inherit FORCE;

mapping *action = ({
([      "action" : "$N����������һ�ֳŵأ����Ӻ�ͦ��ֻ��һ����$n��$l�ĳ�",
	"dodge"  : 0,
	"force"  : 310,
	"attack" : 103,
	"parry"  : 21,
	"damage" : 166,
	"lvl"    : 0,
	"damage_type": "����" 
]), 
([      "action" : "$N˿��������ɫ��˫��΢��������ƽ�죬���������󡹦��"
		   "����������һ������$n",
	"dodge"  : 0,
	"force"  : 332,
	"attack" : 112,
	"parry"  : 37,
	"damage" : 177,
	"lvl"    : 250,
	"damage_type": "����"
]), 
([      "action" : "$N���۱�ס����������Ƭ�̣���Ծ�����۾�Ҳ����������˫"
		   "�Ʊ���$n�ķ������˳�ȥ",
	"dodge"  : 0,
	"force"  : 360,
	"attack" : 122,
	"parry"  : 53,
	"damage" : 285,
	"lvl"    : 260,
	"damage_type": "����"
]),
([      "action" : "$N�Ų�ҡҡ�ϻϣ���Ȼ˫��һ�䡢һ�ǣ����и��һ���кȣ�"
		   "������$n��Ȼ�Ƴ�",
	"dodge"  : 5,
	"force"  : 410,
	"attack" : 143,
	"parry"  : 67,
	"damage" : 291,
	"lvl"    : 270,
	"damage_type": "����"
]), 
});

int valid_enable(string usage, object me)
{ 
	return usage == "force" || usage == "unarmed" || usage == "parry";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("hamagong", 1);
	return lvl * lvl * 15 * 12 / 100 / 200;
}

int valid_learn(object me)
{
	if ( me->query("gender") == "����" && me->query("hamagong", 1) > 49)
		return notify_fail("���޸����ԣ���������������������ĸ�󡹦��\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ��󡹦��\n");

	return ::valid_learn(me);
}

string query_skill_name(int level)
{
	int i = sizeof(action);

	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me)
{
	int i, level;
	
	level = (int) me->query_skill("hamagong", 1);
	if (random(5) == 1)
	{
		me->add("neili", -100);
		return ([
		"action": HIC "$N�׵����ӣ�����΢�գ����й������Ľ���������˫"
			  "����$n" HIC "�����Ƴ������û�����������������" NOR,
		"force"  : 738,
		"attack" : 152,
		"parry"  : 112,
		"dodge"  : 33,
		"damage" : 400,
		"damage_type": "����"]);
	}
	
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

 mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 7)
	{
		victim->receive_wound("qi", damage_bonus / 6);
		return HIC "$n" HIC "Ӳ����$N" HIC "һ�ƣ���ʱȫ��һ���������������һ����Ѫ��"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
} 

int practice_skill(object me)
{
	return notify_fail("��󡹦ֻ����ѧ(learn)�������������ȡ�\n");
}

string perform_action_file(string action)
{
	return __DIR__"hamagong/perform/" + action;
}
string exert_function_file(string action)
{
	return __DIR__"hamagong/exert/" + action;
}