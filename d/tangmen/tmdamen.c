//tmdamen.c

inherit ROOM;
#include <ansi.h>;

int do_qu(string arg);
string look_bian();

void create()
{
        set("short","蜀中唐门");
        set("long",
"一座宏伟建筑，一堵里许长的红墙，一个镏金的大匾(bian)。好大的\n"
"气派，一股敬意油然而生，这就是蜀中唐门的门楼了。但这里冷冷清清的，\n"
"好象没有多少人来过这里。也许是唐门人不在江湖走动的原因吧。门口站\n"
"着几个唐门的弟子。\n"
);
        set("outdoors", "蜀中");
        set("item_desc", ([
             "bian"  : (: look_bian :),
            ])); 
        set("exits", ([ 
            "enter"    : __DIR__"qianyuan",
            "southeast"    : __DIR__"gudao2",
        ]));
        set("objects", ([
            __DIR__"npc/tanggang" : 1,
            __DIR__"npc/dizi" : 2,
        ]));    
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_qu","qu");
}
        
string look_bian()
{
        object me;
        me = this_player();
        
        
        if ( me->query("tangmen/yanli") > 99 && !me->query_temp("dongdong") )
        {
               
              me->set_temp("dongdong",1);
              return HIC"匾后面好象有一个东西! 你可以取下来看看。\n"NOR;
        }
        
        return "四个镏金大字："+HIY"蜀 中 唐 门 \n"NOR;
                  
}

int do_qu(string arg)
{
        object me,ob;
        
        me = this_player();
        
        if ( !me->query_temp("dongdong") ) return 0;
        
        if ( me->query_temp("qudong") ) 
               return notify_fail(HIR"心不要太黑啊！\n"NOR);
        
        if ( !arg || arg != "dongxi")
               return notify_fail("你想取什么啊！\n");
               
        if ( me->query_skill("dodge") < 120 )
               return notify_fail(HIR"你的身手太差了！\n"NOR);
               
        me->delete_temp("dongdong");
        ob = new("/kungfu/class/tangmen/obj/jie");
        tell_object(me,HIG"你得到了一件暗器。\n"NOR);
        me->set_temp("qudong", 1);
        ob->move(me);
        return 1;
}
/*
int valid_leave(object me, string dir)
{
        object guarder;

        if (! objectp(guarder = present("tang gan", this_object())))
                return 1;

        if (dir == "enter")
                return guarder->permit_pass(me, dir);

        return 1;
}
*/

int valid_leave(object me, string dir)
{

        if ( dir == "enter" && objectp(present("tang gang", environment(me))))
        {
                if ( !me->query("family") )
                {
                        return notify_fail( "这位"+RANK_D->query_respect(me)+"要学艺的话到镇上找唐柔？\n");
                }
               // if ( me->query("family/family_name") != "唐门世家" )
              //  {
                  //      return notify_fail( "这位"+RANK_D->query_respect(me)+"，你已是武林中人，不知到此有何干！\n");  
              //  }    
                if ( me->query("tangmen/upshan") )
                {
                        if ( me->query("betrayer") )
                        {
                                tell_object(me,"唐刚说道：“你这个可耻的家伙！”\n");
                                return 0;
                        }
                        else 
                        {
                                tell_object(me,"唐刚说道：进去吧！\n");
                                me->move("/d/tangmen/qianyuan");
                                return 1;
                        }
                }                       
                else  return me->move("/d/tangmen/qianyuan");
        }// else 
       // if ( dir == "enter" )
     //  {
         //       if ( !me->query("family") || me->query("family/family_name") != "唐门世家" ||
         //            !me->query("tangmen/upshan"))
         //               return notify_fail("你一抬足，发现地上有毒，忙抽腿退回。\n");                        
    //   }               
        return ::valid_leave(me, dir);
}

