//【蜀山剑派】dhxy-evil 2000.7.5
// modified by vikee
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("阿良", ({ "baifa laotou","fairy","laotou" }));
        set("title", "好象很猛的");
		set("title", HIY "剑客" NOR);
        set("age", 300);
        set("attitude", "peaceful");
        set("str", 100);
        set("per", 20);
       
        set("max_qi", 100);
        set("max_jing", 100);
		


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
        if (!arg || (arg != "丧尽天良的良" && arg != "善良的良"))
                return notify_fail("你要回答什么？\n");

        message_vision(CYN"阿良说：“下次我看见陈平安那小子肯定揍他一顿，我回去咯，但我会每时每刻在你身边帮助$N的！”\n", this_player());
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
