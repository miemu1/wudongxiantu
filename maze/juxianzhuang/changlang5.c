// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "����");
        set("long",  @LONG
�������θ��ĳ��ȣ����ټҶ����͸������Ĵ�æµ��
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west"  :  __DIR__"xiangfang2",
                "east"  :  __DIR__"changlang3",
                "south" :  __DIR__"neitang",
                "north" :  __DIR__"changlang7",
        ]));

        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
