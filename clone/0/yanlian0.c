#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;
	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
	set_name(HIR"演练测试", ({"hubo"}));	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10);
		set("coin", 1);
          
  set("base_unit", "本");       
  set("no_drop",1); 
  set("no_give",1);
            set("no_get",1);				
            set("no_put",1);				
		set("base_weight", 10);
		set("zjvip/all_pay",350);
		set("long",HIW"这是一本顶级秘籍。一本可无限使用。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	me->set_skill("jiuyang-shengong",350);
	me->set_skill("taixuan-gong",360);
	me->set_skill("six-finger",360);
	me->set_skill("dragon-strike",360);
	me->set_skill("qiankun-danuoyi",360);
	me->set_skill("jiuyin-shengong",360);
	me->set_skill("taiji-shengong",360);
        

	write(HIW"你获得了300级互博神功，"NOR+HIG"感谢您对笑傲的大力支持，祝您游戏愉快！"NOR"\n");

    return 1;
}
