//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIR"奇怪的书"NOR, ({"fbook"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "一本奇怪的书，你忍不住想打开看一下。\n");
                set("value", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
  add_action("do_open", "open");
}

int do_open(string arg)
{
  object me = this_player();
  object ob;

  if (arg!="book")   return 0;
        if(me->query_temp("shushan/open_book",1))
        return 0;
  ob = new("/data/hell/fengmota/npc/b_fairy");
        ob->move(environment(me));
        message_vision(CYN"$N翻开那本奇怪的书，忽然发现面前出现了一位佩剑的侠客。\n",me);  
        write("陈平安道：“是谁打扰我练剑？”\n");
        write("陈平安道：“原来是个小鬼，回答我个问题我就不计较了，我的良是什么(answer)良？”\n"NOR);
        me->set_temp("shushan/open_book",1);
        destruct(this_object());
        return 1;
}


