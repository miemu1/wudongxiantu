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
	set_name(HIG"武器升级石", ({"sjs"}));	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10);
		set("coin", 1);
          
  set("base_unit", "颗");       
  set("no_drop",1); 
  set("no_give",1);
            set("no_get",1);				
            set("no_put",1);				
		set("base_weight", 10);
		set("yuanbao",3500);
		set("long",HIW"使用武器等级可加1级。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if((!me->query("weapon/make")) )
		    return notify_fail("你还没有自制武器呢，不能使用"+ name() +"。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	me->add("weapon/lv",1);
        

	write(HIW"你的武器等级加了一级，记得下线重登刷新攻击力！"NOR"\n");
	add_amount(-1);

    return 1;
}
