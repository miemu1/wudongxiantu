//edit by Jerry
//2008.11.17
//���ļ����ᱻ��¡
/*
�ѵ��˸����Ľӿ�Ҳ���ϡ�
2018.7
byЦ��
*/

#include <ansi.h>
#include <localtime.h>
#include "/d/sangshidong/sys/j.h"

#define MAX_ROOM_INDEX 100
#define JOFFICE_NPC     "/d/sangshidong/npc/joffice"
#define jfbb_JMEM        "/d/sangshidong/sys/jmem"
#define JKILLER_NPC     "/d/sangshidong/npc/jkiller"
#define JBOSS_NPC       "/d/sangshidong/npc/jboss"
#define MAX_KILLER_INDEX 200//npc���ܸ���

//ȫ�ֱ���
int make_room_index;//�������������
int ob_time;

//��������
//void check_time();ȡ��
int jfbb(object leader);
//void del_npc();ȡ��
void room_ok(object me);
varargs void make_jkiller(object *player,int jboss);

//��������ѯ��������������
int query_room_amount() { return make_room_index; }

//��ʼ��
//void create() { }

//���ý��м��
/*
//���ʱ��
void check_time()
{
	object npc;

	if(!ob_time)
	{
		//3Сʱһ��
		ob_time = time()+3*3600;
	}
//tell_object(find_player("jerry"),"\nʱ��.......\n");
	if(ob_time <= time())
	{
		//�ͨ��
		//��¡NPC
		npc = new(JOFFICE_NPC);
		if(npc)
		{
			CHANNEL_D->do_channel( npc, "chat", BLINK+HIC"ɥʬ�ܶ������Ѿ��򿪣�����λӢ��ǰ���Ȼر�������ǵ�ʿ����\n"NOR);
			//�ŵ� /d/city/chatroom
			npc->move("/d/city/wumiao");
			//���������������
			make_room_index = 0;
			//��������NPC(10����)
			call_out("del_npc",600);
			//����ʱ��
			ob_time = time()+3*3600;
		}
	}

	//ʱ��û���ͼ���ѭ��
	if((time() + 1800) >= ob_time)
	{
		call_out("check_time",600);
	}
	else if((time() + 600) >= ob_time)
	{
		call_out("check_time",60);
	}
	else call_out("check_time",60);

}
*/


//NPC���ã����쾵������
int jfbb(object leader)//����
{
	object maps,jmem,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(make_room_index >= MAX_ROOM_INDEX || !leader )
	{
	write("���ȱʧ");
	 return 0;
}
	//�����ڴ�
	if(!jmem = new(jfbb_JMEM))
	{
	write("�����ڴ����ʧ��");
	 return 0;
	 }
	jmem->set("leader",leader);
	//�ж���������Ƿ����Ҫ��
		if(!leader || !userp(leader) || !living(leader))
		{
			destruct(jmem);
		tell_object(leader,HIY"������������Ϊ�����츱��ʱ������������㣬�������������......\n"NOR);
			return 0;//continue;
}
		jmem->set(sprintf("user_id/%d",i),leader->query("id"));
		jmem->set(sprintf("user/%d",i),leader);
		leader->set_temp("jfbb/jfbb_jmem",jmem);

		tell_object(leader,HIY"������������Ϊ���м�������սɥʬ�ܶ������Ժ�......\n"NOR);
	leader->disable_player("<���뾵����>");
		leader->set_temp("block_msg/all",1);

	//��������
	size = sizeof(room_maps);
	for(j=0;j<size;j++)
	{
		maps = new(room_maps[j]);
		if(maps)
		{
			//���е�ͼ��jmem
			jmem->set(sprintf("maps/%d",j),maps);
			sscanf(room_maps[j],"/d/sangshidong/room/%s",fileName);
			jmem->set(fileName,maps);
			maps->set("jmem",jmem);
			if(maps->query("short") == "���")
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
		log_file("sangshidong",sprintf("%d��%d�� %d:%d  ����ռ䴴��ʧ�ܡ�\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		write("����ȱ��");
		return 0;
	}
	else
	{
		make_room_index ++;

			leader->set_temp("room/start_room",start_room);
			call_out("room_ok",20,leader);
		jmem->set("sangshidong_time",time()+ 5400); //�������ʱ��
		jmem->set("open_time",time());        //����ʼʱ��
		jmem->len_1(); //��ͨ��ͼ(С��)
		jmem->heart(1);  //��������
		call_out("make_jkiller",60,leader);   //һ���Ӻ�ʼˢ��
	}
	return 1;
}

int jfbbs(object* player,object leader)//s�������
{
	object maps,jmem,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player || make_room_index >= MAX_ROOM_INDEX || !leader ) return 0;

	//�����ڴ�
	if(!jmem = new(jfbb_JMEM)) return 0;

	jmem->set("leader",leader);
	//�ж���������Ƿ����Ҫ��
	size = sizeof(player);
	for(i=0;i<size;i++)
	{
		if(!player[i] || !userp(player[i]) || !living(player[i]) || !pointerp(player[i]->query_team()))
		{
			destruct(jmem);
			return 0;//continue;
		}

		//�ҳ��ӳ�
		if(player[i]->is_team_leader())
		{
			leader = player[i];

		}
		jmem->set(sprintf("user_id/%d",i),player[i]->query("id"));
		jmem->set(sprintf("user/%d",i),player[i]);
		player[i]->set_temp("jfbb/jfbb_jmem",jmem);

		tell_object(player[i],HIY"������������Ϊ�������м�������սɥʬ�ܶ������Ժ�......\n"NOR);
		player[i]->disable_player("<���뾵����>");
		player[i]->set_temp("block_msg/all",1);
	}

	//��������
	size = sizeof(room_maps);
	for(j=0;j<size;j++)
	{
		maps = new(room_maps[j]);
		if(maps)
		{
			//���е�ͼ��jmem
			jmem->set(sprintf("maps/%d",j),maps);
			sscanf(room_maps[j],"/d/jfbb/room/%s",fileName);
			jmem->set(fileName,maps);
			maps->set("jmem",jmem);
//  tell_object(find_player("jerry"),sprintf("DEBUG: name = %O maps = %O\n",maps->query("short"),maps));
			if(maps->query("short") == "���")
			{
				start_room = maps;
			}
			index ++;
		}
	}
//  tell_object(find_player("jerry"),sprintf("DEBUG: %O",start_room));
	if(index < size || !start_room)
	{
		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->enable_player();
			player[i]->delete_temp("block_msg");
			tell_object(player[i],"Error: �м�����JOB����ʧ�ܣ�����ϵ��ʦ��\n");
		}

		jmem->delete_map();
		destruct(jmem);
		time = localtime(time());
		log_file("jfbb",sprintf("%d��%d�� %d:%d  ����ռ䴴��ʧ�ܡ�\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		return 0;
	}
	else
	{
		make_room_index ++;

		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->set_temp("room/start_room",start_room);
			call_out("room_ok",20,player[i]);
		}
		jmem->set("jfbb_time",time()+ 5400); //�������ʱ��
		jmem->set("open_time",time());        //����ʼʱ��
		jmem->len_1(); //��ͨ��ͼ(С��)
		jmem->heart(1);  //��������
		call_out("make_jkiller",60,player[0]);   //һ���Ӻ�ʼˢ��
	}
}

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
		tell_object(me,"���������û�ܽ��뾵��\n");
		user_id = (mapping)jmem->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d",i)] == me->query("id"))
			{
				jmem->set(sprintf("user_id/%d",i),0);
				jmem->set(sprintf("user/%d",i),0);
				break;
			}
		}
		return;
	}
	else
	{
		me->move(start_room);
		tell_object(me,HIY"�����������λӢ������׼����30����м�������սɥʬ�ܶ��𶯡�\n"NOR); //���
	}
}

varargs void make_jkiller(object player,int jboss)
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
    killer->set_skill("lamaism", skillk/2);
	killer->set_skill("literate", skillk/2);
	killer->set_skill("force", skillk/2);
	killer->set_skill("yinyang-shiertian", skillk/2);
	killer->set_skill("dodge", skillk/2);
	killer->set_skill("yinyang-shiertian", skillk/2);
	killer->set_skill("hand", skillk/2);
	killer->set_skill("yinyang-shiertian", skillk/2);
	killer->set_skill("parry", skillk/2);
	killer->set_skill("sword", skillk/2);
	killer->set_skill("yinyang-shiertian", skillk/2);

	killer->map_skill("force", "yinyang-shiertian");
	killer->map_skill("dodge", "yinyang-shiertian");
	killer->map_skill("hand",  "yinyang-shiertian");
	killer->map_skill("parry", "yinyang-shiertian");
	killer->map_skill("sword", "yinyang-shiertian");

	killer->prepare_skill("hand",  "yinyang-shiertian");
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
/*
//���� NPC
void del_npc()
{
	object *joffice;
	int i,size;

	joffice = children("/d/jfbb/npc/joffice");

	if(!joffice) return;

	size = sizeof(joffice);
	for(i=0;i<size;i++)
	{
		destruct(joffice[i]);
	}
}*/
