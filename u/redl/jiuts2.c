#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��ͷ�����");
        set("long",@LONG
���Ǿ�ͷ�ߵ���أ���Χ���ǳ�ʪ�����ʪ�أ��ֲ�֮����(scheme��research)
LONG);


        set("exits", ([
                "out"    : "/maze/jiutoushe/haitan",
                
        ]));

        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_user_kill", 1); 
        set("dongtianfudi", 999999); 

        set("sleep_room", 1); 

        setup();
}
