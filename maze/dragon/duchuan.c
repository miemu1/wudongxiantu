inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "�ɴ�");
        set("long",
"[1;32mһҶС�ۣ����Ҳ�������߸��ˡ�һ�������������������\n"
"�ֳ���ݣ����ڴ�β�����س��Ŵ���\n"
);
        set("no_clean_up", 0);
        set("no_magic", 1);
	setup();
        replace_program(ROOM);
}

