// shidong10.c 石洞

inherit ROOM;

#include <ansi.h>

string look_bi();
int do_sleep(string arg);

void create()
{
        set("short", "悟道之谷");
        set("long", @LONG
脱凡入道，以道入仙，改造人体丹田，凝结仙元。
LONG );
        set("item_desc",([
	        "石壁"  : (: look_bi :),
        ]));
	set("exits", ([
		"south" : __DIR__"shanmen",

	]));

        setup();
}
do_sleep(string arg);
void init()
{
        add_action("do_canwu", "canwu");
}

string look_bi()
{
       object me = this_player();
       string msg;

       if ((int)me->query("max_neili")<10000||me->query("combat_exp")<1000000||me->query("potential")<1000000)
       {
           msg = HIC "\n你走到四周，感觉有无数道纹四处横行\n"
                 "然而你功力不足。你仔细推敲这些道文却一无所获。\n" NOR;
       }
       else
       {
           msg = HIW "你走到石壁前，仔细观看石壁上的内容，发现石壁布满道纹\n"
"在此处可以参悟石壁，提升自身先天思维属性。每次成功参悟修为-1000万、潜能-1000万、最大内力-1万。\n"
"先天属性+1。\n"
                 WHT"("ZJURL("cmds:canwu 臂力开发 from bi")ZJSIZE(25)""HIY"突破：领悟臂力"NOR")\n"
                    "("ZJURL("cmds:canwu 悟性开发 from bi")ZJSIZE(25)""HIY"突破：领悟悟性"NOR")\n"
                    "("ZJURL("cmds:canwu 根骨开发 from bi")ZJSIZE(25)""HIY"突破：领悟根骨"NOR")\n"
                    "("ZJURL("cmds:canwu 身法开发 from bi")ZJSIZE(25)""HIY"突破：领悟身法"NOR")" NOR;
       }

       return msg;
}

int do_canwu(string msg)
{
    object me = this_player();

    string where, witch;

    if (! msg)return notify_fail("什么？\n");

    if (sscanf(msg, "%s from %s", witch, where) != 2)
          return notify_fail("干什么？\n");

    if (me->is_busy())
          return notify_fail("你现在正忙着呢。\n");

    if (me->is_fighting())
          return notify_fail("你在战斗哦？！小心，来了！！！\n");

    if(me->query("potential")<1000000)
          return notify_fail("你的潜能不足1000万，无法在此领悟！！！\n");

    if(me->query("combat_exp")<1000000)
          return notify_fail("你的修为不足1000万，无法在此领悟！！！\n");


    if (witch != "臂力开发"
     && witch != "身法开发"
     && witch != "根骨开发"
     && witch != "悟性开发")
          return notify_fail("你想开发什么？\n");

    if (where != "bi")
          return notify_fail("这里没什么给你突破的啊！\n");

   /* if (me->query_skill("literate", 1)
        || me->query("learned_literate"))
          return notify_fail("你对着石壁想了半天也没发现什么！\n");
*/
    if ((int)me->query_skill("force", 1) < 1200)
          return notify_fail("你的基础内功不够(1200)级，无法贯通石壁上的道纹！\n");

    if ((int)me->query("max_neili") < 10000)
          return notify_fail("你的内力修为不足(1万)，无法贯通石壁上的道纹！\n");

    if ((int)me->query("jing") < 200)
          return notify_fail("你的精力无法集中，无法领悟石壁上的道纹！\n");

    if (witch == "臂力开发"
        && (int)me->query("bbkf") == 999)
          return notify_fail("你的臂力方面已经全部领悟完毕\n");

    else
    if (witch == "悟性开发"
        &&(int)me->query("nbkf") == 999)
          return notify_fail("你的悟性方面已经全部领悟完毕\n");

     else
    if (witch == "根骨开发"
        &&(int)me->query("glkf") == 999)
          return notify_fail("你的根骨方面已经全部领悟完毕\n");

    else
    if (witch == "身法开发"
        && (int)me->query("tbkf") == 999)
          return notify_fail("你的身法方面已经全部领悟完毕\n");

    me->receive_damage("jing", 95);

    me->start_busy(2);

    if (random(2) == 1 && witch == "臂力开发")
    {
        me->add("str", 1);
         me->add("bbkf", 1);
           me->add("combat_exp", -1000000);
            me->add("max_neili", -10000);
            me->add("potential",-1000000);

        write(HIC "你的臂部潜能开发了1%，先天臂力+1。\n" NOR);
        me->start_busy(2);
        return 1;
    }

    else
    if (random(2) == 1 && witch == "悟性开发")
    {
             me->add("int", 1);
         me->add("nbkf", 1);
           me->add("combat_exp", -1000000);
           me->add("potential",-1000000);
            me->add("max_neili", -10000);

        write(HIC "你的脑部潜能开发了1%，先天悟性+1。\n" NOR);

            return 1;
        }
        
    else
    if (random(2) == 1 && witch == "根骨开发")
    {
                me->add("con", 1);
         me->add("glkf", 1);
           me->add("combat_exp", -1000000);
            me->add("max_neili", -10000);
	me->add("potential",-1000000);
        write(HIC "你的骨骼潜能开发了1%，先天根骨+1。\n" NOR);
       return 1;
    }

    else
    if (random(2) == 1 && witch == "身法开发")
    {
                me->add("dex", 1);
         me->add("tbkf", 1);
           me->add("combat_exp", -1000000);
           me->add("potential",-1000000);
            me->add("max_neili", -10000);

        write(HIC "你的臂部潜能开发了1%，先天身法+1。\n" NOR);
	me->start_busy(2);
            return 1;
        }

    else return notify_fail("你试图从石壁上研究有关「" + witch + "」的内容，但是运气差了点，没有突破！\n");

}
int valid_leave(object me,string dir)
{
        if (dir == "out")
                tell_object(me,"你走出了石洞，神秘地出现在大厅之中。\n");

        return ::valid_leave(me,dir);
}

int do_sleep(string arg)
{
        object me=this_player();
        int lvl;

        lvl = (int)me->query("bbkf", 1) + (int)me->query("tbkf", 1) + (int)me->query("nbkf", 1) + (int)me->query("glkf", 1);
        if (lvl >= 400)
{
me->move("d/city/kedian");
}       
        return 1;
}