// xiandan.c 糊涂丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "糊涂丹" NOR, ({ "hutu dan", "dan", "hutu" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗园园很脏的丹药，据说吃了可以降低智力。\n");
                set("value", 10000);
                set("unit", "颗");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

                tell_object(me, HIG "一股火热蓦然从脑中升起，"
                            "你头痛欲裂，感觉被人敲了一锤"
			    "顿时脑子不太灵光了。\n");
                me->add("int", -1);
             write("\n "+HIR+"恭喜你："+NOR+HIG+"服用仙丹成功，《先天悟性》减少了！！！ "+NOR);

        me->add("gift/xiandan", 1);
        destruct(this_object());
	return 1;
}
