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
	set_name(HIY"古神通宝"NOR, ({"gushen tombo"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1",1000);
        set("no_sell",1);
        set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("unit", "枚");
		set("base_unit", "枚");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","敬利于世，犹欲割截，岂有所惜哉！\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+name()+"。\n");
		
		if ((me->query_skill("martial-cognize")-me->query_skill("martial-cognize"))>800)
                return notify_fail("武学修养太高了，这对你已经没用了"+ name() +"。\n");
      else {
	me->set_skill("literate", me->query_skill("literate",1) + 150);//读书识字
	me->set_skill("xinfa", me->query_skill("xinfa",1) + 150);//基本心法"
	me->set_skill("magic", me->query_skill("magic") + 150);//:"基本法术"
	me->set_skill("medical", me->query_skill("medical",1) + 50);//基本医术
	me->set_skill("poison", me->query_skill("poison",1) + 50);//基本毒技
	me->set_skill("sanscrit", me->query_skill("sanscrit",1) + 50);//梵文
	me->set_skill("buddhism", me->query_skill("buddhism",1) + 50);//禅宗心法
	me->set_skill("lamaism", me->query_skill("lamaism",1) + 50);//密宗心法
	me->set_skill("taoism", me->query_skill("taoism",1) + 50);//道家心法
	me->set_skill("mahayana", me->query_skill("mahayana",1) + 50);//大乘涅磐功
	me->set_skill("count", me->query_skill("count",1) + 50);//阴阳八卦
	me->set_skill("certosina", me->query_skill("certosina",1) + 50);//镶嵌技艺
	me->set_skill("drawing", me->query_skill("drawing",1) + 50);//绘画技巧
	
	
	
	me->set_skill("tanqin-jifa", me->query_skill("tanqin-jifa",1) + 50);//弹琴技法
	me->set_skill("chuixiao-jifa", me->query_skill("chuixiao-jifa",1) + 50);//吹箫技法
	me->set_skill("guzheng-jifa", me->query_skill("guzheng-jifa",1) + 50);//古筝技法
	
	me->set_skill("martial-cognize", me->query_skill("martial-cognize",1) + 50);//武学修养
	me->set_skill("sword-cognize", me->query_skill("sword-cognize",1) + 50);//剑法修养
	me->set_skill("craft-cognize", me->query_skill("craft-cognize",1) + 50);//兵法修养
	  }
	if ((me->query("combat_exp")-me->query("combat_exp"))>500000000)
                return notify_fail("你的exp超过5E这对你已经没用了"+ name() +"。\n");
      else {
		me->add("combat_exp",5000000);//修为
		me->add("magic_points",5000000);//灵慧
	  }
	
	write(YEL"你使用了一枚古钱，古钱化作一道灵光直入脑海中越发清晰！"NOR"\n");
	
	add_amount(-1);
	return 1;
}