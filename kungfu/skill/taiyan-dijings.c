inherit SKILL;

#include <ansi.h>

string *parry_msg = ({
        HIY "$N" HIY "��ʽ���ͣ�$n" HIY "��������֮�⣬����һ����ն������������л��⡣\n" NOR,
        HIY "$n" HIY "����������������磬$N" HIY "�Ͻ����У������ٽ���\n" NOR,
});

mapping *action = ({
([      "action" : "$N����$w���ɨ����һ�С��ε�ն���������ź������ذ��������$n$l��ȥ",
        "skill_name" : "�ε�ն",
        "force"  : 1000,
        "attack" : 1000,
        "parry"  : 1000,
        "damage" : 2000,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С����项������һ����࣬˫��΢�գ�$w�����Ļ���������$n��$l",
        "skill_name" : "����",
        "force"  : 1250,
        "attack" : 1250,
        "parry"  : 1250,
        "damage" : 6000,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����񡹣�$w���纣Х�㣬����ǵؾ���$n",
        "skill_name" : "����",
        "force"  : 1500,
        "attack" : 1500,
        "parry"  : 1500,
        "damage" : 8000,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С����ġ�������$w��ת������һ����â����ն���������$n",
        "skill_name" : "����",
        "force"  : 1750,
        "attack" : 1750,
        "parry"  : 1750,
        "damage" : 10000,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ�С������$wһ���������˵��׹�����$n��$l",
        "skill_name" : "����",
        "force"  : 2000,
        "attack" : 2000,
        "parry"  : 2000,
        "damage" : 20000,
        "damage_type" : "����",
]),
([      "action" : "$Nһ����̾�����׾��£�����һ��������һ�С��Թ����ޡ�ʹ����$w��������������������ְ�ӿ��$n",
        "skill_name" : "�Թ�����",
        "force"  : 3000,
        "attack" : 3000,
        "parry"  : 3000,
        "damage" : 50000,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
          int level;
          level = me->query_skill("taiyan-dijings", 1);

        if( me->query("str")<1 )
                return notify_fail("������������㣬�޷���������̫�ܵ۾���\n");

        if( me->query("con")<1 )
                return notify_fail("��������ǲ��㣬�޷���������̫�ܵ۾���\n");

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
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int double_attack()
{
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("����̫�ܵ۾�������޷��򵥵�ͨ����ϰ������\n");
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string *desc;
        object weapon;

        weapon=me->query_temp("weapon");

        if (! objectp(weapon))return damage_bonus;

        desc = ({
                HIY "$N" HIY "������𣬾�������" + weapon->name() + HIY "�������£�����һ�����绮��$n" HIY "��\n" NOR,
                HIC "$N" HIC "����" + weapon->name() + HIC "������ֱ������ʽ��֮����ȴ�����ޱȡ�\n" NOR,
                HIR "$N" HIR "�Ӷ�����" + weapon->name() + HIR "����ʱ��ɳ��ʯ�������������ĵ��ƣ���$n" HIR "���֡�\n" NOR,
        });

        if (me->is_busy()
           || random(4) >= 1
           || ! living(victim)
           || damage_bonus < 150
            || me->query("neili")<100
           || me->query_skill("taiyan-dijings", 1) < 300)
                return 0;

        // ׷����Ч
        victim->receive_wound("qi", damage_bonus / 4, me);

        if (random(6) == 1)victim->start_busy(3 + random(5));

        return desc[random(sizeof(desc))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp, cost;

        if ((int)me->query_skill("taiyan-dijings", 1) < 350
           || me->query_skill_mapped("parry") != "taiyan-dijings"
            || me->query("neili")<200
           || ! living(me) || random(5) > 2)
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force", 1) * 5 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("taiyan-dijings", 1) * 10 + me->query_skill("martial-cognize", 1) * 10 + 100;

        if (dp / 2 + random(dp / 2) >= ap)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIG "$n" HIG "����������˳��һ����Ӳ��$N" HIG "���ˡ�\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIG "$n" HIG "���˲���������������$N" HIG "����֮�£���æ���С�\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIG "$n" HIG "�ᵶ��ǰ������$N" HIG "�����������ַ���������$N" HIG "��ʽ���� ��\n" NOR]);
                        break;
                }
                return result;
        }
}

string perform_action_file(string action)
{
        return __DIR__"taiyan-dijings/" + action;
}

int difficult_level()
{
        return 30000;
}
