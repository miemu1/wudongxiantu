
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIR"[��������]"NOR);
        set("long", @LONG
��һ��
LONG
);

        set("no_fight", 1);
        set("no_magic", 1);

      
        set("exits",([
       			"west"  : __DIR__ "pairoom",
        ]));
        set("objects",([
                "/clone/game/fxq":1,
        ]));
        
        setup();
}