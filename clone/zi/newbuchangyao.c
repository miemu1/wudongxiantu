
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
	set_name(HIR "ת�������" NOR, ({ " buchangyao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���֮һ���ʴ����ʵ���ת�������ؼ�1��\n");
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

	if (me->query("zhuanshi") <= 0)
	{
		message_vision("���Ҳ�֪����ûת��ô����\n", me);
		tell_object(me, "���û�����ҩ��\n");
	} else
	if (random(5) ==1 /* && !me->query("special_skill/lucky") */)
	{
		tell_object(me, "���֮һ�����������С�ʵ���ŷ�������ܵõ����࣬��ά��������\n");
	      //me->add("gift/unknowdan_fail", 1);
		me->add("str",1)+(me->query("zhuanshi")*2/3);//����
		me->add("int",1)+(me->query("zhuanshi")*2/3);//����
		me->add("dex",1)+(me->query("zhuanshi")*2/3);//��
		me->add("con",1)+(me->query("zhuanshi")*2/3);//����
		
	} else
	{
		tell_object(me, HIM "��֮ǰת�����˵Ĳ�����"NOR"\n");
		me->set("gift/shenliwan",0);//ɾ������ҩ����
		me->set("gift/xiandan",0);//ɾ������ҩ����
		me->set("gift/unknowdan",0);//ɾ����ҩ����
		me->set("gift/xisuidan",0);//ɾ������ҩ����
		write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"���ó�ҩ�����ɹ�"NOR"\n");
	
	}

	add_amount(-1);
      return 1;
}


