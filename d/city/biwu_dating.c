#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"演武大厅"NOR);
    set("long", @LONG
这是一个宽敞的大房间，靠北墙搭着一个巨大的擂台(leitai)，
擂台后被一块布帘遮档的密密实实，但是一股浓厚的杀气仍然从布
帘后散发出来，弥漫在空气里，直钻入你内心。在东面墙上，悬挂
着诺大的一个大匾(dabian)。
LONG );

    set("no_fight",1);
    set("no_beg",1);
    set("no_steal",1);
    set("biwu_room",1);

        set("item_desc",([
            "擂台" : "一个四四方方的大擂台，你可以"ZJURL("cmds:jump leitai")ZJSIZE(15)""HIW"跳上去"NOR"。\n",
            "大匾" : "上现刻画着各个英雄的排名，"ZJURL("cmds:look dabian")ZJSIZE(15)""HIW"查看"NOR"排名。\n",
        ]));

    set("objects",([
            "/adm/npc/broadcaster" : 1,
    ]));

    set("exits", ([
        "south"  : __DIR__"biwu_road",
    ]));

    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_no","get");
    add_action("do_no","put");
    add_action("do_no","drop");
    add_action("do_no","summon");
    add_action("do_no","eat");
    add_action("do_no","drink");
    add_action("do_no","guard");
    add_action("do_jump","jump");
    add_action("do_look","look");
}

int do_no()
{
    object me;
    me = this_player();
    if (wizardp(me)) return 0;

    tell_object(me,"在这里你想干什么？\n");
    return 1;
}

int do_look(string arg)
{
    string msg;
    int i;
    mapping paiming;

    if (arg != "dabian") return 0;
    paiming = BIWU_D->get_list();
    msg = HIC "      *          雄       霸       天       下          *\n"NOR;
    msg += HIC "-------------------------------------------------------------\n";
    msg += "\n";
    for (i = 0;i < sizeof(paiming);i++)
{
            msg += HIY + "   【天下第" + chinese_number(i+1) + "】 " + NOR + paiming[i]["title"] + "\n";
            msg += "\n";
}
    msg += HIC "-------------------------------------------------------------\n";
    write(msg);
    return 1;
}

int do_jump(string arg)
{
    int status;
    object me;
    me = this_player();

    if (arg != "leitai")
    {
            tell_object(me,"你要往哪里跳啊？\n");
            return 1;
    }
/*
    if (wizardp(me))
    {
            tell_object(me,"你是巫师啊，就别来跟玩家争什么第一第二了！\n");
            return 1;
    }*/

    if (me->query("last_biwu_time") &&
        time() - me->query("last_biwu_time") < 300 && !wizardp(me))
    {
            tell_object(me,"你刚刚才打过擂，先休息一会吧，五分钟后再打。\n");
            return 1;
    }

    if (me->query("combat_exp") < 5000000 && !wizardp(me))
    {
            tell_object(me,"你使劲跳了一下，结果下巴碰到了擂台边缘，疼的死去活来。\n");
            return 1;
    }

    status = BIWU_D->get_status();
    if (status == 2) return notify_fail("擂台上已经有人了，你就等等吧！\n");
    if (status == 3) return notify_fail("现在还没到打擂的时间，你急啥？\n");

    if (me->query("combat_exp") > 10000000)
            message_vision(HIW"$N深吸一口气，一挺身，已经悠然飘上擂台。\n"NOR,me);
    else
            message_vision(HIW"$N攀住擂台一角，一使劲，笨拙的爬上了擂台。\n"NOR,me);

    BIWU_D->start_biwu(me);
    return 1;
}

int valid_leave(object me, string dir)
{
	if (BIWU_D->get_status() == 2 && BIWU_D->get_enemy() == me)
	        return notify_fail("你还在擂台上，不能离开。\n");
	return ::valid_leave(me, dir);
}
