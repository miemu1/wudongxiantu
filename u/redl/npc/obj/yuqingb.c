// This program is a part of NITAN MudLIB 
// redl 2012/11/1 

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIB "������" NOR, ({"yuqing wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������裬��˵����֥ع���䵱����ɢ�ᴿ��������ǿ��ҩ��\n");
                set("base_unit", "��");
                set("base_value", 150000000);
                set("base_weight", 800);
                set("only_do_effect", 1);
                set("unit", "��");
        }
        setup();
}

int do_effect(object me)
{
                if( query("max_jingli", me)>=me->query_current_jingli_limit() )
                {
                        return notify_fail(YEL + "������ٳ�һ��..ֱ��ȴ�����㲻������ɶЧ����...\n" + NOR); 
                }
                
        message_vision(YEL "$N" YEL "����һ��" + name() +
                       YEL "����Ϣ��ת��С���죬�о�����������һЩ�仯��\n", me);

        addn("max_jingli", 6000+random(500), me);
        if( query("max_jingli", me)>me->query_current_jingli_limit() )
                set("max_jingli", me->query_current_jingli_limit(), me);
        // me->start_busy(3);
        add_amount(-1); 
        if (query_amount() < 1) 
                destruct(this_object()); 
        return 1;
}

