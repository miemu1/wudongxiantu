// chan.c ��ر� ���־�
#include <ansi.h>
string query_name() { return "���־�"; }
inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;

if( me->query("family/family_name") != "Ѫ����" ) 
            return notify_fail("�㲻���Ѫ���ɵ������ô�õĳ����ǵ��书��\n"); 

    if( !target ) target = offensive_target(me);
    if( !me->is_fighting() )
        return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query_skill("yudi-bian",1) < 150)
        return notify_fail("��ġ���رޡ�����̫ǳ��ʹ���ˡ������־���\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ�������!\n");
    msg = HIB "$Nʹ����ر��еġ������־������ӳ�����ͼ��$n��ȫ���ס��\n";
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        msg += "���$p��$P���˸����ֲ���!\n" NOR;
        target->start_busy( (int)me->query_skill("yudi-bian") / 30 + 1);
        me->start_busy(1+ random(1));
    } else {
        msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        me->start_busy(3);
    }
    message_vision(msg, me, target);
    return 1;
}

