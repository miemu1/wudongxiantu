// /d/tangmen/qianzhuang.c

#include "/d/tangmen/npc/job1.h";

void create()
{
        set("short", "����Ǯׯ");
        set("long",
"�������ŵ�Ǯׯ����������������ʷ�ˣ�������һ���ġ��ϰ�Ҳ��\n"
"�����бȽ������ŵ��˵��Σ�����һ���������ʤ�εġ������������Ʊ\n"
"ȫ��ͨ�ã��ǲ��ɶ��е����ֺ��ˡ�\n"
);
        set("exits", ([
                "north" : __DIR__"edajie",
        ]));
        set("objects", ([
               "/d/tangmen/npc/tangq" : 1
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
        setup();
}


