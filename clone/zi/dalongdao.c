// 上古十大神器之 轩辕剑
// Create by Rcwiz for Hero.cn 2003/09

#include <ansi.h>

#include <weapon.h>
inherit BLADE;


void create()
{
        set_name(HIR "大龙刀" NOR, ({ "dalong dao", "dalong", "dao" }) );
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {		
		set("gongxian",9999);
                set("unit", "柄");
				set("no_sell", 1);set("value", 50000);
			set("no_give",1);
			 set("no_put",1);
			set("no_get",1);
			set("no_steal",1);
			 set("no_sell", 1);
		set("armor_prop/blade", 1500);
                set("long", HIY "【破天神刀，名曰大龙】\n"
                            HIR"大龙刀号称瑰宝中的瑰宝，是远古时期以前就一直在流传的圣器。。\n"
                               "传说天龙皇殒落后，一个可与天抗的无上存在炼化了龙皇部分躯体，截取了龙魂与部分骨之精华，耗费千年之久才打造出此神兵，威力足可毁天灭地。\n"
      NOR);

                set("material", "gold");
                set("wield_msg", HIY "$N" HIW "一声大喝，从内天地中，拥着取出一把周身泛着\n"
                                 "不详的天刀，刹那间此刀犹如远古神魔在世，落入"HIY"$N" HIW "手中。\n" NOR);                               
                set("unwield_msg", HIY "$N" HIW "心意一转，大龙刀缓缓消失在虚空中。\n" NOR);
                set("stable", 100);
				set("only_do_effect", 1);set("no_sell",1);

        }
        init_blade(2000);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;
        
        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(20 + random(20));
                return HIC "$N" HIR "挥舞着手中的大龙刀，万道彩光自中而出，直逼得"
                           "$n" HIY "连连后退。\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIC "$N" HIR "反转手中大龙刀，猛然间，数道血光斩向$n" HIC "，$n" HIY
                           "正惊异间，却已中数刀。\n" NOR;

        }
        return damage_bonus;
}
int do_effect(object me)
{
     

      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

      if (me->query("dalong")>0)
                return notify_fail("你已经记录过了。\n");
      else {
              
                me->set("dalong",1);

                message_vision("$N将精血滴入大龙刀，感觉有了一丝联系。\n", me);
	          write(YEL"恭喜您：成功绑定上古神器--大龙刀"NOR"\n");

	         
                return 1;
            }

}
int query_autoload()
{
	return 1;
}
