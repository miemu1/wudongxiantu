#include <ansi.h>

inherit DEMONROOM;

void create()
{
        set("short", "��ͷ�����");
        set("long",@LONG
���Ǿ�ͷ�ߵ���أ���Χ���ǳ�ʪ�����ʪ�أ��ֲ�֮����
LONG);


        set("exits", ([
                "out"    : "/maze/jiutoushe/haitan",
                    "enter"    : "/u/redl/jiuts2", 
                
        ]));
                set("no_rideto", 1);         // ���ò������������ط�
                set("no_flyto", 1);          // ���ò��ܴ������ط�����������
                set("n_time", 3);
                set("n_npc",30); 
                set("n_max_npc", 30);
                set("s_npc", "/clone/dream_npc/shenlongdao/snake/jiutoushe");

        setup();
}


