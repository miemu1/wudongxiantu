#include <ansi.h>;
inherit "/kungfu/class/generate/chinese";
//�ٲ�Ǳ����ά�����
void create()
{
	string *fams;

	set_name("��������", ({"shilian dizi",}));
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");

	setup();
	fams = keys(init_family);
	setup_family(fams[random(sizeof(fams))]);
}

int accept_fight(object me)
{
	tell_object(me,"������η��η�ŵ�������ʵ�����۷壿\n");
	return 0;
}

void init()
{
	object me = this_object();
	mapping smap = me->query_skills();
	int i;
	string *skills;
	int lvl;
	if(environment()->query("sllv")==10||environment()->query("sllv")==30)
	lvl = environment()->query("sllv")*1500;	
    else if(environment()->query("sllv")==70)
	lvl = environment()->query("sllv")*1000;	
    else
	lvl = environment()->query("sllv")*30;

	skills = keys(smap);
	for(i=0;i<sizeof(skills);i++)
	{
		if(environment()->query("sllv")==10||environment()->query("sllv")==30||environment()->query("sllv")==70)
		me->set_skill(skills[i],lvl/3);
	else
	   me->set_skill(skills[i],lvl/2);
	}

	me->set("combat_exp",lvl*lvl/10*lvl+10000);
if(environment()->query("sllv")==10)
{
	me->set_temp("apply/damage",8000);
	me->set_temp("apply/unarmed_damage",8000);	
}
else if(environment()->query("sllv")==30)
{
	me->set_temp("apply/damage",1000);
	me->set_temp("apply/unarmed_damage",1000);		
}
else if(environment()->query("sllv")==70)
{
	me->set_temp("apply/damage",8000);
	me->set_temp("apply/armor",8000);
	me->set_temp("apply/armor1",8000);
	me->set_temp("apply/unarmed_damage",8000);		
}
else{
	me->set_temp("apply/damage",100+lvl/2);
	me->set_temp("apply/unarmed_damage",100+lvl/2);
}
	me->set("jiali",lvl);
	me->set("texxiaopojia",lvl);
	me->set("qi",lvl*5000);
	me->set("eff_qi",lvl*6000);
	me->set("max_qi",lvl*6000);
	me->set("jing",lvl*6000);
	me->set("eff_jing",lvl*6000);
	me->set("max_jing",lvl*6000);
	me->set("neili",lvl*6000);
	me->set("max_neili",lvl*6000);
}

void die()
{
	int m,sllv,i,pot,exp,lvl,a;
	object weap,bo,me = this_object();
	object *inv,ob,obj,gift,gift1;
	string *items,str;
	mapping give;
    //zhandojieshu();
	sllv = environment()->query("sllv");

     a=environment()->query("sllv");
	if (objectp(ob = query_last_damage_from())&&environment(me)==environment(ob))
	{
/*if(environment()->query("sllv")==10||environment()->query("sllv")==30||environment()->query("sllv")==70)
{
    gift = new("/clone/vip/tupodan");
    gift->set_amount(a);
    gift->move(ob);
    gift = new("/clone/vip/gjtupodan");
    gift->set_amount(a/2);
    gift->move(ob);
}*/
/*else{
    gift = new("/clone/vip/tupodan");
    gift->move(ob);
}*/
   if(environment()->query("sllv")==10&&!ob->query("jhxx"))
   {
	   ob->add("gain/armor",100);
	   ob->add("gain/max_qi",5555);
	   ob->set("jhxx",1);
	   tell_object(ob, sprintf(HIW "������"HIG"��������"HIW"�ƺţ�\n"));
   }
   else if(environment()->query("sllv")==30&&!ob->query("jhxx"))
   {
	   ob->add("gain/armor",300);
	   ob->add("gain/damage",300);
	   ob->add("gain/max_qi",25000);
	   ob->set("wlgs",1);
	   tell_object(ob, sprintf(HIW "������"HIY"���ָ���"HIW"�ƺţ�\n")); 
   }
   else if(environment()->query("sllv")==70&&!me->query("jhxx"))
   {
	   ob->add("gain/armor",1000);
	   ob->add("gain/damage",1000);
	   ob->add("gain/max_qi",50000);
	   ob->set("jhcs",1);
	   ob->move("/d/city/kedian");
	   tell_object(ob, sprintf(HIW "������"HIC"����"HIY"��˵"HIW"�ƺţ����ͨ�������!\n"NOR"")); 
   }
		exp =(random(100) + sllv*50);
		pot =(random(100) + sllv*60);
         ob->add("potential",pot);
		 ob->add("combat_exp",exp);
		 if(environment()->query("sllv")==10||environment()->query("sllv")==30||environment()->query("sllv")==70)
		 {
		tell_object(ob, sprintf(HIG "�����"+query("name")+"�������%s��Ǳ�ܡ�%s����Ϊ��"NOR"\n",
				chinese_number(pot),chinese_number(exp),chinese_number(a),chinese_number(a/2)));
		 }
		 else{
tell_object(ob, sprintf(HIG "�����"+query("name")+"�������%s��Ǳ�ܡ�%s����Ϊ��"NOR"\n",
				chinese_number(pot),chinese_number(exp)));
		 }

		ob->add("wudaota", 1);
		if(!ob->query("wudaotalv")||ob->query("wudaotalv")<ob->query("wudaota"))
			ob->set("wudaotalv",ob->query("wudaota"));

		lvl = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333))/10;
		if((ob->query("wudaota")-lvl)>70)
			ob->force_me("slover1");
		else
			environment()->nextlv(3);
		destruct(me);
	}
	else
	{
		inv = all_inventory(environment());
		for(i=0;i<sizeof(inv);i++)
		{
			if(playerp(inv[i]))
				inv[i]->move("/d/fuben/wudaotai/wudaotai");
		}
		destruct(environment());
	}
}
