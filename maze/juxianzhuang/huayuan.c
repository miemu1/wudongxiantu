// This program is a part of NT MudLIB

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�������θ��Ļ�԰��Ժ�������˸�ɫ�����ĵ����
LONG );
        set("outdoors", "luoyang");
        set("region", "luoyang");

        set("exits", ([
                "north" : __DIR__"xiaofotang",
                "south" : __DIR__"xiangfang1",
                "west"  : __DIR__"yanwuchang",
                "east"  : __DIR__"zhengting",
        ]));

        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
