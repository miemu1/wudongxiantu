
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;
string *dodge_msg = ({
    "$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
    "����$n����������������һ���������$N��һ�С�\n",
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
        "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ��о����յرܿ���$N��һ�С�\n",
        "$n�������ĵ�����һ������ͷ΢��,�����ܹ���$N��һ�С�\n"
});
int valid_enable(string usage) { return (usage == "dodge") ; }
int valid_learn(object me) 
{ 
    if (me->query("family/family_name")!="佻�����")
   return notify_fail("�㲻����佻����ɣ��޷�ѧϰ���ż��ܡ�\n");
if ((int)me->query_skill("guiyuan-dafa",1) < 150)
return notify_fail("��Ĺ�Ԫ�󷨻��̫ǳ��\n");
return 1;           
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	    if (me->query("family/family_name")!="佻�����")
   return notify_fail("�㲻����佻����ɣ��޷���ϰ���ż��ܡ�\n");
        if( (int)me->query("qi") < 50 )
                return notify_fail("�������̫���ˣ������˷ɻ���ƾ��\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feihua-wuping/" + action;
}
	//2017.3.25���ɷ��ob_hit��Ч���������˺�Ϊ0������bug�й�
int ob_hit(object ob, object me, int damage)
{

        int j,ap,dp;
		ap = me->query_skill("feihua-wuping", 1) * me->query("int",1);
		dp = ob->query_skill("dodge", 1) * ob->query("dex",1);

	if (damage <10)  damage=10;      	
      if(random(ap) > dp/10
		&& me->query_skill("guiyuan-dafa",1) > 100
		&& me->query_skill("feihua-wuping", 1) > 200
		&& me->query_skill_mapped("force") == "guiyuan-dafa"
        && me->query("neili") > 1000
		&& random(5)==0	)
        { 	
			message_vision(HIG"$N���ӳ����һ����й���ƬҶ��ճ�¡��ľ��磬��������$n����ʽ��\n"NOR, me, ob); 		
            j = -(damage+random(damage)); 
			me->add("neili", -100 );
			return j;        
        }  
		
}
