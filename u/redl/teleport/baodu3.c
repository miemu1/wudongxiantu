// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 


void create()
{
        set("short", "����ɽ��");
        set("long", 
"������ʮ�������еı���ɽɽ�������������ľ�С·���ѣ�����\n"
"ȫ�ǻ��ɫ�ķ�Ҷ�֣�ֻ΢΢���ü���ˮ������������\n"
);
                set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "east" : __DIR__"baodu4",
                        "southdown" : __DIR__"baodu2",
                ]));

        //set("no_dazuo",1);
        //set("no_kill",1);
        //set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                //set("no_magic", 1); 
        set("no_sleep_room", 1); 
        set("no_get", 1);
        set("no_user_kill", 1);
//        set("max_carry_user" ,5);
//        set("max_carry_exit" ,"out");
        
        setup();
}




