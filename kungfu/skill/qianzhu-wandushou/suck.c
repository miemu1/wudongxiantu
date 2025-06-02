#include <ansi.h>
inherit F_SSERVER;

string name() { return "����"; }
string query_name() { return "ǧ��"ZJBR"����"; }
int perform(object me,object target)
{
        int sp, dp, temp;
        int my_skill, my_force, tg_age, skill_count, duli;

        if( environment(me)->query("no_fight") )
                return notify_fail("����̫���ӣ��㲻�ܾ�������������\n");

        if( !objectp(target)
         || target->query("host_id") != me->query("id") )
                return notify_fail("��Ҫ��ȡʲô����Ķ��أ�\n");

        if( target->query("age")<99 )
                return notify_fail("�㿴����㣬�Ƕ������Ƕ�����\n");

        my_skill = (int)me->query_skill("qianzhu-wandushou", 1);
        my_force = (int)me->query_skill("xiuluo-yinshagong", 1);
        tg_age=target->query("age");

        if( my_skill < 100 )
                return notify_fail("���ǧ�����ֻ��̫ǳ������������ȡ���أ�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ�������ǧ�����֣�\n");

        if( me->is_fighting() )
                return notify_fail("ս�����޷�����ǧ�����֣�\n");

        if( me->is_busy() )
                return notify_fail("����æ���أ�\n");

        if( target->is_fighting() || target->is_busy() )
                return notify_fail("������æ���أ����ܺ�����ϣ�\n");

        if( me->query_temp("wudu_suck") )
                return notify_fail("�����������У�\n");

        if (! me->can_improve_skill("qianzhu-wandushou"))
                return notify_fail("���ʵս��Ϊ�������޷���������ǧ�����֣�\n");

        if( my_skill < 130 && tg_age > 99 )
                return notify_fail(target->query("name")+"�Ķ���������˵̫ǿ�ˣ�С�İ�С�����ˣ�\n");

        if( my_skill < 160 && tg_age > 999 )
                return notify_fail(target->query("name")+"�Ķ���������˵̫ǿ�ˣ�С�İ�С�����ˣ�\n");

        if( my_skill > 140 && my_skill < 170 && tg_age < 999 )
                return notify_fail(target->query("name")+"�Ķ���������˵�Ѿ�̫��΢�ˣ�\n");

        if( my_skill > 200 && tg_age < 9999 )
                return notify_fail(target->query("name")+"�Ķ���������˵�Ѿ�̫��΢�ˣ�\n");

        if( me->query("neili")<200 )
                return notify_fail("������������������ԶԿ����������С���͵���\n");

        if( target->query("qi")<50 )
                return notify_fail(target->query("name")+"�Ѿ�����һϢ�ˣ���"
                                    "�޷�����������ȡ�κζ��أ�\n");

        if( me->query("qi")<200 )
                return notify_fail( "��첻���ˣ������������ģ�\n");

        tell_object(me,RED"��С������Ľ����쵽"+target->query("name")+
                        RED "����ǰ���������ҧס�������ָ��������һ��\n����"
                        "���϶�ʱ����һ�ɺ���������ĺ���Ӷ�ͷ������������ֻ"
                        "����"+target->query("name")+RED"��\n�������˴�"
                        "ԴԴ���������˽������������鲼ȫ��\n\n" NOR );

        target->receive_wound("qi", 5);

        if( tg_age < 999 )
        {
                duli = 3;
        }

        if( tg_age > 999 && tg_age < 9999)
        {
                duli = 5;
        }

        if( tg_age > 9999 )
        {
                duli = 7;
        }

        skill_count = duli * (10 + random((int)me->query_int()));
        me->improve_skill("qianzhu-wandushou", skill_count);
        me->improve_skill("poison", skill_count * 2 / 3);
        tell_object(me, HIC "��ġ�ǧ�����֡��͡����������������ˣ�\n" NOR);

        me->set_temp("wudu_suck", 1);
        call_out("del_wudusuck", 3, me, target);
/*
        switch( random(duli) )
        {
        case 0:
                temp=query("combat_exp", me);
                addn("combat_exp", temp/1000, target);

                if( query("combat_exp", target)>(temp*12/10) )
                            set("combat_exp", temp*12/10, target);
                else
                    tell_object(me,HIC+query("name", target)+NOR+HIC"����Ϊ��ߵ�"+
                        chinese_number(query("combat_exp", target))+"�㡣\n"NOR);
                break;

        case 1:
                addn_temp("apply/attack", 1, target);

                if( query_temp("apply/attack", target)>300 )
                            set_temp("apply/attack", 300, target);
                else
                    tell_object(me,HIC+query("name", target)+NOR+HIC"�Ĺ�������ߵ�"+
                        chinese_number(query_temp("apply/attack", target))+"�㡣\n"NOR);
                break;

        case 2:
                addn_temp("apply/defense", 1, target);

                if( query_temp("apply/defense", target)>300 )
                            set_temp("apply/defense", 300, target);
                else
                    tell_object(me,HIC+query("name", target)+NOR+HIC"�ķ�������ߵ�"+
                        chinese_number(query_temp("apply/defense", target))+"�㡣\n"NOR);
               break;

        case 3:
                addn_temp("apply/armor", 1, target);

                if( query_temp("apply/armor", target)>1500 )
                            set_temp("apply/armor", 1500, target);
                else
                    tell_object(me,HIC+query("name", target)+NOR+HIC"�Ŀ����������ߵ�"+
                        chinese_number(query_temp("apply/armor", target))+"�㡣\n"NOR);
                break;

        case 4:
                addn("max_qi", 10, target);

                if( query("max_qi", target)>20000 )
                            set("max_qi", 20000, target);
                else
                    tell_object(me,HIC+query("name", target)+NOR+HIC"����������ߵ�"+
                        chinese_number(query("max_qi", target))+"�㡣\n"NOR);
                break;

        case 5:
                addn("max_jing", 10, target);

                if( query("max_jing", target)>20000 )
                            set("max_jing", 20000, target);
                else
                    tell_object(me,HIC+query("name", target)+NOR+HIC"�ľ���ߵ�"+
                        chinese_number(query("max_jing", target))+"�㡣\n"NOR);
                break;

        case 6:
                temp = (int)target->query_skill("dodge", 1);

                target->set_skill("dodge",temp+1);
                if((int)target->query_skill("dodge",1)>300)
                            target->set_skill("dodge",300);
                else
                    tell_object(me,HIC+query("name", target)+NOR+HIC"�Ķ���������ߵ�"+
                        chinese_number((int)target->query_skill("dodge", 1)) +"����\n"NOR );
        }
*/
        return 1;
}

void del_wudusuck(object me,object target)
{
        if( me->query_temp("wudu_suck") )
        {
                me->delete_temp("wudu_suck");
                tell_object(me, RED "\nֻ�����Ķ���Խ��Խ�󣬡���ડ�һ������"
                                "���ڵ����˵��ϡ�"+target->query("name")+RED
                                "��������\nѪ������͸��һ�㱦�⣬���Ӷ�ʱ�Ǵ�"
                                "����࣡\n\n\n" NOR,);
                me->receive_damage("qi", 20);
        }

        target->set_temp("nopoison", 0);
}