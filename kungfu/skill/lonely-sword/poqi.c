// poqi.c ����ʽ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "����ʽ"; }
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, force;

//        
     if( (int)me->query_skill("lonely-sword",1)<135)
            return notify_fail("��Ķ��¾Ž���Ϊ�����޷�ʹ������ʽ\n");

   if( (int)me->query_skill("zixia-shengong",1)<135)
            return notify_fail("�����ϼ�񹦻�������죬�޷�ʹ������ʽ��\n");
		if( me->query("family/family_name") != "��ɽ��"  )
                return notify_fail("�㲻�ǻ�ɽ�ɵ���\n");

     me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( skill < 135)
            return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n");

        if( me->query("neili") < 250 )
            return notify_fail("��������������޷����á�����ʽ����\n");
	 force = me->query("sword");

        msg = HIC "$NǱ�˶��¾Ž�������ʽ���������ὣʹ���������ۣ����޻��ε�ֱ
��$n�ĵ��\n"NOR;
        message_combatd(msg, me, target);

        ap = me->query_skill("sword") ;
        dp = target->query_skill("dodge");
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = BLU"$n��ʱ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������\n"NOR;
            target->add("neili",force );
//            target->set("neili",);
            me->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
            if(userp(me))

            msg = "����$n������$N����ͼ�������ؽ��Ż��������������ڻ��е�
����\n"NOR;
            me->start_busy(2);
		message_combatd(msg, me, target);
        }

        return 1;
}
