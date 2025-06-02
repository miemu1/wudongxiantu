// lingboweibu.c �貨΢��

#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
        "$n��Ҳ��������$N��һ�ߡ�\n",
        "$n����΢΢һ������$N���ˡ�\n",
        "$n�������һ�Σ�$N��Ȼ�޷�������ֻ���Ա���\n",
        "$n����һ�񣬽��������н�������ȫ��������\n",
});

int valid_enable(string usage) 
{ 
	return usage == "dodge";
}

int valid_learn(object me)
{
	int lvl;

	lvl = me->query_skill("tianrenheyi", 1);

	if (me->query("max_neili") < 1000 + lvl * 2)
		return notify_fail("�����������������پ��ؿڷ���֮�����������������á�\n");
	return 1;
}

string query_txt()
{
	return ""ZJBR
	"��Ч���Ṧ�����˺����Ա�����(�Ṧ����)+������ά���Ժ͹������Ṧ���������������Կ���";
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp;

	if ((int)me->query_skill("tianrenheyi", 1) < 100 ||
	    ! living(me))
		return;

	mp = ob->query_skill("count",1);
	ap = ob->query_skill("dodge") + mp;
	dp = me->query_skill("dodge")+me->query("str")+me->query("dex")+me->query("int")+me->query("con");

	if (ap / 1 + random(ap) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(4))
		{
		case 0:
			result += (["msg" : HIW "ֻ��$n" HIW "΢΢һЦ����������ζ���$N"
					    HIW "��ǰ��ʱ������������$n" HIW "�Ļ�Ӱ����$N"
					    HIW "��ȫ�޷������ʵ��"NOR"\n"]);
			break;
		case 1:
			result += (["msg" : HIW "$n" HIW "���Ա�����бб������һ����ȴǡ"
					    "����$N" HIW "�Ĺ���ʧ֮���塣"NOR"\n"]);
			break;
		case 2:
			result += (["msg" : HIW "$N" HIW "��һ�����ĺÿ죬Ȼ��$n"
					    HIW "һ�����ƺ����Ѱ��������ȴ��$N"
					    HIW "��һ�иպñܿ���"NOR"\n"]);
			break;
		default:
			result += (["msg" : HIW "����$n" HIW "����һԾ���Ѳ�������Ӱ��$N"
					    HIW "���д󺧣�ȴ�ּ�$n" HIW "���籼��������"
					    "֮���ɣ���������˼�����ǡ�"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(4))
		{
		case 0:
			result = HIY "ֻ��$n" HIY "΢΢һЦ����������ζ���"
				 "��ʱ������������$n" HIY "�Ļ�Ӱ������$N"
				 HIY "��ͨ������������ʵ������������"NOR"\n";
			break;
		case 1:
			result = HIY "$n" HIY "���Ա�����бб������һ����Ȼ��$N"
				 HIY "�����棬��λ���岻�"NOR"\n";
			break;
		case 2:
			result = HIY "$n" HIY "һ�����ƺ����Ѱ��������ȴ��$N"
				 HIY "��һ�иպñܿ�������$N"
				 HIY "�������У�����ȴ�ǲ�ֹ��"NOR"\n";
			break;
		default:
			result = HIY "����$n" HIY "����һԾ���Ѳ�������Ӱ��$N"
				 HIY "����˼����������У����������޷���"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

int query_effect_dodge(object attacker, object me)
{
	int lvl;

	lvl = me->query_skill("tianrenheyi", 1);
	if (lvl < 50)  return 150;
	if (lvl < 100) return 250;
	if (lvl < 150) return 420;
	if (lvl < 200) return 520;
	if (lvl < 250) return 640;
	if (lvl < 300) return 750;
	if (lvl < 350) return 860;
	return 960;;
}

int practice_skill(object me)
{
	int cost;

	cost = me->query_skill("tianrenheyi", 1) / 2 + 120;
	if ((int)me->query("qi") < 1000)
		return notify_fail("�������̫���ˣ�������ϰ���������\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("������������ˣ��޷���ϰ���������\n");

	me->receive_damage("qi", 1000);
	me->add("neili", -cost);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianrenheyi/" + action;
}
