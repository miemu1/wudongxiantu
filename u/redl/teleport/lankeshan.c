// This program is a part of NITAN MudLIB  
// redl 2014/8
#include <ansi.h>  
#include <room.h>  
inherit __DIR__"normal.c";  

void create()
{
        set("short","����ʯ��");
        set("long", @LONG
�������ÿ�ɽ���塣������ʯͤ���顰�ճ�ͤ�����ұ߶��˸�
��ʯ�����������š���ϼ�ڰ˶��족����ǰ���е��������������ʯ
����������Լʮ�ɣ��ʺ�һ���߸߼����γ��˸���Բ���׵Ķ��ߡ�
�����ķ����������ޱȣ�ȷʵ�Ǹ����������ľ���ȥ����
LONG );
        set("outdoors", "yangzhou");
        set("exits",([ /* sizeof() == 1 */
            "out"  : "/u/redl/teleport/teleport",
        ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_magic", 1); 
        set("no_user_kill", 1); 
        set("no_sleep_room", 1);  
        setup();
}

int do_sit() 
{
        object me = this_player(); 
        string file = "/temp/qroom/" + query("id", me) + ".c";
                if (!sizeof(get_dir("/temp/qroom"))) mkdir("/temp/qroom");
        set_temp("time_enter_qroom", time() + 10, me);
        if (!(load_object(file))) 
        cp("/u/redl/teleport/qroom.c", file);
        tell_object(me, NOR CYN "���������˿���������һ����գ�۾ͱ���˿ռ䡣\n" NOR); 
        me->move(file);
        return 1;
}


void init()  
{
        object me = this_player(); 
        if (query_temp("time_enter_qroom", me) < time()) {
                tell_object(me, NOR "�����Ŷ�����İ�ݺ�����̣�����ס����һ��������(" CYN "sit" NOR ")��ȥ��\n" NOR); 
                add_action("do_sit","sit");  
        } else tell_object(me, NOR "���������Ƶ����������İ���̣��ƺ�������ȥ����\n" NOR); 
}  






