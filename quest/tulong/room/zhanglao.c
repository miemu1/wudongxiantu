inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "������");
        set("long",HIG @LONG 
���Ǿ��鳤�����ڵķ��䣬һ���׺��ӵľ��������������ڴ�
ǰ��˼��ʲô��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "west" : "/quest/tulong/room/village",
   "southeast" : "/quest/tulong/room/xiuxishi",
   ]));

        setup();
        replace_program(ROOM);

}

