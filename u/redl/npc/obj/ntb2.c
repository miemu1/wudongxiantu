// This program is a part of NITAN MudLIB 
// redl 2013/8
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        int d = (time() - 1392799000) / 864000; //ÿ10����ֵ1nt
        set_name(NOR BBLU HIW "�䶯��;�����Ʊ" NOR, ({ "ntb" }));
        //������ֵ25nt����Ϊ�̵����Ϊ50nt(�����������������ۼ�35nt)��һ������25+36=61nt
                set("base_value", d+25);
                set("long", NOR + WHT "���Ƿ������䶯��;����ʱ�Ĺ�Ʊ��Ŀǰ����(exchange)�һ���" + (string)(query("base_value")) + "���䶯��;�ҡ�\n" NOR);
                set("base_unit", "��");
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
        int d = query("base_value");
        
        if(me->is_busy()) return notify_fail("����æ�ţ�û�նһ��䶯��;�ҡ�\n");
        me->start_busy(2);

        //30����׼��һ�
        if (time() < (1392799000 + 86400 * 30)) return notify_fail("���ֹ�Ʊ��û�е��һ��ڣ��ٵȵȰɡ�\n");
        
//        if (! objectp(ob = UPDATE_D->global_find_player(target)))
//            return notify_fail("û������ˣ�\n");

 if (d > 50) d = 50;


        if (MEMBER_D->is_member(target))
                MEMBER_D->db_pay_member(target, d);
        else
                MEMBER_D->db_create_member(target, d);

        log_file("static/yangyong2",sprintf("%s %s �䶯��;�����->? $NT, �˻��� %d $NT\n",TIME_D->replace_ctime(time()), target, MEMBER_D->db_query_member(me, "money"))); 


        CHANNEL_D->channel_broadcast("chat", ( NOR + HIC + query("name", me) + NOR + HIC + "�һ��䶯��;����ɻ��" + chinese_number(d) + NOR + HIC + "���䶯��;�ҡ�\n" + NOR )); 
//      write("�һ�ok\n");


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


