// jiuzhuan.c ��ת��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "�߼�ս��" NOR, ({ "zhanling card"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ʹ�ô˿����Խ����߼�ս��Ӷ���ȡ������\n");
		set("spectxt", "ע��ֻ�Ե�ǰ������Ч��\n");
		set("value", 1);
		set("unit", "��");
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            //set("no_put",1);
		set("only_do_effect", 1);
		set("suit_point",300);
				set("yuanbao", 100000);
	}
}

int do_effect(object me)
{
	int effect;
	 mapping my;



	effect = 0;
	message_vision("$Nʹ����һ��" + this_object()->name() +
		       "��\n", me);

	write(HIM "��ϲ������˸߼�ս�����ȡ�ʸ�"NOR"\n");
	me->set("zhanling/goumai", 10);

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }