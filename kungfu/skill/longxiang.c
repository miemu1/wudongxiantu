//
// longxiang.c ���������
//

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
	return force == "mizong-neigong" || force == "xiaowuxiang";
}

void skill_improved(object me)
{
	int lvl;

	lvl = me->query_skill("longxiang", 1);
	if (lvl > 360)
		return;

	if (lvl % 30)
		write(HIY "���������˵�" + chinese_number(lvl / 30 + 1) +
		      "�������������"NOR"\n");
	else
		write(HIR "��ĵ�" + chinese_number(lvl / 30 + 1) +
		      "�������������������һ�㡣"NOR"\n");
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("longxiang", 1);
    if (lvl>=300) 
              return lvl * lvl * 15 * 25 / 100 / 200;
	else 
              return lvl * lvl * 15 * 15 / 100 / 200;
}

int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < 70)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if (me->query("gender") == "����" && (int)me->query_skill("longxiang", 1) > 49)
		return notify_fail("���޸����ԣ���������������������������������\n");

	if (me->query("str") < 24)
		return notify_fail("�������������㣬�޷�ѧϰ���͵������������\n");

	if (me->query("con") < 30)
		return notify_fail("������������е����Ҫ�㹻��������ǲ��ܷ��ӳ�ǿ���������������ǻ��Ǳ��˷�ʱ���ˡ�\n");

	return ::valid_learn(me);
}

mixed valid_fdamage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp;

	if (random(3)==1 || (int) me->query("con") < 31 || (int) me->query_skill("longxiang", 1) < 100 || ! living(me))
		return;

	ap = ob->query_skill("force");
	dp = me->query_skill("force");

	if (ap / 2 + random(ap) < dp)
	{
		result = HIC "$N" HIC "һ�л���$n" HIC "��ȴ�о�$n" HIC "����һ�ɼ���ǿ�ҵ��ھ���Ȼ����������\n"+
				COMBAT_D->do_respond(me, ob, damage, (me->query("con")-28)*6, HIR "$Pֻ��һ�ɰ���������������ʱһ����Ѫ��ӿ��"NOR"\n");
		return result;
	}
}

int practice_skill(object me)
{
	return notify_fail("���������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"longxiang/" + func;
}

int difficult_level()
{
	object me;
	int lvl;

	if (me = this_player())
	{
		// ��С���๦������ѧϰ��
		if (lvl = me->query_skill("xiaowuxiang", 1))
			return 3000;

		// �о����񹦣�����ѧϰ��
		if (lvl = me->query_skill("jiuyang-shengong", 1))
			return 500;
	}

	return 100;
}
