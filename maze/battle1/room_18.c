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
                "north"     : __DIR__"room_17",
                "southwest"     : __DIR__"room_19",
                "east"      : __DIR__"room_08",
        ]));
        set("outdoors", "battle");
        setup();
}
