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
	set_name(HIR"【六道仙经】"NOR, ({"lunhui book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 100);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long"," 相传，六道仙经的原形来源于少林禅宗，乃少林高僧修炼。后经过几代相传，中途又展转流入天竺、西域等地，经无数武学高手及参悟及演化，最终创出六道仙经。\n");
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
if(me->query_skill("lunhui-sword") > 350)
			return notify_fail("你等级太高了已经无法提升了。\n");
		else {
	me->set_skill("lunhui-sword", me->query_skill("lunhui-sword",1) + 25);
	write(YEL"你学会了六道仙经"NOR"\n");
	write(YEL"相传佛家隐藏着一种极其厉害的攻伐之术—六道仙经，此术乃佛家攻伐术法最高境界，也是佛门武学最高境界。"NOR"\n");
	
	add_amount(-1);
		return 1;}
}