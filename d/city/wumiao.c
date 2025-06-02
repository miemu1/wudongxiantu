// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "����");
	set("long", @LONG
�����������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ�
�Ͼ���������ݡ��Ա��ƺ���һ�����š�
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_learn", "1");
	set("no_study", "1");
	set("no_learn", "1");
	set("no_dazuo", "1");
	set("no_sleep_room", "1");

	set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
		"/adm/npc/qiandao": 1,
	]));

	set("action_list", ([
		"ÿ��ǩ��" : "day_sign",	
		"�ƹ����" : "tuiguang",		
		HIY"����ָ��"NOR : "qqq",		
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
		"north"   : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
	create_door("northwest", "����", "southeast", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_sign","day_sign");
	add_action((: this_player()->force_me("tg") :),"tuiguang");//++++
	add_action("mrrw","qqq");	
}

int valid_leave(object me, string dir)
{		
	if (dir == "northwest" && ! userp(me) && ! me->is_chatter())
		return 0;
	return ::valid_leave(me, dir);
}


int do_sign(string arg)
{
	object ob,me,xb;
	string hol,file;
	int vlv,last,times,pot,yuanbao_2,gx,xian;
	mapping gifts;

	me = this_player();

    gx = random(5);
	xian = gx;
	last = me->query("last_day_sign");
	times = me->query("day_sign_times");
	if(time()/86400 == last/86400)
		return notify_fail("�㱾���Ѿ�ǩ���ۼ�"+times+"�Ρ�\n������Ѿ�ǩ�����ˡ�\n");
	if(time()/86400 - last/86400 > 1)
	{
		tell_object(me,"����������δǩ����ǩ���ۼ�����ա�\n");
		times = 0;
	}

	me->set("last_day_sign",time());
	times += 1;
	me->set("day_sign_times",times);
	vlv = me->query("zjvip/level");
	pot = times*50+(10000+random(500)*vlv);
	me->add("potential",pot);
	me->add("combat_exp",pot);
	me->set("mgcs",1);
	me->set("wdtcs",1);
	me->add("zjvip/all_pay",xian);
	tell_object(me,"�㱾���Ѿ�ǩ���ۼ�"+times+"�Ρ�\n����"+pot+"��Ϊ��Ǳ�ܣ�����¥����+1��ǩ������ +1���ۼ�ǩ��"+times+"��, һ���Թ��ʸ�\n");
	log_ufile(me,"sign","������"+times+"��ǩ�����"+pot*2+"��Ϊ��"+pot+"Ǳ�ܡ�\n");
	if(times==7)
	{
	    me->add("jifeng",100);
		tell_object(me,"��ϲ��ǩ���ۼ�"+times+"�Σ������100��ȯ��\n");
	}	
	if(times==15)
	{
	    me->add("jifeng",200);
		tell_object(me,"��ϲ��ǩ���ۼ�"+times+"�Σ������200��ȯ��\n");
	}	
	if(times==30)
	{
	    me->add("jifeng",300);
		tell_object(me,"��ϲ��ǩ���ۼ�"+times+"�Σ������300��ȯ��\n");
		me->set("day_sign_times",0);
		times = 0;
	}														
	if(times>=0)
	{
		ob = new("/clone/vip/vip2/dan_chongmai1");
	//	xb = new("/clone/shizhe/ling_tiaozhan");
		tell_object(me,"���� "+ob->short()+"��\n");
		//tell_object(me,"���� "+xb->short()+"��\n");
		ob->move(me);
	}
	if (me->query("ybvip/times")>0)
	{
		me->add("yuanbao",720);
		tell_object(me,"��Ϊ��ʯ�ܿ���ԭ���������720��ʯ��\n");
	}
	
	GIFT_D->check_gift(me);
	if(hol = "/adm/daemons/payd"->is_hol())
	{
		tell_object(me,HIG"������"HIY+hol+HIG"��ף���������"NOR"��\n");
	}
	else if(localtime(time())[6]==0 || localtime(time())[6]==6)
	{
		tell_object(me,HIG"������"HIY"��ĩ"HIG"��ף����ĩ��죡"NOR"��\n");
	}
	return 1;
}


int mrrw(string arg)
{
	object me=this_player();
	string type;
	string msg="", line="";
if (!arg) {
		msg = ZJOBLONG+
		      "Ŀǰ��Ϸ�е��ճ���������[������]��\n";
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "���ѵ��["+me->query("fuben/wuguan/mun")+"/2]:qqq wuguan";
		msg += ZJSEP"�������["+me->query("fuben/jinbing/mun")+"/2]:qqq jinbing";	
		msg += ZJSEP"������Ԫ["+me->query("fuben/poyuan/mun")+"/2]:qqq poyuan";		
		msg += ZJSEP"ʮ������["+me->query("fuben/huangling/mun")+"/2]:qqq huangling";		
		msg += ZJSEP"����[��]["+me->query("fuben/dangkou/mun")+"/2]:qqq dangkou";		
		
	}
	else if(arg=="wuguan"){
	msg = ZJOBLONG+"�������[���ѵ��]��"ZJBR
	                  "��������������������������������"ZJBR
                      "����ר������"ZJBR
                      "���뽭�������������ѣ����������ѧ�ճ�ʼ�ĺõط�������֮·�����ѧ�տ�ʼ��\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "����ǰ��:qqq wuguan2";	
	}
	else if(arg=="wuguan2"){ 
	me->move("d/city/wuguan/qianting");	
	}
	else if(arg=="jinbing"){
	msg = ZJOBLONG+"������Զ��[�������]��"ZJBR
	                  "��������������������������������"ZJBR
                      "���һֱ������ԭ���Ĳ�������������̽������ڴ�̽���飬�����̽�ɻ�÷������\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "����ǰ��:qqq jinbing2";	
	}
	else if(arg=="jinbing2"){ 
	me->move("d/guanwai/ningyuan");	
	}	
	else if(arg=="poyuan"){
	msg = ZJOBLONG+"�����Ǳ��ݵ�[������Ԫ]��"ZJBR
	                  "��������������������������������"ZJBR
                      "Ԫ�������������⻢������һ�������ű����ƣ�Ԫ����ֱ����ԭ���أ����޿ɵ�������Ӣ�ۺ��ܵ��þ��Լ�һ��������ɱԪ����\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "����ǰ��:qqq poyuan2";	
	}
	else if(arg=="dangkou"){
	msg = ZJOBLONG+"��������[��ƽ����]��"ZJBR
	                  "��������������������������������"ZJBR
                      "�����ں�����ɱ���ӣ��������ʿ�������������������������������\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "����ǰ��:qqq dangkou11";	
	}
	else if(arg=="poyuan2"){ 
	me->move("d/xiangyang/caodi3");	
	}	
	else if(arg=="dangkou11"){ 
	me->move("d/hangzhou/ningyuan");	
	}
	else if(arg=="huangling"){ 
	me->move("d/beijing/huangling");	
	}			
	write(msg + "\n");			
	return 1;
}



