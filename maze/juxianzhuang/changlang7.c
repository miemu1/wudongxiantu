// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "����");
        set("long",  @LONG
�������θ��ĳ��ȣ����ټҶ����͸������Ĵ�æµ��
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west"  :  __DIR__"xiangfang4",
                "south" :  __DIR__"changlang5",
        ]));

        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
