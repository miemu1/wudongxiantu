//���յ���ʯ����ԭ�۸����10
int jiage(object ob)
{
  if (ob->query("yuanbao")>10)
 return ob->query("yuanbao")/10;
 
 return 0;
}
int do_huishou(string arg)
{
    string msg,id_name;
	object me = this_player();
	object obj;
	int amount,duoyu;
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
	  msg += sprintf("%d��%s"ZJBR"(%d��ʯ):huishou %s"ZJSEP,amount,obj->query("name"),jiage(obj),obj->query("id"));
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
	 duoyu=amount-1;
	 if (duoyu < 0)
	 {
		 duoyu=0;
		}
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
     me->add("yuanbao",jiage(obj)+jiage(obj)*(duoyu));
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
	 	
	me->add("yuan_bao",jiage(obj));
	log_file("pay/huishou", ctime(time()) + "  " + me->query("name") + me->query("id") + "������һ��" + obj->query("name") + "\n");
//	destruct(obj);
	destruct(obj);
	write("��ɹ������˸���Ʒ\n");
	return 1;
	}
	return 1;
}
int help (object me)
{
	write(@HELP
ָ���ʽ: arm
 
���г���(��)Ŀǰ������Я����������Ʒ��
 
 
HELP );
	return 1;
}