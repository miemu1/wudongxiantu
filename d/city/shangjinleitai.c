// by ranger_����
// DuoBaoLeiTai.java

inherit ROOM;
int ask_biwu(string arg);
int ask_biwu2(string arg);

void create()
{
	set("short", "�ͽ���̨(PK)");
	set("long", "����һ�����ɼ�������̨����׳��ʵ��ľ������һƬƽ̨���Ľǵ�֧���ϸ߹����ĸ�����������Ĺ��ڶ�������ؿ���̨�ϵ�������䡣��̨�����и������ܣ������ް�������ȫ��");
	set("exits", ([
		"north" : __DIR__"ximen",
	]));
	set("objects", ([
		__DIR__"npc/dashou" : 1,
	]));
	set("action_list", ([
		"�ƽ����":"biwu",
		"��ʯ����":"biwu2",
	]));
	setup();
}
void init()
{
	object me = this_player();
	
	add_action("ask_biwu","biwu");   
	add_action("ask_biwu2","biwu2");   
	add_action("discmds",({"respitate","exert","array","ansuan","touxi","persuade",
		"teach","exert","exercise","study","learn","sleep","kill","steal","cast","expell",
		"fight","hit","perform","prcatice","scribe","surrender"}));
	if (userp(me) && me->query("no_get") )
		call_out("do_recover",15,me);
}
int ask_biwu(string arg)
{
	object me = this_player();
	object room, look_fight_room;
	object *obs, ob, obj;
	int k=0, unit, unit2;
	string str, id, name;
	
	if (me->query_temp("biwu_time") > time())
		return notify_fail("�𼱣�����Ϣ����һ������ϰɣ�\n");
	
	if (unit2 = me->query("bet/balance/unit") > 0)
	{
		me->add("balance", unit2);
		me->delete("bet/balance");
		return notify_fail("���ϴα���δ��ɣ���ע"+MONEY_D->money_str(unit2)+"�˻�����Ǯׯ��\n");
	}
	
	if (!look_fight_room=find_object(__DIR__"leitaiyi"))
		look_fight_room=load_object(__DIR__"leitaiyi");
	
	if (look_fight_room)
	{
		obs = all_inventory(look_fight_room);
		
		foreach(ob in obs) {
			if (userp(ob))
			{
				k++;
				if (k > 0) {
					unit2 = ob->query("bet/balance/unit");
					name = ob->name();
				}
			}
		}
		if (k >=2)
			return notify_fail("��̨���Ѿ������ھ������㻹�ǵȻ����ϰɣ�\n");
	}
	
	if (me->is_busy())
		return notify_fail("����æ�أ�\n");
	
	if (me->is_fighting())
		return notify_fail("���Ѿ��ڴ���ˣ�������˵��\n");
	
	if (me->query("balance") < 10000)
		return notify_fail("������Ҫ1���ƽ���Ϊ�볡�ѣ���Ǯׯ����1���ƽ�\n");
	
	if (!arg) {
		str = sprintf("%s", "��Ҫ����(����):biwu yes" + ZJSEP);
		str += sprintf("%s", "���͵�(ȡ��):biwu no");
		tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	} else
	if (arg == "no") {
		tell_object(me, "����ñ���������̫Σ���ˣ�����ȥ���ͱȽϰ�ȫ��\n");
		return 1;
	}
	
	if (sscanf(arg, "%s %s %d", arg, id, unit) != 3 ) {
		if (look_fight_room) {
			if (unit2 > 0) {
				str = sprintf("%s", "˭��˭(����):biwu yes no " + (unit2/10000) + ZJSEP);
				str += sprintf("%s", "����(ȡ��):biwu no");
				tell_object(me, ZJOBLONG + name+"Ŀǰ��Ľ�Ǯ��"
					+MONEY_D->money_str(unit2)+"����ȷ��������\n"
											+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
				return 1;
			}
		}
		
		obs = all_inventory(this_object());
		str = sprintf("%s%s", "������ս:biwu yes no 1" + ZJSEP, "����(ȡ��):biwu no");
		
		foreach(ob in obs) {
			if (userp(ob))
			{
				if (ob != me)
					str += sprintf(ZJSEP+"%s", HIC+ob->name() + NOR":biwu yes " + ob->query("id") + " 1");
			}
		}

		tell_object(me, ZJOBLONG + "��������˭������б�����\n"
										+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	} else {
		if (unit < 10 || unit > 10000)  {
			write(INPUTTXT("�¶�ע(�ƽ�)��(10-1��ƽ�)","biwu yes "+(id != "no" ? id : "no")+" $txt#")+"\n");
			return 1;
		}
		
		unit *= 10000;
		
		if (me->query("balance") < unit + 10000) {
			tell_object(me, "��Ǯׯ����"+MONEY_D->money_str(unit+10000) +NOR"��\n");
			return 1;
		}
		
		if (obj = present(id, environment(me)))
		{
			me->set_temp("biwu/id", obj->query("id"));
			
			if (obj->query_temp("biwu/id") != me->query("id") ) {
				if ( me->query_temp("biwu/time") < time()) {
					me->set_temp("biwu/time", time() + 5);
					str = sprintf("%s", "˭��˭(����):biwu yes " + me->query("id") + " " + (unit/10000) + ZJSEP);
					str += sprintf("%s", "�ǲ���(ȡ��):biwu no");
					tell_object(obj, ZJOBLONG + me->name()+"�����Ľ�Ǯ��"
								+MONEY_D->money_str(unit) +"�����Ӧս��\n"
											+ZJOBACTS2+ZJMENUF(3,2,9,30) + str+"\n");
				} 
				tell_object(me, "���Ѿ���"+obj->name()+"������ս�ˣ������ĵȴ��Է��Ĵ𸴡�\n");
				return 1;
			}
		} else if (id != "no") {
			tell_object(me, "�����������Ѿ��뿪�ˡ�\n");
			return 1;
		}
		
		if (obj) {
			if (obj->query("balance") >= unit + 10000) {
				obj->add("balance", -(unit));
				obj->set("bet/balance/unit", (unit));
				tell_object(obj, "�����˶�ע��"+ MONEY_D->money_str(unit) +NOR"\n");
				log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
														"��ע��"+MONEY_D->money_str(unit), ctime(time())));
			} else {
				tell_object(me, obj->name() + "Ǯׯ��������ע������ȡ����\n");
				tell_object(obj, "���Ǯׯ��������ע������ȡ����\n");
				return 1;
			}
			
			obj->add("balance", -10000);
			obj->move(__DIR__"leitaiyi");
			tell_object(obj, "���"+me->name()+"˫˫Ծ������̨��\n");
			tell_object(me, "���"+obj->name()+"˫˫Ծ������̨��\n");
			obj->delete_temp("biwu");
			tell_object(obj, ("�������1���ƽ���Ϊ�����볡�ѣ���������ʱ��Ϊ�������ӣ���עΪ��"+MONEY_D->money_str(obj->query("bet/balance/unit"))+"\n"));
		}
		
		if (!me->query("bet/balance/unit")) {
			me->add("balance", -(unit));
			me->set("bet/balance/unit", (unit));
			tell_object(me, "�����˶�ע��"+ MONEY_D->money_str(unit) +NOR"\n");
			log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
													"��ע��"+MONEY_D->money_str(unit), ctime(time())));
		} else if ( unit2 > 0) {//�����̨������
			me->add("balance", -((unit)-me->query("bet/balance/unit")));
			me->set("bet/balance/unit", (unit));
			tell_object(me, "���ע���Ϊ��"+ MONEY_D->money_str(unit)+NOR"\n");
			log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
													"��ע��"+MONEY_D->money_str(unit), ctime(time())));
		} else
			tell_object(me, ("��������ϴεĶ�����������("+
										MONEY_D->money_str(me->query("bet/balance/unit"))+")��\n"));
		
		me->add("balance", -10000);
		me->move(__DIR__"leitaiyi");
		me->delete_temp("biwu");
		tell_object(me, ("�������1���ƽ���Ϊ�����볡�ѣ���������ʱ��Ϊ�������ӣ���עΪ��"+MONEY_D->money_str(me->query("bet/balance/unit"))+"\n"));
	}
	return 1;
}
int ask_biwu2(string arg)
{
	object me = this_player();
	object room, look_fight_room;
	object *obs, ob, obj;
	int k=0, unit, unit2;
	string str, id, name;
	
	if (me->query_temp("biwu_time") > time())
		return notify_fail("�𼱣�����Ϣ����һ������ϰɣ�\n");
	
	if (unit2 = me->query("bet/yuanbao/unit") > 0)
	{
		me->add("yuanbao", unit2);
		me->delete("bet/yuanbao");
		return notify_fail("���ϴα���δ��ɣ���ע"+(unit2)+"��ʯ�˻������˻���\n");
	}
	
	if (!look_fight_room=find_object(__DIR__"leitaier"))
		look_fight_room=load_object(__DIR__"leitaier");
	
	if (look_fight_room)
	{
		obs = all_inventory(look_fight_room);
		
		foreach(ob in obs) {
			if (userp(ob))
			{
				k++;
				if (k > 0) {
					unit2 = ob->query("bet/yuanbao/unit");
					name = ob->name();
				}
			}
		}
		if (k >=2)
			return notify_fail("��̨���Ѿ������ھ������㻹�ǵȻ����ϰɣ�\n");
	}
	
	if (me->is_busy())
		return notify_fail("����æ�أ�\n");
	
	if (me->is_fighting())
		return notify_fail("���Ѿ��ڴ���ˣ�������˵��\n");
	
	if (me->query("yuanbao") < 1)
		return notify_fail("������Ҫ1��ʯ��Ϊ�볡�ѣ����˻�����1��ʯ��\n");
	
	if (!arg) {
		str = sprintf("%s", "��Ҫ����(����):biwu2 yes" + ZJSEP);
		str += sprintf("%s", "���͵�(ȡ��):biwu2 no");
		tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	} else
	if (arg == "no") {
		tell_object(me, "����ñ���������̫Σ���ˣ�����ȥ���ͱȽϰ�ȫ��\n");
		return 1;
	}
	
	if (sscanf(arg, "%s %s %d", arg, id, unit) != 3 ) {
		if (look_fight_room) {
			if (unit2 > 0) {
				str = sprintf("%s", "˭��˭(����):biwu2 yes no " + (unit2) + ZJSEP);
				str += sprintf("%s", "����(ȡ��):biwu2 no");
				tell_object(me, ZJOBLONG + name+"Ŀǰ�����ʯ��"
										+unit2+"����ȷ��������\n"
											+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
				return 1;
			}
		}
		
		obs = all_inventory(this_object());
		str = sprintf("%s%s", "������ս:biwu2 yes no 0" + ZJSEP, "����(ȡ��):biwu2 no");
		
		foreach(ob in obs) {
			if (userp(ob))
			{
				if (ob != me)
					str += sprintf(ZJSEP+"%s", HIC+ob->name() + NOR":biwu2 yes " + ob->query("id") + " 0");
			}
		}

		tell_object(me, ZJOBLONG + "��������˭������б�����\n"
										+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	} else {
		if (unit < 10 || unit > 1000)  {
			write(INPUTTXT("�¶�ע(��ʯ)��(10-1000��ʯ)","biwu2 yes "+(id != "no" ? id : "no")+" $txt#")+"\n");
			return 1;
		}
				
		if (me->query("yuanbao") < unit + 1) {
			tell_object(me, "���˻�����"+(unit + 1)+ "��ʯ"+"��\n");
			return 1;
		}
		
		if (obj = present(id, environment(me)))
		{
			me->set_temp("biwu/id", obj->query("id"));
			
			if (obj->query_temp("biwu/id") != me->query("id") ) {
				if ( me->query_temp("biwu/time") < time()) {
					me->set_temp("biwu/time", time() + 5);
					str = sprintf("%s", "˭��˭(����):biwu2 yes " + me->query("id") + " " + (unit) + ZJSEP);
					str += sprintf("%s", "�ǲ���(ȡ��):biwu2 no");
					tell_object(obj, ZJOBLONG + me->name()+"�����ģ�"
								+unit + "��ʯ"+"�����Ӧս��\n"
											+ZJOBACTS2+ZJMENUF(3,2,9,30) + str+"\n");
				} 
				tell_object(me, "���Ѿ���"+obj->name()+"������ս�ˣ������ĵȴ��Է��Ĵ𸴡�\n");
				return 1;
			}
		} else if (id != "no") {
			tell_object(me, "�����������Ѿ��뿪�ˡ�\n");
			return 1;
		}
		if (obj) {
			if (obj->query("yuanbao") >= unit + 1) {
				obj->add("yuanbao", -(unit));
				obj->set("bet/yuanbao/unit", (unit));
				tell_object(obj, "�����˶�ע��"+ unit + "��ʯ"+NOR"\n");
				log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
														"��ע��"+unit + "��ʯ", ctime(time())));
			} else {
				tell_object(me, obj->name() + "�˻���ʯ��������ע������ȡ����\n");
				tell_object(obj, "����˻���������ע������ȡ����\n");
				return 1;
			}
			obj->add("yuanbao", -1);
			obj->move(__DIR__"leitaier");
			tell_object(obj, "���"+me->name()+"˫˫Ծ������̨��\n");
			tell_object(me, "���"+obj->name()+"˫˫Ծ������̨��\n");
			obj->delete_temp("biwu");
			tell_object(obj, ("�������1��ʯ��Ϊ�����볡�ѣ���������ʱ��Ϊ�������ӣ���עΪ��"+obj->query("bet/yuanbao/unit")+"Ԫ����\n"));
		}
		if (!me->query("bet/yuanbao/unit")) {
			me->add("yuanbao", -(unit));
			me->set("bet/yuanbao/unit", (unit));
			tell_object(me, "�����˶�ע��"+ unit + "��ʯ"+NOR"\n");
			log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
													"��ע��"+unit + "��ʯ", ctime(time())));
		} else if ( unit2 > 0) {//�����̨������
			me->add("yuanbao", -((unit)-me->query("bet/yuanbao/unit")));
			me->set("bet/yuanbao/unit", (unit));
			tell_object(me, "���ע���Ϊ��"+ (unit + "��ʯ")+NOR"\n");
			log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
													"��ע��"+unit + "��ʯ", ctime(time())));
		} else
			tell_object(me, ("��������ϴεĶ�����������("+
										MONEY_D->money_str(me->query("bet/yuanbao/unit"))+")��\n"));
		me->add("yuanbao", -1);
		me->move(__DIR__"leitaier");
		me->delete_temp("biwu");
		tell_object(me, ("�������1��ʯ��Ϊ�����볡�ѣ���������ʱ��Ϊ�������ӣ���עΪ��"+me->query("bet/yuanbao/unit")+"��ʯ��\n"));
	}
	return 1;
}

void do_recover(object me)
{
    if( !me || environment(me) != this_object() ) return;
	me->delete("no_get");
	if (!living(me)) me->revive();
	me->set("eff_jing",me->query("max_jing"));
	me->set("jing",me->query("max_jing"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("max_qi"));
	if (me->query("neili")<me->query("max_neili"))
		me->set("neili",me->query("max_neili"));
	if (me->query("jingli")<me->query("max_jingli"))
		me->set("jingli",me->query("max_jingli"));
	me->start_busy(0);
	tell_object(me,HIW "�����ƺ���һ�����ص�����������һ�¾��ǣ����ֲ�û�����ˣ�"NOR"\n");
}
int discmds()
{
	tell_object(this_player(),"�����㻹��ר�Ŀ�����ɣ�\n");
     return 1;
}
