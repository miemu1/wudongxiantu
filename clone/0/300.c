
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
	set_name(HIY"300����" NOR, ({"300gift"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��л����֧�֣����ǻ����Ŭ����\n");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1000);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
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
			"/clone/vip2/dan_chongmai2":1000,	//1��������
		"/clone/vip2/dan_chongmai1":1000,
			"/clone/vip2/dan_chongmai3":1000,	//1��������
		"/clone/0/shimen1":5,	//��Ʒ����
		"/clone/vip2/putao1":1000,			//1����
		"/clone/vip2/dan_jiuzhuan":1000,
			"/clone/aaa/yajin/neili_dan1":2,	//1��������
		"/clone/aaa/smczl":3,	//ʦ�ſ�
		"/clone/0/1000xue":50,    //�ϵ�
	]);

	list = keys(gifts);

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("ս���У�����ʹ��"+ name() +"��\n");

	message_vision("$N����һ" + query("base_unit") + name() + "��\n", me);
	me->add("vip_box_times",1);
	me->add("yuanbao",60000);
	write(YEL"����60000��ʯ!"NOR"\n");

	log_file(me,"vipbox","��"+me->query("vip_box_times")+"�δ���"+this_object()->short()+"��\n");
	for(i=0;i<sizeof(list);i++)
	{
		obj = new(list[i]);
		if(obj->query_amount())
			obj->set_amount(gifts[list[i]]);
		tell_object(me,"�㷢����"+obj->short()+"��\n");
		obj->move(me);
	}
	add_amount(-1);

	return 1;

}
