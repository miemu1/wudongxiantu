inherit ROOM;

void create()
{
        set("short", "����㳡");
        set("long", @LONG
����������������㳡���ˣ�������ǻʹ������ˣ�һ���Ѱ��
���ն����ҵ�����ȥ�����������ﻹ���൱�����֣���ͷ���յģ���
Ϸ�Ķ��Ƽ��ڴˣ��γ�һ�󾰹⡣
LONG );
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north" : __DIR__"ydmen",
                "south" : __DIR__"nandajie2",
        ]));

        set("objects", ([
//                "/maze/battle3/npc/flowerg" :    1,   
        ]));

        setup();
        replace_program(ROOM);
}
