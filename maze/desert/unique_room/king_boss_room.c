#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"������"NOR);
        set("long",@LONG
���������ѵ�,̫��ĵ�����,���Ӱ���
LONG);

        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");

        set("objects",([
                "/maze/desert/npc/king_boss": 1,
/*
                "/maze/desert/npc/guai_boss": 2,
                "/maze/desert/npc/guai": 3,
*/
        ]));
        setup();
}
