// shen.c  ͥԺ�������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "ͥԺ������"ZJBR"����"; }
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;
	int ap,dp;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("��ͥԺ���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
    if((int)me->query_skill("guiyuan-dafa",1)<300)
        return notify_fail("��Ĺ�Ԫ�󷨲�����񣬲���ʹ�á�ͥԺ�����������\n");	
    if( (int)me->query_skill("huanhua-jian", 1) < 450 )      	
         return notify_fail("���佻�����������죬����ʹ�á�ͥԺ�����������\n");
	if (me->query_skill_mapped("force")!="guiyuan-dafa" )
		return notify_fail("��δʹ�ñ����ڹ�������ʹ�þ�����\n");	
	if (me->query_skill_mapped("sword")!="huanhua-jian" )
		return notify_fail("��δʹ��佻�����������ʹ�þ�����\n");		
		
        msg = HIY "$Nʹ��佻�������ͥԺ�������������ʽ��Ȼ��죬��������Է���\n";
	ap = me->query("xyzx_sys/level") + me->query_skill("huanhua-jian", 1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
     if( random(ap) > dp/4 )
	{
		attack_time = (int)me->query_skill("huanhua-jian", 1) / 60;	
		if(attack_time < 1) attack_time = 1;
        if(attack_time > 50) attack_time = 50;
		me->add_temp("lianzhao", attack_time);	 //2016.6.1���ɸģ��������б�ǣ��������������˺�		
		msg += CYN " ͥԺ������� �������̣���Ļ��������\n" NOR;
		for(i = 0; i < attack_time; i++)
		{
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}
		me->add("neili", -100*attack_time);
		me->delete_temp("lianzhao");  //2016.6.1���ɸģ����н���ȡ�����б��		
	}
	else
	{
		msg += "����$n��͸��$N����Ļ����û���ϵ���\n" NOR;
	}
	message_vision(msg, me, target);
	me->start_busy(3);
	return 1;
}
