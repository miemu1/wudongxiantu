//���ɽ���	�ϳ���ѧ400~1000
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;
mapping *action = ({
    ([
      "action":
"$N����һ����$w���⻯Ϊ����׹⣬�ֱ���$n���ʺ����Ҽ硢�����ҽ��󼲴�",
			"force" : 400,
	        "attack": 180,
	            "dodge" : 110,
	        "parry" : 120,
	        "damage": 170,
			 "sword": 100,
      "damage_type":    "����",
      ]),
    ([
      "action":
"$N���²�������������$w����ǰһ��,һƬ���ΰ׹���$n��ȥ��\n"
"$nʶ�����С�����С�ȡ�����������æ��ܲ���",
		"force" : 380,
	        "attack": 190,
	            "dodge" : 150,
	        "parry" : 130,
	        "damage": 160,
			 "sword": 110,
      "damage_type":    "����",
      ]),
    ([
      "action":
"$N����Ծ������$w����������⣬��$n�����ŵ�ȥ��\n"
"���С��������ޡ���Ȼ��$n�Ƶ���æ����",
		"force" : 450,
	        "attack": 185,
	            "dodge" : 130,
	        "parry" : 150,
	        "damage": 200,
			 "sword": 150,
      "damage_type":    "����",
      ]),
        
    ([
      "action":
"$N���类�������,ȹ��ƮƮ������$w��$n������£�\n"
"���С��������ˡ�����ǳ�����������,$n��ֱ������",
		"force" : 500,
	        "attack": 200,
	            "dodge" : 180,
	        "parry" : 170,
	        "damage": 190,
			 "sword": 170,
      "damage_type":    "����",
      ]),
    ([
      "action":
"$N����Ʈ��,���μ�ת,ת�ۼ�ͳ���һƬ����һ������Ӱ����л���$n!\n"
"���С��������衹�ȱ���,���˵�,�����ڲ���֮��",
		"force" : 550,
	        "attack": 180,
	            "dodge" : 200,
	        "parry" : 200,
	        "damage": 200,
			 "sword": 230,
      "damage_type":    "����",
      ]),
    ([
      "action":
"$N���潣�ߣ�Ѹ�����׵���$n��Χ����һ��������\n"
"$nֻ����Χ������Ӱ����ʱ���п�����һ��$w�����벻����\n"
"λ�ô�����ʵ����Σ������",
		"force" : 600,
	        "attack": 230,
	            "dodge" : 210,
	        "parry" : 220,
	        "damage": 270,
			 "sword": 260,
      "damage_type":    "����",
      ]),
});

int valid_learn(object me)
{
    object ob;
// 	if (!wizardp(me))
//		return notify_fail("��ʦͻȻ�Ӻڰ��г��˳�����������һ����������û���š�\n");	   
    if (me->query("family/family_name")!="���Ƴ�" && me->query("family/family_name")!="���Ƴ�")
        return notify_fail("�㲻�ǰ��ƴ���,�޷���ϰ�����������\n");
    if ((int)me->query("int",1) < 30)
        return notify_fail("���ɽ��������Ծ���֮�ˣ����޷�����ģ�\n");	
    if ((int)me->query("max_neili") < 100)
        return notify_fail("����������㣬�������򽣷��ľ���֮����\n");
 	if ((int)me->query_skill("jingyi-shengong", 1) < 100)
		return notify_fail("��ľ����񹦲�����ѧ���˷��ɽ�����\n");   
    if (!(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword" )
        return notify_fail("���������һ�ѽ�������������\n");
	
	
    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("feixian-jian",1)) > 399 && me->query("neili") > 150 && me->query("jiali")>1000 && random(20)>15 )
        {
                me->add("neili", -150);
                return ([
        "action": ""HIB"��Ȼ$N������ɽ��������Ͻ��⣬ʹ����������ɡ�������$w"HIG"�����Ƶ���\n"
        "$n"HIG"ֻ�������Ƶ������һ����������һ������ۣ������޷�������\n"NOR"",
		"dodge":	230,
		"parry":	300,	
		"attack":	280,	
        "force":	700,
        "damage":	270,
		 "sword":	400,
        "damage_type": "����"]);
		
        }
	
        return action[random(sizeof(action))];
}
/*
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
*/
int practice_skill(object me)
{
//		if (!wizardp(me))
//		return notify_fail("��ʦͻȻ�Ӻڰ��г��˳�����������һ����������û���š�\n");	
    if (me->query("family/family_name")!="���Ƴ�" && me->query("family/family_name")!="���Ƴ�")
        return notify_fail("�㲻�ǰ��Ƶ���,�޷���ϰ�����书��\n");
    if ((int)me->query("int",1) < 30)
        return notify_fail("���ɽ��������Ծ���֮�ˣ����޷�����ģ�\n");	
    if ((int)me->query("qi") < 30)
        return notify_fail("�����̫�ͣ�������ȥ����Σ�յģ�\n");
    if ((int)me->query("neili") < 35)
        return notify_fail("�������������û�а취���÷��ɽ�����\n");
//	       if( (string)me->query("gender") != "Ů��" )
//                return notify_fail("�ԴӰ��Ƴ�����ʧ֮�󣬷��ɽ�����ֻ��Ů�������ˡ�\n");   
    me->receive_damage("qi", 40);
        me->add("neili", -45);

    return 1;
}


string perform_action_file(string action)
{
return __DIR__"feixian-jian/"+action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int ap,dp,damage2;
	ap = me->query("int",1) * me->query_skill("feixian-jian",1);
	dp = victim->query("dex",1) * victim->query_skill("parry",1);
	damage2 = (int)me->query_skill("feixian-jian",1)+(int)me->query_skill("sword",1);
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("jingyi-shengong",1) < 100)	 return 0;
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || me->query_skill_mapped("force") != "jingyi-shengong") return 0;	
	if (damage2<10) damage2=10;
    if( random(ap) > dp/10 && random(6)==0 && me->query("jiali")>0) 
	{
        victim->receive_wound("qi", damage2+damage_bonus,me );
		victim->receive_damage("qi", damage2+damage_bonus,me );
		me->add("neili",-100);
        return HIW "$n��������" HIC"����Բ֮ҹ��" HIM"���Ͻ�֮�ۡ�" HIB"��һ��������" HIY"��������ɡ���"MAG"$n�ѱ�$N��������ɽ������ˣ�\n"NOR;
    }
}
