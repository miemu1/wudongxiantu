// xiaohuayuan.c

#include <ansi.h>
#include <localtime.h>
inherit ROOM;

void create()
{
	set("short","��������");
	set("long", @LONG
������һ�������������ʮ���ʺϸ�����ֲ�����������
LONG
	);

	set("exits", ([ 
		//"west"  : __DIR__"liaotian",
		"down" : __DIR__"beidajie1",
		//"east" : __DIR__"liaotian",
	]));
	set("objects",([ 
		__DIR__"npc/jiuzhong" : 1,
	])); 
	
	set("no_fight", 1);
	set("zhong",1);	
	setup();
}
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""GRN"", ""HIC"", ""HIW"", ""HIR"", ""CYN"",""WHT"",""HIM""});
mapping shuzi=([
		"yumi zhong-b": 5,
		"xiaomai zhong-b": 5,
		"putao zhong-b": 2,
		"nuomi zhong-b": 3,
		"lvdou zhong-b": 4,
		"lihua zhong-b": 4,
		"gaoliang zhong-b": 2,
		"dami zhong-b": 3,							
	]);
	

mapping wenzi=([
		"yumi zhong-b": ([1:"����ũ��ָ������������ֽ��н��ݴ�ѿ�����������ӳ����˰�ɫ��Сѿ��",
 											2 :"��ѡ����һ�����ɷ�����ˮ�ԽϺõ��������£�Ȼ������ؽ���������",
 											3 :"���ڵ����ڳ�һ����С�ӣ�Ȼ��С�ĵذ������ֵ���������ˮ����",
 		 									4 :"�����ڵض����׽��н�ˮ��ʩ�ʡ����ݡ��ۿ�������һ��һ���øߴ�������",
 		 									5 :"�����׿�������ڼ䣬���ܹ�ȱˮ���㰴����ũ��ָ��Ϊ���װ�ʱ��ˮ��",
 		 									6 :"��Ƶ����װ��ӿ�����������߸����˵������������ס�",//�ɹ�
 		 									7 :"��ΪǷȱ�����׳�����õ������ɱ񣬿�����𣲻�ף���������Ľ���",//ʧ��	
]),				
			
		"xiaomai zhong-b": ([1:"����ũ��ָ�������С���ֽ��н��ݷ�ֹ�溦��",
 											2 :"������ؽ������ƽ����Ȼ�����ǳ���������������������������",
 											3 :"�����ĵصȴ��ţ���������������������������ؿ���ȥ�ʵ�������ɫ��",
 		 									4 :"�㰴����ũ��ָ������ؽ��н�ˮ��ʩ�ʡ����ݡ����档",
 		 									5 :"���Ӿ����˳��룬�������࣬��â���룬�ٹ���ʱ�䣬���Ӿ�Ҫ�����ˡ�",
 		 									6 :"������������ո����룬Ȼ����������������ﳡ���ջ����ӣ�",//�ɹ�
 		 									7 :"����δ�ؾ��лر���С������õ������ɱ񣬿������������ǿ��",//ʧ��	
]),				
		"putao zhong-b":([1:"����ũ��ָ������ѡ����һ�����ʷ��ֵĵط������ڿӣ�׼��Ǥ�������١�",
 											2 :"�������ѿ���ʩ�ʽ�ˮ��Ȼ���������С������ز��ڿ��ﲢ��������",
 											3 :"������Χ����ʹ��˳��ܣ��ڴ��������������������ӡ�",
 		 									4 :"������������ѿ�����ܣ��ܿ�Ͳ������������ӡ�",
 		 									5 :"��������н�ˮ��ʩ�ʡ�׽��ȳ��湤����",
 		 									6 :"�����Ϲ����˳ɴ������ѡ���ɫ�����Ѿ�Ө��͸�����˴������Ρ�",//�ɹ�
 		 									7 :"������Ȼ֦��Ҷï����������ȴ��ĺ�С��������ֲҲ��һ�Ŵ�ѧ�ʰ���",//ʧ��	
]),				
		"nuomi zhong-b": ([1:"����ũ��ָ�����㽫����������з�ɢ��ѹ�飬Ȼ����о�������ƽ������",
 											2 :"�㽫���ݺ�����ӷ��벼���У����������������д�ѿ��",
 											3 :"�㽫��ѿ������Ӿ��Ȳ������紲�ϣ�Ȼ����������ˮ���ȴ����硣",
 		 									4 :"���类��С�ĵ��Ժ���ļ���ͼ����뵾�������򣬲����ܡ�",
 		 									5 :"����������ʩ�ʡ����棬������������룬������׳�ɳ���",
 		 									6 :"��Ӳӵĵ���������������ո�ﳡ��æ�Ĳ����ֺ���",//�ɹ�
 		 									7 :"��ΪǷȱ�����³��ֲ������ȡ���������Ŭ���Ϳ����ˣ�����Ҫһ���ķ�����",//ʧ��	
]),				
		"lvdou zhong-b": ([1:"�㽫�̶���̯��ϯ����ɹ��Ȼ��ʹ��Ƥ����������������ˮ������",
 											2 :"�����ؽ�������ƽ����Ȼ����������в��ѽ��ݺ���̶����������С�",
 											3 :"�������̶�������������������һ�����������������������ǹ��������أ�",
 		 									4 :"�����ڵضԶ�����н�ˮ��ʩ�ʡ����ݡ��ۿ�����һ��һ����ͦ��������",
 		 									5 :"�ڰ�����ũ��ָ�������ʱ��ˮ��ʩ�ʡ����ݡ����������ϣ���и����ճɡ�",
 		 									6 :"��ɫ�Ķ��Կ���������������ڣ����˳ϲ����۰���",//�ɹ�
 		 									7 :"��ΪǷȱ���̶�������õ����Ըɱ񣬿�������Ҫ����ũ���ѧϰ���У�",//ʧ��	
]),				
		"lihua zhong-b":([1:"��ѡ��һ��������ˮ�������õĵط��������ؽ�������������ʩ��׷ʡ�",
 											2 :"�㽫�����������Ȼ��ֲ�ѹ��ϸ��������������С�������ٽ�ˮ��",
 											3 :"�����罥��������С���磬�㳣�������н�ˮ��ʩ�ʡ����档",
 		 									4 :"�������о�������ֲ�ĵã�С�����ø��߸����ˡ�",
 		 									5 :"�㰴����ũ��ָ��Ϊ�����޼�֦Ѿ����ȥ����֦Ѿ��",
 		 									6 :"�������ڿ����ˣ�һ����׵ķ�������æ�����ؽ��в�ժ��",//�ɹ�
 		 									7 :"������Ȼ�����ˣ���ϡϡ���裬�������ӡ������˷���һ�ź���!",//ʧ��	
]),				
		"gaoliang zhong-b": ([1:"����ũ��ָ������Ը����ֽ��н��ݴ�ѿ�����������ӳ����˰�ɫ��Сѿ��",
 											2 :"��ѡ����һ�����ɷ�����ˮ�ԽϺõ��������£�Ȼ������ؽ���������",
 											3 :"���ڵ����ڳ�һ����С�ӣ�Ȼ��С�ĵذѸ����ֵ���������ˮ����",
 		 									4 :"�����ڵضԸ����ؽ��н�ˮ��ʩ�ʡ����ݡ��ۿ�������һ��һ���øߴ�������",
 		 									5 :"�ڸ�����������ڼ䣬���ܹ�ȱˮ���㰴����ũ��ָ��Ϊ������ʱ��ˮ��",
 		 									6 :"���ĸ������ӿ�����������߸����˵��������ո������",//�ɹ�
 		 									7 :"��ΪǷȱ������������õ������ɱ񣬿�����𣲻�ף���������Ľ���",//ʧ��	
]),				
		"dami zhong-b": ([1:"����ũ��ָ�����㽫����������з�ɢ��ѹ�飬Ȼ����о�������ƽ������",
 											2 :"�㽫���ݺ�����ӷ��벼���У����������������д�ѿ��",
 											3 :"�㽫��ѿ������Ӿ��Ȳ������紲�ϣ�Ȼ����������ˮ���ȴ����硣",
 		 									4 :"���类��С�ĵ��Ժ���ļ���ͼ����뵾�������򣬲����ܡ�",
 		 									5 :"����������ʩ�ʡ����棬������������룬������׳�ɳ���",
 		 									6 :"��Ӳӵĵ���������������ո�ﳡ��æ�Ĳ����ֺ���",//�ɹ�
 		 									7 :"��ΪǷȱ�����³��ֲ������ȡ���������Ŭ���Ϳ����ˣ�����Ҫһ���ķ�����",//ʧ��	
]),										
	]);

string* use_phrase = ({"��", "��", });
string* use_name = ({"ˮư�е�", "ư�е�", "ˮư���", "ư���", "", });
string* use_what = ({"ˮ", "��ˮ", });
string* use_arj = ({"�������", "�������ɵ�", "С�������", "����", "���ɵ�", "", "��������", "����", });
string* use_action = ({"��", "��", });
string* use_where = ({"ǰ", "��", "��", "��", "��", "��", });
string* action_arj = ({"һ��", "��", "��", "һ��", });


string getwq(object me, string id);
int getsld(object me, string id);

void init()
{
	//if (interactive(this_player()) && environment() == this_player())
	//{
		add_action("do_zhuwuqi","lzdy");
		add_action("do_tzlz","tzlz");
		add_action("do_zhong", "zhonght");//����
		add_action("do_jiao", "jiaoht");//����
	//}
}

int do_zhong()
{
	object ob1, me;

	me = this_player();
		
		 if (me->is_busy()) 
		 	{
		tell_object(me,"����æ�������Ұɡ�\n");
			return 1;
			}
	   // if (environment(me) != find_object("/d/xiangyang/xibian")) 
		//return notify_fail("������Ҩ�������õ�ˮ��\n");
		
			if (!ob1 = present("tao zhong-b", this_player()))
			{
			tell_object(me,"�����Һˣ���������ҡ�\n");
			return 1;
			}
			if (! environment(me)->query("zhong")){
			tell_object(me,"ֻ����������������ҡ�\n");
			return 1;
			}
	
	    tell_object(me,"���Ĵ�������һ�£�ѡ��һ���õء����������Ӱ��Һ����ڵ��\n");
	    me->set("monkey/zhong",time());
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(3)));
	    ob1->add_amount(-1);
	    return 1;
}

int do_jiao()
{
	mixed *local;
	int totaltime, water_time, curent_time, seeded, hour, day, month;
	object room, ob, me, obnew, pound;
	string msg;

	ob = this_object();
	me = this_player();
	room = find_object("/d/city/liangtian");
	local = localtime(time());

	hour = 100;
	day = 10000;
	month = 1000000;
	curent_time = (local[LT_MON] + 1) * month + local[LT_MDAY] * day + local[LT_HOUR] * hour + local[LT_MIN];
// ����11��23������3��21���õ���curent_time����11231521

// û��ˮư��ư��û��ˮ��æʱ���ж�
	//if (! objectp(ob = present("shui piao", me)))
	  //  return notify_fail("��û��ˮư����ô��ˮ��\n");
	//if (! arg || (arg != "shui" && arg != "water"))
	  //  return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy()) 
	    return notify_fail("����æ������ˮ�ɣ�\n");
	//if (! ob->query("filled")) 
	  //  return notify_fail("ư��ûˮ��\n");

// ��������ڻ�����ˮ�ĺ��
	if (environment(me) != room)
	{
	    message_vision("$N������İ�ˮ���ڵ��ϡ�\n", me);
	    //ob->delete("filled");
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(5)));
	    return 1;
	}

// û�в������ӵĺ�������ֵı�Ƿ����������ˡ�
	if (! me->query("monkey/zhong"))
	{
	    message_vision("$NҨ��һưˮ���Ĵ�����ûʲô�ɽ��ģ���˳�ְ�ˮ��������ũ�Ľ��ϡ�\n", me);   
	    //ob->delete("filled");
	    me->start_busy(1 + random(2));
	    me->receive_damage("jing", (20 + random(5)));
	    tell_object(me, "��ũ��ŭ���ֶ���ˮư��˳�ָ���һ���ƣ�˵����û�����ң��㽽ʲôˮ����\n");
	    return 1;
	}

	water_time = me->query("monkey/seeded");
// ����water_timeΪ�ϴθɻ��ʱ�䣬�ɻ�����ǲ��ֺͽ�ˮ��
// ����waterΪ�ܽ�ˮ�Ĵ��������ڿ����ܵ���ֲʱ��ͽ׶�������
// ÿ�ν�ˮ��Ҫ���5-10���ӣ�waterΪ30�Σ����ܵ���ֲʱ��Ϊ��ʵ�е�3-5Сʱ��
	if (! me->query("monkey/water"))
	{
// ��һ�ν�����ֻ���Ե����г���������Ϊ�Ӳ��ֵ���������ҿ�����Ҫ����Щ����������Ӧ��ʱ�䡣
	    message_vision("$NС������ؿ��˿��Һ����µ�λ�á�\n", me);   
//	    ob->delete("filled");
//	    me->start_busy(1+random(2));
//	    me->receive_damage("jing", (20 + random(5)));
//	    me->set("monkey/water", 1);
//	    me->set("monkey/seeded", curent_time);
//	    return 1;
	}

	//if (me->query("monkey/water") && water_time + 5 > curent_time) // ����һ�κ�5���Ӳſ����ٽ���
	if (me->query("monkey/water") && water_time + 1 > curent_time) // ����һ�κ�1���Ӳſ����ٽ���

	{
	    me->start_busy(2 + random(3));
	    return notify_fail("���ǲŸչ�ȹ�ô����ôһֱ��������������ģ�\n");
	}
	//if (me->query("monkey/water") && water_time + 10 < curent_time)// 10�����ڲ���ˮ��ֲʧ�ܡ�
	if (me->query("monkey/water") && water_time + 15 < curent_time)// 15�����ڲ���ˮ��ֲʧ�ܡ�

	{
	    tell_object(me, "��⣬�ܾ�û��������ˮ����ֲʧ�ܡ�:(\n");
	    me->delete("monkey/water");
	    me->delete("monkey/seeded");
	    me->add("monkey/fail", 1);
	    return 1;
	}

	message_vision("$N" + use_phrase[random(sizeof(use_phrase))] + use_name[random(sizeof(use_name))] +
			      use_what[random(sizeof(use_what))] + use_arj[random(sizeof(use_arj))] +
			      use_action[random(sizeof(use_action))] + use_where[random(sizeof(use_where))] +
			      action_arj[random(sizeof(action_arj))] + "��\n", me);
	//ob->delete("filled");
	me->add("monkey/water", 1);
	totaltime = me->query("monkey/water");
	me->start_busy(3 + random(3));
	me->receive_damage("jing", (60 + random(60)));
	me->set("monkey/seeded", curent_time);

// ��ʮ�ν�����ÿ�ζ��Ի��ĸ����ǲ�һ���ġ�
	switch (me->query("monkey/water"))
	{
		case 1:
			msg = "�տ�ʼ��ˮ����о�����Щ���ʸУ�Ҳ�������ۡ�";
			break;
		case 2:
			msg = "��ĬĬ�����ţ�ϣ�������ܿ�Щ��ѿ��";
			break;
		case 3:
			me->receive_damage("qi", 100);
			msg = "���ӻ�û�з�ѿ����ȵ���Щ�ļ��ˡ�";
			break;
		case 4:
			me->receive_damage("qi", 10);
			msg = "�ۣ��������ڷ�ѿ�ˣ�����˵�����������";
			break;
		case 5:
		case 6:
			msg = "������ѿ��һ��㳤�ߣ������������ϲ�á�";
			break;
		case 7:
		case 8:
		case 9:
			me->receive_damage("qi", 50);
			msg = "��������һ��㳤�ߣ������Ѿ���" + chinese_number(totaltime/2) + "�߸��ˡ�";
			break;
		case 11:
		case 12:
			me->receive_damage("qi", 30);
			msg = "����������Щ����Ҷ��ɫ������������������";
			break;
		case 13:
			msg = "����Ҷ�ӱ�����ɫ���й���";
			break;
		case 14:
			me->receive_damage("qi", 20);
			msg = "������Ҷ�Ӹ���ïʢ�ˡ�";
			break;
		case 15:
			msg = "��ͻȻ���������Ѿ������ˡ�";
			break;
		case 17:
			me->receive_damage("qi", 30);
			msg = "ѽ�������ϵĻ��ʷۺ�ɫ���ǳ��ÿ���";
			break;
		case 19:
			me->receive_damage("qi", 20);
			msg = "ֻ���������ۺ�ɫ�Ļ��ٺ������ţ�����������";
			break;
		case 20:
		case 21:
			msg = "�������ٽ�����ȥ��һ��һ����С���ӹ���֦ͷ��";
			break;
		case 23:
		case 28:
			me->receive_damage("qi", 30);
			msg = "ϸ��������������һ��һ����";
			break;
		case 24:
		case 25:
			msg = "���Ӱ�֦Ѿ��ѹ���ˡ�";
			break;
		case 27:
			msg = "�ʺ�����ӿ���ȥ�ǳ����������沼������ë��\"";
			break;
		case 29:
			me->receive_damage("qi", 50);
			msg = "�������Ѿ��ܳ����ˣ��ڹ���ʱ��Ϳ����ջ��ˡ�";
			break;
		case 30:
			me->receive_damage("qi", 60);
			msg = "����ȥ�����Ѿ���ֲ�ɹ����Ͽ�������������ưɡ�";
			break;
		default:
			msg = "Ϊ���ܰ�������ֲ�ɹ����Ͳ����½�ˮ�������ࡣ";
			break;
	}

	msg += "\n";
	tell_object(me, (order[random(11)])+ msg + NOR + "\n");
	if (totaltime > 30)// ���������������²�����֣��Ӵ�CODE�Ƿ�����δȻ�����������ѭ����
	{
	    tell_object(me, "��⣬������Ĳ���ʧ��������ֲʧ�ܡ�:(\n");
	    me->delete("monkey/water");
	    me->delete("monkey/seeded");
	    me->add("monkey/fail", 1);
	    return 1;
	}
	if (totaltime == 30) // ����30�κ���ֲ�ɹ���
	{
	    me->delete("monkey/water");
	    me->delete("monkey/seeded");
	    me->delete("monkey/zhong");
	    
	    
	    if(me->query("kar")*2>random(100))
	    {	
	     	obnew = new("/clone/wine/yuanliao/monkey5");
	    	obnew->set_amount(1);
	    	obnew->move(me);
	     	tell_object(me,HIG"���ջ���һö"HIR"����"HIG"��\n"NOR);
	     
	     	obnew = new("/clone/wine/yuanliao/monkey");
	    	obnew->set_amount(4);
	    	obnew->move(me);
	    	tell_object(me,HIG"���ջ�����ö"RED"����"HIG"��\n"NOR);	     
	  	}
	  	else
	  	{
	  	 	obnew = new("/clone/wine/yuanliao/monkey");
	    	obnew->set_amount(5);
	    	obnew->move(me);
	    	tell_object(me,HIG"���ջ�����ö"RED"����"HIG"��\n"NOR);	    	
	  	}
	  		
	    //me->add("monkey/qxhtget", 1);
	    //me->set("monkey/qxht/have", 1);
	}
	return 1;
}

int do_tzlz(){
	object me = this_player();
	
	tell_object(me,HIR"����ֹͣ��ֲ��\n"NOR);
	me->delete_temp("dzz");
//	me->delete_temp("zhong");
	return 1;
}

int do_zhuwuqi(string arg){
	object me = this_player();
	string pops;
	string wq,xh,cl;
	
	if (! environment(me)->query("zhong")){
		tell_object(me,"ֻ����������ܽ�����ֲ��\n");
		return ;
	}
	
	if(sscanf(arg,"%s %s %s", wq, xh, cl) == 3){
		if(wq == "dao"){
			set_temp("wuqi","1");
		}else{
			tell_object(me,"��ֲ���Ͳ�������\n");
			return 1;
		}
		
		if(xh == "1"){
			set_temp("xh",1);
		}else if(xh == "2"){
			set_temp("xh",2);
		}else{
			tell_object(me,"��ֲ��ʽ���Ͳ�������\n");
			delete_temp("wuqi");
			return 1;			
		}
		
		if(cl == "1"){
			set_temp("cl",1);
		}else if(cl == "2"){
			set_temp("cl",2);
		}else if(cl == "3"){
			set_temp("cl",3);
		}else{
			tell_object(me,"����ʽ��������\n");
			delete_temp("wuqi");
			delete_temp("xh");
			return 1;			
		}
		
		if(me->query_temp("dzz")){
			tell_object(me,"��������ֲ�У�������������ֹͣ��ֲ��\n");
		}else{
			me->set_temp("dzz",1);
			call_out("zhuzao1", 2, me);			
		}

		return 1;	
	}
	
	if(sscanf(arg, "%s %s", wq, xh) == 2){
		pops = ZJOBLONG"��ѡ����ֲ�Ĵ���ʽ��\n";
		pops += ZJOBACTS2+ZJMENUF(1,1,10,30)+
			HIR"������������õ�һ�������������Ƽ���:lzdy "+wq+" "+xh + " 1"ZJSEP
			HIC"���������԰������Ϊ��������ӣ�:lzdy "+wq+" "+xh + " 2"ZJSEP
			HIG"���ڰ��������ֲ��������԰���衣��:lzdy "+wq+" "+xh + " 3\n";
		tell_object(me,pops);
		return 1;	
	}
	
	if(arg){
		
		pops = ZJOBLONG"��ѡ�����ӵ�ʹ�÷�ʽ"ZJBR"�������������Զ�ֹͣ����\n";
		pops += ZJOBACTS2+ZJMENUF(1,1,10,30)+
			HIR"������ֲ�ͼ�����:lzdy "+arg+" 1"ZJSEP
			HIG"������ֲ�߼�����:lzdy "+arg+" 2\n";
		tell_object(me,pops);
		return 1;		
		
	}

}

void zhuzao1(object me){
	object ob;
	
	if(!interactive(me)){
		tell_object(me,"�������ߣ�������ֲֹͣ��\n");
		do_tzlz();
		return ;		
	}
	
	if (! environment(me)->query("zhong")){
		tell_object(me,"ֻ�������������ֲ��\n");
		do_tzlz();
		return ;
	}		
	
	if((int)me->query("jing")<100
	||(int)me->query("qi")<100
	||(int)me->query("neili")<150)    
	{
		tell_object(me, "��ľ��������ڻ�������100���޷���ֲ��\n");
		do_tzlz();
		return;
	}
	
	if(query_temp("xh") == 1){
		if (!(ob = present("gaoliang zhong-b", this_player())) &&
		!(ob = present("putao zhong-b", this_player())) &&
		!(ob = present("dami zhong-b", this_player())) &&
		!(ob = present("nuomi zhong-b", this_player())) &&
		!(ob = present("lihua zhong-b", this_player())) &&
		!(ob = present("lvdou zhong-b", this_player())) &&
		!(ob = present("xiaomai zhong-b", this_player())) &&	
		!(ob = present("yumi zhong-b", this_player())))
		{
			tell_object(me, "ֻ�и��������ѡ����ס�Ŵ�ס��滨���̶���С�����׵����������ֲ��\n");
			do_tzlz();
			return;
		}
	}else{
		
		if (!(ob = present("yumi zhong-b", this_player())) &&
		!(ob = present("xiaomai zhong-b", this_player())) &&
		!(ob = present("lvdou zhong-b", this_player())) &&
		!(ob = present("lihua zhong-b", this_player())) &&
		!(ob = present("nuomi zhong-b", this_player())) &&
		!(ob = present("dami zhong-b", this_player())) &&
		!(ob = present("putao zhong-b", this_player())) &&	
		!(ob = present("gaoliang zhong-b", this_player())))

		{
			tell_object(me, "ֻ�и��������ѡ����ס�Ŵ�ס��滨���̶���С�����׵����������ֲ��\n");
			do_tzlz();
			return;
		}		
	}
	me->set_temp("zhong/name",ob->name());
	me->set_temp("zhong/id",ob->query("id"));
	me->set_temp("zhong/level",ob->query("level"));
	me->set_temp("zhong/end",ob->query("end"));
	me->set_temp("zhong/shuzi",shuzi[me->query_temp("zhong/id")]);

	ob->add_amount(-1);

	tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][1]+"\n"NOR);
	call_out("zhuzao2", me->query_temp("zhong/shuzi"), me);
}

void zhuzao2(object me){

	if (! environment(me)->query("zhong")){
		tell_object(me,"ֻ�������������ֲ��\n");
		do_tzlz();
		return ;
	}		
	tell_object(me,HIW""+wenzi[me->query_temp("zhong/id")][2]+"\n"NOR);
	call_out("zhuzao3", me->query_temp("zhong/shuzi"), me);
}

void zhuzao3(object me){

	if (! environment(me)->query("zhong")){
		tell_object(me,"ֻ�������������ֲ��\n");
		do_tzlz();
		return ;
	}		
	tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][3]+"\n"NOR);
	call_out("zhuzao4", 2, me);
}

void zhuzao4(object me){

	if (! environment(me)->query("zhong")){
		tell_object(me,"ֻ�������������ֲ��\n");
		do_tzlz();
		return ;
	}		
	tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][4]+"\n"NOR);
	call_out("zhuzao5", me->query_temp("zhong/shuzi"), me);
}

void zhuzao5(object me){
	
	if (! environment(me)->query("zhong")){
		tell_object(me,"ֻ�������������ֲ��\n");
		do_tzlz();
		return ;
	}		
	tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][5]+"\n"NOR);
	call_out("zhuzao6", me->query_temp("zhong/shuzi"), me);//ע���
}

void zhuzao6(object me){
	object ob1;
	string wqstr = query_temp("wuqi");
	string wqdj;
	string obid;
	int n,nn,skill;
	int bijiao,jilv,ok;
	skill=me->query_skill("tianyuan-muge",1);
	
	
	if (! environment(me)->query("zhong")){
		tell_object(me,"ֻ�������������ֲ��\n");
		do_tzlz();
		return ;
	}		
	
	obid = me->query_temp("zhong/id");
	

	 
	//�ɹ��ļ��ʺ���԰����ȼ���ء�
//�ɹ���
	ok=0;	
	bijiao=skill-me->query_temp("zhong/level");
			
	if(bijiao<0)jilv=20;//
	if(bijiao>=100)jilv=100;//	����100��100%
	else	
	jilv=25+bijiao;//����50��75%,��԰����մﵽ��Ӧ�ȼ��ɹ�����25%,
	
	if(jilv>=random(100))
	ok=1;		
	
	if(ok)	
	{
	ob1=new(me->query_temp("zhong/end"));	
	}

		if(ob1)
		{	
		ob1->move(me);      
	
		tell_object(me,(order[random(11)])+""+wenzi[me->query_temp("zhong/id")][6]+"\n"NOR);
		
		call_out("zhuzao8", 2, me,obid,ob1);		
		}
		else
		{
	
		tell_object(me,HIR""+wenzi[me->query_temp("zhong/id")][7]+"\n"NOR);
		
		call_out("zhuzao8", 2, me,obid,0);
		}	
}

void zhuzao8(object me, string obid, object ob1){
	int exp,pot,sld;
		
	if (! environment(me)->query("zhong")){
		tell_object(me,"ֻ�������������ֲ��\n");
		do_tzlz();
		return ;
	}
	
	exp = 50 + random(20);
	pot = 25 + random(5);
	
	me->add("combat_exp",exp);
	me->add("potential",pot);	
	
	sld = getsld(me,obid);
	sld = sld/2+random(sld);
	
		
	if(ob1){
			tell_object(me,"��õ���һ"+ob1->query("unit")+ob1->name()+"��\n������"+exp+"����Ϊ��"+pot+"��Ǳ�ܡ�"+sld+"����԰���������ȡ�\n");
			me->improve_skill("tianyuan-muge",sld,0); 
		if(query_temp("cl") == 1){
			me->force_me("sellob "+file_name(ob1));
		}if(query_temp("cl") == 2){ 
			tell_object(me,"�㿶���ؽ�"+ob1->name()+"����ũ��������ũ����ָ���£������԰����������+"+sld/2+"�㡣\n");
			destruct(ob1);
			me->improve_skill("tianyuan-muge",sld,0);
		}
	}else{
			me->improve_skill("tianyuan-muge",sld/2,0); 
			tell_object(me,"��Ȼ��ֲʧ�ܣ������ǵõ���"+exp+"����Ϊ��"+pot+"��Ǳ��,"+sld/2+"����԰���������ȡ�\n");
	}
	
	//if(	me->query_temp("dzz")&&	me->querye_temp("zhong"))
	if(	me->query_temp("dzz"))	
	call_out("zhuzao1", 1, me);
}

int getsld(object me){
	int bl;
	string id;
	id=me->query_temp("zhong/id");
	bl = (100 + me->query_int()) * 10;
	if(id == "yumi zhong-b"){
		return bl + 3200;
	}else if(id == "xiaomai zhong-b"){
		return bl + 1600;
	}else if(id == "lvdou zhong-b"){
		return bl + 800;
	}else if(id == "lihua zhong-b"){
		return bl + 400;
	}else if(id == "nuomi zhong-b"){
		return bl + 200;	
	}else if(id == "dami zhong-b"){
		return bl + 100;
	}else if(id == "putao zhong-b"){
		return bl + 50;
	}else if(id == "gaoliang zhong-b"){
		return bl;
	}else{
		return bl;
	}
}


int valid_leave(object me, string dir)
{

	if (playerp(me) && dir == "west")
	{
		if (me->query_temp("dzz"))
			return notify_fail(HIR"������ô��󣬻�û�ջ��˾������񲻿�ϧ��\n"NOR);
	}

	return ::valid_leave(me, dir);
}