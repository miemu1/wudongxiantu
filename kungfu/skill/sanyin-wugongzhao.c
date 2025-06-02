//sanyin-wugongzhao.c �������ץ
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$Nצ����ף��ǽ�¡�����϶���˺��$n��$l",
    "force" : 320,
    "dodge" : 10,
	"attack": 129,
    "damage": 130,
    "damage_type" : "ץ��"
]),
([  "action" : "$N˫�ֺ������֣�צצ���Ȱ�ץ��$n��$l",
    "force" : 350,
    "dodge" : 20,
	"attack": 139,
    "damage": 145,
    "lvl"   : 30,
    "damage_type" : "ץ��"
]),
([  "action" : "$N����Χ$nһת��צӰ�ݺ�����������$n��$lץ��",
    "force" : 380,
    "dodge" : 30,
	"attack": 149,
    "damage": 155,
    "lvl"   : 60,
    "damage_type" : "ץ��"
]),
([  "action" : HIR"$Nһ���ֽУ�һצ���ֱ��$n"HIR"��$l",
    "force" : 340,
    "dodge" : 50,
	"attack": 159,
    "damage": 360,
    "lvl"   : 90,
    "skill_name" : "Ψ�Ҷ���" ,
    "damage_type" : "ץ��"
]),
([  "action" : HIR"$N"HIR"����а������������ƮƮ����������̽��һצ��Ȼ����$n"HIR"��$l",
    "force" : 370,
    "dodge" : 60,
	"attack": 169,
    "damage": 380,
    "lvl"   : 120,
    "skill_name" : "Ψ�Ҷ���" ,
    "damage_type" : "ץ��"
]),
});

int valid_enable(string usage) { return usage == "claw" ||  usage == "parry"; }

int valid_combine(string combo) { return combo == "chousui-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	    return notify_fail("������צ������֡�\n");

	if ((int)me->query("max_neili") < 200)
	    return notify_fail("�������̫�����޷�������צ��\n");

	if ((int)me->query_skill("claw", 1) < (int)me->query_skill("sanyin-wugongzhao", 1))
	    return notify_fail("��Ļ���צ��ˮƽ���ޣ��޷��������������צ����\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if (level >= action[i - 1]["lvl"])
			return action[i - 1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("sanyin-wugongzhao", 1);
	for(i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 5, level / 5)];

}

int practice_skill(object me)
{
	object* ob;
	int i,skill,damage;

	skill = me->query_skill("jiuyin-baiguzhao", 1);
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������צ��\n");

	me->receive_damage("qi", 30);
	me->add("neili", -31);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sanyin-wugongzhao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int lvl;

	lvl = me->query_skill("sanyin-wugongzhao", 1);

	if (damage_bonus < 160 || lvl < 180) return 0;

	if (random(10) < 7)
	{
		victim->receive_wound("qi", damage_bonus/ 6, me);
		victim->affect_by("sanyin",
			       ([ "level" : me->query("jiali") + random(me->query("jiali")),
				  "id"    : me->query("id"),
				  "duration" : lvl / 150 + random(lvl / 10) ]));
		return HIM "$n" HIM "һ��������Ҫ����ץ�����ţ�����צ������ʱ������룡"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}