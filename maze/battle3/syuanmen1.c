// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ԯ����"NOR);
        set("long", @LONG
������ǡ����Ρ���Ӫפ�����ˣ�ԶԶ�ؿ��Կ���һ����죬��
������һ����������顸�Ρ��֣����߽�Щ�͵���Ӫ�ˣ�Ѱ���˻���
��Ҫ�����ĺã�ʡ�ñ�����ϸ��׽����������һ��ʯ��ͨ���¥����
��һ������ͨ���ǽ��
LONG );
        set("defence",120);
        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "south" : __DIR__"sying",
               "east"  : __DIR__"conglin4",
               "west"  : __DIR__"sying6",
               "up"    : __DIR__"sying5",
        ]));    

        create_door("up", "����", "down", DOOR_CLOSED);
        create_door("west", "ʯ��", "east", DOOR_CLOSED);
        setup();
}
              
void init()
{
        object me = this_player();

        if( query_temp("warquest/party", me) == "meng" )
                add_action("do_break", "break");
        else
        if( query_temp("warquest/party", me) == "song" )
                add_action("do_repair", "repair");
}

int do_repair()
{
        object room = this_object(), me = this_player();

        if (me->is_busy())
                return notify_fail("����æ���أ�\n");

        if (WAR_D->query_stones(me) < 200)
                return notify_fail("����ȱ���㹻��ʯͷ��ľ��,ԯ�ŵķ��������޷�����\n");

        if( query("defence", room)>999 )
                return notify_fail("ԯ�ŵķ��������Ѿ�������ˣ�\n");
        else
        {
                if( query_temp("warquest/group", me) < 1 )
                        return notify_fail("�㻹�Ǵ��������������ԯ�ŵķ������°ɣ�\n");

                message_vision(
                        HIW "$N����һ֧������ŵ�������ԯ�ŵķ������£�\n" NOR, me);
                addn("defence", random(query_temp("warquest/group", me)), room);
                WAR_D->expend_stones(me, 200);
                me->start_busy(1 + random(2));
                return 1;
        }
}

int do_break()
{
        object room = this_object(), me = this_player();

        if (me->is_busy())        
                return notify_fail("����æ���أ�\n");

        if( query("defence", room)<1 )
        {
                set("defence", 0, room);
                write("ԯ�ŵĵķ����Ѿ��������ˣ�����ȥ����\n");
                return 1; 
        } else
        {
                message_vision(
                        HIY "$N����һ֧���Ƕ������ӽ�������ԯ�ŵķ������£�\n" NOR,me);
                addn("defence", -random(query_temp("warquest/group", me)), room);
                me->start_busy(2 + random(2));
                return 1;
        }
}

