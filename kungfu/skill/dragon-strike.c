// dragon-strike.c ����ʮ����
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ����"+HIY+"�����л�"+NOR+"������$n��$l"NOR,
	"force"  : 640,
	"attack" : 170,
	"dodge"  : 10,
	"parry"  : 100,
	"damage" : 300,
	"skill_name" : HIY"�����л�"NOR,
	"damage_type": "����"
]),
([      "action" : "$NͻȻ���η���˫�ƾӸ�����һ�С�"+HIB+"��������"+NOR+"������$n��$l",     
	"force"  : 580,
	"attack" : 150,
	"dodge"  : 5,
	"parry"  : 80,
	"damage" : 200,
	"skill_name" : HIB"��������"NOR,
	"damage_type": "����"
]),
([      "action" : "$N����һ�С�"+HIG+"��������"+NOR+"����Ѹ���ޱȵ�����$n��$l",
	"force"  : 520,
	"attack" : 150,
	"dodge"  : 40,
	"parry"  : 145,
	"damage" : 200,
	"skill_name" : HIG"��������"NOR,
	"damage_type": "����"
]),
([      "action" : "$N˫��ʩ��һ�С�"+HIC+"�轥��½"+NOR+"�����������ŷ�������$n��$l",
	"force"  : 560,
	"attack" : 180,
	"dodge"  : 15,
	"parry"  : 130,
	"damage" : 200,
	"skill_name" : HIC"�轥��½"NOR,
	"damage_type": "����"
]),
([      "action" : "$N���ƾ۳�ȭ״������һ�С�"+HIM+"Ǳ������"+NOR+"����������$n��$l",
	"force"  : 580,
	"attack" : 190,
	"dodge"  : 10,
	"parry"  : 130,
	"damage" : 200,
	"skill_name" : HIM"Ǳ������"NOR,
	"damage_type": "����"
]),
([      "action" : "$Nʩ��һ�С�"+GRN+"�����"+NOR+"�������Ʋ�������������$n��$l",
	"force"  : 550,
	"attack" : 150,
	"dodge"  : 20,
	"parry"  : 180,
	"damage" : 200,
	"skill_name" : GRN"�����"NOR,
	"damage_type": "����"
]),
([      "action" : "$Nʹ����"+HIR+"ͻ������"+NOR+"�������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
	"force"  : 520,
	"attack" : 160,
	"dodge"  : 40,
	"parry"  : 150,
	"damage" : 200,
	"skill_name" : HIR"ͻ������"NOR,
	"damage_type": "����"
]),
([      "action" : "$N���һ����˫��ʹ����"+YEL+"�𾪰���"+NOR+"��������һ�а����$n",
	"force"  : 690,
	"attack" : 220,
	"dodge"  : 10,
	"parry"  : 75,
	"damage" : 200,
	"skill_name" : YEL"�𾪰���"NOR,
	"damage_type": "����"
]),
([      "action" : "$Nʹ����"+MAG+"��Ծ��Ԩ"+NOR+"������$n��$l��������",
	"force"  : 530,
	"attack" : 150,
	"dodge"  : 30,
	"parry"  : 140,
	"damage" : 200,
	"skill_name" : MAG"��Ծ��Ԩ"NOR,
	"damage_type": "����"
]),
([      "action" : "$N���λ�����˫��ʹһ�С�"+GRN+"˫��ȡˮ"+NOR+"��һǰһ����$n��$l",
	"force"  : 560,
	"attack" : 170,
	"dodge"  : 50,
	"parry"  : 115,
	"damage" : 200,
	"skill_name" : GRN"˫��ȡˮ"NOR,
	"damage_type": "����"
]),
([      "action" : "$Nʹ����"+HIB+"��Ծ��Ԩ"+NOR+"�������η���˫�Ʋ���һ����$n��$l����",     
	"force"  : 550,
	"attack" : 185,
	"dodge"  : 30,
	"parry"  : 100,
	"damage" : 200,
	"skill_name" : HIB"��Ծ��Ԩ"NOR,
	"damage_type": "����"
]),
([      "action" : "$N˫������ʹ����"+HIG+"ʱ������"+NOR+"����$n��������",
	"force"  : 570,
	"attack" : 180,
	"dodge"  : 50,
	"parry"  : 110,
	"damage" : 200,
	"skill_name" : HIG"ʱ������"NOR,
	"damage_type": "����"
]),
([      "action" : "$Nʹ����"+HIC+"���Ʋ���"+NOR+"�������Ʒ�ס$n����·������бб������$l",     
	"force"  : 560,
	"attack" : 170,
	"dodge"  : 15,
	"parry"  : 120,
	"damage" : 200,
	"skill_name" : HIC"���Ʋ���"NOR,
	"damage_type": "����"
]),
([      "action" : "$Nʹ����"+WHT+"��������"+NOR+"����˫�������������$n��$l",
	"force"  : 590,
	"attack" : 175,
	"dodge"  : 15,
	"parry"  : 100,
	"damage" : 200,
	"skill_name" : WHT"��������"NOR,
	"damage_type": "����"
]),
([      "action" : "$N����һת��ͻȻ�۵�$n��ǰ��һ�С�"+HIR+"��ս��Ұ"+NOR+"������$n��$l",     
	"force"  : 580,
	"attack" : 180,
	"dodge"  : 10,
	"parry"  : 95,
	"damage" : 200,
	"skill_name" : HIR"��ս��Ұ"NOR,
	"damage_type": "����"
]),
([      "action" : "$N�Ż��󿪣�һ�С�"+HIM+"��˪����"+NOR+"����$n��$l��ȥ",
	"force"  : 660,
	"attack" : 200,
	"dodge"  : 20,
	"parry"  : 90,
	"damage" : 200,
	"skill_name" : HIM"��˪����"NOR,
	"damage_type": "����"
]),
([      "action" : "$Nʹ����"+GRN+"����ެ"+NOR+"����˫���������ϻ���$n��$l",
	"force"  : 520,
	"attack" : 200,
	"dodge"  : 40,
	"parry"  : 130,
	"damage" : 200,
	"skill_name" : GRN"����ެ"NOR,
	"damage_type": "����"
]),
([      "action" : "$N���ƻ��أ�����ʹһ�С�"+HIR+"������β"+NOR+"�����»ζ��Ż���$n��$l",     
	"force"  : 520,
	"attack" : 200,
	"dodge"  : 60,
	"parry"  : 120,
	"damage" : 200,
	"skill_name" : HIR"������β"NOR,
	"damage_type": "����"
]),
});

string main_skill() { return "dragon-strike"; }

mapping sub_skills = ([
	"kanglong-youhui"  : 70,	// 1
	"feilong-zaitian"  : 70,	// 2
	"jianlong-zaitian" : 70,	// 3
	"hongjian-yulu"    : 70,	// 4
	"qianlong-wuyong"  : 70,	// 5
	"lishe-dachuan"    : 70,	// 6
	"turu-qilai"       : 70,	// 7
	"zhenjing-baili"   : 70,	// 8
	"huoyue-zaiyuan"   : 70,	// 9
	"shuanglong-qushui": 70,	// 10
	"yuyue-yuyuan"     : 70,	// 11
	"shicheng-liulong" : 70,	// 12
	"miyun-buyu"       : 70,	// 13
	"sunze-youfu"      : 70,	// 14
	"longzhan-yuye"    : 70,	// 15
	"lvshuang-bingzhi" : 70,	// 16
	"diyang-chufan"    : 70,	// 17
	"shenlong-baiwei"  : 70,	// 18
]);

int get_ready(object me)
{
	return 1;
}

int get_finish(object me)
{
	if (me->query("str") < 30 || me->query_str() < 45)
	{
		tell_object(me, "��������ϣ��ֱ�������������̧��������\n");
		return 0;
	}

	if (me->query("con") < 22 || me->query_con() < 37)
	{
		tell_object(me, "��������ϣ��;�����ǰ������ð��̫��Ѩͻͻ������\n");
		return 0;
	}

	if ((int)me->query_skill("force") < 150)
	{
		tell_object(me, "��������ϣ��������ѣ��Լ����ڹ�ˮƽ�������д���ߡ�\n");
		return 0;
	}

	if ((int)me->query("max_neili") < 1500)
	{
		tell_object(me, "��������ϣ������᲻��������������Ӧ�ü�������������\n");
		return 0;
	}

	if (random(10) < 5)
	{
		tell_object(me, "���ʮ���Ƶİ����������򣬻���������һ�ξ��ܹ��ڻ��ͨ��\n");
		return 0;
	}

	tell_object(me, HIY "��һ���ǳɣ���ʮ���ƴ�ͷ��β������һ�䣬���ж���ͨ\n"
			    "���˽���ʮ���Ƶİ���裬�ڻ��ͨ���Ʒ��ľ�΢֮����\n"
			    "��Ҳ�ǲ�ʹ����ô��ô�򵥡�"NOR"\n");
	return 1;
}

mapping query_sub_skills()
{
	return sub_skills;
}

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }  

int valid_learn(object me)
{
	if ((int)me->query("str") < 31)
		return notify_fail("���������ӹǻ�������ʮ���ƣ�С��Ū���˸첲��\n");

	if ((int)me->query("con") < 24)
		return notify_fail("���˰ɣ���������ǲ��ã���ǿѧ�ˡ�\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("����ڹ���򲻹����޷�ѧϰ����ʮ���ơ�\n");

	if ((int)me->query("max_neili") < 1500)
		return notify_fail("���������ô������ڻ��ͨ����ʮ���ƣ�\n");

	if ((int)me->query_skill("strike", 1) < 30)
		return notify_fail("��Ļ����Ʒ���򲻹����޷�ѧϰ����ʮ���ơ�\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("dragon-strike", 1))
		return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ľ���ʮ���ơ�\n");

	return 1;
}

int practice_skill(object me)
{
	int cost;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ʮ���Ʊ�����֡�\n");

	if ((int)me->query("qi") < 150)
		return notify_fail("�������̫���ˡ�\n");

	cost = me->query_skill("dragon-strike", 1) / 3 + 50;
	if ((int)me->query("neili") < 100)
		return notify_fail("�����������������ʮ���ơ�\n");

	me->receive_damage("qi", 120);
	me->add("neili", -cost);
	return 1;
}

mapping query_action(object me, object weapon)
{
        int tmp;
        tmp = 4 + random(15);

	if (random(8) == 0)
	{
	return ([
	"action": HIY  "$N" HIY"����΢�������ƻ��˸�ԲȦ��ƽ�Ƴ�ȥ�����ǽ���ʮ�����еġ������޻ڡ������Ƴ�ȥ�������赭д����һ��������ɲʱ֮������"  HIR  +chinese_number(tmp) + HIY "���ᾢ��һ��ǿ��һ�������ص�����ֱ���޼᲻�ݣ���ǿ���ƣ�"NOR"\n",
	"attack": 300,
	"dodge" : 100,
	"parry" : 100,
    "damage": 300 + tmp*20,
	"force" : 580,
	"damage_type": "����"]);
	}


	return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) >= 5||me->query("family/family_name") == "ؤ��")
	{
		victim->receive_wound("qi", damage_bonus / 6);
		return HIR "���������������������죬���ƹ������ѵ�������"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"dragon-strike/" + action;
}

void skill_improved(object me)
{
	int i;
	string *sub_skillnames;

	sub_skillnames = keys(sub_skills);
	for (i = 0; i < sizeof(sub_skillnames); i++)
		me->delete_skill(sub_skillnames[i]);
}
