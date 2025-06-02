inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void create()
{
	set_name("ˮ����Ƭ", ({"shuiyu suipian"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����ˮ����Ƭ��\n");
		set("base_unit", "Ƭ");
		set("base_weight", 10);
		set("base_value", 10000);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}

	set_amount(1);
	setup();
}

int do_effect(object me)
{
	object ob;

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	if (query_amount() < 10)
		return notify_fail("�����Ƭ����Ŷ��\n");

	if (objectp(ob = new(__DIR__"shuiyu")))
	{
		ob->move(me);
		write("��ϳ�����Ƭ�������һ��ˮ��\n");
		add_amount(-10);
	}
	else
	{
		return notify_fail("�ϳɳ�������ϵ����Ա����\n");
	}

	return 1;

}