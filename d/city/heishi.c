// by ranger_����
// heishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", "�����Ǻ��У���Ʒ���׵ĳ�����");
	set("exits", ([
		"northwest":__DIR__"guangchang",
			"south":__DIR__"pairoom",
	]));
	set("objects", ([		
		"/adm/npc/heixin" : 1,	//��������
	//	"/adm/npc/ping" : 1,	
	]));
	set("action_list", ([
		"������Ʒ" : "jishou",
		"��Ʒ�б�" : "jylist",
		"��ѡ�Ը�" : "xingge",
		//"����ϴ��" : "xidian",
		"������Ʒ" : "huishou"
	]));
	set("no_fight","1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		"clone/shizhe/nianshou" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_stock", "jishou");
	add_action("do_buy", "jybuy");
	add_action("do_list", "jylist");
	add_action("do_cha", "jychakan");
	add_action("do_cha", "jychakan");
	add_action("do_unstock", "quhui");
	add_action("do_effect", "effect");
	add_action("do_xingge","xingge");
	add_action("do_uses","xidian");
	add_action("do_huishou","huishou");
			
}

int do_stock(string arg)
{
	tell_object(this_player(),SALE_D->do_stock(this_player(),arg)+"\n");
	return 1;
}

int do_buy(string arg)
{
	if (this_player()->query("combat_exp") < 200000)
	{
		tell_object(this_player(), "�����Ϊ����20���޷�������Ʒ��\n");
		return 1;
	}
	tell_object(this_player(),SALE_D->do_buy(this_player(),arg)+"\n");
	return 1;
}

int do_cha(string arg)
{
	tell_object(this_player(),SALE_D->do_cha(this_player(),arg)+"\n");
	return 1;
}

int do_list(string arg)
{
//	return notify_fail(OKSAY"������ʱ�رգ�\n");
	if(!arg)
		arg = "ȫ�� 1";
	tell_object(this_player(),SALE_D->do_list(this_player(),arg)+"\n");
	return 1;
}

int do_unstock(string arg)
{
	tell_object(this_player(),SALE_D->do_unstock(this_player(),arg)+"\n");
	return 1;
}


int do_xingge(string arg)
{
object me = this_player();
tell_object(me,ZJOBLONG"��ѡ���Ը�ÿ�ο۷�2000��ʯ��\n"
		ZJOBACTS2+ZJMENUF(2,2,6,30)+
        "������:effect ������"ZJSEP
		"��������:effect ��������"ZJSEP
		"���ռ�թ:effect ���ռ�թ"ZJSEP
		"�ĺ�����:effect �ĺ�����\n");
	return 1;
}


int do_effect(string arg)
{
	object me = this_player();
	if (me->query("yuanbao") < 2000)
	{
	tell_object(me,HIR"�����ʯ������������"NOR"\n");		
		return 1;
	}
	if (me->query("character")==arg)
		{
	tell_object(me,HIR"��ѡ�����������Ը�һ���ģ�"NOR"\n");		
		return 1;
	}
	if (arg=="������") 
	 me->set("character", "������");
	else
	 if (arg=="��������") 
	   me->set("character", "��������");

	else 
	if (arg=="�ĺ�����") 
	 me->set("character", "�ĺ�����");

	else 
	if (arg=="���ռ�թ") 
	me->set("character", "���ռ�թ");
		else 	
		{
	tell_object(me,HIR"\n�����ڴ����Ը�"NOR"\n");		
	return 1;
		}
	  tell_object(me,"�Ը�ת���ɹ�!\n");
	  
	   me->add("yuanbao",-2000);
	   tell_object(me,"2000��ʯ�ѿ۳�!\n");
	  me->set("xixingge",1);
    return 1;
}

varargs int do_uses(string arg)
{
	mapping shuxing=([]), my;
	string *sname, str, line;
	int i;
	int max_sx, max_sx2;
	int tmpstr, tmpint, tmpcon, tmpdex;
	object me = this_player();
		
	
	if (me->query("xidian") && me->query("yuanbao") < 2000)
	{
		return notify_fail("�����ʯ������\n");
	}
	if(!arg) {
		str = ZJOBLONG+ "����������·�������������������ѡ��һ��ϴ��������غ���Ų����𣬵�һ�����,�����շ�2000��ʯ��\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		
		str += sprintf("ȷ��:xidian -yes" + ZJSEP);
		str += sprintf("ȡ��:look");
		tell_object(me, str + "\n");
	 return 1;
	} else if(arg == "-yes") {
		max_sx = (me->query("con") + me->query("dex")+me->query("int")+me->query("str"))
					-(me->query("gift/shenliwan") + me->query("gift/xiandan")+me->query("gift/unknowdan")+me->query("gift/lighting") +me->query("gift/xisuidan"))
					-(me->query("level")/10-me->query("tianfu_point"));
		
		write(INPUTTXT(HIR"ע��ֵ������13-30֮��"ZJBR"�ܺͲ��ܳ��������е�����"+max_sx+"�㡣"
											+NOR+ZJBR+HIW+"(���� ���� ���� ��)"
											+NOR+ZJBR+HIY+"(����30 30 30 30���м��Կո����)"+NOR+
												ZJBR+"�������������������","xidian $txt#")+"\n");
	} else if(sscanf(arg, "-yes %d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) == 4) {
		if (tmpstr < 30 || tmpstr >30
			|| tmpint < 30 || tmpint >30
			|| tmpcon < 30 || tmpcon >30
			|| tmpdex < 30 || tmpdex >30) {
				write(HIR"����һ�����벻��(30-30)��Χ֮�ڡ�"NOR"\n");
				return 1;
			}
		my = me->query_entire_dbase();
		max_sx = (my["con"] + my["dex"]+my["int"]+my["str"])
					-(me->query("gift/shenliwan") + me->query("gift/xiandan")+me->query("gift/unknowdan")+me->query("gift/lighting") +me->query("gift/xisuidan"))
					-(my["level"]/10-my["tianfu_point"]);
			
		if (tmpstr+ tmpint+ tmpcon+ tmpdex != max_sx) {
			write(HIR"���������������������Ŀǰ�����������ԡ�"NOR"\n");
			return 1;
		}
		
		line = sprintf("str(%d)int(%d)con(%d)dex(%d)", tmpstr, tmpint, tmpcon, tmpdex);
		
		tmpstr += me->query("gift/shenliwan");
		tmpint += me->query("gift/xiandan");
		tmpcon += me->query("gift/xisuidan")+me->query("gift/lighting");
		tmpdex += me->query("gift/unknowdan");
		max_sx2 = tmpstr+ tmpint+ tmpcon+ tmpdex;
		
		my["str"]= tmpstr;
		my["int"]= tmpint;
		my["con"]= tmpcon;
		my["dex"]= tmpdex;
		my["tianfu_point"] = my["level"] /10;
		
		CHANNEL_D->do_channel(present("shenyi",this_object()), "chat", "���գ�"+me->name()+"���Ҵ����������壡");
		message_vision(HIY"$N�ں������������壡"NOR"\n", me);
		tell_object(me, HIY"�������ܳɹ������ٲ�������һ���츳��"NOR"\n");
		
		//�����������ļ����Ƿ����Ҫ�󣬲����ϵ�ɾ��
		UPDATE_D->check_skill(me);
		me->save();
	//	log_file("/cmds/xidian", sprintf("%s  ϴ��=%s  �ܼ�=str(%d)int(%d)con(%d)dex(%d) �ܹ�(%d/%d��) ϴ��ʱ�䣺%s\n", 
	//										me->name()+"("+my["id"]+")", line, tmpstr, tmpint, tmpcon, tmpdex, max_sx, max_sx2, CHINESE_D->chinese_date(time(), 2)));
	if (me->query("xidian"))
		me->add("yuanbao",-2000);
		
	 me->set("xidian", 1);
	} else if(sscanf(arg, "%d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) == 4) {
		
		str = ZJOBLONG+ HIC"������ã�"HIG"����("+tmpstr+") ����("+tmpint+") ����("+tmpcon+") ��("+tmpdex+")"NOR
				+ZJBR"��������·�������������"ZJBR
										+"������ѡ�����һ�����ѣ�һ��ϴ�㣬�����ɻָ���������غ���Ų�����"NOR"\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		
		str += sprintf("ȷ��:xidian -yes " +tmpstr+" "+ tmpint+" "+ tmpcon+" "+ tmpdex+ ZJSEP);
		str += sprintf("ȡ��:look");
		tell_object(me, str + "\n");
	} else 
		me->force_me("xidian");
	return 1;
}

//���յ���ʯ����ԭ�۸����10
int jiage(object ob)
{
  if (ob->query("yuanbao")>10)
 return ob->query("yuanbao")/4;
 
 return 0;
}
int do_huishou(string arg)
{
    string msg,id_name;
	object me = this_player();
	object obj;
	int amount;
     if (!arg)
     {
	object *pobj;
	pobj = all_inventory(me);
	pobj = filter_array(pobj,(: jiage($1) :));
	
	if (!sizeof(pobj))
	return 1;
	
	msg = ZJOBLONG"��ѡ������Ҫ���յ���Ʒ��\n"
		ZJOBACTS2+ZJMENUF(2,2,6,30);
		
	 foreach (obj in pobj)
	 {
	  amount = obj->query_amount()?obj->query_amount():1;
	  msg += sprintf("%d��%s"ZJBR"(%d��ȯ):huishou %s"ZJSEP,amount,obj->query("name"),jiage(obj),obj->query("id"));
     }
     
	  msg += "ȡ��:look\n";
	 tell_object(me,msg);
	 return 1;
	}
	//Ĭ����string ��Ҫ����ת����int
	if (sscanf(arg, "%s==%s", id_name, arg) == 2)
	{
	
	 obj = present(id_name,me);
	 amount = to_int(arg);
	 if (amount < 1)
	 {
	     write("�����������������롣\n");
	     return 1;
	 }
	 
	 if (!objectp(obj))
	 return notify_fail("��û�и���Ʒ\n");
	 
	 if (obj->query_amount()<amount)
	 return notify_fail("�����û����ô��"+obj->query("name")+"\n");
	 
	 log_file("pay/huishou", ctime(time()) + "  " + me->query("name") + me->query("id") + "������" + chinese_number(amount) + "��" + obj->query("name") + "\n");
     //Ϊɶ��Ҫ��ǰ���أ������Ʒ����û�����أ�Сǧ��ע��һ��Ŷ��
     //emmmmm����
     me->add("jifeng",jiage(obj)*amount);
     obj->add_amount(-amount);
     
      write("��ɹ������˸���Ʒ\n");
      return 1;
      
	}
	
	if (arg)
	{
	 obj = present(arg,me);
	 amount = obj->query_amount();
	 
	 if (amount)
	 return notify_fail(INPUTTXT("����"+amount+"�ݣ�������Ҫ���ն��ٷ�"+obj->query("name"),"huishou "+arg+"==$txt#")+"\n");
	 	
	me->add("jifeng",jiage(obj));
	log_file("pay/huishou", ctime(time()) + "  " + me->query("name") + me->query("id") + "������һ��" + obj->query("name") + "\n");
//	destruct(obj);
	destruct(obj);
	write("��ɹ������˸���Ʒ\n");
	return 1;
	}
	return 1;
}

int query_autoload() { return 1; }


