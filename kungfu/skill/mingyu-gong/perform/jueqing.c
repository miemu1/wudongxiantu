// This program is a part of NITAN MudLIB

#include <command.h>
#include <ansi.h>
inherit F_SSERVER;

string query_name() { return HIR"����"ZJBR"����"NOR; }
int perform(object me, object target)
{
        string msg;
        int ski_value, max_lv,ap,dp,aa;
       aa=me->query_skill("jueqing-xinjing", 1) / 10;
        ski_value = random(me->query_skill("mingyu-gong", 1));
        max_lv = me->query_skill("mingyu-gong", 1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
  
        if( me->query_skill("mingyu-gong", 1) < 450 )
                return notify_fail("������񹦹���(450)���㡣 \n");

        if( me->query_skill("force", 1) < 450 )
                return notify_fail("����ڹ�(450)�����á� \n");
        
        if (me->query_skill_mapped("force") != "mingyu-gong") 
                return notify_fail("������û�м�������Ϊ�ڹ�������ʩչ�������������\n"); 
                
        if (me->query_skill_mapped("unarmed") != "mingyu-gong" && 
        		me->query_skill_mapped("sword") != "mingyu-gong") 
                return notify_fail("������û�м�������Ϊȭ�Ż򽣷�������ʩչ�������������\n");
                
        if(me->query("neili") < 3000)
                return notify_fail("�������������\n");
   
        if( target->is_busy() )
                return notify_fail(target->name() + "Ϊ�˶�����ɱ����Ŀǰ���Թ˲�Ͼ��\n");
        
        msg = HIC"$N���к�âһ��������ȫ�������뵤��,��ת���죬����ȫ�����Ѫ������\n \n" NOR;

        ap = me->query_skill("force") + me->query_skill("martial-cognize") ; 
        dp = target->query_skill("force") + target->query_skill("martial-cognize");
        
        if (ap / 2 + random(ap) > dp)  
        {
                msg += BLK HBWHT "$Nȫ����Ѫ��ӿ��Ѫ���ƣ�ʹ�������񹦵�����ɱ�� ���� �� �� �������������Ѫ��ΪѪ����������$n"BLK HBWHT"��ȫ���Ѩ����$n�ش�����\n \n \n" NOR;

                target->start_busy( random((int)me->query_skill("mingyu-gong") / 100 + 3) );
                target->receive_wound("jing", random(target->query("jing")/100), me);
                target->receive_wound("qi", random(target->query("qi")/100), me);
                me->receive_damage("qi", random(me->query("max_qi")/100));
                me->add("neili",-5000);  
        }
        else
        if( ski_value < 20 ){
                msg +="$N����������Ѫ����ǿ�󣬾��öԷ����ɶ����\n";
                me->receive_damage("qi", me->query("qi")*1/100);
                me->add("neili", -500); 
        }
        else if( ski_value <  70 )
        {
                msg += HIM "��һ�� ��ħ���޳���\n\n$n�ܵ��˺�,�������ã�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /120 + 1);
       					me->start_busy(3 + random(2));
                me->add("neili",-1000);    
        }
        else if( ski_value <  90 )
        {
                msg += HIG "�ڶ��� ����ħɷ��\n\n$n�ܵ��˺�,�������ã�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /110 + 1);
       					me->start_busy(3 + random(2));
 
                me->add("neili",-1000);    
        }
        else  if( ski_value < 100 )
        {
                msg += HIC "������ ���̻�ħ��\n\n$n�ܵ��˺�,�������á�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /100 + 1);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  120 )
        {
                msg += HIB "������ ����ħ������\n\n$n�ܵ��˺�,�������ã�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /95 + 1);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  140 )
        {
                msg += HIW "������ ����ħ�ƿա�\n\n$n�ܵ��˺�,�������ã�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /90 + 2);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  160 )
        {
                msg += CYN "������ ��Ⱥħ���衻\n\n$n�ܵ��˺�,�������ã�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /85 + 2);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  180 )
        {
                msg +=  YEL "������ ���켫ħɱ��\n\n$n�ܵ��˺�,�������ã�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /80 + 2);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  200 )
        {
                msg += BLU "�ڰ��� ����ħ�����꡻\n\n$n�ܵ��˺�,�������ã�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /75 + 2);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else                    
        {
                msg += RED "�ھ��� ����ħ��תҵ��\n\n$n�ܵ��˺�,�������á�\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /70 + 2);
       					me->start_busy(3 + random(2));
 
                me->add("neili",-1000);    
        }

        message_vision(msg, me, target);
        return 1;
}

