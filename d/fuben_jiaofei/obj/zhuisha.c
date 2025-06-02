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
	set_name(HIW"׷ɱ��"NOR, ({"zhuisha ling", "zhuisha"}));
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 10000);
		set("long","����׷ɱ�ʹ�ú��ܹ����"NOR"��ǰ��ͽnpc�ľ�ȷλ�ã�\n");
	}
	set_amount(1);
	setup();
}

void init()
{
    if (environment()==this_player())
    	add_action("on_used","use");
}

int on_used(string arg)
{
	int i = 0;
	object who, temp;
	object *npc_obj;
	string area;
	
	if (arg != "zhuisha ling")
		return notify_fail("��Ҫʹ��ʲô��\n");
	
	who = this_player();
	if (!(environment(who)->query("is_fuben")))
	{
		tell_object(who, "׷ɱ��ֻ���ڽ˷˸�����ʹ�á�\n");
		return 1;
	}
	
	npc_obj = (who->query_temp("fb_mem"))->query("npc_obj");
	foreach(temp in npc_obj)
	{
		if(temp && objectp(temp) && environment(temp))
		{
			sscanf(base_name(environment(temp)),"/d/%s/%*s",area);
			message("shout", ZJOBLONG + "(" + who->name() + "ʹ����׷ɱ��) ��ͽ���ڵĵص�Ϊ" + MAP_D->query_map_short(area) + "��" + environment(temp)->query("short") + "��\n", (who->query_temp("fb_mem"))->query("team"));
			message("shout", "(" + who->name() + "ʹ����׷ɱ��) ��ͽ���ڵĵص�Ϊ" + MAP_D->query_map_short(area) + "��" + environment(temp)->query("short") + "��\n", (who->query_temp("fb_mem"))->query("team"));
			break;
		}
		i += 1;
		if(i == sizeof(npc_obj))
			tell_object(who, "�޷���ѯ����ͽ���ڣ������Ѿ���ȫ��ɱ����\n");
	}
	add_amount(-1);
	return 1;
}