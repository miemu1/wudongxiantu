// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "ɽ��");
        set("long", 
"����ɽ����һƬ�ܿ����ĵط��������߰��ɣ���Բ����ʮ�ɡ�������\n"
"������һ��������("CYN"enter"NOR")������̨���������ţ�����������һ�����ˡ�\n"
);

         set("exits",([ /* sizeof() == 1 */
                 "enter" : __DIR__"suistone",
         ]));

        set("objects", ([
                __DIR__"obj/daoren" : 1,
        ]));

                set("no_rideto", 1);
                set("no_flyto", 1);
                        set("get_time", time());
        setup();
        
}

int valid_leave(object me, string dir)
{
                if (objectp(present("dao ren", this_object()))) {
                tell_object(me, NOR "�����������..����һ������ǰһ��ģ������δ���뿪ԭ�ذ벽��\n" NOR);
                return -1;
                }
        if (dir == "enter" && playerp(me)) {
                tell_object(me, YEL "�����������䣬ǿ���򶨵ؿ���˴�����\n" NOR
                                                HIY "�ռ�������ͣ��˺��Ť����ת�۵������ʯ��\n" NOR);
        }

        return ::valid_leave(me, dir);
}

