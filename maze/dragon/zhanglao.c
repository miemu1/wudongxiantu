inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "������");
        set("long",
"[1;32m���Ǿ��鳤�����ڵķ��䣬һ���׺��ӵľ���������������\n"
"��ǰ��˼��ʲô��\n"
);
        set("exits", ([ /* sizeof() == 4 */
   "west" : __DIR__"village",
   "southeast" : __DIR__"xiuxishi",
   ]));

        set("no_magic", 1);
	setup();
        replace_program(ROOM);

}

