// This program is a part of NITAN MudLIB

inherit SKILL;

mapping *action = ({
([      "action": "$N˫Ŀ��죬�������ɱ���������������أ�һ�С�����޹⡹����ǧ��֮����������$n��$l����ȥ",
        "force" : 130,
        "dodge" : 20,
        "parry" : 20,
        "attack": 15,
        "damage": 20,
        "lvl"   : 0,
        "skill_name" : "����޹�",
        "damage_type": "����"
]),
([      "action": "$Nһ����Х��һ�С�������ء�,һȭ�����������쿪�죬�����Ƶ�֮������$n",
        "force" : 185,
        "dodge" : 25,
        "parry" : 25,
        "attack": 17,
        "damage": 43,
        "lvl"   : 20,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action": "$N�����Ʋ��ϱ任��һ�С���ս��Ұ���û���������״��������Σ���ʱ����ѹ������$n��",                
        "force" : 220,
        "dodge" : 31,
        "parry" : 33,
        "attack": 21,
        "damage": 68,
        "lvl"   : 40,
        "skill_name" : "��ս��Ұ",
        "damage_type":  "����"
]),
([      "action": "$N�������У�һ�С�ͬ���ġ�����ȭ���͵ػӳ�����һȭ֮���·������ؼ��ٹ���$n��",                
        "force" : 260,
        "dodge" : 71,
        "parry" : 83,
        "attack": 71,
        "damage": 88,
        "lvl"   : 90,
        "skill_name" : "ͬ����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ŭȭ������֡�\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ���򲻹����޷�ѧŭȭ��\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷���ŭȭ��\n");

        if ((int)me->query_skill("cuff", 1) < 20)
                return notify_fail("��Ļ���ȭ�����̫ǳ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("nuquan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷����������ŭȭ��\n");

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
        level = (int) me->query_skill("nuquan", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("�������������ŭȭ��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -45);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"nuquan/" + action;
}

