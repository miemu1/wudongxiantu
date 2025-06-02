#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload()
{
        return query_amount() + "";
}

void create()
{
        set_name(HIY "��ҩ" NOR, ({ "pill" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "����һ�������ڹ��Ĳ�ҩ��\n" NOR);
                set("base_unit", "��");
                set("base_value", 10000);
                set("base_weight", 50);
                set("only_do_effect", 1);

                // ���Ӽ��ܵ�����
                set("pill_skill", "force");

                // �Ƿ�Ϊ�����书
                set("skill_mapped", 1);

                // ���ܵ�����Ч��
                set("pill_point", 20000);

                // ����������Ч��
                set("force_point", 3);

                // ���óɹ�������
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵����"
                                 "��������á�\n" NOR);

                // ����ʧ�ܵ�����
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ���"
                                 "��ȫ�Ĳ��䡣\n" NOR);

                // ���ӹ����������������ǰ��������Ϣ����Ӧ��ȱʡ
                set("pill_msg3", HIM "��е��������ۺ���һЩ��\n" NOR);
                set("pill_msg4", HIR "��е���Ϣ���ȣ���������ҩ����\n" NOR);
        }
        setup();
}

int do_effect(object me)
{
        string skill;
        int pot1, pot2, time;
        mapping my = me->query_entire_dbase();

        pot1 = query("pill_point");
        pot2 = query("force_point");
        time = query("pill_point") / 10;

        // �Ǽ����͵�ҩ�����¼���Ч��ʱ��
        if (! query("pill_point"))
                time = 400 + query("force_point") * 10;

        // ����֪ʶ������ҩ������ҩ��Ч��
        if( query("special_skill/herb", me) || query("special_skill/yaowang", me) )
        {
                pot1 += pot1 / 2;
                pot2 += pot2 / 2;
                time -= time / 2;
        }
        
        // ����ҩ��������Ч��10%
        if( query("special_skill/yaowang", me) )
        {
                pot1 += pot1 / 10;
                pot2 += pot2 / 10;
                time -= time / 10;
        }       

        if ((int)me->query_condition("pill_drug") > 0)
        {
                write("�����������Ϣδ���������������ܸе�����"
                      "�嵴������óȻ��ʳ��\n");
                return 1;
        }
        
        // δ1ת����ҽ���Ϊ25%
        if( !query("scborn/ok", me))time=time/4;
        // һת����δ��ת����ҽ���Ϊ40%
        if( query("scborn/ok", me) && !query("thborn/ok", me))time=time*2/5;


        // vip��Ч��
        switch(me->query_viplevel())
        {
        case 1:
                time = time - time / 10;
        break;
        case 2:
                time = time - time * 2 / 10;
        break;
        case 3:
                time = time - time * 3 / 10;
        break;
        case 4:
                time = time - time * 4 / 10;
        break;
        case 5:
                time = time - time * 5 / 10;
        break;
        case 6:
                time = time - time * 6 / 10;
        break;  
        case 7:
                time = time - time * 7 / 10;
        break;                  
        }

        if (time < 10)time = 10;
        
        // ����ҩ��Ч��ʱ�䣬��ʱ���ﲻ���ٴη���
        me->apply_condition("pill_drug", time);

        message_vision(HIY "$N" HIY "����һ" + query("base_unit") +
                       name() + HIY "����æ��ʼ�˹�����ҩ����\n"
                       NOR, me);

        // �����ҩ�������Ӽ��ܵĹ��ܣ����֮
        if (query("pill_skill") && query("pill_point"))
        {
                // �ж����ӵļ����Ƿ�Ϊ���⼼��
                if (query("skill_mapped") >= 1)
                        skill = me->query_skill_mapped(query("pill_skill"));
                else
                        skill = query("pill_skill");

                // �������Ӹü���
                if (stringp(skill) && me->can_improve_skill(skill))
                {
                        tell_object(me, query("pill_msg1"));
                        me->improve_skill(skill, pot1);
                } else
                        tell_object(me, query("pill_msg2"));
        }


        // �����ҩ�������ӹ����Ĺ��ܣ����֮
        if (query("pill_skill") && query("force_point"))
        {
                // �ڹ���ҩ���������������������Ӿ���
                if (query("pill_skill") == "force")
                {
                        // �ṩ����Ϣ
                        if( query("max_neili", me)<me->query_neili_limit( )
                           && query("pill_msg3"))
                                tell_object(me, query("pill_msg3"));
                        else
                        if( query("max_neili", me) >= me->query_neili_limit( )
                           && query("pill_msg4"))
                                tell_object(me, query("pill_msg4"));

                        me->improve_neili(pot2 + random(pot2));

                        if( query("neili", me)<query("max_neili", me) )
                                my["neili"]  = my["max_neili"];
                } else
                {
                        // �ṩ����Ϣ
                        if( query("max_jingli", me)<me->query_jingli_limit( )
                           && query("pill_msg3"))
                                tell_object(me, query("pill_msg3"));
                        else
                        if( query("max_jingli", me) >= me->query_jingli_limit( )
                           && query("pill_msg4"))
                                tell_object(me, query("pill_msg4"));

                        me->improve_jingli(pot2 + random(pot2));

                        if( query("jingli", me)<query("max_jingli", me) )
                                my["jingli"]  = my["max_jingli"];
                }
        }
        me->start_busy(random(3) + 3);

        add_amount(-1);
        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}

void autoload(string param)
{
        int amt;

        if (sscanf(param, "%d", amt) == 1)
                set_amount(amt);
}

void setup()
{
        set_amount(1);
        ::setup();
}
