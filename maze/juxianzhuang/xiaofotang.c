// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "С����");
        set("long",  @LONG
�����ֵܲ��ǳ�����ţ�ȴҲ�ڼ��и���һ��С���ã�����������
������ι㿪Ӣ���磬���������Ŵ�ʦ�ʵ���ǰ�����ᣬ�����ݾ���
�ˡ�
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west"  :  __DIR__"changlang3",
                "east"  :  __DIR__"beilou",
                "south" :  __DIR__"huayuan",
        ]));
        /*
        set("objects",([
                __DIR__"npc/xunji" : 1,
                __DIR__"npc/xunnan" : 1,
                __DIR__"npc/sengren" : 1,
        ]));
        */
        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
