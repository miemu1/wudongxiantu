#include <ansi.h>
#include <localtime.h>
#include "/d/jfbb/sys/j.h"//���������

#define MAX_ROOM_INDEX 100
#define JOFFICE_NPC     "/d/jfbb/npc/joffice"//�����Ĵ���npc
#define jfbb_JMEM        "/d/jfbb/sys/jmem"//�ڴ������
#define JKILLER_NPC     "/d/jfbb/npc/jkiller"//��ͨ����
#define JBOSS_NPC       "/d/jfbb/npc/jboss"//boss
#define MAX_KILLER_INDEX 200//npc���ܸ���

//ȫ�ֱ���
int make_room_index;//�������������
int ob_time;

//��������
//void check_time();ȡ��
private int copy_skill(object me, object ob);
int jfbb(object leader);
//void del_npc();ȡ��
void room_ok(object me);
varargs void make_jkiller(object *player,int jboss);

//��������ѯ��������������
int query_room_amount() { return make_room_index; }




//NPC���ã����쾵������
int jfbb(object leader)//����
{
	object maps,jmem,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;


	//�����ڴ�
	if(!jmem = new(jfbb_JMEM))
	{
	write("�����ڴ������ʧ��");
	 return 0;
	 }
	jmem->set("leader",leader);
	//�ж���������Ƿ����Ҫ��
		if(!leader || !userp(leader) || !living(leader))
		{
			destruct(jmem);			
		tell_object(leader,HIY"�����Ӱټҡ�����Ϊ�������м�����ʱ������������㣬�������������......\n"NOR);
			return 0;//continue;
}
		jmem->set(sprintf("user_id/%d",i),leader->query("id"));
		jmem->set(sprintf("user/%d",i),leader);
		leader->set_temp("jfbb/jfbb_jmem",jmem);//��ҵ���ʱ��������

		tell_object(leader,HIY"�����Ӱټҡ�����Ϊ�������м�������ս�����ܶ������Ժ�......\n"NOR);
	leader->disable_player("<���뾵����>");
		leader->set_temp("block_msg/all",1);

	//��������
	size = sizeof(room_maps);//��ȡ����
	for(j=0;j<size;j++)//��ʼѭ��
	{
		maps = new(room_maps[j]);//��������
		if(maps)
		{
			//���е�ͼ��jmem
			jmem->set(sprintf("maps/%d",j),maps);
			sscanf(room_maps[j],"/d/jfbb/room/%s",fileName);
			jmem->set(fileName,maps);
			maps->set("jmem",jmem);
			if(maps->query("short") == "���")//�����������short����ڣ���ô��Ϊ��ʼ����
			{
				start_room = maps;
			}
			index ++;
		}
	}
//  tell_object(find_player("jerry"),sprintf("DEBUG: %O",start_room));
	if(index < size || !start_room)
	{
			leader->enable_player();
			leader->delete_temp("block_msg");
			tell_object(leader,"Error: �м�����JOB����ʧ�ܣ�����ϵ��ʦ��\n");
			write("����ȱ��.");
		jmem->delete_map();
		destruct(jmem);
		time = localtime(time());
		log_file("jfbb",sprintf("%d��%d�� %d:%d  ����ռ䴴��ʧ�ܡ�\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		write("����ȱ��");
		return 0;
	}
	else
	{
		make_room_index ++;

			leader->set_temp("room/start_room",start_room);
			call_out("room_ok",5,leader);
		jmem->set("jfbb_time",time()+ 10800); //�������ʱ��
		jmem->set("open_time",time());        //����ʼʱ��
		jmem->len_1(); //��ͨ��ͼ(С��)
		jmem->heart(1);  //��������
		call_out("make_jkiller",5,leader);   //һ���Ӻ�ʼˢ��
	}
	return 1;
}

//��������
void room_ok(object me)
{
	object start_room,jmem;
	int i,size;
	mapping user_id;

	if(!me) return;

	start_room = (object)me->query_temp("room/start_room");
	jmem = (object)me->query_temp("jfbb/jfbb_jmem");

	me->enable_player();
	me->delete_temp("block_msg");

	//û�п�ʼ����
	if(!start_room)
	{
		tell_object(me,"����������г�ʼ���䣬û�ܽ��뾵��\n");
		user_id = (mapping)jmem->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d",i)] == me->query("id"))//���������ʶ
			{
				jmem->set(sprintf("user_id/%d",i),0);
				jmem->set(sprintf("user/%d",i),0);
				break;
			}
		}
		return;
	}
	else//�ɹ�����
	{
		me->move(start_room);
		tell_object(me,HIY"�����Ӱټҡ����λӢ������׼����30����м�������ս�����ܶ��𶯡�\n"NOR); //���
	}
}

varargs void make_jkiller(object player,int jboss)//��������
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0,skillk;
	object killer,jmem,rand_map;
	mapping maps;
	skillk = player->query_skill("force",1);
	skillk = skillk/2;
	skillk += random(skillk);

	if(!player) return;

	jmem = (object)player->query_temp("jfbb/jfbb_jmem");
	if(!jmem) return; //������
	//������������NPC
	if(!jboss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
		if(jmem->query("npc_amount",1) >= 1201) break;		
		if(!jboss)
		{
			if(killer = new(JKILLER_NPC))
			{
				jmem->add("npc_amount",1);
				maps = jmem->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //�����ͼ
      	copy_skill(killer,player);//��ʼ������Ҽ���
		killer->set("name",player->query("name")+"�Ļ���");
				killer->move(rand_map);
			}
		}
		else
		{
			if(killer = new(JBOSS_NPC))
			{
				maps = jmem->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //�����ͼ

				killer->move(rand_map);
			}
		}
	}
}
//��������֮��ĸ��Ƽ���
private int copy_skill(object me, object ob)
{
	mapping hp_status, skill_status, map_status, prepare_status;
	mapping my;
	string *sname, *mname, *pname;
	int i, temp;

	if (mapp(skill_status = me->query_skills()))
	{
		skill_status = me->query_skills();
		sname = keys(skill_status);

		temp = sizeof(skill_status);
		for (i = 0; i < temp; i++)
			me->delete_skill(sname[i]);
	}

	if (mapp(skill_status = ob->query_skills()))
	{
		skill_status = ob->query_skills();
		sname = keys(skill_status);

		for (i = 0; i < sizeof(skill_status); i++)
			me->set_skill(sname[i], skill_status[sname[i]]);
	}

	if (mapp(map_status = me->query_skill_map()))
	{
		mname = keys(map_status);

		temp = sizeof(map_status);
		for (i = 0; i < temp; i++)
			me->map_skill(mname[i]);
	}

	if (mapp(map_status = ob->query_skill_map()))
	{
		mname = keys(map_status);

		for(i = 0; i < sizeof(map_status); i++)
			me->map_skill(mname[i], map_status[mname[i]]);
	}

	if (mapp(prepare_status = me->query_skill_prepare()))
	{
		pname = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i = 0; i < temp; i++)
			me->prepare_skill(pname[i]);
	}

	if (mapp(prepare_status = ob->query_skill_prepare()))
	{
		pname = keys(prepare_status);

		for(i = 0; i < sizeof(prepare_status); i++)
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
	}

	hp_status = ob->query_entire_dbase();
	my = me->query_entire_dbase();

	my["str"] = hp_status["str"];
	my["int"] = hp_status["int"];
	my["con"] = hp_status["con"];
	my["dex"] = hp_status["dex"];

	my["max_qi"]     = hp_status["max_qi"];
	my["eff_qi"]     = hp_status["eff_qi"];
	my["qi"]	 = hp_status["qi"];
	my["max_jing"]   = hp_status["max_jing"];
	my["eff_jing"]   = hp_status["eff_jing"];
	my["jing"]       = hp_status["jing"];
	my["max_neili"]  = hp_status["max_neili"];
	my["neili"]      = hp_status["neili"];
	my["jiali"]      = hp_status["jiali"];
	my["combat_exp"] = hp_status["combat_exp"];

	me->reset_action();
	return 1;
}

