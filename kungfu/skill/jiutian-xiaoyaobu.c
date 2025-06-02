// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
        "$n���������һΣ���������֮����һ��[��������]���ɵض㿪$N�Ľ�����\n",
        "$n����һ�����̣�Ʈ��������������ĥ������һ��[ħ������]������$N�����\n",
        "$n��̬����֮��������֮��˿�������Ǳ�̬֮��һ��[�������]�ܿ���$N�Ĺ�����\n",
        "$n����ͻȻ�������£����������еĻ��飬һ��[��������]�㿪��$N�Ĺ�����\n",
});

int valid_enable(string usage)
{
        return usage == "dodge";
}

int valid_learn(object me)
{
        int lvl;

        lvl = me->query_skill("jiutian-xiaoyaobu", 1);
        if (lvl > 300) lvl = 300;

        if (me->query("max_neili") < 2000)
                return notify_fail("�����������������پ���"
                                   "�ڷ���֮�����������������á�\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("jiutian-xiaoyaobu", 1) < 100 ||
            ob->query("family/family_name") == "������" ||
            ! living(me))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("dodge") + mp;
        dp = me->query_skill("dodge", 1) * 3/5 +
             me->query_skill("jiutian-xiaoyaobu", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                result += (["msg" : HIW "$n" HIW "������ͬ���Ȱ�ػζ��˼��£�������һ��㿪��$N"
                                    HIW "�Ĺ�����\n" NOR]);

                return result;
        } else
        if (mp >= 100)
        {
                result = HIY "$n" HIY "������ͬ���Ȱ�ػζ��˼��£�����$N"
                         HIY "��Ӧ��죬����һ������ס��$n" HIY "��ȥ·\n" NOR;

                COMBAT_D->set_bhinfo(result);
        }
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("jiutian-xiaoyaobu", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 30;
        if (lvl < 150) return 50;
        if (lvl < 200) return 80;
        if (lvl < 250) return 100;
        if (lvl < 300) return 120;
        if (lvl < 350) return 140;
        return 150;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˣ�������ϰ������ң����\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("������������ˣ��޷���ϰ������ң����\n");

        me->receive_damage("qi", 65);
        me->add("neili", -65);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jiutian-xiaoyaobu/" + action;
}
