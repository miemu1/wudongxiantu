// This program is a part of NT MudLIB

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"ɽ��"NOR);
        set("long", @LONG
������һ�����͵�ɽ����ͨ���վ���ɽ�塣���������Ҫ������һ�ذѵ������Ī�С�
LONG
    );
        set("exits", ([
                "west"    : __DIR__"room_07",
                "up"      : __DIR__"etower1",
                "east"    : __DIR__"egarden",
        ]));

        set("outdoors", "battle");
        setup();
}
