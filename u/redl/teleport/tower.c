// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 

void create()
{
        set("short", "����֮��");
        set("long", 
"���ǿ����������Ķ���������ģ���ĺ�Ӱ������ſ����������\n"
"Χ���ܽ��ϣ����ŵؿ���������������\n"
);
                set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "out" : __DIR__"teleport",
                ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        set("max_carry_user" ,3);
        set("max_carry_exit" ,"out");
        
        setup();
}



