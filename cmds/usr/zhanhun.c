// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *zhanhuns,zhanhun;
	int i;
	string str;
	int armor;
	string longs;
	
	if(!arg)
	{
	if(me->query("zhanhuns") < 1 )
	{
	
   return notify_fail(ZJOBLONG"�������ʲô������\n"
   ZJOBACTS2+ZJMENUF(3,3,9,30)+"����ս��:zhanhun zhaomu\n");
  	}
   else      
   { 
   if(!me->query("zhanhuns"))
   return notify_fail("�㻹û�л��ս���أ�\n");  
   return notify_fail(ZJOBLONG"����Խ���ʲô������\n"
   ZJOBACTS2+ZJMENUF(2,2,9,30)+"�ٻ�ս��:zhanhun call"ZJSEP"����ս��:zhanhun gone"ZJSEP"ս�긽��:zhanhun change"ZJSEP"ս�����:zhanhun jiechu"ZJSEP"�鿴����:zhanhun score"ZJSEP"ǿ��ս��:zhanhun lvl\n");   
   }
   }
	else if(arg=="zhaomu")
	{	
	if (me->query("yuanbao") < 100000)
	return notify_fail("�����ʯ����10��\n");	
	me->add("yuanbao",-100000);
	if (me->query("combat_exp") < 100000000)
	return notify_fail("��ľ��鲻��1�ڣ�\n");	
	me->add("combat_exp",-100000000);
	if(me->query("zhanhuns") < 1 )
	{
	zhanhun = new("/clone/pet/zhanhun");
	zhanhun->set_name(me->query("name")+"ս��",({me->query("id")+" zhanhun"}));
	zhanhun->set("owner",me->query("id"));
	zhanhun->set("zhanhun",1); 
	zhanhun->set("level",0);
	zhanhun->move(environment(me));
	zhanhun->set_leader(me);
	me->set("zhanhuns",1);
	me->set("zhanhunname",me->query("name")+"ս��");
	me->set("zhanhunid",me->query("id")+" zhanhun");
	write("ս���óɹ���\n");
	
   }else
   {
   write("���Ѿ���ս����\n");   
   }
   
   	}else
	if(arg=="call")
	{
   if(!me->query("zhanhuns"))
   return notify_fail("�㻹û��ս���أ�\n");
    if(me->query_temp("is_change"))
    return notify_fail("���Ѿ���ս�긽���ˣ������������ԣ�\n");
		zhanhuns = children("/clone/pet/zhanhun");
		for(i=0;i<sizeof(zhanhuns);i++)
		{
			if(zhanhuns[i]->query("owner")==me->query("id"))
			{
			
				zhanhuns[i]->set("max_qi",me->query("max_qi"));
				zhanhuns[i]->set("eff_qi",me->query("eff_qi"));
				zhanhuns[i]->set("eff_jing",me->query("eff_jing"));
				zhanhuns[i]->set("qi",me->query("qi"));
				zhanhuns[i]->set("max_neili",me->query("max_neili"));
				zhanhuns[i]->set("neili",me->query("neili"));
				zhanhuns[i]->set("max_jing",me->query("max_jing"));		
				zhanhuns[i]->set("jing",me->query("jing"));
				zhanhuns[i]->set("max_jingli",me->query("max_jingli"));
				zhanhuns[i]->set("jingli",me->query("jingli"));		
					zhanhuns[i]->save();		
				zhanhuns[i]->move(environment(me));
				return 1;
			}
		}
		zhanhun = new("/clone/pet/zhanhun");
		zhanhun->set("owner",me->query("id"));
		zhanhun->set_name(zhanhun->query("name"),({me->query("id")+" zhanhun"}));
		zhanhun->restore();
		zhanhun->move(environment(me));
		zhanhun->set_leader(me);
		zhanhun->save();	
		
	}
	else if(arg=="gone")
	{
	    if(!me->query("zhanhuns"))
      return notify_fail("�㻹û��ս���أ�\n");
        if(me->query_temp("is_change"))
    return notify_fail("���Ѿ���ս�긽���ˣ��������������أ�\n");
		zhanhuns = children("/clone/pet/zhanhun");
		for(i=0;i<sizeof(zhanhuns);i++)
		{
			if(zhanhuns[i]->query("owner")==me->query("id"))
			{
				zhanhuns[i]->set("eff_qi",me->query("eff_qi"));
				zhanhuns[i]->set("eff_jing",me->query("eff_jing"));
			    zhanhuns[i]->set("max_qi",me->query("max_qi"));
				zhanhuns[i]->set("qi",me->query("qi"));
				zhanhuns[i]->set("max_neili",me->query("max_neili"));
				zhanhuns[i]->set("neili",me->query("neili"));
				zhanhuns[i]->set("max_jing",me->query("max_jing"));
				zhanhuns[i]->set("jing",me->query("jing"));
				zhanhuns[i]->set("max_jingli",me->query("max_jingli"));
				zhanhuns[i]->set("jingli",me->query("jingli"));		
				zhanhuns[i]->save();						
				destruct(zhanhuns[i]);
				write("���ս�걻�����ˡ�\n");
				return 1;
			}
		}
		return notify_fail("���ս���Ѿ������ˣ�\n");
	}else if(arg=="score")
	{
	    if(!me->query("zhanhuns"))
        return notify_fail("�㻹û��ս���أ�\n");
		if(!(zhanhun=present(me->query("id")+" zhanhun",environment(me))))
	return notify_fail("���ս�겻�����ǰ���޷����壡\n");		
		str = ZJOBLONG;
		str += zhanhun->short()+ZJBR;
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		str += sprintf("��*ս��ȼ�* %d��"NOR""ZJBR,zhanhun->query("level"));
		str += sprintf("����������%d��"NOR""ZJBR,zhanhun->query("str"));
		str += sprintf("��������%d  "NOR""ZJBR,zhanhun->query("dex"));
		str += sprintf("�������ǡ�%d  "NOR""ZJBR,zhanhun->query("con"));
		str += sprintf("�������ԡ�%d  "NOR""ZJBR,zhanhun->query("int"));
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		str += sprintf("���������˺���%d��"NOR""ZJBR,zhanhun->query("apply/damage"));
		str += sprintf("���������˺���%d  "NOR""ZJBR,zhanhun->query("apply/unarmed_damage"));
		str += sprintf("����װ��������%d��"NOR""ZJBR,zhanhun->query("apply/armor"));
		str += sprintf("������֮�˺���%d��"NOR""ZJBR,zhanhun->query("apply/add_poison"));
		str += sprintf("����ħ֮�˺���%d  "NOR""ZJBR,zhanhun->query("apply/add_magic"));
		str += sprintf("��������͵ȡ��%d��"NOR""ZJBR,zhanhun->query("apply/leech_neili"));
		str += sprintf("��������͵ȡ��%d��"NOR""ZJBR,zhanhun->query("apply/leech_qi"));
		str += sprintf("���������мܡ�%d  "NOR""ZJBR,zhanhun->query("apply/avoid_parry"));
		str += sprintf("�������Ӷ�����%d��"NOR""ZJBR,zhanhun->query("apply/avoid_dodge"));
		str += sprintf("�������״�͸��%d��"NOR""ZJBR,zhanhun->query("apply/through_armor"));
		str += sprintf("����˫���˺���%d  "NOR""ZJBR,zhanhun->query("apply/double_damage"));
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		write(str+"\n");
	}else
	 if(arg=="change")
	{	
	if(!me->query("zhanhuns"))
    return notify_fail("�㻹û��ս���أ�\n");
    if(me->query_temp("is_change"))
    return notify_fail("���Ѿ���ս�긽���ˣ�\n");
	if(!(zhanhun=present(me->query("id")+" zhanhun",environment(me))))
	return notify_fail("���ս�겻�����ǰ���޷�������\n");	
	me->set_temp("is_change",1);  	
	zhanhun->move(me);
	zhanhun->set_weight(1);
	zhanhun->set("no_drop",1);
	zhanhun->set("no_give",1);
	zhanhun->set("no_sell",1);
	me->add_temp("apply/add_poison",zhanhun->query("apply/add_poison"));
	me->add_temp("apply/add_magic",zhanhun->query("apply/add_magic"));
	me->add_temp("apply/leech_neili",zhanhun->query("apply/leech_neili"));
	me->add_temp("apply/leech_qi",zhanhun->query("apply/leech_qi"));
	me->add_temp("apply/avoid_parry",zhanhun->query("apply/avoid_parry"));
	me->add_temp("apply/avoid_dodge",zhanhun->query("apply/avoid_dodge"));
	me->add_temp("apply/through_armor",zhanhun->query("apply/through_armor"));
	me->add_temp("apply/double_damage",zhanhun->query("apply/double_damage"));
    me->add_temp("apply/str",zhanhun->query("str")*1/1);
    me->add_temp("apply/con",zhanhun->query("con")*1/1);
    me->add_temp("apply/int",zhanhun->query("int")*1/1);
    me->add_temp("apply/dex",zhanhun->query("dex")*1/1);
    zhanhun->save();		
	write(HIR"��ִ�������룬�з�����׽٣�"HIC"һ��ս��������������Ҳ����죡\n"NOR);
	return 1;
	}else
	if(arg=="jiechu")
	{	
	if(!me->query("zhanhuns"))
    return notify_fail("�㻹û��ս���أ�\n");
if(!me->query_temp("is_change"))
return notify_fail("�㲢û����ս�긽�壡\n");
zhanhuns = children("/clone/pet/zhanhun");
	for(i=0;i<sizeof(zhanhuns);i++)
	{
	if(zhanhuns[i]->query("owner")==me->query("id"))
	{
	zhanhuns[i]->move(environment(me));				
	me->add_temp("apply/add_poison",-zhanhuns[i]->query("apply/add_poison"));
	me->add_temp("apply/add_magic",-zhanhuns[i]->query("apply/add_magic"));
	me->add_temp("apply/leech_neili",-zhanhuns[i]->query("apply/leech_neili"));
	me->add_temp("apply/leech_qi",-zhanhuns[i]->query("apply/leech_qi"));
	me->add_temp("apply/avoid_parry",-zhanhuns[i]->query("apply/avoid_parry"));
	me->add_temp("apply/avoid_dodge",-zhanhuns[i]->query("apply/avoid_dodge"));
	me->add_temp("apply/through_armor",-zhanhuns[i]->query("apply/through_armor"));
	me->add_temp("apply/double_damage",-zhanhuns[i]->query("apply/double_damage"));
	me->add_temp("apply/str",-zhanhuns[i]->query("str")*1/1);
    me->add_temp("apply/con",-zhanhuns[i]->query("con")*1/1);
    me->add_temp("apply/int",-zhanhuns[i]->query("int")*1/1);
    me->add_temp("apply/dex",-zhanhuns[i]->query("dex")*1/1);
	me->set_temp("is_change",0);						
	zhanhuns[i]->delete("no_give");
    zhanhuns[i]->delete("no_drop");	
	zhanhuns[i]->delete("no_sell");		
	zhanhuns[i]->save();		
			}						
		}				
	    write(MAG"ս����塣\n"NOR);	
	}else
	if(arg=="lvl")
	{	
		//int l=zhanhun->query("level");
		//int m=200*zhanhun->query("level");
	    if(!me->query("zhanhuns"))
        return notify_fail("�㻹û��ս���أ�\n");
		if(!(zhanhun=present(me->query("id")+" zhanhun",environment(me))))
		return notify_fail("���ս�겻�����ǰ���޷��������ԣ�\n");			
		if(me->query("tianji1") < (1+1*zhanhun->query("level")))
		return notify_fail("���������㣬���ܶ�ս������ǿ������Ҫ"+(1+1*zhanhun->query("level"))+"�����\n");
		if(me->query("combat_exp") < (10000+5000*zhanhun->query("level")))
		return notify_fail("�����Ϊ���㣬���ܶ�ս������ǿ������Ҫ"+(10000+5000*zhanhun->query("level"))+"��Ϊ��\n");
		if (zhanhun->query("level") > 999)
		return notify_fail("���ս���Ѿ���ǿ�������£�\n");
        me->add("tianji1",-(1+1*zhanhun->query("level")));
		me->add("combat_exp",-(10000+5000*zhanhun->query("level")));
        zhanhun->add("apply/add_poison",1);
        zhanhun->add("apply/add_magic",1);
        zhanhun->add("apply/leech_neili",1);
        zhanhun->add("apply/leech_qi",1);
        zhanhun->add("apply/avoid_parry",1);
        zhanhun->add("apply/avoid_dodge",1);
        zhanhun->add("apply/through_armor",1);
        zhanhun->add("apply/double_damage",1);
        zhanhun->add("dex",1);
        zhanhun->add("con",1);
        zhanhun->add("str",1);
        zhanhun->add("int",1);
		zhanhun->add("level",1);
        zhanhun->save();
        write(MAG"ս��ǿ���ɹ���\n"NOR);
        
	}
	
	return 1;
	
}

