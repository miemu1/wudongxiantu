// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "��¥");
        set("long",  @LONG
�������θ�����¥������˫�۵�֪���������������ʹ����ڴ˴���
�˴�Ӣ��������ı���֮�У��������й١����������ȸߣ���������˫
�۽����ǳ���㽫������������᷿����ס��
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west"  :  __DIR__"changlang4",
                "east"  :  __DIR__"changlang2",
                "north" :  __DIR__"zhengting",
        ]));
        /*
        set("objects",([
                __DIR__"npc/shanzheng" : 1,
        ]));
        */
        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
