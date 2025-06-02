#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����$wһת������һ��������$n$l������һ�С����ס�",
        "force"  : 100,
        "dodge"  : 100,
        "parry"  : 100,
        "attack" : 100,
        "damage" : 1250,
        "lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "����",
]),
([      "action" :  "ֻ��$N����Ȼ�ӿ죬ʩչ������硹�����絴����$w˲������$n$l",
        "force"  : 150,
        "dodge"  : 150,
        "parry"  : 150,
        "attack" : 150,
        "damage" : 1250,
        "lvl"    : 25,
        "damage_type" : "����",
        "skill_name"  : "���",
]),
([      "action" : "$N����Ծ��ʹ��һ�С�������������$w�Ӱ��ֱָ$N$l",
        "force"  : 200,
        "dodge"  : 200,
        "parry"  : 200,
        "attack" : 200,
        "damage" : 1250,
        "lvl"    : 50,
        "damage_type" : "����",
        "skill_name"  : "�������",
]),
([      "action" : "$N�ڿն���һ�С����꡹������׼�ֿ죬����$w�ѵ�$n$l",
        "force"  : 300,
        "dodge"  : 300,
        "parry"  : 300,
        "attack" : 300,
        "damage" : 1250,
        "lvl"    : 75,
        "damage_type" : "����",
        "skill_name"  : "����",
]),
([      "action" : "$N�����ת��һ����ֱ����$n$l�������ھ�ʮ�㣬����һ�С����硹",
        "force"  : 400,
        "dodge"  : 400,
        "parry"  : 400,
        "attack" : 400,
        "damage" : 1250,
        "lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "����",
]),
([      "action" : "$N����$w��Ȼ�س���������һ�������ư��磬�����ݺᣬ���ǡ�����",
        "force"  : 500,
        "dodge"  : 500,
        "parry"  : 500,
        "attack" : 500,
        "damage" : 1250,
        "lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "����",
]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob=me->query_temp("weapon") )
            || ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        if( me->query("max_neili")<10000 )
                return notify_fail("���������Ϊ�������޷�ѧϰ���󽣾���\n");

        if ((int)me->query_skill("force") < 600)
                return notify_fail("����ڹ����̫ǳ���޷�ѧϰ���󽣾���\n");

        if ((int)me->query_skill("sword", 1) < 600)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ���󽣾���\n");

        if (me->query_skill("sword", 1) < me->query_skill("wuyin-jianjing", 1))
                return notify_fail("��Ļ�������������ޣ��޷�������������󽣾���\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
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

        level = (int) me->query_skill("wuyin-jianjing", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
       object weapon;

       if( !objectp(weapon=me->query_temp("weapon") )
           || weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԡ�\n");

       if( me->query("neili")<1000 )
                   return notify_fail("����������㣬û�а취��ϰ���󽣾���\n");

       if( me->query("qi")<50 )
                   return notify_fail("����������������󽣾���\n");

       me->receive_damage("qi", 50);
       me->add("neili", -1000);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuyin-jianjing/" + action;
}
