inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIC"ǧ����֥"NOR, ({"ling zhi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100000);
		set("yuanbao", 20);
        set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);		
		set("unit", "��");
		set("long","����һ��ǧ����֥��"ZJURL("cmds:fu1 ling zhi")ZJSIZE(20)"����"NOR"��֥������(30-60)��������Ϊ��\n");
	}
}

void init()
{
    if (environment()==this_player())
    	add_action("do_use","fu1");
}

int do_use(string arg)
{
	int n;
	object me=this_player();

	if (arg!="ling zhi")
      		return notify_fail("��Ҫ����ʲô?\n");  

	n = 30+random(30);
    me->add("zjvip/lingzhi_num2",1);
	me->add("max_neili", n);
    message_vision(YEL+me->query("name")+"����һ��"HIC"ǧ����֥"YEL"���پ���������("+n+")��"NOR"\n",me);

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }