// This program is a part of NITAN MudLIB

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$wð������������ৡ���һ�����治��س�$n��$l����",
        "force"  : 120,
        "dodge"  : 20,
        "damage" : 25,
        "lvl"    : 0,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$N�����³������Ӳ�ס��ת������$w����һ�Ž�����$n��$l����ȥ",
        "force"  : 120,
        "dodge"  : 20,
        "damage" : 20,
        "lvl"    : 10,
        "skill_name" : "������ˮ",
        "damage_type": "����"
]),
([      "action" : "$N���е�$w����ƫ�棬��ת���䣬�����ޱ�һ�д���$n��$l",
        "force"  : 140,
        "dodge"  : 15,
        "damage" : 25,
        "lvl"    : 20,
        "skill_name" : "���ֿ��",
        "damage_type": "����"
]),
([      "action" : "$N����$wһ�ӣ���ʽ�󿪴��أ�ֻ��˲ʱ��㽣Ӱ��$n��$l������",
        "force"  : 150,
        "dodge"  : 15,
        "damage" : 35,
        "lvl"    : 30,
        "skill_name" : "��Ů����",
        "damage_type": "����"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("moshen-jianfa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������ħ�񽣷���\n");

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
        level = (int) me->query_skill("moshen-jianfa", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("�������������ħ�񽣷���\n");

        if ((int)me->query("neili") < 10)
                return notify_fail("�������������ħ�񽣷���\n");

        me->receive_damage("qi", 25);
        me->add("neili", -10);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"moshen-jianfa/" + action;
}
