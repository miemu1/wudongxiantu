// waiter.c

inherit KNOWER; 
inherit F_VENDOR;
#include <ansi.h>;

void create()
{
        set_name("��С��", ({ "tang xiaoer", "tang", "waiter", "xiao er" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
                "/clone/weapon/dagger",
                "/clone/food/jiudai",
                "/clone/food/baozi",
                "/clone/food/jitui",
        }) );
        setup();
}

void init()
{       
        object ob;
        mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) 
        {
                myfam = (mapping)ob->query("family");
                if ( myfam && myfam["family_name"]== "��������")
                {
                        remove_call_out("saying");
                        call_out("saying",1,ob);
                }
        
                remove_call_out("welcoming");
                call_out("welcoming", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void welcoming(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
                
        switch( random(2) ) 
        {
                case 0:
                        say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        tell_object(ob,"��С��Ц�����˵������λ"+RANK_D->query_respect(ob)+"����ӭ����"GRN"���ſ͵�"NOR"\n\n");
        ob->set_temp("rent_paid",1);
                
}

int accept_object(object who, object ob)
{
                
        if (ob->query("money_id") && ob->value() >= 5000) 
        {
                tell_object(who, "��С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");

                who->set_temp("rent_paid",1);

                return 1;
        }

        return 0;
}


