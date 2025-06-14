// yijinjing.c 少林 易筋经神功
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
       if (me->query("family/family_name") == "少林派")
              return lvl * lvl * 15 * 21 / 100 / 200;
	else 
              return lvl * lvl * 15 * 19 / 100 / 200;
}

int valid_learn(object me)
{
	if (me->query_skill("force", 1) < 100)
		return notify_fail("你的基本内功火候不够，无法学习易筋经神功！\n");

	if (me->query_skill("freezing-force", 1)) 
		return notify_fail("你已经将易筋经神功和冰蚕寒毒合炼成了一门新内功了。\n");

	if (me->query_skill("force", 1) < me->query_skill("yijinjing", 1))
		return notify_fail("你的基本内功水平不够，难以领悟更高深的易筋经神功！\n");

	if (me->query("gender") != "男性" && me->query("gender") != "女性")
		return notify_fail("你不男不女，无法练习易筋经神功。\n");

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
			result += (["msg" : HIR "$n" HIR "身上生出一股反震之力," HIY "易筋经神功" + HIR "随心而起，承下$N" + HIR "这一招。"NOR"\n" ]);
			break;
		default:
			result += (["msg" : HIR "$N" HIR "一招击中$n" HIR "上身，却似击在一堵棉花作面，钢铁为里的厚墙上一般，震退数步！"NOR"\n" ]);
			break;
		}

		return result;
	}
}

int practice_skill(object me)
{
	return notify_fail("易筋经神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijinjing/" + func;
}
