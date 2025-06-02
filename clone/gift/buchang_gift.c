
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
	set_name("��ħ����С���", ({"buchang gift"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����С�����ħ�������л��Ҷ���Ϸ��֧�֣�ף����Ϸ��죡\n");
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
		"/clone/shizhe/jinsha":10,
	]);

	list = keys(gifts);

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");
	
	if (! me->query("born"))
return notify_fail("�㻹û�г����أ�������ȡ���\n");

	if (me->is_fighting())
		return notify_fail("ս���У�����ʹ��"+ name() +"��\n");
	if (me->query("buchang_times"))
		return notify_fail("�Ѿ�ʹ�ù��ˣ�����ʹ��"+ name() +"��\n");
	message_vision("$N����һ" + query("base_unit") + name() + "��\n", me);
	
	me->add("experience", 50000);
	me->add("potential", 50000);
	me->add("buchang_times",1);
	
	log_file("gift_all/buchang", me->query("name")+"("+me->query("id")+")��"
				+me->query("buchang_times")+"�δ���"+this_object()->short()+"   "+ctime(time())+"��\n");
	for(i=0;i<sizeof(list);i++)
	{
		obj = new(list[i]);
		if(obj->query_amount())
			obj->set_amount(gifts[list[i]]);
		tell_object(me, HIR"�㷢����"+NOR+obj->short()+NOR"��\n");
		obj->move(me);
	}
	tell_object(me, HIY"������5���ʵս��ᣬ5���Ǳ�ܡ�"NOR+HIG"��ħף����Ϸ��죡"NOR"\n");
	add_amount(-1);

	return 1;

}
