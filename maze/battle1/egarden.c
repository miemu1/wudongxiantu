// This program is a part of NT MudLIB
// /d/arenahuang/egarden.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"ɽ��"NOR);
        set("long", @LONG
����һ��ɽ�ȣ�ɽ�������ֻ������ǲ��١��ٻ����ţ�ɽʯ��׾��
�������壬���ɴ��񣬾���ɷ�����ˡ��峺��Ϫ����������һ��Сͤ�ӣ�
����Ϫˮ��������ȥ��
LONG);
        set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"ezoulan",
                "west" : __DIR__"room_09",
                "out" : __DIR__"egate",
        ]));

        set("outdoors", "battle");
        setup();
}
