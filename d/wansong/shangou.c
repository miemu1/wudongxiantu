// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit ROOM;

int do_jump(string arg);
void create()
{
        set("short", "山沟");
        set("long",ZJURL("cmds:jump hongshui")+ZJSIZE(20)+HIC"山沟"NOR"\n" "这里是万松山庄后园的一个山沟，旁边是一片密密的松木林，四周一片寂静。\n" ZJURL("cmds:time")+ZJSIZE(20)+HIC"看时间"NOR"\n" );
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
                msg += HIW "山沟中的洪水滚滚而过，气势非凡，你见此情形顿时有想要跳入洪水中的冲动。" NOR;

       if (NATURE_D->query_month() == 7 &&
            NATURE_D->query_day() == 15)
                msg += HIW "山沟中的洪水滚滚而过，气势非凡，你见此情形顿时有想要跳入洪水中的冲动。" NOR;

 if (NATURE_D->query_month() == 10 &&
            NATURE_D->query_day() == 15)
                msg += HIW "山沟中的洪水滚滚而过，气势非凡，你见此情形顿时有想要跳入洪水中的冲动。" NOR;

        return sort_string(msg, 60, 4);
}

int do_jump(string arg)
{
        object me = this_player();

        if (! arg || (arg != "hongshui" && arg != "shangou"))
                return notify_fail("你想跳入什么？\n");

        message_vision(HIW "$N" HIW "纵身跳入山沟中的滚滚洪水之中，顿时没有了身影。\n" NOR, me);

        tell_object(me, HIW "山沟中的洪水太急，一股劲浪打来，你顿时晕了过去。\n" NOR);

       // me->unconcious();
        me->move(__DIR__"hole");
        return 1;
}
