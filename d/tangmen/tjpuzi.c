// tangjiapuzi.c 

#include <ansi.h>;
#include "/d/tangmen/npc/job1.h";

void create()
{
        set("short", "�Ƽ�����");
        set("long",
"�����������ҵ��ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ��\n"
"���ƹ��������ӵ�ע���Ź������ˡ���˵��������ŵ�һ���鱨�㣬��\n"
"�����Ҫ���鱨�Ǵ������ȥ�ġ��ſڹ���һ�����ӣ�sign����\n"
);
        set("item_desc", ([
                "sign": HIY"    ��       ��\n"
                           "    ��       ��\n"
                           "    ��       ��\n"
                           "    ��       ��\n\n"NOR,
        ]));
        set("exits", ([
                "south" : __DIR__"edajie",
        ]));
        set("objects", ([
                __DIR__"npc/tangzg": 1,
        ]));
        set("no_clean_up", 1);
        setup();
}

