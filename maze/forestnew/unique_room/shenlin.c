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
                "south" : "maze/forestnew/enter", 
				"east" : "maze/forestnew/unique_room/bearlair", 
                "west" : "maze/forestnew/unique_room/wolfcave", 
                "north" : "maze/forestnew/unique_room/tigerhill", 
        ])); 

        setup();
        // replace_program(ROOM);
}
