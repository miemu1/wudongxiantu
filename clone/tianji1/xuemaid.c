// jinchuang.c 八龙涅槃丹

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIY "八龙血脉丹" NOR, ({"xuemaid"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "服用后直接打通带脉和冲脉。\n");
                set("tianji1", 35);
		    set("no_get", 1);
		    set("no_give", 1);
		    set("no_sell", 1);
		    set("no_steal", 1);

                set("no_sell", 1);set("value", 200);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{    
   int effect;
	 mapping my;

        log_file("static/using", sprintf("%s(%s) eat 八龙血脉丹 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
					   
					   

if( me->query("meridian/带脉")>0  )
            return notify_fail("你已经开始打通经脉，无法承受夺天丹的药力!\n");


if( me->query("meridian/冲脉")>0  )
            return notify_fail("你已经开始打通经脉，无法承受夺天丹的药力!\n");




 CHANNEL_D->do_channel(this_object(), "rumor", "恭喜" + me->name() + "打通了"HIR"带脉和冲脉"HIM",功力已如神人。。\n");

                effect++;
                write(HIM "你觉得自己的头脑更清醒了。"NOR"\n");
				me->set("meridian/冲脉", 24);
				me->set("meridian/带脉", 19);
               
				me->add("gain/damage", 500);
				me->add("gain/max_qi", 12500);
                write("\n "+HIR+"恭喜你："+NOR+HIG+"服用夺天丹，奇经八脉步入天人之境！！！ "+NOR);
        
		
		if(me->query("meridian/冲脉") >=24
		&& me->query("meridian/带脉") >=19)
	{
		me->add("max_neili", 1000);
		tell_object(me,HIG"恭喜你！成功打通2条经脉，一时间只觉全身真气行走全身，生生不息。"NOR"\n");
		message_vision(HIY"$N长啸一声，啸声清越激昂，连绵不绝！！！"NOR"\n",me);
	}
		
                destruct(this_object());
                return 1;
}