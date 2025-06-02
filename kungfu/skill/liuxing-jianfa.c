// This program is a part of NITAN MudLIB

inherit SKILL;

mapping *action = ({
([      "action": "$N���һ��������ͻȻ�ӿ죬��ͬ���ǻ���ҹ��һ�㣬����$n��$l",
        "force" : 126,
        "parry" : 3,
        "dodge" : 5,
        "damage": 21,
        "lvl"   : 0,
        "skill_name" : "Ⱥ����ҫ",
        "damage_type":  "����"
]),
([      "action": "$N��ʽͻȻ�仺��������Ũ�ص�ɱ����ˢ��һ��ͻȻ����$n��$l",
        "force" : 149,
        "parry" : 13,
        "dodge" : 10,
        "damage": 25,
        "lvl"   : 30,
        "skill_name" : "����ǧ��",
        "damage_type":  "����"
]),
([      "action": "$N����Ծ������$w�������ǣ�ֱ����$n��$l",
        "force" : 167,
        "parry" : 12,
        "dodge" : 15,
        "damage": 31,
        "lvl"   : 50,
        "skill_name" : "���б���",
        "damage_type":  "����"
]),
([      "action": "$N��Цһ��������ͻȻ�����������ͬ����һ�����$n��$l",
        "force" : 187,
        "parry" : 23,
        "dodge" : 19,
        "damage": 45,
        "lvl"   : 70,
        "skill_name" : "�ǹ�����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹�������ѧϰ���ǽ�����\n");

        if (me->query_skill("sword", 1) < 80)
                return notify_fail("��Ļ���������򲻹�������ѧϰ���ǽ�����\n");

        if (me->query("max_neili") < 1000)
                return notify_fail("�����������������ѧϰ���ǽ�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liuxing-jianfa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������ǽ�����\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("liuxing-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("����������������ǽ�����\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("����������������ǽ�����\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuxing-jianfa/" + action;
}

