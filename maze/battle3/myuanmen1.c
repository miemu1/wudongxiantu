#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ԯ����"NOR);
        set("long", @LONG
������ǡ��ɹš���Ӫפ�����ˣ�ԶԶ�ؿ��Կ�����Ӫ�ڷ����
��������ʱ�м�ƥ����ɱ��������������ٿ�����Ȼವ�һö�����
��ͷ�Ϸɹ������ǸϿ��뿪�ĺá�
LONG );
        set("defence",120);
        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "south"  : __DIR__"caoyuan4",
        ]));    

        set("objects", ([

        ]));
    
        setup();
}

void init()
{
        object me = this_player();

        if( query_temp("warquest/party", me) == "song" )
                add_action("do_break", "break");
}

int do_break()
{
        object room = this_object(), me = this_player();

        if (me->is_busy())
                return notify_fail("����æ���أ�\n");

        if( query("exits/north", room) )
                return notify_fail("ԯ�ŵĵķ����Ѿ��������ˣ�����ȥ����\n");

        if( query("defence", room)<1 )
        {
                set("defence", 0, room);
                tell_object(me, HIR "ԯ�ŵĵķ����Ѿ��������ˣ�����ȥ����\n" NOR);
                set("exits/north", __DIR__"mying", room);
                call_out("door_close", 20, room);
                return 1;
        } else
        {
                if( query_temp("warquest/group", me) < 1 )
                        return notify_fail("�㻹�Ǵ������������ԯ�ŵķ������°ɣ�\n");

                message_vision(
                        HIY "$N����һ֧���Ƕ������ӽ�������ԯ�ŵķ������£�\n" NOR, me);
                addn("defence", -random(query_temp("warquest/group", me)), room);
                me->start_busy(3 + random(2));
                return 1;
        }
}

void door_close(object room)
{
        if( query("exits/north", room) )
        {
                delete("exits/north", room);
                tell_object(all_inventory(room),
                        HIW "�ɹž���æ����һ֧�����ԯ�ŵķ��������޺��ˣ�\n" NOR);
        }
        return;
}

