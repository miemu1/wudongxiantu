// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit ROOM;

int do_jump(string arg);
void create()
{
        set("short", "ɽ��");
        set("long",ZJURL("cmds:jump hongshui")+ZJSIZE(20)+HIC"ɽ��"NOR"\n" "����������ɽׯ��԰��һ��ɽ�����Ա���һƬ���ܵ���ľ�֣�����һƬ�ž���\n" ZJURL("cmds:time")+ZJSIZE(20)+HIC"��ʱ��"NOR"\n" );
        set("outdoors", "wansong");
        set("type","forest");
        set("exits",([
                "east":__DIR__"senling4",
        ]) );

        set("coor/x",-630);
        set("coor/y",250);
        set("coor/z",90);
        setup();
}

void init()
{
        if (NATURE_D->query_month() == 1 &&
           NATURE_D->query_day() == 15)
        {
                add_action("do_jump", "jump");
        }

       if (NATURE_D->query_month() == 7 &&
           NATURE_D->query_day() == 15)
        {
                add_action("do_jump", "jump");
        }

       if (NATURE_D->query_month() == 10 &&
           NATURE_D->query_day() == 15)
        {
                add_action("do_jump", "jump");
        }

}

string long()
{
        string msg;

        msg = query("long");

        if (NATURE_D->query_month() == 1 &&
            NATURE_D->query_day() == 15)
                msg += HIW "ɽ���еĺ�ˮ�������������ƷǷ�����������ζ�ʱ����Ҫ�����ˮ�еĳ嶯��" NOR;

       if (NATURE_D->query_month() == 7 &&
            NATURE_D->query_day() == 15)
                msg += HIW "ɽ���еĺ�ˮ�������������ƷǷ�����������ζ�ʱ����Ҫ�����ˮ�еĳ嶯��" NOR;

 if (NATURE_D->query_month() == 10 &&
            NATURE_D->query_day() == 15)
                msg += HIW "ɽ���еĺ�ˮ�������������ƷǷ�����������ζ�ʱ����Ҫ�����ˮ�еĳ嶯��" NOR;

        return sort_string(msg, 60, 4);
}

int do_jump(string arg)
{
        object me = this_player();

        if (! arg || (arg != "hongshui" && arg != "shangou"))
                return notify_fail("��������ʲô��\n");

        message_vision(HIW "$N" HIW "��������ɽ���еĹ�����ˮ֮�У���ʱû������Ӱ��\n" NOR, me);

        tell_object(me, HIW "ɽ���еĺ�ˮ̫����һ�ɾ��˴��������ʱ���˹�ȥ��\n" NOR);

       // me->unconcious();
        me->move(__DIR__"hole");
        return 1;
}
