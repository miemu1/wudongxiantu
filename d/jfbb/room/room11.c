inherit ROOM;

void create()
{
        set("short", "密道");
        set("long", @LONG
一条昏暗潮湿的地道，地道很长，两边点着两根不太明亮的火把，
而且画得相当难看，你加快脚步，想知道地道的尽头是什么地方。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"room10",
                "south" : __DIR__"room5",
                "north" : __DIR__"room17",
                "east" : __DIR__"room12",
        ]));
        set("no_update", 1);

        setup();
}
//是镜像
int is_jfb() { return 1; }

