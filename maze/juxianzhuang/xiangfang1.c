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
                "west"  :  __DIR__"changlang4",
                "east"  :  __DIR__"nanlou",
                "north" :  __DIR__"huayuan",
        ]));

        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
