#include <ansi.h> 
inherit FORCE;

string *dodge_msg = ({
        "$n体内太玄真气迸发，忽见$n左手拍出，劲风到处，把$N震到一边。\n",
        "$n手臂回转，抓住$N手肘一推，将$N远远掷开。\n",
        "$n默念太玄口诀，两腿轻蹬，激跃而出，竟已落在十数丈外。\n",
        "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n",
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("taixuan-gong", 1);
          return lvl * lvl * 20 * 15 / 100 / 200;
}

mapping *actionf = ({
([      "action":"$N双手一举，一股劲气澎湃汹涌而来，逼得$n踉踉后退",
        "force" : 450,
        "attack": 150,
        "dodge" : 70,
        "parry" : 80,
        "damage": 95,
        "damage_type":  "瘀伤"
]),
([      "action":"$N右手伸出，霎时一股气流激射而出袭向$n",    
        "force" : 470,
        "attack": 140,
        "dodge" : 60,
        "parry" : 90,
        "damage": 110,
        "damage_type":  "瘀伤"
]),
([      "action":"$N大喝一声，左掌一抖，顿时一股气流向$n脸上涌去",
        "force" : 440,
        "attack": 135,
        "dodge" : 55,
        "parry" : 85,
        "damage": 100,
        "damage_type":  "瘀伤"
]),
([      "action":"$N猱身而上，全身真气暴发，双掌猛地拍向$n",
        "force" : 480,
        "attack": 170,
        "dodge" : 100,
        "parry" : 75,
        "damage": 95,
        "damage_type":  "瘀伤"
]),
([      "action":"$N身法陡快，忽左忽又，突然间$N双掌连连拍出，数股太玄内劲已射向$n",
        "force" : 470,
        "attack": 175,
        "dodge" : 80,
        "parry" : 65,
        "damage": 110,
        "damage_type":  "瘀伤"
]),
([      "action":"$N突然间左手一捺，封住$n退路，右手掌力汹涌而出",
        "force" : 460,
        "attack": 160,
        "dodge" : 75,
        "parry" : 85,
        "damage": 100,
        "damage_type":  "瘀伤"
]),
});

mapping *actionw = ({
([      "action" : "$N攻势如虹，气势非凡，$w忽隐忽现，捉摸不定向$n慢慢攻去",
        "force" : 410,
        "attack": 80,
        "dodge" : 75,
        "parry" : 85,
        "damage": 95,
        "damage_type": "内伤"
]),
([      "action":"$N手中的$w龙吟不定，犹如长江滚滚而来，将$n笼罩",
        "force" : 410,
        "attack": 88,
        "dodge" : 72,
        "parry" : 85,
        "damage": 110,
        "damage_type": "刺伤"
]),
([      "action":"$N卷起手中的$w，宛如翻江倒海直射向$n而去",
        "force" : 432,
        "attack": 125,
        "dodge" : 100,
        "parry" : 82,
        "damage": 95,
        "damage_type": "刺伤"
]),
([      "action":"$N手中$w幻出一个个光环，顿时将$n团团包围",
        "force" : 465,
        "attack": 110,
        "dodge" : 105,
        "parry" : 105,
        "damage": 120,
        "damage_type": "内伤"
]),
([      "action":"$N飞身而起，手中$w犹如神龙般地卷向$n",
        "force" : 455,
        "attack": 118,
        "dodge" : 100,
        "parry" : 100,
        "damage": 120,
        "damage_type": "刺伤"
]),
});

mapping *actionbad = ({
([      "action" : "$N正欲施招，却又突然觉得好象忘记了招式，只好胡乱使出。",
        "force" : 10,
        "attack": 10,
        "dodge" : 10,
        "parry" : 10,
        "damage": 10,
        "damage_type": "内伤"
]),
});

int valid_enable(string usage)
{ 
        object me = this_player();

       // if (me->query_skill("taixuan-gong", 1)<180 && me->query_skill("literate", 1))
        if ( !me->query("relife/zhuanshi") && me->query_skill("literate", 1))//改为不可以有读书技能除非转生 by luoyun 2018.5.12
                return usage == 0;

        if (! me->query("can_learned/taixuan-gong/enable_weapon"))
                return usage == "force" || usage == "unarmed" || usage == "dodge" || usage == "parry";
        else
        if (me->query_skill("sword", 1) < me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) < me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge" || usage == "parry";
 
        else 
        if (me->query_skill("sword", 1) < me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) > me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge" || usage =="blade" || usage == "parry";

        else
        if (me->query_skill("sword", 1) > me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) < me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge" || usage =="sword" || usage == "parry";

        else        
            return usage == "force" || usage == "unarmed" || usage == "dodge" || usage =="blade" || usage == "parry" || usage == "sword";
       
}

mapping query_action(object me, object weapon)
{
        if ( !me->query("relife/zhuanshi"))//改为不可以有读书技能除非转生 by luoyun 2018.5.12
               return actionbad[0];

        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;  

        if ( !me->query("relife/zhuanshi"))//改为不可以有读书技能除非转生 by luoyun 2018.5.12
               return;

        cost = damage / 4;

        if ((int)me->query_skill("taixuan-gong", 1) < 150
		   || !me->query_temp("parry_valid_damage")
           || me->query_skill_mapped("parry") != "taixuan-gong"
           || me->query_skill_mapped("force") != "taixuan-gong"
           || me->query_skill_mapped("unarmed") != "taixuan-gong"
           || (int)me->query("neili") < (int)me->query("max_neili")/3
           || (int)me->query("neili") < cost
           || ! living(me))
                return;

        ap = ob->query_skill("force") * 12 + ob->query("max_neili");
        dp = me->query_skill("force") * 12 + me->query("neili");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIR "$n" HIR "默念太玄功口诀，太玄内"
                                            "劲齐聚于全身，$N" HIR "只觉这招攻在"
                                            "$n" HIR "身上，犹如碰到铜墙铁壁一般，"
                                            "丝毫不起作用。\n"NOR]);
                        break;
                case 1:
                        result += (["msg" : HIR "$N" HIR "一招击中$n" HIR "上身"
                                            "，可却犹如击在铜墙铁壁上一般，力道顿时"
                                            "消失得无影无踪。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIR "但见$n" HIR "一声轻啸，浑若无事"
                                            "的接下了$N" HIR "这一招，却没有受到"
                                            "半点伤害。\n" NOR]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        string msg;
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("taixuan-gong", 1);

        if ( !me->query("relife/zhuanshi") && me->query_skill("literate", 1))//改为不可以有读书技能除非转生 by luoyun 2018.5.12
               return 0;

        if (damage_bonus < 150
           || lvl < 140
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "taixuan-gong")
                return 0;

        // 未学会驾御兵器
        if (! me->query("can_learned/taixuan-gong/enable_weapon"))
        {
             if (me->query_skill_prepared("unarmed") != "taixuan-gong")
                      return 0;
        }

        // 已经会驾御兵器
        if (me->query("can_learned/taixuan-gong/enable_weapon"))
        {             
             if (! objectp(weapon))
                  if (me->query_skill_prepared("unarmed") != "taixuan-gong")           
                         return 0;

             if (objectp(weapon) && weapon->query("skill_type") != "sword" 
                 && weapon->query("skill_type") != "blade")
                         return 0;
           
             if (objectp(weapon) && weapon->query("skill_type") == "sword"
                 && me->query_skill_mapped("sword") != "taixuan-gong")
                         return 0;
            
             if (objectp(weapon) && weapon->query("skill_type") == "blade"
                 && me->query_skill_mapped("blade") != "taixuan-gong")
                         return 0;                                   
        }

        if (random(damage_bonus) / 2 > victim->query_con() && random(2))
        {
                me->add("neili", -100);
                result = ([ "damage" : (damage_bonus - 80)/3 ]);

                if (me->query("can_learned/taixuan-gong/enable_weapon") && objectp(weapon))
                {
                        msg = random(2) ? HIM "$N" HIM "一招攻出，竟卷起千层气浪，太玄内劲"
                                           "顿时源源不绝透过" + weapon->name() + HIM "涌入$n" HIM "体"
                                           "内！\n" NOR:
                                           HIM "$N" HIM "太玄内劲迸发，$n" HIM "只感全身一震，登时一"
                                           "股灼热之气透胸而过，" + weapon->name() + HIM "鲜血淋漓！\n" NOR;
                } else
                {
                        msg = random(2) ? HIW "$N" HIW "一招攻出，竟卷起千层气浪，太玄内劲"
                                           "顿时源源不绝涌入$n" HIW "体内！\n" NOR:
                                           HIW "$N" HIW "太玄内劲迸发，$n" HIW "只感全身一"
                                           "震，登时“喀喀喀”断了数根肋骨！\n" NOR;
                }
                result += ([ "msg" : msg ]);
                return result;
        }
}

int practice_skill(object me)
{
        return notify_fail("太玄功只能用学(learn)的来增加熟练度。\n");
}

int valid_learn(object me)
{
        int level;
 
        if ( !me->query("relife/zhuanshi") && me->query_skill("literate", 1))//改为不可以有读书技能除非转生 by luoyun 2018.5.12
                return notify_fail("你觉得太玄神功深奥之极，一时间难以领会。\n");

        if (me->query("gender") == "无性")
                return notify_fail("你无根无性，阴阳不调，难以领会高深的太玄功。\n");

        if ((int)me->query("int") < 18)
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        if ((int)me->query("dex") < 25)
                return notify_fail("你研究了半天，只觉招式始终无法随意施展。\n");
        
        if ((int)me->query("con") < 25)
                return notify_fail("你研究了半天，只觉得根骨有些差，招式始终无法随意施展。\n");
        
        if ((int)me->query("str") < 25)
                return notify_fail("你研究了半天，感觉膂力有些低，始终无法随意施展。\n");

        level = me->query_skill("taixuan-gong", 1);

        if (me->query_skill("force", 1) < level)
                return notify_fail("你对基本内功的理解还不够，无法继续领会更"
                                   "高深的太玄功。\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("你对基本拳脚的理解还不够，无法继续领会更"
                                   "高深的太玄功。\n");

        return ::valid_learn(me);
}

int get_ready(object me)
{
        return 1;
}

int difficult_level()
{
        return 200;
}

string perform_action_file(string action)
{
        return __DIR__"taixuan-gong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"taixuan-gong/exert/" + action;
}
