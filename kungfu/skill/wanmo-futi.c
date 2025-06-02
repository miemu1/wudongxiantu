// liuli-jinshen.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 600)
		return notify_fail("����ڹ���򲻹����޷�����̫Ԫ�۾���\n"); 



	if ((int)me->query_skill("parry", 1) < (int)me->query_skill("wanmo-futi", 1))
		return notify_fail("��Ļ����м�ˮƽ���ޣ��޷������������������\n");

	return 1;
}

string query_txt()
{
	return "Ҫ���ڹ�600������3500���ȼ����ܸ��ڻ����м�"ZJBR
	"��Ч�����������⹥�����˺�����������=�˺�1.5�����Ա�����(�ڹ�����*15+�������/2)�͹�����(�ڹ�����*15+����/2)��ͬ��ֵ1/1���ʴ���"
	"�������������������һ���򲻴���";
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	int ap, dp;
	int cost;

	cost = damage * 3 / 2 ;

	if (! living(me) ||
	    (int)me->query_skill("wanmo-futi", 1) < 100 ||
	    (int)me->query("neili") < cost ||
	    (int)me->query("neili") < me->query("max_neili")/2)
		return;

	ap = ob->query_skill("force") * 15 + ob->query("max_neili")/2;
	dp = me->query_skill("force") * 15 + me->query("neili")/2;

	if (ap / 80 + random(ap) < dp)
	{
		me->add("neili", -cost);
        tell_object(me,HBRED HIC"��Ĭ��̫Ԫ�۾�������ǧ��ħ��סȫ�����£�˫���ɺ죬���������·�һ�㣬��˿�������˼����������ڣ�Ψ���ұ������ˡ���"+cost+"�����ֵ���"+damage+"�˺���"NOR"\n");
		result = ([ "damage": -damage ]);

		switch (random(5))
		{
		case 0:
			result += (["msg" : HBYEL HIR"$n" HBYEL HIR"����ǧǧ������ħ����ȫ���ɺ����ɣ������������޸�������ȫ�������ħ���壬���:˭�˲������ֻأ�ι�Ҳ�����������ֻΪ����������������һʽ����������Ⱥħ��Ϊ�����ã�����$N"
					    HBYEL HIR"�޴����֡�"NOR"\n"]);
					break;
		case 1:
			result += (["msg" : HBWHT HIR"ֻ��$N" HBWHT HIR"��һ�д��˸����У�Ȼ��$n"
					    HBCYN HIR"�������Ⲣ�е����������½磬������ħ�𡣴ȱ����Ĺ㣬Ը������������Թſ���ޡ���"NOR"\n"]);
			break;
		case 2:
			result += (["msg" : HBYEL HIR"$N" HBYEL HIR"һ�����ô���$n" HBYEL HIR"���ϣ���"
					    "��������ʯ���󺣣�˿����������.....����ʮ������ħ�࣬��ʮ����ׯ��������һ�������������죬�����Թ������"NOR"\n"]);
			break;
		case 3:
			result += (["msg" : HBRED HIR"$N" HBWHT HIR"һ�л���$n" HBWHT HIR"���ϣ�ֻ��$n"
					    HBWHT HIR"һ����ȣ�������ħ�������壬������ȣ�����覻࣡
$N" HBWHT HIR"�����������������"
					    "������"NOR"\n"]);
			break;
		default:
			result += (["msg" : HBCYN HIR"$n" HBWHT HIR"�������µĽ�����$N"
					    HBWHT HIR"��һ�У�ȴû���ܵ�����˺�....��������ɲ������һ����Ѫ��Ȼ��ɣ��۽�ü���ڳ�һ�ɹɺ��������:�����ܱ������ˣ��Ӵ˶�������ħ�����������ټ���İ·��Ψ������꣬����Ѫ������һ��ޡ�˵�ջ���������������̫Ԫ�۾���"NOR"\n"]);
			break;
		}
		return result;
	}
}

int query_effect_parry(object attacker, object me)
{
	int lvl;

	lvl = me->query_skill("wanmo-futi", 1);
	if (lvl < 100) return 0;
	if (lvl < 150) return 50;
	if (lvl < 200) return 80;
	if (lvl < 250) return 10;
	if (lvl < 300) return 80;
	if (lvl < 350) return 120;
	if (lvl < 400) return 100;
	return 150;
}

int practice_skill(object me)
{
	int cost;
	int lvl;

	if ((lvl = me->query_skill("wanmo-futi", 1)) < 300)
				return notify_fail("���̫Ԫ�۾����˽���ǳ�������������ж�����\n");

	cost = 1000 + (lvl - 100) / 3;
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("�������������̫Ԫ�۾���\n");

	me->receive_damage("qi", 50);
	me->add("neili", -cost);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wanmo-futi/" + action;
}

