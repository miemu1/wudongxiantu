// jianshen.c ����һЦ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "����"ZJBR"һЦ"; }
int perform(object me, object target)
{
	string msg;
	int i,extra,attack_time;
	object weapon;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����һЦֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if ( me->query_skill("feixian-jian",1) < 240) 
		return notify_fail("��ķ��ɽ������������죡\n");
	if ( me->query_skill("jingyi-shengong",1) < 240) 
		return notify_fail("��ľ����񹦻��������죡\n");		
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("ʹ�ý���һЦ��������һ�ѽ���\n");
	if (target && target->query_temp("apply/shade_vision")) 
		return notify_fail("�Է������ˣ��㿴����"+target->query("name")+"��\n"); 	
	if ( me->query_skill_mapped("force") != "jingyi-shengong")
		return notify_fail("����뼤�������񹦲���ʹ�á�����һЦ����\n");   	 
	if( (int)me->query("neili") < me->query_skill("feixian-jian",1)*4  ) 
		return notify_fail("�������������\n");
	if( (int)me->query("jingli") < 100 )
		return notify_fail("��ľ���������\n");		
	if( (int)me->query("max_neili") < 100  ) 
		return notify_fail("���������Ϊ������\n");
	if (me->query_skill_mapped("sword") != "feixian-jian")
		return notify_fail("��û��ȷ�����ü��� ��\n");
	if (me->query_temp("autolian"))
		return notify_fail("�����ڷ����Զ����У�\n"); 	
	if ( me->query_temp("cooldown") )	//CDд��	2017.9.7���
		return notify_fail("�㴦�ڼ�����ȴ״̬�У�������ʹ�ðɡ�\n");
		
	extra = me->query_skill("feixian-jian",1) ;

	msg = RED  "$N��̤�۷��ɲ��ݣ�ͬʱʹ���۷��ɽ����ݵľ��裭��������һЦ�������е�"+ weapon->name() +"����һ�����磬�����Ļ���$n��" NOR;
	me->set_temp("cooldown", 2);	//CDд��	2017.9.7���
	call_out("del_cooldown", 5, me);	//CDд��1
	msg =  HIW "����һ������ʧ��������\n" NOR;	
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	me->add_temp("apply/strength", extra);
	attack_time = me->query_skill("feixian-jian",1)/600;
	if (attack_time < 1) attack_time= 1;
	if (me->query("jm/nanhai")) 
	{
		if (attack_time > 100) attack_time= 100;
	} else 
	{
		if (attack_time > 50) attack_time= 50;
	}	
	
//		me->add_temp("lianzhao", attack_time);	 //2016.6.1���ɸģ��������б�ǣ��������������˺�	
	for(i=0;i < attack_time;i++)
	{
	msg = RED "$N����ͻת�������طɣ�\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add_temp("apply/strength", -extra);
	me->add("neili", -(100*attack_time));
//	me->delete_temp("lianzhao");  //2016.6.1���ɸģ����н���ȡ�����б��	
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