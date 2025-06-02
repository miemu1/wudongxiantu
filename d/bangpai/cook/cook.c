#define VEGDIR "/d/bangpai/plant/seed/veg/"
#define FOODDIR "/d/bangpai/cook/food/"
#define MEAT_DIR "/d/bangpai/farm/meat/"

int test();
int do_cook(string arg, object who, object room);
int cooking(object who, object room);
int do_halt_cooking(string arg, object who);
void finish_cook(object who);


int do_cook(string arg, object who, object room)
{
	string temp, str;
	string *food_file;
	object food, veg;
	mapping food_need;
	
	if (who->query_temp("cook/sign"))
	{
		write("��������������ء�\n");
		return 1;
	}
	
	if (!arg || arg == "")
	{
		str =  ZJOBLONG + "��Ҫ��ʲôʳ�\n" + ZJOBACTS2;
		food_file = list_dirs(FOODDIR + "*.c");
		foreach(temp in food_file)
		{
			str += (FOODDIR + temp)->query("name") + ":cook " +  base_name(load_object(FOODDIR + temp)) + ZJSEP;
		}
		write(str + "\n");
		return 1;
	}
	
	if (!objectp(food = new(arg)))
	{
		write("����ʧ�ܡ�" + arg + "\n");
		return 1;
	}
	
	if (!mapp(food_need = food->query("need")) && !sizeof(food_need))
	{
		write("ʳ���زĻ�ȡʧ�ܣ�����ʧ�ܡ�\n");
		return 1;
	}
	
	foreach(temp in keys(food_need))
	{
		if (!objectp(veg = present(temp, who)))
		{
			if (!objectp(veg = load_object(MEAT_DIR + temp)))
			    veg = load_object(VEGDIR + temp);
			
			write("������û��" + veg->query("name") + "ѽ��\n");
			return 1;
		}
		else
		{
    		if (veg->query_amount() < food_need[temp])
    		{
    			write("�㻹ȱ��" + (food_need[temp] - veg->query_amount()) + "��" + veg->query("name") + "�����������ˡ�\n");
    			return 1;
    		}
    	}
	}
	
	foreach(temp in keys(food_need))
	{
		if (objectp(veg = present(temp, who)))
			veg->add_amount(-food_need[temp]);
	}
	
	who->set_temp("cook/food", food);
	who->set_temp("cook/sign", 1);
	who->start_busy((cooking(who, room)));
	
	return 1;
}

int cooking(object who, object room)
{
	string str;
	int finish;
	
	if (environment(who) != room)
	{
		do_halt_cooking("y", who);
		return 0;
	}
	
	if (!who->query_temp("cook/sign"))
		return 0;
	
	if (! who->query_temp("cook/step"))
		who->set_temp("cook/step", 1);

	if (! living(who))
	{
		who->delete_temp("cook/step");
		return 0;
	}
	
	finish = 0;
	switch(who->query_temp("cook/step"))
	{
		case 1 : 
			str = "�������������Ҫ��ʳ�Ŀ�ʼ����������\n";
			break;
		case 5 :
			str = "��������\n";
			break;
		case 10 : 
			str = "�㿪ʼ���ʳ���\n";
			break;
		case 20 :
			finish = 1;
			str = "���������⿣�����˲��ȡ�\n";
	}
	if(str)
		write(str);
	
	if(finish)
	{
		who->query_temp("cook/food")->move(who);
		who->delete_temp("cook");
		return 1;
	}
	who->add_temp("cook/step", 1);
	call_out((: $1->start_busy((cooking($2, $3))) :), 1, who, who, room);
	return 1;
}


int do_halt_cooking(string arg, object who)
{
	object food, veg;
	mapping food_need;
	string temp;
	
	if (!who->query_temp("cook/sign"))
	{
		write("������û�н������Ŷ��\n");
		return 1;
	}
	
	if (arg != "y")
	{
		write(ZJOBLONG + "��ȷ��Ҫֹͣ��⿣�\n" + ZJOBACTS2 + "ȷ��:halt_cooking y\n");
		return 1;
	}
	
	if (objectp(food = who->query_temp("cook/food")))
	{
		if (mapp(food_need = food->query("need")))
		{
        	foreach(temp in keys(food_need))
        	{
        		if (objectp(veg = present(temp, who)))
        			veg->add_amount(food_need[temp]);
        	}
        }
		destruct(food);
	}
	write("��ֹͣ��ʳ���������\n");
	who->delete_temp("cook");
	return 1;
}