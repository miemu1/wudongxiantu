//by system_2
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int time;
    object weapon;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("�����־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
if ( (string)me->query("family/family_name") != "��ң��") 
     return notify_fail("ֻ����ң���Ӳ���ʹ�ø�PFM��\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");
    if( (int)me->query("neili") < 1200 )
        return notify_fail("�������������\n");
                if(me->query_skill_mapped("dodge") != "lingbo-weibu") 
               return notify_fail("����貨΢��û�������Ṧ�ϰ�? \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "�Ѿ�æ�����ˣ�\n");
                
        if( (int)me->query_skill("zuixin-sword", 1) < 200 )
                return notify_fail("�㻹û�õ���ң���Ľ��ľ��裬ʹ���������־���\n");

    msg = HIM "$N����Ʈ�죬�����н������һ�ס����־���������$nˣ��ͷ���ۻ���\n";

if( random( me->query_skill("zuixin-sword",1)+me->query_skill("sword",1) ) > (me->query_skill("unarmed",1)*2)/3 ) {
   msg += HIB "$p�����ԻõĽ�������Χ��˸�����ѳ���\n" NOR;
             target->start_busy( (int)me->query_skill("lingbo-weibu") /2 + 1);
   me->add("neili", -1000);
        } else {
        me->start_busy(2);
           me->add("neili",-800);        
                msg += HIY "$p��ס������һ������ѹ������а�⡣\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

