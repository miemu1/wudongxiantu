// yizhanxiaoer.c С��

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name("��վС��", ({"xiao er"}) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λС����Ц���������������ʱ�������������ڡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("no_get", "1");
        set("rank_info/respect", "С����");
        set("chat_chance", 1 );
        set("chat_msg", ({
                ( : command("say "+"��Ǯ����������ûǮ�������ȡ�") : ),
                ( : command("say "+"��Ǯ���Ǵ�ү��ûǮ���Ǵ�ү��") : ),
                ( : command("say "+"�۸�ƽ�����������ɾ�����") : ),
        }) );       
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{      
         object ob; 
        
        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) 
        {
           remove_call_out("greeting");
           call_out("greeting", 1, ob);
                
        }
        
        add_action("do_kill", "hit");          
        add_action("do_kill", "fight");          
        add_action("do_kill", "kill");          
}       

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( ob->query("age") < 15 ) ob->set_temp("paid_for" ,1);
                
        switch( random(2) ) 
        {
                case 0:
                        say( "С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����Ƕ�ȥ����\n");
                        break;
                case 1:
                        say( "С�����˿ڲ裬˵������λ" + RANK_D->query_respect(ob)
                                + "����;���У������Żݡ�\n");
                        break;
        }
}


int do_kill(string arg)
{    
            
        if ( arg == "xiao er" || arg == "xiaoer" )
        return 1;    
        return 0;    
}

int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 2000) 
        {
                tell_object(who, "С��һ������˵������л���ϣ������Ϲͳ���\n");

                who->set_temp("paid_for",1);

                return 1;
        }

        return 0;
}            

