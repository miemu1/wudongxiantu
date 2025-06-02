// by name QQ��3468713544
inherit ROOM;
#define PAT "/log/adm/mrt"
void create()
{
	set("short", "������");
	set("channel_id", "������");
	set("long", "���߽���ʵ��Ϊ���������ʵ������ʵ����������ʷ��ɣ�\n");
	
	set("exits", ([	
		//"north" : __DIR__"wumiao",
		"southwest" : __DIR__"kedian",
		
	]));
	set("action_list",([
		HIY"��������"NOR:"mrt",	
		HIW"�����ؼ�"NOR:"mijishop",	
	]));	
	set("mrt",1);  //Ĭ��ǿ��100%
	set_heart_beat(35);
	setup();
}
void init()
{
    add_action("mrt_kill","kills");
	add_action("mijishop","mijishop");
}

int mijishop(string arg)
{
	string *list,str,file,price;
	int i,yuanbao,value;
	object me,ob;
	int amount;
	mapping goods,times;

	me = this_player();
	goods = ([
		"/clone/mingrt/qingmang":30,
	/* 	"/clone/lunjian/dan_chongmai4":3,
		"/clone/lunjian/putao":10,
		"/clone/lunjian/wujueling":100,
		"/clone/lunjian/xyj":50,
		"/clone/lunjian/da-xidian":25, */
	]);
	times = ([
		/* "/clone/lunjian/wujueling":1, */
	]);
	list = keys(goods);
	if (! arg)
	{
		str = ZJOBLONG"��Ŀǰ��"+me->query("mjf")+"�ؼ���ȯ����ѡ������һ��ĵ��ߣ�\n"ZJOBACTS2+ZJMENUF(4,4,8,32);
		for(i=0;i<sizeof(list);i++)
		{
			file = list[i];
			if(!goods[file]||file_size(file+".c")<0) continue;
			yuanbao = goods[file];
			price = yuanbao+"��ȯ";
			str += sprintf("%s"ZJBR"%s:mijishop look %s"ZJSEP,file->query("name"),price,file);
		}
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"�һ��б���û��������ߣ���"NOR"\n");

		yuanbao = goods[file];
		price = yuanbao+"��ȯ";
		str = ZJOBLONG+"��"+file->query("name")+"�������۸�"+price+NOR+ZJBR"һһһһһһһһһһһһһһһһһһһһһһһ"ZJBR;
		if(times[file])
			str += HIR"����Ʒÿ������޶һ�"+times[file]+"��"NOR ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "�һ�:mijishop buy "+file+"\n";
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"�һ��б���û��������ߣ���"NOR"\n");

		yuanbao = goods[file];

		if(times[file])
		{
			if(me->query("lunjian/duihuan/"+file->query("id")) >= times[file])
				return notify_fail(HIM"����Ʒÿ�����ֻ�ܶһ�"+times[file]+"�Σ���"NOR"\n");
			me->add("lunjian/duihuan/"+file->query("id"),1);
		}
		if(me->query("mjf") < yuanbao)
			return notify_fail(HIM"��Ķһ���ȯ���㣬��μӲμ������û�ɣ���"NOR"\n");
		me->add("mjf",-yuanbao);
		ob = new(file);
		log_ufile(me,"pay/mrt", "�һ���"+ob->short()+"��\n");
		tell_object(me,"��ɹ��һ�����"+ob->short()+"��"NOR"\n");
		ob->move(me);
		return 1;
	}
	else
		return notify_fail(HIM"�����ʲô����"NOR"\n");

	return 1;
}

int mrt_kill(string arg)
{
mapping skill;
string skills,msg;
object where,npc,me,room;
int lvl,last,nd,i;

me=this_player();
last = me->query("mrt_day_time");	
where = environment(me);

if (!arg)
{
msg = "��ѡ����ս��Σ�\n";
msg += ZJOBACTS2+ZJMENUF(3,3,9,32);
for(i=0;i<=me->query("mrt/nd");i++){
msg+="��"+i+"��:kills "+i+""ZJSEP;		
}
msg=ZJOBLONG+msg;
msg+="\n";
write(msg);
}else{	

if(me->query("combat_exp")<1000000)
return notify_fail(HIR"�����Ϊ����100W��û���ʸ���ս�����ø��֡�\n"NOR);	
if(me->query_skill("force",1)<180)
return notify_fail(HIR"����ڹ��ȼ�����180����û���ʸ���ս�����ø��֡�\n"NOR);	
if(time()/86400 == last/86400)
return notify_fail("������Ѿ���ս�������ø����ˣ����������ɣ�\n");	
sscanf(arg,"%d",nd);
if(me->query("mrt/nd")<nd)
return notify_fail("�㻹û����ս������ء���\n");	
me->set("mrtnd",nd);
lvl=me->query_skill("force",1)+(me->query_skill("force",1)*query("mrt"))+(me->query_skill("force",1)*nd);
//NPC��ROOM	
npc=new("/cmds/npc");
room=new("/d/city/mrtroom");
skill=npc->query_skills();
//����ǿ�������ø��ֵȼ�����������
    npc->set("qi",to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_qi", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("eff_qi", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("eff_jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));	
	npc->set("jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));	
	npc->set("neili", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_neili", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));    
	npc->set("jingli", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_jingli", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));		 
	npc->set("combat_exp", to_int(10000*me->query_skill("force",1)+((me->query_skill("force")*10000)*query("mrt"))));	
	npc->set_temp("apply/attack", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/damage", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/defence",to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/armor", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
    npc->set_temp("apply/unarmed_damage",to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));      
    //���ü���   
    foreach(skills in keys(skill)){
    npc->set_skill(skills,to_int(lvl));
   }
 npc->move(room);
 me->move(room);
 me->set("mrt_day_time",time());
 }
 return 1;

}
//30�������һ��ǿ��
void heart_beat()
{
float qd;
mixed *sj;
sj = localtime(time());
qd=1+random(10);
if(sj[1]%30==0){
set("mrt",qd/10);
CHANNEL_D->do_channel(this_object(), "chat", "������ǿ��ˢ�¡�");
}

//ÿ��7��
if(sj[3]%7==0&&sj[2]==1&&sj[1]==1&&sj[0]==1)
{
rm("/log/adm/mrt");
}
  
  
}