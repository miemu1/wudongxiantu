// Room: /city/wumiao2.c

#include <room.h>

inherit ROOM;
string look_shu();

void create()
{
	set("short", "武庙二楼");
	set("long", @LONG
这里是岳王庙的二楼，这里供的是岳飞的长子岳云和义子张宪，两尊塑像
金盔银铠，英气勃勃。
LONG );

	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_sleep_room", 1);
	set("exits", ([
		"south" : __DIR__"wumiao",
		"north": "/d/fuben/ciyuan",
	]));
	set("objects", ([
		
	    //"/clone/misc/msgd" : 1,
		//"/adm/npc/qingyangzi" : 1,
		//"/adm/npc/gu" : 1,
		"/adm/npc/buchang" : 1,
		"/adm/npc/abc" : 1,
		"/adm/npc/yimei" : 1,
	]));

	set("exits", ([
			"south" : __DIR__"wumiao",
	]));
	set("action_list",([
		"师门贡献换取":"scgj"
	]));
	setup();
}

void init()
{
	add_action("do_hydjl","hydjl");
	add_action("hyd","hyd");
	add_action("scgj","scgj");
}
int scgj(string arg)
{
	string *list,str,file,price;
	int i,yuanbao,value;
	object me,ob;
	int amount;
	mapping goods,times;

	me = this_player();
	goods = ([
	//"/clone/lunjian/wujueling":12000,
//	"/clone/vip2/putao1":250,
	//"/clone/vip2/jiuzhuan":450,
//	"/clone/vip/tianjing":2550,
	"/clone/book/qimai":2222,
	"/clone/book/mengzi":5222,
	//"/clone/vip2/dan_chongmai2":15,
    //"/clone/gift/kuihuazhen":2,
	"/clone/book/hanmo":2222,
	  "/clone/book/youxue":2222,
	  	  "/clone/book/tiandi":2222,
		   "/clone/book/xiantian":2222,
		 "/clone/book/yunv":2222,
		  "/clone/book/tianwei":2222,
		   "/clone/book/jinchan":2222,
		 "/clone/book/bixue":2222,
		  "/clone/book/yingdao":2222,
		 "/clone/book/qimen":2222,
		 "/clone/book/jianxin":2222,
	]);
	times = ([
	]);
	list = keys(goods);
	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("gongxian")+"贡献，请选择您想兑换的道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		for(i=0;i<sizeof(list);i++)
		{
			file = list[i];
			if(!goods[file]||file_size(file+".c")<0) continue;
			yuanbao = goods[file];
			price = yuanbao+"贡献";
			str += sprintf("%s"ZJBR"%s:scgj look %s"ZJSEP,file->query("name"),price,file);
		}
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];
		price = yuanbao+"贡献";
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		if(times[file])
			str += HIR"此物品每个玩家限兑换"+times[file]+"次"NOR ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "兑换:scgj buy "+file+"\n";
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];

		if(times[file])
		{
			if(me->query("shimen/duihuan/"+file->query("id")) >= times[file])
				return notify_fail(HIM"此物品每个玩家只能兑换"+times[file]+"次！！"NOR"\n");
			me->add("shimen/duihuan/"+file->query("id"),1);
		}
		if(me->query("gongxian") < yuanbao)
			return notify_fail(HIM"你的兑换贡献不足，去师门吧！"NOR"\n");
		me->add("gongxian",-yuanbao);
		ob = new(file);
//		log_file(me,"pay/smdh", "兑换了"+ob->short()+"。\n");
			log_file("pay/smdh", sprintf("%s:%s(%s)消费%d贡献，兑换了%s(%s)。\n",
				ctime(time()),me->query("name"),me->query("id"),yuanbao,file->query("name"),file->query("id")));

		tell_object(me,"你成功兑换到了"+ob->short()+"。"NOR"\n");
		ob->move(me);
		return 1;
	}
	else
		return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}



