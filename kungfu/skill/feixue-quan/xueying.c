#include <ansi.h>

string query_name() { return "����"ZJBR"ѪӰ"; }
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !me->is_fighting() )
        return notify_fail("��"+HIR"����ѪӰ"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


    if( (int)me->query_skill("feixue-quan", 1) < 300 )
          return notify_fail("��ķ�Ѫȭ��������������ʹ�á�����ѪӰ����\n"); 

    if( (int)me->query_skill("huaxue-dafa", 1) < 300 )
          return notify_fail("��Ļ�Ѫ�󷨲�������������ʹ�á�����ѪӰ����\n"); 

    if((int)me->query_skill("cuff",1) < 300)
                return notify_fail("��Ļ���ȭ������Ϊ����, ����ʹ����һ���� !\n");

    if( (int)me->query("max_neili") < 12000 )
           return notify_fail("���������Ϊ�������ߡ�\n");

    if( (int)me->query("neili") < 12000 )
           return notify_fail("������������ˡ�\n");

    if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     

      if ((int)me->query("neili")<5000)
        {
        return notify_fail(HIC"����������������û�ܽ�������ѪӰ��ʹ�꣡\n"NOR);
        }
      msg  = HIR"ֻ��$N˫Ŀ��죬ȫ���½��޶������г�Хһ����\n"NOR;
      msg += HIR"$N������ע��˫�ۣ��͵�һ����˫��Ѫ�����䣬\n"NOR;
      msg += HIR"��ʱֻ��������Ѫ��������˫���ѿ����漴������\n"NOR;
      msg += HIR"$N���� ����ž�� һ���죬˫��˳�������Ѫ�裬\n"NOR;
      msg += HIR"ʹ��һ�ƣ�ɲ�Ǽ�һ�������ߵ�Ѫǽ�εض���\n"NOR;
      msg += HIR"�Ӷ�������ɽ����֮����$nӿȥ��\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                me->start_busy(3);
                target->start_busy(random(3));
                damage = (int)me->query_skill("feixue-quan", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage*10);
                target->receive_wound("qi", damage*10);
                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage/1);
      msg += HIG"$n��״��æ����������˫���͵��Ƴ�����ʱ"+HIW"�Ʒ�"NOR+""+HIG"��ӿ����!\n"NOR;
      msg += HIG"û�뵽ǿ���������Ȼ��"+HIR"Ѫǽ"NOR+""+HIG"˿��ûӰ�죬\n"NOR;
      msg += HIG"ɲ�Ǽ�$n�ͱ�"+HIR"Ѫǽ"NOR+""+HIG"��û��\n"NOR;
                me->add("neili", -10000);
        } else
        {
                me->start_busy(4);
        msg += HIY"$n��Ȼ�����������������һ�����㽫ѪǽϨ��\n"NOR;
                me->add("neili", -2000);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        if(userp(target)) target->fight_ob(me);
        else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}

