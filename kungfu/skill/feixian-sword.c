// fonxansword.c

inherit SKILL;

string query_name() { return "����"ZJBR"����"; }

mapping *action = ({
        ([      "action":               
"$Nʹһ�С����·ת��������$w��һ�����߰����$n��$l",
	 "force" : 290,
        "attack": 145,
        "dodge" :95,
        "parry" :105,
        "damage": 160,
        "damage_type" : "����"
        ]),
        ([      "action":               
"$Nʹ�����ɽ����еġ���ɽ������������ն��$n��$l",
        "force" : 410,
        "attack": 135,
        "dodge" :135,
        "parry" :175,
        "damage": 270,
        "damage_type" : "����"
        ]),
        ([      "action":               
"$Nһ�С�������С������ζ�Ȼ�������ߣ�����$wն��$n��$l",
        "force" : 310,
        "attack": 115,
        "dodge" :75,
        "parry" :105,
        "damage": 275,
        "damage_type" : "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ�����ն�������׼$n��$l�̳�һ��",
        "force" : 280,
        "attack": 125,
        "dodge" :55,
        "parry" :125,
        "damage": 360,
        "damage_type" : "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С����к�ء���׼$n��$lбб�̳�һ��",
       "force" : 340,
        "attack": 160,
        "dodge" :65,
        "parry" :95,
        "damage": 320,
        "damage_type" : "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С�һ������������$n��$l",
        "force" : 250,
        "attack": 135,
        "dodge" :85,
        "parry" :105,
        "damage": 410,
        "damage_type" : "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С��������������ֶ�׼$n$lһ����ȥ",
        "force" : 240,
        "attack": 105,
        "dodge" :125,
        "parry" :175,
        "damage": 510,
        "damage_type" : "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С������ܲ�������һ���⻡����$n��$l",
        "force" : 345,
        "attack": 125,
        "dodge" :115,
        "parry" :145,
        "damage": 310,
        "damage_type" : "����"
        ]),
([      "action" : "$N����$wԽתԽ�죬ʹ�ľ�ȻѪ������ʽ�������ƾ���ӿ���Թ�\n�߲��ɵ�ĿΪ֮ѣ",
        "force" : 350,
        "attack": 145,
        "dodge" :165,
        "parry" :185,
        "damage": 350,
        "damage_type" : "����"
]),
([      "action" : "$N��Ц����������ׯ�ϣ�$w��ӣ���" HIW "�����" NOR "��"
                   "Ϊһʽ������ش���$n",
        "force" : 330,
        "attack": 135,
        "dodge" :95,
        "parry" :125,
        "damage": 460,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��" HIW "���" NOR "�����⣬�������СС��"
                   "������â�������޾�ԴԴ�����ز���$n",
        "force" : 230,
        "attack": 105,
        "dodge" :285,
        "parry" :375,
        "damage": 340,
        "damage_type" : "����"
]),
([      "action" : "$N�������أ�$w�����������Һ�ɨ������$n����"
                   HIR "��ؾ�" NOR "��������.",
        "force" : 330,
        "attack": 185,
        "dodge" :135,
        "parry" :155,
        "damage": 380,
        "damage_type" : "����"
]),
([      "action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô"
                   "��ʽ",
        "force" : 380,
        "attack": 125,
        "dodge" :145,
        "parry" :215,
        "damage": 330,
        "damage_type" : "����"
]),
([      "action" : "$N��ɫһ�������г����һ������"
                   "$n��$l",
        "force" : 390,
        "attack": 155,
        "dodge" :185,
        "parry" :275,
        "damage": 330,
        "damage_type" : "����"
]),
([
        "action" : "$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮������������"
                   "�Ѳ�",
        "force" : 410,
        "attack": 155,
        "dodge" :300,
        "parry" :300,
        "damage": 330,
        "damage_type" : "����"
]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
                return notify_fail("�������������û�а취�����ɽ�����\n");

        if( (string)me->query_skill_mapped("force")!= "jingyiforce")
                return notify_fail("���ɽ���������Ͼ����ķ���������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

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
                return  notify_fail("�����������������û�а취��ϰ���ɽ�����\n");
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
        "$nʹ��һ�С�������졹�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
        "$nʹ��һ�С�������ѩ�������е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ����һ�С����ش��ס�����$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��������ա�����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С�������졹��$vֱ��$N��˫�֡�\n",
        "$n�����е�$v���������������ȵ�$N�������ˡ�\n",
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
			result += (["msg" : "$nֻ����Ҷ�׷ɣ�$N����˾�������˫�ۣ���ʽҲƫ���˹켣��"NOR"\n"]); 
			break; 
		case 1: 
			result += (["msg" : HIW "$N" HIW "$n����һ����$N�����Լ��Ĺ���û�𵽰�����ã���¶��ɫ"NOR"\n"]); 
			break; 
		case 2: 
			result += (["msg" : HIW "$N" HIW "��һ��Ѹ���ޱȣ�Ȼ��$n" 
					    HIW "����һŤ���ƺ����Ѱ��������ȴ��" 
					    HIW "$N��һ�ж��˿�ȥ��"NOR"\n"]); 
			break; 
		default: 
			result += (["msg" : HIW "$N" HIW "$n����һ����$N�����Լ��Ĺ���û�𵽰�����ã���¶��ɫ"NOR"\n"]);  
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

