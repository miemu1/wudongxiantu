//tulong.c ����
// By Spiderii@ty
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
#define MAX_HITS    24
 
string perform_name() {return HIC"������"NOR;}

int perform(object me, object target)
{
        string weapon;
        int i,k;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
        
      if((int)me->query_skill("yitian-tulong",1) < 200 )
         return notify_fail("�������������������������ʹ������������\n");
      
      if((int)me->query_skill("literate",1) < 200 )
         return notify_fail("��Ķ���д�ֵȼ�������ʹ������������\n");  

      if((int)me->query_skill("sword",1) < 200 )
         return notify_fail("��Ļ�������������������\n");

        if( me->query("neili") <= 3000 )
                return notify_fail("�����������ʹ����������\n");

        if( me->query("jingli") <= 1000 )
                return notify_fail("��ľ�������ʹ����������\n");

        if( me->query_temp("yttlg/tulong"))
                return notify_fail("������������������\n");

        if( !me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword" )
                return notify_fail("�������޽�����ʹ������������\n");
              
        weapon = (me->query_temp("weapon"))->query("name");
              
       message_vision(HIY "\n$N��Ȼ�佣���ֱ䣬������" + weapon + HIY"���ʣ�ʹ��������������������һ�����ʻ���Ĳ����䷱,\n" +
        "�ʻ��ٵĲ�����ª������Ҳ���أ��Ƴ��֮��������Ҳ�վ��������֮�ѡ���ʽ���ﲨ��������ɵ����Ӿ�Э��״�����ơ�\n" NOR, me, target);
		k=me->query("int")/10;
        me->set_temp("yttlg/tulong",1);
        me->add_temp("apply/attack",me->query_skill("sword",1));
        me->add_temp("apply/damage",me->query_skill("sword")*k);
 
    for( i = 0; i < 10; i ++ ) {
       if (! me->is_fighting(target))
			break;
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
          me->add("neili",-100);
         
        }
    
        me->add("neili", -500);
        me->add_temp("apply/attack",-me->query_skill("sword",1));
        me->add_temp("apply/damage",-me->query_skill("sword")*k);
        me->add("jingli", -300);
        me->delete_temp("yttlg/tulong");
        me->start_busy(3+random(2));

        return 1;
}