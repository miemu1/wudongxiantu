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
	set_name(HIR"【天 籁 箴 言】"NOR, ({"zhengdao yueli book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 9500000);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","【以 音 证 道】\n");
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

	me->set_skill("mingyue-blade", me->query_skill("mingyue-blade",1) + 180);//天涯明月刀
	me->set_skill("doomforce", me->query_skill("doomforce",1) + 180);//吹雪神功
	me->set_skill("wuyun-jianfa", me->query_skill("wuyun-jianfa",1) + 280);//五韵七弦剑
	me->set_skill("xiyu-tiezheng", me->query_skill("xiyu-tiezheng",1) + 180);//西域铁筝音
	me->set_skill("taohua-yuan", me->query_skill("taohua-yuan",1) + 180);//桃花怨
	me->set_skill("qingxin-pushan", me->query_skill("qingxin-pushan",1) + 180);//清心普善咒
	
	write(YEL"读完，手中小册化为一阵天籁鸣音萦绕耳畔"NOR"\n");
	
	add_amount(-1);
	return 1;
}