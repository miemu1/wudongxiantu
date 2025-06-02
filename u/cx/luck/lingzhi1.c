#include <ansi.h>
inherit COMBINED_ITEM;
int do_use(string arg);
string query_autoload()
 { return query_amount() + ""; }

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
	set_name(HIC"ǧ����֥"NOR, ( {"ling zhi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value", 100000);
		set("yuanbao", 20);
		set("no_sell",1);
		set("unit", "��");
		set("long","����һ��ǧ����֥��"ZJURL("cmds:fu ling zhi")ZJSIZE(20)"����"NOR"��֥������100��������Ϊ��ע��ÿ��ֻ�ܷ���һ�Ρ�\n");
		set("base_weight", 200);
	}
	setup();
}

void init()
{
	if (environment()==this_player())
		add_action("do_use","fu");
}

int do_use(string arg)
{
	object me=this_player();
	object ob1;
	int times;
	mixed *local,*last;

	if (arg!="ling zhi")
		return notify_fail("��Ҫ����ʲô?\n");

	if (me->query("day_item/lingzhi/last_time"))
	{
		last = localtime(me->query("day_item/lingzhi/last_time"));
		times = me->query("day_item/lingzhi/times");

		if(last[7]!=localtime(time())[7])
			me->set("day_item/lingzhi/times",0);
		else if(last[7]==localtime(time())[7]&&times>=1)
		{
			message_vision(me->query("name")+"�����Ѿ�ʹ�ù�"+this_object()->query("name")+"�ˡ�"NOR"\n",me);
			return 1;
		}
	}

	me->set("day_item/lingzhi/last_time",time());
	me->add("day_item/lingzhi/times",1);

	me->add("zjvip/lingzhi_num",1);
	me->add("max_neili", 100);
	message_vision(YEL+me->query("name")+"����һ��"HIC"ǧ����֥"YEL"���پ�����������"NOR"\n",me);

	add_amount(-1);
	return 1;
}

