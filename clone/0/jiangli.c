// jiuzhuan.c ��ת��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "��ɱ��" NOR, ({ "jisha jiangli"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������ս��ɱ�󽱣�ʹ�ÿɻ����ʯ�͵�ȯ��\n");
		set("spectxt", "��������������ԡ�\n");
		set("value", 500);
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
	int effect;
	 mapping my;

	log_file("static/using", sprintf("%s(%s) eat ��ɱ�� at %s.\n",
		 me->name(1), me->query("id"), ctime(time())));

	effect = 0;
	message_vision("$N����" + this_object()->name() +
		       "��\n", me);

	write(HIM "����100��ʯ��500��ȯ��"NOR"\n");
	me->add("yuanbao", 100);
	me->add("jifeng", 500);

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }