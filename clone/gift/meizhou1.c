
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
	set_name(HIW"每周礼包"NOR, ({"meizhou libao1"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "巫师白的财产！\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i,num1,num2,num3,num4;
	object gong,jiuzhuan,jian;

	if (me->is_busy())
		return notify_fail("你在忙没时间！！AWA。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	gong = new("/clone/shizhe/tianling3");
	gong->set_amount(2);
	write(YEL"恭喜您：获得了"+gong->short()+"。"NOR"\n");
	gong->move(me);
	jian = new("/clone/vip3/kuilei");
	jian->set_amount(3);
	write(YEL"恭喜您：获得了"+jian->short()+"。"NOR"\n");
	jian->move(me);
	jiuzhuan = new("/clone/vip3/jiuzhuan");
    write(YEL"恭喜您：获得了"+jiuzhuan->short()+"。"NOR"\n");
	jiuzhuan->move(me);
	
	
	add_amount(-1);
	me->save();
	

	return 1;
}
