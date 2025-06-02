// This program is a part of NITAN MudLIB  
// redl 2015/10
#include <ansi.h>  
#include <room.h>  
inherit BUILD_ROOM; 

void create()
{
        set("short","����ɽ��703��");
        set("long", "�����ǲ���ɽ���ഫ����ɽ���˽�Ψһ�ܹ���������·����\n"
"ֻ��ϧ����ɽ���꺮�䣬����Ʈѩ���Ƿ�����������ͽ�������\n"
"�����з���Ϊ������һ���ֻ����ɽ����ȴδ�����䷵�硣\n");
        set("outdoors", "yangzhou");
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_magic", 1); 
        set("no_user_kill", 1); 
        set("no_sleep_room", 1);  
        set("exits",(["down":__DIR__"bzs_10","up":__DIR__"bzs_12"]));setup();
}

int do_look(string arg)
{
        object me = this_player();
        if ( arg && arg=="up" ) {
                        tell_object(me, NOR "������Ŀ������ȥ��ֻ������Ʈ�졣\n" NOR);
                        return -1;
        }
        return 0;
}

int valid_leave(object me, string dir)
{
                if (dir=="up") {
                        if ( file_size(query("exits/up") + ".c") < 1 )
                                return notify_fail(NOR "һ��������ֹ�㣺���Ǵ�ɽ�Ű���������\n" NOR);
                }
                
        return ::valid_leave(me, dir);
}

int init() 
{ 
        add_action("do_look", "look");
} 

