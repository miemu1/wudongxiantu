inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "���ַ�");
        set("long",
"[1;32m����Ⱥ����֣�����һ������������Ⱥ�壬Ҳ��˵�徿����\n"
"�ж��١�Ȼ����ɽ�����ڣ�ȴΨ��һ�����һ�������С�ݳ���ɽ���\n"
"��֮�����������ƽ��ɴ˶�����\n"
);
        set("exits", ([ 
             "down" : __DIR__"mountain",
]));
        set("objects", ([ 
        "/quest/tulong/obj/drug1" : 1,
        "/quest/tulong/npc/spirit2" : 1,
                        ]) );
        set("no_magic", 1);
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

