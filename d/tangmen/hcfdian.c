//hcfdian.c

#include "/d/tangmen/npc/job1.h";

void create()
{
        set("short", "ҩ��");
        set("long",
"���ǻش������������ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ���ɴ˿�\n"
"֪�����ҩ�Ǿ������ڡ���������Ϊʲôû�п���ҩ���أ�ԭ��ܼ򵥣�\n"
"���ŵ�ҩ�ǲ����ģ�ֻ�����ŵ��Ӳ��ܺ��õġ����վ�ڹ�̨���к��Ź˿͡�\n"
);
        set("objects", ([
                "/d/city/npc/huoji" : 1,
        ]));
        set("exits", ([
                 "east" : __DIR__"ndajie",
        ]));
        set("no_clean_up", 0);
        setup();
}

