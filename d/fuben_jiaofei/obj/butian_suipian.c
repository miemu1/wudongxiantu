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
	set_name(HIW"����ʯ��Ƭ"NOR, ({"butian suipian", "suipian"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "��");
		set("base_weight", 1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("base_value", 8000000);
		set("long","����ʯ����Ƭ��ò�ƿ��Ժϳ�(hecheng suipian)��\n");
        set("only_do_effect", 1);
	}
	set_amount(1);
	setup();
}

int do_effect(object me)
{
	if(query_amount() < 10)
	{
		tell_object(me, "�����Ƭ��������Ŷ���Ͻ�����ռ��ɣ�\n");
		return 1;
	}
	else if(random(2))
	{	
		new(__DIR__"butian")->move(me);
		tell_object(me, "��ƴ���Ų���ʯ��ͻȻ������Ƭɢ����ʹ�ԣ����������һ�鲹��ʯ��\n");
		message("vision", "�㿴��" + me->name() + "ƴ���Ų���ʯ��Ƭ��ͻȻ��Ƭ������ʹ�ԣ�" + me->name() + "�ϳɳ��˲���ʯ��\n", environment(me), ({me}) );
		add_amount(-10);
		return 1;
	}
	
	tell_object(me, "�ϳ�ʧ�ܡ�\n");
	add_amount(-10);
	return 1;
}