
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIR"[С�׿��ַ�]"NOR);
        set("long", @LONG
��һ��
LONG
);

        set("no_fight", 1);
        set("no_magic", 1);

      
        set("exits",([
       			"east"  : __DIR__ "fxqroom",
				"north"  : __DIR__ "fxqroom3",
				"south"  : __DIR__ "fxqroom2",
				"west"  : __DIR__ "fxqroom1",
				"up"  : __DIR__ "heishi",
        ]));
       
        
        setup();
}