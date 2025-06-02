inherit ITEM;

void finish(object who);

void create()
{
	set_name(HIR"�������"NOR, ({"diao gan"}));
	 set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "��������ר�ã����ָ�fish_yujing��\n");
		set("unit", "��");
		set("no_sell", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("value", 5000);
		set("tezhi", 1);
		set("action_list", ([
		"ʹ��":"fish_yujing",
		]));
	}

	setup();
}

void init()
{
	if (interactive(this_player()) &&
	    environment() == this_player())
	{
		add_action("do_fish_yujing", "fish_yujing");
	}
}

int do_fish_yujing()
{
	object who = this_player();

	if (who->is_busy() || who->is_fighting())
	{
		write("��������æ���޷����㡣\n");
		return 1;
	}

	if (environment(who)->query("short") != "����")
	{
		write("���ﲻ�ܵ���Ѿ��\n");
		return 1;
	}

	if ((who->query("nanan_fish_last_time") / 86400) != (time() / 86400))
	{
		who->delete("nanan_fish");
	}

	if (who->query("nanan_fish") >= 20)
	{
		write("������Ѿ������ٵ����ˡ�\n");
		return 1;
	}

	message_vision("$N����һ˦�ˣ�ֻ��ˮ���ϵ�����һ����ԲȦ���м�ֻ��һ����ɫ�ĸ���������ˮ��������\n", who);
	who->start_busy((: call_other, __FILE__, "fishing" :), (: call_other, __FILE__, "halt_fish" :));
	who->set_temp("fishing", 1);
	who->set_temp("finish_sign", 0);
	who->set("nanan_fish_last_time", time());

	return 1;
}

int fishing(object who)
{
	object diaogan;
    
    if (objectp(environment()) && environment()->query("short"))
    {
        tell_object(find_player("qianmu"), sprintf("���Խڵ�%O\n��%O\n", who, environment(this_object())));
		who->delete_temp("fishing");
		who->delete_temp("fishing_sign");
		return 0;
    }
    
	if (environment(who)->query("short") != "����")
	{
		who->delete_temp("fishing");
		who->delete_temp("fishing_sign");
		return 0;
	}

	if (!who->query_temp("fishing"))
	{
		who->delete_temp("fishing_count");
		who->delete_temp("fishing_sign");
		return 0;
	}

	if (!objectp(diaogan = present("diao gan", who)) || !diaogan->query("tezhi"))
	{
		who->delete_temp("fishing");
		who->delete_temp("finish_sign");
		who->delete_temp("fishing_count");
		write("������û�����Ƶ��͡�\n");
		return 0;
	}

	if (who->query_temp("finish_sign"))
	{
		who->add("nanan_fish", 1);
		who->delete_temp("fishing");
		who->delete_temp("finish_sign");
		who->delete_temp("fishing_count");
		tell_object(who, "�������Ҷ��������͵�һ����͡�\n");
		finish(who);
		return 1;
	}

	if (who->query_temp("fishing_count") < 60)
	{
		if (who->query_temp("fishing_count") % 10 == 0)
			write("΢������Ĵ���ˮ�浴��һ���ϸ�ˣ�����û�����Ϲ���\n");
		who->add_temp("fishing_count", 1);
	}
	else
	{
		who->set_temp("finish_sign", 1);
		return 1;
	}

	return 1;
}

int halt_fish(object who)
{
	who->delete_temp("fishing");
	who->delete_temp("finish_sign");
	who->delete_temp("fishing_count");
	write("��ֹͣ�˵��㡣\n");
	return 1;
}

void finish(object who)
{
	object gift;
	object yujing;

	if (random(10) < 2)
	{
		yujing = new(__DIR__"yujing");
		yujing->move(environment(who));
		yujing->set("player_id", who->query("id"));
		write("�������һֻ�㾫��\n");
		return ;
	}
	else
	{
		gift = new("/clone/jinli");
		if (objectp(gift))
		{
			gift->move(who);
			write("��ʲôҲû���������Ǿ��ڵ���ĵ��ϼ���һ�Ž�����\n");
			return ;
		}
	}
}
int query_autoload() { return 1; }