// qingmang-jian.c ������(��)��
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;

string *dodge_msg = ({
"�ƺ�$Nÿһ�ж�����$n������������$n���ǻ򷴴򡢻����ܣ�һһ��⿪ȥ��\n",
"ȴ��$nһ��ͷ����$N����������ȥ��������Ƹ���$n���ұۡ�\n",
"��֪$n����һ�ϣ��������ɵرܹ���$N�Ĺ�����\n",
"$n�������㣬����$N����һ�С�Ҷ�׷��ࡹ����Ϊ�ء�\n"
});

string  *msg = ({
"$Nˢˢˢ�������У�ʹ�����������š�������$w������������������һ�㣬��֪Ҫ����δ�",
"$N�������ˣ�����һ�У�$wֱ��$n���ţ��Ƶ�$n��æ��ͷ����",
"$N�������$nС����һɨ���뽫$n�赹������$wһ������ָס$n�ʺ�",
"$Nһ����Ц������$wӭ�濳�£�ֱ��$n$l",
"$Nһ�³嵽$n��ǰ��ͻȻ֮��γ�$w������$nͷ�Ͽ�����ȥ",
"$NͻȻһ�°�$w�ӻ�������ͻ���������ж����ǿ켫��$nȫ�����ܵ���ԣ",
"$N$wͦ����һ�С����߳���������$n������ȥ���Ƶ����Ǿ���",
"$N���������ã���$wȦת������$n$l",
"$Nһ�С��������š���$w�����ޱȵ���$n��$l"
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry" ;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(3)+2)*50,
                "damage_type":random(2)?"����":"����",
                "dodge":random(50),
                "force":200+random(200)
        ]);
}

string query_dodge_msg(object weapon)
{        
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 300)
    return notify_fail("�������������\n");
    if ((int)me->query_skill("force", 1) < 60)
    return notify_fail("����ڹ��ķ����̫ǳ��\n");
    if ((int)me->query_skill("sword", 1) < 60)
    return notify_fail("��Ļ����������̫ǳ��\n");
    if ((int)me->query_dex() < 25)
    return notify_fail("�������������\n");
    return 1;
}
int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 30)
    return notify_fail("�������������������\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"qingmang-jian/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	int ap,dp,damage2;
	ap = me->query_skill("qingmang-jian",1) + me->query_skill("unarmed",1) + me->query_skill("force",1);
	dp = victim->query_skill("parry",1);
	damage2 = (int)me->query_skill("qingmang-jian",1);
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || damage_bonus < 100) return 0;
	if( random(ap) > dp/8 && me->query("jiali")>0 && random(6)==1) 
	{
		victim->receive_damage("qi", damage2+damage_bonus/2 ,me);
		victim->receive_wound("qi", damage2+damage_bonus/2 ,me);
		me->add("neili",-100);
//		if (!victim->is_busy()) victim->start_busy(1);
		return HIR "ֻ��$N������ͬ����һ�㣬���н�������������Խ��Խ����$n���������������Ʋ��ѡ�\n" NOR;
	}
}