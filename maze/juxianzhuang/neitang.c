// This program is a part of NT MudLIB

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
�������������ؿ��˵�С���á��м�һ��СԲ��ľ���ϣ�������
һ����ϯ�����ſ����������ε��⣬���Կ������䳡��
LONG);
        set("region", "jingzhou");
        set("exits", ([
                "east"   : __DIR__"yanwuchang",
                "west"   : __DIR__"houyuan",
                "south"  : __DIR__"changlang6",
                "north"  : __DIR__"changlang5",
        ]));

        set("coor/x", -1487);
        set("coor/y", -2040);
        set("coor/z", 0);
        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
