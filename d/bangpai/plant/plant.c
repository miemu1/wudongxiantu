int kaitong(object who, string arg)
{
	if(arg != "y")
	{
		write(ZJOBLONG + "��ȷ��Ҫ��ͨ��԰�����𣿣���Ҫ200���ӣ�\n" + ZJOBACTS2 + "ȷ��:kaitong y\n");
		return 1;
	}
	
	if (!PLANTVEG_D->query_kaitong(who))
	{
		write("���Ѿ���ͨ��԰�����ˡ�\n");
		return 1;
	}
	
	if(!MONEY_D->player_pay(who, 2000000))
	{
		write("���Ǯû��ô���ˣ�\n");
		return 1;
	}
	
	if(!PLANTVEG_D->create_player_caidi(who))
	{
	    write("��ɹ���ͨ�˲�԰���ܡ�\n");
	    return 1;
	}
	return 1;
}

int kuojian(object who, string arg)
{
	int count;
	
	if(arg != "y")
	{
		write(ZJOBLONG + "��ȷ��Ҫ�����˵��𣿣���Ҫ200���ӣ�\n" + ZJOBACTS2 + "ȷ��:kuojian y\n");
		return 1;
	}
	
	if ((count = pow(who->query("combat_exp") * 10, 0.3333333)/100 + 4) <= (PLANTVEG_D->query_caidi_count(who)))
	{
		write("�㵱ǰֻ��ӵ��" + count + "��ء�\n");
		return 1;
	}
	
	if(!MONEY_D->player_pay(who, 2000000))
	{
		write("���Ǯû��ô���ˣ�\n");
		return 1;
	}
	
	if(!PLANTVEG_D->add_player_caidi(who))
	{
		write("��Ŀǰ��û��ͨ��԰���ܡ�\n");
		return 1;
	}
	
	write("��������������ء�\n");
	return 1;
}


int look_caidi(object who, string arg)
{
	mapping caidi;
	string str;
	int i;
	
	if(sizeof(caidi = PLANTVEG_D->query_player_caidi(who)))
	{
		str = "��Ŀǰ�Ĳ˵�������£�\n" + ZJOBACTS2+ZJMENUF(2,2,10,25);
		for(i = 0; i < sizeof(caidi); i++)
		{
			if(caidi[i] != "none")
			{
				str += caidi[i]["mature_name"] + ":lookveg " + i + ZJSEP;
			}
			else
			{
				str += "��ֲ:plantveg " + i + " " + ZJSEP;
			}
		}
		
		write(ZJOBLONG + str + "\n");
	}
	else
		write(ZJOBLONG + "�㻹û�в˵ء�\n");
	return 1;
}

int plantveg(object who, string arg)
{
	object seed;
	object *seeds;
	string str;
	int num;
	
	if(sscanf(arg,"%d %s", num, seed) != 2)
	{
		if(!sizeof(seeds = filter_array(all_inventory(who), (: ($1)->query("seed") :))))
		{
			write("�������û�����ӡ�\n");
			return 1;
		}
		
		str = "��Ҫ��ֲʲô���ӣ�\n" + ZJOBACTS2+ZJMENUF(2,2,10,25);
		foreach(seed in seeds)
		{
			str += seed->query("name") + ":plantveg " + arg + " " + file_name(seed) + ZJSEP;
		}
		write(ZJOBLONG + str + "\n");
		return 1;
	}
	
	if(PLANTVEG_D->add_vegetable(who, seed, num))
	{
		seed->add_amount(-1);
		write("��ֲ�ɹ���\n");
	}
	else
		write("��ֲʧ�ܡ�\n");
	return 1;
}

int lookveg(object who, string arg)
{
	mapping veg;
	int num;
	string str = "";
	
	if(!sscanf(arg, "%d", num))
		return ;
	
	veg = PLANTVEG_D->query_vegetable(who, num);
	if (veg["time"] < time())
	{
		str += "����һ�ó����" + veg["mature_name"] + "��\n"  + ZJOBACTS2+ZJMENUF(2,2,10,25);
		str += "����:shouveg " + num;
	}
	else
	{
		str += "����һ��δ�����" + veg["mature_name"] + "(" + CHINESE_D->chinese_time(veg["time"] - time()) + "�����)��\n" ZJOBACTS2+ZJMENUF(2,2,10,25);
		str += "����:chanveg " + num;
	}
	
	write(ZJOBLONG + str + "\n");
	return 1;
}

int shouveg(object who, string arg)
{
	object vegetable;
	int num;
	mapping veg;
	
	if(!sscanf(arg, "%d", num))
		return 1;
		
	veg = PLANTVEG_D->query_vegetable(who, num);
	if(veg["time"] > time())
	{
		write("���" + veg["mature_name"] + "δ���죡\n");
		return 1;
	}
	vegetable = new(veg["mature"]);
	vegetable->move(who);
	PLANTVEG_D->delete_vegetable(who, num);
	
	write("���ջ���һ��" + veg["mature_name"] + "��\n");
	return 1;
}

int chanveg(object who, string arg)
{
	int num;
	mapping veg;
	
	if(!sscanf(arg, "%d", num))
		return 1;
	else if (sscanf(arg, "%d %s", num, arg) != 2 && arg != "y")
	{
		write(ZJOBLONG + "��ȷ��Ҫ������\n" + ZJOBACTS2 + "ȷ��:chanveg " + num + " " + "y\n");
		return 1;
	}
	
	veg = PLANTVEG_D->query_vegetable(who, num);
	if(veg["time"] < time())
	{
		write("���" + veg["mature_name"] + "�Ѿ������ˣ�����հɣ�\n");
		return 1;
	}
	PLANTVEG_D->delete_vegetable(who, num);
	write("��ε���һ��δ�����" + veg["mature_name"] + "��\n");
	return 1;
}