inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "������\n");

	set("action_list", ([
		"����" : "test",
		]));
	
	setup();
}

void init()
{
	add_action("do_test", "test");
	add_action("do_test2", "test2");
	add_action("do_dest_item", "dest_item");
}

int do_test2()
{
	tell_room(this_object(), "���������\n"NOR);
	return 1;
}

int do_test(string arg)
{
	object who = this_player();
    object room;

mapping id = ([

"1�˺�" : "chilly27",
"2�˺�" : "egg579aa1",
"3�˺�" : "cdm106",
"4�˺�" : "a101100",
"5�˺�" : "g2585729683",
"6�˺�" : "yjn19158217",
"7�˺�" : "w111111111",
"8�˺�" : "g3584721",
"9�˺�" : "meloding",
"10�˺�" : "wzwzwz1103",
"11�˺�" : "z948653949",
"12�˺�" : "chufengliu",
"13�˺�" : "rubina",
"14�˺�" : "zhuao",
"15�˺�" : "yygysss",
"16�˺�" : "a2273099224",
"17�˺�" : "h847681409",
"18�˺�" : "jn01",
]);
    string temp;

    foreach(temp in values(id))
    {
        log_file("id_buchang", "\"" + temp + "\",\n");
    }


    
	// who->start_busy((: call_other, __FILE__, "start" :),
	// 				(: call_other, __FILE__, "end" :));
    //room = new("/d/jingjichang/room");
    //who->move(room);
	//"/d/fuben_huanjing/huanjing"->start_fuben(who);
	return 1;
}

int start()
{
	return 1;
}

int end()
{
	write("��ֹͣ�ˡ�\n");
	return 1;
}

int do_dest_item(string arg)
{
    object * obs;
    object temp;
    
    obs = children(arg);
    foreach(temp in obs)
    {
        log_file("xxxxxxxxx", "�������" + sprintf("%O\n",all_inventory(temp)) + "��\n");
        
        //temp->end_fuben_moku();
        //destruct(temp);
    }
}