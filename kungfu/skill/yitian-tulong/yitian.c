//yitian.c ����
// By Spiderii@ty
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string perform_name(){ return HIC"�����"NOR; }

int perform(object me, object target)
{
      string msg; 
      int i;                                  
      object weapon = me->query_temp("weapon");

      if (!weapon || weapon->query("skill_type") != "sword")
         return notify_fail("�������޽������ʹ�ó����죡\n");

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
         return notify_fail("����ֻ����ս���жԶ���ʹ�á�\n");
             
      if((int)me->query_skill("yitian-tulong",1) < 180 )
         return notify_fail("���������������������죬��ʹ�������죡\n");
      
      if((int)me->query_skill("literate",1) < 180 )
         return notify_fail("��Ķ���д�ֵȼ�����������д�����죡\n");

      if((int)me->query_skill("sword",1) < 180)
         return notify_fail("��Ļ��������ȼ�����������д�����죡\n");  
      
      if((int)me->query("max_neili") < 1500 )
         return notify_fail("���������Ϊ�ƺ�����! \n");
      
      if((int)me->query("neili") < 500 )
         return notify_fail("��ĵ�ǰ�����ƺ�������\n"); 

      if( target->is_busy() )
         return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

      if (me->query_skill_mapped("sword") != "yitian-tulong"
       || me->query_skill_mapped("parry") != "yitian-tulong")
         return notify_fail("�������޷�д�������졹��\n");

      i = random((int)(me->query_skill("yitian-tulong",1)/100));
      if(i < 1) i=1;
      if(i > 8) i=8;                                                                                 
      msg = HIC"$Nһת����Ȼ��������"+weapon->query("name")+HIC"���ʣ�ʹ��������������������һ��������������������\n"+
               "�������������캨�����ۻ�ս������ݴ����Ʈ����ѩ�裬���ش�,�绢�ף����󲽣�\n" NOR;
      me->add("neili", - 200);
      if((random(me->query_skill("literate", 1)) > target->query_skill("literate", 1)/5)
        &&  random(me->query("combat_exp")) > target->query("combat_exp")/2) {
            target->start_busy(i+2);
            msg += HIR"$n��ο��ĳ����еİ������$N���в����Լ�����ҪѨ��������ֻ��������ס�����ؿ�\n"+
                      "Ҫ����ͻ��ϥͷһ�飬ԭ���ѱ�$N���Ƶ���Ѩ����\n"NOR;
      }
      else {
            me->start_busy(2);
            msg += HIY"��֪$p��ͨ�Ĳɣ���㱼��ƾ�$P��һ��֮������д��һֱ����Ҳ�صþ���������\n"+
                      "˿����������\n"NOR;
      }
      message_vision(msg, me, target);
      me->start_perform(3,"���������");
      return 1;
}
