// This program is a part of NT MudLIB
// eting.c
// 演武厅


#include <ansi.h>
inherit ROOM;

string long_desc();
int do_withdraw(string arg);
int do_plant(string arg);
#define BATTLEFIELD_D "/adm/daemons/battlefieldd"

void create()
{
        set("short", HIW"演武厅"NOR);
        set("long",@LONG
ba对方的qi。
LONG);

        set("exits", ([
                "west" : __DIR__"etower2",
        ]));

        set("outdoors", "battle");
        setup();
}

void init()
{
        add_action("do_withdraw", "ba");
        add_action("do_withdraw", "withdraw");
        add_action("do_plant", "plant");
}



int do_withdraw(string arg)
{
        object flag, me=this_player(), *obj;
        int i, bGuarded = 0;

        if( !arg || arg != "flag" && arg != "qi" )
                return notify_fail("你想要拔什么？\n");

        if( me->is_busy() )
                return notify_fail("你很忙");

        if( query("flag") <= 0 )
                return notify_fail("没旗可拔。\n");

        if( me->query_temp("battle/team_name") == query("team_name") )
                return notify_fail("偷自己的旗？\n");

        message_vision(HIY"$N向旗杆跃起，想一把拔下旗子。\n"NOR, me);

        obj = all_inventory(environment(me));
        for( i=0; i<sizeof(obj); i++ ) {
                if( living(obj[i]) &&
                    obj[i]->query_temp("battle/team_name") != me->query_temp("battle/team_name") &&
                    obj[i]->visible(me) ) {
                        obj[i]->kill_ob(me);
                        message_vision(HIR"$N急对$n喝道：“$n竟敢偷旗，看招！”\n"NOR, obj[i],me,me);
                        me->kill_ob(obj[i]);
                        bGuarded = 1;
                }
        }

        if( !bGuarded )
        {
                flag = new(__DIR__"obj/flag");
                flag->set_name(({ "flag" })->query("flag_name") );
                if( flag->move(me) ) {
                        message_vision(HIG"$N一把扯下了大旗，高高举起。\n"NOR, me);
                        set("flag",0);
                } else {
                        destruct(flag);
                }
                CHANNEL_D->do_channel(this_object(), "war",
                        "听说"+me->name()+"夺走了"+query("flag_name")+HIR"！"NOR );
        }
        return 1;
}

int do_plant(string arg)
{
        object flag, me = this_player();

        if( !BATTLEFIELD_D->in_battle(me) )
                return notify_fail("现在没有比赛。\n");

        if( me->is_busy() )
                return notify_fail("你很忙");

        if( !arg || arg != "flag" && arg != "qi" )
                return notify_fail("你想要插什么？\n");

        if( query("flag") > 0 )
                return notify_fail("旗杆上已有旗了。\n");

        if( me->query_temp("battle/team_name") == query("team_name") )
                return notify_fail("这可不是你的地盘。\n");

        flag = present("flag",me );
        if( !flag ) return notify_fail("你手中没旗可以插。\n");

        if( flag->query("name") == query("team_name")+"大旗" )
                return notify_fail("自己的队旗应该插在大本营才是。\n");

        message_vision(HIY"$N把大旗哗啦啦展开，插上了旗杆。\n"NOR, me);

        set("flag",1);

        CHANNEL_D->do_channel(this_object(), "war",
                "听说"+me->name()+"将"+flag->query("name")+HIR"插到了演武厅！"NOR);
        set("flag_name",flag->query("name"));

        destruct(flag);

        BATTLEFIELD_D->add_bonus_score(me, 20);
        BATTLEFIELD_D->win_battle(me->query_temp("battle/team_name"));
        return 1;
}
