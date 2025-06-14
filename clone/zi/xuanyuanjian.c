// 上古十大神器之 轩辕剑
// Create by Rcwiz for Hero.cn 2003/09

#include <ansi.h>

#include <weapon.h>
inherit SWORD;


void create()
{
        set_name(HIY "轩辕剑" NOR, ({ "xuanyuan jian", "xuanyuan", "jian" }) );
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {		
		set("gongxian",9999);
                set("unit", "把");
				set("no_sell", 1);set("value", 50000);
				set("can_summon", 1);
			set("no_give",1);
			set("no_steal",1);
			 set("no_sell", 1);
			set("no_get",1);
			 set("no_put",1);
			 set("armor_prop/sword", 1500);
                set("long", HIY "此乃上古神器之首，拥有着无穷的力量，据说"
                                "拥有此剑者可驰骋人、魔、神三界，势不可挡。\n"
                               "剑身一面刻日月星辰，一面刻山川草木。剑柄一面书农耕畜养之术，一面书四海一统之策。其内蕴藏无穷之力，为斩妖除魔的神剑。\n"
     NOR);

                set("material", "gold");
                set("wield_msg", HIY "$N" HIY "一声轻呼，两条神龙自天而下，拥着一把周身泛着\n"
                                 "金光的神剑，刹那间此剑犹如一道流星划过，落入$N" HIY "手中。\n" NOR);                               
                set("unwield_msg", HIY "$N" HIY "心意一转，轩辕剑已归鞘。\n" NOR);
                set("stable", 100);
				set("only_do_effect", 1);set("no_sell",1);
        }
        init_sword(2000);
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
                return HIY "$N" HIY "挥舞着手中的轩辕剑，万道彩光自中而出，直逼得"
                           "$n" HIY "连连后退。\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIR "$N" HIR "反转手中轩辕剑，猛然间，数道金光划向$n" HIY "，$n" HIY
                           "正惊异间，却已中剑。\n" NOR;

        }
        return damage_bonus;
}

int do_effect(object me)
{
     

      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

      if (me->query("xuanyuan",1))
                return notify_fail("你已经记录过了。\n");
      else {
              
                me->set("xuanyuan",1);

                message_vision("$N将精血滴入轩辕剑，感觉有了一丝联系。\n", me);
	          write(YEL"恭喜您：成功绑定人族皇道之兵--轩辕"NOR"\n");

	         
                return 1;
            }

}

int query_autoload()
{
	return 1;
}
