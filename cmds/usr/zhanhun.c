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
	
   return notify_fail(ZJOBLONG"你想进行什么操作：\n"
   ZJOBACTS2+ZJMENUF(3,3,9,30)+"觉醒战魂:zhanhun zhaomu\n");
  	}
   else      
   { 
   if(!me->query("zhanhuns"))
   return notify_fail("你还没有获得战魂呢！\n");  
   return notify_fail(ZJOBLONG"你想对进行什么操作：\n"
   ZJOBACTS2+ZJMENUF(2,2,9,30)+"召唤战魂:zhanhun call"ZJSEP"隐藏战魂:zhanhun gone"ZJSEP"战魂附体:zhanhun change"ZJSEP"战魂解体:zhanhun jiechu"ZJSEP"查看属性:zhanhun score"ZJSEP"强化战魂:zhanhun lvl\n");   
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
	if(me->query("zhanhuns") < 1 )
	{
	zhanhun = new("/clone/pet/zhanhun");
	zhanhun->set_name(me->query("name")+"战魂",({me->query("id")+" zhanhun"}));
	zhanhun->set("owner",me->query("id"));
	zhanhun->set("zhanhun",1); 
	zhanhun->set("level",0);
	zhanhun->move(environment(me));
	zhanhun->set_leader(me);
	me->set("zhanhuns",1);
	me->set("zhanhunname",me->query("name")+"战魂");
	me->set("zhanhunid",me->query("id")+" zhanhun");
	write("战魂获得成功！\n");
	
   }else
   {
   write("你已经有战魂了\n");   
   }
   
   	}else
	if(arg=="call")
	{
   if(!me->query("zhanhuns"))
   return notify_fail("你还没有战魂呢！\n");
    if(me->query_temp("is_change"))
    return notify_fail("你已经将战魂附体了，请解除附体再试！\n");
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
      return notify_fail("你还没有战魂呢！\n");
        if(me->query_temp("is_change"))
    return notify_fail("你已经将战魂附体了，请解除附体再隐藏！\n");
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
				write("你的战魂被隐藏了。\n");
				return 1;
			}
		}
		return notify_fail("你的战魂已经隐藏了！\n");
	}else if(arg=="score")
	{
	    if(!me->query("zhanhuns"))
        return notify_fail("你还没有战魂呢！\n");
		if(!(zhanhun=present(me->query("id")+" zhanhun",environment(me))))
	return notify_fail("你的战魂不在你跟前，无法附体！\n");		
		str = ZJOBLONG;
		str += zhanhun->short()+ZJBR;
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		str += sprintf("　*战魂等级* %d　"NOR""ZJBR,zhanhun->query("level"));
		str += sprintf("　〖臂力〗%d　"NOR""ZJBR,zhanhun->query("str"));
		str += sprintf("　〖身法〗%d  "NOR""ZJBR,zhanhun->query("dex"));
		str += sprintf("　〖根骨〗%d  "NOR""ZJBR,zhanhun->query("con"));
		str += sprintf("　〖悟性〗%d  "NOR""ZJBR,zhanhun->query("int"));
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		str += sprintf("　〖武器伤害〗%d　"NOR""ZJBR,zhanhun->query("apply/damage"));
		str += sprintf("　〖空手伤害〗%d  "NOR""ZJBR,zhanhun->query("apply/unarmed_damage"));
		str += sprintf("　〖装备防御〗%d　"NOR""ZJBR,zhanhun->query("apply/armor"));
		str += sprintf("　〖毒之伤害〗%d　"NOR""ZJBR,zhanhun->query("apply/add_poison"));
		str += sprintf("　〖魔之伤害〗%d  "NOR""ZJBR,zhanhun->query("apply/add_magic"));
		str += sprintf("　〖内力偷取〗%d　"NOR""ZJBR,zhanhun->query("apply/leech_neili"));
		str += sprintf("　〖生命偷取〗%d　"NOR""ZJBR,zhanhun->query("apply/leech_qi"));
		str += sprintf("　〖忽视招架〗%d  "NOR""ZJBR,zhanhun->query("apply/avoid_parry"));
		str += sprintf("　〖忽视躲闪〗%d　"NOR""ZJBR,zhanhun->query("apply/avoid_dodge"));
		str += sprintf("　〖护甲穿透〗%d　"NOR""ZJBR,zhanhun->query("apply/through_armor"));
		str += sprintf("　〖双倍伤害〗%d  "NOR""ZJBR,zhanhun->query("apply/double_damage"));
		str += "┣━━━━━━━━━━━━━━━━━━┫"NOR+ZJBR;
		write(str+"\n");
	}else
	 if(arg=="change")
	{	
	if(!me->query("zhanhuns"))
    return notify_fail("你还没有战魂呢！\n");
    if(me->query_temp("is_change"))
    return notify_fail("你已经和战魂附体了！\n");
	if(!(zhanhun=present(me->query("id")+" zhanhun",environment(me))))
	return notify_fail("你的战魂不在你跟前，无法改名！\n");	
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
	write(HIR"掌执天阴幻祀，行罚罡阳雷劫！"HIC"一具战魂合我身，我命由我不由天！\n"NOR);
	return 1;
	}else
	if(arg=="jiechu")
	{	
	if(!me->query("zhanhuns"))
    return notify_fail("你还没有战魂呢！\n");
if(!me->query_temp("is_change"))
return notify_fail("你并没有与战魂附体！\n");
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
	    write(MAG"战魂解体。\n"NOR);	
	}else
	if(arg=="lvl")
	{	
		//int l=zhanhun->query("level");
		//int m=200*zhanhun->query("level");
	    if(!me->query("zhanhuns"))
        return notify_fail("你还没有战魂呢！\n");
		if(!(zhanhun=present(me->query("id")+" zhanhun",environment(me))))
		return notify_fail("你的战魂不在你跟前，无法提升属性！\n");			
		if(me->query("tianji1") < (1+1*zhanhun->query("level")))
		return notify_fail("你的天机不足，不能对战魂升级强化，需要"+(1+1*zhanhun->query("level"))+"天机！\n");
		if(me->query("combat_exp") < (10000+5000*zhanhun->query("level")))
		return notify_fail("你的修为不足，不能对战魂升级强化，需要"+(10000+5000*zhanhun->query("level"))+"修为！\n");
		if (zhanhun->query("level") > 999)
		return notify_fail("你的战魂已经被强化到极致！\n");
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
        write(MAG"战魂强化成功。\n"NOR);
        
	}
	
	return 1;
	
}

