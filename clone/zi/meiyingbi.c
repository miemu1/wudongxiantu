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
	set_name(HIY"����ù�˽��"NOR, ({"mei coin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 0);
        set("no_sell",1);
        set("no_give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "ö");
		set("base_unit", "ö");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","�и����������㣬�������Ż����������\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    if (me->is_busy())
                return notify_fail("����æ���ء�\n");
	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+name()+"��\n");
		
		
	if(me->query("yuanbao") > -20000000){
		if (random(10)<=6){
	me->add("yuanbao",-500000);
	write(YEL"����֮һ�ĸ���-50Wyuanbao��"NOR"\n");
	}}
	if(me->query("jifeng") > -20000000){
	if (random(20)<=2){
	me->add("jifeng",-500000);
	write(YEL"����֮һ�ĸ���-50Wjifeng��"NOR"\n");
	}}
	if(me->query("tianji1") > -20000000){
	if (random(5)<=4){
	me->add("tianji1",-5000);
	write(YEL"����֮һ�ĸ���-5ktianji��"NOR"\n");
	}}
	
	
	
	if (random(40)==1){
	me->add("tianji1",10000);
	write(YEL"��ϲ����40��֮1�ĸ��ʻ����1������㣡"NOR"\n");
	}


	// me->add("zjvip/all_pay",1000000);
	// write(YEL"�����1000000�����ף�"NOR"\n");
	add_amount(-1);
	return 1;
}