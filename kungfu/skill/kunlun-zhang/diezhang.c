// diezhang.c ��ɽ����
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	string msg, *limbs;
	int p,count, damage,skill1,skill2;
	int arg,ap,dp;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����ɽ���ơ�ֻ����ս���жԶ���ʹ�á�\n");
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ���ʩչ����ɽ���ơ���\n");

	if( me->query_skill_mapped("unarmed") != "kunlun-zhang" )
		return notify_fail("��û���������Ʒ���\n");

	if( (int)me->query_skill("kunlun-zhang", 1) < 300 )
		return notify_fail("����Ʒ�������죬����ʹ�á���ɽ���ơ���\n");

	if( (int)me->query_skill("xuantian-wuji", 1) < 300 )
		return notify_fail("��������޼����ȼ�����������ʹ�á���ɽ���ơ���\n");

	if( (int)me->query("str",) < 25 )
		return notify_fail("���������������ǿ������ʹ�á���ɽ���ơ���\n");

	if(me->query_skill_mapped("force") != "xuantian-wuji" )
		return notify_fail("��û���������޼���\n");
	if (me->query_skill_mapped("unarmed") != "kunlun-zhang")
		return notify_fail("��û��ȷ�����ü��� ��\n");	
	if( (int)me->query("max_neili", 1) < 10000 )
		return notify_fail("��������Ϊ����������ʹ�á���ɽ���ơ���\n");

	if( (int)me->query("neili", 1) < 5000 )
		return notify_fail("�����ڵ�����ʩչ������ô���С�\n");
	arg=(int)(me->query_skill("kunlun-zhang", 1) / 60);
	if ( arg > 50) arg = 50;	
	skill1 = (int)me->query_skill("kunlun-zhang", 1);
	skill2 = (int)me->query_skill("xuantian-wuji", 1);
	message_vision(HIG"$N����һ���������һ������������"HIW+ chinese_number(arg) +HIG"�ƣ���������ǰ�У�����������һ������$n��\n\n"NOR, me, target);
	ap = me->query("xyzx_sys/level") + me->query_skill("kunlun-zhang", 1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");	
	if( random(ap) > dp/3 )
	{
		limbs = target->query("limbs");
//		me->add_temp("lianzhao", arg);	 //2016.6.1���ɸģ��������б�ǣ��������������˺�������ò�����ص��Ʋ�������	
		for(count = 0; count < arg; count++)
		{
			message_vision( replace_string(HIG+SKILL_D("kunlun-zhang")->query_action(me, me->query_temp("weapon"))["action"],
			                   "$l", limbs[random(sizeof(limbs))]) + "��\n"NOR, me, target);
			damage = skill1+random(skill2);
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg = damage_msg(damage, "����");
			msg += "( $n"+eff_status_msg(p)+" )\n\n";
			//if (damage >1250) damage =1250;
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/2,me);
			message_vision(msg, me, target);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"�þ��жԵ�����Ѫ������Ϊ"+ damage +"������Ϊ"+ damage/2 +"��\n" NOR);
		}
		me->add("neili", -100 * arg);

//		me->delete_temp("lianzhao");  //2016.6.1���ɸģ����н���ȡ�����б��
	}
	else
	{

		me->add("neili", -200);
		msg =HIY"\n$n���ͼ��ٺ��ˣ�˳���Ʒ����һ�����㿪���⹥����\n" NOR;
		message_vision(msg, me, target);
	}
	 me->start_busy(3);
	return 1;
}
