inherit ITEM;

void finish(object who);

void create()
{
	set_name(HIR"黄河钓竿"NOR, ({"diao gan"}));
	 set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "专用地址：【黄河入海口】，快捷指令：fish_yujing。\n");
		set("unit", "根");
		set("no_sell", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("value", 5000);
		set("tezhi", 1);
		set("action_list", ([
		"使用":"fish_yujing",
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
		write("你现在正忙，无法钓鱼。\n");
		return 1;
	}

	if (environment(who)->query("short") != "黄河入海口")
	{
		write("这里不能钓鱼丫。\n");
		return 1;
	}

	if ((who->query("nanan_fish_last_time") / 86400) != (time() / 86400))
	{
		who->delete("nanan_fish");
	}

	if (who->query("nanan_fish") >= 20)
	{
		write("你今天已经不能再钓鱼了。\n");
		return 1;
	}

	message_vision("$N轻轻一甩杆，只见水面上荡起了一个个圆圈，中间只有一个白色的浮子在随着水波荡漾。\n", who);
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
        tell_object(find_player("qianmu"), sprintf("测试节点%O\n二%O\n", who, environment(this_object())));
		who->delete_temp("fishing");
		who->delete_temp("fishing_sign");
		return 0;
    }
    
	if (environment(who)->query("short") != "黄河入海口")
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
		write("你身上没有特制钓竿。\n");
		return 0;
	}

	if (who->query_temp("finish_sign"))
	{
		who->add("nanan_fish", 1);
		who->delete_temp("fishing");
		who->delete_temp("finish_sign");
		who->delete_temp("fishing_count");
		tell_object(who, "鱼鳔剧烈抖动，你猛地一拉鱼竿。\n");
		finish(who);
		return 1;
	}

	if (who->query_temp("fishing_count") < 60)
	{
		if (who->query_temp("fishing_count") % 10 == 0)
			write("微风轻轻的吹，水面荡起一层层细浪，就是没有鱼上钩。\n");
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
	write("你停止了钓鱼。\n");
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
		write("你钓到了一只鱼精。\n");
		return ;
	}
	else
	{
		gift = new("/clone/jinli");
		if (objectp(gift))
		{
			gift->move(who);
			write("你什么也没钓到，但是竟在钓鱼的地上捡到了一颗金粒！\n");
			return ;
		}
	}
}
int query_autoload() { return 1; }