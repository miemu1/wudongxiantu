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
	
   return notify_fail(ZJOBLONG"你想对宠物进行什么操作：\n"
   ZJOBACTS2+ZJMENUF(3,3,9,30)+"领养宠物:pet zhaomu\n");
  	}
   else      
   { 
   if(!me->query("pets"))
   return notify_fail("你还没有宠物呢！\n");  
   return notify_fail(ZJOBLONG"你想对宠物进行什么操作：\n"
   ZJOBACTS2+ZJMENUF(2,2,9,30)+"召唤宠物:pet call"ZJSEP"收回宠物:pet gone"ZJSEP"开始助战:pet change"ZJSEP"停止助战:pet jiechu"ZJSEP"查看属性:pet score"ZJSEP"提升属性:pet lvl"ZJSEP"修改描述:petlong\n");   
   }
   }
	else if(arg=="zhaomu")
	{	
	if (me->query("yuanbao") < 10000)
	return notify_fail("你的灵石不足1万！\n");	
	me->add("yuanbao",-10000);
	if(me->query("pets") < 1 )
	{
	pet = new("/clone/pet/pet");
	pet->set_name(me->query("name")+"的宠物",({me->query("id")+" pet"}));
	pet->set("owner",me->query("id"));
	pet->set("pet",1); 
	pet->set("level",0);
	pet->move(environment(me));
	pet->set_leader(me);
	me->set("pets",1);
	me->set("petname",me->query("name")+"的宠物");
	me->set("petid",me->query("id")+" pet");
	write("领取成功\n");
	
   }else
   {
   write("你已经有宠物了\n");   
   }
   
   
	}else
	if(arg=="call")
	{
   if(!me->query("pets"))
   return notify_fail("你还没有宠物呢！\n");
    if(me->query_temp("is_change"))
    return notify_fail("宠物已经助战了，请解除助战后再试\n");
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
      return notify_fail("你还没有宠物呢！\n");
        if(me->query_temp("is_change"))
    return notify_fail("宠物已经助战了，请解除助战再收回\n");
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
				write("你的宠物被收回去了。\n");
				return 1;
			}
		}
		return notify_fail("你的宠物已经收回去了！\n");
	}
	else if(arg=="score")
	{
	    if(!me->query("pets"))
        return notify_fail("你还没有宠物呢！\n");
		if(!(pet=present(me->query("id")+" pet",environment(me))))
	return notify_fail("你的宠物不在你跟前，无法化为内丹！\n");	
		str = ZJOBLONG;
		str += pet->short()+ZJBR;
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		str += sprintf("　*宠物等级* %d　"NOR""ZJBR,pet->query("level"));
		str += sprintf("　〖臂力〗%d　"NOR""ZJBR,pet->query("str"));
		str += sprintf("　〖身法〗%d  "NOR""ZJBR,pet->query("dex"));
		str += sprintf("　〖根骨〗%d  "NOR""ZJBR,pet->query("con"));
		str += sprintf("　〖悟性〗%d  "NOR""ZJBR,pet->query("int"));
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		str += sprintf("　〖武器伤害〗%d　"NOR""ZJBR,pet->query("apply/damage"));
		str += sprintf("　〖空手伤害〗%d  "NOR""ZJBR,pet->query("apply/unarmed_damage"));
		str += sprintf("　〖装备防御〗%d　"NOR""ZJBR,pet->query("apply/armor"));
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		write(str+"\n");
	}else
	 if(arg=="change")
	{	
	if(!me->query("pets"))
    return notify_fail("你还没有宠物呢！\n");
    if(me->query_temp("is_change"))
    return notify_fail("宠物已经助战了！\n");
	if(!(pet=present(me->query("id")+" pet",environment(me))))
	return notify_fail("你的宠物不在你跟前，无法化为内丹！\n");	
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
	write(HIR"顿时宠物化为一股浓烟随后越来越浓直到化为一颗直径为一厘米的内丹！"HIC"散射出奇异的光彩进入了你的背包里面，你突然你的力气变大了不少！\n"NOR);
	return 1;
	}else
	if(arg=="jiechu")
	{	
	if(!me->query("pets"))
    return notify_fail("你还没有宠物呢！\n");
    if(!me->query_temp("is_change"))
    return notify_fail("宠物不在你背包里，你想解除什么？\n");
    
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
	    write(MAG"解除！宠物化为一股浓烟从你的背包里出来了。\n"NOR);	
	}else
	if(arg=="lvl")
	{
	    if(!me->query("pets"))
        return notify_fail("你还没有宠物呢！\n");
		if(!(pet=present(me->query("id")+" pet",environment(me))))
		return notify_fail("你的宠物不在你跟前，无法提升属性！\n");		
		if(me->query("jifeng") < (2000+500*pet->query("level")))
		return notify_fail("你的点券不足，不能进行宠物升级，需要"+(2000+500*pet->query("level"))+"点券！\n");
		if (pet->query("level") > 999)
		return notify_fail("你的宠物已经达到极致！\n");
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
        write(MAG"升级成功，收回放出生效。\n"NOR);
        
	}
	
	return 1;
	
}

