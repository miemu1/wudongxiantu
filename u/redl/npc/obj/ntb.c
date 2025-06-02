// This program is a part of NITAN MudLIB 
// redl 2013/8
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(YEL"��Ԫ�䶯��;��"NOR, ({ "ntb" }));
                set("long", NOR + WHT "����һ�Ű�Ԫ�󳮣�ʹ��(exchange)���һ���100�䶯��;�ҡ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 10000000000);
                set("base_weight", 3600);
                set("unit", "��");
        set_amount(1);
                                     set("set_data", 1);
                                     set("auto_load", 1);
}

int do_exchange()
{
        object ob, me = this_player();
        string target = query("id", me);
        
        if(me->is_busy()) return notify_fail("����æ�ţ�û�նһ��䶯��;�ҡ�\n");
        me->start_busy(2);
        
//        if (! objectp(ob = UPDATE_D->global_find_player(target)))
//            return notify_fail("û������ˣ�\n");

        if (MEMBER_D->is_member(target))
                MEMBER_D->db_pay_member(target, 100);
        else
                MEMBER_D->db_create_member(target, 100);

        log_file("static/yangyong2",sprintf("%s %s ��Ԫ�䶯��;��->100 $NT, �˻��� %d $NT\n",TIME_D->replace_ctime(time()), target, MEMBER_D->db_query_member(me, "money"))); 

//         UPDATE_D->global_destruct_player(ob, 1);
        
        add_amount(-1); 
        if (query_amount() < 1) 
                destruct(this_object()); 
        return 1;
}


void init()
{
                if (! interactive(this_player()))
                        return;
        add_action("do_exchange", "exchange");
}



