inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "��̲");
        set("long",
"�����Ǳ���������̲�������Ĵ��ź��߾�ʯ����Χ��һ����\n"
"�ʵĴ󺣣����ߴ�������޴�����죬�ض�ɽҡһ�㣬�ƺ����ϵ�\n"
"��ɽ�ڲ��ϵ��緢���ͷų��޴��������\n"
);
        set("exits", ([ 
                "east"    : __DIR__"shadi",
        ]));
        
        set("no_rideto", 1);         // ���ò������������ط�
        set("no_flyto", 1);          // ���ò��ܴ������ط�����������
        set("binghuo", 1);           // ��ʾ�ڱ���    
        set("outdoors", "battle4");
        
        set("objects", ([
                __DIR__"npc/shouwei" : 1,
                __DIR__"npc/xiexiao-ci" : 1,
        ]));
        
        set("no_fight", 1);
        
        setup();
}

int valid_leave(object me, string dir)
{
        object guarder, horse, person;
        object *inv;
        int i;

        if (dir == "east")
        {
                // �����µ�һ��Ҳ��ڰ�ս�ڼ䲻�ý������
                if( !BUNCH_D->is_battle_start() && !BUNCH_D->is_top_bunch(me) )
                {
                        if (! objectp(guarder = present("binghuo shouhushen", this_object())))
                        {
                                message_vision(HIM "һ���â�����������ػ���Ļ��뾹������$N" HIM "��ǰ����$N�޷�ǰ����\n" NOR, me);
                                return 0;
                        }
                        else
                        {
                                message_vision(HIM "$N" HIM "һ�ѽ�$n" HIM "��ס��������Ŀǰ����ֻ�������µ�һ����ҽ��룡\n" NOR, guarder, me);
                                return 0;
                        }
                }
                
                // ��ս�ڼ䣬�Ͻ����µ�һ���Ա���ܽ���
                if( (BUNCH_D->is_battle_start() || BUNCH_D->is_battle_open()) && BUNCH_D->query_bunch_topten(1) == query("bunch/bunch_name", me) )
                {
                        if (! objectp(guarder = present("binghuo shouhushen", this_object())))
                        {
                                message_vision(HIM "һ���â�����������ػ���Ļ��뾹������$N" HIM "��ǰ����$N�޷�ǰ����\n" NOR, me);
                                return 0;
                        }
                        else
                        {
                                message_vision(HIM "$N" HIM "һ�ѽ�$n" HIM "��ס��������Ŀǰ���𵺲������Ͻ����µ�һ����룡\n" NOR, guarder, me);
                                return 0;
                        }
                } 
                
                // ����������˱�������
                if( objectp(horse=query_temp("is_riding", me)) )
                {
                        if( objectp(person=query_temp("is_rided_follow", horse)) )
                                delete_temp("is_riding_follow", person);
        
                        delete_temp("is_rided_follow", horse);
                        delete_temp("is_rided_by", horse);
                        delete_temp("is_riding_follow", me);
                        delete_temp("is_riding", me);
        
                        message_vision(HIR "\n$N��" + horse->name() + HIR " �ƺ��ܵ��˾��ţ�ǰ��һ�������"
                                       "����������\n\n" NOR, me);
        
                        return 1;
                }

                // �ѱ�����û�������
                inv = deep_inventory(me);
                for (i = 0; i < sizeof(inv); i++)
                {
                        if (! playerp(inv[i])) continue;
        
                        // ���˱�����û�
                        inv[i]->move(__FILE__);
                }                       
        }

        return ::valid_leave(me, dir);
}
