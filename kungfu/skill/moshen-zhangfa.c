// This program is a part of NITAN MudLIB

inherit SKILL;

mapping *action = ({
([      "action": "$N����ð��������������һ�����߳�$n��$l����ȥ",
        "force" : 10,
        "dodge" : 5,
        "parry" : 2,
        "lvl"   : 0,
        "skill_name" : "����ӭ��",
        "damage_type": "����"
]),
([      "action": "$N���е��������������͵س�$n��$l����ȥ",
        "force" : 15,
        "dodge" : 18,
        "parry" : 17,
        "lvl"   : 10,
        "skill_name" : "���·ת",
        "damage_type": "����"
]),
([      "action": "$N����һ����˫�����ص���ֻ��һ��������$n��$l�������ȥ",
        "force" : 15,
        "dodge" : 16,
        "parry" : 19,
        "lvl"   : 20,
        "skill_name" : "���ͻ��",
        "damage_type": "����"
]),
([      "action": "$N˫��ƽ�ƣ�$nֻ����һ�ɷ�������֮�����Լ�ѹ��",
        "force" : 25,
        "dodge" : 24,
        "parry" : 21,
        "lvl"   : 30,
        "skill_name" : "���컨��",
        "damage_type": "����"
]),

});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ħ���Ʒ�������֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷�ѧħ���Ʒ���\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷���ħ���Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("moshen-zhangfa", 1))
                return notify_fail("��Ļ����Ʒ�����㣬�޷����������ħ���Ʒ���\n");

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
        level = (int) me->query_skill("moshen-zhangfa", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 100 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if( (int)me->query("neili") < 80 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -50);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"moshen-zhangfa/" + action;
}
