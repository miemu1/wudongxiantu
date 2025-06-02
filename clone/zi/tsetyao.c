
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
	set_name(HIR "��άҩ����" NOR, ({ " siyaoyao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ת����ҿ��Է��ã����֮һ�ĸ��ʿ��Դ����ʵ���������ת���Ѫ׬����\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 10000);
		set("tianji1", 150);
        set("no_sell", 1);
		set("give",1);
        set("drop",1);
        set("get",1); 
		set("suit_point", 300);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$Nһ������������һ" + query("unit") + name() + "��\n", me);

	
	
		tell_object(me, "ŷ�������ܵõ����࣬��ά��������\n");
	      //me->add("gift/unknowdan_fail", 1);
		me->add("str",5)+(me->query("zhuanshi")*2/3);//����
		me->add("int",5)+(me->query("zhuanshi")*2/3);//����
		me->add("dex",5)+(me->query("zhuanshi")*2/3);//��
		me->add("con",5)+(me->query("zhuanshi")*2/3);//����
		
	
	
	

	add_amount(-1);
      return 1;
}


