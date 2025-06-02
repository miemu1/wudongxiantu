// feixian-steps.c
// by jeeny
 
#include <ansi.h> 
      
inherit SKILL; 
	
string *parry_msg = ({
	"$nֻ����Ҷ�׷ɣ�$N����˾�������˫�ۣ���ʽҲƫ���˹켣��\n",
	"$n�������ƣ�$N�����Զ�ϣ���ʽֻ��һ˿֮�ࡣ\n",
        "$n�������·���$N���ֲ�����ã���ʽ���ƣ�ȴ��Ȼ������\n",
        "$n��̤�仨��$N����շ���ĺ������㿪����ʽ����\n",
        "$n�������ݣ��Ų�һת���������ɶ㿪��ʽ��\n",
	"$n�������Ů��һ����ɴ��ƬҶδճ��\n",
	"$n�������������⻪������Բ�¡�$N������һ����Ȼ���Ƶ���ɢ�ˡ�\n",
	"$n����һת��$Nһ��ȴ�����˿յ��ϣ�ֻ��ó������\n",
});

string *dodge_msg = ({
	"$nֻ����Ҷ�׷ɣ�$N����˾�������˫�ۣ���ʽҲƫ���˹켣��\n",
	"$n�������ƣ�$N�����Զ�ϣ���ʽֻ��һ˿֮�ࡣ\n",
        "$n�������·���$N���ֲ�����ã���ʽ���ƣ�ȴ��Ȼ������\n",
        "$n��̤�仨��$N����շ���ĺ������㿪����ʽ����\n",
        "$n�������ݣ��Ų�һת���������ɶ㿪��ʽ��\n",
	"$n�������Ů��һ����ɴ��ƬҶδճ��\n",
	"$n�������������⻪������Բ�¡�$N������һ����Ȼ���Ƶ���ɢ�ˡ�\n",
	"$n����һת��$Nһ��ȴ�����˿յ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}
       
int valid_learn(object me) 
{ 
	int lvl, q; 

        q = me->query("per");
	lvl = me->query_skill("feixian-steps", 1); 
	if (lvl > 300) lvl = 300; 
       
	if (me->query("max_neili") < 200 + lvl * 2 + q * 25) 
		return notify_fail("�������㣬����������������\n");

 	if (me->query("per") < 30)
		return notify_fail("����˳�ª��òҲ��ѧ����������\n"); 

	if (me->query("dex") < 20)
		return notify_fail("�����������ѧ����������\n"); 

	return 1; 
} 
       
string query_dodge_msg(string limb) 
{ 
	return dodge_msg[random(sizeof(dodge_msg))]; 
} 
       
mixed valid_damage(object ob, object me, int damage, object weapon) 
{ 
	mixed result; 
	int ap, dp; 
       
	if ((int)me->query_skill("feixian-steps", 1) < 100 || 
	    ! living(me)) 
		return; 
	
	ap = ob->query_skill("dodge") + ob->query("per") * 20;
	dp = me->query_skill("dodge", 1) / 2 + me->query_skill("feixian-steps", 1) + me->query("per") * 30; 
       
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
      
int query_effect_dodge(object attacker, object me) 
{ 
	int lvl; 
      
	lvl = me->query_skill("feixian-steps", 1); 
	if (lvl < 50)  return 0; 
	if (lvl < 100) return 50; 
	if (lvl < 150) return 70; 
	if (lvl < 200) return 100; 
	if (lvl < 250) return 120; 
	if (lvl < 300) return 140; 
	if (lvl < 350) return 160; 
	if (lvl < 650) return 190; 
	return 200; 
} 
      
int practice_skill(object me) 
{ 
	int cost;

	cost = 60 + (int) me->query_skill("feixian-steps", 1) / 3;
	if ((int)me->query("qi") < 70) 
		return notify_fail("�������̫���ˣ�������ϰ���ɲ�����\n"); 
     
	if ((int)me->query("neili") < cost) 
		return notify_fail("������������ˣ��޷���ϰ���ɲ�����\n"); 
      
	//me->receive_damage("qi", 50); 
	//me->add("neili", -cost);
	cost = cost>=180?180:cost;
	return cost*30/100; 
} 
      
string perform_action_file(string action) 
{ 
	return __DIR__"feixian-steps/" + action; 
} 

void skill_improved(object me)
{
	int lvl;
	lvl = me->query_skill("feixian-steps", 1);

	if (lvl < 270)
	{
		me->apply_condition("yihua-except", lvl / 2 +
				    (int)me->query_condition("feixian-steps"));
	}
}	     
