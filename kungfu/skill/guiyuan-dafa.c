
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
		return notify_fail("��Ļ����ڹ���򻹲�����\n");
    if (me->query("family/family_name")!="佻�����")
   return notify_fail("�㲻�Ǳ��ŵ��ӣ��޷�ѧϰ���ż��ܡ�\n");	
	if ( me->query("gender") == "����" && me->query_skill("guiyuan-dafa",1) > 49)
		return notify_fail("���޸����ԣ���������������������Ĺ�Ԫ�󷨡�\n");
	/* skl = this_player()->query_skills();
	sname  = keys(skl);
	for (z=0; z<sizeof(skl); z++)
	{
		if (sname[z]=="yijing-force") continue;
		if (sname[z]=="guiyuan-dafa") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[z])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫ�󷨣���\n");
	} */
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("��Ԫ��ֻ����ѧ(learn)�������������ȡ�\n");
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
		return HIB "$N���ӳ�"+HIR+"��Ԫ��"NOR HIB"������,�ݻ���$n����Ԫ��������\n" NOR;
	}
}

mapping exercise_msg(object me)
{
  return ([
        "status_msg" : "̫��Ѩ�����������¡�\n" ,
        "start_my_msg" : "˫����̫��״�����ڵ��������â�����Ļ�ۡ�\n",
        "start_other_msg" :  me->name() + "˫����̫��״�����ڵ��ﴦ��������â�����Ļ�ۡ�\n",
        "heal_my_msg" : "˫����̫��ӡ��������â������У������������������оۼ���\n",
        "heal_other_msg" :  me->name() + "˫����̫��ӡ��������â���������ľۼ�����������Խ��Խ������\n",
        "halt_msg" :  "˫����ǰ�Ƴ������Ĺ�â��������Ԫ������˳�ȥ��\n",
        "end_my_msg" : "˫����ǰ�Ƴ������Ĺ�â��������Ԫ�������Զ���������˿�����������\n",
        "end_other_msg" : me->name()+"���Ĺ�â�����ۼ������������������������վ��������\n",		
        "hover_my_msg" : "������âԽ��Խ�����������������Ҳ�������֡��������ã���վ��������˫����ǰһ�ơ�\n",
        "hover_other_msg" : ""+me->name()+"����������âԽ��Խ��������������Խ�����ʡ��������ã���վ������˫���͵���ǰһ�ơ�\n",	
    ]);
}