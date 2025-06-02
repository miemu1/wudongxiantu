// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.

#include <ansi.h>
#include <command.h>

#define RIDE_CMD        "/cmds/std/ride"

inherit ROOM;


void create()
{
        set("short", HIW"Ԫ˧��Ӫ"NOR);
        set("long", @LONG
������ǡ����Ρ�Ԫ˧����Ӫ�����߷������ڽ����ʿ������Ԫ
˧�����︺�����ǲ���������ɹž������֣���ʱ�д������æ�ؽ�
����������ǰ�ߵľ��顣
LONG );

        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */
              "north" :   __DIR__"sying",
              "south" :   __DIR__"sying4",
              "west"  :   __DIR__"sying2",
              "east"  :   __DIR__"sying3",
        ]));

        setup();
}

void init()
{
        object me = this_player();

        if (me == WAR_D->query_marshal())
        {
                message_vision(HIW "���еĽ�ʿ����$N���˽�������æ������վ�ñ�ֱ���𾴵���$N�����¾���\n" NOR, me);

                add_action("do_assign", ({ "appoint", "paiqian", "assign" }));
                add_action("do_convene", ({ "convene", "dianjiang" }));
        }
}

// recruit ��ļ
int do_assign(string arg)
{
        object me;

        me = this_player();
        tell_object(me, WAR_D->do_assign(me, arg));
        return 1;
}

int do_convene(string arg)
{
        object ob, me;
        object *total;
        int i;

        me = this_player();
        message_vision(HIR "$N���������������������ٴ����Ӫͳ�쵽��˧��ǰ�����\n", me);

        total = WAR_D->query_generals();
        for (i = 0; i < sizeof(total); i++)
        {
                if (! objectp(total[i])) continue;

                ob = total[i];
                if( query_temp("warquest/guard", ob) || 
                    query_temp("warquest/recon", ob) || 
                    query_temp("warquest/purchase", ob) || 
                    query_temp("warquest/battle", ob) )
                        continue;

                if (sscanf(base_name(environment(ob)), "/maze/battle3/sy%*s"))
                {
                        message_vision(HIR "һλ��������Ҵҵø�����$N������������" +
                                       "������Ԫ˧��Ӫ�����\n" NOR, ob);

                        ob->start_call_out((: call_other, __FILE__, "go_back", ob :), 5);
                }
        }

        return 1;
}

void go_back(object ob)
{
        if (! objectp(ob)) return;

        message_vision(HIY "$N��æ�������ף�����Ԫ˧��Ӫ������û����ʱ����\n" NOR, ob);
        ob->move(__DIR__"sying1");

        return;
}


