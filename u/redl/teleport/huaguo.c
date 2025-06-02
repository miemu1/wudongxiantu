// This program is a part of NITAN MudLIB  
// redl 2014/8
#include <ansi.h>  
#include <room.h>  
inherit "/u/redl/teleport/normal.c";  

void create()
{
        set("short","ˮ����");
        set("long", @LONG
�������ٲ�����ڸ��Ŷ��ţ�����һ����ʯ�ߡ��鴰���ң�����
����������������йң��ӻ��������⡣������´�𼣣�ʯ��ʯ��
��ɰ���ʯ��ʯ������䡣�ּ���һ�����������������÷������
������һʯ�١����Ͽ���������š�����ɽ���أ�ˮ�������족��        
LONG );
        set("outdoors", "yangzhou");
        set("exits",([ /* sizeof() == 1 */
            "out"  : "/u/redl/teleport/teleport",
        ]));

        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_protect", 1); 
        set("no_fly", 1);
        set("no_sleep_room", 1); 
        set("no_magic", 1); 

        set("no_user_yanjiu",1);
        set("no_user_kill", 1); 
        set("max_carry_user" ,99);
        set("max_carry_exit" ,"out");

        setup();
}

int valid_leave(object me, string dir)
{
        if (!interactive(me) || !playerp(me)) return 0;
        return ::valid_leave(me, dir);
}
