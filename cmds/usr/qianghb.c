//qianghb.c
//抢红包

int main(object me, string arg)
{
	string index, *list, type, type_a, name, msg ="", str, unit, *qiang, myid, id;
	mapping mp;
	int i, num, number;
	
	mp = HONGBAO_D->query_hongbao();
	if (!mapp(mp) || !i =sizeof(mp))
		return notify_fail("现在没有红包可抢。\n");
	
	if (!arg) {
		myid = me->query("id");
		//抢什么红包？
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
			//你已经抢过这个红包了。
			if (member_array(myid, qiang) != -1)
				continue;
			//不能抢自己发的红包
			if (myid == id)
				continue;
			
			if (type == "yuanbao") {
				type_a = "灵石";
				unit = "个";
			}
			else
			if (type == "balance") {
				type_a = "铜板";
				unit = "个";
			}
			else
			if (type == "hj") {
				type_a = "黄金";
				unit = "个";
			}
			else continue;
			if (sizeof(msg)) msg += ZJSEP;
			msg += sprintf("%s发的%s 余%d份%d%s:qianghb %s", name, type_a, number, num, unit, index);
		}
		if (sizeof(msg)) {
			str = ZJOBLONG"请选择想抢的红包：\n";
			str += ZJOBACTS2+ZJMENUF(2, 2, 9, 30);
			str += msg;
		} else
			str = "暂时没有红包可抢。";
		
		tell_object(me, str+"\n");
		return 1;
	} else {
		index = arg;
		if (!mapp(mp[index]) || !sizeof(mp[index]))
			return notify_fail("没有这个红包可抢。\n");
	}
	
	HONGBAO_D->do_qianghongbao(me, index);
	return 1;
}