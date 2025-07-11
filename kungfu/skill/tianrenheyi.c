// lingboweibu.c 凌波微步

#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
        "$n动也不动，把$N震到一边。\n",
        "$n身形微微一抖，将$N迫退。\n",
        "$n手足忽的一晃，$N竟然无法进击，只能自保。\n",
        "$n轻轻一格，将天下所有进攻招数全部封死。\n",
});

int valid_enable(string usage) 
{ 
	return usage == "dodge";
}

int valid_learn(object me)
{
	int lvl;

	lvl = me->query_skill("tianrenheyi", 1);

	if (me->query("max_neili") < 1000 + lvl * 2)
		return notify_fail("你试着走了两步，顿觉胸口烦恶之极，看来是内力不济。\n");
	return 1;
}

string query_txt()
{
	return ""ZJBR
	"特效：轻功化解伤害，对比自身(轻功激发)+先天四维属性和攻击者轻功激发，受阴阳八卦克制";
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp;

	if ((int)me->query_skill("tianrenheyi", 1) < 100 ||
	    ! living(me))
		return;

	mp = ob->query_skill("count",1);
	ap = ob->query_skill("dodge") + mp;
	dp = me->query_skill("dodge")+me->query("str")+me->query("dex")+me->query("int")+me->query("con");

	if (ap / 1 + random(ap) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(4))
		{
		case 0:
			result += (["msg" : HIW "只见$n" HIW "微微一笑，身子轻轻晃动，$N"
					    HIW "眼前顿时出现了无数个$n" HIW "的幻影，令$N"
					    HIW "完全无法辨出虚实。"NOR"\n"]);
			break;
		case 1:
			result += (["msg" : HIW "$n" HIW "往旁边歪歪斜斜的迈出一步，却恰"
					    "好令$N" HIW "的攻击失之毫厘。"NOR"\n"]);
			break;
		case 2:
			result += (["msg" : HIW "$N" HIW "这一招来的好快，然后$n"
					    HIW "一闪，似乎不费半点力气，却将$N"
					    HIW "这一招刚好避开。"NOR"\n"]);
			break;
		default:
			result += (["msg" : HIW "但见$n" HIW "轻轻一跃，已不见了踪影，$N"
					    HIW "心中大骇，却又见$n" HIW "擦肩奔过，步法"
					    "之奇巧，当真令人思索菲仪。"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(4))
		{
		case 0:
			result = HIY "只见$n" HIY "微微一笑，身子轻轻晃动，"
				 "顿时出现了无数个$n" HIY "的幻影，可是$N"
				 HIY "精通易理，将其中虚实辨得清清楚楚。"NOR"\n";
			break;
		case 1:
			result = HIY "$n" HIY "往旁边歪歪斜斜的迈出一步，然而$N"
				 HIY "错步跟随，方位毫厘不差。"NOR"\n";
			break;
		case 2:
			result = HIY "$n" HIY "一闪，似乎不费半点力气，却将$N"
				 HIY "这一招刚好避开，可是$N"
				 HIY "招中有招，进攻却是不止。"NOR"\n";
			break;
		default:
			result = HIY "但见$n" HIY "轻轻一跃，已不见了踪影，$N"
				 HIY "不假思索，反身出招，更是巧妙无方。"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

int query_effect_dodge(object attacker, object me)
{
	int lvl;

	lvl = me->query_skill("tianrenheyi", 1);
	if (lvl < 50)  return 150;
	if (lvl < 100) return 250;
	if (lvl < 150) return 420;
	if (lvl < 200) return 520;
	if (lvl < 250) return 640;
	if (lvl < 300) return 750;
	if (lvl < 350) return 860;
	return 960;;
}

int practice_skill(object me)
{
	int cost;

	cost = me->query_skill("tianrenheyi", 1) / 2 + 120;
	if ((int)me->query("qi") < 1000)
		return notify_fail("你的体力太差了，难以练习归真道经。\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("你的内力不够了，无法练习归真道经。\n");

	me->receive_damage("qi", 1000);
	me->add("neili", -cost);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianrenheyi/" + action;
}
