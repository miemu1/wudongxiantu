inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "���ַ�");
        set("long", HIG @LONG ����Ⱥ����֣�����һ������������Ⱥ�壬Ҳ��˵�徿������
���١�Ȼ����ɽ�����ڣ�ȴΨ��һ�����һ�������С�ݳ���ɽ
�����֮�����������ƽ��ɴ˶�����
LONG
        );
        set("exits", ([ 
             "down" : "/quest/tulong/room/mountain",
]));
        set("objects", ([ 
        "/quest/tulong/obj/drug1" : 1,
        "/quest/tulong/npc/spirit2" : 1,
                        ]) );
        setup();
//      replace_program(ROOM);
}

void grass_grow()
{
        object grass;
        seteuid(getuid());
        if(grass=new("/quest/tulong/obj/drug1")){
                grass->move(this_object());
                grass->invocation();
        }
        return;
}

