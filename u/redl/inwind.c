// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "��ؼ�");
        set("long", 
"������裬����ǧ�ء�̤����磬��ң��񷡣\n"
);

                set("no_fight", 1); 
                set("no_magic", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);
        
        setup();
}

void init()
{
                object me = this_player();
                if (playerp(me)) {
                        me->start_busy(3);
                        call_out("do_sui", 1, me); 
                }
}


int do_sui(object me)
{
                if (!query_temp("can_redlinwind", me)) set_temp("can_redlinwind", 1, me);
                if (query_temp("can_redlinwind", me) < 12) {
                        addn_temp("can_redlinwind", 1, me);
                message_vision(YEL "$N��Ӱ��Խ��ԽԶ���������������Զ��Ʈȥ...\n" NOR, me);
                me->move(__DIR__"inwind");
                } else {
                        delete_temp("can_redlinwind", me);
                        me->stop_busy();
                message_vision(YEL "$N��˼������ƮƮ����֮�У�ͻȻ����һ��$N��Ŀһ��...\n" NOR, me);
                me->move(__DIR__"lake");
                tell_object(me, YEL "��罫�㻺���е����߷��£�ע������ǰ��һ�У���þò���Ų���Ų���\n" NOR);
                }
                return 1;
}


