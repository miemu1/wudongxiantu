inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY"��Դ��"NOR, ({"fuyuan dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1000000);         
		set("unit", "��");
		set("yuanbao", 800);

		set("long","����һ�Ÿ�Դ����ʹ��֮��������Ӹ�Դ��\n");
		set("only_do_effect", 1);
	}
}


int do_effect(object me)
{
      if (me->query("kar")>99) return notify_fail("��������Ѿ��ܺ��ˣ�\n");

	me->add("kar",1+random(3));

      if (me->query("kar")>100) me->set("kar",100);

	write(YEL"�������һ"+ query("unit") + name() +YEL"����ĸ�Դ�����ˣ�"NOR"\n�����ڵĸ�Դ�ǣ�"+me->query("kar")+"��"NOR"\n");
	
	me->save();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }