// storyd.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;
#include <localtime.h>


// ��ʼ��BOSSϵͳ
#define REFRESH_INTERVAL	10 * 3600

string *story_name;
mapping history;
int     last_update = 0;
mapping room_place = ([
	"����ɽ"		: "/d/baituo/",
	"����"			: "/d/beijing/",
	"����" 			: "/d/changan/",
	"����"			: "/d/city/",
	"�ɶ�"			: "/d/city3/",
	"����"			: "/d/dali/",
	"����ɽ" 		: "/d/emei/",
	"��ɽ"			: "/d/foshan/",
	"ؤ��" 			: "/d/gaibang/",
	"����"			: "/d/fuzhou/",
	"����"			: "/d/guanwai/",
	"����ɽׯ"	: "/d/guiyun/",
	"��Ĺ" 			: "/d/gumu/",
	"����"			: "/d/hangzhou/",
	"��ľ��"		: "/d/heimuya/",
	"��ɽ" 			: "/d/hengshan/",
	"��ɽ"			: "/d/henshan/",
	"�ƺ�"			: "/d/huanghe/",
	"��ɽ��"		: "/d/huashan/",
	"���չ�"			: "/d/lingjiu/",
	"����"			: "/d/lingzhou/",
	"÷ׯ"			: "/d/meizhuang/",
	"����" 			: "/d/mingjiao/",
	"���ɽ"		: "/d/qingcheng/",
	"ȫ����" 		: "/d/quanzhen/",
	"Ȫ��" 			: "/d/quanzhou/",
	"������" 		: "/d/shaolin/",
	"������"		: "/d/shenlong/",
	"��ɽ"			: "/d/songshan/",
	"����"			: "/d/suzhou/",
	"̩ɽ"			: "/d/taishan/",
	"�һ���"		: "/d/taohua/",
	"������"		: "/d/tianlongsi/",
	"��ٹ�"		: "/d/wanjiegu/",
	"�䵱ɽ"		: "/d/wudang/",
	"���͵�"		: "/d/xiakedao/",
	"����"			: "/d/xiangyang/",
	"��ң��"		: "/d/xiaoyao/",
	"���޺�" 		: "/d/xingxiu/",
	"Ѫ����" 		: "/d/xuedao/",
	"ѩɽ" 			: "/d/xueshan/",
	"������" 		: "/d/yanziwu/",
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
	set("channel_id", "�ʴ�");
	CHANNEL_D->do_channel( this_object(), "sys", "�ʴ��Ѿ�������");

	// �ָ�BOSS����״��
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
	
	//ȷ��λ�� 
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
	CHANNEL_D->do_channel(this_object(), "chat", "�ʴ��������ʫ�ʡ�");
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
	CHANNEL_D->do_channel(this_object(), "chat", HIY"��˵"HIR""+ob->query("name")+""WHT"����"+HIG+path_where+HIY"һ���������������ǰ����ɱ��"NOR"");
	  }
	  else if(boos==2)
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"��˵"HIR""+ob->query("name")+""WHT"����"+HIG+path_where+HIY"һ���������������ǰ����ɱ��"NOR"");
	  }else if(boos==3)
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"��˵"HIR""+ob->query("name")+""WHT"����"+HIG+path_where+HIY"һ���������������ǰ����ɱ��"NOR"");
	  }else if(boos==4)
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"��˵"HIR""+ob->query("name")+""WHT"����"+HIG+path_where+HIY"һ���������������ǰ����ɱ��"NOR"");
	  }else
	  {
		  ob->move(room);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"��˵"HIR""+ob->query("name")+""WHT"����"+HIG+path_where+HIY"һ���������������ǰ����ɱ��"NOR"");
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
CHANNEL_D->do_channel(this_object(), "chat", HIY"��˵������������ˣ�"+ZJURL("cmds:kjfaf "+ob->query("id"))ZJSIZE(15)+""+ob->query("name")+""NOR"\n");
		shout(HIR "\n"HIY"�������¥��" NOR+WHT "��˵������������ˣ�"+ZJURL("cmds:kjfaf "+ob->query("id"))ZJSIZE(15)+""+ob->query("name")+""NOR"\n" );
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
       tell_object(players[i],WHT"�����ʾ�ʼ��"NOR"\n"); 
       }
	   
	   
	   
		switch (a1)
		{
 case 1: CHANNEL_D->do_channel(this_object(), "chat", HIY"ɽ��ľ��ľ��֦"+ZJURL("cmds:wenda "+"���þ������֪ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 2: CHANNEL_D->do_channel(this_object(), "chat", HIY"������ֻ�����"+ZJURL("cmds:wenda "+"������籯���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 3: CHANNEL_D->do_channel(this_object(), "chat", HIY"ʮ��������ãã"+ZJURL("cmds:wenda "+"��˼���������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 4: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����׺���Ϊˮ"+ZJURL("cmds:wenda "+"��ȴ��ɽ������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 5: CHANNEL_D->do_channel(this_object(), "chat", HIY"���ֻӰϵ�˼�"+ZJURL("cmds:wenda "+"���ͬ����ͬ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;  
 case 6: CHANNEL_D->do_channel(this_object(), "chat", HIY"ֻԸ����������"+ZJURL("cmds:wenda "+"��������˼�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 7: CHANNEL_D->do_channel(this_object(), "chat", HIY"Ը��һ����"+ZJURL("cmds:wenda "+"��ͷ������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 8: CHANNEL_D->do_channel(this_object(), "chat", HIY"�첻����1.�˲ţ�����糤ҹ"+ZJURL("cmds:wenda "+"�˲� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 9: CHANNEL_D->do_channel(this_object(), "chat", HIY"����Ŀǰ��ʦ�ǣ�1.����2.С��3.С��4.����ħ��"+ZJURL("cmds:wenda "+"����ħ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 10: CHANNEL_D->do_channel(this_object(), "chat", HIY"���治֪�δ�ȥ"+ZJURL("cmds:wenda "+"�һ�����Ц���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 11: CHANNEL_D->do_channel(this_object(), "chat", HIY"������������·"+ZJURL("cmds:wenda "+"ʼ���˼����� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 12: CHANNEL_D->do_channel(this_object(), "chat", HIY"����һ��ֵǧ��"+ZJURL("cmds:wenda "+"�������������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 13: CHANNEL_D->do_channel(this_object(), "chat", HIY"���˲�����ʱ��"+ZJURL("cmds:wenda "+"���������չ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 14: CHANNEL_D->do_channel(this_object(), "chat", HIY"��������ͷ"+ZJURL("cmds:wenda "+"��Լ�ƻ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 15: CHANNEL_D->do_channel(this_object(), "chat", HIY"�׺�����������"+ZJURL("cmds:wenda "+"������ů������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 16: CHANNEL_D->do_channel(this_object(), "chat", HIY"�绨ѩ�¾��б�����·�ϣ��������ϻ�"+ZJURL("cmds:wenda "+"·�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 17: CHANNEL_D->do_channel(this_object(), "chat", HIY"��������������"+ZJURL("cmds:wenda "+"�����������֮ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 18: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����Թ�˭����"+ZJURL("cmds:wenda "+"��ȡ�����պ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 19: CHANNEL_D->do_channel(this_object(), "chat", HIY"��Ů��֪������"+ZJURL("cmds:wenda "+"�����̳���ͥ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 20: CHANNEL_D->do_channel(this_object(), "chat", HIY"����ָ����û�У�1.û�У�"+ZJURL("cmds:wenda "+"û�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 21: CHANNEL_D->do_channel(this_object(), "chat", HIY"Ӧ�����ɿ���"+ZJURL("cmds:wenda "+"�ҰѰ������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 22: CHANNEL_D->do_channel(this_object(), "chat", HIY"��������μ��ڲ������˭��������"+ZJURL("cmds:wenda "+"���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 23: CHANNEL_D->do_channel(this_object(), "chat", HIY"�컯������"+ZJURL("cmds:wenda "+"��������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 24: CHANNEL_D->do_channel(this_object(), "chat", HIY"��Ҫ�Ҵ����࣬�ú�������Ҵ����࣬��δ�����ţ�"+ZJURL("cmds:wenda "+"��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 25: CHANNEL_D->do_channel(this_object(), "chat", HIY"���������뾡��"+ZJURL("cmds:wenda "+"Īʹ���׿ն��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 26: CHANNEL_D->do_channel(this_object(), "chat", HIY"���β�봽�������Ϸ��1.����2.��ƽ3.��г4.�����"+ZJURL("cmds:wenda "+"���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 27: CHANNEL_D->do_channel(this_object(), "chat", HIY"��˵��˧��˧�ľٸ���"+ZJURL("cmds:wenda "+"˧ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 28: CHANNEL_D->do_channel(this_object(), "chat", HIY"������ˮ����ƽ"+ZJURL("cmds:wenda "+"�������¹����� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 29: CHANNEL_D->do_channel(this_object(), "chat", HIY""+q+"+"+w+"+"+e+"+"+t+"=?"+ZJURL("cmds:wenda "+""+(q+w+e+t)+" "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 30: CHANNEL_D->do_channel(this_object(), "chat", HIY""+q+"*"+w+"*"+e+"*"+t+"=?"+ZJURL("cmds:wenda "+""+(q*w*e*t)+" "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 31: CHANNEL_D->do_channel(this_object(), "chat", HIY"������"+q+"��3�η���"+w+""+ZJURL("cmds:wenda "+""+((q*q*q)+w)+" "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 32: CHANNEL_D->do_channel(this_object(), "chat", HIY"ÿ�����߶�Ҫ��ʲô��1.ǩ��2.ʦ��3.���㣩"+ZJURL("cmds:wenda "+"ǩ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 33: CHANNEL_D->do_channel(this_object(), "chat", HIY"������������ǿ��1.����2.����3.�ޣ�"+ZJURL("cmds:wenda "+"����"+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 34: CHANNEL_D->do_channel(this_object(), "chat", HIY"������֪�������������ࡣ��һ���"+ZJURL("cmds:wenda "+"һ������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 35: CHANNEL_D->do_channel(this_object(), "chat", HIY"���������˾���Ϣһ�£�����"+ZJURL("cmds:wenda "+"�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 36: CHANNEL_D->do_channel(this_object(), "chat", HIY"����Ҫô��Ҫô���ã�������Ҫ�š����ţ��Լ���"+ZJURL("cmds:wenda "+"�Լ� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 37: CHANNEL_D->do_channel(this_object(), "chat", HIY"��һ������һ��"+ZJURL("cmds:wenda "+"������������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 38: CHANNEL_D->do_channel(this_object(), "chat", HIY"��ǰ��ѹ���˵"+ZJURL("cmds:wenda "+"���ﴺ���Ȳ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 39: CHANNEL_D->do_channel(this_object(), "chat", HIY"����Ī����"+ZJURL("cmds:wenda "+"����ʲ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 40: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����ĺѩ��"+ZJURL("cmds:wenda "+"����ϴ�������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 41: CHANNEL_D->do_channel(this_object(), "chat", HIY"��ʹ���Ƿɽ���"+ZJURL("cmds:wenda "+"���̺������ɽ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 42: CHANNEL_D->do_channel(this_object(), "chat", HIY"��鿸�̨"+ZJURL("cmds:wenda "+"�����ܱ����紵ȥ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 43: CHANNEL_D->do_channel(this_object(), "chat", HIY"���ϵر�˫�ɿ�"+ZJURL("cmds:wenda "+"�ϳἸ�غ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 44: CHANNEL_D->do_channel(this_object(), "chat", HIY"����Ȥ������"+ZJURL("cmds:wenda "+"���и��гն�Ů "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 45: CHANNEL_D->do_channel(this_object(), "chat", HIY"���������¹Ɑ"+ZJURL("cmds:wenda "+"�����������ϴ� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 46: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����ɼ���"+ZJURL("cmds:wenda "+"��Ȫʯ���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 47: CHANNEL_D->do_channel(this_object(), "chat", HIY"�ε�����������"+ZJURL("cmds:wenda "+"ȴ����ɽҹ��ʱ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 48: CHANNEL_D->do_channel(this_object(), "chat", HIY"����������"+ZJURL("cmds:wenda "+"��������ѩ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 49: CHANNEL_D->do_channel(this_object(), "chat", HIY"ѰѰ���٣���������"+ZJURL("cmds:wenda "+"����Ҳ����� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 50: CHANNEL_D->do_channel(this_object(), "chat", HIY"���ػƻ��ѻ�������"+ZJURL("cmds:wenda "+"�����˭��ժ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 51: CHANNEL_D->do_channel(this_object(), "chat", HIY"������������"+ZJURL("cmds:wenda "+"�����ͳ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 52: CHANNEL_D->do_channel(this_object(), "chat", HIY"ͥԺ���������������"+ZJURL("cmds:wenda "+"��Ļ������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 53: CHANNEL_D->do_channel(this_object(), "chat", HIY"һ���´ʾ�һ��"+ZJURL("cmds:wenda "+"ȥ��������̨ͤ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;  
 case 54: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����׺���Ϊˮ"+ZJURL("cmds:wenda "+"��ȴ��ɽ������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 55: CHANNEL_D->do_channel(this_object(), "chat", HIY"������������ˮ"+ZJURL("cmds:wenda "+"�˻��Ծ�Ӣ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 56: CHANNEL_D->do_channel(this_object(), "chat", HIY"����������ѻ��С����ˮ�˼�"+ZJURL("cmds:wenda "+"�ŵ��������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 57: CHANNEL_D->do_channel(this_object(), "chat", HIY"һ��һ��һ˫��"+ZJURL("cmds:wenda "+"������Ѱ븡�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 58: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����м����ң�*����"+ZJURL("cmds:wenda "+"���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 59: CHANNEL_D->do_channel(this_object(), "chat", HIY"���û�����ǧ��"+ZJURL("cmds:wenda "+"һ��˪��ʮ���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 60: CHANNEL_D->do_channel(this_object(), "chat", HIY"�������ƺ�֮ˮ������"+ZJURL("cmds:wenda "+"�������������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 61: CHANNEL_D->do_channel(this_object(), "chat", HIY"��ʱ���º�ʱ��"+ZJURL("cmds:wenda "+"���ﳤ����δ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 62: CHANNEL_D->do_channel(this_object(), "chat", HIY"ǰ�������ˣ��󲻼�����"+ZJURL("cmds:wenda "+"�����֮���ƣ�����Ȼ������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 63: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����������ǿ죨�죩"+ZJURL("cmds:wenda "+"�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 64: CHANNEL_D->do_channel(this_object(), "chat", HIY"�������ƺ�֮ˮ���������αص������Ĳ��ʣ�"+ZJURL("cmds:wenda "+"�Ĳ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 65: CHANNEL_D->do_channel(this_object(), "chat", HIY" �������ˮ"+ZJURL("cmds:wenda "+"�������ˮ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 66: CHANNEL_D->do_channel(this_object(), "chat", HIY"Ǽ�Ѻ���Թ����"+ZJURL("cmds:wenda "+"���粻�����Ź� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 67: CHANNEL_D->do_channel(this_object(), "chat", HIY"��ɳ��ս�����"+ZJURL("cmds:wenda "+"����¥���ղ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 68: CHANNEL_D->do_channel(this_object(), "chat", HIY"�Կ��Ϻ�ӧ"+ZJURL("cmds:wenda "+"�⹳˪ѩ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 69: CHANNEL_D->do_channel(this_object(), "chat", HIY"���˷���ȥ"+ZJURL("cmds:wenda "+"��ع����� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 70: CHANNEL_D->do_channel(this_object(), "chat", HIY" �������Ǿó�ʱ"+ZJURL("cmds:wenda "+"�����ڳ���ĺĺ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 71: CHANNEL_D->do_channel(this_object(), "chat", HIY" ��ˮһƬ���󣬷�ľ���Ż��㡣�����գ�"+ZJURL("cmds:wenda "+"ÿ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 72: CHANNEL_D->do_channel(this_object(), "chat", HIY" �����䣬��Ϊ����"+ZJURL("cmds:wenda "+"ֱ���������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 73: CHANNEL_D->do_channel(this_object(), "chat", HIY" �ƴ��ǳ�����ҹ"+ZJURL("cmds:wenda "+"Ϊ˭��¶������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 74: CHANNEL_D->do_channel(this_object(), "chat", HIY" ����Բԣ���¶Ϊ˪"+ZJURL("cmds:wenda "+"��ν���ˣ���ˮһ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 75: CHANNEL_D->do_channel(this_object(), "chat", HIY" Ұ������"+ZJURL("cmds:wenda "+"��¶�`�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 76: CHANNEL_D->do_channel(this_object(), "chat", HIY" ɽ�з���"+ZJURL("cmds:wenda "+"���кɻ� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 77: CHANNEL_D->do_channel(this_object(), "chat", HIY" ��ҹ�������"+ZJURL("cmds:wenda "+"Ũ˯�����о� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 78: CHANNEL_D->do_channel(this_object(), "chat", HIY" ����Ϫͤ��ĺ"+ZJURL("cmds:wenda "+"����֪��· "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 79: CHANNEL_D->do_channel(this_object(), "chat", HIY" ľҶ�׷׹�·"+ZJURL("cmds:wenda "+"��������δ� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 80: CHANNEL_D->do_channel(this_object(), "chat", HIY" ��������ʲôʫ��"+ZJURL("cmds:wenda "+"��Ŷ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 81: CHANNEL_D->do_channel(this_object(), "chat", HIY" ��ʮ���ҵ"+ZJURL("cmds:wenda "+"˵��ɽ���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 82: CHANNEL_D->do_channel(this_object(), "chat", HIY" ���������޷�"+ZJURL("cmds:wenda "+"���˵��鼴�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 83: CHANNEL_D->do_channel(this_object(), "chat", HIY" ��"+q+"*"+q+"+"+e+"*"+t+""+ZJURL("cmds:wenda "+"q*q+e*t "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 84: CHANNEL_D->do_channel(this_object(), "chat", HIY" �龡��˿������"+ZJURL("cmds:wenda "+"�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 85: CHANNEL_D->do_channel(this_object(), "chat", HIY"Ҫ���ľã�1.��yan2.�Ⱦ�3.����4.�����棩"+ZJURL("cmds:wenda "+"�Ⱦ� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 86: CHANNEL_D->do_channel(this_object(), "chat", HIY"������Ʋ����"+ZJURL("cmds:wenda "+"ȴ���Ǿ����糾 "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 87: CHANNEL_D->do_channel(this_object(), "chat", HIY"Ը�����Ǿ�����"+ZJURL("cmds:wenda "+"ҹҹ�������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 88: CHANNEL_D->do_channel(this_object(), "chat", HIY"���֪����ˮ"+ZJURL("cmds:wenda "+"��������ѹ�Ǻ� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 89: CHANNEL_D->do_channel(this_object(), "chat", HIY"�ײ���������"+ZJURL("cmds:wenda "+"���ڵȷ�Ҳ���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 90: CHANNEL_D->do_channel(this_object(), "chat", HIY"�������Ǹ�"+ZJURL("cmds:wenda "+"����ҹ���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 91: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����湭Ӱ"+ZJURL("cmds:wenda "+"��˪������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 92: CHANNEL_D->do_channel(this_object(), "chat", HIY"��ҹ�ǳ���ҹ��"+ZJURL("cmds:wenda "+"��¥���Ϲ��ö� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 93: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx���λش�����Ӫ"+ZJURL("cmds:wenda "+"�������ƿ��� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 94: CHANNEL_D->do_channel(this_object(), "chat", HIY"�ֽ����У�xxxxx��"+ZJURL("cmds:wenda "+"����ǲ���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 95: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx��Ӯ����ǰ�����"+ZJURL("cmds:wenda "+"��ȴ��ǰ����� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 96: CHANNEL_D->do_channel(this_object(), "chat", HIY"�����ذײ��ۣ�xxxxxxx"+ZJURL("cmds:wenda "+"������¼���ѩ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 97: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx?��ȡ�����պ���"+ZJURL("cmds:wenda "+"�����Թ�˭���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 98: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx��ǧ�������滨��"+ZJURL("cmds:wenda "+"����һҹ������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 99: CHANNEL_D->do_channel(this_object(), "chat", HIY"����âЬ��ʤ��˭�£�xxxxxxx"+ZJURL("cmds:wenda "+"һ��������ƾ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 100: CHANNEL_D->do_channel(this_object(), "chat", HIY"�ԾƵ��裬xxxx"+ZJURL("cmds:wenda "+"�������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 101: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxx����������Բȱ"+ZJURL("cmds:wenda "+"���б������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 102: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxxx�������Ǻ�������"+ZJURL("cmds:wenda "+"���֪����ˮ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 103: CHANNEL_D->do_channel(this_object(), "chat", HIY"xxxxxx�����Ǿ����ƽ��"+ZJURL("cmds:wenda "+"��������͸���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break; 
 case 104: CHANNEL_D->do_channel(this_object(), "chat", HIY"����������ʢ��"+ZJURL("cmds:wenda "+"һ�˴�ɡ������ "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 105: CHANNEL_D->do_channel(this_object(), "chat", HIY"����������ɪ������ȥ"+ZJURL("cmds:wenda "+"Ҳ�޷���Ҳ���� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;		
 case 106: CHANNEL_D->do_channel(this_object(), "chat", HIY"���к���"+ZJURL("cmds:wenda "+"Ī��ǰ�� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
 case 107: CHANNEL_D->do_channel(this_object(), "chat", HIY"��Լ������������գ����η�����"+ZJURL("cmds:wenda "+"�������ڴ� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR""); break;
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