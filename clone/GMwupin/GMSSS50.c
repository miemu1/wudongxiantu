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
	set_name(HIM"������ʯ��"NOR, ({"lss4 dai"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"��С���󣬶Ĺ�ר�����и��ʡ��ա���\n"NOR);
		set("unit", "��");
		set("base_unit", "��");
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
           return notify_fail("����æ���ء�\n");
i=random(40);
if (i<1){
me->add("yuanbao",5000);
message_vision(HIR"$N�����5000��ʯ��"NOR"\n", me, this_object());
}
if (i>=2 && i<3){
me->add("yuanbao",4000);
message_vision(HIR"$N�����4000��ʯ��"NOR"\n", me, this_object());
}
if (i>=4 && i<5){
me->add("yuanbao",3000);
message_vision(HIR"$N�����3000��ʯ��"NOR"\n", me, this_object());
}
if (i>=6 && i<7){
me->add("yuanbao",2500);
message_vision(HIR"$N�����2500��ʯ��"NOR"\n", me, this_object());
}
if (i>=8 && i<9){
me->add("yuanbao",2000);
message_vision(HIR"$N�����2000��ʯ��"NOR"\n", me, this_object());
}
if (i>=10 && i<11){
me->add("yuanbao",1500);
message_vision(HIR"$N�����1500��ʯ��"NOR"\n", me, this_object());
}
if (i>=12 && i<13){
me->add("yuanbao",1000);
message_vision(HIR"$N�����1000��ʯ��"NOR"\n", me, this_object());
}
if (i>=14 && i<15){
me->add("yuanbao",750);
message_vision(HIR"$N�����750��ʯ��"NOR"\n", me, this_object());
}
if (i>=16 && i<17){
me->add("yuanbao",500);
message_vision(HIR"$N�����500��ʯ��"NOR"\n", me, this_object());
}
if (i>=18 && i<19){
me->add("yuanbao",250);
message_vision(HIR"$N�����250��ʯ��"NOR"\n", me, this_object());
}
	add_amount(-1);
	return 1;

}
