// fonxansword.c

inherit SKILL;

string query_name() { return "飞仙"ZJBR"剑法"; }

mapping *action = ({
        ([      "action":               
"$N使一招「峰回路转」，手中$w如一条银蛇般刺向$n的$l",
	 "force" : 290,
        "attack": 145,
        "dodge" :95,
        "parry" :105,
        "damage": 160,
        "damage_type" : "刺伤"
        ]),
        ([      "action":               
"$N使出飞仙剑法中的「空山鸟语」，剑光霍霍斩向$n的$l",
        "force" : 410,
        "attack": 135,
        "dodge" :135,
        "parry" :175,
        "damage": 270,
        "damage_type" : "刺伤"
        ]),
        ([      "action":               
"$N一招「御风而行」，身形陡然滑出数尺，手中$w斩向$n的$l",
        "force" : 310,
        "attack": 115,
        "dodge" :75,
        "parry" :105,
        "damage": 275,
        "damage_type" : "刺伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「旭日东升」对准$n的$l刺出一剑",
        "force" : 280,
        "attack": 125,
        "dodge" :55,
        "parry" :125,
        "damage": 360,
        "damage_type" : "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「金光泻地」对准$n的$l斜斜刺出一剑",
       "force" : 340,
        "attack": 160,
        "dodge" :65,
        "parry" :95,
        "damage": 320,
        "damage_type" : "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「一剑西来」刺向$n的$l",
        "force" : 250,
        "attack": 135,
        "dodge" :85,
        "parry" :105,
        "damage": 410,
        "damage_type" : "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「柳暗花明」反手对准$n$l一剑刺去",
        "force" : 240,
        "attack": 105,
        "dodge" :125,
        "parry" :175,
        "damage": 510,
        "damage_type" : "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招「仙云密布」画出一道光弧刺向$n的$l",
        "force" : 345,
        "attack": 125,
        "dodge" :115,
        "parry" :145,
        "damage": 310,
        "damage_type" : "刺伤"
        ]),
([      "action" : "$N手中$w越转越快，使的居然血起连天式，有如云卷雾涌，旁观\n者不由得目为之眩",
        "force" : 350,
        "attack": 145,
        "dodge" :165,
        "parry" :185,
        "damage": 350,
        "damage_type" : "刺伤"
]),
([      "action" : "$N含笑抱剑，气势庄严，$w轻挥，「" HIW "天地仙" NOR "」"
                   "为一式，闲舒地刺向$n",
        "force" : 330,
        "attack": 135,
        "dodge" :95,
        "parry" :125,
        "damage": 460,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举起$w运使「" HIW "万城" NOR "」剑意，划出大大小小无"
                   "数个剑芒，无穷无尽源源不绝地缠向$n",
        "force" : 230,
        "attack": 105,
        "dodge" :285,
        "parry" :375,
        "damage": 340,
        "damage_type" : "刺伤"
]),
([      "action" : "$N神声凝重，$w上劈下切左右横扫，逼往$n，「"
                   HIR "天地惊" NOR "」风雨破.",
        "force" : 330,
        "attack": 185,
        "dodge" :135,
        "parry" :155,
        "damage": 380,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么"
                   "招式",
        "force" : 380,
        "attack": 125,
        "dodge" :145,
        "parry" :215,
        "damage": 330,
        "damage_type" : "刺伤"
]),
([      "action" : "$N脸色一定，胸有成竹地一剑刺向"
                   "$n的$l",
        "force" : 390,
        "attack": 155,
        "dodge" :185,
        "parry" :275,
        "damage": 330,
        "damage_type" : "刺伤"
]),
([
        "action" : "$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，当真人所"
                   "难测",
        "force" : 410,
        "attack": 155,
        "dodge" :300,
        "parry" :300,
        "damage": 330,
        "damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力不够，没有办法练飞仙剑法。\n");

        if( (string)me->query_skill_mapped("force")!= "jingyiforce")
                return notify_fail("飞仙剑法必须配合净衣心法才能练。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("jing") < 30
        ||      (int)me->query("neili") < 3 )
                return  notify_fail("你的内力或气不够，没有办法练习飞仙剑法。\n");
       // me->receive_damage("qi", 30);
        //me->add("neili", -3);
     
        return 9;
}

string perform_action_file(string action)
{
        return __DIR__"feixian-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$n使出一招「凤舞九天」，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n使出「封」字诀，将$N的$w封于丈外。\n",
        "$n使出一招「朝朝瑞雪」，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「旱地春雷」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「阳光普照」，整个人消失在一团剑光之中。\n",
        "$n使出一招「龙舞九天」，$v直刺$N的双手。\n",
        "$n将手中的$v化做七条剑气，迫得$N连连后退。\n",
});
mixed valid_damage(object ob, object me, int damage, object weapon) 
{ 
	mixed result; 
	int ap, dp; 
       
	if ((int)me->query_skill("feixian-sword", 1) < 100 || 
	    ! living(me)) 
		return; 
	
	ap = ob->query_skill("parry") + ob->query("per") * 20;
	dp = me->query_skill("parry", 1) / 2 + me->query_skill("feixian-sword", 1) + me->query("per") * 30; 
       
	if (ap / 2 + random(ap) < dp) 
	{ 
		result = ([ "damage": -damage ]); 
       
		switch (random(4)) 
		{ 
		case 0: 
			result += (["msg" : "$n只见落叶纷飞，$N此情此景迷乱了双眼，招式也偏离了轨迹。"NOR"\n"]); 
			break; 
		case 1: 
			result += (["msg" : HIW "$N" HIW "$n轻轻一带，$N发现自己的攻击没起到半点作用，面露惊色"NOR"\n"]); 
			break; 
		case 2: 
			result += (["msg" : HIW "$N" HIW "这一招迅疾无比，然而$n" 
					    HIW "身子一扭，似乎不费半点力气，却将" 
					    HIW "$N这一招躲了开去。"NOR"\n"]); 
			break; 
		default: 
			result += (["msg" : HIW "$N" HIW "$n轻轻一带，$N发现自己的攻击没起到半点作用，面露惊色"NOR"\n"]);  
			break; 
		} 
		return result; 
	}
 
} 
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 15;
}

