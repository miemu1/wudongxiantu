// This program is a part of NITAN MudLIB 
// redl 2014/3
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
                set_name(NOR WHT "���G" NOR, ({ "penny", "gang beng" }));
                set("base_value", 10);
                set("long", NOR + WHT "����һöӲ�ң�������������(throwing penny)��\n" NOR);
                set("base_unit", "ö");
                set("base_weight", 100);
                set("unit", "��");
                set_amount(1);
                set("set_data", 1);
                set("auto_load", 1);
}

int do_exchange(string arg)
{
        object ob, me = this_player();
        string target = query("id", me);
        
        if (!arg || (arg!="penny" && arg!="gang beng")) {
                write(NOR "��Ҫ��ʲô������\n" NOR);
                return 1;
        }
        
        if(me->is_busy()) return notify_fail("����æ���ء�\n");

        me->start_busy(2);

        message_vision(NOR CYN "$N" NOR CYN "�����۾��ͳ�һö$n" NOR CYN "�������дʵ�������һ��...\n" NOR, me, this_object()); 
        if (random(3)) {
                if (MEMBER_D->is_member(target))
                        MEMBER_D->db_pay_member(target, 1);
                else
                        MEMBER_D->db_create_member(target, 1);
                write(NOR WHT "���G" NOR HIG "�����ϻ���1���䶯��;�ң�һ�����������¶��" NOR HIK "(��ʹ��memberָ�����) \n" NOR); 
                return 1;//�����٣����ؼ�������
        }

        message_vision(NOR CYN "$n" NOR CYN "Ʈ��Ʈ��Ʈ��Ʈ...\n����������Ҳû����$N" NOR CYN "һ�۵ط����ˡ�\n" NOR, me, this_object()); 
        add_amount(-1); 
        if (query_amount() < 1) 
                destruct(this_object()); 
        return 1;
}


void init()
{
            if (! interactive(this_player()))
                       return;
        add_action("do_exchange", "throwing");
}

