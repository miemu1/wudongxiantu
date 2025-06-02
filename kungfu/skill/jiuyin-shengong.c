// jiuyin-shengong.c ������

inherit FORCE;

string *dodge_msg = ({
	"$n��Ҳ��������$N��һ�ߡ�\n",
	"$n����΢΢һ������$N���ˡ�\n",
	"$n�������һ�Σ�$N��Ȼ�޷�������ֻ���Ա���\n",
	"$n����һ�񣬽��������н�������ȫ��������\n",
});

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("jiuyin-shengong", 1);
	return lvl * lvl * 22 * 15 / 100 / 200;
}

mapping *action = ({
([      "action":"$N����һ̽�����޻��ɵ�Ϯ��$n",
	"force" : 510,
	"attack": 190,
	"dodge" : 100,
	"parry" : 90,
	"damage": 180,
	"damage_type":  "����"
]),
([      "action":"$N˫����ץ������$n��$l",
	"force" : 510,
	"attack": 185,
	"dodge" : 90,
	"parry" : 120,
	"damage": 175,
	"damage_type":  "ץ��"
]),
([      "action":"$N����һת��ȭͷ�ӳ�������$n��$l",
	"force" : 530,
	"attack": 175,
	"dodge" : 90,
	"parry" : 110,
	"damage": 200,
	"damage_type":  "����"
]),
([      "action":"$N�Ʋ���ǰ��һ�Ʋ�������������$n��$l",
	"force" : 525,
	"attack": 185,
	"dodge" : 85,
	"parry" : 115,
	"damage": 185,
	"damage_type":  "����"
]),
([      "action":"$N����һ�࣬����һ�ţ�����$n��$l",
	"force" : 530,
	"attack": 165,
	"dodge" : 90,
	"parry" : 115,
	"damage": 200,
	"damage_type":  "����"
]),
([      "action":"$N˫�ֺ�ȭ������ſ���ץ��$n��$l",
	"force" : 540,
	"attack": 200,
	"dodge" : 115,
	"parry" : 120,
	"damage": 180,
	"damage_type":  "ץ��"
]),
});

string *usage_skills = ({ "finger", "strike"
			  "claw", "cuff", "dodge",
			  "parry", "force" });

int valid_enable(string usage)
{
	return (member_array(usage, usage_skills) != -1);
}

int valid_force(string force) { return 1; }

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
	if (random(10) == 8)
	{
		me->add("neili", -200);
		return ([
     "action":HIR"$N����һת��ȭͷ�ӳ�������$n��$l��$n�ܲ�����һ�ػ�����ͣ��Ѫ"NOR,
	"force" : 540,
	"attack": 400,
	"dodge" : 230,
	"parry" : 240,
	"damage": 360,
	"damage_type": "����"]);
	}
	return action[random(sizeof(action))];	
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	int level;
	int i;

	if ((int)me->query("combat_exp") < 10000000 && !me->query("relife/zhuanshi"))
		return notify_fail("����þ��������֮����"
				   "ƾ�Լ���ս����Ϊһʱ��������ᡣ\n");

	if ((int)me->query_skill("martial-cognize", 1) < 50)
		return notify_fail("����þ����񹦹�����£���"
				   "�Լ�����ѧ����ȫȻ�޷����ס�\n");

	if (me->query("character") != "��������")
		return notify_fail("����������ֺ룬����ٲȻ����"
				   "��ôҲѧ�������ơ�\n");

	if (me->query("str") < 30 && me->query_str() < 150)
		return notify_fail("�㷢���Լ����������㣬�޷�"
				   "���������������硣\n");

	if (me->query("gender") == "����" &&
	    (int)me->query_skill("jiuyin-shengong", 1) > 199)
		return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");

	level = me->query_skill("jiuyin-shengong", 1);

	if ((int)me->query_skill("martial-cognize", 1) < 400 &&
	    (int)me->query_skill("martial-cognize", 1) < level && !me->query("relife/zhuanshi"))
		return notify_fail("������Լ�����ѧ�������ޣ�������������ľ����񹦡�\n");

	if (me->query_skill("force", 1) < level)
		return notify_fail("��Ի����ڹ�����⻹�������޷�����"
				   "��������Ĳ����񹦡�\n");

	if (me->query_skill("parry", 1) < level)
		return notify_fail("��Ի����мܵ���⻹�������޷�����"
				   "��������Ĳ����񹦡�\n");

	if (me->query_skill("dodge", 1) < level)
		return notify_fail("��Ի����Ṧ����⻹�������޷�����"
				   "��������Ĳ����񹦡�\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����񹦲�����޷��򵥵�ͨ����ϰ������\n");
}
int difficult_level()
{
	return 1000;
}

string perform_action_file(string action)
{
	return __DIR__"jiuyin-shengong/perform/" + action;
}

string exert_function_file(string action)
{
	return __DIR__"jiuyin-shengong/exert/" + action;
}
