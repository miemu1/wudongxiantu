//wuying-zhang ��Ӱ������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([        "action" : "$N��������$w��Ȼ�͵�һ�ƻ���$n��$l������һ�С������Ӱ����",
        "skill_name" : "�����Ӱ",
        "lvl" : 10
]),
([        "action" : "$N����ͻȻ����һ�С���Ӱ�ɻ����Կ����ޱȵ��ٶ�����$n��$l����",
        "skill_name" : "��Ӱ�ɻ�",
        "lvl" : 15
]),
([        "action" : "$N���������������ĥ������һ�С���Ӱ���١�ͻȻһ�ƴ���$n��$l��",
        "skill_name" : "��Ӱ����",
        "lvl" : 20
]),
([        "action" : "$N�����ֺ�Ȼ������ǧ��Ӱ��������˷�����$n��$l������һ�С�ǧ��Ѱ������",
        "skill_name" : "ǧ��Ѱ��",
        "lvl" : 25
]),
([        "action" : "$N��������$n��ͻȻ�����͵�һת���Ƶ�$n�������һ�С���Ӱ��������$l���˹�ȥ��",
        "skill_name" : "��Ӱ����",
        "lvl" : 30
]),
([        "action" : "$N���л���һ������Ȧ�ӣ����С��췽��԰��һ������ʱ����$n�ۻ����ң���֪���룡",
        "skill_name" : "�췽��Բ",
        "lvl" : 50
]),
([        "action" : HIR"$N����$w�������£�������ǰ������ȴһ��[̽��ȡ��]ֱ����$n��$l��",
        "skill_name" : "̽��ȡ��",
        "lvl" : 70
]),
([        "action" : "$N���ڵ������ڲ��ϱ仯���������ƣ�ͻȻһ�С���Ӱ��ն��ն��$n��$l!",
        "skill_name" : "��Ӱ��ն",
        "lvl" : 80
]),
([        "action" : "$Nչ���鲽������Ծ�䣬һ�С���ҹ��Ӱ����˫��һת�����������$n��",
        "skill_name" : "��ҹ��Ӱ",
        "lvl" : 90
]),
([        "action" : "HIB"$N���й��죬������$n�����ܣ��͵����Ƴɵ���ʹ��һ��[��Ӱ����]����$n������!"NOR,
        "skill_name" : "��Ӱ����",
        "lvl" : 100
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo == "boyun-suowu"; }

int valid_learn(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("����Ӱ�����Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹����޷�����Ӱ�����ơ�\n");

        if( query("max_neili", me)<750 )
                return notify_fail("�������̫�����޷�����Ӱ�����ơ�\n");

        if ((int)me->query_skill("strike", 1) < 80)
                return notify_fail("��Ļ����Ʒ���򲻹����޷���ϰ��Ӱ�����ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("wuying-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷������������Ӱ�����ơ�\n");

        return 1;
}
int practice_skill(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("�������ֲ�����ϰ��\n");
        if( query("qi", me)<40 )
                return notify_fail("�������̫���ˡ�\n");
        if( query("neili", me)<40 )
                return notify_fail("���������������Ӱ�����ơ�\n");
        me->receive_damage("qi", 35);
        addn("neili", -20, me);
        return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
        int d_e1 = -35;
        int d_e2 = -5;
        int p_e1 = 5;
        int p_e2 = 35;
        int f_e1 = 170;
        int f_e2 = 280;
        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int) me->query_skill("wuying-zhang", 1);
        for(i = ttl; i > 0; i--)
                if(lvl > action[i-1]["lvl"])
                {
                        seq = i; /* �������������� */
                        break;
                }
        seq = random(seq);       /* ѡ������������ */
        return ([
                "action"      : action[seq]["action"],
                "dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
                "parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
                "force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
                "damage_type" : random(2) ? "����" : "����",
        ]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
        return __DIR__"wuying-zhang/" + action;
}
