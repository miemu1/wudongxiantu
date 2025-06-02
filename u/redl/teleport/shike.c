// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 


void create()
{
        set("short", "ʯ��ɽ");
        set("long", 
"������ʮ���������ʯ��ɽ����ɽ��Ұ�Ĵ�Сʯͷ���������ż\n"
"����һЩʯ�촦�����ü������п�����΢΢������ɫ�ڻƲ��塣\n"
);
                //set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "out" : __DIR__"teleport",
                ]));
                set("objects", ([ 
                        __DIR__"/npc/tie" : 1, 
                        __DIR__"/npc/shi" : 2, 
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
        set("max_carry_user" ,5);
        set("max_carry_exit" ,"out");
    set("no_protect", 1);
        
        setup();
}

int discmds() 
{ 
        tell_object(this_player(), "�㲻��������ë��ë�ŵ�������\n");  
        return 1;  
} 

int init() 
{ 
        object me = this_player();
        if (!interactive(me) || !playerp(me)) return 1;
        if ( wiz_level(me) > 5 ) return 1;

        add_action("discmds", ({  
                "steal", "cast", "conjure", "array", "fight",    
                "quit", "exit", "recall", "kill", "ansuan", "touxi", 
                "surrender", "team", "chatroom", "rideto",
        }));  
        return 1;
} 




