// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "ľ����");
        set("long", 
"���Ǽ俴��ȥʮ�����ʵĴ����ӣ����ڹ��ӵļҾ��ǡ���ĳ��裬��\n"
"���������Ҹ�������ĺۼ��������Ĵ�����ֻ����Ƭ��Ҷ�ɹ������ź�ѻ\n"
"���ݶ��⴫���ɰ���һ����̾��\n"
);
         set("exits",([ /* sizeof() == 1 */
                 "out" : __DIR__"lakehouse",
         ]));

        set("objects", ([
//                "/u/redl/obj/mbox" : 1,
        ]));

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);

                set("no_rideto", 1);
                set("no_flyto", 1);
        
        setup();
}

void init()
{
        object me = this_player();
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" )
        {
                        message_vision(YEL "һ��΢�紵������$N���������⡣\n" NOR, me);
                        me->move(__DIR__"lakehouse");
                        return;
        }
}




