// This program is a part of NITAN MudLIB 
// redl 2015/2
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "��������");
        set("long", 
"�����������ž��£�����С������һ�����ĸ��ӣ������Ÿ���ȥ����һ\n"
"�����ĸ������涼��һ�������Ļ������̹ſ��죬������֮ս����������\n"
"�ⳤ��֮�ϣ�Ҳ�ܸ����Ϲ�֮ս�ĵ��������\n"
);
                set("exits",([ /* sizeof() == 1 */
                                "down" : "/u/redl/teleport/teleport",
                        "east" : "/u/lonely/workroom",
                          "south" : "/u/mud/workroom", 
                        "northwest" : __DIR__"workroom",
                ]));

      /*  set("no_fight",1);         
        set("no_steal",1);
        set("no_beg",1);         
        set("no_flyto", 1);*/
        set("no_drift", 1);
        setup();
}

int discmds() 
{ 
        tell_object(this_player(), "�㲻�������������������\n");  
        return -1;  
} 


void init()
{
        object me = this_player();
        
                        if (wiz_level(me) < 2) 
                                add_action("discmds", ({  
                                        "ride", "stab", /*"save", "ansuan", "touxi", 
                                        "steal", "cast", "conjure", "array", "fight", "hit",   
                                        "surrender", "exert", "team",  
                                        "array", "battle", "accept", "swear",*/
                        }));  
                

}

int valid_leave(object me, string dir)
{
        object room, *inv;
        int countp;
        
        if (wiz_level(me) < 2 && dir!="down") 
                {
                        tell_object(me, NOR "�ǲ�������Խ�ȥ�ĵط���\n" NOR);  
                        return -1;      
                }
        
        return ::valid_leave(me, dir);
}

