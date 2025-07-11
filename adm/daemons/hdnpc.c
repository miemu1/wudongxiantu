//autonpc.c
//by luoyun
#include <ansi.h>
#include <net/dns.h>//检测网络断线
inherit F_DBASE;
#include <localtime.h>

mapping room_place = ([
	"白驼山"		: "/d/baituo/",
	"北京"			: "/d/beijing/",
	"长安" 			: "/d/changan/",
	"扬州"			: "/d/city/",
	"成都"			: "/d/city3/",
	"大理"			: "/d/dali/",
	"峨嵋山" 		: "/d/emei/",
	"佛山"			: "/d/foshan/",
	"丐帮" 			: "/d/gaibang/",
	"福州"			: "/d/fuzhou/",
	"关外"			: "/d/guanwai/",
	"归云山庄"	: "/d/guiyun/",
	"古墓" 			: "/d/gumu/",
	"杭州"			: "/d/hangzhou/",
	"黑木崖"		: "/d/heimuya/",
	"恒山" 			: "/d/hengshan/",
	"衡山"			: "/d/henshan/",
	"黄河"			: "/d/huanghe/",
	"华山派"		: "/d/huashan/",
	"灵鹫宫"			: "/d/lingjiu/",
	"灵州"			: "/d/lingzhou/",
	"梅庄"			: "/d/meizhuang/",
	"明教" 			: "/d/mingjiao/",
	"青城山"		: "/d/qingcheng/",
	"全真派" 		: "/d/quanzhen/",
	"泉州" 			: "/d/quanzhou/",
	"少林寺" 		: "/d/shaolin/",
	"神龙岛"		: "/d/shenlong/",
	"嵩山"			: "/d/songshan/",
	"苏州"			: "/d/suzhou/",
	"泰山"			: "/d/taishan/",
	"桃花岛"		: "/d/taohua/",
	"天龙寺"		: "/d/tianlongsi/",
	"万劫谷"		: "/d/wanjiegu/",
	"武当山"		: "/d/wudang/",
	"侠客岛"		: "/d/xiakedao/",
	"襄阳"			: "/d/xiangyang/",
	"逍遥派"		: "/d/xiaoyao/",
	"星宿海" 		: "/d/xingxiu/",
	"血刀门" 		: "/d/xuedao/",
	"雪山" 			: "/d/xueshan/",
	"燕子坞" 		: "/d/yanziwu/",
]);


string *special_list = ({
	"/clone/book/wuji1",
	"/clone/book/wuji2",
	"/clone/book/wuji3",
	"/clone/book/wuji4",
	"/clone/book/qiankun_book",
	"/clone/book/six_book",
	"/clone/book/yijinjing",
	"/clone/book/lbook4",
	"/clone/book/jiuyin1",
	"/d/tulong/obj/zhenjing",
	"/clone/book/ling1",
	"/clone/book/ling2",
	"/clone/book/ling3",
	"/d/tulong/obj/tulongdao",
	"/d/tulong/obj/yitianjian",
	"/clone/weapon/zhenwu",
	"/clone/weapon/xtbishou",
	"/clone/weapon/jsbaojia",
	"/d/shaolin/obj/fumo-zhang",
	"/d/shaolin/obj/jingang-zhao",
	"/clone/weapon/green_stick",
	"/clone/weapon/lingshe",
 	 "/d/guanwai/obj/cwbdao",
  	"/d/guanwai/obj/lengyue",
  	"/clone/lonely/tieqin",
 	"/clone/lonely/book/xunleijian",
	"/clone/lonely/liangjijian",
	"/d/xuedao/obj/xblade",
	"/clone/misc/swmuding",

});

object load_room_place(string file_dir)
{
	string *file, bin_dir, path;
	int max, get_an;
	object room;

	bin_dir = file_dir;
		
	if (! bin_dir)
		//bin_dir = "/binaries" + file_dir;
			bin_dir = file_dir;
	if ( file_size(bin_dir) != -2 ) return 0;
	file = get_dir(bin_dir, -1);

	if ( !(max = sizeof(file)) ) return 0;

	get_an = random(max);
	path = bin_dir + file[get_an][0];
	if ( file_size(path) <= 0 ) return 0;

	if (room=find_object(path))
		return room;
	else
		return load_object(path[0..<3]);
}

int ok = 0;//飞贼标记
int ok1 = 0;//重置唯一物品标记
int xiaofeng = 0;
int yanqing = 0;
int laoshu = 0;
int laoren = 0;//天机老人
int sikong = 0;//司空摘星标记
int wabao=0;//挖宝标记
int dati=0;//答题标记
int yzbq=0;//饮中八器标记
int yitian=0;//倚天标记
int tulong=0;//屠龙标记

string path_where=0;

void create()
{
	seteuid(getuid());
	set("channel_id", "活动NPC系统");
	CHANNEL_D->do_channel( this_object(), "sys", "活动NPC系统已经启动。"NOR);
	set_heart_beat(20);
}

int clean_up()
{
	return 1;
}
object do_copy()
{
	object room;
	string *strtemp, locastr, exit;
	int temp, i1, i;
	
	//确定位置 
	strtemp = keys(room_place);
	i1 = sizeof(strtemp);
	temp = random(i1);
	locastr = room_place[strtemp[temp]];
	room = load_room_place(locastr);
	path_where = strtemp[temp];
	
	if( objectp(room) )
	{
		exit = room->query("exits"); 
		if ( !room->query("short") || !mapp(exit) || !sizeof(exit) || !room->query("outdoors") || room->query("no_fight")) 
			return do_copy();
	} 

	if ( !objectp(room) )
		return do_copy();
	else
		return room;
}

void clear_special()
{
	int i,k;
	object *list,ob;

	for(i=0;i<sizeof(special_list);i++)
	{
		list = children(special_list[i]);
		if(!list||!sizeof(list)) continue;
		for(k=0;k<sizeof(list);k++)
		{
			if((ob=environment(list[k]))&&playerp(ob))
			{
				tell_object(ob,"系统特殊物品刷新，你身上的"+list[k]->short()+"消失了！\n");
				destruct(list[k]);
			}
		}
	}
}

void check_time()
{	

	int GMT = time();
	string d, times,msg,fengjing;
	int h, s,m;
	object room, ob;
	int tiku,hang;//答题标记
	times = ctime(GMT);
	//Sun(星期日) Mon(星期一)  Tue(星期二)  Wed(星期三)  Thu(星期四)  Fri(星期五)  Sat(星期六)
	d = times[0..2];//星期
	h = to_int(times[10..12]);//时
	s = to_int(times[14..15]);//分
	m = to_int(times[17..18]);//秒
//五十分的时候刷新飞贼
	if ((s == 50) && !ok) {
		if (!room = do_copy())
			room = do_copy();
		else {
			ob = new("/clone/npc/feizei");
			if (ob->move(room)) {
				message("channel", HIR"【官府】:"HIY"听说有飞贼在"+HIG+path_where+HIY"一带出没，请留心自身财物安全！"NOR"\n", users());
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
				ok = 1;
				call_out("remove_npc", 120, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼生成失败。"NOR);
		}
	}
	

	
	//萧峰
	if ((s ==30&&((h%4)==2)&& !xiaofeng) )
{
			ob = new("/kungfu/class/misc/xiaofeng");
			if (ob->move("/d/changan/xiaojinghu")) 
			CHANNEL_D->do_channel(this_object(), "rumor",HIY"听说南院大王出现在长安小镜湖！"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", "萧峰出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
			xiaofeng = 1;
				call_out("remove_xiaofeng", 3600, ob);
}
	if (s!=30) xiaofeng = 0;//和上面时间一致清除标记

	//段延庆
	if ((s == 30&&((h%4)==2)&& !yanqing) )
{
			ob = new("/kungfu/class/misc/yanqing");
			if (ob->move("/d/lingzhou/yipindating"))
			CHANNEL_D->do_channel(this_object(), "rumor",HIR"听说延庆太子出现在灵州一品堂。"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", "段延庆出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
				yanqing = 1;
				call_out("remove_yanqing", 3600, ob);	
}
	if (s!=30) yanqing = 0;//和上面时间一致清除标记
	
	//白毛老鼠精
/*
	if ((s ==10&&(h==10||h==22)&& !laoshu) )
{
			ob = new("/kungfu/class/misc/laoshujing");
			if (ob->move("/d/quanzhou/zhongxin"))
			CHANNEL_D->do_channel(this_object(), "rumor",HIW"听说白毛老鼠精为祸人间出现在泉州城中心。"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", "白毛老鼠精出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
				laoshu = 1;
				call_out("remove_laoshu", 3600, ob);	
}
	if (s!=10) laoshu = 0;//和上面时间一致清除标记
	*/


	if ((s ==31&&(h==12||h==19||h==20||h==21)&& !laoren) )
{
			ob = new("/adm/npc/laoren");
			set("channel_id", "天机老人");
				
				switch(h){
		case 12:	ob->set("fst",1);
							msg="老魔封禅台";
			break;
		case 19:	ob->set("jxz",1);
							msg="血战聚贤庄";
			break;
		case 20:	ob->set("tulong",1);
							msg="屠龙宝刀";
			break;
		case 21:	ob->set("yitian",1);
							msg="倚天神剑";
			break;
		//default:	
			//break;							
		}	
		
			if(ob->move("/d/changan/tea-shop"))
			CHANNEL_D->do_channel(this_object(), "chat",HIW"老夫现在在长安茶馆，【"+msg+"】剧情已经启动。"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", "天机老人出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
			set("channel_id", "活动NPC系统");

				laoren = 1;
				call_out("remove_npc", 600, ob);	
}
	if (s!=31) laoren = 0;//和上面时间一致清除标记



	//司空摘星
	//if ((s == 50) && !sikong) 
	if (s == 22&&(h%2)==1&& !sikong) 
	{
		if (!room = do_copy())
			room = do_copy();
		else {
			ob = new("/u/xu/xingjiao");
			if (ob->move(room)) {
				message("channel", HIR"【以物易物】:"HIY"听说司空摘星身携重宝在"+HIG+path_where+HIY"一带出没，喜欢寻宝的玩家可以找他兑换心仪的宝物！"NOR"\n", users());
				CHANNEL_D->do_channel( this_object(), "sys", "司空摘星出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
				sikong = 1;
				call_out("remove_npc", 300, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "司空摘星生成失败。"NOR);
		}
	}
	if (s!=22) sikong = 0;//和上面时间一致清除标记

	//五十分的时候刷新挖宝
	if (s == 36&&(h%3)==0 && !wabao) {
		if (!room = do_copy())
			room = do_copy();
		else {
			//ob = new("/clone/npc/feizei");
			room->set("wabao",1);
			if (room) {
				message("channel", HIR"【天外异宝】:"HIW"天空响起一个炸雷，只见一道流光快速向"+HIG+path_where+HIW"方向坠去。！"NOR"\n", users());
				//CHANNEL_D->do_channel( this_object(), "sys", "宝藏出现了。"+ZJURL("cmds:goto "+room+"飞过去"+NOR"。");
		  CHANNEL_D->do_channel( this_object(), "sys", "宝藏出现了。"+ZJURL("cmds:goto "+room)+"飞过去"+NOR"。");
				wabao = 1;
				//call_out("remove_npc", 120, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "挖宝生成失败。"NOR);
		}
	}
	if (s!=36) wabao = 0;//和上面时间一致清除标记
	
	
	//答题
	//if (s == 10&&(h%2)==0 && !dati) {
	if (s==5&&h==18&& !dati) {	
			tiku=random(4);//中级题库四选一
			hang=random(3500);//所有题库三千五选一
			if(hang>3480)hang=3000;
			set("channel_id", "唐伯虎");
	  //CHANNEL_D->do_channel( this_object(), "chat", "科举答题时间到了。点击"+ZJURL("cmds:goto "+room)+"开始答题"+NOR"。");
	  	CHANNEL_D->do_channel( this_object(), "chat", HIY"潜能如江海，君能几瓢饮？科举闯关答题时间到了。"+NOR"。");
		 set("channel_id", "活动NPC系统");
		 
		 	foreach (object player in users()) {
			if (!environment(player) || base_name(environment(player)) == "/d/jianyu" ||  player->query_temp("netdead")||  player->query("dati-guan")) continue;
     
       			if(!player->query_temp("kxcd/start_time"))//加上统一的开始时间标记
       			player->set_temp("kxcd/start_time",time());
       			player->set_temp("kxcd/tiku",tiku);
       			player->set_temp("kxcd/hang",hang);		
        			tell_object(player,ZJFORCECMD("kaixindati"));
    			} 
			dati = 1;		
	}
	if (s!=05) dati = 0;//和上面时间一致清除标记

	
	//饮中八器
	if ((s ==8&&((h%4)==1)&& !yzbq) )
{
		switch(random(5)){
		case 0:fengjing="/d/emei/jinding";
		break;
		case 1:fengjing="/d/dali/huanggs";
		break;
		case 2:fengjing="/d/wanjiegu/wlhoushan";
		break;
		case 3:fengjing="/d/guanwai/tianchi1";
		break;
		case 4:fengjing="/d/hangzhou/qiantang";
		break;
		}
			ob = new("/u/xu/yzbx");
			if (ob->move(fengjing)) 
			CHANNEL_D->do_channel(this_object(), "rumor",HIC"【饮中八仙】"+ob->query("name")+HIC"近日突发兴致,决定去江湖风景秀丽之地饮酒赋诗。"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", ""+ob->query("name")+"出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
			yzbq = 1;
				call_out("remove_npc", 300, ob);
}
	if (s!=8) yzbq = 0;//和上面时间一致清除标记


	//原物品刷新时间
	//if ((h == 18) && (s == 0) && !ok1) {
	//修改为早上5点五十五分刷新特殊物品
	if ((h == 05) && (s == 55) && !ok1) {

		clear_special();
		ok1 = 1;
	}
//标记重置，防止重复产生npc
	if (s!=50) ok = 0;
//物品刷新标记
	//if (!(h==18&&s==0)) ok1 = 0;
	if (!(h==05&&s==55)) ok1 = 0;

}

void remove_npc(object ob)
{
	if (ob) {
	if (ob->query("id")=="fei zei")
		ob->force_me("say 这鬼地方真穷，没什么油水可捞，还是回家吧！\n");
	//if (ob->name()=="sikong zhaixing")
	if (ob->query("id")=="sikong zhaixing")
		ob->force_me("say 宝物虽然稀少但还是供过于求。是我错了还是世人错了？\n");	
	if (ob->query("id")=="tianji laoren")
		ob->force_me("chat 这正是江湖风波恶，平地起波澜，要知后事如何，且听下回分解。\n");
	if (ob->query("id")=="zu qianqiu")
		ob->force_me("chat 古来圣贤皆寂寞，惟有饮者留其名。\n");	
	destruct(ob);
	}	
}

void remove_xiaofeng(object ob)
{
	if (ob) {
		ob->force_me("chat 好生无趣，天下英雄竟然没谁能接得了萧某三招！\n");
		command("chat 好生无趣，天下英雄竟然没谁能接得了萧某三招！\n");

		destruct(ob);
	}
}
void remove_yanqing(object ob)
{
	if (ob) {
		ob->force_me("chat 这中原武林不过是浪得虚名罢了！某家去也！\n");
		command("chat 这中原武林不过是浪得虚名罢了！某家去也！\n");

		destruct(ob);
	}
}


void remove_laoshu(object ob)
{
	if (ob) {
		ob->force_me("chat 人间不好玩，姑奶奶回天庭了！\n");
		command("chat 人间不好玩，姑奶奶回天庭了！\n");

		destruct(ob);
	}
}


protected void heart_beat()
{	
	check_time();
}