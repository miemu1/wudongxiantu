// yijinjing.c ���� �׽��
// Feb.21 1998 by Java

inherit FORCE;

int is_shaolin_skill() { return 1; }

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_force(string force)
{
	return force == "hunyuan-yiqi" ||
	       force == "taiji-shengong" ||
	       force == "wudang-xinfa" ||
	       force == "shaolin-xinfa";
}

int query_neili_improve(object me)
{
	int lvl;
	
	lvl = (int)me->query_skill("yijinjing", 1);
       if (me->query("family/family_name") == "������")
              return lvl * lvl * 15 * 21 / 100 / 200;
	else 
              return lvl * lvl * 15 * 19 / 100 / 200;
}

int valid_learn(object me)
{
	if (me->query_skill("force", 1) < 100)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧϰ�׽�񹦣�\n");

	if (me->query_skill("freezing-force", 1)) 
		return notify_fail("���Ѿ����׽�񹦺ͱ��Ϻ�����������һ�����ڹ��ˡ�\n");

	if (me->query_skill("force", 1) < me->query_skill("yijinjing", 1))
		return notify_fail("��Ļ����ڹ�ˮƽ���������������������׽�񹦣�\n");

	if (me->query("gender") != "����" && me->query("gender") != "Ů��")
		return notify_fail("�㲻�в�Ů���޷���ϰ�׽�񹦡�\n");

	return ::valid_learn(me);
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	int ap, dp;
	int jiali;

	if ((int) me->query_skill("yijinjing", 1) < 100 ||
	    ! living(me))
		return;

	if ((jiali = ob->query("jiali")) < 1)
		return;

	ap = ob->query_skill("force") * 100 + ob->query("max_neili");
	dp = me->query_skill("force") * 100 + me->query("max_neili");

	if (ap *2/3 + random(ap) < dp)
	{
		result = ([ "damage" : -damage ]);

		switch (random(2))
		{
		case 0:
			result += (["msg" : HIR "$n" HIR "��������һ�ɷ���֮��," HIY "�׽��" + HIR "���Ķ��𣬳���$N" + HIR "��һ�С�"NOR"\n" ]);
			break;
		default:
			result += (["msg" : HIR "$N" HIR "һ�л���$n" HIR "����ȴ�ƻ���һ���޻����棬����Ϊ��ĺ�ǽ��һ�㣬����������"NOR"\n" ]);
			break;
		}

		return result;
	}
}

int practice_skill(object me)
{
	return notify_fail("�׽��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijinjing/" + func;
}
