#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action": "$Nʹ��һ�С��������¡���������ɣ�����ֱ��$n��$l",
    "force" : 100,
    "attack": 100,
    "dodge" : 100,
    "parry" : 100,
    "damage": 350,
    "lvl"   : 0,
    "skill_name" : "��������" ,
    "damage_type" : "����"
]),
([  "action": "$Nʹ��һ�С�������𡹣�˫�Ƽ��������������������Ʒ�ֱ��$n��$l",
    "force" : 200,
    "attack": 200,
    "dodge" : 200,
    "parry" : 200,
    "damage": 355,
    "lvl"   : 30,
    "skill_name" : "�������" ,
    "damage_type" : "����"
]),
([  "action": "$N����һԾ����һ���ֽУ�һ�С������ɢ����˫������ǵذ�����$n",
    "force" : 300,
    "attack": 300,
    "dodge" : 300,
    "parry" : 300,
    "damage": 355,
    "lvl"   : 60,
    "skill_name"  : "�����ɢ" ,
    "damage_type" : "����"
]),
([  "action": "$N��Ȼһ����Х��һ�С��ջ����ǡ���˫����Ȼ���£�ֱ��$n��Ҫ��",
    "force" : 400,
    "attack": 400,
    "dodge" : 400,
    "parry" : 400,
    "damage": 400,
    "lvl"   : 90,
    "skill_name" : "�ջ�����" ,
    "damage_type" : "����"
]),
([  "action": "$N���һ��������һ���죬˫�ۺ�Ȼ�������ߣ�һ�С�����׷�꡹ֱֱ����$n��$l",
    "force" : 500,
    "attack": 500,
    "dodge" : 500,
    "parry" : 500,
    "damage": 500,
    "lvl"   : 120,
    "skill_name" : "����׷��" ,
    "damage_type" : "����"
]),
([  "action": "$Nһ�С�ʴ�Ǵ��ġ���˫���ͷ��ĳ�������������Ӱ����Ȼ��һ����Ѹ���ޱȵ�����$n",
    "force" : 600,
    "attack": 600,
    "dodge" : 600,
    "parry" : 600,
    "damage": 600,
    "lvl"   : 150,
    "skill_name" : "ʴ�Ǵ���" ,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo=="jiuyin-baiguzhao"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	    return notify_fail("���鶾ħ��������֡�\n");

	if ((int)me->query("max_neili") < 1000)
	    return notify_fail("���������Ϊ̫ǳ���޷���ϰ�鶾ħ����\n");

	if ((int)me->query_skill("force") < 1200)
	    return notify_fail("����ڹ�̫��޷���ϰ�鶾ħ����\n");

	if ((int)me->query_skill("strike", 1) < 1200)
	    return notify_fail("��Ļ����Ʒ�̫��޷�����鶾ħ����\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("mingdu-mojing", 1))
	    return notify_fail("��Ļ����Ʒ���򲻹����޷�����������鶾ħ����\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action); i > 0; i--)
		if (level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("mingdu-mojing",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 5, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 100)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 1000)
		return notify_fail("�������������\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("���ﲻ��������\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("���ﲻ��������\n");

	me->receive_damage("qi", 100);
	me->add("neili", -1000);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lvl;
	int flvl;

	lvl  = me->query_skill("mingdu-mojing", 1);
	flvl = me->query("jiali");
	if (lvl < 80 || flvl < 10 || ! damage_bonus)
		return;

	if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
	    victim->affect_by("ming-du",
			      ([ "level" : flvl + random(flvl),
				 "id"    : me->query("id"),
				 "duration" : lvl / 100 + random(lvl / 10) ])))
	{
		return HIR "ֻ��$n�ƺ���һ�����������ܵ����鶾�ĸ��ţ�"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"mingdu-mojing/" + action;
}

