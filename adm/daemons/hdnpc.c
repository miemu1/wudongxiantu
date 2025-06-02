//autonpc.c
//by luoyun
#include <ansi.h>
#include <net/dns.h>//����������
inherit F_DBASE;
#include <localtime.h>

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

int ok = 0;//�������
int ok1 = 0;//����Ψһ��Ʒ���
int xiaofeng = 0;
int yanqing = 0;
int laoshu = 0;
int laoren = 0;//�������
int sikong = 0;//˾��ժ�Ǳ��
int wabao=0;//�ڱ����
int dati=0;//������
int yzbq=0;//���а������
int yitian=0;//������
int tulong=0;//�������

string path_where=0;

void create()
{
	seteuid(getuid());
	set("channel_id", "�NPCϵͳ");
	CHANNEL_D->do_channel( this_object(), "sys", "�NPCϵͳ�Ѿ�������"NOR);
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
				tell_object(ob,"ϵͳ������Ʒˢ�£������ϵ�"+list[k]->short()+"��ʧ�ˣ�\n");
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
	int tiku,hang;//������
	times = ctime(GMT);
	//Sun(������) Mon(����һ)  Tue(���ڶ�)  Wed(������)  Thu(������)  Fri(������)  Sat(������)
	d = times[0..2];//����
	h = to_int(times[10..12]);//ʱ
	s = to_int(times[14..15]);//��
	m = to_int(times[17..18]);//��
//��ʮ�ֵ�ʱ��ˢ�·���
	if ((s == 50) && !ok) {
		if (!room = do_copy())
			room = do_copy();
		else {
			ob = new("/clone/npc/feizei");
			if (ob->move(room)) {
				message("channel", HIR"���ٸ���:"HIY"��˵�з�����"+HIG+path_where+HIY"һ����û��������������ﰲȫ��"NOR"\n", users());
				CHANNEL_D->do_channel( this_object(), "sys", "���������ˡ�"+ZJURL("cmds:goto "+file_name(ob))+"�ɹ�ȥ"+NOR"��");
				ok = 1;
				call_out("remove_npc", 120, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "��������ʧ�ܡ�"NOR);
		}
	}
	

	
	//����
	if ((s ==30&&((h%4)==2)&& !xiaofeng) )
{
			ob = new("/kungfu/class/misc/xiaofeng");
			if (ob->move("/d/changan/xiaojinghu")) 
			CHANNEL_D->do_channel(this_object(), "rumor",HIY"��˵��Ժ���������ڳ���С������"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", "��������ˡ�"+ZJURL("cmds:goto "+file_name(ob))+"�ɹ�ȥ"+NOR"��");
			xiaofeng = 1;
				call_out("remove_xiaofeng", 3600, ob);
}
	if (s!=30) xiaofeng = 0;//������ʱ��һ��������

	//������
	if ((s == 30&&((h%4)==2)&& !yanqing) )
{
			ob = new("/kungfu/class/misc/yanqing");
			if (ob->move("/d/lingzhou/yipindating"))
			CHANNEL_D->do_channel(this_object(), "rumor",HIR"��˵����̫�ӳ���������һƷ�á�"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", "����������ˡ�"+ZJURL("cmds:goto "+file_name(ob))+"�ɹ�ȥ"+NOR"��");
				yanqing = 1;
				call_out("remove_yanqing", 3600, ob);	
}
	if (s!=30) yanqing = 0;//������ʱ��һ��������
	
	//��ë����
/*
	if ((s ==10&&(h==10||h==22)&& !laoshu) )
{
			ob = new("/kungfu/class/misc/laoshujing");
			if (ob->move("/d/quanzhou/zhongxin"))
			CHANNEL_D->do_channel(this_object(), "rumor",HIW"��˵��ë����Ϊ���˼������Ȫ�ݳ����ġ�"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", "��ë���󾫳����ˡ�"+ZJURL("cmds:goto "+file_name(ob))+"�ɹ�ȥ"+NOR"��");
				laoshu = 1;
				call_out("remove_laoshu", 3600, ob);	
}
	if (s!=10) laoshu = 0;//������ʱ��һ��������
	*/


	if ((s ==31&&(h==12||h==19||h==20||h==21)&& !laoren) )
{
			ob = new("/adm/npc/laoren");
			set("channel_id", "�������");
				
				switch(h){
		case 12:	ob->set("fst",1);
							msg="��ħ����̨";
			break;
		case 19:	ob->set("jxz",1);
							msg="Ѫս����ׯ";
			break;
		case 20:	ob->set("tulong",1);
							msg="��������";
			break;
		case 21:	ob->set("yitian",1);
							msg="������";
			break;
		//default:	
			//break;							
		}	
		
			if(ob->move("/d/changan/tea-shop"))
			CHANNEL_D->do_channel(this_object(), "chat",HIW"�Ϸ������ڳ�����ݣ���"+msg+"�������Ѿ�������"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", "������˳����ˡ�"+ZJURL("cmds:goto "+file_name(ob))+"�ɹ�ȥ"+NOR"��");
			set("channel_id", "�NPCϵͳ");

				laoren = 1;
				call_out("remove_npc", 600, ob);	
}
	if (s!=31) laoren = 0;//������ʱ��һ��������



	//˾��ժ��
	//if ((s == 50) && !sikong) 
	if (s == 22&&(h%2)==1&& !sikong) 
	{
		if (!room = do_copy())
			room = do_copy();
		else {
			ob = new("/u/xu/xingjiao");
			if (ob->move(room)) {
				message("channel", HIR"���������:"HIY"��˵˾��ժ����Я�ر���"+HIG+path_where+HIY"һ����û��ϲ��Ѱ������ҿ��������һ����ǵı��"NOR"\n", users());
				CHANNEL_D->do_channel( this_object(), "sys", "˾��ժ�ǳ����ˡ�"+ZJURL("cmds:goto "+file_name(ob))+"�ɹ�ȥ"+NOR"��");
				sikong = 1;
				call_out("remove_npc", 300, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "˾��ժ������ʧ�ܡ�"NOR);
		}
	}
	if (s!=22) sikong = 0;//������ʱ��һ��������

	//��ʮ�ֵ�ʱ��ˢ���ڱ�
	if (s == 36&&(h%3)==0 && !wabao) {
		if (!room = do_copy())
			room = do_copy();
		else {
			//ob = new("/clone/npc/feizei");
			room->set("wabao",1);
			if (room) {
				message("channel", HIR"�������챦��:"HIW"�������һ��ը�ף�ֻ��һ�����������"+HIG+path_where+HIW"����׹ȥ����"NOR"\n", users());
				//CHANNEL_D->do_channel( this_object(), "sys", "���س����ˡ�"+ZJURL("cmds:goto "+room+"�ɹ�ȥ"+NOR"��");
		  CHANNEL_D->do_channel( this_object(), "sys", "���س����ˡ�"+ZJURL("cmds:goto "+room)+"�ɹ�ȥ"+NOR"��");
				wabao = 1;
				//call_out("remove_npc", 120, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "�ڱ�����ʧ�ܡ�"NOR);
		}
	}
	if (s!=36) wabao = 0;//������ʱ��һ��������
	
	
	//����
	//if (s == 10&&(h%2)==0 && !dati) {
	if (s==5&&h==18&& !dati) {	
			tiku=random(4);//�м������ѡһ
			hang=random(3500);//���������ǧ��ѡһ
			if(hang>3480)hang=3000;
			set("channel_id", "�Ʋ���");
	  //CHANNEL_D->do_channel( this_object(), "chat", "�ƾٴ���ʱ�䵽�ˡ����"+ZJURL("cmds:goto "+room)+"��ʼ����"+NOR"��");
	  	CHANNEL_D->do_channel( this_object(), "chat", HIY"Ǳ���罭�������ܼ�ư�����ƾٴ��ش���ʱ�䵽�ˡ�"+NOR"��");
		 set("channel_id", "�NPCϵͳ");
		 
		 	foreach (object player in users()) {
			if (!environment(player) || base_name(environment(player)) == "/d/jianyu" ||  player->query_temp("netdead")||  player->query("dati-guan")) continue;
     
       			if(!player->query_temp("kxcd/start_time"))//����ͳһ�Ŀ�ʼʱ����
       			player->set_temp("kxcd/start_time",time());
       			player->set_temp("kxcd/tiku",tiku);
       			player->set_temp("kxcd/hang",hang);		
        			tell_object(player,ZJFORCECMD("kaixindati"));
    			} 
			dati = 1;		
	}
	if (s!=05) dati = 0;//������ʱ��һ��������

	
	//���а���
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
			CHANNEL_D->do_channel(this_object(), "rumor",HIC"�����а��ɡ�"+ob->query("name")+HIC"����ͻ������,����ȥ�����羰����֮�����Ƹ�ʫ��"NOR);
			CHANNEL_D->do_channel( this_object(), "sys", ""+ob->query("name")+"�����ˡ�"+ZJURL("cmds:goto "+file_name(ob))+"�ɹ�ȥ"+NOR"��");
			yzbq = 1;
				call_out("remove_npc", 300, ob);
}
	if (s!=8) yzbq = 0;//������ʱ��һ��������


	//ԭ��Ʒˢ��ʱ��
	//if ((h == 18) && (s == 0) && !ok1) {
	//�޸�Ϊ����5����ʮ���ˢ��������Ʒ
	if ((h == 05) && (s == 55) && !ok1) {

		clear_special();
		ok1 = 1;
	}
//������ã���ֹ�ظ�����npc
	if (s!=50) ok = 0;
//��Ʒˢ�±��
	//if (!(h==18&&s==0)) ok1 = 0;
	if (!(h==05&&s==55)) ok1 = 0;

}

void remove_npc(object ob)
{
	if (ob) {
	if (ob->query("id")=="fei zei")
		ob->force_me("say ���ط����ûʲô��ˮ���̣����ǻؼҰɣ�\n");
	//if (ob->name()=="sikong zhaixing")
	if (ob->query("id")=="sikong zhaixing")
		ob->force_me("say ������Ȼϡ�ٵ����ǹ����������Ҵ��˻������˴��ˣ�\n");	
	if (ob->query("id")=="tianji laoren")
		ob->force_me("chat �����ǽ����粨��ƽ��������Ҫ֪������Σ������»طֽ⡣\n");
	if (ob->query("id")=="zu qianqiu")
		ob->force_me("chat ����ʥ�ͽԼ�į��Ω��������������\n");	
	destruct(ob);
	}	
}

void remove_xiaofeng(object ob)
{
	if (ob) {
		ob->force_me("chat ������Ȥ������Ӣ�۾�Ȼû˭�ܽӵ�����ĳ���У�\n");
		command("chat ������Ȥ������Ӣ�۾�Ȼû˭�ܽӵ�����ĳ���У�\n");

		destruct(ob);
	}
}
void remove_yanqing(object ob)
{
	if (ob) {
		ob->force_me("chat ����ԭ���ֲ������˵��������ˣ�ĳ��ȥҲ��\n");
		command("chat ����ԭ���ֲ������˵��������ˣ�ĳ��ȥҲ��\n");

		destruct(ob);
	}
}


void remove_laoshu(object ob)
{
	if (ob) {
		ob->force_me("chat �˼䲻���棬�����̻���ͥ�ˣ�\n");
		command("chat �˼䲻���棬�����̻���ͥ�ˣ�\n");

		destruct(ob);
	}
}


protected void heart_beat()
{	
	check_time();
}