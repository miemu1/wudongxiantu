
//返老还童丹 (降低3-5岁年龄)

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "返老还童丹" NOR, ({ "huantong dan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "一粒传说中的仙丹，据说吃后能返老还童。\n" NOR);
                set("unit", "粒");
                set("value", 10);
                set("weight", 10);                
             }
        setup();
}

void init()
	{
		add_action("do_eat","eat");
	}
		

int do_eat( string arg )
{		 
        int num, rdm;
	 object me  = this_player();

        if ( ! arg || (arg != "huantong dan" && arg != "dan") )
          return 0;	
	
        if (me->query("age") < 28 )
        {
           write(HIG"你还年轻，用不着吃这东东。\n"NOR);
           return 1;
        }

        message_vision(HIY "$N将还童丹一口吞下。\n" NOR, me);

        num = 4 - me->query("reborn_start/huantong");
        if ( num > 1 ) 
        {
            rdm = random(num);
            if ( rdm == 0 ) rdm = 1;
            me->add("mud_age", - rdm * 2 * 520000);
            
            tell_object(me, HIG"你觉得身体发生了奇异的变化，"
                        "似乎一切机能都在重生。\n"NOR
                     HIR"你突然感到头痛欲裂，几欲晕倒......\n"NOR, me);       
	     me->unconcious(); 
        } else             
            tell_object(me, HIY"可是你觉得这药似乎没啥作用。\n"NOR, me);

       me->add("reborn_start/huantong", 1);
       destruct(this_object());
       return 1;
}
		
int query_autoload() { return 1; }

       	