//hongbaod.c
//��/�����ϵͳ
inherit F_DBASE;

//��¼���ĺ������
nosave mapping all_gift=([]);
//�����ౣ��ʱ��(��)
nosave int max_time = 5 *60;
//ͬʱ���ֻ�ܴ��ڶ��ٸ�δ������������������ʱ���޷����º��
nosave int max_index = 50;
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "��ħ");
	CHANNEL_D->do_channel( this_object(), "sys", "��������Ѿ�������");
	set_heart_beat(10);//10������һ��
}
int clean_up()
{
	return 1;
}

//����ִ�м�飬û����ĺ���Զ����ظ����
void heart_beat(int coerce)
{
	string id, name, type, *list, index, msg ="", str, type_a;
	int num;
	int time, times;
	int i, is_load,huangjing;
	object ob;
//	huangjing = 
	
	if (i = sizeof(all_gift)) {
		list = keys(all_gift);
		times = time();
		while(i--) {
			index = list[i];
			time = all_gift[index]["time"];
			num = all_gift[index]["num"];
			id = all_gift[index]["id"];
			name = all_gift[index]["name"];
			type = all_gift[index]["type"];
			if (num <1) {
				msg += sprintf("���Ϊ��:%s��ɾ��:%s ����:%d\n", name+"("+id+")", type, num);
				//�պ����ɾ��
				map_delete(all_gift, index);
				continue;
			}
			//����ǿ�Ʋ������������ʱ�䣬ǿ�ƽ�δ����ĺ�����������
			if (!coerce) {
				//û�г�ʱ�ģ�����
				if (times < time +max_time) continue;
			}
			if (!objectp(ob = find_player(id))) {
				ob = UPDATE_D->global_find_player(id);
				is_load = 1;
			}
			if (!objectp(ob))  {
				msg += sprintf("�Ҳ����������:%s��ɾ��:%s ����:%d\n", name+"("+id+")", type, num);
				map_delete(all_gift, index);
				continue;
			}
			if (type == "yuanbao")
				ob->add("yuanbao", num);
			else
			if (type == "balance")
				ob->add("balance", num);
			else
			if (type == "hj")
				ob->add("balance", num*10000);
			/*else
			if (type == "hj")
				ob->add("hj", num);*/
			if (type == "balance") type_a = "ͭ��";
			else if (type == "yuanbao") type_a = "��ʯ"; 
			else if (type == "hj") type_a = "�ƽ�"; 
			else type_a = type;
			
			str = sprintf("���δ������:%s�����������:%s ����:%d\n", type_a, name+"("+id+")", num);
			ob->save();
			if (is_load) {
				destruct(ob);
			} else
				tell_object(ob, str);
			msg += ctime(time())+str;
			map_delete(all_gift, index);
		}
		if (sizeof(msg))
			log_file("hongbaod.log", "ʱ��:" + ctime(time())+" "+msg);
	}
}

//ϵͳ�������������ʱ���Ѿ������������û����ĺ�����Զ����ظ�����������ˡ�
int mud_shutdown()
{
	heart_beat(1);
	set_heart_beat(0);

	return 1;
}

//�����me=�����type=���ͣ�num=�ֳɶ��ٷݣ�number=����������
int do_fahongbao(object me, string type, int num, int number)
{
	int yb_max;
	int yp_max;
	mixed time;
	string type_a, unit, index;
	
	if (!me) return 0;
	
	if (sizeof(all_gift) >=max_index) {
		tell_object(me, sprintf("������кö�û����ȡ����ʱ�޷����š�\n"));
		return 0;
	}
	if (number <1) {
		tell_object(me, INPUTTXT("�������Ҫ�ֳ����ݡ�"ZJBR"��ʽ(��ʯ ���� ����)��","fahongbao $txt#")+"\n");
		return 0;
	}
	if (num >100000000000000) {
		tell_object(me, INPUTTXT("����������ֻ��װ10000������"ZJBR"��ʽ(��ʯ ���� ����)��","fahongbao $txt#")+"\n");
		return 0;
	}
	if (number >num) {
		tell_object(me, INPUTTXT("����������࣬���������ֵġ�"ZJBR"��ʽ(��ʯ ���� ����)��","fahongbao $txt#")+"\n");
		return 0;
	}
	if (number >100) {
		tell_object(me, INPUTTXT("������ֻ�ֳܷ�һ�ٷݡ�"ZJBR"��ʽ(��ʯ ���� ����)��","fahongbao $txt#")+"\n");
		return 0;
	}
	if (type != "yuanbao" && type != "balance" && type != "hj") {
		tell_object(me, sprintf("���뷢ʲô���(ֻ�ܷ���ʯ��ͭ���ƽ�)��\n"));
		return 0;
	}
	if (num <1) {
		tell_object(me, INPUTTXT("���������������ܵ���2��"ZJBR"��ʽ(��ʯ ���� ����)��","fahongbao $txt#")+"\n");
		return 0;
	}

	if (type == "yuanbao") {
		yb_max = me->query("yuanbao");
		if (yb_max <1) {
			tell_object(me, sprintf("��û����ʯ��\n"));
			return 0;
		}
		if (num >yb_max) {
			tell_object(me, sprintf("��û����ô����ʯ���ٷ�һ��ɡ�\n"));
			return 0;
		}
		type_a = "��ʯ";
		unit = "��";
	} else
	if (type == "balance") {
		yb_max = me->query("balance");
		if (yb_max <1) {
			tell_object(me, sprintf("��û��ͭ�塣\n"));
			return 0;
		}
		if (num >yb_max) {
			tell_object(me, sprintf("��û����ô��ͭ�壬�ٷ�һ��ɡ�\n"));
			return 0;
		}
		type_a = "ͭ��";
		unit = "��";
	} else
	if (type == "hj") {
		yb_max = me->query("balance")/10000;
		if (yb_max <1) {
			tell_object(me, sprintf("��û�лƽ�\n"));
			return 0;
		}
		if (num >yb_max) {
			tell_object(me, sprintf("��û����ô��ƽ��ٷ�һ��ɡ�\n"));
			return 0;
		}
		type_a = "�ƽ�";
		unit = "��";
	}

	time = time();
	index = save_variable(time);
	if (all_gift[index]) {
		time += 1;
		index = save_variable(time);
	} 
	//��¼�����������
	all_gift[index] = (["time" :time, "id": me->query("id"), "name" :me->query("name"),
								"type" :type, "num" :num, "number" :number, "qiang" : ({}), ]);
	tell_object(me, sprintf("�㽫"+num+unit+type_a+"�ֳ�"+number+"�ݺ�������˳�ȥ��\n"));
									
	//����Ƶ��������Ϣ���ṩ��ť���������
	CHANNEL_D->do_channel(this_object(), "chat", me->query("name")+"������"
										+number+"��"ZJURL("cmds:qianghb "+time)+HIR+ZJSIZE(22)+type_a+"���"NOR"��");
   if(type == "hj")
	   me->add("balance", -num*10000);
   else me->add(type, -num);
	return 1;
}
//������
int set_hongbao()
{
	int time = 1111;
	
	all_gift[time] = (["time" :time, "id": "alll", "name" :"Ҭ��",
				"type" :"yuanbao", "num" :10, "number" :2, "qiang" : ({}), ]);
	return 1;
}
//��ѯ�������
mapping query_hongbao()
{
	return all_gift;
}
//�����me=�����time=���������
int do_qianghongbao(object me, string index) 
{
	int max_num, num, number;
	string myid, id, name, type, type_a, unit, *qiang_list, msg;
		
	if (!me || !index) return 0;
	if (!sizeof(all_gift) || !mapp(all_gift) || !all_gift[index]) {
		tell_object(me, sprintf("û�����������Ѿ����������ˡ�\n"));
		return 0;
	}
	//�����������
	qiang_list = all_gift[index]["qiang"];
	if (!arrayp(qiang_list)) qiang_list = ({});
		
	myid = me->query("id");
	//�Ѿ�����ˣ������ٴ���

	if (member_array(myid, qiang_list) != -1) {
		tell_object(me, sprintf("���Ѿ������������ˡ�\n"));
		return 0;
	}

	id =all_gift[index]["id"];
	name =all_gift[index]["name"];
	type =all_gift[index]["type"];
	max_num =all_gift[index]["num"];
	number =all_gift[index]["number"];
	
	//if (myid == id) {
		//tell_object(me, sprintf("�㲻�����Լ����ĺ����\n"));
		//return 0;
	//}
	if (max_num <1) {
		tell_object(me, sprintf("�������Ѿ��������ˡ�\n"));
		map_delete(all_gift, index);
		return 0;
	}
		
	//������ɺ���ڵ�����
	if (number >1) {
		num =random(max_num /number *2);
		if (num <1) num = 1;
	}
	else
		num =max_num;
	
	if (type == "yuanbao") {
		type_a = "��ʯ";
		unit = "��";
		
		me->add("yuanbao", num);
	} else 
	if (type == "balance") {
		type_a = "ͭ��";
		unit = "��";
		
		me->add("balance", num);
	} else 
	if (type == "hj") {
		type_a = "�ƽ�";
		unit = "��";
		
		me->add("balance", num*10000);
	} 
	
	all_gift[index]["num"] -= num;
	all_gift[index]["number"] -= 1;
	//������ˣ��������
	if (all_gift[index]["num"] <1) {
		map_delete(all_gift, index);
	} else
		all_gift[index]["qiang"] += ({myid});

	msg = sprintf("��ϲ��ɹ�����"+name+"���ĺ������һ����ԭ����"+type_a+""+num+""+unit+"��\n");
	CHANNEL_D->do_channel(this_object(), "chat", me->query("name")+"����"+name+"���ĺ����������"+type_a+""+num+""+unit+"��\n");
	
	tell_object(me, msg);
	return 1;
}


