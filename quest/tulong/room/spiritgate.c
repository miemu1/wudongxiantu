#include <room.h>
inherit ROOM; 
#include <ansi.h>
int do_knock(string arg);
void create()
{
      set("short","忘忧园");
      set("long",@LONG
你处在一个植满茶花的花园里，虽然还不是开花的时节，但是
那些生机勃勃的茶树，不禁让你感到心神清爽。草丛里有些小虫子
正唧喁唧喁地叫得正欢。
LONG);
      set("exits",([ 
            "west"  : "/d/gaochang/road",
      ]));
      setup();
} 

void init()
{
        add_action("do_knock","knock");
}
int do_knock(string arg)
{ 
   object member;

   member = this_player()->query_team();
       if (!arg || arg != "spiritgate")
      {
            return notify_fail("你要敲什么？\n");
      }
     if( this_player()->query("combat_exp")<20000) return notify_fail("你这样的能力是进不了精灵界的。\n");
   if( sizeof(member) != 7 )
     return notify_fail(HIG"如果队中成员数目不是正好为十四之半，精灵之门不会开启。\n"NOR);
   message_vision( HIG "$N在虚空中轻轻扣动几下，一阵优美的乐声中，$N被送到了一个奇异的地方！\n" NOR, this_player());
message("channel:chat", HBMAG"【精灵神界】精灵之门开启，某小队进入了精灵神界，破解神龙的封印!\n"NOR,users());
            this_player()->move("/quest/tulong/room/spirit1"); 
            this_player()->set("fighter",0); 
            this_player()->set("mark/diary",0); 
          this_player()->set_temp("m_success/初级",0);  
          this_player()->set_temp("m_success/幻影",0);  
          this_player()->set_temp("m_success/孽龙",0);  
          this_player()->set_temp("m_success/琼草",0);  
   return 1;
}

