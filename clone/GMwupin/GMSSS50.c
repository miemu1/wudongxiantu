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
	set_name(HIM"超级灵石卡"NOR, ({"lss4 dai"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"以小博大，赌狗专属！有概率【空】卡\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 100);
		set("yuanbao", 10);
        set("no_sell", 1);
		set("no_put",1);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_steal",1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int i,ob1;

    if (me->is_busy())
           return notify_fail("你正忙着呢。\n");
i=random(40);
if (i<1){
me->add("yuanbao",5000);
message_vision(HIR"$N获得了5000灵石！"NOR"\n", me, this_object());
}
if (i>=2 && i<3){
me->add("yuanbao",4000);
message_vision(HIR"$N获得了4000灵石！"NOR"\n", me, this_object());
}
if (i>=4 && i<5){
me->add("yuanbao",3000);
message_vision(HIR"$N获得了3000灵石！"NOR"\n", me, this_object());
}
if (i>=6 && i<7){
me->add("yuanbao",2500);
message_vision(HIR"$N获得了2500灵石！"NOR"\n", me, this_object());
}
if (i>=8 && i<9){
me->add("yuanbao",2000);
message_vision(HIR"$N获得了2000灵石！"NOR"\n", me, this_object());
}
if (i>=10 && i<11){
me->add("yuanbao",1500);
message_vision(HIR"$N获得了1500灵石！"NOR"\n", me, this_object());
}
if (i>=12 && i<13){
me->add("yuanbao",1000);
message_vision(HIR"$N获得了1000灵石！"NOR"\n", me, this_object());
}
if (i>=14 && i<15){
me->add("yuanbao",750);
message_vision(HIR"$N获得了750灵石！"NOR"\n", me, this_object());
}
if (i>=16 && i<17){
me->add("yuanbao",500);
message_vision(HIR"$N获得了500灵石！"NOR"\n", me, this_object());
}
if (i>=18 && i<19){
me->add("yuanbao",250);
message_vision(HIR"$N获得了250灵石！"NOR"\n", me, this_object());
}
	add_amount(-1);
	return 1;

}
