#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIC"ɭ��ɽ��"NOR);
        set("long", @LONG
����ɭ���
LONG);
        
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("no_clean_up", 1);
        set("outdoors", "necropolis");
                set("exits", ([ /* sizeof() == 3 */ 
                "south" : "maze/forest/enter", 
				"east" : "maze/forest/unique_room/bearlair", 
                "west" : "maze/forest/unique_room/wolfcave", 
                "north" : "maze/forest/unique_room/tigerhill", 
        ])); 

        setup();
        // replace_program(ROOM);
}
