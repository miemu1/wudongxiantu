// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *kaijias,kaijia;
	int i;
	string str;
	int armor;
	string longs;
	
	if(!arg)
	{
	if(me->query("kaijias") < 1 )
	{
	
   return notify_fail(ZJOBLONG"�������ʲô������\n"
   ZJOBACTS2+ZJMENUF(3,3,9,30)+"��������:kaijia zhaomu\n");
  	}
   else      
   { 
   if(!me->query("kaijias"))
   return notify_fail("�㻹û�л�������أ�\n");  
   return notify_fail(ZJOBLONG"����Խ���ʲô������\n"
   ZJOBACTS2+ZJMENUF(2,2,9,30)+"�ٻ�����:kaijia call"ZJSEP"��������:kaijia gone"ZJSEP"���׺���:kaijia change"ZJSEP"���׽���:kaijia jiechu"ZJSEP"�鿴����:kaijia score"ZJSEP"ǿ������:kaijia lvl\n");   
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
	if(me->query("kaijias") < 1 )
	{
	kaijia = new("/clone/pet/kaijia");
	kaijia->set_name(me->query("name")+"����",({me->query("id")+" kaijia"}));
	kaijia->set("owner",me->query("id"));
	kaijia->set("kaijia",1); 
	kaijia->set("level",0);
	kaijia->move(environment(me));
	kaijia->set_leader(me);
	me->set("kaijias",1);
	me->set("kaijianame",me->query("name")+"����");
	me->set("kaijiaid",me->query("id")+" kaijia");
	write("���׻�óɹ���\n");
	
   }else
   {
   write("���Ѿ���������\n");   
   }
   
   	}else
	if(arg=="call")
	{
   if(!me->query("kaijias"))
   return notify_fail("�㻹û�������أ�\n");
    if(me->query_temp("is_change"))
    return notify_fail("���Ѿ������׺����ˣ������������ԣ�\n");
		kaijias = children("/clone/pet/kaijia");
		for(i=0;i<sizeof(kaijias);i++)
		{
			if(kaijias[i]->query("owner")==me->query("id"))
			{
			
				kaijias[i]->set("max_qi",me->query("max_qi"));
				kaijias[i]->set("eff_qi",me->query("eff_qi"));
				kaijias[i]->set("eff_jing",me->query("eff_jing"));
				kaijias[i]->set("qi",me->query("qi"));
				kaijias[i]->set("max_neili",me->query("max_neili"));
				kaijias[i]->set("neili",me->query("neili"));
				kaijias[i]->set("max_jing",me->query("max_jing"));		
				kaijias[i]->set("jing",me->query("jing"));
				kaijias[i]->set("max_jingli",me->query("max_jingli"));
				kaijias[i]->set("jingli",me->query("jingli"));		
					kaijias[i]->save();		
				kaijias[i]->move(environment(me));
				return 1;
			}
		}
		kaijia = new("/clone/pet/kaijia");
		kaijia->set("owner",me->query("id"));
		kaijia->set_name(kaijia->query("name"),({me->query("id")+" kaijia"}));
		kaijia->restore();
		kaijia->move(environment(me));
		kaijia->set_leader(me);
		kaijia->save();	
		
	}
	else if(arg=="gone")
	{
	    if(!me->query("kaijias"))
      return notify_fail("�㻹û�������أ�\n");
        if(me->query_temp("is_change"))
    return notify_fail("���Ѿ������׺����ˣ��������������أ�\n");
		kaijias = children("/clone/pet/kaijia");
		for(i=0;i<sizeof(kaijias);i++)
		{
			if(kaijias[i]->query("owner")==me->query("id"))
			{
				kaijias[i]->set("eff_qi",me->query("eff_qi"));
				kaijias[i]->set("eff_jing",me->query("eff_jing"));
			kaijias[i]->set("max_qi",me->query("max_qi"));
				kaijias[i]->set("qi",me->query("qi"));
				kaijias[i]->set("max_neili",me->query("max_neili"));
				kaijias[i]->set("neili",me->query("neili"));
				kaijias[i]->set("max_jing",me->query("max_jing"));
				kaijias[i]->set("jing",me->query("jing"));
				kaijias[i]->set("max_jingli",me->query("max_jingli"));
				kaijias[i]->set("jingli",me->query("jingli"));		
				kaijias[i]->save();						
				destruct(kaijias[i]);
				write("������ױ������ˡ�\n");
				return 1;
			}
		}
		return notify_fail("��������Ѿ������ˣ�\n");
	}else if(arg=="score")
	{
	    if(!me->query("kaijias"))
        return notify_fail("�㻹û�������أ�\n");
		if(!(kaijia=present(me->query("id")+" kaijia",environment(me))))
	return notify_fail("������ײ������ǰ���޷����壡\n");		
		str = ZJOBLONG;
		str += kaijia->short()+ZJBR;
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		str += sprintf("��*���׵ȼ�* %d��"NOR""ZJBR,kaijia->query("level"));
		str += sprintf("����������%d��"NOR""ZJBR,kaijia->query("str"));
		str += sprintf("��������%d  "NOR""ZJBR,kaijia->query("dex"));
		str += sprintf("�������ǡ�%d  "NOR""ZJBR,kaijia->query("con"));
		str += sprintf("�������ԡ�%d  "NOR""ZJBR,kaijia->query("int"));
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		str += sprintf("���������˺���%d��"NOR""ZJBR,kaijia->query("apply/damage"));
		str += sprintf("���������˺���%d  "NOR""ZJBR,kaijia->query("apply/unarmed_damage"));
		str += sprintf("����װ��������%d��"NOR""ZJBR,kaijia->query("apply/armor"));
		str += sprintf("�����������ޡ�%d��"NOR""ZJBR,kaijia->query("apply/max_neili"));
		str += sprintf("������Ѫ���ޡ�%d  "NOR""ZJBR,kaijia->query("apply/max_qi"));
		str += sprintf("�����������ޡ�%d��"NOR""ZJBR,kaijia->query("apply/max_jingli"));
		str += sprintf("�����������ޡ�%d��"NOR""ZJBR,kaijia->query("apply/max_jing"));
		str += sprintf("����ʵս���ޡ�%d  "NOR""ZJBR,kaijia->query("apply/max_experience"));
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		write(str+"\n");
	}else
	 if(arg=="change")
	{	
	if(!me->query("kaijias"))
    return notify_fail("�㻹û�������أ�\n");
    if(me->query_temp("is_change"))
    return notify_fail("���Ѿ������׺����ˣ�\n");
	if(!(kaijia=present(me->query("id")+" kaijia",environment(me))))
	return notify_fail("������ײ������ǰ���޷�������\n");	
	me->set_temp("is_change",1);  	
	kaijia->move(me);
	kaijia->set_weight(1);
	kaijia->set("no_drop",1);
	kaijia->set("no_give",1);
	kaijia->set("no_sell",1);
	me->add_temp("apply/max_neili",kaijia->query("apply/max_neili"));
	me->add_temp("apply/max_qi",kaijia->query("apply/max_qi"));
	me->add_temp("apply/max_jingli",kaijia->query("apply/max_jingli"));
	me->add_temp("apply/max_jing",kaijia->query("apply/max_jing"));
	me->add_temp("apply/max_experience",kaijia->query("apply/max_experience"));
    me->add_temp("apply/str",kaijia->query("str")*1/1);
    me->add_temp("apply/con",kaijia->query("con")*1/1);
    me->add_temp("apply/int",kaijia->query("int")*1/1);
    me->add_temp("apply/dex",kaijia->query("dex")*1/1);
    kaijia->save();		
	write(HIR"��ִ�������룬�з�����׽٣�"HIC"һ�����׺������������Ҳ����죡\n"NOR);
	return 1;
	}else
	if(arg=="jiechu")
	{	
	if(!me->query("kaijias"))
    return notify_fail("�㻹û�������أ�\n");
if(!me->query_temp("is_change"))
return notify_fail("�㲢û�������׺��壡\n");
kaijias = children("/clone/pet/kaijia");
	for(i=0;i<sizeof(kaijias);i++)
	{
	if(kaijias[i]->query("owner")==me->query("id"))
	{
	kaijias[i]->move(environment(me));				
	me->add_temp("apply/max_neili",-kaijias[i]->query("apply/max_neili"));
	me->add_temp("apply/max_qi",-kaijias[i]->query("apply/max_qi"));
	me->add_temp("apply/max_jingli",-kaijias[i]->query("apply/max_jingli"));
	me->add_temp("apply/max_jing",-kaijias[i]->query("apply/max_jing"));
	me->add_temp("apply/max_experience",-kaijias[i]->query("apply/max_experience"));
	me->add_temp("apply/str",-kaijias[i]->query("str")*1/1);
    me->add_temp("apply/con",-kaijias[i]->query("con")*1/1);
    me->add_temp("apply/int",-kaijias[i]->query("int")*1/1);
    me->add_temp("apply/dex",-kaijias[i]->query("dex")*1/1);
	me->set_temp("is_change",0);						
	kaijias[i]->delete("no_give");
    kaijias[i]->delete("no_drop");	
	kaijias[i]->delete("no_sell");		
	kaijias[i]->save();		
			}						
		}				
	    write(MAG"���׽��塣\n"NOR);	
	}else
	if(arg=="lvl")
	{	
		//int l=kaijia->query("level");
		//int m=200*kaijia->query("level");
	    if(!me->query("kaijias"))
        return notify_fail("�㻹û�������أ�\n");
		if(!(kaijia=present(me->query("id")+" kaijia",environment(me))))
		return notify_fail("������ײ������ǰ���޷��������ԣ�\n");			
		if(me->query("yuanbao") < (1000+500*kaijia->query("level")))
		return notify_fail("�����ʯ���㣬���ܶ���������ǿ������Ҫ"+(1000+500*kaijia->query("level"))+"��ʯ��\n");
		if(me->query("combat_exp") < (10000+5000*kaijia->query("level")))
		return notify_fail("�����Ϊ���㣬���ܶ���������ǿ������Ҫ"+(10000+5000*kaijia->query("level"))+"��Ϊ��\n");
		if (kaijia->query("level") > 999)
		return notify_fail("��������Ѿ���ǿ�������£�\n");
        me->add("yuanbao",-(1000+500*kaijia->query("level")));
		me->add("combat_exp",-(10000+5000*kaijia->query("level")));
        kaijia->add("apply/damage",500);
        kaijia->add("apply/unarmed_damage",500);
        kaijia->add("apply/armor",500);
        kaijia->add("apply/max_neili",500);
        kaijia->add("apply/max_qi",500);
        kaijia->add("apply/max_jingli",100);
        kaijia->add("apply/max_jing",100);
        kaijia->add("apply/max_experience",100);
        kaijia->add("dex",1);
        kaijia->add("con",1);
        kaijia->add("str",1);
        kaijia->add("int",1);
		kaijia->add("level",1);
        kaijia->save();
        write(MAG"����ǿ���ɹ���\n"NOR);
        
	}
	
	return 1;
	
}

