// xiaoer2.c �Ƶ�С��

inherit KNOWER;
inherit F_DEALER;
#include <ansi.h>;
mixed do_ask(string arg);

void create()
{
        set_name("��Сһ", ({ "tang xiaoyi", "tang", "xiaoyi" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��Сһ��Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("no_get", "1");
        set("rank_info/respect", "Сһ��");
        set("vendor_goods", ({
                "/clone/food/jiudai",
                "/clone/food/meat",
                "/clone/food/peanut",
        }));
      /*  set("inquiry", ([ 
              "tangfei"   : (: do_ask :), 
        ])); */
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

        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_ask", "wen");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) 
        {
                case 0:
                        say( "��СһЦ�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "��Сһ�ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say ("��λ�͹٣���ʲô�µĻ�������С��һ����С�����Ͼ͵���\n");
                        break;        
        }
}
/*
mixed do_ask(string arg)
{    
        object me;
        mapping myfam;
        
        me=this_player();
        myfam=(mapping)me->query("family");
        
        // say(HIC"�����������㾡���ʰɣ�\n"NOR);
                
        if ( me->query_temp("yiwen"))
                return "�㷳��������������˵���ˣ��㻹�����ң�������ʲô����֪����! \n";
         
        if ( !myfam || myfam["family_name"] != "��������")
                return "��λ"+RANK_D->query_respect(me)+"�����뱾�������������˻��Ӻ�̸��\n";
        
        if ( myfam["family_name"]=="��������")
        {      
                me->set_temp("yiwen", 1);
                switch( random(2) )
                {
                   case 0:
                        tell_object(me, HIG"ԭ�����Լ��˰�������¥�����ϰ����û����ˣ�\n"NOR);
                        me->move("/d/tangmen/jiulou2");
                        me->set_temp("askxiao", 1);
                        break;
                   case 1:
                        tell_object(me, HIR"���ɰ������ϰ����ó����ˣ����һ�������ɣ�\n"NOR);
                        break;
                 }            
                        
        }
          
        me->set_temp("yiwen", 1);
        return "��֪��λ"+RANK_D->query_respect(me)+"���Ҽ��ϰ���ʲô��! \n";
}

*/