// roar.c

#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "��������"ZJBR"����̾Ϣ"; }

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if ((int)me->query("neili") < 10000)
		return notify_fail("�������������\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	skill = me->query_skill("force");

	me->add("neili", -10000);
	me->receive_damage("qi", 10);

	me->start_busy(5);
	message_combatd(HIY "$N" HBRED+HIY "����һ�����಻���ĳ���������գ�"
		    "����˺�ѣ�"NOR"\n", me);

	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
	{
		if (! living(ob[i]) || ob[i] == me) continue;
		if (skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2)
			continue;

		if (userp(ob[i]) && !ob[i]->die_protect(me))
			continue;

		damage = skill - ((int)ob[i]->query("max_neili")  / 1000);
		if (damage > 0)
		{
			ob[i]->receive_damage("jing", damage * 6 , me);
			if ((int)ob[i]->query("neili") < skill * 6)
				ob[i]->receive_wound("jing", damage, me);
			tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
		}

		me->want_kill(ob[i]);
		ob[i]->kill_ob(me);
	}

	return 1;
}
