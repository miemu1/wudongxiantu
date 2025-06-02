//fumozhang.c ����ħ�ơ�by yushu@SHXY
//2000/11
inherit SKILL;
#include <ansi.h>
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
        ([      "action":
"$Nǰ���߳������Ƚż��أ�һʽ"HIC"����ħ���¡�"NOR"������ֱ��������$n����������·",
        "lvl" : 0,
        "skill_name" : "��ħ����"

        ]),
        ([      "action":
"$N���ƻ�һ��Բ��һʽ"HIR"����Ѫ���ġ�"NOR"������б������������$n����ǰ��Ѩ",
        "lvl" : 30,
        "skill_name" : "��Ѫ����"
        ]),
        ([      "action":
"$Nʹһʽ"HIM"������Ⱥħ��"NOR"�����������������ɺ����һ��˦����ն��$n��$l",
        "lvl" : 60,
        "skill_name" : "����Ⱥħ"

        ]),
        ([      "action":
"$N���ƻ��أ���ȭ�����󷢣�һʽ"HIY"����ճ�����"NOR"����������$n��$l",
        "lvl" : 90,
        "skill_name" : "��ճ���"
        ]),
        ([      "action":
"$Nʹһʽ"HIG"������ǧ����"NOR"��ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
        "lvl" : 120,
        "skill_name" : "����ǧ��"

        ]),
        ([      "action":
"$N���Ʊ�������һ������һʽ"HIW"��Ⱥħ���ס�"NOR"��˫�Ƽ�����$n�ļ�ͷ",
        "lvl" : 150,
        "skill_name" : "Ⱥħ����"

        ]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
   int level; 

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����ħ�Ʊ�����֡�\n");

        if( me->query("int")<30 )
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if( me->query("dex")<30 )
                return notify_fail("���о��˰��죬ֻ����ʽʼ���޷�����ʩչ��\n");

        if( me->query("con")<30 )
                return notify_fail("���о��˰��죬ֻ���ø�����Щ���ʽʼ���޷�����ʩչ��\n");

        if( me->query("str")<30 )
                return notify_fail("���о��˰��죬�о�������Щ�ͣ�ʼ���޷�����ʩչ��\n");

         level = me->query_skill("fumozhang", 1);

   if ((int)me->query_skill("unarmed", 1) < 180)
               return notify_fail("��Ļ���ȭ�Ż�򲻹����޷�ѧϰ��ħ�ơ�\n");

       if ((int)me->query_skill("unarmed", 1) < level)
               return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷���������ķ�ħ�ơ�\n");
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
{/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
        int d_e1 = -30;
        int d_e2 = -20;
        int p_e1 = -10;
        int p_e2 = 5;
        int f_e1 = 260;
        int f_e2 = 320;
        int a_e1 = me->query_skill("fumozhang", 1);
        int a_e2 = me->query_skill("fumozhang", 1);

        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int) me->query_skill("fumozhang", 1);
        seq = random(ttl);       /* ѡ������������ */
        return ([
                "action"      : action[seq]["action"],
                "dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
                "parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
                "force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
                "attack"       : a_e1 + (a_e2 - a_e1) * seq / ttl,
                "damage"       : a_e1 + (a_e2 - a_e1) * seq / ttl,
                "damage_type" : random(2) ? "����" : "����",
        ]);
}
int practice_skill(object me)
{
	    return notify_fail("��ħ��ֻ����ѧ(learn)�������������ȡ�\n");
}
string perform_action_file(string action)
{
        return __DIR__"fumozhang/" + action;
}