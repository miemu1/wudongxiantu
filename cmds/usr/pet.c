// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *pets,pet;
	int i;
	string str;
	int armor;
	string longs;
	
	if(!arg)
	{
	if(me->query("pets") < 1 )
	{
	
   return notify_fail(ZJOBLONG"����Գ������ʲô������\n"
   ZJOBACTS2+ZJMENUF(3,3,9,30)+"��������:pet zhaomu\n");
  	}
   else      
   { 
   if(!me->query("pets"))
   return notify_fail("�㻹û�г����أ�\n");  
   return notify_fail(ZJOBLONG"����Գ������ʲô������\n"
   ZJOBACTS2+ZJMENUF(2,2,9,30)+"�ٻ�����:pet call"ZJSEP"�ջس���:pet gone"ZJSEP"��ʼ��ս:pet change"ZJSEP"ֹͣ��ս:pet jiechu"ZJSEP"�鿴����:pet score"ZJSEP"��������:pet lvl"ZJSEP"�޸�����:petlong\n");   
   }
   }
	else if(arg=="zhaomu")
	{	
	if (me->query("yuanbao") < 10000)
	return notify_fail("�����ʯ����1��\n");	
	me->add("yuanbao",-10000);
	if(me->query("pets") < 1 )
	{
	pet = new("/clone/pet/pet");
	pet->set_name(me->query("name")+"�ĳ���",({me->query("id")+" pet"}));
	pet->set("owner",me->query("id"));
	pet->set("pet",1); 
	pet->set("level",0);
	pet->move(environment(me));
	pet->set_leader(me);
	me->set("pets",1);
	me->set("petname",me->query("name")+"�ĳ���");
	me->set("petid",me->query("id")+" pet");
	write("��ȡ�ɹ�\n");
	
   }else
   {
   write("���Ѿ��г�����\n");   
   }
   
   
	}else
	if(arg=="call")
	{
   if(!me->query("pets"))
   return notify_fail("�㻹û�г����أ�\n");
    if(me->query_temp("is_change"))
    return notify_fail("�����Ѿ���ս�ˣ�������ս������\n");
		pets = children("/clone/pet/pet");
		for(i=0;i<sizeof(pets);i++)
		{
			if(pets[i]->query("owner")==me->query("id"))
			{
			
				pets[i]->set("max_qi",me->query("max_qi"));
				pets[i]->set("eff_qi",me->query("eff_qi"));
				pets[i]->set("eff_jing",me->query("eff_jing"));
				pets[i]->set("qi",me->query("qi"));
				pets[i]->set("max_neili",me->query("max_neili"));
				pets[i]->set("neili",me->query("neili"));
				pets[i]->set("max_jing",me->query("max_jing"));		
				pets[i]->set("jing",me->query("jing"));
				pets[i]->set("max_jingli",me->query("max_jingli"));
				pets[i]->set("jingli",me->query("jingli"));		
					pets[i]->save();		
				pets[i]->move(environment(me));
				return 1;
			}
		}
		pet = new("/clone/pet/pet");
		pet->set("owner",me->query("id"));
		pet->set_name(pet->query("name"),({me->query("id")+" pet"}));
		pet->restore();
		pet->move(environment(me));
		pet->set_leader(me);
		pet->save();	
		
	}
	else if(arg=="gone")
	{
	    if(!me->query("pets"))
      return notify_fail("�㻹û�г����أ�\n");
        if(me->query_temp("is_change"))
    return notify_fail("�����Ѿ���ս�ˣ�������ս���ջ�\n");
		pets = children("/clone/pet/pet");
		for(i=0;i<sizeof(pets);i++)
		{
			if(pets[i]->query("owner")==me->query("id"))
			{
				pets[i]->set("eff_qi",me->query("eff_qi"));
				pets[i]->set("eff_jing",me->query("eff_jing"));
			pets[i]->set("max_qi",me->query("max_qi"));
				pets[i]->set("qi",me->query("qi"));
				pets[i]->set("max_neili",me->query("max_neili"));
				pets[i]->set("neili",me->query("neili"));
				pets[i]->set("max_jing",me->query("max_jing"));
				pets[i]->set("jing",me->query("jing"));
				pets[i]->set("max_jingli",me->query("max_jingli"));
				pets[i]->set("jingli",me->query("jingli"));		
				pets[i]->save();						
				destruct(pets[i]);
				write("��ĳ��ﱻ�ջ�ȥ�ˡ�\n");
				return 1;
			}
		}
		return notify_fail("��ĳ����Ѿ��ջ�ȥ�ˣ�\n");
	}
	else if(arg=="score")
	{
	    if(!me->query("pets"))
        return notify_fail("�㻹û�г����أ�\n");
		if(!(pet=present(me->query("id")+" pet",environment(me))))
	return notify_fail("��ĳ��ﲻ�����ǰ���޷���Ϊ�ڵ���\n");	
		str = ZJOBLONG;
		str += pet->short()+ZJBR;
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		str += sprintf("��*����ȼ�* %d��"NOR""ZJBR,pet->query("level"));
		str += sprintf("����������%d��"NOR""ZJBR,pet->query("str"));
		str += sprintf("��������%d  "NOR""ZJBR,pet->query("dex"));
		str += sprintf("�������ǡ�%d  "NOR""ZJBR,pet->query("con"));
		str += sprintf("�������ԡ�%d  "NOR""ZJBR,pet->query("int"));
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		str += sprintf("���������˺���%d��"NOR""ZJBR,pet->query("apply/damage"));
		str += sprintf("���������˺���%d  "NOR""ZJBR,pet->query("apply/unarmed_damage"));
		str += sprintf("����װ��������%d��"NOR""ZJBR,pet->query("apply/armor"));
		str += "�ǩ�������������������������������������"NOR+ZJBR;
		write(str+"\n");
	}else
	 if(arg=="change")
	{	
	if(!me->query("pets"))
    return notify_fail("�㻹û�г����أ�\n");
    if(me->query_temp("is_change"))
    return notify_fail("�����Ѿ���ս�ˣ�\n");
	if(!(pet=present(me->query("id")+" pet",environment(me))))
	return notify_fail("��ĳ��ﲻ�����ǰ���޷���Ϊ�ڵ���\n");	
	me->set_temp("is_change",1);  	
	pet->move(me);
	pet->set_weight(1);
	pet->set("no_drop",1);
	pet->set("no_give",1);
	pet->set("no_sell",1);
    me->add_temp("apply/str",pet->query("str")*3/4);
    me->add_temp("apply/con",pet->query("con")*3/4);
    me->add_temp("apply/int",pet->query("int")*3/4);
    me->add_temp("apply/dex",pet->query("dex")*3/4);
    pet->save();		
	write(HIR"��ʱ���ﻯΪһ��Ũ�����Խ��ԽŨֱ����Ϊһ��ֱ��Ϊһ���׵��ڵ���"HIC"ɢ�������Ĺ�ʽ�������ı������棬��ͻȻ�����������˲��٣�\n"NOR);
	return 1;
	}else
	if(arg=="jiechu")
	{	
	if(!me->query("pets"))
    return notify_fail("�㻹û�г����أ�\n");
    if(!me->query_temp("is_change"))
    return notify_fail("���ﲻ���㱳���������ʲô��\n");
    
        pets = children("/clone/pet/pet");
		for(i=0;i<sizeof(pets);i++)
		{
			if(pets[i]->query("owner")==me->query("id"))
			{
				pets[i]->move(environment(me));				
				me->add_temp("apply/str",-pets[i]->query("str")*3/4);
                me->add_temp("apply/con",-pets[i]->query("con")*3/4);
                me->add_temp("apply/int",-pets[i]->query("int")*3/4);
                me->add_temp("apply/dex",-pets[i]->query("dex")*3/4);
				me->set_temp("is_change",0);						
	     pets[i]->delete("no_give");
         pets[i]->delete("no_drop");	
	     pets[i]->delete("no_sell");		
	     pets[i]->save();		
			}						
		}				
	    write(MAG"��������ﻯΪһ��Ũ�̴���ı���������ˡ�\n"NOR);	
	}else
	if(arg=="lvl")
	{
	    if(!me->query("pets"))
        return notify_fail("�㻹û�г����أ�\n");
		if(!(pet=present(me->query("id")+" pet",environment(me))))
		return notify_fail("��ĳ��ﲻ�����ǰ���޷��������ԣ�\n");		
		if(me->query("jifeng") < (2000+500*pet->query("level")))
		return notify_fail("��ĵ�ȯ���㣬���ܽ��г�����������Ҫ"+(2000+500*pet->query("level"))+"��ȯ��\n");
		if (pet->query("level") > 999)
		return notify_fail("��ĳ����Ѿ��ﵽ���£�\n");
		me->add("jifeng",-(2000+500*pet->query("level")));
        pet->add("apply/damage",35);
        pet->add("apply/unarmed_damage",35);
        pet->add("apply/armor",35);
        pet->add("dex",1);
        pet->add("con",1);
        pet->add("str",1);
        pet->add("int",1);
		pet->add("level",1);
        pet->save();
        write(MAG"�����ɹ����ջطų���Ч��\n"NOR);
        
	}
	
	return 1;
	
}

