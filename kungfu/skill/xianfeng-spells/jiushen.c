#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "酒神"; }

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        object *ob;
        int i, skill, damage;

        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("小娃娃，你的名字酒剑仙没有没有告知本座！\n");

        if(me->query("shushan/jiushen_cast")!=1)
                return notify_fail("你还没领会「酒神」！\n");    

        if ((int)me->query("jing") < 1000)
                return notify_fail("你现在神智不清，连MM都不认识，更别说是酒神了！\n");

       skill = me->query_skill("xianfeng-spells", 1);

       me->add("neili", -300);
       me->receive_damage("jing", 200);
       me->apply_condition("drunk", 0);
message_vision(HIR "\n$N忽然一张口，朝天喷出一口酒雾\n
只见酒雾中化出一个人形，凭空打出了一个惊雷，击向在场的每一个人！\n\n"NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;

                damage = skill + me->query("int")*100;
                ob[i]->receive_damage("qi", damage);
                ob[i]->receive_damage("jing", damage / 2);
                 tell_object(ob[i], "结果你被击个正着！\n");
                 if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);}

        me->receive_wound("jing", 10);
        me->start_busy(2+random(2));
        return 1;
}



