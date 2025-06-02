// This program is a part of NITAN MudLIB
// yinlong-shou.c ������

inherit SKILL;

mapping *action = ({
([      "action" : "$N������Ʈ����������ͬ��Ӱһ�㣬������$n�����һ�С���Ӱ���١�����$n��$l",
        "force" : 130,
        "dodge" : 20,
        "damage" : 10,
        "lvl" : 0,
        "skill_name" : "��Ӱ����",
        "damage_type" : "����"
]),
([      "action" : "$N˫����ͬ����һ�㣬���ſ���������һ�С�����̽Ӱ��������$n��$l",
        "force" : 150,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 20,
        "skill_name" : "����̽Ӱ",
        "damage_type" : "����"
]),
([      "action" : "$N��������$n����ת������Ȼ���ƣ�����һ�С�������ơ�����$n��$l",
        "force" : 150,
        "dodge" : 30,
        "damage" : 35,
        "lvl" : 30,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N˫�����·��ɣ���ͬ������ǧ������ƣ�����һ�С�����ǧ�á�����$n��$l��",
        "force" : 250,
        "dodge" : 20,
        "damage" : 10,
        "lvl" : 40,
        "skill_name" : "����ǧ��",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������ֱ�����֡�\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷��������֡�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("yinlong-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("������������������֡�\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yinlong-shou/" + action;
}

