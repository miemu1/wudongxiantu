

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("老者", ({ "lao zhe","lao","zhe" }));
       // set("title", "好象很猛的");
		//set("title", HIY "剑客" NOR);
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
		//	return notify_fail("你回答过了\n");

	 if (arg = ""+daan+"")
	 {
		who->set("wenqingshibai",0);
            return notify_fail("你回答对\n");
	 }
	  
     //  message_vision(CYN"阿良说：“下次我看见陈平安那小子肯定揍他一顿，我回去咯，但我会每时每刻在你身边帮助$N的！”\n", this_player());
        command("haha"+ me->query("id"));
        command("great"+ me->query("id"));
        who->add_temp("shushan/answer_book_fairy",1);
        write(CYN"说罢，阿良消失得无影无踪！\n"NOR);
        message_vision("$N发现身上多了一本书。\n",this_player());
        ob = new("/d/shushan/zhenyaota/obj/fbook");
        ob->move(who);
        destruct(me);
        return 1;
}
