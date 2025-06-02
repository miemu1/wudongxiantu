// taizu-quan ̫�泤ȭ
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"
inherit SKILL;


mapping *action = (
{
([     "action" : "$Nһʽ��ǧ����С���˫��ֱ��ֱ�£��͹���ǰ������$n��$l",
	"force" : 100,
	"dodge" : 20,
	"parry" : 50,
	"damage": 200,
	"lvl" : 0,
"damage_type" : "����"
	 ]),
([     "action" : "$N����ǰ�㣬��ȭֱ������һ������$n������һ�С�����ն����",
	"force" : 135,
	"dodge" : 20,
	"damage": 200,
	"lvl" : 0,
"damage_type" : "����"
	 ]),
([     "action" : "$Nʹ�С���˷����������������һ�������ȭ����$n",
	"force" : 240,
	"dodge" : 10,
	"parry" : 25,
	"damage": 200,
	"lvl" : 10,
"damage_type" : "����"
	 ]),
([     "action" : "$N˫ȭ����������������飬���͡�������ͨ��֮��",
	"force" : 350,
	"dodge" : 35,
	"parry" : 330,
	"damage": 200,
	"lvl" : 10,
"damage_type" : "����"
	 ]),
([     "action" : "$N������������һת�������غ�˫ȭ���������$n��$l��������������",
	"force" : 400,
	"dodge" : 110,
	"parry" : 335,
	"damage": 200,
	"lvl" : 30,
"damage_type" : "����"
	 ]),
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
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
	int i, level;
	object ob;
	ob = me->select_opponent();
	level   = (int) me->query_skill("taizu-quan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
	level   = (int) me->query_skill("taizu-quan",1)/10;
	if (!userp(me) || (int)me->query_skill("taizu-quan", 1) > 10)
	{
		if (  !me->is_busy()
		        &&living(ob)
		        && !me->query_temp("dsauto")
		        && random(me->query_skill("taizu-quan",1))> 180
		   )
		{
			message_vision(HIW"\n$N�Լ����ٵ��������ڵ�һ����$nû�����ֿ���ʱ����ڶ���! \n"NOR, me,ob);
			me->set_temp("dsauto",1);
			me->add_temp("apply/attack", (level*2));
			me->add_temp("apply/damage", (level*4));
			COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
			me->add_temp("apply/attack", -(level*2));
			me->add_temp("apply/damage", -(level*4));
			me->delete_temp("dsauto");
		}
	}

}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������̫�泤ȭ��\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��̫�泤ȭ������֡�\n");
        return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	int ap,dp,damage2;

	ap = me->query_skill("taizu-quan",1) + me->query_skill("unarmed",1) + me->query_skill("force",1);
	dp = victim->query_skill("parry",1);
	damage2 = (int)me->query_skill("taizu-quan",1);
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || damage_bonus < 100) return 0;
	if( random(ap) > dp/8 && me->query("jiali")>0 && random(6)==1) 
	{
		victim->receive_damage("qi", damage2+damage_bonus/2 ,me);
		victim->receive_wound("qi", damage2+damage_bonus/2,me );
		me->add("neili",-100);
		return HIY"ֻ��$n����һ����Ѫ���ѱ�̫�泤ȭ��ȭ��������ˣ�\n"NOR;
	}
}

string perform_action_file(string action)
{
	return __DIR__"taizu-quan/" + action;
}
