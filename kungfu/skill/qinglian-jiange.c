// qinglian-jiange.c �������� 
// ���Ӳ�ͬ���ܼ�����Ӧ��ѧϰ����ʹ����������, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()
// Updated by Doing

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С�"+RED+"��ȸβ"+NOR+"����ִ�����˸���Ȧ������$n��$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : RED"��ȸβ"NOR,
	"lvl" : 0,
	"damage_type" : "������"
]),
([	"action" : "$Nʹһ�С�"+GRN+"����"+NOR+"����ִ������ӳ�������$n��$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : GRN"����"NOR,
	"lvl" : 5,
	"damage_type" : "������"
]),
([	"action" : "$Nʹһ�С�"+YEL+"�ӽ�����"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : YEL"������ʽ"NOR,
	"lvl" : 10,
	"damage_type" : "������"
]),
([	"action" : "$N���н�������ʹһ�С�"+HIC+"�׺�����"+NOR+"��������$n�����ź�$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIC"�׺�����"NOR,
	"lvl" : 15,
	"damage_type" : "������"
]),
([	"action" : "$N����΢ת��ʹһ�С�"+HIW+"§ϥ�ֲ�"+NOR+"��������$n��$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIW"§ϥ�ֲ�"NOR,
	"lvl" : 20,
	"damage_type" : "������"
]),
([	"action" : "$Nִ���������������ָ񵲣�һ�С�"+MAG+"�ֻ�����"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : MAG"�ֻ�����"NOR,
	"lvl" : 25,
	"damage_type" : "������"
]),
([	"action" : "$Nִ�������´�����һ�С�"+RED+"��׿���"+NOR+"��������$n��$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : RED"��׿���"NOR,
	"lvl" : 30,
	"damage_type" : "������"
]),
([	"action" : "$N���ǰ̤�벽��ִ��ʹһ�С�"+YEL+"������"+NOR+"����ָ������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : YEL"������"NOR,
	"lvl" : 35,
	"damage_type" : "������"
]),
([	"action" : "$N�С�"+GRN+"��ͨ��"+NOR+"�������һ����������ִ����$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : GRN"��ͨ��"NOR,
	"lvl" : 40,
	"damage_type" : "������"
]),
([	"action" : "$N��������ԣ�ִ��ʹһ�С�"+HIC+"б��ʽ"+NOR+"��������$n��$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIC"б��ʽ"NOR,
	"lvl" : 45,
	"damage_type" : "������"
]),
([	"action" : "$N�����鰴��ִ��ʹһ�С�"+YEL+"��������"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : YEL"��������"NOR,
	"lvl" : 50,
	"damage_type" : "������"
]),
([	"action" : "$Nִ����ǰ��󻮻���һ�С�"+HIC+"˫����"+NOR+"������$n��$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIC"˫����"NOR,
	"lvl" : 55,
	"damage_type" : "������"
]),
([	"action" : "$N�����黮��ִ��һ�ǡ�"+WHT+"ָ�ɴ�"+NOR+"������$n���ɲ�",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : WHT"ָ�ɴ�"NOR,
	"lvl" : 60,
	"damage_type" : "������"
]),
([	"action" : "$Nʩ����"+MAG+"������"+NOR+"����ִ������$n��$l�����ֹ���$n���ɲ�",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : MAG"������"NOR,
	"lvl" : 65,
	"damage_type" : "������"
]),
([	"action" : "$N�ɱ۴���������������һ�С�"+RED+"�ƽ�"+NOR+"��������$n��$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : RED"�ƽ�"NOR,
	"lvl" : 70,
	"damage_type" : "������"
]),
([	"action" : "$N��������ִ��ʹһ�С�"+YEL+"�𼦶���"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : YEL"�𼦶���"NOR,
	"lvl" : 75,
	"damage_type" : "������"
]),
([	"action" : "$Nִ�����ϣ��Ƴ�һ�С�"+HIC+"��̽��"+NOR+"��",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIC"��̽��"NOR,
	"lvl" : 80,
	"damage_type" : "������"
]),
([	"action" : "$Nִ��ʹһʽ�С�"+MAG+"��Ů����"+NOR+"����������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : MAG"��Ů����"NOR,
	"lvl" : 85,
	"damage_type" : "������"
]),
([	"action" : "$Nִ������ǰƲ����ʹһ�С�"+HIG+"����Ʋ��"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIG"����Ʋ��"NOR,
	"lvl" : 90,
	"damage_type" : "������"
]),
([	"action" : "$N�����鰴��ִ��ʹһ�С�"+HIB+"����"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 100,
	"skill_name" : HIB"����Ž�"NOR,
	"lvl" : 100,
	"damage_type" : "������"
]),
([	"action" : "$N�������ϻ�����ִ��ʹһ�С�"+RED+"��������"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 102,
	"skill_name" : RED"��������"NOR,
	"lvl" : 120,
	"damage_type" : "������"
]),
([	"action" : "$Nʹһ�С�"+YEL+"�Դ���"+NOR+"��������§��ϥ��ִ�����¿���$n��$l",
	"force" : 100,
	"dodge" : 100,
	"parry" : 115,
	"skill_name" : YEL"�Դ���"NOR,
	"lvl" : 140,
	"damage_type" : "������"
]),
([	"action" : "$N˫���ս�����һ�С�"+MAG+"Ұ�����"+NOR+"������$n��$l�����ſ�ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 119,
	"skill_name" : MAG"Ұ�����"NOR,
	"lvl" : 160,
	"damage_type" : "������"
]),
([	"action" : "$Nִ��һ�ӣ�һ�С�"+HIC+"������"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 100,
	"parry" : 115,
	"skill_name" : HIC"������"NOR,
	"lvl" : 180,
	"damage_type" : "������"
]),
([	"action" : "$Nִ������ǰ�̣�һʽ��"+HIY+"ʮ�ִ�"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 102,
	"parry" : 122,
	"skill_name" : HIY"ʮ�ִ�"NOR,
	"lvl" : 200,
	"damage_type" : "������"
]),
([	"action" : "$Nִ��ǰ�̽�̤���ǣ�һ�С�"+HIM+"��������"+NOR+"������$n��$l��ȥ",
	"force" : 100,
	"dodge" : 110,
	"parry" : 133,
	"skill_name" : HIM"��������"NOR,
	"lvl" : 210,
	"damage_type" : "������"
]),
([	"action" : "$N��������ڳ�ִ���̳���ʹһ�С�"+HIG+"����｣"+NOR+"������$n��$l�����Ŵ�ȥ",
	"force" : 115,
	"dodge" : 132,
	"parry" : 121,
	"skill_name" : HIG"����｣"NOR,
	"lvl" : 220,
	"damage_type" : "������"
]),
([	"action" : "$N����Ϊ�ᣬһ�С�"+HIC+"ת�����"+NOR+"������$n���ֽ�Ӱ֮��",
	"force" : 120,
	"dodge" : 154,
	"parry" : 145,
	"skill_name" : HIC"ת�����"NOR,
	"lvl" : 230,
	"damage_type" : "������"
]),
([	"action" : "$Nִ��ǰͻ�����һ�С�"+HIR+"�乭�仢"+NOR+"����ֱ��$n���Ѷ�ȥ",
	"force" : 115,
	"dodge" : 166,
	"parry" : 175,
	"skill_name" : HIR"�乭�仢"NOR,
	"lvl" : 240,
	"damage_type" : "������"
]),
([	"action" : "$Nִ��������һ�С�"+GRN+"����Ʊ�"+NOR+"����һ�ɾ���ֱ��$n",
	"force" : 120,
	"dodge" : 178,
	"parry" : 185,
	"skill_name" : GRN"����Ʊ�"NOR,
	"lvl" : 250,
	"damage_type" : "������"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo)
{
	return combo == "wudang-zhang" || combo == "paiyun-shou";
}

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 600)
		return notify_fail("����ڹ���򲻹����޷�ѧ�������衣\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷����������衣\n");

	if ((int)me->query_skill("sword", 1) < 600)
		return notify_fail("��Ļ���������򲻹����޷�ѧ�������衣\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("qinglian-jiange", 1))
		return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������������衣\n");

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
	int i, level;
	level = (int) me->query_skill("qinglian-jiange", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 5, level / 5)];
}

string query_txt()
{
	return "Ҫ�󣺽���������1000���ڹ�����600����������6000�����ܵȼ����ܸ��ڻ�������"ZJBR
	"��Ч�����л�����ֵĿ��ֹ������Ա�����(�мܼ���/4+���ܵȼ�)�͹������ڹ�������ͬ�ȼ�1/3���ʴ��������������Կ���";
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp,mp2;

	if ((int)me->query_skill("qinglian-jiange", 1) < 100 ||
	    ! living(me))
		return;
    mp2 = ob->query_skill("never-defeated", 1)/2;
	mp = ob->query_skill("count", 1)+mp2;
	ap = ob->query_skill("force") + mp;
	dp = me->query_skill("parry") / 4 + me->query_skill("qinglian-jiange", 1);

	if (ap / 2 + random(ap) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(3))
		{
		case 0:
			result += (["msg" : HIC "$n" HIC "�溬΢Ц���ý�������"
					    "һ��ԲȦ����Ȼ��$N" +
					    HIC "�Ĺ���ȫ��������"NOR"\n"]);
			break;

		case 1:
			result += (["msg" : HIC "$n" HIC "�ӽ����Ҹ񵲣�"
					    "����$N" HIC "�Ĺ��������Ρ�"NOR"\n"]);
			break;

		default:
			result += (["msg" : HIC "$n" HIC "��������"
					    HIC "��������Ȼ������ȴ��$N"
					    HIC "�е�����ճ�ͣ������泩��"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(3))
		{
		case 0:
			result = HIY "$n" HIY "�溬΢Ц���ý�������"
				 "һ��ԲȦ��Ȼ��$N" +
				 HIY "��Ҳ�������ֻ���ֱ�룬��Ϯ$n"
				 HIY "��"NOR"\n";
			break;

		case 1:
			result = HIY "$n" HIY "�ӽ����Ҹ񵲣�"
				 "����$N" HIY "����ȴ�Ǳ仯�޷�������ѭ����"NOR"\n";
			break;

		default:
			result = HIY "$n" HIY "��������"
				 HIY "����������ȴ��$N"
				 HIY "�е�ճ�ͣ�����$N"
				 HIY "���̱仯���࣬�����п��ٽ���$n"
				 HIY "��"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

int query_effect_parry(object attacker, object me)
{
	int lvl;

	if (me->query_temp("weapon"))
		return 0;

	lvl = me->query_skill("qinglian-jiange", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("��������������������衣\n");

	me->receive_damage("qi", 50);
	me->add("neili", -100);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qinglian-jiange/" + action;
}
//�ȼ��������Ƿ�ѧ���µ���ʽ
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}