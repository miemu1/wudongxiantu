// This program is a part of NT MudLIB

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"С��"NOR);
        set("long", @LONG
������һ������С�����ž������˺��¡�
LONG
        );
        set("exits", ([
                "north" : __DIR__"wgarden",
                "east"  : __DIR__"room_04",
        ]));
        set("outdoors", "battle");

        setup();
}
