//hp1.c ����״̬��Ѫ����ʾ
inherit F_CLEAN_UP;

string nts(int num);
int fighting_hp1(object me);
int normal_hp1(object ob);
int main(object me, string arg)
{
	object ob;
	mapping my;
	string sp;
	int buff;

	seteuid(getuid(me));
	ob = me;
 
	my = ob->query_entire_dbase();

	if (my["max_jing"] < 1 || my["max_qi"] < 1)
		return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");

	//ս��ʱ����ʾ״̬
	if(me->is_fighting() && fighting_hp1(me))
		return 1;
	
	return normal_hp1(me);
}

//�ж������Ƿ񳬹�һ�ڣ���������ˡ���ת��
string nts(int num)//number to string 
{
	int yiyi = 10000;
	string s_num;
	if(num >= yiyi) //һ��
		s_num = ""+(num/yiyi)+"��";
	else
		s_num = ""+num;
	return s_num;
}

int normal_hp1(object ob)
{
	mapping my;
	string sp;
	my = ob->query_entire_dbase();
	if(ob->query("env/hpp")==1)
	{
	sp  = ZJHPTXT+ZJMENUF(3,3,26,42)+sprintf("<��ϷID>��%s:100/100:%s",my["name"],"#990000FF");
	sp += "�U" + sprintf("��Ѫ.%d:%d/%d/%d:%s:%s",my["qi"],my["qi"],my["eff_qi"],my["max_qi"]+ob->query_gain_qi(),"#99FF0000","exert recover");
	sp += "�U" + sprintf("����.%d:%d/%d/%d:%s",my["neili"],my["neili"],my["max_neili"],ob->query_current_neili_limit(),"#990066FF");
	sp += "�U" + sprintf("����.%d:%d/%d/%d:%s:%s",my["jing"],my["jing"],my["eff_jing"],my["max_jing"]+ob->query_gain_jing(),"#996600CC","exert regenerate");
	sp += "�U" + sprintf("����.%d:%d/%d/%d:%s",my["jingli"],my["jingli"],my["max_jingli"],ob->query_current_jingli_limit(),"#996600CC",);
	sp += "�U" + sprintf("ŭ��.%d:%d/%d:%s",ob->query_craze(),ob->query_craze(),ob->query_max_craze(),"#996600CC");
//	sp += "�U" + sprintf("ʳ��.%d:%d/%d:%s",my["food"],my["food"],ob->max_food_capacity(),"#99FF6600");
//	sp += "�U" + sprintf("��ˮ.%d:%d/%d:%s",my["water"],my["water"],ob->max_water_capacity(),"#990000FF");
	sp += "�U" + sprintf("Ǳ��(��).%d:%d/%d/%d:%s",my["potential"]/10000-my["learned_points"]/10000,my["potential"]/10000-my["learned_points"]/10000,ob->query_potential_limit()/10000-my["potential"]/10000,ob->query_potential_limit()/10000,"#99006600");

	sp += "�U" + sprintf("��Ϊ(��).%d:%d/%d:%s",my["combat_exp"]/10000,my["combat_exp"]/10000,F_LEVEL->level_max_exp(ob)/10000,"#99006600");
	sp += "�U" + sprintf("Ԫ��EXP.%d:%d/%d/%d:%s",ob->query("yuanshen/exp"),ob->query("yuanshen/exp"),ob->query("yuanshen/exp"),ob->query("yuanshen/exp"),"#99006600",);
//	sp += "�U" + sprintf("Ԫ��exp��%d:100/100:%s",ob->query("yuanshen/exp"),"#99006600");

	sp += "\n";
	tell_object(ob, sp);
	return 1;
	}else
	{
	sp  = ZJHPTXT+ZJMENUF(5,5,28,45)+sprintf("%s:100/100:%s",my["name"],"#000000");
	sp += "�U" + sprintf("��Ѫ.%d:%d/%d/%d:%s:%s",my["qi"],my["qi"],my["eff_qi"],my["max_qi"]+ob->query_gain_qi(),"#99FF0000","exert recover");
	sp += "�U" + sprintf("����.%d:%d/%d/%d:%s",my["neili"],my["neili"],my["max_neili"],ob->query_current_neili_limit(),"#990066FF");
	sp += "�U" + sprintf("����.%d:%d/%d/%d:%s:%s",my["jing"],my["jing"],my["eff_jing"],my["max_jing"]+ob->query_gain_jing(),"#996600CC","exert regenerate");
	sp += "�U" + sprintf("����.%d:%d/%d/%d:%s",my["jingli"],my["jingli"],my["max_jingli"],ob->query_current_jingli_limit(),"#99006600",);
	sp += "�U" + sprintf("ŭ��.%d:%d/%d:%s",ob->query_craze(),ob->query_craze(),ob->query_max_craze(),"#99990000");
	sp += "�U" + sprintf("ʳ��.%d:%d/%d:%s",my["food"],my["food"],ob->max_food_capacity(),"#99FF6600");
	sp += "�U" + sprintf("��ˮ.%d:%d/%d:%s",my["water"],my["water"],ob->max_water_capacity(),"#990000FF");
	sp += "�U" + sprintf("��Ϊ(��).%d:%d/%d:%s",my["combat_exp"]/10000,my["combat_exp"]/10000,F_LEVEL->level_max_exp(ob)/10000,"#99FF0066");
	sp += "�U" + sprintf("Ǳ��(��).%d:%d/%d/%d:%s",my["potential"]/10000-my["learned_points"]/10000,my["potential"]/10000-my["learned_points"]/10000,ob->query_potential_limit()/10000-my["potential"]/10000,ob->query_potential_limit()/10000,"#99FF00FF");
	
	sp += "\n";
	tell_object(ob, sp);
	return 1;
	}
}

int fighting_hp1(object me)
{
	object ob = me,enemy, *enemys = me->query_enemy();
	int num=1,now,eff,max;
	mapping edb,my = ob->query_entire_dbase();
	string sp;
	
	if(!me->query("env/no_new_hp1"))
		return 0;
	
	if(sizeof(enemys) > 0) 
	{
		if(!pointerp(me->query_team()))
			enemys = ({me}) + enemys;//���Լ��ŵ���������ĵ�һλȥ��
		else
			enemys = me->query_team()+enemys;
		num = sizeof(enemys);

		switch(sizeof(enemys))
		{
			case 2:
				sp  = ZJHPTXT+ZJMENUF(5,5,28,40);
				break;
			default :
				sp  = ZJHPTXT+ZJMENUF(5,5,35,50); 
		}
		
		if(num > 3)
			num = 3;

		for(int i = 0; i < num; i++)
		{
			enemy = enemys[i];
			if(!objectp(enemy)) continue;
			edb = enemy->query_entire_dbase();
			if(i == 0 )
				sp += sprintf("%s:100/100:%s:%s","��","#000000","hp1 buff");
			else
				sp += "�U" + sprintf("%s:100/100:%s:%s",edb["name"],"#000000","hp1 buff");
			
			sp += "�U" + sprintf("��Ѫ.%s:%d/%d/%d:%s:%s",nts(edb["qi"]),edb["qi"],edb["eff_qi"],edb["max_qi"],"#99FF0000","exert recover");
			sp += "�U" + sprintf("����.%s:%d/%d/%d:%s",nts(edb["neili"]),edb["neili"],edb["max_neili"],edb["max_neili"],"#990066FF");
			sp += "�U" + sprintf("����.%s:%d/%d/%d:%s:%s",nts(edb["jing"]),edb["jing"],edb["eff_jing"],edb["max_jing"],"#996600CC","exert regenerate");
			if (enemy->is_busy() && intp(enemy->query_busy()) )
				sp += "�U" + sprintf("æ��.%s:%d/1:%s",""+enemy->query_busy(),1,"#000000");	
			else if(enemy->is_busy())
				sp += "�U" + sprintf("æ��.%s:%d/1:%s","������...",1,"#000000");
			else
				sp += "�U" + sprintf("æ��.%s:%d/1:%s","0",0,"#000000");
		}
		sp += "\n";
		tell_object(me, sp);
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : hp1

���ָ�������״̬����ʾ��Ľ���״̬��
ս��ʱ��ʾ��͵��˵Ľ���״̬��
 
see also : hp1
HELP );
    return 1;
}


