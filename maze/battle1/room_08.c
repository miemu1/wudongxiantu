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
                "north": __DIR__"room_07",
                "west" : __DIR__"room_18",
                "east" : __DIR__"ezoulan",
        ]));
        set("outdoors", "battle");
        setup();
}

