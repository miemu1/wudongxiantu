// storyd.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;
#include <localtime.h>


// 初始化BOSS系统
#define REFRESH_INTERVAL	10 * 3600

string *story_name;
mapping history;
int     last_update = 0;
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
	"黑木涯"		: "/d/heimuya/",
	"衡山" 			: "/d/hengshan/",
	"恒山"			: "/d/henshan/",
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

static mapping interval;
static object  running_story;
static int flag;
static int a_flag;
static int b_flag;
static int yitian_flag;
static int tulong_flag;
static int step;
static int wjg_flag;
static int wjgl_flag;
int    filter_listener(object ob);

void init_story();
void go_on_process(object ob);
varargs void start_story(string sname);

string query_save_file()
{
	return DATA_DIR "bossd";
}

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "问答");
	CHANNEL_D->do_channel( this_object(), "sys", "问答已经启动。");

	// 恢复BOSS发生状况
	restore();

	if (! arrayp(story_name))
		init_story();

	if (! mapp(history))
		history = ([ ]);

	interval = ([ ]);
	set_heart_beat(20);
}


int ok = 0;
int ok1 = 0;
string path_where=0;


object load_room_place(string file_dir)
{
	string *file, bin_dir, path;
	int max, get_an;
	object room;

	bin_dir = file_dir;
		
	if (! bin_dir)
		bin_dir = "/binaries" + file_dir;

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






int query_next_update()
{
	return last_update + REFRESH_INTERVAL - time();
}

void init_story()
{
	CHANNEL_D->do_channel(this_object(), "chat", "问答更新所有诗词。");
	story_name = get_dir("/adm/daemons/boss/" + "*.c");
	//story_name = map_array(story_name, (: $1[0..<3] :));

	last_update = time();
}

void heart_beat()
{
	object *players;
	mixed* r;
	int a1,a2,a3,i,boos;
	int q=random(100),w=random(100),e=random(100),t=random(100),y=random(100),u=random(100);
	object dao,jian,a,ob;
	object jing,road3,wjg,khy;
	object room;
	int time = time();
	room = do_copy();
	r = localtime(time);

if(r[1]==11+random(20)&&a_flag==0)
	{
		boos=random(17);
		boos=random(5);
		a_flag=1;
		if(boos==1)
		ob=new("/adm/npc/xiayan");
	else if(boos==3||boos==4)
		ob=new("/adm/npc/xiayan");
	else if(boos==5||boos==7||boos==8||boos==9)
	ob=new("/adm/npc/xiayan");
    else if(boos==16)
	ob=new("/adm/npc/xiayan");
		else
	ob=new("/adm/npc/xiayan");
      if(boos==1)
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"听说"HIR""+ob->query("name")+""WHT"正在"+HIG+path_where+HIY"一带作恶！请各大侠客前往击杀！"NOR"");
	  }
	  else if(boos==2)
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"听说"HIR""+ob->query("name")+""WHT"正在"+HIG+path_where+HIY"一带作恶！请各大侠客前往击杀！"NOR"");
	  }else if(boos==3)
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"听说"HIR""+ob->query("name")+""WHT"正在"+HIG+path_where+HIY"一带作恶！请各大侠客前往击杀！"NOR"");
	  }else if(boos==4)
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"听说"HIR""+ob->query("name")+""WHT"正在"+HIG+path_where+HIY"一带作恶！请各大侠客前往击杀！"NOR"");
	  }else
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"听说"HIR""+ob->query("name")+""WHT"正在"+HIG+path_where+HIY"一带作恶！请各大侠客前往击杀！"NOR"");
	  }
	}
	if(r[1]==38&&a_flag==1)a_flag=0;

if(r[1]==0&&r[2]>9&&r[2]<24)
	{
		if(!objectp(running_story)&&!flag)
		{
			flag = 1;
			remove_call_out("start_story");
			remove_call_out("process_story");
			call_out("start_story", 0);
		}
	}
	else flag = 0;

	if(r[1]==30&&r[2]==21)
	{
		jian = find_object("/d/tulong/obj/yitianjian");
		jing = find_object("/d/tulong/obj/zhenjing");
		if ( !yitian_flag && (!jian||!environment(jian)) && (!jing||!environment(jing)) ) 
		{
			road3 = find_object("/d/heimuya/road3");
			if(!road3) road3 = load_object("/d/heimuya/road3");
			road3->start_yitian();
			yitian_flag = 1;
		}
	}
	else yitian_flag = 0;
	
	if(r[1]==01&&r[2]==20)
	{
			khy= find_object("/d/city/khy");
			if(!khy) khy = load_object("/d/city/khy");
			khy->start_khy();
	}

	if(r[1]==04&&r[2]==21&&r[6]==6)
	{
		players = users();
			for(i = 0; i<sizeof(players); i++)
         {
         players[i]->set("wjg",1);
       }
			wjg = find_object("/d/city/wjg");
			if(!wjg) wjg = load_object("/d/city/wjg");
			wjg->start_wjg();
			wjg_flag = 1;
	}
	
	if(r[1]==30&&r[2]==21&&r[6]==6&&wjgl_flag!=1)
	{
		wjgl_flag=1;
		ob=new("/d/wjg/npc/a4");
		ob->move("/d/wjg/a"+random(100)+"");
CHANNEL_D->do_channel(this_object(), "chat", HIY"听说异朽阁主出现了！"+ZJURL("cmds:kjfaf "+ob->query("id"))ZJSIZE(15)+""+ob->query("name")+""NOR"\n");
		shout(HIR "\n"HIY"【异朽阁楼】" NOR+WHT "听说异朽阁主出现了！"+ZJURL("cmds:kjfaf "+ob->query("id"))ZJSIZE(15)+""+ob->query("name")+""NOR"\n" );
	}
if(r[1]==35&&wjgl_flag==1)
{
	wjgl_flag==0;
	players = users();
		for(i = 0; i<sizeof(players); i++)
         {
         players[i]->set("wjg",0);
		  players[i]->set("khya",0);
       }
}
	if(r[1]==30&&r[2]==20)
	{
		dao = find_object("/d/tulong/obj/tulongdao");
		jing = find_object("/d/tulong/obj/zhenjing");
		if ( !tulong_flag && (!dao||!environment(dao)) && (!jing||!environment(jing)) ) 
		{
			road3 = find_object("/d/beijing/haigang");
			if(!road3) road3 = load_object("/d/beijing/haigang");
			road3->start_tulong();
			tulong_flag = 1;
		}
	}
	else tulong_flag = 0;

	if(r[1]==10&&b_flag==0||r[1]==20&&b_flag==0||r[1]==30&&b_flag==0||r[1]==45&&b_flag==0||r[1]==50&&b_flag==0||r[1]==00&&b_flag==0)
	{
		players = users();
		b_flag=1;
		a1=random(120);
	for(i = 0; i<sizeof(players); i++)
         {
         players[i]->set("wenda",1);
       tell_object(players[i],WHT"武林问卷开始！"NOR"\n"); 
       }
	   
	   
	   
		switch (a1)
		{
 case 1: CHANNEL_D->do_channel(this_object(), "chat", HIY"山有木兮木有枝"+ZJURL("cmds:wenda "+"心悦君兮君不知 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 2: CHANNEL_D->do_channel(this_object(), "chat", HIY"人生若只如初见"+ZJURL("cmds:wenda "+"何事秋风悲画扇 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 3: CHANNEL_D->do_channel(this_object(), "chat", HIY"十年生死两茫茫"+ZJURL("cmds:wenda "+"不思量，自难忘 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 4: CHANNEL_D->do_channel(this_object(), "chat", HIY"曾经沧海难为水"+ZJURL("cmds:wenda "+"除却巫山不是云 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 5: CHANNEL_D->do_channel(this_object(), "chat", HIY"嗟余只影系人间"+ZJURL("cmds:wenda "+"如何同生不同死 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;  
 case 6: CHANNEL_D->do_channel(this_object(), "chat", HIY"只愿君心似我心"+ZJURL("cmds:wenda "+"定不负相思意 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 7: CHANNEL_D->do_channel(this_object(), "chat", HIY"愿得一心人"+ZJURL("cmds:wenda "+"白头不相离 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 8: CHANNEL_D->do_channel(this_object(), "chat", HIY"天不生（1.人才）万古如长夜"+ZJURL("cmds:wenda "+"人才 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 9: CHANNEL_D->do_channel(this_object(), "chat", HIY"本服目前巫师是（1.三分2.小三3.小四4.韩老魔）"+ZJURL("cmds:wenda "+"韩老魔 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 10: CHANNEL_D->do_channel(this_object(), "chat", HIY"人面不知何处去"+ZJURL("cmds:wenda "+"桃花依旧笑春风 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 11: CHANNEL_D->do_channel(this_object(), "chat", HIY"鱼沈雁杳天涯路"+ZJURL("cmds:wenda "+"始信人间别离苦 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 12: CHANNEL_D->do_channel(this_object(), "chat", HIY"春宵一刻值千金"+ZJURL("cmds:wenda "+"花有清香月有阴 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 13: CHANNEL_D->do_channel(this_object(), "chat", HIY"今人不见古时月"+ZJURL("cmds:wenda "+"今月曾经照古人 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 14: CHANNEL_D->do_channel(this_object(), "chat", HIY"月上柳梢头"+ZJURL("cmds:wenda "+"人约黄昏后 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 15: CHANNEL_D->do_channel(this_object(), "chat", HIY"沧海月明珠有泪"+ZJURL("cmds:wenda "+"蓝田日暖玉生烟 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 16: CHANNEL_D->do_channel(this_object(), "chat", HIY"风花雪月酒中杯，（路上）行人欲断魂"+ZJURL("cmds:wenda "+"路上 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 17: CHANNEL_D->do_channel(this_object(), "chat", HIY"苟利国家生死以"+ZJURL("cmds:wenda "+"岂因祸福避趋之 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 18: CHANNEL_D->do_channel(this_object(), "chat", HIY"人生自古谁无死"+ZJURL("cmds:wenda "+"留取丹心照汗青 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 19: CHANNEL_D->do_channel(this_object(), "chat", HIY"商女不知亡国恨"+ZJURL("cmds:wenda "+"隔江犹唱后庭花 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 20: CHANNEL_D->do_channel(this_object(), "chat", HIY"新手指导有没有（1.没有）"+ZJURL("cmds:wenda "+"没有 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 21: CHANNEL_D->do_channel(this_object(), "chat", HIY"应是天仙狂醉"+ZJURL("cmds:wenda "+"乱把白云揉碎 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 22: CHANNEL_D->do_channel(this_object(), "chat", HIY"本服最早参加内测的人是谁（龙阳）"+ZJURL("cmds:wenda "+"龙阳 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 23: CHANNEL_D->do_channel(this_object(), "chat", HIY"造化钟神秀"+ZJURL("cmds:wenda "+"阴阳割昏晓 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 24: CHANNEL_D->do_channel(this_object(), "chat", HIY"不要乱带节奏，好好玩对于乱带节奏，如何处理（封号）"+ZJURL("cmds:wenda "+"封号 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 25: CHANNEL_D->do_channel(this_object(), "chat", HIY"人生得意须尽欢"+ZJURL("cmds:wenda "+"莫使金樽空对月 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 26: CHANNEL_D->do_channel(this_object(), "chat", HIY"不肝不氪金，文明游戏（1.文明2.和平3.和谐4.舒服）"+ZJURL("cmds:wenda "+"文明 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 27: CHANNEL_D->do_channel(this_object(), "chat", HIY"你说我帅吗，帅的举个手"+ZJURL("cmds:wenda "+"帅 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 28: CHANNEL_D->do_channel(this_object(), "chat", HIY"春江潮水连海平"+ZJURL("cmds:wenda "+"海上明月共潮生 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 29: CHANNEL_D->do_channel(this_object(), "chat", HIY""+q+"+"+w+"+"+e+"+"+t+"=?"+ZJURL("cmds:wenda "+""+(q+w+e+t)+" "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 30: CHANNEL_D->do_channel(this_object(), "chat", HIY""+q+"*"+w+"*"+e+"*"+t+"=?"+ZJURL("cmds:wenda "+""+(q*w*e*t)+" "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 31: CHANNEL_D->do_channel(this_object(), "chat", HIY"请输入"+q+"的3次方加"+w+""+ZJURL("cmds:wenda "+""+((q*q*q)+w)+" "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 32: CHANNEL_D->do_channel(this_object(), "chat", HIY"每天上线都要做什么（1.签到2.师门3.摸鱼）"+ZJURL("cmds:wenda "+"签到 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 33: CHANNEL_D->do_channel(this_object(), "chat", HIY"武林中如果变得强大（1.摸鱼2.抱肝3.无）"+ZJURL("cmds:wenda "+"抱肝"+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 34: CHANNEL_D->do_channel(this_object(), "chat", HIY"伯牙望知音，琴声意绵绵。打一成语）"+ZJURL("cmds:wenda "+"一见钟情 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 35: CHANNEL_D->do_channel(this_object(), "chat", HIY"困不，困了就休息一下（困）"+ZJURL("cmds:wenda "+"困 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 36: CHANNEL_D->do_channel(this_object(), "chat", HIY"运气要么好要么不好，不过不要慌。相信（自己）"+ZJURL("cmds:wenda "+"自己 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 37: CHANNEL_D->do_channel(this_object(), "chat", HIY"云一緺，玉一梭"+ZJURL("cmds:wenda "+"澹澹衫儿薄薄罗 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 38: CHANNEL_D->do_channel(this_object(), "chat", HIY"尊前拟把归期说"+ZJURL("cmds:wenda "+"欲语春容先惨咽 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 39: CHANNEL_D->do_channel(this_object(), "chat", HIY"饮酒莫辞醉"+ZJURL("cmds:wenda "+"醉多适不愁 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 40: CHANNEL_D->do_channel(this_object(), "chat", HIY"风卷寒云暮雪晴"+ZJURL("cmds:wenda "+"江烟洗尽柳条轻 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 41: CHANNEL_D->do_channel(this_object(), "chat", HIY"但使龙城飞将在"+ZJURL("cmds:wenda "+"不教胡马度阴山 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 42: CHANNEL_D->do_channel(this_object(), "chat", HIY"舞榭歌台"+ZJURL("cmds:wenda "+"风流总被雨打风吹去 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 43: CHANNEL_D->do_channel(this_object(), "chat", HIY"天南地北双飞客"+ZJURL("cmds:wenda "+"老翅几回寒暑 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 44: CHANNEL_D->do_channel(this_object(), "chat", HIY"欢乐趣，离别苦"+ZJURL("cmds:wenda "+"就中更有痴儿女 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 45: CHANNEL_D->do_channel(this_object(), "chat", HIY"葡萄美酒月光杯"+ZJURL("cmds:wenda "+"欲饮琵琶马上催 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 46: CHANNEL_D->do_channel(this_object(), "chat", HIY"明月松间照"+ZJURL("cmds:wenda "+"清泉石上流 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 47: CHANNEL_D->do_channel(this_object(), "chat", HIY"何当共剪西窗烛"+ZJURL("cmds:wenda "+"却话巴山夜雨时 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 48: CHANNEL_D->do_channel(this_object(), "chat", HIY"孤舟蓑笠翁"+ZJURL("cmds:wenda "+"独钓寒江雪 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 49: CHANNEL_D->do_channel(this_object(), "chat", HIY"寻寻觅觅，冷冷清清"+ZJURL("cmds:wenda "+"凄凄惨惨戚戚 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 50: CHANNEL_D->do_channel(this_object(), "chat", HIY"满地黄花堆积。憔悴损"+ZJURL("cmds:wenda "+"如今有谁堪摘 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 51: CHANNEL_D->do_channel(this_object(), "chat", HIY"有情风万里卷潮来"+ZJURL("cmds:wenda "+"无情送潮归 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 52: CHANNEL_D->do_channel(this_object(), "chat", HIY"庭院深深深几许，杨柳堆烟"+ZJURL("cmds:wenda "+"帘幕无重数 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 53: CHANNEL_D->do_channel(this_object(), "chat", HIY"一曲新词酒一杯"+ZJURL("cmds:wenda "+"去年天气旧亭台 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;  
 case 54: CHANNEL_D->do_channel(this_object(), "chat", HIY"曾经沧海难为水"+ZJURL("cmds:wenda "+"除却巫山不是云 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 55: CHANNEL_D->do_channel(this_object(), "chat", HIY"滚滚长江东逝水"+ZJURL("cmds:wenda "+"浪花淘尽英雄 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 56: CHANNEL_D->do_channel(this_object(), "chat", HIY"枯藤老树昏鸦，小桥流水人家"+ZJURL("cmds:wenda "+"古道西风瘦马 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 57: CHANNEL_D->do_channel(this_object(), "chat", HIY"一生一代一双人"+ZJURL("cmds:wenda "+"半醉半醒半浮生 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 58: CHANNEL_D->do_channel(this_object(), "chat", HIY"吉他有几根弦（*根）"+ZJURL("cmds:wenda "+"六根 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 59: CHANNEL_D->do_channel(this_object(), "chat", HIY"满堂花醉三千客"+ZJURL("cmds:wenda "+"一剑霜寒十四州 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 60: CHANNEL_D->do_channel(this_object(), "chat", HIY"君不见黄河之水天上来"+ZJURL("cmds:wenda "+"奔流到海不复回 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 61: CHANNEL_D->do_channel(this_object(), "chat", HIY"秦时明月汉时关"+ZJURL("cmds:wenda "+"万里长征人未还 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 62: CHANNEL_D->do_channel(this_object(), "chat", HIY"前不见古人，后不见来者"+ZJURL("cmds:wenda "+"念天地之悠悠，独怆然而涕下 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 63: CHANNEL_D->do_channel(this_object(), "chat", HIY"本服是慢还是快（快）"+ZJURL("cmds:wenda "+"快 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 64: CHANNEL_D->do_channel(this_object(), "chat", HIY"君不见黄河之水天上来，何必当初（心不甘）"+ZJURL("cmds:wenda "+"心不甘 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 65: CHANNEL_D->do_channel(this_object(), "chat", HIY" 饮马渡秋水"+ZJURL("cmds:wenda "+"饮马渡秋水 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 66: CHANNEL_D->do_channel(this_object(), "chat", HIY"羌笛何须怨杨柳"+ZJURL("cmds:wenda "+"春风不度玉门关 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 67: CHANNEL_D->do_channel(this_object(), "chat", HIY"黄沙百战穿金甲"+ZJURL("cmds:wenda "+"不破楼兰终不还 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 68: CHANNEL_D->do_channel(this_object(), "chat", HIY"赵客缦胡缨"+ZJURL("cmds:wenda "+"吴钩霜雪明 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 69: CHANNEL_D->do_channel(this_object(), "chat", HIY"事了拂衣去"+ZJURL("cmds:wenda "+"深藏功与名 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 70: CHANNEL_D->do_channel(this_object(), "chat", HIY" 两情若是久长时"+ZJURL("cmds:wenda "+"又岂在朝朝暮暮 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 71: CHANNEL_D->do_channel(this_object(), "chat", HIY" 遇水一片汪洋，逢木可闻花香。（字谜）"+ZJURL("cmds:wenda "+"每 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 72: CHANNEL_D->do_channel(this_object(), "chat", HIY" 问世间，情为何物"+ZJURL("cmds:wenda "+"直教生死相许 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 73: CHANNEL_D->do_channel(this_object(), "chat", HIY" 似此星辰非昨夜"+ZJURL("cmds:wenda "+"为谁风露立中宵 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 74: CHANNEL_D->do_channel(this_object(), "chat", HIY" 蒹葭苍苍，白露为霜"+ZJURL("cmds:wenda "+"所谓伊人，在水一方 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 75: CHANNEL_D->do_channel(this_object(), "chat", HIY" 野有蔓草"+ZJURL("cmds:wenda "+"零露漙兮 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 76: CHANNEL_D->do_channel(this_object(), "chat", HIY" 山有扶苏"+ZJURL("cmds:wenda "+"隰有荷华 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 77: CHANNEL_D->do_channel(this_object(), "chat", HIY" 昨夜雨疏风骤"+ZJURL("cmds:wenda "+"浓睡不消残酒 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 78: CHANNEL_D->do_channel(this_object(), "chat", HIY" 常记溪亭日暮"+ZJURL("cmds:wenda "+"沉醉不知归路 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 79: CHANNEL_D->do_channel(this_object(), "chat", HIY" 木叶纷纷归路"+ZJURL("cmds:wenda "+"残月晓风何处 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 80: CHANNEL_D->do_channel(this_object(), "chat", HIY" 李清照是什么诗派"+ZJURL("cmds:wenda "+"亲哦派 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 81: CHANNEL_D->do_channel(this_object(), "chat", HIY" 五十年鸿业"+ZJURL("cmds:wenda "+"说与山鬼听 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 82: CHANNEL_D->do_channel(this_object(), "chat", HIY" 人生当苦无妨"+ZJURL("cmds:wenda "+"良人当归即好 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 83: CHANNEL_D->do_channel(this_object(), "chat", HIY" 问"+q+"*"+q+"+"+e+"*"+t+""+ZJURL("cmds:wenda "+"q*q+e*t "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 84: CHANNEL_D->do_channel(this_object(), "chat", HIY" 抽尽红丝泪涟涟"+ZJURL("cmds:wenda "+"江 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 85: CHANNEL_D->do_channel(this_object(), "chat", HIY"要想活的久（1.抽yan2.喝酒3.上网4.吃泡面）"+ZJURL("cmds:wenda "+"喝酒 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 86: CHANNEL_D->do_channel(this_object(), "chat", HIY"本是青灯不归客"+ZJURL("cmds:wenda "+"却因浊酒留风尘 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 87: CHANNEL_D->do_channel(this_object(), "chat", HIY"愿我如星君如月"+ZJURL("cmds:wenda "+"夜夜流光相皎洁 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 88: CHANNEL_D->do_channel(this_object(), "chat", HIY"醉后不知天在水"+ZJURL("cmds:wenda "+"满船清梦压星河 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 89: CHANNEL_D->do_channel(this_object(), "chat", HIY"白茶清风别无事"+ZJURL("cmds:wenda "+"我在等风也等你 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 90: CHANNEL_D->do_channel(this_object(), "chat", HIY"北斗七星高"+ZJURL("cmds:wenda "+"哥舒夜带刀 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 91: CHANNEL_D->do_channel(this_object(), "chat", HIY"边月随弓影"+ZJURL("cmds:wenda "+"胡霜拂剑花 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 92: CHANNEL_D->do_channel(this_object(), "chat", HIY"昨夜星辰昨夜风"+ZJURL("cmds:wenda "+"画楼西畔桂堂东 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 93: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx，梦回吹角连营"+ZJURL("cmds:wenda "+"醉里挑灯看剑 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 94: CHANNEL_D->do_channel(this_object(), "chat", HIY"持节云中，xxxxx？"+ZJURL("cmds:wenda "+"何日遣冯唐 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 95: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx，赢得身前身后名"+ZJURL("cmds:wenda "+"了却身前身后事 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 96: CHANNEL_D->do_channel(this_object(), "chat", HIY"北风卷地白草折，xxxxxxx"+ZJURL("cmds:wenda "+"胡天八月即飞雪 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 97: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx?留取丹心照汗青"+ZJURL("cmds:wenda "+"人生自古谁无死 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 98: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx，千树万树梨花开"+ZJURL("cmds:wenda "+"忽如一夜春风来 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 99: CHANNEL_D->do_channel(this_object(), "chat", HIY"竹杖芒鞋轻胜马，谁怕？xxxxxxx"+ZJURL("cmds:wenda "+"一蓑烟雨任凭生 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 100: CHANNEL_D->do_channel(this_object(), "chat", HIY"对酒当歌，xxxx"+ZJURL("cmds:wenda "+"人生几何 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 101: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxx，月有阴晴圆缺"+ZJURL("cmds:wenda "+"人有悲欢离合 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 102: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx，满船星河入梦来"+ZJURL("cmds:wenda "+"醉后不知天在水 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 103: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxx，满城尽带黄金甲"+ZJURL("cmds:wenda "+"冲天香阵透长安 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break; 
 case 104: CHANNEL_D->do_channel(this_object(), "chat", HIY"后来烟雨落盛京"+ZJURL("cmds:wenda "+"一人打伞两人行 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 105: CHANNEL_D->do_channel(this_object(), "chat", HIY"回首向来萧瑟处，归去"+ZJURL("cmds:wenda "+"也无风雨也无情 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;		
 case 106: CHANNEL_D->do_channel(this_object(), "chat", HIY"但行好事"+ZJURL("cmds:wenda "+"莫问前程 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
 case 107: CHANNEL_D->do_channel(this_object(), "chat", HIY"隐约雷鸣，阴霾天空，但盼风雨来"+ZJURL("cmds:wenda "+"能留你在此 "+"1497163455!")ZJSIZE(15)+"回答"NOR""); break;
		default:
			break;
		}
		
		
		
		
	if(r[1]==12||r[1]==22||r[1]==32||r[1]==42||r[1]==52||r[1]==2)
	{	
players = users();
	b_flag=0;
		for(i = 0; i<sizeof(players); i++)
         {
         players[i]->set("wenda",0);
       }
	}
	
	
}

}