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
                "east"  :  __DIR__"changlang7",
                "south" :  __DIR__"xiangfang2",
        ]));

        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
