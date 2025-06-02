inherit ITEM;

void create()
{
	set_name("����", ({ "box" }));
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����䡣\n");
		set("value", 1000);
		set("no_get",1);
		set("no_drop",1);
		set("do_not_clean_me", 1);
	}
	setup();
	set("action_list", ([
			"����" : "open_box " + file_name(this_object()),
			]));
}

void init()
{
	add_action("do_open_box", "open_box");
}

int do_open_box(string arg)
{
	string * gift_file = ({
		"/clone/gift/putao",
		"/clone/gift/putao",
		"/clone/vip/dan_chongmai1",
		"/clone/vip/dan_chongmai2",
		"/clone/vip/dan_chongmai3",
		"/clone/vip/dan_chongmai4",
		"/clone/vip/dan_chongmai1",
		"/clone/vip/putao1",
		"/clone/vip/butian",
        "/clone/gift/putao",
		"/clone/vip/jinsha",
		"/clone/vip/dan_chongmai4",
		"/clone/baiyi/hundunshi",
		"/clone/vip/dan_chongmai1",
		"/clone/baiyi/tencard",
		"/clone/gift/putao",
		"/clone/baiyi/onecard",
		"/clone/vip/dan_chongmai4",
		"/clone/baiyi/rendaoxianglian",
		"/clone/baiyi/didaoxianglian",
		"/clone/vip/dan_chongmai4",
		"/clone/baiyi/tiandaoxianglian",
		"/clone/1shimen",
		"/clone/vip/dan_chongmai2",
		
	});
	object gift;
	object who = this_player();

	if (arg != file_name(this_object()))
		return 0;

	if (query("open_sign"))
	{
		write("���Ѿ�������������ˡ�\n");
		return 1;
	}

	if (query("gift_sign"))
	{
		set("open_sign", 1);
		environment(who)->query("mem")->add("box_open_count", 1);
		if (who->query_temp("open_bad_box"))
			who->add_temp("open_bad_box", -1);

		if (objectp(gift = new(gift_file[random(sizeof(gift_file))])))
		{
			tell_object(who, "��ϲ������" + gift->query("name") + "��\n");
			gift->move(who);
			return 1;
		}
	}
	else
	{
		set("open_sign", 1);
		who->start_busy(5);
		if (!who->query_temp("open_bad_box"))
		{
			who->add_temp("open_bad_box", 1);
			tell_object(who, "��򿪵��Ǽٵı��䣬һ��������������ж��ˣ�\n");
			return 1;
		}
		else if(who->query_temp("open_bad_box") < 21)
		{
			who->add_temp("open_bad_box", 1);
			tell_object(who, "��򿪵��Ǽٵı��䣬���еĶ������ˡ�\n");
			return 1;
		}
	}

	return 1;
}