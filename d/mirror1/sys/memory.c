//edit by rock
//2008.10.16
//镜像房间内存

#include <ansi.h>
inherit ITEM;

#include "/d/mirror/sys/list.h"

#define SYSTEAM "/d/mirror/sys/mirror_sys"

void create() { set_name("镜像房间内存",({ "memory"})); }

//心跳(小心准备 误差为30秒)
varargs void heart(int open)
{
	int i,size,index=0,leave_user=0;
	object me,player,*players = ({ });
	mapping userId;
	string str;

	me = this_object();

	userId = me->query("user_id");
	size = sizeof(userId);
	for(i=0;i<size;i++)
	{
		str = userId[sprintf("%d",i)];
		if(!str || !stringp(str))
		{
			leave_user++;
			continue;
		}
		player = find_player(str);

		if((!player || (!environment(player)->is_mirror()) && !open))
		{
			me->set(sprintf("user_id/%d",i),0);
		}
	}
	//玩家离开副本
	if(leave_user >= size)
	{
		if(me->delete_map())
		{
			destruct(me);
			return;
		}
	}

	userId = me->query("user_id");
	size = sizeof(userId);
	if(me->query("open_time")+600 <= time() && !me->query("fanghuo")) //5分钟后
	{
		for(i=0;i<size;i++)
		{
			str = userId[sprintf("%d",i)];
			if(!str || !stringp(str)) continue;
			player = find_player(str);
			tell_object(player,HIY"【武动仙途】扶桑人放火了，整条街都在燃烧。\n"NOR);
		}
		me->len_exits(1);
		me->set("fanghuo",1);
	}
	else if(me->query("open_time")+900 <= time() && !me->query("rand"))  //10分钟后
	{
		for(i=0;i<size;i++)
		{
			str = userId[sprintf("%d",i)];
			if(!str || !stringp(str)) continue;
			player = find_player(str);
			tell_object(player,HIY"【武动仙途】整条街燃烧殆尽，已经分不清方向了。\n"NOR);
		}
		me->len_exits(2);
		me->set("rand",1);
	}
	else if(me->query("open_time")+1200 <= time())  //10分钟后
	{
		if(!me->query("rand_2"))
		{
			for(i=0;i<size;i++)
			{
				str = userId[sprintf("%d",i)];
				if(!str || !stringp(str)) continue;
				player = find_player(str);
				tell_object(player,HIY"【武动仙途】扶桑人摧毁了扬州。\n"NOR);
			}
			me->len_exits(3);
			me->set("rand_2",1);
		}
		else
		{
			if(me->query("open_time")+300 <= time())
			{
				me->set("open_time",time());
				me->len_exits(4);
			}
		}
	}
	if(me->query("make_boss") >= 150 && !me->query("send_boss"))
	{
		for(i=0;i<size;i++)
		{
			str = userId[sprintf("%d",i)];
			if(!str || !stringp(str)) continue;
			player = find_player(str);
			tell_object(player,HIY"【武动仙途】扶桑统帅出现，请各位小心。\n"NOR);
			players += ({ player });
		}
		SYSTEAM->make_killer(players,1);
		me->set("send_boss",1);
	}
	//已到副本生存期限
	if(me->query("mirror_time") <= time())
	{
		for(i=0;i<size;i++)
		{
			str = userId[sprintf("%d",i)];
			if(!str || !stringp(str)) continue;
			player = find_player(str);
			tell_object(player,HIY"【武动仙途】镜像已经瓦解，欢迎再次挑战。\n"NOR);
		}
		if(me->delete_map())
		{
			destruct(me);
			return;
		}
	}
	//tell_object(find_player("rock"),HIY"心跳~~~~~~~~~~!\n"NOR);
	call_out("heart",30);
}

//删除虚拟地图
int delete_map()
{
	int i,size,j,size2;
	mapping maps;
	object me,map,*objs;

	me = this_object();
	maps = (mapping)me->query("maps");
	size = sizeof(maps);

	for(i=0;i<size;i++)
	{
		if(!map = (object)maps[sprintf("%d",i)] || !clonep(map)) continue;
		if(!objs = all_inventory(map) || !arrayp(objs)) continue;

		//找出房间内的物品,并且删除之
		size2 = sizeof(objs);
		for(j=0;j<size2;j++)
		{
			if(!objectp(objs[j])) continue;
			if(userp(environment(objs[j]))) continue;

			//如果是玩家,移动到安全的地方
			if(userp(objs[j]))
			{
				tell_object(objs[j],HIY"【武动仙途】你被传回安全区。\n"NOR);
				objs[j]->move("/d/city/wumiao");
				continue;
			}
			destruct(objs[j]);
		}
		destruct(map);
	}
	return 1;
}

//连通地图
varargs int len_exits(int rand)
{
	object me,map;
	mapping room_exits,maps,exit;
	string fileName,mapfile,file,*dirs,temp,temp1,name;
	int i,size,j,size2,size3;

	me = this_object();
	maps = me->query("maps");
	size = sizeof(maps);

	if(!rand)
	{
		for(i=0;i<size;i++)
		{
			map = maps[sprintf("%d",i)];

			if(!clonep(map)) continue;   //物件载入失败<注意危险,如果list不对,玩家有可能走到正本.这里只为防止报错>

	//		tell_object(find_player("rock"),sprintf("DEBUG: i = %d\n",i));
			room_exits = map->query("exits");

			dirs = keys(room_exits);
			size2 = sizeof(dirs);
			for(j=0;j<size2;j++)
			{
				file = room_exits[dirs[j]];
				sscanf(file,"/d/mirror/%s",fileName);

				mapfile = sprintf("/%O",me->query(fileName));

				if(strsrch(mapfile,"#") == -1 || !fileName || !stringp(fileName))
				{
					mapfile = sprintf("/%O",map);
				}
				exit = room_exits; exit[dirs[j]] = mapfile;

	//			tell_object(find_player("rock"),sprintf("DEBUG: %s == %s mapfile = %s\n",exit[dirs[j]],room_exits[dirs[j]],mapfile));
			}
			map->set("exits",exit);
		}
	}
	else if(rand == 1)
	{
		for(i=0;i<size;i++)
		{
			map = maps[sprintf("%d",i)];

			if(!clonep(map)) continue;   //物件载入失败<注意危险,如果list不对,玩家有可能走到正本.这里只为防止报错>

			map->set("only_name",map->query("short"));
			name = sprintf("燃烧的%s",map->query("short"));
			map->set("short",name);
		}
	}
	//随机出口
	else if(rand == 2 || rand == 3 || rand == 4)
	{
		for(i=0;i<size;i++)
		{
			map = maps[sprintf("%d",i)];

			if(!clonep(map)) continue;   //物件载入失败<注意危险,如果list不对,玩家有可能走到正本.这里只为防止报错>

			if(rand == 2)
			{
				name = sprintf("烧毁的%s",map->query("only_name"));
				map->set("short",name);
			}
			else if(rand == 3)
			{
				name = "废墟";
				map->set("short",name);
				map->set("long","一片焦黑，杂乱无章，根本无法分辨是什么地方。\n");
			}

			room_exits = map->query("exits");

			dirs = keys(room_exits);
			size2 = sizeof(dirs);

			for(j=0;j<size2;j++)
			{
				size3 = sizeof(mirror_maps);
				file = mirror_maps[random(size3)];
				sscanf(file,"/d/mirror/%s",fileName);

				mapfile = sprintf("/%O",me->query(fileName));

				if(strsrch(mapfile,"#") == -1 || !fileName || !stringp(fileName))
				{
					mapfile = sprintf("/%O",map);
				}
				exit = room_exits;
				//tell_object(find_player("rock"),sprintf("DEBUG: exit = %O  mapfile = %O\n",exit,mapfile));
				exit[dirs[j]] = mapfile;
			}
			map->set("exits",exit);
		}
	}
}

void quest_over()
{
	call_out("quest_over_1",60);
}

void quest_over_1()
{
	int size,i;
	mapping userId;

	object me = this_object();

	userId = me->query("user_id");
	size = sizeof(userId);
	for(i=0;i<size;i++)
	{
		me->set(sprintf("user_id/%d",i),0);
	}
}