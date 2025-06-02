//zuixin-sword  by:system_2
//change by jerry@ty 
inherit SKILL;
string type() { return "zhongji"; }
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([  "action":"$N����һ�С�"+(order[random(13)])+"��������"+NOR+"��������$wһ�������ߵ��������$n��$l",
    "force" : 350,
    "lvl" : 350,
	 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
    "damage_type":  "����"
]),
([  "action":"$N����$wһ����һ�С�"+(order[random(13)])+"�����"+NOR+"����ббһ��������������$n��$l",
    "force" : 350,
    "lvl" : 350,
	 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
    "damage_type":  "����"
]),
([      "action" : "$Nһ�С�"+(order[random(13)])+"ȥ���˼�"+NOR+"����$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
        "force"  : 350,
        "lvl"    : 350,
		 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
        "skill_name" : "ȥ���˼�",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ��"+(order[random(13)])+"���б���"+NOR+"��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
        "force" : 350,
        "lvl"   : 350,
		 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
        "skill_name" : "���б���",
        "damage_type":  "����"
]),
([      "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��"+(order[random(13)])+"��������"+NOR+"������$n���ʺ�",
        "force" : 350,
        "lvl"   : 350,
		 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С�"+(order[random(13)])+"Ⱥ�ɾۻ�"+NOR+"��������$w����һ�Ž���������$n��$l",
        "force"  : 350,
        "lvl"    : 350,
		 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
        "skill_name" : "Ⱥ�ɾۻ�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�"+(order[random(13)])+"ȥ���˼�"+NOR+"����$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
        "force"  : 350,
        "lvl"    : 350,
		 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
        "skill_name" : "ȥ���˼�",
        "damage_type" : "����"
]),
([  "action":"$N��������ҡ�ڣ���һ���佣â��ʢ��һ�С�"+(order[random(13)])+"��Ҷ��"+NOR+"������$n��$l",
        "force" :350,
        "lvl" : 350,
		 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
    "damage_type":  "����"
]),
([  "action":"$N����$n��ʽ�е�����������һ������"+(order[random(13)])+"���˫Ʈ��"+NOR+"���ѹ���$n����֮��",
        "force" : 350,
        "lvl" : 350,
		 "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
    "damage_type":  "����"
]),
([  "action":HIB"$Nʹ��һʽ��"+(order[random(13)])+"�������"+HIB+"�����ֵ�������$n��������æ����"NOR,
     "force" : this_player()->query_skill("zuixin-sword",1),
      "lvl" : 1050,
	   "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
    "damage_type": "����"
]),
([  "action":HIW"$N΢΢һЦ����"+(order[random(13)])+"��ӵ�к"+HIW+"�����п������������$w"HIW"ֱ����$n��ǰ"NOR, 
     "force" : this_player()->query_skill("zuixin-sword",1),
     "lvl" : 1100,
	  "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
    "damage_type": "����"
]),
([  "action":HIC"$N�������ң����Կ�罣���Ľ��С�"+(order[random(13)])+"������"+HIC+"�����ѽ�$n���ڵ�������֮��"NOR, 
     "force" : this_player()->query_skill("zuixin-sword",1),
     "lvl" : 1200,
	  "dodge" :350,
		"attack": 350,
        "parry" :350,
        "damage": 350,
    "damage_type": "����"
])
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 60;  }
mapping query_action(object me,object weapon)
{

    mapping a_action;
    int i, level, medj;
    me = this_player();
    medj    = (int) me->query("int",1);
    level   = (int) me->query_skill("zuixin-sword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 5, level/5)];
                        break;
                }
 
    return a_action;

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;

 //  �����ȼ�������
      if( me->query_skill("zuixin-sword",1)>2000
         && me->query_skill("beiming-shengong",1)>1200
  && (me->query("neili")*6) > victim->query_max_neili() ) {
              victim->receive_damage("qi", damage_bonus/2, me);
return HIR "$N�����Ľ����ѵ�"BLINK HIC" ��ߵȼ� "NOR HIR"����һ����"BLINK HIW" ��â "NOR HIR"�ݻ���$n��"BLINK HIR" ��Ԫ "NOR HIR"������\n" NOR;
  }      

 //  ����ȼ�������
      if( me->query_skill("zuixin-sword",1)>1000
         && me->query_skill("beiming-shengong",1)>1000
  && (me->query("neili")*5) > victim->query_max_neili() ) {
              victim->receive_damage("qi", damage_bonus/4 , me);
return HIR "$N�߶�"HIC"��ڤ����"HIR"����һ��ǿ������"HIG"$n"HIR"һ������������Ѫ������\n" NOR;
  }      
 //  ���ĵȼ�������
      if( me->query_skill("zuixin-sword",1)>800
         && me->query_skill("beiming-shengong",1)>800
  && (me->query("neili")*4) > victim->query_max_neili() ) {
                victim->receive_damage("qi", damage_bonus/6, me);
return HIG "$N�߶�"HIC"��ڤ����"HIR"����һ��ǿ������"HIG"$n"HIR"һ������������Ѫ������\n" NOR;
  }      


 // �ڶ��ȼ�������
        if ( me->query_skill("zuixin-sword",1)>400
      //   && me->query_skill("langzi-sword",1)<1001
         && me->query_skill("beiming-shengong",1)>300
&& (me->query("neili")*3) > victim->query_max_neili() ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 10 , me);
return HIC "$N�ı�ڤ�������ڽ��ϣ�$nһ����ͱ����ϵ��������ˣ�����\n" NOR;
}

 //  �����ȼ�������
      if( me->query_skill("zuixin-sword",1)>600
         && me->query_skill("beiming-shengong",1)>600
 // && me->query("jym_level/level")>=10
  && (me->query("neili")*3) > victim->query_max_neili() ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return HIR "$N������һ��ǿ���"HIC"��ڤ����"HIR"���ڽ���֮�ϣ�"HIG"$n"HIR"һ������������Ѫ������\n" NOR;
  }      


      return 1;
}


int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("���������������ң���Ľ�����\n");
    me->receive_damage("qi", 25);
    return 1;
}
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("�㻹�����Ұѽ����ɡ�\n");
		
		if( me->query("int")<38 )
        return notify_fail( "��ֻ�н�����ɬ�Ѷ���\n");
        if( me->query("dex")<28 )
         return notify_fail( "��ֻ�������鶯�Ƿ���\n");
        if( me->query("con")<30 )
         return notify_fail("��ֻ��������Ѫ��ӿ��\n");
        if( me->query("str")<25 )
        return notify_fail( "��ֻ������̫�����ء�\n");
               
        if (me->query("max_neili") < 20000)
                return notify_fail("�������������\n");
        if (me->query("zhuanshi") < 3)
               return notify_fail("���ת��̫�ͣ������3����ѧϰ��ǿ����ϰС���߻���ħ��\n");
		/* if (me->query_skill("zuixin-sword",1) > 200)
			return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n"); */
		if (me->query_skill("sword", 1)<=me->query_skill("zuixin-sword",1))
			return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
		if (me->query_skill("beiming-shengong", 1) < 400)
			return notify_fail("��ı�ڤ�񹦻��̫ǳ��\n");
		if (me->query_skill("lingbo-weibu", 1) < 400)
			return notify_fail("����貨΢�����̫ǳ��\n");

     return 1;
}


string perform_action_file(string action)
{
    return __DIR__"zuixin-sword/" + action;
}
int difficult_level()
{
        return 2500;
}
