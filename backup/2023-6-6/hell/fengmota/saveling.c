//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;                                                        
#include <ansi.h>                                                                     
void create ()                                                       
{                                                                    
  set ("short", "巨柱下");                                   
  set ("long", @LONG                                                 
一根盘龙巨柱矗立在你的面前，你沿着龙纹向上看，你惊讶地发现，
好象有个些什么，不，是一女孩(girl)被铁链捆在巨柱上，最好救救(jiu)她。                                           
LONG);                                                          
set("item_desc", ([
                "girl": @TEXT
你看清楚，她是带着泪的半蛇女，你看到她的可怜样，是否会考虑救？
TEXT        ]) );                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "south" : __DIR__"pole",                                      
]));                                                                                                                          
// set("no_fight",1);
        set("no_magic",1);
  setup();                                                           
}

void init()
{
        add_action("do_jiu", "jiu");
}

int do_jiu(string arg)
{
        object room, ob;
        object me = this_player();

        if (query("exits/down"))
                return notify_fail("大门已经是破了。\n");

        if (!arg || (arg != "girl"))
                return notify_fail("你要救谁？\n");

        if(!( room = find_object(__DIR__"hole1")) )
                room = load_object(__DIR__"hole1");
        if(objectp(room))
        {
                set("exits/down", __DIR__"hole1");
                message_vision("$N把女孩救了下来！\n", this_player());
                write(CYN"女孩道：“谢谢你救了我，我叫赵灵儿，但你只是救了我下来，这样我们还是出不去！”\n");
                write("塔灵突然出现在一阵烟雾之中。\n");
                write("塔灵道：“哈哈，这里几百年来从没有生物能成功逃离，我看你们还是省点力把。”\n");
                write("不知那里传来书中仙的声音：“那到未必，只要有人能打倒守塔柱的七条龙，柱在哪里，看看脚下吧！”\n");
                write(HIR"灵儿道：“太好了！我又有机会见道逍遥哥哥啦！七条龙的事就拜托了！请你答应(daying)我！”\n"NOR);
                write("塔灵：“那我回去通知大家，准备离开！”\n");
                write("塔灵突然消失在一阵烟雾之中。\n"NOR);
                ob = new("/data/hell/fengmota/npc/linger");              
                ob->move("/data/hell/fengmota/saveling");
                me->set_temp("shushan/linger_saver_1",1);
                room->set("exits/up", __FILE__);
                
        }

        return 1;
}
