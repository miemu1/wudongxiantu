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
	set_name(HIY"顶级基础技能册"NOR, ({"foundation book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 100);
        set("no_sell",1);
        set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("unit", "本");
		set("base_unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","这是一本"HIG"技能书"NOR);
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
		
	me->set_skill("force", me->query_skill("force",1) + 50);//基本内功
	me->set_skill("dodge", me->query_skill("dodge",1) + 50);//基本轻功
	me->set_skill("parry", me->query_skill("parry",1) + 50);//基本招架
	me->set_skill("unarmed", me->query_skill("unarmed",1) + 50);//基本拳脚
	me->set_skill("cuff", me->query_skill("cuff",1) + 50);//基本拳法
	me->set_skill("strike", me->query_skill("strike",1) + 50);//基本掌法
	me->set_skill("finger", me->query_skill("finger",1) + 50);//基本指法
	me->set_skill("hand", me->query_skill("hand",1) + 50);//基本手法
	me->set_skill("claw", me->query_skill("claw",1) + 50);//基本爪法
	me->set_skill("sword", me->query_skill("sword",1) + 50);//基本剑法
	me->set_skill("blade", me->query_skill("blade",1) + 50);//基本刀法
	me->set_skill("staff", me->query_skill("staff",1) + 50);//基本丈法
	me->set_skill("hammer", me->query_skill("hammer",1) + 50);//基本锤法
	me->set_skill("club", me->query_skill("club",1) + 50);//基本棍法
	me->set_skill("whip", me->query_skill("whip",1) + 50);//基本鞭法
	me->set_skill("dagger", me->query_skill("dagger",1) + 50);//基本短兵
	me->set_skill("throwing", me->query_skill("throwing",1) + 50);//基本暗器
	
	
	
	
	write(YEL"看完这本小册子，突然恍然大悟，以前不明了的武学都在脑海里清晰起来了"NOR"\n");
	
	add_amount(-1);
	return 1;
}