// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit ROOM; 


void create()
{
        set("short", "���"); 
        set("long", HIG "����һ�������ķ��䡣\n" NOR);

        set("exits", ([ /* sizeof() == 1 */
                "east" : "/data/room/redl/dadian",
        ]));

        set("no_rideto", 1);
        set("no_flyto", 1);
        setup();
}



