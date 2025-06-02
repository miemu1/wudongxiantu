// Room: /city/wumiao2.c

#include <room.h>

inherit ROOM;
string look_shu();

void create()
{
	set("short", "�����¥");
	set("long", @LONG
������������Ķ�¥�����﹩�������ɵĳ������ƺ��������ܣ���������
���������Ӣ��������
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
		"ʦ�Ź��׻�ȡ":"scgj"
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
		str = ZJOBLONG"��Ŀǰ��"+me->query("gongxian")+"���ף���ѡ������һ��ĵ��ߣ�\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		for(i=0;i<sizeof(list);i++)
		{
			file = list[i];
			if(!goods[file]||file_size(file+".c")<0) continue;
			yuanbao = goods[file];
			price = yuanbao+"����";
			str += sprintf("%s"ZJBR"%s:scgj look %s"ZJSEP,file->query("name"),price,file);
		}
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"�һ��б���û��������ߣ���"NOR"\n");

		yuanbao = goods[file];
		price = yuanbao+"����";
		str = ZJOBLONG+"��"+file->query("name")+"�������۸�"+price+NOR+ZJBR"һһһһһһһһһһһһһһһһһһһһһһһ"ZJBR;
		if(times[file])
			str += HIR"����Ʒÿ������޶һ�"+times[file]+"��"NOR ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "�һ�:scgj buy "+file+"\n";
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
			if(me->query("shimen/duihuan/"+file->query("id")) >= times[file])
				return notify_fail(HIM"����Ʒÿ�����ֻ�ܶһ�"+times[file]+"�Σ���"NOR"\n");
			me->add("shimen/duihuan/"+file->query("id"),1);
		}
		if(me->query("gongxian") < yuanbao)
			return notify_fail(HIM"��Ķһ����ײ��㣬ȥʦ�Űɣ�"NOR"\n");
		me->add("gongxian",-yuanbao);
		ob = new(file);
//		log_file(me,"pay/smdh", "�һ���"+ob->short()+"��\n");
			log_file("pay/smdh", sprintf("%s:%s(%s)����%d���ף��һ���%s(%s)��\n",
				ctime(time()),me->query("name"),me->query("id"),yuanbao,file->query("name"),file->query("id")));

		tell_object(me,"��ɹ��һ�����"+ob->short()+"��"NOR"\n");
		ob->move(me);
		return 1;
	}
	else
		return notify_fail(HIM"�����ʲô����"NOR"\n");

	return 1;
}



