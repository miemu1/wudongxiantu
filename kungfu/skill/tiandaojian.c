//tiandaodao ���콣

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w���ƣ�ʹ��һ���ƺ�,����������$n��ȥ",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 0,
	"skill_name" : "�ƺ�",
	"damage_type" : "����"
]),
([      "action" : "$Nһ��ɽ��,�������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ�л���$n�ľ���",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 100,
	"skill_name" : "ɽ��",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ��һ�з籩��$w��������һ��ѹ��$n",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 200,
	"skill_name" : "�籩",
	"damage_type" : "����"
]),
([      "action" : "$N����$w��ת��Ծ��һ�б���һ���׹�����$n���ؿ�",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 300,
	"skill_name" : "����",
	"damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ���һ��������ã����ҿ�����������$n",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 400,
	"skill_name" : "�һ�",
	"damage_type" : "����"
]),
([      "action" : "$Nһ����أ����Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 500,
	"skill_name" : "���",
	"damage_type" : "����"
]),
([      "action" : "$N���ʹһ�����죬��ʱ�����������佣��������˷�ӿ��$nȫ��",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 600,
	"skill_name" : "����",
	"damage_type" : "����"
]),
});
string main_skill()
{
        return "tiandaojian";
}

mapping sub_skills = ([
        "yuxiao-jian"  : 500,
        "lonely-sword"  : 500,
        "wuzhan-mei"  : 500,
        ]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;
		
        if (me->query_skill("wudao-shanqian", 1))
        {
                tell_object(me, "��������ϣ������Դ�ͨ�������ǧ����"
                                "�ֿ�������ȫȻ���á�\n");
                return 0;
        }
        if( me->query("int")<60 )
        {
                tell_object(me, "��������ϣ�ֻ��˼�����ң�������������ԣ���"
                                "�������һ��\n");
                return 0;
        }
        if( me->query("con")<60 )
        {
                tell_object(me, "��������ϣ�ֻ��ȫ�������Ҵܣ���ð���ǣ�������������"
                                "�����ײſ���������\n");
                return 0;
        }
        if( me->query("str")<60 )
        {
                tell_object(me, "��������ϣ�ֻ��˫�����ۣ�ȫ����\n");
                return 0;
        }
        if( me->query("dex")<60 )
        {
                tell_object(me, "��������ϣ��������������ʱ���޷������ڻ��ͨ��\n");
                return 0;
        }

        if( me->query("age") >= 18 )
        {
                                tell_object(me, "���Ѵ�����������ʱ�̣��������ڴ˸�����ѧ��Ե��\n");
                return 0;
        }

        if (random(100) != 1 && ! wizardp(me))
        {
                tell_object(me, "������������򣬻���������һ�ξ����ڻ��ͨ�������������\n");
                return 0;
        }

        tell_object(me, HIW "һ�󷲳�����ӿ����ͷ���㼸��������̾�����Ǽ䣬����ۻ��ף�����һ��Ī��\n"
                        "�ı�������ʦ̩�����ָ߳���ʤ������̩ɽ��С����֮����Ȼ��������ֻ������\n����"
                        "��ѧ���ڿ����Ƕ�ô����С��Ц��\n" NOR);

        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name() + "������"HIY"�����"HIM"��\n");
        return 1;
}
mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage) { return usage == "sword"; } 

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 5000)
		return notify_fail("���������Ϊ̫ǳ��\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("��Ļ����ڹ���Ϊ���㡣\n");

	if ((int)me->query_skill("martial-cognize") < 100)
		return notify_fail("����ù�����£����Լ�����ѧ����ȫȻ�޷����ס�\n");

		if (me->query("str") < 60)
                return notify_fail("���������������޷�ѧϰ��\n");
        if (me->query("dex") < 60)
                return notify_fail("��������������޷�ѧϰ��\n");
		if (me->query("int") < 60)
                return notify_fail("����������̲����޷�ѧϰ��\n");
        if (me->query("con") < 60)
                return notify_fail("���������ǲ����޷�ѧϰ��\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("tiandaojian", 1))
		return notify_fail("��Ļ�������ˮƽ���ޡ�\n");

	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int lvl;
	int i;

	lvl = me->query_skill("martial-cognize", 1);
	i = random(lvl);

	if (i > 100)
	{
		if (i < 200)
		{
			victim->receive_wound("qi", damage_bonus / 4);
			return HIC "ֻ��$N" HIC "����һ̽����â���ǣ�����$n��"NOR"\n";
		}
		if (i < 400)
		{
			victim->receive_wound("qi", damage_bonus / 2);
			return HIY "ֻ��$N" HIY "һ����Х��������ɣ�$n" HIY "�������У�"NOR"\n";
		} else
		{
			victim->receive_wound("qi", damage_bonus);
			return HIW "����$N" HIW "΢΢һЦ�������ƶ��콣��$n" HIW "��Ȼ���У�"NOR"\n";
		}
	}
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
   int i, j, level;
   level   = (int) me->query_skill("tiandaojian",1);
   for(i = sizeof(action); i > 0; i--) {
       if(level > action[i-1]["lvl"]) {
           j = NewRandom(i, 20, level/4);
       if((int)me->query_skill("tiandaodao",1) > 500 ){
       return ([
               "action" : HIR+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR)+NOR,
               "force" : 1000,
               "dodge": 1000,
               "parry" : 1000,
               "damage" : 1000,
               "damage_type" : "����",
                ]);
       }
       else return action[j];
       }
}
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 65)
		return notify_fail("�������������\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("�������������\n");

	me->receive_damage("qi", 60);
	me->add("neili", -16);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiandaojian/" + action;
}

