#include <ansi.h>

inherit FORCE;
string *dodge_msg = ({
        "$N身形加速，电光挪移，饶是$n攻击范围既广且厉，却总能在间不容发的空隙避过\n",
        "$N空中快速转折，在$n每次攻击前又倏乎消失，一下子就脱出$n的攻击范围\n",        
        "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了\n", 
        "$N凭著高速身法，在$n的攻击范围内进退趋避，险险闪过一道又一道的攻击\n",
        "$N腾挪快速，竟然在空中形成身影残像，有如无数$N一起挪动\n",
        "$n眼前忽然一花，眼前$N的身影似乎有些淡化，而另外一个$N竟尔出现在面前不足一尺的近处\n",
});
int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("taixu-jiandian", 1);
        return lvl / 10 * lvl / 10 * 15 * 25 / 10 / 20;
}

mapping *actionf = ({
([      "action": "$N飞身一跃而起，身法陡然加快，朝着$n$l快速攻出数十拳",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "启剑形" NOR,
        "damage_type":  "刺伤"
]),
([      "action": "$N沉身运气，一拳击向$n，刹那间，$N全身竟浮现出一道金光",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "化剑形" NOR,
        "damage_type":  "刺伤"
]),
([      "action": "$N将太虚剑气运劲于臂，一掌凌空劈斩而出，划出一道炽热的黄芒",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "开剑形" NOR,
        "damage_type":  "割伤"
]),
([      "action": "$N跨步上前，身形微微一展，双掌对准$n$l一并攻出",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "寸心式" NOR,
        "damage_type":  "刺伤"
]),
([      "action": "$N急催太虚剑气内劲，猛的一拳在呼啸声中陡然挥击而出",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "守剑形" NOR,
        "damage_type":  "刺伤"
]),
([      "action": "$N一声暴喝，十指暮的张开，一股雄厚的内劲澎湃而出",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "折剑式" NOR,
        "damage_type":  "割伤"
]),
});

mapping *actionw = ({
([      "action" : "$N攻势忽缓而不疏，$w变化无常，捉摸不定向$n慢慢卷去",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "内伤"
]),
([      "action":"$N手中的$w突焕气象森严，便似千军万马奔驰而来，$w幻作一道红芒贯向$n",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "刺伤"
]),
([      "action":"$N卷起手中的$w，霎时剑芒暴涨，宛如骄阳烈火直射向$n而去",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "刺伤"
]),
([      "action":"$N运用$w幻化做一个一个圆圈，顿时无数火圈将$n团团包围",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "内伤"
]),
([      "action":"$N回转$w遥指$n，顿时$w顶端顿时透出一道吞吐不定的火光，电射而出",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "刺伤"
]),
});

string main_skill() { return "taixu-jiandian"; }

int get_ready(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        object me = this_player();

                return usage == "force" || usage == "unarmed" || usage =="parry"|| usage == "sword"|| usage == "dodge";
}

int valid_force(string force) { return 1; }

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

int valid_learn(object me)
{
        int level;
        int i;

	if (me->query("gender") == "无性" && (int)me->query_skill("taixu-jiandian", 1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的太虚剑典。\n");

	if (me->query("int") < 50)
		return notify_fail("你觉得太虚剑气过于艰深，难以理解。\n");

	if (me->query("con") < 50)
		return notify_fail("你的根骨不好，难以运转太虚剑气。\n");
	if (me->query("str") < 50)
		return notify_fail("你觉得太虚剑气过于艰深，难以理解。\n");

	if (me->query("dex") < 50)
		return notify_fail("你的根骨不好，难以运转太虚剑气。\n");

        if ((int)me->query("max_neili") < 50000)
            return notify_fail("你的内力修为太浅，无法运转太虚剑气。\n");

        level = me->query_skill("taixu-jiandian", 1);

        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("你觉得太虚剑典过于深奥，以自己的武学修养"
                                   "全然无法明白。\n");

        if ((int)me->query_skill("force", 1) < 300)
                return notify_fail("你的基本内功修为不足，难以运转太虚剑典。\n");

        if (me->query_skill("force", 1) < level)
                return notify_fail("你对基本内功的理解还不够，无法继续领会更"
                                   "高深的太虚剑气。\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("你对基本拳脚的理解还不够，无法继续领会更"
                                   "高深的太虚剑气。\n");
		if (me->query_skill("dodge", 1) < level)
                return notify_fail("你对基本轻功的理解还不够，无法继续领会更"
                                   "高深的太虚剑气。\n");

        if (me->query_skill("sword", 1) < level)
                return notify_fail("你对基本剑法的理解还不够，无法继续领会更"
                                   "高深的太虚剑气。\n");

        return 1;
}

string query_dodge_msg(string limb)
		{    return dodge_msg[random(sizeof(dodge_msg))];}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp,cp,kp;
        int cost;

        if ((int)me->query_skill("taixu-jiandian", 1) < 250
           || me->query_skill_mapped("parry") != "taixu-jiandian"
           || me->query_skill_mapped("force") != "taixu-jiandian"
           || me->query_skill_mapped("unarmed") != "taixu-jiandian"
           || (int)me->query("neili") < 500
           || ob->query_temp("weapon")
           || ! living(me))
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force") * 12 + ob->query("neili");
        dp = me->query_skill("force") * 12 + me->query("max_neili");
		cp = me->query_skill("dodge") * 12 + me->query("max_neili");
		kp = ob->query_skill("dodge") * 12 + me->query("neili");
        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "默念太虚剑典总诀，收敛"
                                            "内劲，承下$N" + HIC "这一招，$N" HIC
                                            "只觉犹如石沉大海，丝毫不起作用。" +
                                            COMBAT_D->do_respond(me, ob, damage, 50, HIR "$P只觉一股暗劲翻涌而来，身不由己的击向自己！"NOR"\n")]);
                        break;
                case 1:
                        result += (["msg" : HIC "$N" HIC "一招击中$n" HIC "上身"
                                            "，可却犹如击在棉花上一般，力道顿时"
                                            "消失得无影无踪。"+
											COMBAT_D->do_respond(me, ob, damage, (me->query("int"))*6, HIR "$P只觉一股暗劲反击而来，顿时一阵气血翻涌！"NOR"\n")]);
                        break;
                default:
                        result += (["msg" : HIC "但见$n" HIC "微微一笑，浑若无事"
                                            "的接下了$N" HIC "这一招，却没有受到"
                                            "半点伤害。" +
											COMBAT_D->do_respond(me, ob, damage, 50, HIR "$P只觉一股暗劲翻涌而来，身不由己的击向自己！"NOR"\n")]);
                        break;
                }
                return result;
        }
		else if (kp / 2 + random(kp) < cp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "默念太虚剑典总诀，收敛"
                                            "内劲，承下$N" + HIC "这一招，$N" HIC
                                            "只觉犹如石沉大海，丝毫不起作用。" +
                                            COMBAT_D->do_respond(me, ob, damage, 50, HIR "$P只觉一股暗劲翻涌而来，身不由己的击向自己！"NOR"\n")]);
                        break;
                case 1:
                        result += (["msg" : HIC "$N" HIC "一招击中$n" HIC "上身"
                                            "，可却犹如击在棉花上一般，力道顿时"
                                            "消失得无影无踪。"+
											COMBAT_D->do_respond(me, ob, damage, (me->query("int"))*6, HIR "$P只觉一股暗劲反击而来，顿时一阵气血翻涌！"NOR"\n")]);
                        break;
                default:
                        result += (["msg" : HIC "但见$n" HIC "微微一笑，浑若无事"
                                            "的接下了$N" HIC "这一招，却没有受到"
                                            "半点伤害。" +
											COMBAT_D->do_respond(me, ob, damage, 50, HIR "$P只觉一股暗劲翻涌而来，身不由己的击向自己！"NOR"\n")]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("taixu-jiandian", 1);

        if (damage_bonus < 150
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "taixu-jiandian"
           || me->query_skill_mapped("unarmed") != "taixu-jiandian"
           || me->query_skill_prepared("unarmed") != "taixu-jiandian")
		return 0;
		if (userp(me) && (me->query("family/family_name") != "太虚山")) {
			if (damage_bonus > 1000)
				damage_bonus = 1000;
		}
        if (damage_bonus / 5 > victim->query_con())
        {
	        me->add("neili", -50);
                victim->receive_wound("qi",damage_bonus, me);
                return random(2) ? HIC "只见$N" HIC "太虚剑气自体内迸发，剑气随招式"
                                   "而荡漾，摧毁了$n" HIC "的真元！\n" NOR:

                                   HIC "$N" HIC "太虚剑气的力量爆发了出来，突然间$n"
                                   HIC "只感喉咙一甜，喷出一口鲜血！\n" NOR;
        }
		else if (damage_bonus / 5 > victim->query_con() &&
	    victim->affect_by("taixu",
			      ([ "level" : damage_bonus + random(damage_bonus),
				 "id"    : me->query("id"),
				 "duration" : lvl / 50 + random(lvl / 20) ])))
	{
		return HIR "$n" HIR "一声惨叫，只觉身上被剑气肆虐！！！\n";
	}
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("taixu-jiandian", 1);
        if (lvl < 150) return 0;
        if (lvl < 200) return 50;
        if (lvl < 250) return 60;
        if (lvl < 300) return 70;
        if (lvl < 350) return 80;
        if (lvl < 400) return 90;
        return 500;
}

int query_effect_dodge(object attacker, object me) 
{ 
	int lvl; 
      
	lvl = me->query_skill("taixu-jiandian", 1);
        if (lvl < 150) return 0;
        if (lvl < 200) return 50;
        if (lvl < 250) return 60;
        if (lvl < 300) return 70;
        if (lvl < 350) return 80;
        if (lvl < 400) return 90;
        return 500;
} 

int practice_skill(object me)
{
        return notify_fail("太虚剑气只能通过读书或研究来增加熟练度。\n");
}

int difficult_level()
{
        return 5;
}

string perform_action_file(string action)
{
        return __DIR__"taixu-jiandian/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"taixu-jiandian/exert/" + action;
}
