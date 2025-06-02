inherit F_DBASE;

void start_fuben(object who);
void box_sign(object *temp_arr);
void link_room(mapping test);
void end_fuben(object me);

void start_fuben(object who)	//�ӿڣ��������������
{
    mapping test = ([]);
    mapping test_x;
    int x, y, i;
    object room, mem = new(__FILE__);
    object *temp_arr = ({});
    object shuiyu;
    
    if (!objectp(shuiyu = present("shui yu", who)) || !shuiyu->query("is_shuiyu"))
    {
        write("�������û��ˮ�񰡡�\n");
        return ;
    }
    shuiyu->add_amount(-1);
    
    who->delete_temp("open_bad_box");	//����ж��ļ�¼

    for(y = 0; y < 6; y++)
    {
    	test_x = ([]);
    	for(x = 0; x < 6; x++)
    	{
    		room = new(__DIR__"room");
    		room->set("coord", ({x, y}));
    		room->set("short", "����(" + x + "," + y + ")");
    		room->set("mem", mem);
    		test_x += ([x : file_name(room)]);
    		temp_arr += ({room});
    	}
    	test += ([y : test_x]);
    }
    box_sign(temp_arr);
    link_room(test);
    mem->set("room_map", test);
    mem->set("room_arr", temp_arr);
    mem->mem_set_heart_beat(1);
    mem->set("player", who);

    who->set_temp("huanjing_mem", mem);
    who->set("eff_qi", who->query("max_qi"));
    who->set("qi", who->query("max_qi"));
	who->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
    who->set_override("die", (: call_other, __FILE__, "check_out" :));
    who->move(temp_arr[random(sizeof(temp_arr))]);
}

void box_sign(object *temp_arr) //���ñ���
{
    int i;
    object temp_room;
    object box;

    for(i = 0; i < 10; i++)	//������Ʒ�ı��䣬���Ϊgift_sign
    {
    	temp_room = temp_arr[random(sizeof(temp_arr))];
    	if (objectp(box = new(__DIR__"obj/box")))
    	{
    		box->set("gift_sign", 1);
    		box->move(temp_room);
    	}
    	temp_arr -= ({temp_room});
    }

    for(i = 0; i < 20; i++)
    {
    	temp_room = temp_arr[random(sizeof(temp_arr))];
    	if (objectp(box = new(__DIR__"obj/box")))
    	{
    		box->move(temp_room);
    	}
    	temp_arr -= ({temp_room});
    }
}

void link_room(mapping test)	//���Ӹ�������
{
	int x, y;
	object room;
	mapping exits;
	
	for(y = 0; y < 6; y++)
	{
		for(x = 0; x < 6; x++)
		{
			exits = ([]);
			room = test[x][y];
			if((x - 1) >= 0)
			{
				exits += (["west" : test[x - 1][y]]);
			}
			if((x + 1) <= 5)
			{
				exits += (["east" : test[x + 1][y]]);
			}
			if((y - 1) >= 0)
			{
				exits += (["south" : test[x][y - 1]]);
			}
			if((y + 1) <= 5)
			{
				exits += (["north" : test[x][y + 1]]);
			}
			room->set("exits", exits);
		}
	}
}

void end_fuben(object me)
{
	object temp, *room_arr;
	object *objs, obj;
	
	room_arr = me->query("room_arr");
	
	me->query("player")->delete_temp("open_bad_box");
	foreach(temp in room_arr)
	{
		if (!temp || !clonep(temp))	continue;
		if (!objectp(temp))	continue;
		if (!objs = all_inventory(temp) || !arrayp(objs))	continue;
		
		foreach (obj in objs)
		{
			if (!objectp(obj))	continue;
			if (userp(environment(obj))) continue;
			if (userp(obj))
			{
				tell_object(obj, "���������ѱ����͵��㳡��\n");
				obj->move("/d/city/guangchang");
				continue;
			}
		}
		destruct(temp);
	}
    destruct(me);
}

int check_out(object me)
{
    object ob;
    mapping my;
    string msg;
    string room;

    if(!environment(me)->query("is_huanjing"))
    	return 0;

    me->delete_temp("open_bad_box");
    my = me->query_entire_dbase();
    my["eff_qi"] = my["max_qi"];
    my["eff_jing"] = my["max_jing"];
    my["qi"] = 1;
    my["jing"] = 1;

    tell_object(me, HIR "\n�������ǰһ��ģ��...�������ˣ�\n" NOR);
    if( ob = me->query_last_damage_from() )
            msg = WHT "\n$N��" + ob->name(1) + "������ˣ��Ǳ����ӣ�\n\n" NOR;
    else
            msg = WHT "\n$N�������ˣ��Ǳ����ӣ�\n\n" NOR;

    message_vision(msg, me);

    me->move("d/city/kedian");
    message("vision", "һ����Ӱٿ�Ĵ��˳������漴���ǡ�ž����"
            "һ�����ͼ�" + me->name() +"ˤ���˵��ϣ�һ��������"
            "������ӡ�\n", environment(me), ({ me }));
    tell_object(me, "�������У�����ñ���������������"
                "���ص�ˤ���˵��ϡ�\n");
    if( !living(me) )
            me->revive();

    me->query_temp("huanjing_mem")->end_fuben(me->query_temp("huanjing_mem"));

    return 1;
}

void huanjing_poison(object who)
{
	int damage;

	if (!environment(who)->query("is_huanjing"))
		return ;
	if (who->query_temp("open_bad_box"))
	{
		damage = who->query_temp("open_bad_box") * who->query("max_qi") / 100;
		who->receive_wound("qi", damage);
	}
}

int count = 0;

void heart_beat()
{
	object who = query("player");

	count++;
	if (count > 1800 || query("box_open_count") >= 10 || !environment(who)->query("is_huanjing"))
	{
		end_fuben(this_object());
		return ;
	}

	huanjing_poison(who);
}

void mem_set_heart_beat()
{
	set_heart_beat(1);
}