// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "�θ�����");
        set("long",  @LONG
����һ����Ϊ���������ã�û��ʲô̫���װ�Σ�ֻ�ڱ���ǽ�Ϲ���
һ����������ġ�����ͼ�������ϴ˼����˵����֡��������а���һ
�ź�ľ�輸�����Ҹ�����һ��̫ʦ�Σ��������Ķ��˱�������լԺ��
���ˣ�����˫�ۡ�
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west"  :  __DIR__"huayuan",
                "east"  :  __DIR__"dayuan",
                "south" :  __DIR__"nanlou",
                "north" :  __DIR__"beilou",
        ]));
        /*
        set("objects",([
                __DIR__"npc/youju" : 1,
                __DIR__"npc/youji" : 1,
        ]));
        */
        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
