#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([        "action" : "$N����һ������һ��"CYN"���ƴ����¡�"NOR"���Բ����������򣬵�ʱ��$n��������б��",
        "lvl"    : 0,
        "skill_name" : "�ƴ�����"
]),
([        "action" : "$Nʹһ��"YEL"����ˮ������"NOR"�����ƶ�Ȼ�����쳤���ұۣ��ɿ��һ��������ն��$n��$l",
        "lvl"    : 10,
        "skill_name" : "��ˮ����"
]),
([        "action" : "$NͻȻʹһʽ"HIW"�����ƻ��衹"NOR"��˫��������һ��һ����裬����һ����ת�����ˡ� ",
        "lvl"    : 20,
        "skill_name" : "���ƻ���"
]),
([        "action" : "$Nһ��"HIY"������Ǭ����"NOR"���͵ز���������ұ��������¼���������Ĵ������ָ��Ȧ�͵�$n��$l",
        "lvl"    : 30,
        "skill_name" : "����Ǭ��"
]),
([        "action" : "$Nһ��"RED"�����ո��¡�"NOR"������һ��һ�գ�һ����˿��������һ��֮�䣬һ�������ޱȵ������Ŷ�Ȼ������",
        "lvl"    : 40,
        "skill_name" : "���ո���"
]),
([        "action" : "$N���б���һʽ"BLU"������Ϊ����"NOR"��˫�ƺ���г�����Ե�ŵݳ������غ�Х֮��������",
        "lvl"    : 50,
        "skill_name" : "����Ϊ��"
]),
([        "action" : "$Nһ��"MAG"�����޵�����"NOR"�����ƴ�Ȧ����������СȦ�������������������һ��֮�£�����$n��$l",
        "lvl"    : 60,
        "skill_name" : "���޵���"
]),
([        "action" : "$Nһ��"HIG"����ָ��ɽ��"NOR"����һ�����������������ţ���һ��ȴ��Ѹ���ޱȵ�һ�Ƽ��ա�",
        "lvl"    : 80,
        "skill_name" : "��ָ��ɽ"
]),
([        "action" : "$NͻȻ���һ����һ��"HIR"���ͻ���ɽ��"NOR"���м��ɶ�������$nֱ�˶��£������б������ء���һ���̶���Х��",
        "lvl"    : 100,
        "skill_name" : "�ͻ���ɽ"
]),
});

/*
mapping *action = ({
([      "action": "$N����һ������ʩ�����ƴ����¡��Բ����������򣬵�ʱ��$n������б",
        "force"  : 187,
        "attack" : 45,
        "dodge"  : 33,
        "parry"  : 32,
        "damage" : 38,
        "lvl"    : 0,
        "skill_name" : "�ƴ�����",
        "damage_type": "����"
]),
([      "action": "$Nʩ������ˮ�����������ƶ�Ȼ�����쳤���ұ�һ��������ն��$n��$l",
        "force"  : 212,
        "attack" : 53,
        "dodge"  : 34,
        "parry"  : 45,
        "damage" : 43,
        "lvl"    : 20,
        "skill_name" : "�ƴ�����",
        "damage_type": "����"
]),
([      "action": "$Nһ�С����ƻ��衹��˫��������һ��һ����裬����һ����ת������",
        "force"  : 224,
        "attack" : 67,
        "dodge"  : 45,
        "parry"  : 53,
        "damage" : 51,
        "lvl"    : 40,
        "skill_name" : "�ƴ�����",
        "damage_type": "����"
]),
([      "action": "$N��Ȼһ�С�����Ǭ����������������ұ��������·�����ֱ����$n��ȥ",
        "force"  : 251,
        "attack" : 91,
        "dodge"  : 61,
        "parry"  : 63,
        "damage" : 68,
        "lvl"    : 80,
        "skill_name" : "����Ǭ��",
        "damage_type": "����"
]),
([      "action": "$Nһ�С����ո��¡�������һ��һ�գ���ʱһ�������ޱȵ�������$n��ȥ",
        "force"  : 297,
        "attack" : 93,
        "dodge"  : 81,
        "parry"  : 87,
        "damage" : 76,
        "lvl"    : 120,
        "skill_name" : "���ո���",
        "damage_type": "����"
]),
([      "action": "$N���б���һʽ������Ϊ������˫�ƺ����$n�г������غ�Х֮������",
        "force"  : 310,
        "attack" : 91,
        "dodge"  : 67,
        "parry"  : 71,
        "damage" : 73,
        "lvl"    : 160,
        "skill_name" : "����Ϊ��",
        "damage_type": "����"
]),
([      "action": "$Nһ�С����޵����������ƴ�Ȧ����������СȦ��������������ͬʱ����$n",
        "force"  : 324,
        "attack" : 102,
        "dodge"  : 71,
        "parry"  : 68,
        "damage" : 85,
        "lvl"    : 200,
        "skill_name" : "���޵���",
        "damage_type": "����"
]),
([      "action": "$Nʩһ�С���ָ��ɽ���������������ţ���һ��ȴ��Ѹ���ޱȵ�һ�Ƽ���",
        "force"  : 330,
        "attack" : 112,
        "dodge"  : 55,
        "parry"  : 73,
        "damage" : 92,
        "lvl"    : 220,
        "skill_name" : "��ָ��ɽ",
        "damage_type": "����"
]),
([      "action": "$NͻȻ���һ����һ�С����������������м��ɶ���������$nֱ�˶���",
        "force"  : 321,
        "attack" : 123,
        "dodge"  : 73,
        "parry"  : 72,
        "damage" : 95,
        "lvl"    : 240,
        "skill_name" : "��������",
        "damage_type": "����"
]),
});
*/

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_learn(object me)
{

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�������Ʒ�������֡�\n");

        if( me->query("str")<32 )
                return notify_fail("�����������������������������Ʒ���\n");

        if( me->query("con")<32 )
                return notify_fail("�����������������������������Ʒ���\n");

        if( me->query("max_neili")<2000 )
                return notify_fail("���������Ϊ̫�����������������Ʒ���\n");

        if ((int)me->query_skill("force") < 230)
                return notify_fail("����ڹ�����㣬�������������Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < 150)
                return notify_fail("��Ļ����Ʒ���򲻹����������������Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("tie-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������������Ʒ���\n");

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
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
        int d_e1 = -55;
        int d_e2 = -30;
        int p_e1 = -60;
        int p_e2 = -50;
        int f_e1 = 300;
        int f_e2 = 450;
        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int) me->query_skill("tie-zhang", 1);
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

int practice_skill(object me)
{
        int cost;

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�������Ʒ�������֡�\n");

        if( me->query("qi")<150 )
                return notify_fail("�������̫���ˡ�\n");

        cost = me->query_skill("tie-zhang", 1) / 5 + 80;

        if( me->query("neili")<cost )
                return notify_fail("������������������Ʒ���\n");

        me->receive_damage("qi", 120);
        me->add("neili", -cost);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("tie-zhang", 1);

        if (damage_bonus < 150 || lvl < 150)
                return 0;

        if (damage_bonus / 6 > victim->query_con()/10
            /*&& random(2) == 1*/)
        {
                victim->receive_wound("qi", (damage_bonus - 90) / 2, me);

                return random(2) ? HIR "ֻ��$n" HIR "ǰ�ء����꡹һ�����죬������"
                                   "�߹Ƕ��۵�������\n" NOR:

                                   HIR "$n" HIR "һ���ҽУ���ǰ���������꡹������"
                                   "�죬������Ѫ���硣\n" NOR;
        }
}

/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lev,damage, i;
        string msg;
        object weap;
        object piece;
        weap=query_temp("weapon", victim);
        lev=query("tiezhang-zhangfa", me);

        if( (query("neili", me)>1000) &&
                (query_temp("weapon", victim)) &&
                (query_temp("tzzf", me)) &&
                (random(me->query_str()) > victim->query_str()/2) )
        {
                if( random(query("rigidity", weap))<3 )
                {
                        message_combatd(HIW"$N�����絶��������ʮ���£�ֻ������ž����һ����$n���е�" + weap->name() + "�Ѿ���Ϊ���أ�\n" NOR, me, victim );
                        seteuid(getuid());
                        piece = new("/clone/misc/piece");
                        piece->set_name("�ϵ���"+query("name", weap),({query("id", weap),"piece"}));
                        piece->move(environment(me));
                        destruct(weap);
                }
                else
                {
                        message_combatd(HIW"$N�����絶��������ʮ���£�ֻ������������һ����$n���е�" + weap->name() + "���������䵽���ϣ�\n" NOR, me,victim );
                        weap->move(environment(me));
                }
                victim->reset_action();
                addn("neili", -100, me);
                return 1;
        }
}
*/
string perform_action_file(string action)
{
        return __DIR__"tie-zhang/" + action;
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

int help(object me)
{
        write(HIC"\n�����Ʒ���"NOR"\n");
        write(@HELP

    �����Ʒ������ư�����Ʒ���
    �����������񶾣��뽵��ʮ���ơ���Ȼ�����Ʋ������¡�


        ѧϰҪ��
                ��Ԫ���ɷ�100��
                ������Ϊ1000
HELP
        );
        return 1;
}
