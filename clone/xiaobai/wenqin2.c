

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "lao zhe","lao","zhe" }));
       // set("title", "������͵�");
		//set("title", HIY "����" NOR);
        set("age", 300);
        set("attitude", "peaceful");
        set("str", 1000);
        set("per", 2000);
       
        set("max_qi", 10000);
        set("max_jing", 10000);
		


        setup();
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        object who = this_player();
        object me = this_object();
        object ob;
		string daan;
		daan = who->query("love",1);
     
	   
		//if(!arg=0||me->query("wenqingshibai",1))
		//	return notify_fail("��ش����\n");

	 if (arg = ""+daan+"")
	 {
		who->set("wenqingshibai",0);
            return notify_fail("��ش��\n");
	 }
	  
     //  message_vision(CYN"����˵�����´��ҿ�����ƽ����С�ӿ϶�����һ�٣��һ�ȥ�������һ�ÿʱÿ��������߰���$N�ģ���\n", this_player());
        command("haha"+ me->query("id"));
        command("great"+ me->query("id"));
        who->add_temp("shushan/answer_book_fairy",1);
        write(CYN"˵�գ�������ʧ����Ӱ���٣�\n"NOR);
        message_vision("$N�������϶���һ���顣\n",this_player());
        ob = new("/d/shushan/zhenyaota/obj/fbook");
        ob->move(who);
        destruct(me);
        return 1;
}
