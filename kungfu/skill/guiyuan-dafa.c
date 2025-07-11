
inherit FORCE;
inherit F_DBASE;
public string query_type()
{
	return "yin";
}
int valid_enable(string usage)
{
	return usage == "force";
}
int valid_force(string force)
{
	return force == "guiyuan-tunafa";
}
int valid_learn(object me)
// need more limit here
{
	mapping skl;
	string *sname;
	int z;
	int i = (int)me->query_skill("wuji-shengong", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t *= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
    if (me->query("family/family_name")!="浣花剑派")
   return notify_fail("你不是本门地子，无法学习本门技能。\n");	
	if ( me->query("gender") == "无性" && me->query_skill("guiyuan-dafa",1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的归元大法。\n");
	/* skl = this_player()->query_skills();
	sname  = keys(skl);
	for (z=0; z<sizeof(skl); z++)
	{
		if (sname[z]=="yijing-force") continue;
		if (sname[z]=="guiyuan-dafa") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[z])->valid_enable("force") )
			return notify_fail("你不先散了别派内功，怎能学归元大法？！\n");
	} */
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("归元大法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"guiyuan-dafa/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp,damage2;
	damage2 = (int)me->query_skill("guiyuan-dafa",1);	
	ap = me->query_skill("guiyuan-dafa",1);
	dp = victim->query_skill("force",1);
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("guiyuan-dafa",1) < 100)	 return 0;
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || me->query_skill_mapped("force") != "guiyuan-dafa") return 0;	
	if (damage2<10) damage2=10;	

	if ( random(ap) > dp/20 && random(6)==0 && me->query("jiali") > 0) 
	{
		victim->receive_wound("qi", 100+damage2+damage_bonus/2,me);
		me->add("neili", -100 );
		return HIB "$N发挥出"+HIR+"归元大法"NOR HIB"的真髓,摧毁了$n的真元！！！！\n" NOR;
	}
}

mapping exercise_msg(object me)
{
  return ([
        "status_msg" : "太阳穴鼓起，神情肃穆。\n" ,
        "start_my_msg" : "双手做太极状，合于丹田，三道光芒在手心汇聚。\n",
        "start_other_msg" :  me->name() + "双手做太极状，合于丹田处，三道光芒在手心汇聚。\n",
        "heal_my_msg" : "双手捏太极印，三道光芒汇聚其中，似有雷霆闪电在其中聚集。\n",
        "heal_other_msg" :  me->name() + "双手捏太极印，三道光芒慢慢再手心聚集，雷霆闪电越来越清晰。\n",
        "halt_msg" :  "双手向前推出，手心光芒化作三道元气球飞了出去。\n",
        "end_my_msg" : "双手向前推出，手心光芒化作三道元气球冲向远方，你吸了口气精神饱满。\n",
        "end_other_msg" : me->name()+"手心光芒慢慢聚集，待雷霆闪电出现三道，你站了起来。\n",		
        "hover_my_msg" : "三道光芒越来越亮，雷霆闪电的声音也渐渐呈现。过了良久，你站了起来，双掌向前一推。\n",
        "hover_other_msg" : ""+me->name()+"手心三道光芒越来越明亮，掌心闪电越发明朗。过了良久，你站了起来双掌猛的向前一推。\n",	
    ]);
}