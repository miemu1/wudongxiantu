//qianghb.c
//�����

int main(object me, string arg)
{
	string index, *list, type, type_a, name, msg ="", str, unit, *qiang, myid, id;
	mapping mp;
	int i, num, number;
	
	mp = HONGBAO_D->query_hongbao();
	if (!mapp(mp) || !i =sizeof(mp))
		return notify_fail("����û�к��������\n");
	
	if (!arg) {
		myid = me->query("id");
		//��ʲô�����
		list = keys(mp);
		while(i--) {
			index = list[i];
			id = mp[index]["id"];
			name = mp[index]["name"];
			type = mp[index]["type"];
			num = mp[index]["num"];
			number = mp[index]["number"];
			qiang = mp[index]["qiang"];
			
			if (num <1) continue;
			//���Ѿ������������ˡ�
			if (member_array(myid, qiang) != -1)
				continue;
			//�������Լ����ĺ��
			if (myid == id)
				continue;
			
			if (type == "yuanbao") {
				type_a = "��ʯ";
				unit = "��";
			}
			else
			if (type == "balance") {
				type_a = "ͭ��";
				unit = "��";
			}
			else
			if (type == "hj") {
				type_a = "�ƽ�";
				unit = "��";
			}
			else continue;
			if (sizeof(msg)) msg += ZJSEP;
			msg += sprintf("%s����%s ��%d��%d%s:qianghb %s", name, type_a, number, num, unit, index);
		}
		if (sizeof(msg)) {
			str = ZJOBLONG"��ѡ�������ĺ����\n";
			str += ZJOBACTS2+ZJMENUF(2, 2, 9, 30);
			str += msg;
		} else
			str = "��ʱû�к��������";
		
		tell_object(me, str+"\n");
		return 1;
	} else {
		index = arg;
		if (!mapp(mp[index]) || !sizeof(mp[index]))
			return notify_fail("û��������������\n");
	}
	
	HONGBAO_D->do_qianghongbao(me, index);
	return 1;
}