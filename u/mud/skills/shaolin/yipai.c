//banruo-zhang's perform yipai(һ����ɢ)
//mud@NT7 2015.02.15 

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string name() { return HIW "һ����ɢ" NOR; }

int perform(object me, object target)
{
        int damage;
        int max_neili,neili,jiali;
        int ap,dp;
        string msg;
        int lunhui,budd;

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("����δ������޷�ʩչ" + name() + "��\n");
       
        if( !objectp(target) ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) 
           || environment(target)!=environment(me))
                return notify_fail("һ����ɢ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");      


        if( (int)me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("��İ����ƻ���������������ʹ��һ����ɢ���жԵУ�\n");

        if( (int)me->query_skill("yijinjing", 1) < 180 )
                return notify_fail("����׽������������������ʹ��һ����ɢ���жԵУ�\n");
 
        if( (int)me->query_skill("strike", 1) < 180 )
                return notify_fail("����Ʒ�������죬ʹ���������Ƶľ��У�\n");
                
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á�һ����ɢ����\n");
                                
        if (me->query_skill_prepared("strike") != "banruo-zhang" ||
            me->query_skill_mapped("strike") != "banruo-zhang")
                return notify_fail("������Ƚ��������������Ʒ�֮�в��С�\n");

//        if (me->query_skill_mapped("parry") != "banruo-zhang")
//                return notify_fail("������Ƚ��������������м�֮�в��С�\n");
                                
        max_neili = me->query("max_neili");
        neili = me->query("neili");
        if( max_neili < 100000 )
                return notify_fail("��������Ϊ���㣬ʹ���������Ƶľ��У�\n");     
        if( neili < max_neili/10*9 )
                return notify_fail("�������������㣬ʹ���������Ƶľ��У�\n");     

        if( (int)me->query("jingli") < me->query("eff_jingli")/2 )
                return notify_fail("�����ھ������㣬ʹ���������Ƶľ��У�\n");   
                
        tell_object(me, RED"���עһ������ȫ��������һ��֮���ĳ���\n"NOR);
        me->start_busy(1+random(2));

        if(!target->is_busy())
                target->start_busy(1); 
      
        jiali = me->query("neili")/4;
        me->set_temp("brz_yipai", me->query("jiali")+1);
        me->set("jiali", jiali);      
                
        if(wizardp(me))  tell_object(me, "Jiali = "+jiali+"��");

        ap = attack_power(me,"strike");
                ap+= attack_power(me,"force");
                ap+= me->query_skill("buddhism",1);
                
                dp = defense_power(target,"parry");
                dp+= defense_power(target,"dodge");
                
                lunhui = me->query_skill("lunhui",1);
                budd = me->query_skill("buddhism",1);
                budd = budd/5000;
                if(budd<1) budd = 1;
                if(budd>6) budd = 12;
                ap = ap + ap * lunhui/1000;
                ap*= 2;
                
                damage = damage_power(me,"strike");
                damage+= damage_power(me,"force");
                damage+= me->query_skill("force-cognize",1);
                damage*= budd;
                
                message_combatd(sort_msg(HIY "\n$N" HIY "��ȵ���������һ�ƣ���˫����������ת�˸�ԲȦ��"
                         "������$n���˹�����\n$N����δ����$n�Ѹ��ؿں������������֮�䣬$N��������ŭ������ӿ������" NOR), me);

        if(ap/2+random(ap) > dp)
        {
            if(query("combat_exp",me) /2 + random( query("combat_exp",me)) > query("combat_exp",target))
            msg = COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 100 + lunhui/5, 
                              HIY"$n⧲�������������ɽ��������������ػ��У������ɢ��\n"NOR);       
            else
            msg = COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage/2, 100 + lunhui/5,
                  HIY"���������ཻ������������$N��$n������������$nһ����ֻ��ȫ�����������᲻����!\n"NOR);
        }
        else
        msg = CYN "$n" CYN "����һ������������һ�����Ǳ��ض�����С�\n" NOR;
        // cost all neili and half jingli.
        me->set("neili", max_neili/2);
        me->set("jiali", me->query_temp("brz_yipai")-1);
        me->delete_temp("brz_yipai");
        me->set("jingli", me->query("eff_jingli")/5);
        
        message_combatd(msg, me, target);
            me->stary_busy(1+random(2));
        if(!target->is_killing(me->query("id"))) target->kill_ob(me); // hehehehehehe.....
        return 1;
}


