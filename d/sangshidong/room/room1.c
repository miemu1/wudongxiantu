inherit ROOM;

void create()
{
        set("short", "入口");
        set("long", @LONG
一条昏暗潮湿的地道，地道很长，两边点着两根不太明亮的火把，
而且画得相当难看，你加快脚步，想知道地道的尽头是什么地方。 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "north" : __DIR__"room7",
                "east" : __DIR__"room2",
        ]));
        set("no_update", 1);

        setup();
}
//是镜像
int is_jfb() { return 1; }

