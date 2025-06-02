#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "��"ZJBR"����"; }

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        object *ob;
        int i, skill, damage;

        if(me->query("family/family_name")!="��ɽ��")
                return notify_fail("����ɽ�����á��򽣹��ڡ���\n");

        if( (int)me->query("neili") < 300 )        
             return notify_fail("������û���㹻������ʹ�á��򽣹��ڡ���\n");        
        if( (int)me->query("max_neili") < 2000 )
             return notify_fail("�㷨�������ۺ���ʹ�á��򽣹��ڡ���\n");       

        if ((int)me->query("jing") < 1000)
                return notify_fail("������û���㹻�ľ���ʹ�á��򽣹��ڡ���\n");

        if( (int)me->query_skill("xianfeng-spells", 1) < 500 )
                return notify_fail("����ɷ���������û�������򽣹��ڡ�ʹ��������\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        skill = me->query_skill("xianfeng-spells", 1);

        me->add("neili", -300);
        me->add("max_neili", -5);
        me->receive_damage("jing", 200);

        me->start_busy(2);
        message_vision(
   HIR "$Nʹ���ɷ��������ܴ��������򽣹��ڡ���\n"
       "ɲʱ����˷����������ص���\n"
       "����Բʮ��֮�ڶ�������������\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;

                damage = (int)me->query("int")*30;
                ob[i]->receive_damage("qi", damage);
                ob[i]->receive_damage("jing", damage / 2);
                tell_object(ob[i], "����û����ʹ���Ѿ������ٽ������ˡ�\n");
                if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);}

        me->start_busy(2+random(2));
        return 1;
}


