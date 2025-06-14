#include <ansi.h>

inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("jiuyang-shengong", 1);
        return lvl / 10 * lvl / 10 * 15 * 28 / 10 / 20;
}

mapping *actionf = ({
([      "action": "$N飞身一跃而起，身法陡然加快，朝着$n$l快速攻出数十拳",
        "force" : 510,
        "attack": 190,
        "dodge" : 100,
        "parry" : 90,
        "damage": 180,
        "weapon": HIR "九阳无极劲" NOR,
        "damage_type":  "刺伤"
]),
([      "action": "$N沉身运气，一拳击向$n，刹那间，$N全身竟浮现出一道金光",
        "force" : 510,
        "attack": 185,
        "dodge" : 90,
        "parry" : 120,
        "damage": 175,
        "weapon": HIR "九阳无极劲" NOR,
        "damage_type":  "刺伤"
]),
([      "action": "$N将九阳神功运劲于臂，一掌凌空劈斩而出，划出一道炽热的黄芒",
        "force" : 530,
        "attack": 175,
        "dodge" : 90,
        "parry" : 110,
        "damage": 200,
        "weapon": HIR "九阳无极劲" NOR,
        "damage_type":  "割伤"
]),
([      "action": "$N跨步上前，身形微微一展，双掌对准$n$l一并攻出",
        "force" : 525,
        "attack": 185,
        "dodge" : 85,
        "parry" : 115,
        "damage": 185,
        "weapon": HIR "九阳无极劲" NOR,
        "damage_type":  "刺伤"
]),
([      "action": "$N急催九阳神功内劲，猛的一拳在呼啸声中陡然挥击而出",
        "force" : 530,
        "attack": 165,
        "dodge" : 90,
        "parry" : 115,
        "damage": 200,
        "weapon": HIR "九阳无极劲" NOR,
        "damage_type":  "刺伤"
]),
([      "action": "$N一声暴喝，十指暮的张开，一股雄厚的内劲澎湃而出",
        "force" : 540,
        "attack": 200,
        "dodge" : 115,
        "parry" : 120,
        "damage": 180,
        "weapon": HIR "九阳无极劲" NOR,
        "damage_type":  "割伤"
]),
});

mapping *actionw = ({
([      "action" : "$N攻势忽缓而不疏，$w变化无常，捉摸不定向$n慢慢卷去",
        "force" : 330,
        "attack": 140,
        "dodge" : 35,
        "parry" : 85,
        "damage": 325,
        "damage_type": "内伤"
]),
([      "action":"$N手中的$w突焕气象森严，便似千军万马奔驰而来，$w幻作一道红芒贯向$n",
        "force" : 310,
        "attack": 120,
        "dodge" : 25,
        "parry" : 25,
        "damage": 310,
        "damage_type": "刺伤"
]),
([      "action":"$N卷起手中的$w，霎时剑芒暴涨，宛如骄阳烈火直射向$n而去",
        "force" : 340,
        "attack": 115,
        "dodge" : 20,
        "parry" : 25,
        "damage": 365,
        "damage_type": "刺伤"
]),
([      "action":"$N运用$w幻化做一个一个圆圈，顿时无数火圈将$n团团包围",
        "force" : 285,
        "attack": 110,
        "dodge" : 25,
        "parry" : 25,
        "damage": 390,
        "damage_type": "内伤"
]),
([      "action":"$N回转$w遥指$n，顿时$w顶端顿时透出一道吞吐不定的火光，电射而出",
        "force" : 330,
        "attack": 118,
        "dodge" : 10,
        "parry" : 20,
        "damage": 420,
        "damage_type": "刺伤"
]),
});

string main_skill() { return "jiuyang-shengong"; }

int get_ready(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        object me = this_player();

        if (! me->query("can_skill/jiuyang-shengong"))
                return usage == "force";
        else
                return usage == "force" || usage == "unarmed" || usage =="parry";
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
/*
        if ((int)me->query_skill("yinyang-shiertian", 1))
                return notify_fail("你已将九阳神功融汇贯通，合成了普天之下最"
                                   "强的武功，不必再分开学习了。\n");
*/
	
    //    if( (!me->query("family/family_name") ||
    //            me->query("family/family_name") != "明教") && me->query("reborn/family_name") != "明教" )
    //            return notify_fail("你没有经过张教主的指点，难以理解。\n");

	if (me->query("gender") == "无性" && (int)me->query_skill("jiuyang-shengong", 1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。\n");

	if (me->query("int") < 25)
		return notify_fail("你觉得九阳神功过于艰深，难以理解。\n");

	if (me->query("con") < 29)
		return notify_fail("你的根骨不好，难以运转九阳神功。\n");

        if ((int)me->query("max_neili") < 3500)
            return notify_fail("你的内力修为太浅，无法运转九阳神功。\n");

        level = me->query_skill("jiuyang-shengong", 1);

        if ((int)me->query_skill("martial-cognize", 1) < 100)
                return notify_fail("你觉得九阳神功过于深奥，以自己的武学修养"
                                   "全然无法明白。\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你的基本内功修为不足，难以运转九阳神功。\n");

        if (me->query_skill("force", 1) < level)
                return notify_fail("你对基本内功的理解还不够，无法继续领会更"
                                   "高深的九阳神功。\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("你对基本拳脚的理解还不够，无法继续领会更"
                                   "高深的九阳神功。\n");
/*
        if (me->query("can_learn/jiuyang-shengong/enable_weapon") &&
            me->query_skill("sword", 1) < level &&
            me->query_skill("blade", 1) < level)
                return notify_fail("你对刀剑功夫的理解还不够，无法继续领会更"
                                   "高深的九阳神功。\n");

        if (! me->query("can_learn/jiuyang-shengong/enable_weapon"))
        {
                write(HIG "你学会了利用九阳神功驾御兵器！\n");
                me->set("can_learn/jiuyang-shengong/enable_weapon", 1);
        }
*/
        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;

        if ((int)me->query_skill("jiuyang-shengong", 1) < 150
           || me->query_skill_mapped("parry") != "jiuyang-shengong"
           || me->query_skill_mapped("force") != "jiuyang-shengong"
           || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
           || (int)me->query("neili") < 500
           || ob->query_temp("weapon")
           || ! living(me))
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force") * 12 + ob->query("max_neili") + ob->query_skill("count", 1) * 6;
        dp = me->query_skill("force") * 12 + me->query("neili");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIR "$n" HIR "默念九阳神功总诀，收敛"
                                            "内劲，承下$N" + HIR "这一招，$N" HIR
                                            "只觉犹如石沉大海，丝毫不起作用。\n"
                                            NOR]);
                        break;
                case 1:
                        result += (["msg" : HIR "$N" HIR "一招击中$n" HIR "上身"
                                            "，可却犹如击在棉花上一般，力道顿时"
                                            "消失得无影无踪。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIR "但见$n" HIR "微微一笑，浑若无事"
                                            "的接下了$N" HIR "这一招，却没有受到"
                                            "半点伤害。\n" NOR]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("jiuyang-shengong", 1);

        if (damage_bonus < 150
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "jiuyang-shengong"
           || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
           || me->query_skill_prepared("unarmed") != "jiuyang-shengong")
		return 0;
		if (userp(me) && (! me->query("can_skill/jiuyang-shengong") || me->query("family/family_name") != "明教")) {
			if (damage_bonus > 300)
				damage_bonus = 300;
		}
        if (damage_bonus / 5 > victim->query_con())
        {
	        me->add("neili", -50);
                victim->receive_wound("qi", (damage_bonus - 80) / 2, me);
                return random(2) ? HIR "只见$N" HIR "九阳内劲自体内迸发，真气随招式"
                                   "而荡漾，摧毁了$n" HIR "的真元！\n" NOR:

                                   HIR "$N" HIR "九阳神功的潜力发挥了出来，突然间$n"
                                   HIR "只感喉咙一甜，喷出一口鲜血！\n" NOR;
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("jiuyang-shengong", 1);
        if (lvl < 150) return 0;
        if (lvl < 200) return 50;
        if (lvl < 250) return 60;
        if (lvl < 300) return 70;
        if (lvl < 350) return 80;
        if (lvl < 400) return 90;
        return 100;
}

int practice_skill(object me)
{
        return notify_fail("九阳神功只能通过读书或研究来增加熟练度。\n");
}

int difficult_level()
{
        return 700;
}

string perform_action_file(string action)
{
        return __DIR__"jiuyang-shengong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"jiuyang-shengong/exert/" + action;
}
