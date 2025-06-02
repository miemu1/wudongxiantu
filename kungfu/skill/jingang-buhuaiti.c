// jingang-buhuaiti.c

#include <ansi.h>

inherit SHAOLIN_SKILL;

int valid_enable(string usage) { return usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 300)
		return notify_fail("����ڹ���򲻹���������ϰ����񹦡�\n");

	if ((int)me->query("max_neili") < 3000)
		return notify_fail("�����������������ϰ����񹦡�\n");

	if ((int)me->query_skill("force", 1) < (int)me->query_skill("jingang-buhuaiti", 1))
		return notify_fail("��Ļ����ڹ�ˮƽ���ޣ��޷���������Ľ�ղ������񹦡�\n");

	return 1;
}

string query_txt()
{
	return "Ҫ���ڹ�����300������3000���ȼ����ܸ��ڻ����ڹ�"ZJBR
	"��Ч�����������⹥�����˺�����������=�˺�/4���Ա�����(�ڹ�����*12+�����/2)�͹�����(�ڹ�����*12+����/2)��ͬ��ֵ1/2���ʴ���"
	"���������������/3���������ܲ������ƽ�";
}

mixed valid_damage(object ob, object me, int damage, object weapon) 
{ 
	mixed result; 
	int ap, dp, mp, ratio; 
  	int cost;
	cost = damage / 4;  
		if (! living(me) ||
	    (int)me->query_skill("jingang-buhuaiti", 1) < 100 ||
	    (int)me->query("neili") < cost ||
	    (int)me->query("neili") < me->query("max_neili")/3)
		return;
		
	mp = ob->query_skill("never-defeated", 1) ;
	ap = ob->query_skill("force") * 12 + ob->query("max_neili")/2;
	dp = me->query_skill("force") * 12 + me->query("neili")/2;	    
	if (ap / 2 + random(ap) < dp)
	{
		me->add("neili", -cost);
        tell_object(me,"��ʹ����ղ������񹦣���"+cost+"����������"+damage+"�˺���"NOR"\n");
		result = ([ "damage": -damage ]);

		switch (random(5))
		{
		case 0:
			result += (["msg" : HIY "$n" HIY "��ǰ�·���һ��������ǽ����$N"
					    HIY "����ǰ��һ����"NOR"\n"]);
			break;
		case 1:
			result += (["msg" : HIY "ֻ��$N" HIY "��һ�д��˸����У�Ȼ��$n"
					    HIY "�������⣬��û�з������ϡ�"NOR"\n"]);
			break;
		case 2:
			result += (["msg" : HIY "$N" HIY "һ�����ô���$n" HIY "���ϣ���"
					    "��������ʯ���󺣣�˿���������á�"NOR"\n"]);
			break;
		case 3:
			result += (["msg" : HIY "$N" HIY "һ�л���$n" HIY "���ϣ�����$n"
					    HIY "һ����ȣ�$N" HIY "�����������������"
					    "������"NOR"\n"]);
			break;
		default:
			result += (["msg" : HIY "$n" HIY "�������µĽ�����$N"
					    HIY "��һ�У�ȴû���ܵ�����˺���"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(4))
		{
		case 0:
			result = HIY "$N" HIY "��ͨ�ƽ�֮�����ѿ��ƣ�$n" HIY "�ĵֵ���\n";
			break;
		case 1:
			result = HIY "$N" HIY "��ͨ�ƽ�֮�����ѿ��ƣ�$n" HIY "�ĵֵ���\n";
			break;
		case 2:
			result = HIY "$N" HIY "��ͨ�ƽ�֮�����ѿ��ƣ�$n" HIY "�ĵֵ���\n";
			break;
		default:
			result = HIY "$N" HIY "��ͨ�ƽ�֮�����ѿ��ƣ�$n" HIY "�ĵֵ���\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	} 
} 

int query_effect_parry(object attacker, object me)
{
	int lvl;

	lvl = me->query_skill("jingang-buhuaiti", 1);
	if (lvl < 100) return 0;
	if (lvl < 150) return 50;
	if (lvl < 200) return 60;
	if (lvl < 250) return 70;
	if (lvl < 300) return 80;
	if (lvl < 350) return 90;
	if (lvl < 400) return 100;
	return 120;
}

int practice_skill(object me)
{
	int cost;
	int lvl;

	if ((lvl = me->query_skill("jingang-buhuaiti", 1)) < 100)
		return notify_fail("������Ż����񹦵��˽���ǳ�������������ж�����\n");

	cost = 85 + (lvl - 100) / 3;
	if ((int)me->query("qi") < 70)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("������������������񹦡�\n");

	me->receive_damage("qi", 50);
	me->add("neili", -cost);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jingang-buhuaiti/" + action;
}

