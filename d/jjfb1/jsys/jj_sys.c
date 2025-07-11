//edit by jerry
//2008.12.7
//本文件不会被克隆

#include <ansi.h>
#include <localtime.h>
#include "/d/jjfb/jsys/jj.h"

#define MAX_ROOM_INDEX 2000
#define JJOFFICE_NPC     "/d/jjfb/jnpc/jjoffice"
#define JJFB_JJMEM       "/d/jjfb/jsys/jjmem"
#define JJKILLER_NPC     "/d/jjfb/jnpc/jjkiller"
#define JJBOSS_NPC       "/d/jjfb/jnpc/jjboss"
#define MAX_KILLER_INDEX 1

//全局变量
int make_room_index;
int ob_time;


//函数声明
//void check_time();  不用时间个人副本可以一直挑战 add jerry
int jjfb(object player);
void del_npc();
void jroom_ok(object me);
varargs void make_jjkiller(object *player,int jjboss);

//函数：查询现有量镜像数量
int query_room_amount() { return make_room_index; }

/*
//不用时间个人副本可以一直挑战 add jerry
//初始化
void create() { check_time(); }


//检查时间
void check_time()
{
	object npc;

	if(!ob_time)
	{
		//3小时一次
		ob_time = time()+3*3600;
	}
//tell_object(find_player("room"),"\n时间.......\n");
	if(ob_time <= time())
	{
		//活动通告
		//克隆NPC
		npc = new(JJOFFICE_NPC);
		if(npc)
		{
			CHANNEL_D->do_channel( npc, "chat", BLINK+HIC"心魔镜像已经打开，望各位英雄前来救回被剥夺魂魄的士兵。\n"NOR);
			//放到 /d/city/chatroom
			npc->move("/d/city/chatroom");
			//副本最大数量清零
			make_room_index = 0;
			//激活收起NPC(10分钟)
			call_out("del_npc",600);
			//重设时间
			ob_time = time()+3*3600;
		}
	}

	//时间没到就继续循环
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


//NPC调用，创造镜像世界
int jjfb(object player)
{
	object maps,jjmem,start_jroom;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player || make_room_index >= MAX_ROOM_INDEX ) return 0;

	//创建内存
	if(!jjmem = new(JJFB_JJMEM)) return 0;

	jjmem->set("user_id/0",player->query("id"));
	jjmem->set("user/0",player);
	player->set_temp("jjfb/jjfb_jjmem",jjmem);

	tell_object(player,HIY"【老魔】正在为你制造困难挑战单人副本，请稍候......\n"NOR);
	player->disable_player("<进入镜像中>");
	player->set_temp("block_msg/all",1);

	//制造世界
	size = sizeof(jroom_maps);
	for(j=0;j<size;j++)
	{
		maps = new(jroom_maps[j]);
		if(maps)
		{
// tell_object(find_player("jerry"),sprintf("DEBUG: name = %O maps = %O\n",maps->query("short"),maps));
			//所有地图进jjmem
			jjmem->set(sprintf("maps/%d",j),maps);
			sscanf(jroom_maps[j],"/d/jjfb/jroom/%s",fileName);
			jjmem->set(fileName,maps);
			maps->set("jjmem",jjmem);
			if(maps->query("short") == "狂盗谷入口")
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
		tell_object(player,"Error: 副本JOB制造失败，请联系巫师。\n");
//  tell_object(find_player("jerry"),sprintf("DEBUG: %3",start_jroom));
		jjmem->delete_map();
		destruct(jjmem);
		time = localtime(time());
		log_file("jjfb",sprintf("%d月%d日 %d:%d  虚拟空间创建失败。\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		return 0;
	}
	else
	{
		make_room_index ++;

		player->set_temp("jroom/start_jroom",start_jroom);
		call_out("jroom_ok",20,player);

		jjmem->set("jjfb_time",time()+ 1800); //任务结束时间
		jjmem->set("open_time",time());        //任务开始时间
		jjmem->len_1(); //连通地图(小心)
		jjmem->heart(1);  //启动心跳
		call_out("make_jjkiller",30,player);   //一分钟后开始刷怪
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

	//没有开始房间
	if(!start_jroom)
	{
		tell_object(me,"坐标错误，你没能进入镜像。\n");
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
		tell_object(me,HIY"【老魔】请各位英雄做好准备，30秒后副本挑战起动。\n"NOR); //广告
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
	if(!jjmem) return; //防抱错
	//放置主动攻击NPC
	if(!jjboss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
		if(jjmem->query("npc_amount",1) >= 1201) break;
		if(!jjboss)
		{
			if(killer = new("/d/fuben1/kunnan/1"))
			{
				NPC_D->set_from_me(killer, me, 100);
				jjmem->add("npc_amount",1);
				maps = jjmem->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图

				killer->move(rand_map);
                 n1 = new("/d/fuben1/kunnan/2");
				n1->move(rand_map);
                 n1 = new("/d/fuben1/kunnan/3");
				n1->move(rand_map);
                 n1 = new("/d/fuben1/kunnan/4");
				n1->move(rand_map);				
                 n1 = new("/d/fuben1/kunnan/5");
				n1->move(rand_map);				
	             n1 = new("/d/fuben1/kunnan/6");
				n1->move(rand_map);		
                 n1 = new("/d/fuben1/kunnan/7");
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
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图

				killer->move(rand_map);
			}
		}
	}
}
/*
//个人副本不用收起 NPC add jerry
//收起 NPC
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