// taiji-jian.c ̫����
// cleansword 2/15/96
// Marz 5/21/96
// Updated by Doing

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N�鲽������һ�С����ѵ�ˮ��������$w���������һ��������$n��$l",
	"force" : 25,
	"dodge" : 20,
	"parry" : 25,
	"lvl"   : 0,
	"damage_type" : "����"
]),
([      "action": "$N��ǰ����һ�������ֽ���������$wʹ��һʽ��ָ���롹ֱ��$n��$l",
	"force" : 30,
	"dodge" : 25,
	"parry" : 30,
	"lvl"   : 6,
	"damage_type" : "����"
]),
([      "action": "$N��������һ�죬���ֽ���������$wʹ��һʽ������ǡ�����$n��$l",
	"force" : 30,
	"dodge" : 35,
	"parry" : 35,
	"lvl"   : 12,
	"damage_type" : "����"
]),
([      "action": "$N˫ϥ�³�������$wʹ��һʽ��̽��ʽ�������¶��ϼ���$n��$l",
	"force" : 35,
	"dodge" : 35,
	"parry" : 40,
	"lvl"   : 15,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С������Ӳ�����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 35,
	"dodge" : 45,
	"parry" : 45,
	"lvl"   : 18,
	"damage_type" : "����"
]),
([      "action": "$N���������һš��һ�С�������β��������$w������$n��$l��ȥ",
	"force" : 35,
	"dodge" : 45,
	"parry" : 55,
	"lvl"   : 21,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$n��$l",
	"force" : 40,
	"dodge" : 60,
	"parry" : 55,
	"lvl"   : 24,
	"damage_type" : "����"
]),
([      "action": "$N������ϥ������$wбָ��һ�С�����Ͷ�֡�����$n��$l",
	"force" : 40,
	"dodge" : 55,
	"parry" : 60,
	"lvl"   : 27,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�������ˮ����$w���¶��ϻ���һ���󻡣�ƽƽ�ػ���$n��$l",
	"force" : 45,
	"dodge" : 65,
	"parry" : 65,
	"lvl"   : 30,
	"damage_type" : "����"
]),
([      "action": "$Nʹ�����������¡���$w��������ԲȦ������ֱ�������಻�ϻ���$n��$l",
	"force" : 45,
	"dodge" : 70,
	"parry" : 70,
	"lvl"   : 35,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�����Ҷ����$w����ػ�������Բ����Ѹ�ٵ���$n��$l��ȥ",
	"force" : 50,
	"dodge" : 75,
	"parry" : 80,
	"lvl"   : 40,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�����ͷ����$w����һ������ҸߵĴ󻡣�бб��ն��$n��$l",
	"force" : 50,
	"dodge" : 75,
	"parry" : 80,
	"lvl"   : 45,
	"damage_type" : "����"
]),
([      "action": "$Nʹ����ʨ��ҡͷ����$w�������󻮳�һ�����֣���$nȦ������",
	"force" : 55,
	"dodge" : 85,
	"parry" : 80,
	"lvl"   : 50,
	"damage_type" : "����"
]),
([      "action": "$N���̤ʵ���ҽ���㣬һ�С�����ָ·��������$w����һ�Ž���������$n��$l",
	"force" : 55,
	"dodge" : 95,
	"parry" : 80,
	"lvl"   : 60,
	"damage_type" : "����"
]),
([      "action": "$N����Ծ��һ�С�Ұ����������$w�ڰ���л�ΪһȦ��â������$n��$l",
	"force" : 60,
	"attack": 3,
	"dodge" : 95,
	"parry" : 90,
	"lvl"   : 80,
	"damage_type" : "����"
]),
([      "action": "$N����ǰ���󹭣�һ�С�����ʽ��������$wֱ��$n��$l",
	"force" : 65,
	"attack": 5,
	"dodge" : 100,
	"parry" : 100,
	"lvl"   : 100,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�С���ǡ�����������һ�죬���ֽ���������$wƽƽ����$n��$l��ȥ",
	"force" : 70,
	"attack": 7,
	"dodge" : 100,
	"parry" : 105,
	"damage": 1,
	"lvl"   : 110,
	"damage_type" : "����"
]),
([      "action": "$N������ϣ�һ�С���Գ�׹���������$wбб����$n��$l��ȥ",
	"force" : 75,
	"attack": 10,
	"dodge" : 110,
	"parry" : 120,
	"damage": 2,
	"lvl"   : 120,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�ӭ�絧������$w���������һ�ӣ�$nȴ����һ�ɾ���ӭ��Ϯ����",
	"force" : 80,
	"attack": 12,
	"dodge" : 105,
	"parry" : 115,
	"damage": 4,
	"lvl"   : 130,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�˳ˮ���ۡ���$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ��",
	"force" : 85,
	"attack": 15,
	"dodge" : 115,
	"parry" : 125,
	"damage": 5,
	"lvl"   : 140,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С����Ǹ��¡���$w����$n��$l",
	"force" : 90,
	"attack": 18,
	"dodge" : 135,
	"parry" : 125,
	"damage": 8,
	"lvl"   : 150,
	"damage_type" : "����"
]),
([      "action": "$NͻȻ�̶���������һ�С��������¡���$w���¶��ϵ���$n��$l��ȥ",
	"force" : 95,
	"attack": 20,
	"dodge" : 125,
	"parry" : 125,
	"damage": 12,
	"lvl"   : 160,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�����ʽ����$w���¶������컮��һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 100,
	"attack": 22,
	"dodge" : 135,
	"parry" : 145,
	"damage": 17,
	"lvl"   : 170,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С��Ʒ��붴����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 105,
	"attack": 25,
	"dodge" : 140,
	"parry" : 165,
	"damage": 20,
	"lvl"   : 180,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�����չ�᡹������Ծ������$w����$n��$l",
	"force" : 110,
	"attack": 28,
	"dodge" : 145,
	"parry" : 155,
	"damage": 22,
	"lvl"   : 190,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С����ֽ�����$w����һƬ���̣�ƽƽ����$n��$l��ȥ",
	"force" : 115,
	"attack": 28,
	"dodge" : 155,
	"parry" : 175,
	"damage": 25,
	"lvl"   : 200,
	"damage_type" : "����"
]),
([      "action": "$N��������棬������ǰһ�ˣ�һ�С������пա���$w��$n��$l��ȥ",
	"force" : 120,
	"attack": 29,
	"dodge" : 165,
	"parry" : 180,
	"damage": 31,
	"lvl"   : 210,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С���ɨ÷����������Ծ�ڰ�գ�����$wɨ��$n��$l",
	"force" : 125,
	"attack": 32,
	"dodge" : 175,
	"parry" : 185,
	"damage": 33,
	"lvl"   : 220,
	"damage_type" : "����"
]),
([      "action": "$Nһ�С�ȴ���齣�������Ծ����أ�$w�س飬���ֹ���$n��$l",
	"force" : 130,
	"attack": 35,
	"dodge" : 185,
	"parry" : 200,
	"damage": 34,
	"lvl"   : 230,
	"damage_type" : "����"
]),
([      "action": "$N���Ȱ�����ף�һ�С�����Ʊա���������ָ��ת������$n��$l",
	"force" : 135,
	"attack": 38,
	"dodge" : 185,
	"parry" : 220,
	"damage": 37,
	"lvl"   : 240,
	"damage_type" : "����"
]),
([  "action" : "$N����š���������鱧��һ�С�����հ�ա���$w�й�ֱ��������$n��$l",
	"force" : 150,
	"attack": 40,
	"dodge" : 220,
	"parry" : 220,
	"damage": 40,
	"lvl" : 250,
	"damage_type" : "����"
]),
});

string *taiji_msg = ({
"$N"HIW"����������һʽ���ֻ����ҡ������鸧�����ֳ������ֻ�������㽣������$n"HIW"����ʵ����"NOR,
"$N"HIW"Ŀ��Զ�����·ɣ���̾һ������������$w"HIW"�������������������ƾ��Ƕϣ����������콣Ӱ"NOR,
"����$N"HIW"�������¿��ϡ�����������ʵ�ѵ���̫�������ľ���"NOR,
"$N"HIW"����$w"HIW"��ʹ�ü��죬ȴ˿����������������֮�����������֮�����Ѵ��ڻ���"NOR,
"$N"HIW"���������Ҫ֮���������˳�������ս��ǿ��$w"HIW"�������ھ�������ǿ"NOR,
"$N"HIW"��������������ﳤ����������$n"HIW"������$P$w"HIW"һ��������һ�ƽ�������"NOR,
"$N"HIW"����$n"HIW"��ʽ������������֮�ơ���ׯ��֮�Σ��������ն���������������������˸����"NOR,
"$N"HIW"�����ٻ������ǽ���������֮�٣�ʵ������"NOR,
"$N"HIW"����$w"HIW"������ǰ��������һ���Σ�һ��ɭɭ������ֱ����$n"HIW"��ͻȻ֮�䣬$N"HIW"�������֣�����һ����$n"HIW"��$l"HIW"��ȥ"NOR,
"$N"HIW"����ͻ�䣬���������������Լ����������ʹ����������������������������⵴������������"NOR,
"$N"HIW"����Ѹ�ݣ����ǽ���������֮�٣�ʵ������"NOR,
"$N"HIW"$w"HIW"����һ�д�����Լ�֮�ۣ�����֮�޷棬���������ᴫ�ڵ�̫���������⡹�ľ�������"NOR,
"$N"HIW"��Ȼ�����У����ж�δ��ʹ�ϣ���ȻȦת�����������˳�һ�㣬����ӿ��$n"HIW""NOR,
"$N"HIW"��ʽ����Ʈ��֮���������й��ӻ�񣬽��ϵ������ƺ�ֻ���ӵ�һ���ɣ������ȴ�������Դ�����ز�¶"NOR,
"�������������$N"HIW"����$w"HIW"���˳�ȥ����������ƽ�̣������������"NOR,
"$N"HIW"˫��ע��$n"HIW"������$w"HIW"���������߰��ԣ��ν�һ���й�ͦ�������ƻ���������ʵ��������ϳ�̫��֮�������ܱٽ����"NOR,
"$N"HIW"����û����ʽ��������ȫ�ǡ����ڽ��ȡ����಻����֮�⣬һ˿˿����$n"HIW""NOR,
"$N"HIW"������Ȧ��һ�㺮�Ǵ���$n"HIW""NOR,
"����$N"HIW"������$w"HIW"������������ֻ��˸���Բ������$n"HIW""NOR,
"$N"HIW"����һ�ӣ�$w"HIW"��������б����������һ�������ƿ�������֤�������Ѵﷴ�ӹ���ľ���"NOR,
"$N"HIW"$w"HIW"�ڿ��л��ɴ�Ȧ�����ֽ�������������Ҳ��������΢��"NOR,
"$N"HIW"����̤�ϣ��������֣�һ�С��������¡���һ������ʵʵ�������ֽ����У������Ϲ�â��˸�������͵ķ�����΢����"NOR,
"$N"HIW"���ӻ�����ת�����ֳֽ������������𣬽��������ǰ������������ԣ�˫�۳ɻ�������$w"HIW"�������Ȼ��������"NOR,
"$N"HIW"һ���̵�����������������������죬������ǿ"NOR,
"$N"HIW"�������Ž���������$w"HIW"��ס�Ķ���������$n"HIW"�����ߴ�ҪѨ�����⼱��������������δ�"NOR,
"$N"HIW"���ֽ���б����$w"HIW"�����������Բ������������ֱ��$n"HIW"$l"HIW""NOR,
"$N"HIW"����һ���˿�������$w"HIW"�������಻������������"NOR,
"$N"HIW"����$w"HIW"ʹ����Ӧ�֣��켫���������о��棬�����鶯����ò��⣬ͻȻ���󷭽���ֱ��$n"HIW"��$l"HIW"��ȥ"NOR,
"$N"HIW"$w"HIW"�ݳ���˳��$n"HIW"��·���£��Լ�֮�ۣ�����֮�޷棬ʵ�ѵ���̫�������ľ���"NOR,
"$N"HIW"����Ԧ����ǧ���򻯣������޾���ÿһ�ж�����ƽ����ʵ�������Դ�����ز�¶"NOR,
"$N"HIW"��$w"HIW"����һ����ԲȦ��ÿһ�о����Ի��δ̳����Ի����ջ�"NOR,
"$N"HIW"����Ԧ�������ڽ��ȣ����಻�������п��������̣������࣬ʵ��ǧ���򻯣������޾�"NOR,
"$N"HIW"������Х�������ݺ�仯������޷���$w"HIW"����������ʹ֮����������������ɵ�"NOR,
"$N"HIW"���о��ް�����ң������˽���$w"HIW"ÿ��һ�У����Ʒų�һ��ϸ˿��Ҫȥ��ס$n"HIW""NOR,
"$N"HIW"�������У���˵����ȥȥֻ��һ�У�Ȼ����һ��ȴ����Ӧ������"NOR,
"$N"HIW"�������¿��ϡ�������������̫���������Ҫ֮���������˳���������һ���˿������಻��"NOR,
"$N"HIW"����$w"HIW"������ǰ��������һ���Ρ�$n"HIW"ֻ��һ��ɭɭ������ֱ�ƹ���"NOR,
"$N"HIW"������������������$w"HIW"��ס������ͻȻƽ�̣����⼱��������������δ���$P"HIW"��һ����������$n"HIW"�����ߴ�ҪѨ"NOR,
"$N"HIW"����δ��ʹ�ϣ���ȻȦת��ͻȻ֮�䣬$n"HIW"��ǰ�����˼�����ɫ��Ȧ����ȦСȦ����ȦбȦ����˸����"NOR,
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("����ڹ����̫ǳ��\n");

	if ((int)me->query_skill("taiji-quan", 1) < 100)
		return notify_fail("���̫��ȭ���̫ǳ��\n");
	if ( me->query_skill("taiji-jian", 1) > me->query_skill("taiji-quan", 1)+30 )
		return notify_fail("ѧϰ̫��������̫��ȭΪ������\n");
	if ( me->query_skill("taiji-jian", 1) > me->query_skill("taiji-shengong", 1)+30 )
		return notify_fail("ѧϰ̫��������̫����Ϊ������\n");

	if ((int)me->query_skill("sword", 1) < 100)
		return notify_fail("��Ļ����������̫ǳ��\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("taiji-jian", 1))
		return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������̫��������\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	string str;
	level = (int) me->query_skill("taiji-jian", 1);

	if( me->query_temp("tjj/sanhuan") ) {
		switch(me->query_temp("tjj/sanhuan")){
			case 3: str = HIG"$N"HIG"ʹ�����������¡�����ʽһ�䣬���ָ����ѣ������н������������������һ��Բ����$w"HIG"��$n��������"NOR; break;
			case 2: str = HIG"Ȼ��$N"HIG"�ƽ�һ�����������У��������У�ͬ��һ�����Żӳ�����������������һ��ͣ�ٵĺۼ�"NOR; break;
			case 1: str = HIG"������ӣ�$N"HIG"���е�$w"HIG"��һ�λӳ�����$n$l���������������������������������ͬ�����ϵ�������֮��"NOR; break;
			default: str = HIG"$Nʹ�����������¡�����ʽһ�䣬���ָ����ѣ������н������������������һ��Բ����$w"HIG"��$n��������"NOR; break;
		}
		if( me->query_temp("tjj/sanhuan") > 0 )
			me->add_temp("tjj/sanhuan", -1);
		return ([
			"attack": 200,
			"action":str,
			"dodge": random(100),
			"parry": random(30),
			"force": 400 + random(250),
			"damage": 300 + random(100),
			"damage_type": "����",
		]);
	}

	if( level > 349 )
		return ([
			"action": HIW+replace_string(replace_string(taiji_msg[random(sizeof(taiji_msg))], "$w", "$w"), "$w", "$w")+NOR,
			"dodge": random(100),
			"parry": random(30),
			"attack": 200,
			"force": 350 + random(250),
			"damage": 150 + random(100),
			"damage_type": "����",
		]);

	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];

}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp;
	object m_weapon;

	if ((int) me->query_skill("taiji-jian", 1) < 100 ||
	    ! (m_weapon = me->query_temp("weapon")) ||
          m_weapon->query("skill_type") != "sword"||
	    ! living(me) )
		return;

	//mp = ob->query_skill("count", 1);
	//ap = ob->query_skill("force") + mp;
	//dp = me->query_skill("parry", 1) / 2 +
	     //me->query_skill("taiji-jian", 1);
		 
	mp = ob->query_skill("count", 1) + ob->query_skill("never-defeated", 1)/3 + ob->query_skill("jiuyin-shengong", 1)/3 + ob->query_skill("kuihua-mogong", 1)/3 + ob->query_skill("bluesea-force", 1)/3;
	ap = ob->query_skill("force")*3/4 + mp;
	dp = me->query_skill("parry")/4 + me->query_skill("taiji-jian", 1)+ (me->query_skill("never-defeated", 1)/3 + me->query_skill("jiuyin-shengong", 1)/3 + me->query_skill("kuihua-mogong", 1)/3 + me->query_skill("bluesea-force", 1)/3)*me->query_skill("tianwei-zhengqi", 1)/100;

	if (ap *2/ 3 + random(ap) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(3))
		{
		case 0:
			result += (["msg" : HIC "$n" HIC "һ�����е�" + m_weapon->name() +
					    HIC "��������һ��ԲȦ����Ȼ��$N" +
					    HIC "�Ĺ���ȫȻ��ա�"NOR"\n"]);
			break;

		case 1:
			result += (["msg" : HIC "$n" HIC "����" + m_weapon->name() +
					    HIC "��������ָ��$N" HIC "�����е�������"NOR"\n"]);
			break;

		default:
			result += (["msg" : HIC "$n" HIC "�ζ����е�" + m_weapon->name() +
					    HIC "����ס�ı�ý��ƣ���$N"
					    HIC "��ȫ�޷���׽��������"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(3))
		{
		case 0:
			result = HIY "$n" HIY "һ�����е�" + m_weapon->name() +
				 HIY "��������һ��ԲȦ��$N"
				 HIY "��Ҳ������������ֱ�룬��Ϯ$n"
				 HIY "��"NOR"\n";
			break;

		case 1:
			result = HIY "$n" HIY "����" + m_weapon->name() + "������"
				 HIY "��ָ��$N" HIY "�����е�����������$N"
				 HIY "����һ�䣬�������̲���Ϊ������"NOR"\n";
			break;

		default:
			result = HIY "$n" HIY "�ζ����е�" + m_weapon->name() +
				 HIY "����ס�ı�ý��ƣ�Ȼ��$N"
				 HIY "������񣬾���������˿������$n"
				 HIY "���Ի�\n"  NOR;
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 100)
		return notify_fail("�������������̫��������\n");

	if ((int)me->query("neili") < 120)
		return notify_fail("�������������̫��������\n");

	me->receive_damage("qi", 50);
	me->add("neili", -100);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon;
	
	if (random(10) < 7)
	{
			victim->receive_wound("qi", damage_bonus / 6, me);
		return HIY "$N" HIY "���б���һ�٣�������ת��$n" HIY "ֻ��һ�����������ѱ�̫���������ˣ�"NOR"\n"HIR"����Ѫ���� -"+damage_bonus/6+"��"NOR"\n";
	}
}

/*mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon;
	
	if (random(10) >= 5)
	{
			victim->receive_wound("qi", damage_bonus / 4, me);
			return HIC "$N" HIC "Ĭ�˷�������" NOR + weapon->name() +
			       HIC "�ϣ������ɵ��ع���$n" HIC"�����ƻֺ�֮����"NOR"\n";
	}
}*/

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}
