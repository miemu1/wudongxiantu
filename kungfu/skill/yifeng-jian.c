inherit SKILL;
string type() { return "zhongji"; }
int tydamage = this_player()->query_skill("yifeng-jian")*3;

mapping *action = ({
([      "action":"$Nʹһʽ��������ơ�������$w����΢�񣬻ó�һ�����������$n��$l",
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : tydamage,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N�Ʋ���ǰ��ʹ�����껨�׷ɡ�������Χ�ƣ�$w��������$n��$l��ȥ",
        "force" : 20,
        "dodge" : 160,
        "parry" : 40,
        "damage" : tydamage,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action":"$Nһʽ��"HIM"������"NOR"��������Ʈ�����ߣ��˷�����������$wңң����$n��$l",
        "force" : 160,
        "dodge" : 20,
        "parry" : 40,
        "damage" : tydamage,
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action":"$N��������Ծ��һʽ��"HIC"�ϻ�����"NOR"�������⻯Ϊ��ɫ��Ʈ��$n��$l",
        "force" : 60,
        "dodge" : 30,
        "parry" : 180,
        "damage" : tydamage,
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action":"$N����$w�й�ֱ����һʽ��"HIB"������л"NOR"����������Ϣ�ض�׼$n��$l�̳�һ��",
        "force" : 50,
        "dodge" : 100,
        "parry" : 40,
        "damage" : tydamage,
        "lvl" : 110,
        "damage_type" : "����"
]),
  ([      "action":"$N����$wбָ���죬��â���£�һʽ��"HIY"�ɻ���Ҷ"NOR"������׼$n��$lбб����"NOR,
        "force" : 130,
        "dodge" : 90,
        "parry" : 40,
        "damage" : tydamage,
     "lvl" : 120,
        "damage_type" : "����"
]),
  ([      "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��"HIG"���ش��"NOR"������$n��$l"NOR,
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : tydamage,
     "lvl" : 150,
        "damage_type" : "����"
]),
  ([      "action":HIM"������,ֻ�����굽������,ͻȻ�����������$n,$n��ʱ��Ѫֱ��"NOR,
        "force" : 200,
        "dodge" : 80,
        "parry" : 5,
        "damage" : tydamage,
     "lvl" : 200,
     "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if (me->query_skill("yifeng-jian")< 120 && me->query("family/master_id")!="yao yue")
        return notify_fail("�Ʒ罣�����ƻ���������ֻ�й������²��ܽ���\n");

        if ((int)me->query_skill("mingyu-shengong", 1) < 100)
                return notify_fail("���ڤ���񹦻��̫ǳ��\n");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");
	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("yifeng-jian", 1))
		return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������Ʒ罣����\n");

        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level   = (int) me->query_skill("yifeng-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{

 //  �����ȼ�������
      if( me->query_skill("yifeng-jian",1) > 450 )
		{
                victim->receive_damage("qi", (damage_bonus ) , me);
				return WHT "$N�����������Ʒ罣���ľ����������б�¶���ţ���ʱ$nȫ��ѪҺ��ʱ���ڣ�����\n" NOR;
		}

 //  ����ȼ�������
      if( me->query_skill("yifeng-jian",1) > 350 )
		{
              victim->receive_damage("qi", (damage_bonus )/3 , me);
			  return YEL "$N���Ʒ罣���Ѿ��ﵽ�˽���һ�ľ��磬�������������ִ�$n������Ѩ������\n" NOR;
		}
 //  ���ĵȼ�������
      if( me->query_skill("yifeng-jian",1)>250 )
		    {
				victim->receive_damage("qi", (damage_bonus - 100) /4 , me);
				return MAG "$N��̨������˲�������Ʒ罣���裬����һ������ߣ�����\n" NOR;
			}


 //  �����ȼ�������
        if( me->query_skill("yifeng-jian",1)>150 )
			{
                victim->receive_damage("qi", (damage_bonus - 100) / 6 , me);
				return CYN "$N���Ʒ罣�����뷵豹��澳�磬����һ������һ��������$n����������\n" NOR;
			}
 // �ڶ��ȼ�������
        if ( me->query_skill("yifeng-jian",1)>120 )
			{
				victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
				return RED "$N���Ʒ罣���ѳ���С��,ÿ��һ��������ǿ��"HIR"����"HIW"����$n����\n" NOR;
			}
}

int practice_skill(object me)
{
    return notify_fail("�Ʒ罣��ֻ��ͨ����"+HIC+"���־�"+NOR+"����������\n");
}

string perform_action_file(string action)
{
        return __DIR__"yifeng-jian/" + action;
}


