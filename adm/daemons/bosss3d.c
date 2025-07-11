// storyd.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;

// 初始化BOSS系统
#define REFRESH_INTERVAL	10 * 3600

string *story_name;
mapping history;
int     last_update = 0;

static mapping interval;
static object  running_story;
static int flag;
static int a_flag;
static int c_flag;
static int d_flag;
static int e_flag;
static int f_flag;

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
	set("channel_id", "世界管理员");
	CHANNEL_D->do_channel( this_object(), "sys", "公共boss。");

	// 恢复BOSS发生状况
	restore();

	if (! arrayp(story_name))
		init_story();

	if (! mapp(history))
		history = ([ ]);

	interval = ([ ]);
	set_heart_beat(20);
}

int query_next_update()
{
	return last_update + REFRESH_INTERVAL - time();
}

void init_story()
{
//	CHANNEL_D->do_channel(this_object(), "chat", "公共boss启动，更新所有boss。");
	story_name = get_dir("/adm/daemons/boss/" + "*.c");
	//story_name = map_array(story_name, (: $1[0..<3] :));

	last_update = time();
}

void heart_beat()
{
	object *players;
	mixed* r;
	int a1,a2,a3,i,a4;
	int q=random(100),w=random(100),e=random(100),t=random(100),y=random(100),u=random(100);
	object dao,jian,a,ob;
	object jing,road3,wjg,khy;
	int time = time();
	r = localtime(time);


	if(r[1]==10&&b_flag==0)
	{
		players = users();
		b_flag=1;
		a1=random(2);
		if(a1==2)
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现"HIR""+ob->query("name")+""WHT"正在"HIC"扬州北门"WHT"危害武林！请各大侠客前往击杀！"NOR"");		
		}
		else if(a1==2)
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现"HIR""+ob->query("name")+""WHT"正在"HIC"古墓黄沙岭"WHT"危害武林！请各大侠客前往击杀！"NOR"");		
		}else 
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/beidajie1");
		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现"HIR""+ob->query("name")+""WHT"正在"HIC"白云城北大街"WHT"危害武林！请各大侠客前往击杀！"NOR"");		
		}
	}
	
	if(r[1]==20&&b_flag==0)
	{
		players = users();
		b_flag=1;
		a1=random(2);
		if(a1==2)
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现白云客卿"HIR""+ob->query("name")+""WHT"出现在"HIC"华山云门"WHT"一带！！"NOR"");		
		}
		else if(a1==2)
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现白云客卿"HIR""+ob->query("name")+""WHT"出现在"HIC"华山云门"WHT"一带！！"NOR"");		
		}else 
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/nandajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现白云客卿"HIR""+ob->query("name")+""WHT"出现在"HIC"华山云门"WHT"一带！！"NOR"");			
		}
	}
	
	if(r[1]==30&&b_flag==0)
	{
		players = users();
		b_flag=1;
		a1=random(2);
		if(a1==2)
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现前朝太监"HIR""+ob->query("name")+""WHT"出现在"HIC"泰山回马岭"WHT"一带！！"NOR"");		
		}
		else if(a1==2)
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现前朝太监"HIR""+ob->query("name")+""WHT"出现在"HIC"泰山回马岭"WHT"一带！！"NOR"");			
		}else 
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/xidajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现前朝太监"HIR""+ob->query("name")+""WHT"出现在"HIC"泰山回马岭"WHT"一带！！"NOR"");			
		}
	}
	
	if(r[1]==58&&b_flag==0)
	{
		players = users();
		b_flag=1;
		a1=random(2);
		if(a1==2)
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现"HIR""+ob->query("name")+""WHT"出现在"HIC"长安青龙街"WHT"请及时将其击败遣回天庭！"NOR"");		
		}
		else if(a1==2)
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现"HIR""+ob->query("name")+""WHT"出现在"HIC"佛山南门"WHT"请及时将其击败遣回天庭！"NOR"");		
		}else 
		{
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		ob=new("/d/boss/jiangshi");
		  ob->move("d/city/dongdajie1");
		  		  		ob=new("/d/boss/jiangshi");
		  ob->move("data/hell/0/guangchang");
//	CHANNEL_D->do_channel(this_object(), "chat", WHT"有人发现"HIR""+ob->query("name")+""WHT"出现在"HIC"关外雪地"WHT"请及时将其击败遣回天庭！"NOR"");		
		}
	}
	if(r[1]==09)
	{	
players = users();
	b_flag=0;

	}
	if(r[1]==19)b_flag=0;
	if(r[1]==29)b_flag=0;
	if(r[1]==39)b_flag=0;
	if(r[1]==57)b_flag=0;

	
}

