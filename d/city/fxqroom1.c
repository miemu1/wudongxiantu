
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIR"[��ɫ]"NOR);
        set("long", @LONG
�ڶ���
LONG
);

        set("no_fight", 1);
        set("no_magic", 1);
	
      
        set("exits",([
             			"east"  : __DIR__ "pairoom",
        ]));
        set("objects",([
                "/clone/game/dhs":1,
        ]));
        
        setup();
}