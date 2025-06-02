
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
	set_name("���ֵ��С���", ({"dan gift"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�ں��󶨵�4�ž�ת��4���Ե���һ�ţ�\n");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1000);
		set("yuanbao", 1120);		
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("tejia", 1);		
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i;
	mapping gifts;
	string *list;
	object obj;

	gifts = ([
		"/clone/vip/vip2/dan_jiuzhuan":4,
		"/clone/vip/vip2/dan_int":1,
		"/clone/vip/vip2/dan_str":1,
		"/clone/vip/vip2/dan_dex":1,
		"/clone/vip/vip2/dan_con":1,								
	]);

	list = keys(gifts);
    if(me->query("box_xinshou"))
		return notify_fail("ʹ�ù��˱����ˣ�������ʦ�˻���\n");
		
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("ս���У�����ʹ��"+ name() +"��\n");

	message_vision("$N����һ" + query("base_unit") + name() + "��\n", me);
	for(i=0;i<sizeof(list);i++)
	{
		obj = new(list[i]);
		if(obj->query_amount())
			obj->set_amount(gifts[list[i]]);
		tell_object(me,"�㷢����"+obj->short()+"��\n");
		obj->move(me);
		me->set("box_xinshou",1);
	}
	add_amount(-1);

	return 1;

}
