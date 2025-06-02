// douzhan-shengjing.c ��սʥ��
// By Vin 2000

#include <ansi.h>

inherit SHAOLIN_SKILL;
 
mapping *action = ({
([      "action": "$N�������ˣ�һ�С����ֵظ���������$wӭ��һ��������$n��ͷ�������ҽ���",
	"dodge" : 350,
	"attack": 350,
	"force" : 350,
	"damage": 350,
	"parry" : 350,
	"lvl" : 0,
	"damage_type": "����"
]),
([      "action": "$N���쳤Ц����Ҳ������һ�С����������������һ����$n��ͷ����",
	"dodge" : 450,
	"attack": 450,
	"force" : 450,
	"damage": 450,
	"parry" : 450,
	"lvl" : 25,
	"damage_type": "����"
]),
([      "action": "$Nһ��������Խ��$nͷ����һ�С��¶��񽫡�������$w�ո���Բ������$n$l",
	"dodge" : 550,
	"attack": 550,
	"force" : 550,
	"damage": 550,
	"parry" : 550,
	"lvl" : 50,
	"damage_type": "����"
]),
([      "action": "$Nһ���޺ȣ�һ�С������ɾ�����$nһ�֮�䣬$N����$w�Ѻ�Х������ɨ��$n��$l",
	"dodge" : 650,
	"attack": 650,
	"force" : 650,
	"damage": 650,
	"parry" : 650,
	"lvl" : 75,
	"damage_type": "����"
]),
([      "action": "$N�������ˣ�һ�С������칬��������$wӭ��һ��������$n��ͷ�������ҽ���",
	"dodge" : 750,
	"attack": 750,
	"force" : 750,
	"damage": 750,
	"parry" : 750,
	"lvl" : 100,
	"damage_type": "����"
]),
([      "action": "$Nʹ����������᡹���Ų����ԣ���һ������һ�������$n��æ���ң��мܲ���",
	"dodge" : 850,
	"attack": 850,
	"force" : 850,
	"damage": 850,
	"parry" : 850,
	"lvl" : 130,
	"damage_type": "����"
]),
([      "action": "$N�����������ʹ��������׹ǡ�������$wת����糵һ�㣬һ������ֱ��$n����",
	"dodge" : 950,
	"attack": 950,
	"force" : 950,
	"damage": 950,
	"parry" : 950,
	"lvl" : 160,
	"damage_type": "����"
]),
([      "action": "$Nһ�С���ͨ���졹������$w��Ϊ���ϼ�⣬��$nĿѣ֮ʱ��$w�ѵ���$n��$l",
	"dodge" : 1050,
	"attack": 1050,
	"force" : 1050,
	"damage": 1050,
	"parry" : 1050,
	"lvl" : 200,
	"damage_type": "����"
]),
});


int valid_enable(string usage) { return  (usage =="parry")|| (usage =="club"); }

int valid_learn(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "club")
		return notify_fail("���������һ�����Ӳ�������սʥ����\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("����������㣬û�а취����սʥ��������Щ���������ɡ�\n");

	if ((int)me->query_skill("force") < 600)
		return notify_fail("����ڹ����̫ǳ��û�а취����սʥ����\n");

	if ((int)me->query_skill("club", 1) < 600)
		return notify_fail("��Ļ����������̫ǳ��û�а취����սʥ����\n");

	if ((int)me->query_skill("club", 1) < (int)me->query_skill("douzhan-shengjing", 1))
		return notify_fail("��Ļ�������ˮƽ���������޷���������Ķ�սʥ����\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("douzhan-shengjing", 1);

	if (random(me->query_skill("douzhan-shengjing", 1)) > 120 &&
	     me->query_skill("force") > 100 &&
	     me->query("neili") > 1000 &&
	     random(10) > 6)
	{
		me->add("neili", -100);
		return ([
		"action": HIY "$N" HIY "������" + me->query_temp("weapon")->query("name")
			  + HIY "ӭ��һ�ӣ�ʹ����ɱ������" NOR + HIR "�������� "
			  "������" NOR + HIY "����"
			  + me->query_temp("weapon")->query("name") + HIY "��ʱ�ó�"
			  "��ǧ��\nӰ����׼$n������ֱ�����¡���һ��Ҫ�Ǵ��У���������"
			  "�޽���Ҳ����һ��" NOR,
		"force" : 2000,
		"attack": 2000,
		"damage": 2000,
		"dodge" : -50,
		"damage_type": "����"]);
	}

	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level *15 /1)];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 500)
		return notify_fail("���������������սʥ����\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("���������������սʥ����\n");

	me->receive_damage("qi", 500);
	me->add("neili", -500);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"douzhan-shengjing/" + action;
}

