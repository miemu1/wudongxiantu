inherit SKILL;

mapping *action = ({
([      "action": "$N��һ����������ȭ��$n��$l����ȥ",
        "force" : 60,
        "attack": 20,
        "dodge" : 40,
        "parry" : 5,
        "damage": 6,
        "lvl"   : 0,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action": "$N��������һ�ˣ��������˫ȭ�͵س�$n��$l����ȥ",
        "force" : 80,
        "attack": 25,
        "dodge" : 43,
        "parry" : 6,
        "damage": 7,
        "lvl"   : 30,
        "skill_name" : "�β�Ѱ��",
        "damage_type":  "����"
]),
([      "action": "$N����Ծ��˫��һɨ������һ����������ȭ�͵س�$n��$l������",
        "force" : 100,
        "attack": 28,
        "dodge" : 45,
        "parry" : 8,
        "damage": 10,
        "lvl"   : 60,
        "skill_name" : "Ҷ��͵��",
        "damage_type":  "ץ��"
]),
([      "action": "$N��ȭ����$n�沿��ͬʱ��ȭ��$n��$l��������ȥ",
        "force" : 120,
        "attack": 35,
        "dodge" : 47,
        "parry" : 11,
        "damage": 17,
        "lvl"   : 80,
        "skill_name" : "�ڻ�����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage)
{
        return usage == "cuff" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ħ��ȭ��������֡�\n");

        if (me->query("max_neili") < 100)
                return notify_fail("��������������޷���ϰħ��ȭ������\n");

        if ((int)me->query_skill("cuff", 1) < 20)
                return notify_fail("��Ļ���ȭ�����̫ǳ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("moshen-quanfa", 1))
                return notify_fail("��Ļ���ȭ��������ޣ��޷����������ħ��ȭ������\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("moshen-quanfa", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 65);
        me->add("neili", -40);

        return 1;
}
