// tie@fengyun
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "����"ZJBR"��ѩ"; }
int perform(object me, object target)
{
	string msg;
	int i, lmt, damage ;
	int ap,dp;	object weapon;
	weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HIW "��������ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);	
	if( (int)me->query_skill("huanhua-jian",1) < 600)
		return notify_fail(HIW "��ġ�佻��������������ң��޷�ʹ�á�������ѩ����\n"NOR);
	if( (int)me->query_skill("feihua-wuping",1) < 600)
		return notify_fail(HIW "��ġ��ɻ���ƾ���������ң��޷�ʹ�á�������ѩ����\n"NOR);
	if ((int)me->query("neili") < 1000)
		return notify_fail("��������������޷�ʹ�á�������ѩ����\n");	
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("���������Ϊ�������޷�ʹ�á�������ѩ����\n");	
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if ((int)me->query_skill("guiyuan-dafa", 1) <600)
		return notify_fail("��Ĺ�Ԫ�󷨻��̫ǳ���޷�ʹ�á�������ѩ����\n");
	if (me->query_skill_mapped("force")!="guiyuan-dafa")
		return notify_fail("���δʹ�ù�Ԫ�󷨣��޷�ʹ�á�������ѩ����\n");	
	if (me->query_skill_mapped("sword") != "huanhua-jian")
		return notify_fail("��û��ȷ�����ü��� ��\n");	
	if (! objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("������Ҳ���ðѽ���!");
	if (!(int)me->query("breakup"))
        return notify_fail("���ζ�����δͨ,�޷�ʹ�á�������ѩ����\n"NOR); 
	if (weapon->query("weapon_prop/damage") < 10)
		return notify_fail("��ʹ�õ�����̫�����ˣ�\n");	
	
	 message_vision(HBWHT "$N��ͨ佻�����ѧ��ʹ����佻��ɵľ�ѧ֮���裡\n" NOR, me, target);
	
	msg = HIY  "$N��Хһ�������ж�Ю����֮ʽ�������͵ı������ߣ����е�\n"+ weapon->name()+  "���籩������$n������\n\n" NOR;
	message_vision(msg,me,target);
	ap = me->query("xyzx_sys/level") + me->query_skill("huanhua-jian", 1) + me->query_skill("feihua-wuping",1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
        
		damage = me->query_skill("huanhua-jian",1) + me->queryry_skill("sword",1) + me->query_skill("guiyuan-dafa",1) + weapon->query("weapon_prop/damage");
		damage = damage + random(damage);
	if(damage < 10 ) damage = 10; //2015.4 �������˺�Ϊ0
	if(me->query_skill("huanhua-jian",1) < 2000)  lmt=4+random(4);	
	if(me->query_skill("huanhua-jian",1) >= 2000)  lmt=7+random(7);
	for(i=1;i<=lmt;i++)
	{
	msg =  HIW "$N���һ�����ӵ�"+chinese_number(i)+"����\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	target->receive_damage("qi", damage,me);
	target->receive_wound("qi", damage,me);
    me->add("neili", -100*lmt);
	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage +"��\n" NOR);
	
	if ( me->query_skill("huanhua-jian",1) > 3000)
	{
		message_vision(HIY"һ�ֽ���֮��$N���г����ֳ����µı仯�������������飬���е�"+ weapon->name()+  "�·����������㣬$N���һ������������ѩ����\n"NOR,me,target);
		damage = me->query_skill("huanhua-jian",1)*me->query("dex",1)+me->query_skill("feihua-wuping",1)*me->query("dex",1)+me->query_skill("guiyuan-dafa",1)*me->query("dex",1)+ me->query_skill("sword",1) + weapon->query("weapon_prop/damage")*(2+random(me->query("dex",1)))/2;
		damage = damage + random(damage);
		if(damage < 10 ) damage = 10; //2015.4 �������˺�Ϊ0
	if (random(ap) > dp/3 )	
	{
		message_vision(HIC"$N���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥���ƽ�$n\n"NOR,me,target);
		message_vision(HIB"$n�������콣�⣬�����Ծ��ֻ��һɲ��\n"NOR,me,target);
		message_vision(HIY"���콣Ӱ��Ϊһ��ֱ��$nǰ�أ�������ף�ֻ��һ����\n"NOR,me,target);
		target->receive_wound("jing", damage/2,me);
		target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/3,me);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage/3 +"�����������Ϊ"+ damage/2 +"��\n" NOR);
	//	if (!target->is_busy()) target->start_busy(random(3));
		me->add("neili", -(me->query("jiali")+100));
		target->add("neili", -(me->query("jiali")+1000));
	}
	else
    {

        message_vision(HIC"����$n����һЦ��������ת�������ָ��������$P�Ľ��ϣ�\n"NOR,me,target);
        message_vision(HIY"������$n��໮����$n��Ϊ�������ˡ�Ȼ��$nһ��ͷ��"+ weapon->name()+ "���ؿڰγ���\n"NOR,me,target);
        me->add("neili", -(me->query("jiali")+100));
		target->receive_damage("qi", damage/5,me);
        target->receive_wound("qi", damage/5,me);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage/5 +"������Ϊ"+ damage/5 +"��\n" NOR);
    }
	}
	me->start_busy(5);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
