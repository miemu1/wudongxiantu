// freezing-force.c 少林 冰蚕寒功
// Feb.21 1998 by Java

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_force(string force)
{
	return force == "guixi-gong";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("freezing-force", 1);
	return lvl * lvl * 15 * 18 / 100 / 200;
}

int valid_learn(object me)
{
    	if (me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，难以锻炼冰蚕寒功！\n");

	if (me->query_skill("yijinjing", 1))
		me->delete_skill("yijinjing");

	if (me->query_skill("force", 1) < me->query_skill("freezing-force", 1))
		return notify_fail("你的基本内功水平不够，难以锻炼更深厚的冰蚕寒功！\n");

	return ::valid_learn(me);
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	int ap, dp;
	int jiali;

	if ((int) me->query_skill("freezing-force", 1) < 100 ||
	    ! living(me))
		return;

	if ((jiali = ob->query("jiali")) < 1)
		return;

	ap = ob->query_skill("force") * 100 + ob->query("max_neili");
	dp = me->query_skill("force") * 100 + me->query("max_neili");

	if (me->query_skill("hanmo-xuangong", 1) > 99) 
	{
	if (ap *2/3 + random(ap) < dp)
	{
		result = ([ "damage" : -damage ]);

		switch (random(2))
		{
		case 0:
			result += (["msg" : HIW"$N"HIW"一触$n"HIW"衣衫，忽然全身大震，如遭电击，再难寸进。"NOR"\n" ]);
			break;
		default:
            result += (["msg" : HIW"一阵锥心刺骨的寒冷沁进了$N"HIW"心中，$N"HIW"不由打了一个寒颤，手上劲力一偏。"NOR"\n" ]);
		}
		return result;
	}
	}
	else if (me->query_skill("hanmo-xuangong", 1) > 49) 
	{
	if (ap *3/4 + random(ap) < dp)
	{
		result = ([ "damage" : -damage ]);

		switch (random(2))
		{
		case 0:
			result += (["msg" : HIW"$N"HIW"一触$n"HIW"衣衫，忽然全身大震，如遭电击，再难寸进。"NOR"\n" ]);
			break;
		default:
            result += (["msg" : HIW"一阵锥心刺骨的寒冷沁进了$N"HIW"心中，$N"HIW"不由打了一个寒颤，手上劲力一偏。"NOR"\n" ]);
		}
		return result;
	}
	}
	else {
	if (ap *4/5 + random(ap) < dp)
	{
		result = ([ "damage" : -damage ]);

		switch (random(2))
		{
		case 0:
			result += (["msg" : HIW"$N"HIW"一触$n"HIW"衣衫，忽然全身大震，如遭电击，再难寸进。"NOR"\n" ]);
			break;
		default:
            result += (["msg" : HIW"一阵锥心刺骨的寒冷沁进了$N"HIW"心中，$N"HIW"不由打了一个寒颤，手上劲力一偏。"NOR"\n" ]);
		}
		return result;
	}
	}

}

int practice_skill(object me)
{
	return notify_fail("冰蚕寒功无法通过简单的练习来增加熟练度。\n");
}

// hit effect called by combatd
mixed force_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	mixed result;
	int lvl;
	int flvl;

	result = ::force_hit_ob(me, victim, damage_bonus, factor);
	if (intp(result) && result > 0)
	{
		lvl  = me->query_skill("freezing-force", 1);
		flvl = me->query("jiali");
		if (lvl < 80 || flvl < 10)
			return;
	
	    	if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
		    victim->affect_by("freezing",
				      ([ "level" : flvl * 3 / 2 + random(flvl / 2),
					 "id"    : me->query("id"),
					 "duration" : lvl / 40 + random(lvl / 20) ])))
		{
			return ([ "damage" : result,
				  "msg" : HIW "$n" HIW "只觉得寒风袭体，一时说不出的难受。"NOR"\n" ]);
	    	}
	}

	return result;
}

string exert_function_file(string func)
{
	return __DIR__"freezing-force/" + func;
}

int diffcult_level() { return 200; }
