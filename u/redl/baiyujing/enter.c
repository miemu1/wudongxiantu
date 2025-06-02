// This program is a part of NITAN MudLIB 
// redl 2013/3
#include <ansi.h>

#define TIME_INTERVAL 86400     

inherit ROOM;

int clean_up() { return 1;}

int do_restart()
{
        set("byj/entertime", time());//��;����uid
        return 1;
}

void set_can_up()
{
        remove_call_out("set_can_up");
        do_restart();
        call_out("set_can_up", TIME_INTERVAL);
}

void create()
{
        set("short", "��ɽ");
        set("long",
"��������ɽ������ɫ�ı��������У���Լ���������������������\n"
"ֻ������С·�ֱ�ͨ�������·�м�һ��������д�ţ�"+CYN+"���У���Ϊ������\n"
"��Ǳ�ܣ��Ϸ�����Ǯ��������������������������.�����������һ���ꡣ\n"
);

        set("exits", ([
                "south"   : "/u/redl/workroom", 
                "up"   : __DIR__"byjxx",
                "northup"   : __DIR__"byjxx",
                "southup"   : __DIR__"byjxx",
                "westup"   : __DIR__"byjxx",
                "eastup"   : __DIR__"byjxx",
        ]));
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
                set("no_clean_up", 1);
                set("no_fight", "1"); 
        setup();
        set_can_up();
}

void init()
{
        object me = this_player();
}


int valid_leave(object me, string dir)
{
        object *inv, ob;
        if (dir != "south"){
                if (!playerp(me)) return -1;
//              if (me->is_busy()) {
//                      tell_object(me,NOR + "��Ķ�����û����ɣ������ƶ���\n" + NOR); 
//                      return 1; 
//              }

                me->start_busy(2+random(2));
                
                if ( query("byj/entertime") == query("byj/entertime", me) ){
                        tell_object(me,NOR"�������Լ������ˣ���̫̰���˰���\n"NOR); 
                        return -1; 
                }

        if( me->in_team() ) {
           tell_object(me, "�㲻�������ȥ��\n");
           return -1;
        }

                if ( objectp(query_temp("is_riding", me)) ) return notify_fail("��������û����ȥ��\n");

                ob = find_object(__DIR__"byjxx"); 

                if (ob) {
                inv = deep_inventory(ob);
                if( sizeof(inv) > 0 ) {
                    foreach( object ob3 in inv ) {
                                if( playerp(ob3) ) {
                                    tell_object(me,NOR"���ٵȵȰɣ�����"+query("name",ob3)+NOR+"����"+HIC+query("short",ob)+NOR+"�����Σ�\n"NOR); 
                                        return -1;
                                }
                        }
                }
                }

                if (ob) destruct(ob);
                load_object(__DIR__"byjxx.c")->create();
                delete_temp("byj", me);//��ֹ���û��quit��
                set("byj/entertime", query("byj/entertime"), me);
                
        }
        return ::valid_leave(me, dir);
}
