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
	
   return notify_fail(ZJOBLONG"你想进行什么操作：\n"
   ZJOBACTS2+ZJMENUF(3,3,9,30)+"觉醒铠甲:kaijia zhaomu\n");
  	}
   else      
   { 
   if(!me->query("kaijias"))
   return notify_fail("你还没有获得铠甲呢！\n");  
   return notify_fail(ZJOBLONG"你想对进行什么操作：\n"
   ZJOBACTS2+ZJMENUF(2,2,9,30)+"召唤铠甲:kaijia call"ZJSEP"隐藏铠甲:kaijia gone"ZJSEP"铠甲合体:kaijia change"ZJSEP"铠甲解体:kaijia jiechu"ZJSEP"查看属性:kaijia score"ZJSEP"强化铠甲:kaijia lvl\n");   
   }
   }
	else if(arg=="zhaomu")
	{	
	if (me->query("yuanbao") < 100000)
	return notify_fail("你的灵石不足10万！\n");	
	me->add("yuanbao",-100000);
	if (me->query("combat_exp") < 100000000)
	return notify_fail("你的经验不足1亿！\n");	
	me->add("combat_exp",-100000000);
	if(me->query("kaijias") < 1 )
	{
	kaijia = new("/clone/pet/kaijia");
	kaijia->set_name(me->query("name")+"铠甲",({me->query("id")+" kaijia"}));
	kaijia->set("owner",me->query("id"));
	kaijia->set("kaijia",1); 
	kaijia->set("level",0);
	kaijia->move(environment(me));
	kaijia->set_leader(me);
	me->set("kaijias",1);
	me->set("kaijianame",me->query("name")+"铠甲");
	me->set("kaijiaid",me->query("id")+" kaijia");
	write("铠甲获得成功！\n");
	
   }else
   {
   write("你已经有铠甲了\n");   
   }
   
   	}else
	if(arg=="call")
	{
   if(!me->query("kaijias"))
   return notify_fail("你还没有铠甲呢！\n");
    if(me->query_temp("is_change"))
    return notify_fail("你已经将铠甲合体了，请解除合体再试！\n");
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
      return notify_fail("你还没有铠甲呢！\n");
        if(me->query_temp("is_change"))
    return notify_fail("你已经将铠甲合体了，请解除合体再隐藏！\n");
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
				write("你的铠甲被隐藏了。\n");
				return 1;
			}
		}
		return notify_fail("你的铠甲已经隐藏了！\n");
	}else if(arg=="score")
	{
	    if(!me->query("kaijias"))
        return notify_fail("你还没有铠甲呢！\n");
		if(!(kaijia=present(me->query("id")+" kaijia",environment(me))))
	return notify_fail("你的铠甲不在你跟前，无法合体！\n");		
		str = ZJOBLONG;
		str += kaijia->short()+ZJBR;
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		str += sprintf("　*铠甲等级* %d　"NOR""ZJBR,kaijia->query("level"));
		str += sprintf("　〖臂力〗%d　"NOR""ZJBR,kaijia->query("str"));
		str += sprintf("　〖身法〗%d  "NOR""ZJBR,kaijia->query("dex"));
		str += sprintf("　〖根骨〗%d  "NOR""ZJBR,kaijia->query("con"));
		str += sprintf("　〖悟性〗%d  "NOR""ZJBR,kaijia->query("int"));
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		str += sprintf("　〖武器伤害〗%d　"NOR""ZJBR,kaijia->query("apply/damage"));
		str += sprintf("　〖空手伤害〗%d  "NOR""ZJBR,kaijia->query("apply/unarmed_damage"));
		str += sprintf("　〖装备防御〗%d　"NOR""ZJBR,kaijia->query("apply/armor"));
		str += sprintf("　〖内力上限〗%d　"NOR""ZJBR,kaijia->query("apply/max_neili"));
		str += sprintf("　〖气血上限〗%d  "NOR""ZJBR,kaijia->query("apply/max_qi"));
		str += sprintf("　〖精神上限〗%d　"NOR""ZJBR,kaijia->query("apply/max_jingli"));
		str += sprintf("　〖精力上限〗%d　"NOR""ZJBR,kaijia->query("apply/max_jing"));
		str += sprintf("　〖实战上限〗%d  "NOR""ZJBR,kaijia->query("apply/max_experience"));
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		write(str+"\n");
	}else
	 if(arg=="change")
	{	
	if(!me->query("kaijias"))
    return notify_fail("你还没有铠甲呢！\n");
    if(me->query_temp("is_change"))
    return notify_fail("你已经和铠甲合体了！\n");
	if(!(kaijia=present(me->query("id")+" kaijia",environment(me))))
	return notify_fail("你的铠甲不在你跟前，无法改名！\n");	
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
	write(HIR"掌执天阴幻祀，行罚罡阳雷劫！"HIC"一具铠甲合我身，我命由我不由天！\n"NOR);
	return 1;
	}else
	if(arg=="jiechu")
	{	
	if(!me->query("kaijias"))
    return notify_fail("你还没有铠甲呢！\n");
if(!me->query_temp("is_change"))
return notify_fail("你并没有与铠甲合体！\n");
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
	    write(MAG"铠甲解体。\n"NOR);	
	}else
	if(arg=="lvl")
	{	
		//int l=kaijia->query("level");
		//int m=200*kaijia->query("level");
	    if(!me->query("kaijias"))
        return notify_fail("你还没有铠甲呢！\n");
		if(!(kaijia=present(me->query("id")+" kaijia",environment(me))))
		return notify_fail("你的铠甲不在你跟前，无法提升属性！\n");			
		if(me->query("yuanbao") < (1000+500*kaijia->query("level")))
		return notify_fail("你的灵石不足，不能对铠甲升级强化，需要"+(1000+500*kaijia->query("level"))+"灵石！\n");
		if(me->query("combat_exp") < (10000+5000*kaijia->query("level")))
		return notify_fail("你的修为不足，不能对铠甲升级强化，需要"+(10000+5000*kaijia->query("level"))+"修为！\n");
		if (kaijia->query("level") > 999)
		return notify_fail("你的铠甲已经被强化到极致！\n");
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
        write(MAG"铠甲强化成功。\n"NOR);
        
	}
	
	return 1;
	
}

