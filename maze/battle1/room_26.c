// This program is a part of NT MudLIB

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"ɽ��"NOR);
        set("long", @LONG
������һ�����͵�ɽ����ͨ���վ���ɽ�塣���������Ҫ������һ�ذѵ������Ī�С�
LONG
    );
        set("exits", ([
                "north"     : __DIR__"room_25",
                "west"      : __DIR__"room_28",
                "south"     : __DIR__"room_27",
        ]));
        set("outdoors", "battle");
        setup();
}
