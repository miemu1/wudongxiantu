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
                "west"      : __DIR__"room_04",
                "north"     : __DIR__"room_12",
                "southeast" : __DIR__"room_14",
        ]));
        set("outdoors", "battle");
        setup();
}
