#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "����"; }

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        object *ob;
        int i, skill, damage;

        if(me->query("family/family_name")!="��ɽ��")
                return notify_fail("С���ޣ�������־ƽ���û��û�и�֪������\n");

        if(me->query("shushan/jiushen_cast")!=1)
                return notify_fail("�㻹û��ᡸ���񡹣�\n");    

        if ((int)me->query("jing") < 1000)
                return notify_fail("���������ǲ��壬��MM������ʶ������˵�Ǿ����ˣ�\n");

       skill = me->query_skill("xianfeng-spells", 1);

       me->add("neili", -300);
       me->receive_damage("jing", 200);
       me->apply_condition("drunk", 0);
message_vision(HIR "\n$N��Ȼһ�ſڣ��������һ�ھ���\n
ֻ�������л���һ�����Σ�ƾ�մ����һ�����ף������ڳ���ÿһ���ˣ�\n\n"NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;

                damage = skill + me->query("int")*100;
                ob[i]->receive_damage("qi", damage);
                ob[i]->receive_damage("jing", damage / 2);
                 tell_object(ob[i], "����㱻�������ţ�\n");
                 if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);}

        me->receive_wound("jing", 10);
        me->start_busy(2+random(2));
        return 1;
}



