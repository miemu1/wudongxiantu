
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIR"[21��]"NOR);
        set("long", @LONG
������
LONG
);

        set("no_fight", 1);
        set("no_magic", 1);
	
      
        set("exits",([
                	"north" : __DIR__ "pairoom",
        ]));
        set("objects",([
                "/clone/game/pai21":1,
        ]));
        
        setup();
}