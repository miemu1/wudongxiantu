

inherit ROOM;

void  create  ()
{
        set("short",  "��Ժ");
        set("long",  @LONG
���߽�����ׯ��Ժ��Ժ�����ż�����÷��֦������򰾢��Ժ������
СͥԺ�ڣ��ٲ������������ı�־������ͦ�����ĵ����Ժ����ͣ�˲�
�ٳ���ÿһƥ���ڶ��ǰ���������
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "south"  :  __DIR__"changlang2",
                "north"  :  __DIR__"changlang1",
                "east"   :  __DIR__"damen",
                "west"   :  __DIR__"zhengting",
        ]));
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("coor/x", -600);
        set("coor/y", 10);
        set("coor/z", 0);
        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
