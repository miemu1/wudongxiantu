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
	set_name(HIW"�����Ϊ��"NOR, ({"exp dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 5000);
		set("base_value", 5000);	
		set("sc_exp",1);	
		set("yuanbao", 500);        
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);		
	    set("long","����һ�������Ϊ��������Ϊ�������5000����Ϊֵ\n");	
	}
	setup();
}

