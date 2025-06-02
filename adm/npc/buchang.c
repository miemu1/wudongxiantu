#include <ansi.h>

inherit NPC;

string ask_lilian();
string ask_jieshu();
string ask_baotu();
string ask_pay();
int ask_job();
string ask_yao();
int ask_gift1();
int ask_jiuyang();
int ask_gift();
int ask_xflb();
int ask_chongqi();
int ask_tap();
int ask_guanji();
int ask_meizhou1();
int ask_yuanma();
int ask_buchang();
int ask_xiaobai();
int ask_zhenai();

void create()
{
	set_name(HIW"��������һ���"NOR, ( { "bai" }));
	set("nickname", HBCYN"ʹ��"NOR);
	set("long", "һλ�ڷ����������\n");
	set("gender", "Ů��");
	set("age", 30);
	set("per", 24);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("qi",5000);
	set("jingli",6000);
	set("max_qi", 8000);
	set("max_jing", 5000);
	set("eff_jingli", 6000);
	set("jiali", 190);
	set("combat_exp", 9000000);
	set("shen", 25000);


	set("inquiry", ([
	//"�ϼ����" : (: ask_tap :),
	
//		"�·�С���" : (: ask_guanji :),
	///	"Դ�����" : (: ask_yuanma :),
	"��������" : (: ask_jiuyang :),
	//	"ÿ�����" : (: ask_meizhou1 :),
//		"�䶯��;����С���" : (: ask_buchang :),
		"������װ" : (: ask_xiaobai :),
	//	"�氮" : (: ask_zhenai:),
	]));
	setup();
}





int ask_jiuyang()
{
	object me = this_player();
	object gift;
	int num,money,gongxian;
	string assd;
	assd = me->query("name");
	gongxian = me->query("gongxian");
	//CHANNEL_D->do_channel( this_object(), "chat", "Ⱥ�ų����ˡ�"+ZJURL("tel:1131210568")"��ȥ"+NOR"��");
	//CHANNEL_D->do_channel( this_object(), "chat", "�ٶȳ����ˡ�"+ZJURL("http://m.hao123.comp")"��ȥ"+NOR"��");
	if (me->query("zjvip/jiuyangjiemi"))
	{
		tell_object(me,"���ɣ���ʦ�Ź��ײ���\n");
		return 1;
	}
   if(gongxian<20000)
   {
		tell_object(me,"���ɣ���ʦ�Ź��ײ�����\n");
		return 1;
   }
	if (me->query("family/family_name") == "����"&&me->query("gongxian")>20000)
	{
		me->set("can_perform/jiuyang-shengong/jiu", 1);
	me->set("can_perform/jiuyang-shengong/pi", 1);
	me->set("can_perform/jiuyang-shengong/po", 1);
	me->set("can_perform/jiuyang-shengong/ri", 1);
	me->set("can_skill/jiuyang-shengong", 1);
	me->add("gongxian", -20000);
	me->set("zjvip/jiuyangjiemi",1);
	tell_object(me,"����ܾ�����\n");
	CHANNEL_D->do_channel(this_object(), "chat", HIR""HIC+me->query("name")+HIG"���ܾ�����"NOR"");
	}
	else
	tell_object(me,""+assd+"�㲻���������ˣ�\n");


	
	return 1;
}












int ask_xflb()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/buchang_bai"))
	{
		tell_object(ob,"���Ѿ���ȡ����Ա�����,�����Ҿ�ûǮ�ˣ�\n");
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"�Բ���ֻ�л�Ա������ȡ��Ա�����\n");
		return 1;
	}
*/
	command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/buchang_bai");
	tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/buchang_bai",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}

int ask_gift()
{
	object ob = this_player();
	object gift;
	int num,money;
	mixed *today;

	today = localtime(time());
	if(wizardp(ob)||((today[4]+1)==10 && today[3]>=1 && today[3]<=10))
	{
		money=VIP_D->query_gift_payrec("�����/"+ob->query("id"));
		tell_object(ob,"��Ŀǰ����ڳ�ֵ�ۼ�Ϊ"+money+"��\n");

		if(ob->query("guoqing/diaolong"))
			tell_object(ob,HIM"���Ѿ���ȡ������������(��Ѫ+200)���ˡ�"NOR"\n");
		else if(ob->query("shimen/today")>=1000&&!ob->query("guoqing/diaolong"))
		{
			gift = new("/clone/suit/huodong/diaolong");
			tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
			log_file("guoqing", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));
			gift->move(ob);
			ob->set("guoqing/diaolong",1);
		}
		else
			tell_object(ob,HIM"�㻹δ�ﵽ��ȡ����������(��Ѫ+200)��������(�����ڼ�ʦ�ų���1000��)��"NOR"\n");

		if(ob->query("guoqing/manao"))
			tell_object(ob,HIM"���Ѿ���ȡ����Ѫ�������(��Ѫ+500)���ˡ�"NOR"\n");
		else if(money>=500&&!ob->query("guoqing/manao"))
		{
			gift = new("/clone/suit/huodong/manao");
			tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
			log_file("guoqing", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));
			gift->move(ob);
			ob->set("guoqing/manao",1);
		}
		else
			tell_object(ob,HIM"�㻹δ�ﵽ��ȡ��Ѫ�������(��Ѫ+500)��������(�����ڼ��ֵ����500)��"NOR"\n");

		if(ob->query("guoqing/feicui"))
			tell_object(ob,HIM"���Ѿ���ȡ�����δ�������(��Ѫ+1000)���ˡ�"NOR"\n");
		else if(money>=1000&&!ob->query("guoqing/feicui"))
		{
			gift = new("/clone/suit/huodong/feicui");
			tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
			log_file("guoqing", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));
			gift->move(ob);
			ob->set("guoqing/feicui",1);
		}
		else
			tell_object(ob,HIM"�㻹δ�ﵽ��ȡ���δ�������(��Ѫ+1000)��������(�����ڼ��ֵ����1000)��"NOR"\n");

		if(ob->query("guoqing/jiulong"))
			tell_object(ob,HIM"���Ѿ���ȡ�������������(��Ѫ+1500,�ڹ�����+50)���ˡ�"NOR"\n");
		else if(money>=1500&&!ob->query("guoqing/jiulong"))
		{
			gift = new("/clone/suit/huodong/jiulong");
			tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
			log_file("guoqing", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));
			gift->move(ob);
			ob->set("guoqing/jiulong",1);
		}
		else
			tell_object(ob,HIM"�㻹δ�ﵽ��ȡ�����������(��Ѫ+1500,�ڹ�����+50)��������(�����ڼ��ֵ����1500)��"NOR"\n");
	}

	return 1;
}















/*int ask_chongqi()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/buchang_chongqi"))
	{
		tell_object(ob,"���Ѿ���ȡ����������ˣ�\n");
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"�Բ���ֻ�л�Ա������ȡ��Ա�����\n");
		return 1;
	}
*/
	/*command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/buchang_chongqi");
	tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/buchang_chongqi",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}
*/

























int ask_tap()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/taptap"))
	{
		tell_object(ob,"���Ѿ���ȡ����������ˣ�\n");
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"�Բ���ֻ�л�Ա������ȡ��Ա�����\n");
		return 1;
	}
*/
	command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/taptap");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/taptap",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}































int ask_guanji()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/guanji"))
	{
		tell_object(ob,"���Ѿ���ȡ���·�С����ˣ�\n");  //�ػ��·�С���
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"�Բ���ֻ�л�Ա������ȡ��Ա�����\n");
		return 1;
	}
*/
	command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/buchang_guanji");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/guanji",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}












int ask_meizhou1()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/meizhou1"))
	{
		tell_object(ob,"���Ѿ���ȡ���ػ�����ˣ�\n");
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"�Բ���ֻ�л�Ա������ȡ��Ա�����\n");
		return 1;
	}
*/
	command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/meizhou1");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/meizhou1",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}













int ask_yuanma()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/yuanma"))
	{
		tell_object(ob,"���Ѿ���ȡ��Դ������ˣ�\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/yuanmalibao");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/yuanma",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}


















int ask_yuanbao()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/yuanbao"))
	{
		tell_object(ob,"���������\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say ��ʦ����Ŀ����㡣");
	gift = new("/clone/gift/yvrenjie");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/yuanbao",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}



































//������װ
int ask_xiaobai()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/xiaobai"))
	{
		tell_object(ob,"���Ѿ���ȡ���ˣ�\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/xinren_tao");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/xiaobai",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}
























int ask_zhenai()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/zhenai"))
	{
		tell_object(ob,"���Ѿ���ȡ�����������ˣ�\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say ��л��Ե�֧�֡�");
	gift = new("/clone/gift/zhenailihe");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/zhenai",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}



int ask_buchang()
{
	object ob = this_player();
	object gift;
	
	int num,money;

	if (ob->query("zjvip/buchang"))   //Ц�����
	{
		tell_object(ob,"���Ѿ���ȡ����ħ����С����ˣ�\n");
		if (! ob->query("born"))
return notify_fail("�㻹û�г����أ�������ȡ���\n");
		return 1;
	}
	
	command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/buchang_gift");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/buchang",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}
