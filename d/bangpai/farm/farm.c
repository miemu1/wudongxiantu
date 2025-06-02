#define ANIMAL_DIR "/d/bangpai/farm/animal/"
#define MEAT_DIR "/d/bangpai/farm/meat/"

mapping animals = ([    //��ֵ��λΪ����
    "pig" : 10,
    "sheep" : 20,
]);


void kaitong(object who, string arg)    //��ͨ��������
{
    if (FARM_D->query_player_farmd(who))
    {
        write("���Ѿ���ͨ���������ˡ�\n");
        return ;
    }
    
    if (!arg || arg == "")
    {
        write(ZJOBLONG + "��ȷ��Ҫ����200���ӿ�ͨ����������\n" + ZJOBACTS2 + "ȷ��:kaitong y\n");
        return ;
    }
    
    if (arg != "y")
    {
        write("��ʽ�������������롣\n");
        return ;
    }
    
    if (!MONEY_D->player_pay(who, 2000000))
    {
        write("���Ǯ�����ˡ�\n");
        return ;
    }
    
    if (FARM_D->set_player_farmd(who) && FARM_D->add_animal_amount(who))
    {
        write("��ɹ���ͨ�������ܡ�\n");
        return ;
    }
    else
    {
        write("��ͨ��������ʧ�ܣ�����ϵ����Ա����\n");
        return ;
    }
}

void kuojian(object who, string arg)    //����
{
    int count;
    
    if (!FARM_D->query_player_farmd(who))
    {
        write("�㻹û�п�ͨ�������ܡ�\n");
        return ;
    }
    
    if (!arg || arg == "")
    {
        write(ZJOBLONG + "��ȷ��Ҫ����200��������������\n" + ZJOBACTS2 + "ȷ��:kuojian y\n");
        return ;
    }
    
    if (arg != "y")
    {
        write("��ʽ�������������롣\n");
        return ;
    }
    
	if ((count = pow(who->query("combat_exp") * 10, 0.3333333)/100 + 4) <= (FARM_D->get_animal_amount(who)))
	{
		write("�㵱ǰ���ֻ����" + count + "ֻ���\n");
		return ;
	}
	
    if (!MONEY_D->player_pay(who, 2000000))
    {
        write("���Ǯ�����ˡ�\n");
        return ;
    }
    
    if (FARM_D->add_animal_amount(who))
    {
        write("��ɹ�����ũ����\n");
        return ;
    }
    else
    {
        write("����ʧ�ܣ�����ϵ����Ա����\n");
        return ;
    }
}

void buy_animal(object who, string arg)    //������
{
    string str = "";
    string temp, sign;
    object animal;
    int i;
    
    if (!FARM_D->query_player_farmd(who))
    {
        write("�㻹û�п�ͨ�������ܡ�\n");
        return ;
    }
    
    if (!arg || arg == "")
    {
        foreach(temp in keys(animals))
        {
            str += (ANIMAL_DIR + temp)->query("name") + "  " + animals[temp] + "��:buy_animal " + temp + ZJSEP;
        }
        
        write(ZJOBLONG + "��Ҫ��ʲô���\n" + ZJOBACTS2 + str + "\n");
        return ;
    }
    
    if (sscanf(arg, "%s %s", arg, sign) != 2)
    {
        write(ZJOBLONG + "��Ҫ���򻨷�" + animals[arg] + "���ӹ���" + (ANIMAL_DIR + arg)->query("name") + "��\n" + ZJOBACTS2 + "ȷ��:buy_animal " + arg + " y\n");
        return ;
    }
    
    if (sign != "y")
    {
        write("��ʽ�������������롣\n");
        return ;
    }
    
    if (FARM_D->get_animal_amount(who) <= sizeof(FARM_D->get_animal(who)))
    {
        write("��Ŀǰ�������Ѿ����ˡ�\n");
        return ;
    }
    
    if (!MONEY_D->player_pay(who, animals[arg] * 10000))
    {
        write("���Ǯ�����ˡ�\n");
        return ;
    }
    
    if (i = FARM_D->add_animal(who, arg))
    {
        write("�㹺����һֻ" + (ANIMAL_DIR + arg)->query("name") + "��\n");
        animal = new(ANIMAL_DIR + arg);
        animal->set("animal", i - 1);
        animal->set("mature_time", time() + animal->query("need_time"));
        //
        //animal->set_name(animal->query("name") + animal->query("animal"), ({animal->query("id")}));
        //
        animal->move(environment(who));
        return ;
    }
    else
    {
        write("��������ϵ����Ա����\n");
        return ;
    }
    
    return ;
}

void slaughter_animal(object who, string arg)    //ɱ������
{
    string sign;
    string animal_name;
    int meat_amount;
    object meat;
    
    if (sscanf(arg, "%s %s", arg, sign) != 2)
    {
        write(ZJOBLONG + "��ȷ��Ҫɱ��" + arg->query("name") + "��\n" + ZJOBACTS2 + "ȷ��:slaughter_animal " + arg + " y\n");
        return ;
    }
    
    if (sign != "y")
    {
        write("��ʽ�������������롣\n");
        return ;
    }
    
    if (!find_object(arg) || !arg->query("is_animal") || environment(find_object(arg)) != environment(who))
    {
        write("�����ڴ˶�������Ϊ�����ö��������������\n");
        return ;
    }
    
    if (find_object(arg)->query("mature_time") > time())
    {
        write("��δ���죬�������ס�\n");
        return ;
    }
    
    if (FARM_D->delete_animal(who, arg->query("animal")))
    {
        animal_name = arg->query("name");
        meat_amount = arg->query("meat");
        meat = new(MEAT_DIR + arg->query("meat_name"));    //�޸�
        meat->set_amount(meat_amount);
        meat->move(who);
        destruct(find_object(arg));
        write("��ɱ��" + animal_name + "���" + meat_amount + animal_name + "�⡣\n");
        return ;
    }
    else
    {
        write("��������ϵ����Ա����\n");
        return ;
    }
}

void sell_animal(object who, string arg)    //��������
{
    string sign;
    string animal_name;
    int gold_amount;
    object money_gold;
    
    if (sscanf(arg, "%s %s", arg, sign) != 2)
    {
        write(ZJOBLONG + "��ȷ��Ҫ����" + arg->query("name") + "��\n" + ZJOBACTS2 + "ȷ��:sell_animal " + arg + " y\n");
        return ;
    }
    
    if (sign != "y")
    {
        write("��ʽ�������������롣\n");
        return ;
    }
    
    if (!find_object(arg) || !arg->query("is_animal") || environment(find_object(arg)) != environment(who))
    {
        write("�����ڴ˶�������Ϊ�����ö��������������\n");
        return ;
    }
    
    if (FARM_D->delete_animal(who, arg->query("animal")))
    {
        animal_name = arg->query("name");
        gold_amount = animals[arg->query("id")] * 7 / 10;
        money_gold = new("/clone/money/gold");
        money_gold->set_amount(gold_amount);
        money_gold->move(who);
        destruct(find_object(arg));
        write("��������" + animal_name + "�����" + gold_amount + "���ӡ�\n");
        return ;
    }
    else
    {
        write("��������ϵ����Ա����\n");
        return ;
    }
}

void init_muchang(object who, object room)    //��ʼ������
{
    mapping animals;
    int i;
    object ob;
    
    if (sizeof(animals = FARM_D->get_animal(who)))
    {
        for(i = 0; i < sizeof(animals); i++)
        {
            ob = new(ANIMAL_DIR + animals[i]["name"]);
            ob->set("animal", i);
            ob->set("mature_time", animals[i]["time"]);
            ob->move(room);
        }
    }
}

void look(object who, object ob)    //look
{
    string str = "";
    
    str += ob->short();
    str += "\nһһһһһһһһһһһһһһһһһһһһһһһ\n";
    str += ob->long() + "(" + (((ob->query("mature_time") - time()) > 1)?CHINESE_D->chinese_time(ob->query("mature_time") - time()) + "�����" : "�ѳ���") + ")\n";
	str = replace_string(str,"\n",ZJBR);
    if (str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
        str = str[0..(strlen(str)-5)];
        
    str +=  "\n" + ZJOBACTS2 + "����ɱ��:slaughter_animal " + ob + ZJSEP + "����:sell_animal " + ob + "\n";
    write(ZJOBLONG + str + "\n");
}