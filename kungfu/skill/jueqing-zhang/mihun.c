#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "�Ի�"; }
int perform(object me, object target)
{
        string msg;
int busy; 
       busy=(int)me->query("zjb_dj/dj")/2+1;  
    if (busy > 20 ) busy=20; 

	if( !target ) target = offensive_target(me);

        if ( !wizardp(this_player()) && (me->query("family/family_name") != "�ƻ���"))
                return notify_fail("�㲻���ƻ������Ӳ���ʹ��ڤ����.\n
                                    �����Ʋ�����, ���ƻ������Ӳ���, �治֪��������ôѧ���!\n
                                    Ҫ������λ����֪������ɲ���.\n");


	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�Ի�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "�����Ѿ���־�����ˣ�\n");
		
	if( (int)me->query_skill("jueqing-zhang", 1) < 40 )
		return notify_fail("��ľ����Ʒ�������죬����ʹ�á��Ի꡹��\n");

	msg = HIM "ͻȻ��Χ�����������ֻ꣬��$Nվ���������$n����һЦ��\n";

	me->start_busy(1);
   if( random(me->query_exp()*4) > target->query_exp() ) { 
        msg += HIR " $p������ؿ����㣬����ϧ��֮����Ȼ���𣬾�Ȼ�����Լ���ս��֮�С�\n" NOR;
         target->start_busy( (int)me->query_skill("jueqing-zhang") / 40 );
	} else {
		msg += HIY "$p����Ŀ���$Pһ�ۣ���û���ϵ���\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
