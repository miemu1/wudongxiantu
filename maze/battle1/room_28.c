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
         set("objects", ([

         ]));
         set("exits", ([
                  "north"     : __DIR__"room_23",
                  "east"      : __DIR__"room_26",
                  "south"     : __DIR__"room_24",
                  "west"      : __DIR__"room_21",
         ]));
         set("outdoors", "battle");
         setup();
}
