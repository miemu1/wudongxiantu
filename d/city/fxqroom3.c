
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIR"[��ս����]"NOR);
        set("long", @LONG
������
LONG
);

        set("no_fight", 1);
        set("no_magic", 1);
	
      
        set("exits",([
                	"south" : __DIR__ "pairoom",
        ]));
        set("objects",([
                "/clone/game/seaf":1,
        ]));
        
        setup();
}