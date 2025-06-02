inherit SKILL;

#include <ansi.h>

string *parry_msg = ({
        HIY "$N" HIY "��ʽ���ͣ�$n" HIY "��������֮�⣬����һ����ն������������л��⡣\n" NOR,
        HIY "$n" HIY "����������������磬$N" HIY "�Ͻ����У������ٽ���\n" NOR,
});

mapping *action = ({
([      "action" : "$N����$w���ɨ����һ�С��ϲ��������������ź������ذ��������$n$l��ȥ",
        "skill_name" : "�ϲ�����",
        "force"  : 900,
        "attack" : 960,
        "parry"  : 100,
        "damage" : 750,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С������项������һ����࣬˫��΢�գ�$w�����Ļ���������$n��$l",
        "skill_name" : "������",
        "force"  : 900,
        "attack" : 960,
        "parry"  : 100,
        "damage" : 750,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С��̲��񵶡���$w���纣Х�㣬����ǵؾ���$n",
        "skill_name" : "�̲���",
        "force"  : 900,
        "attack" : 960,
        "parry"  : 100,
        "damage" : 750,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С��׺�������������$w��ת������һ����â����ն���������$n",
        "skill_name" : "�׺�����",
        "force"  : 900,
        "attack" : 960,
        "parry"  : 100,
        "damage" : 750,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ�С��쵶��ʽ����$wһ���������˵��׹�����$n��$l",
        "skill_name" : "�쵶��ʽ",
        "force"  : 900,
        "attack" : 960,
        "parry"  : 100,
        "damage" : 750,
        "damage_type" : "����",
]),
([      "action" : "$Nһ����̾�����׾��£�����һ��������һ�С����쵶ɷ��ʹ����$w��������������������ְ�ӿ��$n",
        "skill_name" : "���쵶ɷ",
        "force"  : 900,
        "attack" : 960,
        "parry"  : 100,
        "damage" : 1000,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
          int level;
          level = me->query_skill("badao", 1);

        if( me->query("str")<35 )
                return notify_fail("�������������35���޷����������ɾ���\n");

        if( me->query("con")<35 )
                return notify_fail("��������ǲ���35���޷����������ɾ���\n");

        if( me->query_skill("yinyang-shiertian",1) )
                return notify_fail("�����顢���ڵ����������������ɾ��������л���̫ʼ�۾���������������ɾ���\n");

        if( me->query_skill("lunhui-sword",1))
                return notify_fail("�����顢���ڵ����������������ɾ��������л��������ɾ���������������ɾ���\n");

        if( me->query_skill("taiyan-dijing",1))
                return notify_fail("�����顢���ڵ����������������ɾ��������л���̫�ܵ۾���������������ɾ���\n");

        if( me->query("max_neili")<10000 )
                return notify_fail("���������Ϊ����1��\n");

        if ((int)me->query_skill("force", 1) < 600)
                return notify_fail("����ڹ�����600����\n");

        if ((int)me->query_skill("martial-cognize", 1) < 400)
                return notify_fail("�����ѧ��������400����\n");

        if ((int)me->query_skill("badao", 1) < 180)
                return notify_fail("�ؼ��㶼û�п��������������\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("��Ļ���������򲻹����޷���������Ŀ����ɾ���\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("��Ļ����Ṧˮƽ���ޣ��޷���������Ŀ����ɾ���\n");

        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("��Ļ����м�ˮƽ���ޣ��޷���������Ŀ����ɾ���\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ��޷���������Ŀ����ɾ���\n");

        if (me->query_skill("martial-cognize", 1) < level &&
            me->query_skill("martial-cognize", 1) < 600)
                                return notify_fail("����ѧ��������600�����޷�����������\n");

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
        return notify_fail("�����ɾ�������޷��򵥵�ͨ����ϰ������\n");
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
            || me->query("neili")<500
           || me->query_skill("badao", 1) < 300)
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

        if ((int)me->query_skill("badao", 1) < 350
           || me->query_skill_mapped("parry") != "badao"
            || me->query("neili")<200
           || ! living(me) || random(5) > 2)
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force", 1) * 3 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("badao", 1) * 3 + me->query_skill("martial-cognize", 1) + 50;

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
        return __DIR__"badao/" + action;
}

int difficult_level()
{
        return 30000;
}
