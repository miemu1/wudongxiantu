// feixian.c �������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <condition.h>
inherit F_SSERVER;
string query_name() { return "����"ZJBR"����"; }
int perform(object me, object target)
{
	int damage,damage1;
	string msg;
	object weapon;
	int extra;
	int ap,dp;

	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��������ɡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ��������ɡ���\n"NOR);
//	if (target && target->query_temp("apply/shade_vision")) 
//		return notify_fail("�Է������ˣ��㿴����"+target->query("name")+"��\n"); 	
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if ((int)me->query_skill("feixian-jian", 1) < 360 )
		return notify_fail(WHT"��ķ��ɽ���������죬ʹ������������ɡ���\n"NOR);
	if ((int)me->query_skill("feixian-bu", 1) < 360 )
		return notify_fail(WHT"��ķ��ɲ�������죬ʹ������������ɡ���\n"NOR);
	if ((int)me->query_skill("jingyi-shengong", 1) < 360 )
		return notify_fail(WHT"��ľ����񹦲�����죬ʹ������������ɡ���\n"NOR);
	if( (int)me->query("int",1) < 30 )
		return notify_fail(HIC"������Բ��㣬�޷�����������ɡ�������\n"NOR);
	 if ( me->query_skill_mapped("sword") != "feixian-jian")
         return notify_fail("����뼤�����ɽ�������ʹ�á�������ɡ���\n");   
	 if ( me->query_skill_mapped("force") != "jingyi-shengong")
         return notify_fail("����뼤�������񹦲���ʹ�á�������ɡ���\n");  
	 if ( me->query_skill_mapped("dodge") != "feixian-bu")
         return notify_fail("��������ɡ�����Ҫ�о���Ĳ�����ϣ�\n");  	 
	//if (!(int)me->query("breakup"))
		//return notify_fail("���ζ�����δͨ,�޷�ʹ�á�������ɡ���\n"NOR);
	if ((int)me->query("max_neili")<1500)
		return notify_fail(RED"��������Ϊ���㣬�޷�ʹ�á�������ɡ���\n"NOR);
	if ((int)me->query("max_jingli")<200)
		return notify_fail(RED"�㾫����Ϊ���㣬�޷�ʹ�á�������ɡ���\n"NOR);
	if ((int)me->query("neili")<1500)	
		return notify_fail(HIC"����������������û�ܽ���������ɡ�ʹ�꣡\n"NOR);
	if ((int)me->query("jingli")<200)	
		return notify_fail(HIC"�����ھ���������û�ܽ���������ɡ�ʹ�꣡\n"NOR);
	if (me->query_temp("autolian"))
		return notify_fail("�����ڷ����Զ����У�\n"); 	
	if ( me->query_temp("cooldown") )	//CDд��	2017.9.7���
		return notify_fail("�㴦�ڼ�����ȴ״̬�У�������ʹ�ðɡ�\n");
		
	msg = HBWHT "$N��ͨ���ɽ�����ʹ���˰��Ƴǵľ�ѧ֮���裡\n" NOR;
	message_vision(msg, me, target);
	me->set_temp("cooldown", 3);	//CDд��	2017.9.7���
	call_out("del_cooldown", 6, me);	//CDд��1	
	ap = me->query("xyzx_sys/level") + me->query_skill("feixian-jian", 1) + me->query_skill("feixian-bu", 1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");	
	extra = me->query_skill("feixian-jian",1) + me->query_skill("sword",1);

	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	msg = HIW "$N����������ʹ��Ҷ�³ǵġ�"HIG"�������"HIW"�����������콣Ӱ�����赲��\n"NOR;
	message_vision(msg, me, target);

	msg = MAG"���Ƴ�����"HIR"��"HIG"���ɽ���"HIY"֮"U+HIG"��"HIW"Բ"HIY"֮"HIW+BLK"ҹ"NOR+HIR"��"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = MAG"���Ƴ�����"HIR"��"HIG"���ɽ���"HIY"֮"U+HIG"��"HIW"��"HIY"֮"HIW+BLK"��"NOR+HIR"��"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = MAG"���Ƴ�����"HIR"��"HIG"���ɽ���"HIY"֮"U+HIG"һ"HIW"��"HIY"��"HIW+BLK"��"NOR+HIR"��"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = MAG"���Ƴ�����"HIR"��"HIG"���ɽ���"HIY"֮"U+HIG"��"HIW"��"HIY"��"HIW+BLK"��"NOR+HIR"��"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);	
	me->add("neili", -1500);
	damage1 = me->query_skill("feixian-jian", 1);
	damage1 = damage1 + random(damage1);
	target->receive_damage("qi", damage1,me);
	target->receive_wound("qi", damage1/5,me);
	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage1 +"������Ϊ"+ damage1/5 +"��\n" NOR);
//�ڶ���	
if ((int)me->query_skill("feixian-jian", 1)>200 && (int)me->query_skill("feixian-bu", 1)>200)
{	
	msg = HIW "$N" HIW "ʹ�����ɽ���֮ "HIG"������һЦ��"HIW"������" + weapon->name() + HIW "�û�������������$n" HIW "��ü�Ĵ�����\n" NOR;
	message_vision(msg, me, target);
	if (random(ap) > dp/3 )
	{
		damage = me->query("xyzx_sys/level") + me->query_skill("sword",1) + me->query_skill("feixian-jian",1) + me->query_skill("jingyi-shengong",1) + me->query_skill("feixian-bu",1);
		damage = damage + random(damage);	
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/5,me);
		msg =HIR "$n" HIR "��$N" HIR "����ǵصĽ���������$n����������$N�Ľ������ڣ���ʱ��������͸��\n" NOR;
		message_vision(msg, me, target);		
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage/5 +"��\n" NOR);
		me->add("neili", -1500);
		me->add("jingli", -100);
		me->add_temp("apply/attack", extra*2);
		me->add_temp("apply/damage", extra*2);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));	
		me->add_temp("apply/attack", -extra*2);
		me->add_temp("apply/damage", -extra*2);		
	}
	else
	{
		me->add("neili", -1100);
		msg = CYN "��$n" CYN "����˫�ۣ���֪��$N�Ľ������ڣ�����һת���������һ����\n" NOR;
		message_vision(msg, me, target);
	}
}
//������
if ((int)me->query_skill("feixian-jian", 1)>300 && (int)me->query_skill("feixian-bu", 1)>300)
{ 
	msg = HIW "$N" HIW "ʹ�����ɽ���֮"HIG"���˽���һ��"HIW"������" + weapon->name() + HIW "����$N�϶�Ϊһ���񽣴������ֱ��ͷ����\n" NOR;
	message_vision(msg, me, target);
	if (random(ap) > dp/3 )
	{
		if (me->query("jm/nanhai")) damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1)*me->query("int",1)/2 + me->query_skill("jingyi-shengong",1)*me->query("int",1)/3 + me->query_skill("feixian-bu",1);
		else damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1) + me->query_skill("jingyi-shengong",1)*me->query("int",1)/3 + me->query_skill("feixian-bu",1);
		damage = damage + random(damage);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/2,me);
		target->receive_damage("jing",damage,me);
		target->receive_wound("jing",damage/2,me);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage/2 +"�����������Ϊ"+ damage +"������Ϊ"+ damage/2 +"��\n" NOR);
		me->add("neili", -1500);
		me->add("jingli", -100);
		msg =HIR "$n" HIR "�������޴ӷ���$N" HIR "�Ľ���ֱ�ӱ�����͸���������Ѫ���磡\n" NOR;
		message_vision(msg, me, target);
		me->add_temp("apply/attack", extra*3);
		me->add_temp("apply/damage", extra*3);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));	
		me->add_temp("apply/attack", -extra*3);
		me->add_temp("apply/damage", -extra*3);
	}
	else
	{
		if (me->query("jm/nanhai"))
		{
		damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1) + me->query_skill("jingyi-shengong",1)*me->query("int",1)/2 + me->query_skill("feixian-bu",1);
		damage = damage + random(damage);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
		msg = HIR "���ǽ��������ˣ������ǽ����˻����ˣ�\n" NOR;
		message_vision(msg, me, target);		
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage +"��\n" NOR);
		}
		me->add("neili", -1500);
		msg = CYN "��$n" CYN "��Ȼ��֮����������Ϭ"CYN "˫ָ�������΢��������������棬" + weapon->name() + HIW "�ͺ����δ������������$n˫ָ֮�䡣\n" NOR;
		message_vision(msg, me, target);
	}

}
//���Ķ�
if ((int)me->query_skill("feixian-jian", 1)>400 && (int)me->query_skill("feixian-bu", 1)>400 )
{
	msg = HIW "$N" HIW "ʹ�����ɽ���֮"HIG"�����������"HIW"��$N�������޽����������޽���\n" NOR;	
	msg += HIW "$n" HIW "�о����콣�⣬���ָо������κ�ɱ�⡣"HIC"�˽��·����˼䣬�ַ·��޴����ڡ�\n" NOR;	
	msg += HIB "��Բ֮ҹ��"HIC"�Ͻ�֮�ۣ�"HIR"һ��������"HIM"������ɣ�����"HIC"\n" NOR;	
	msg +=HIC "��һ��������û�����ܿ��� "HIR"���������˶��Ѿ����� "HIC" \n" NOR;
	message_vision(msg, me, target);
	if (random(ap) > dp/4 )
	{
		if (me->query("jm/nanhai")) damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1) * me->query("int",1)*2/3 + me->query_skill("jingyi-shengong",1) * me->query("int",1)*2/3 + me->query_skill("feixian-bu",1)*me->query("int",1)*2/3+me->query_skill("force",1);
		else damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1) * me->query("int",1) + me->query_skill("jingyi-shengong",1) * me->query("int",1) + me->query_skill("feixian-bu",1)*me->query("int",1)+me->query_skill("force",1);
		damage = damage + random(damage);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
		target->receive_damage("jing",damage,me);
		target->receive_wound("jing",damage,me);		
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage +"�����������Ϊ"+ damage +"������Ϊ"+ damage +"��\n" NOR);
		me->add("neili", -1500);
		me->add("jingli", -100);
		target->apply_condition("no_enforce", 20);
		msg =HIC "��һ�� "HIR"���Ρ�"HIC"�����δ����֮�ȣ�"HIR"����"HIC"������ѳ���֮�ᣡ"HIW"������Ϊ���ᣬ�Բ���Ϊ�䣡�� \n" NOR;		
		msg +=HIR "û������������һ�򵥲��úͻԻͣ�" YEL "û������������һ�����ٶȣ�"HIC"���Ѳ���һ������\n" NOR;
		msg +=HIC "�˾��ǽ� "HIR"�������� "HIC"�˷ǽ�"HIR"������"HIC" \n" NOR;	
		message_vision(msg, me, target);
		me->add_temp("apply/attack", extra*4);
		me->add_temp("apply/damage", extra*4);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));	
		me->add_temp("apply/attack", -extra*4);
		me->add_temp("apply/damage", -extra*4);
		if (me->query("jm/nanhai")) 
		{
			msg =HIW "������ʧ֮�ʣ�"HIM"�����ٴδ����ⱬ��һ�������貵Ĺ�â��"HIR"��һ�������ǰ���ã���ͬ���㣡\n" NOR;
			message_vision(msg, me, target);
			target->receive_damage("qi",damage/3,me);
			target->receive_wound("qi",damage/3,me);		
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ���׷�ӶԵ�����Ѫ������Ϊ"+ damage/2 +"������Ϊ"+ damage/2 +"��\n" NOR);	
		}
/*		if (random(6)==1)
		{
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�������˻��ԡ�\n" NOR);
			target->unconcious();			
		}	*/
	}
	else
	{	
		msg = CYN "$n������������ν�������ʧ�����֮�У�����һ�������������Ƶ���$n���������ͣ����һϢƬ�̣��ͱ��Ƶ�¶�������Σ�ֻ�������Ǳܿ��˴󲿷ֽ�����\n" NOR;
		message_vision(msg, me, target);
		if (me->query("jm/nanhai")) damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1)*me->query("int",1) + me->query_skill("jingyi-shengong",1) + me->query_skill("feixian-bu",1);
		else damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1)*me->query("int",1)/2 + me->query_skill("jingyi-shengong",1) + me->query_skill("feixian-bu",1);
		damage =damage + random(damage);
		target->receive_damage("jing",damage,me);
		target->receive_wound("jing",damage,me);
		me->add("neili", -1500);
		me->add("jingli", -100);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ��˾��������Ϊ"+ damage +"������Ϊ"+ damage +"��\n" NOR);
	}

}
	me->start_busy(1);
	return 1;
}

void del_cooldown(object me)	//CDд��1
{ 
	if ( !objectp(me) ) return;
	if ( me->query_temp("cooldown") )	
	{
		me->delete_temp("cooldown");
		tell_object(me, HIM"�����һ�����������Ľ������ջص��\n"NOR);
	}	
}