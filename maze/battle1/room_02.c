// This program is a part of NT MudLIB

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"ɽ��"NOR);
        set("long", @LONG
������һ�����͵�ɽ����ͨ���վ���ɽ�塣���������Ҫ������һ�ذѵ������Ī�С�
LONG
    );
        set("exits", ([                
                "south" : __DIR__"room_03",
                "east"  : __DIR__"room_11",
        ]));
        
        set("outdoors", "battle");
        setup();
}
