// jiuzhuan.c ��ת��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "1������ս���" NOR, ({ "1ji"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��ͨ�����ս������ﵽս��ȼ���ȡ�Ľ�����\n");
		set("spectxt", "��������������ԡ�\n");
		set("value", 5000000);
		set("jifeng", 500);
		set("unit", "��");
            set("no_shop",1);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            //set("no_put",1);
		set("only_do_effect", 1);
		set("suit_point",300);
	}
}

int do_effect(object me)
{
	object obj1,obj2,obj3;
	int effect;
	 mapping my;


	effect = 0;
	message_vision("$N����" + this_object()->name() +
		       "��\n", me);

	write(HIM "����1��˫����ȯ����"NOR"\n");
//	me->add("yuanbao", 20);
//	me->add("jifeng", 20);
        obj1 = new("/clone/0/jifen");
        obj1->move(me);
		
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }