#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name(HIG "「开天仙经」" NOR, ({ "badao book", "badao", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
               // set("no_sell", 1);
                set("long", HIG "\n这是一本用薄纸写成的书，封皮上写有「开天仙经」二字。\n"
                            "你可以试着读读(read)看。\n\n" NOR, );
        }

}


void init()
{
        add_action("do_du", "read");
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        string msg;

        if (! arg)
        {
                write("你要读什么？\n");
                return 1;
        }

        if (me->is_fighting())
        {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

        if (where->query("no_fight")
           && me->query("doing") != "scheme")
        {
                write("你无法在这里静下心来研读开天仙经。\n");
                return 1;
        }


        if (me->query("str") < 35)
        {
                write("你先天臂力不足，无法修炼开天仙经。\n");
                return 1;
        }
/*
        if (me->query("con") < 35)
        {
                write("你先天臂力不足，无法修炼开天仙经。\n");
                return 1;
        }

        if ((int)me->query_skill("sword", 1) )
        {
                write("你所学的杂学太多了，无法专心研习开天仙经。\n");
                return 1;
        }

        if ((int)me->query_skill("club", 1) )
        {
                write("你所学的杂学太多了，无法专心研习开天仙经。\n");
                return 1;
        }

        if ((int)me->query_skill("staff", 1) )
        {
                write("你所学的杂学太多了，无法专心研习开天仙经。\n");
                return 1;
        }

        if ((int)me->query_skill("whip", 1) )
        {
                write("你所学的杂学太多了，无法专心研习开天仙经。\n");
                return 1;
        }

        if ((int)me->query_skill("dagger", 1) )
        {
                write("你所学的杂学太多了，无法专心研习开天仙经。\n");
                return 1;
        }

        if ((int)me->query_skill("hammer", 1) )
        {
                write("你所学的杂学太多了，无法专心研习开天仙经。\n");
                return 1;
        }

        if ((int)me->query("max_neili") < 10000)
        {
                write("你的内力修为不足。\n");
                return 1;
        }

        if ((int)me->query_skill("force", 1) < 500)
        {
                write("你的内功火候太浅。\n");
                return 1;
        }

        if ((int)me->query_skill("martial-cognize", 1) < 300)
        {
                write("你的武学修养不足。\n");
                return 1;
        }

        if ((int)me->query_skill("blade", 1) < 400)
        {
                write("你的基本刀法火候不够，无法学习开天仙经。\n");
                return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }
*/
 /*       if (me->query_skill("sanscrit", 1) < 200)
        {
                write("你的梵文水平太低，无法看懂书里所记载的内容。\n");
                return 1;
        }*/

/*if (! id(arg))
        {
                write("这里没有这本书。\n");
                return 1;
        }

     /*   if (me->query_skill("yinyang-shiertian", 1) )
        {
                write("你体内的阴阳真气无法与开天仙经相兼容。\n");
                return 1;
        }

        if (me->query_skill("lunhui-sword", 1) )
        {
                write("你体内的六道轮回真气无法与开天仙经相兼容。\n");
                return 1;
        }
*/
  /*      if ((int)me->query("combat_exp") < 10000000)
        {
                write("你的实战修为不足，再怎么读也没用。\n");
                return 1;
        }*/

        if ((int)me->query("jing") < 100
           || (int)me->query("qi") < 100
           || (int)me->query("neili") < 200)
        {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

        msg = HIG "$N" HIG "翻看《开天仙经》，仔细研究上面所记载的武学，霎那间若有所悟……\n" NOR;
        msg += HIG "$N" HIG "以手做刀，左劈右砍，忽而眉头金锁，忽而闭目沉思。\n" NOR;
        msg += HIG "$N" HIG "长叹一声，感慨万千，似乎明白了什么 ……\n" NOR;
        message_vision(msg, me);

        if (me->query_skill("badao", 1) < 180)
        {
                write(HIW "你对「" HIG "开天仙经" HIW "」有了新的领悟。\n" NOR);

                if (! me->query_skill("badao", 1))
                {
                        me->set_skill("badao", 40 + random(21));
                        me->save();
                }
                else
                        me->set_skill("badao", me->query_skill("badao", 1) + 40 + random(21));

                destruct(this_object());
        }
        else
        {
                write(HIR "你开天仙经级别已经无法再通过研读秘籍来提升了。\n" NOR);
                return 1;
        }

        return 1;
}
