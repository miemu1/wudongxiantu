// This program is a part of NT MudLIB

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
        set("exits", ([ /* sizeof() == 3 */
                "south": __DIR__"wzoulan",
                "east" : __DIR__"room_01",
                "out" : __DIR__"wgate",
        ]));

        set("outdoors", "battle");
        setup();
}
