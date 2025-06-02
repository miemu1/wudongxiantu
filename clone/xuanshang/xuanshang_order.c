inherit ITEM;

#define XUANSHANGD "/adm/daemons/xuanshangd"

void create()
{
	set_name("������", ({"xuanshang ling"}));
	set("long", "�����\n");

	set("unit", "��");
	setup();
}

string query_autoload() { return query("xuanshang_name") + "|" + query("xuanshang_id"); }


void destruct_this_order(string xuanshang_id)
{
	mapping xuanshang;

	if (!sizeof(xuanshang = XUANSHANGD->get_xuanshang()))
	{
		destruct(this_object());
	}

	if (undefinedp(xuanshang[xuanshang_id]))
	{
		destruct(this_object());
	}
}

void autoload(string param)
{
	string xuanshang_id;
	string xuanshang_name;

	if (sscanf(param, "%s|%s", xuanshang_name, xuanshang_id) != 2)
	{
		destruct(this_object());
		return ;
	}

	call_out("destruct_this_order", 1, xuanshang_id);

    set_name(xuanshang_name + "������", ({ xuanshang_id + "-order" }));
    set("xuanshang_name", xuanshang_name);
    set("xuanshang_id", xuanshang_id);
}

void destruct_all_order()
{
	object * order;
	object temp;

	order = filter_array(children(base_name(this_object())), (: $1->query("xuanshang_id") == this_object()->query("xuanshang_id") :));
	if (sizeof(order))
	{
		foreach(temp in order)
		{
			if (temp == this_object())
				continue;

			destruct(temp);
		}
		destruct(this_object());
	}
}

void finish_xuanshang(object killer, object victim)
{
	mapping xuanshang = XUANSHANGD->get_xuanshang();
	int money;

	if (!sizeof(xuanshang) || undefinedp(xuanshang[victim->query("id")]))
	{
		call_out("destruct_all_order", 1);
		return ;
	}

	if (!money = xuanshang[victim->query("id")][1])
	{
		tell_object(killer, "��ȡ�����������ϵ����Ա����\n");
		call_out("destruct_all_order", 1);
		return ;
	}

	log_file("xuanshang/finish", ctime(time()) + killer->query("name") + "(" + killer->query("id") + ")��ɻ�ɱ" + victim->query("name") + "(" + 
		victim->query("id") + ")���񣬽���" + money + "���ƽ�\n");
	tell_object(killer, "������˻�ɱ" + victim->query("name") + "���������񣬻����" + money + "���ƽ�\n");
	killer->add("balance", money * 10000);
	XUANSHANGD->delete_xuanshang(victim->query("id"));
	call_out("destruct_all_order", 1);
}