// This program is a part of NT MudLIB

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIM"ɽ��"NOR);
        set("long", @LONG
������һ�����͵�ɽ����ͨ���վ���ɽ�塣���������Ҫ������һ�ذѵ������Ī�С�
LONG
    );
        set("exits", ([
                "northwest"     : __DIR__"room_15",
                "east"      : __DIR__"room_06",
                "south"     : __DIR__"room_17",
        ]));
        set("outdoors", "battle");
        setup();
}
