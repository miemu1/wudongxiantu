//edit by jerry
//2008.12.7
//���ļ����ᱻ��¡

#include <ansi.h>
#include <localtime.h>
#include "/d/jjfb/jsys/jj.h"

#define MAX_ROOM_INDEX 2000
#define JJOFFICE_NPC     "/d/jjfb/jnpc/jjoffice"
#define JJFB_JJMEM       "/d/jjfb/jsys/jjmem"
#define JJKILLER_NPC     "/d/jjfb/jnpc/jjkiller"
#define JJBOSS_NPC       "/d/jjfb/jnpc/jjboss"
#define MAX_KILLER_INDEX 1

//ȫ�ֱ���
int make_room_index;
int ob_time;


//��������
//void check_time();  ����ʱ����˸�������һֱ��ս add jerry
int jjfb(object player);
void del_npc();
void jroom_ok(object me);
varargs void make_jjkiller(object *player,int jjboss);

//��������ѯ��������������
int query_room_amount() { return make_room_index; }

/*
//����ʱ����˸�������һֱ��ս add jerry
//��ʼ��
void create() { check_time(); }


//���ʱ��
void check_time()
{
	object npc;

	if(!ob_time)
	{
		//3Сʱһ��
		ob_time = time()+3*3600;
	}
//tell_object(find_player("room"),"\nʱ��.......\n");
	if(ob_time <= time())
	{
		//�ͨ��
		//��¡NPC
		npc = new(JJOFFICE_NPC);
		if(npc)
		{
			CHANNEL_D->do_channel( npc, "chat", BLINK+HIC"��ħ�����Ѿ��򿪣�����λӢ��ǰ���Ȼر�������ǵ�ʿ����\n"NOR);
			//�ŵ� /d/city/chatroom
			npc->move("/d/city/chatroom");
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
int jjfb(object player)
{
	object maps,jjmem,start_jroom;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player || make_room_index >= MAX_ROOM_INDEX ) return 0;

	//�����ڴ�
	if(!jjmem = new(JJFB_JJMEM)) return 0;

	jjmem->set("user_id/0",player->query("id"));
	jjmem->set("user/0",player);
	player->set_temp("jjfb/jjfb_jjmem",jjmem);

	tell_object(player,HIY"����ħ������Ϊ���������ս���˸������ڼ�����˳���Ϸ�����Ժ�......\n"NOR);
	player->disable_player("<���뾵����>");
	player->set_temp("block_msg/all",1);

	//��������
	size = sizeof(jroom_maps);
	for(j=0;j<size;j++)
	{
		maps = new(jroom_maps[j]);
		if(maps)
		{
// tell_object(find_player("jerry"),sprintf("DEBUG: name = %O maps = %O\n",maps->query("short"),maps));
			//���е�ͼ��jjmem
			jjmem->set(sprintf("maps/%d",j),maps);
			sscanf(jroom_maps[j],"/d/jjfb/jroom/%s",fileName);
			jjmem->set(fileName,maps);
			maps->set("jjmem",jjmem);
			if(maps->query("short") == "��������")
			{
				start_jroom = maps;
//  tell_object(find_player("jerry"),sprintf("DEBUG: %1",start_jroom));

			}
			index ++;
		}
	}

	if(index < size || !start_jroom)
	{
//  tell_object(find_player("jerry"),sprintf("DEBUG: %2",start_jroom));
		player->enable_player();
		player->delete_temp("block_msg");
		tell_object(player,"Error: ����JOB����ʧ�ܣ�����ϵ��ʦ��\n");
//  tell_object(find_player("jerry"),sprintf("DEBUG: %3",start_jroom));
		jjmem->delete_map();
		destruct(jjmem);
		time = localtime(time());
		log_file("jjfb",sprintf("%d��%d�� %d:%d  ����ռ䴴��ʧ�ܡ�\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		return 0;
	}
	else
	{
		make_room_index ++;

		player->set_temp("jroom/start_jroom",start_jroom);
		call_out("jroom_ok",20,player);

		jjmem->set("jjfb_time",time()+ 900); //�������ʱ��
		jjmem->set("open_time",time());        //����ʼʱ��
		jjmem->len_1(); //��ͨ��ͼ(С��)
		jjmem->heart(1);  //��������
		call_out("make_jjkiller",30,player);   //һ���Ӻ�ʼˢ��
	}
}

void jroom_ok(object me)
{
	object start_jroom,jjmem;
	int i,size;
	mapping user_id;

	if(!me) return;

	start_jroom = (object)me->query_temp("jroom/start_jroom");
	jjmem = (object)me->query_temp("jjfb/jjfb_jjmem");

	me->enable_player();
	me->delete_temp("block_msg");

	//û�п�ʼ����
	if(!start_jroom)
	{
		tell_object(me,"���������û�ܽ��뾵��\n");
		user_id = (mapping)jjmem->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d")] == me->query("id"))
			{
				jjmem->set(sprintf("user_id/%d"),0);
				jjmem->set(sprintf("user/%d"),0);
				break;
			}
		}
		return;
	}
	else
	{
		me->move(start_jroom);
		tell_object(me,HIY"����ħ�����λӢ������׼����30��󸱱���ս�𶯣�������ʱ15���ӡ�\n"NOR); //���
	}
}

varargs void make_jjkiller(object player,int jjboss)
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0;
	object killer,jjmem,rand_map,me;
	object n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
	mapping maps;

	if(!player) return;
	me = this_player();
	jjmem = (object)player->query_temp("jjfb/jjfb_jjmem");
	if(!jjmem) return; //������
	//������������NPC
	if(!jjboss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
		if(jjmem->query("npc_amount",1) >= 1201) break;
		if(!jjboss)
		{
			if(killer = new("/d/fuben1/jiandan/1"))
			{
				NPC_D->set_from_me(killer, me, 100);
				jjmem->add("npc_amount",1);
				maps = jjmem->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //�����ͼ

				killer->move(rand_map);
                 n1 = new("/d/fuben1/jiandan/2");
				n1->move(rand_map);
                 n1 = new("/d/fuben1/jiandan/3");
				n1->move(rand_map);
                 n1 = new("/d/fuben1/jiandan/4");
				n1->move(rand_map);				
                 n1 = new("/d/fuben1/jiandan/5");
				n1->move(rand_map);				
	             n1 = new("/d/fuben1/jiandan/6");
				n1->move(rand_map);		
                 n1 = new("/d/fuben1/jiandan/7");
				n1->move(rand_map);
			}
		}
		else
		{
			if(killer = new(JJBOSS_NPC))
			{
				NPC_D->set_from_me(killer, jjmem, 100);
				maps = jjmem->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //�����ͼ

				killer->move(rand_map);
			}
		}
	}
}
/*
//���˸����������� NPC add jerry
//���� NPC
void del_npc()
{
	object *jjoffice;
	int i,size;

	joffice = children("/d/jjfb/jnpc/jjoffice");

	if(!jjoffice) return;

	size = sizeof(jjoffice);
	for(i=0;i<size;i++)
	{
		destruct(jjoffice[i]);
	}
}
*/