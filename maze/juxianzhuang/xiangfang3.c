// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "�᷿");
        set("long",  @LONG
�������θ���һ���᷿������˫�۵�֪���������������ʹ����ڴ�
����
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"  :  __DIR__"changlang6",
                "south" :  __DIR__"xiangfang5",
                "north" :  __DIR__"houyuan",
        ]));

        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
