// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "��¥");
        set("long",  @LONG
�����θ��ı�¥������¥ңң��ԡ����Ӣ������������������С�
Ѧ��ҽ���������ڶ཭������������ɣ�Ӧ������ˣ���ʱ������᷿
��ЪϢƬ�̡�
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west"  :  __DIR__"xiaofotang",
                "east"  :  __DIR__"changlang1",
                "south" :  __DIR__"zhengting",
        ]));
        set("objects",([
                "/maze/juxianzhuang/npc/xuemuhua" : 1,
        ]));
        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
