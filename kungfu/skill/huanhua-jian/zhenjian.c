// zhen.c 佻����� ֮ �Һ�ɹ���ǧ��
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "�Һ�ɹ�"ZJBR"��ǧ��"; }
int perform(object me, object target)
{
	int damage, ap, dp;
	object obj;
	string w_name;

	w_name = me->query("weapon/name");
	obj = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���Һ�ɹ���ǧȥ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if ((int)me->query_skill("huanhua-jian", 1) < 450)
		return notify_fail("���佻�����������죬�����˽����硣\n");
	if ((int)me->query_skill("guiyuan-dafa", 1) < 300)
		return notify_fail("��Ĺ�Ԫ�󷨻��̫ǳ���޷�������г�����\n");
	if (me->query_skill_mapped("force")!="guiyuan-dafa")
		return notify_fail("���δʹ�ù�Ԫ�󷨣��޷�������г�����\n");	
	if ((int)me->query("neili",1) < 1000)
		return notify_fail("��������������޷�������г�������\n");
	if (! objectp(obj = me->query_temp("weapon")) || (string)obj->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ�\n");	
	if (me->query_skill_mapped("sword") != "huanhua-jian")
		return notify_fail("��û��ȷ�����ü��� ��\n");
	if (obj->query("weapon_prop/damage") < 10)
		return notify_fail("��ʹ�õ�����̫�����ˣ�\n");	
	
	message_vision( HIY "$N�����ڽ���Ĭ��������ֻ�������һ������Ȼ��������ҫ��$N���г�������Ϊ����\n"
	                + "�أ���������ư���$n���������\n"NOR, me, target );
	ap = me->query("xyzx_sys/level") + me->query_skill("huanhua-jian", 1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	if( random( ap ) > dp/3 )
	{
		damage = me->query_skill("huanhua-jian",1) + me->query_skill("force") + me->query_skill("sword",1) + obj->query("weapon_prop/damage")*2;
		damage = damage+random(damage);
		if(damage < 10 ) damage = 10; //2015.4 �������˺�Ϊ0
//		if( objectp(obj) && w_name!=obj->query("name") )	//�����ʲô��˼��
		if( objectp(obj) )	
		{
			target->receive_wound("jing", damage,me);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage,me);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage +"�����������Ϊ"+ damage +"��\n" NOR);
		//	if (!target->is_busy()) target->start_busy(1 + random(5));
		}
		else
		{
			target->receive_wound("jing", damage/3,me);
			target->receive_damage("qi", damage/3,me);
			target->receive_wound("qi", damage/3,me);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage/3 +"������Ϊ"+ damage/3 +"�����������Ϊ"+ damage/3 +"��\n" NOR);
		//	if (!target->is_busy()) target->start_busy(1 + random(2));
		}
		message_vision( HIM "�����ʻ�������Һ�ɹ���ǧ����$N�ĳ���������Ƭ������Ҷ��ɢ��һ�أ�\n"NOR, me, target );
	}
	else
	{
		message_vision( HIY "����$p�ζ����Σ�Ѹ�ٵ������˽��ꡣ\n" NOR, me, target );
	}
//	if( !target->is_killing(me) ) target->kill_ob(me);
	me->add("neili", -200);
/*		//2017.4.20���ɸģ���һ��pfm����һ������������Ҳ�ò���
	if( objectp(obj) && w_name!=obj->query("name") )
	{
		me->set("weapon/make",0);
		destruct( obj );
		me->delete("weapon");		
		me->save();
	}
	else
	{
		destruct( obj );
	}	
	message_vision( HIM "�����ʻ�������Һ�ɹ���ǧ����$N�ĳ���������Ƭ������Ҷ��ɢ��һ�أ�\n"NOR, me, target ); */
	me->start_busy(3);
	return 1;
}
