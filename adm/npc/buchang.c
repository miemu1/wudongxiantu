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
	set_name(HIW"补偿礼包兑换处"NOR, ( { "bai" }));
	set("nickname", HBCYN"使者"NOR);
	set("long", "一位在发补偿礼包。\n");
	set("gender", "女性");
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
	//"上架礼包" : (: ask_tap :),
	
//		"新服小礼包" : (: ask_guanji :),
	///	"源码礼包" : (: ask_yuanma :),
	"九阳绝招" : (: ask_jiuyang :),
	//	"每周礼包" : (: ask_meizhou1 :),
//		"武动仙途开服小礼包" : (: ask_buchang :),
		"新手套装" : (: ask_xiaobai :),
	//	"真爱" : (: ask_zhenai:),
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
	//CHANNEL_D->do_channel( this_object(), "chat", "群号出现了。"+ZJURL("tel:1131210568")"过去"+NOR"。");
	//CHANNEL_D->do_channel( this_object(), "chat", "百度出现了。"+ZJURL("http://m.hao123.comp")"过去"+NOR"。");
	if (me->query("zjvip/jiuyangjiemi"))
	{
		tell_object(me,"滚吧，你师门贡献不够\n");
		return 1;
	}
   if(gongxian<20000)
   {
		tell_object(me,"滚吧，你师门贡献不够。\n");
		return 1;
   }
	if (me->query("family/family_name") == "明教"&&me->query("gongxian")>20000)
	{
		me->set("can_perform/jiuyang-shengong/jiu", 1);
	me->set("can_perform/jiuyang-shengong/pi", 1);
	me->set("can_perform/jiuyang-shengong/po", 1);
	me->set("can_perform/jiuyang-shengong/ri", 1);
	me->set("can_skill/jiuyang-shengong", 1);
	me->add("gongxian", -20000);
	me->set("zjvip/jiuyangjiemi",1);
	tell_object(me,"你解密九阳！\n");
	CHANNEL_D->do_channel(this_object(), "chat", HIR""HIC+me->query("name")+HIG"解密九阳！"NOR"");
	}
	else
	tell_object(me,""+assd+"你不是明教中人！\n");


	
	return 1;
}












int ask_xflb()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/buchang_bai"))
	{
		tell_object(ob,"你已经领取过会员礼包了,再领我就没钱了！\n");
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"对不起，只有会员才能领取会员礼包！\n");
		return 1;
	}
*/
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/buchang_bai");
	tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/buchang_bai",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

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
		money=VIP_D->query_gift_payrec("国庆节/"+ob->query("id"));
		tell_object(ob,"你目前国庆节充值累计为"+money+"。\n");

		if(ob->query("guoqing/diaolong"))
			tell_object(ob,HIM"你已经领取过【雕龙玉佩(气血+200)】了。"NOR"\n");
		else if(ob->query("shimen/today")>=1000&&!ob->query("guoqing/diaolong"))
		{
			gift = new("/clone/suit/huodong/diaolong");
			tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
			log_file("guoqing", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));
			gift->move(ob);
			ob->set("guoqing/diaolong",1);
		}
		else
			tell_object(ob,HIM"你还未达到领取【雕龙玉佩(气血+200)】的条件(国庆期间师门超过1000次)。"NOR"\n");

		if(ob->query("guoqing/manao"))
			tell_object(ob,HIM"你已经领取过【血晶玛瑙佩(气血+500)】了。"NOR"\n");
		else if(money>=500&&!ob->query("guoqing/manao"))
		{
			gift = new("/clone/suit/huodong/manao");
			tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
			log_file("guoqing", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));
			gift->move(ob);
			ob->set("guoqing/manao",1);
		}
		else
			tell_object(ob,HIM"你还未达到领取【血晶玛瑙佩(气血+500)】的条件(国庆期间充值超过500)。"NOR"\n");

		if(ob->query("guoqing/feicui"))
			tell_object(ob,HIM"你已经领取过【滴翠琉璃佩(气血+1000)】了。"NOR"\n");
		else if(money>=1000&&!ob->query("guoqing/feicui"))
		{
			gift = new("/clone/suit/huodong/feicui");
			tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
			log_file("guoqing", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));
			gift->move(ob);
			ob->set("guoqing/feicui",1);
		}
		else
			tell_object(ob,HIM"你还未达到领取【滴翠琉璃佩(气血+1000)】的条件(国庆期间充值超过1000)。"NOR"\n");

		if(ob->query("guoqing/jiulong"))
			tell_object(ob,HIM"你已经领取过【金镶九龙佩(气血+1500,内功激发+50)】了。"NOR"\n");
		else if(money>=1500&&!ob->query("guoqing/jiulong"))
		{
			gift = new("/clone/suit/huodong/jiulong");
			tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
			log_file("guoqing", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));
			gift->move(ob);
			ob->set("guoqing/jiulong",1);
		}
		else
			tell_object(ob,HIM"你还未达到领取【金镶九龙佩(气血+1500,内功激发+50)】的条件(国庆期间充值超过1500)。"NOR"\n");
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
		tell_object(ob,"你已经领取过补偿礼包了！\n");
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"对不起，只有会员才能领取会员礼包！\n");
		return 1;
	}
*/
	/*command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/buchang_chongqi");
	tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/buchang_chongqi",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

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
		tell_object(ob,"你已经领取过补偿礼包了！\n");
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"对不起，只有会员才能领取会员礼包！\n");
		return 1;
	}
*/
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/taptap");
	//tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/taptap",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

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
		tell_object(ob,"你已经领取过新服小礼包了！\n");  //关机新服小礼包
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"对不起，只有会员才能领取会员礼包！\n");
		return 1;
	}
*/
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/buchang_guanji");
	//tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/guanji",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

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
		tell_object(ob,"你已经领取过关机礼包了！\n");
		return 1;
	}
/*
	if (ob->query("zjvip/times") <1)
	{
		tell_object(ob,"对不起，只有会员才能领取会员礼包！\n");
		return 1;
	}
*/
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/meizhou1");
	//tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/meizhou1",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

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
		tell_object(ob,"你已经领取过源码礼包了！\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/yuanmalibao");
	//tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/yuanma",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

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
		tell_object(ob,"你个蠢货！\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say 巫师嘲讽的看着你。");
	gift = new("/clone/gift/yvrenjie");
	//tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/yuanbao",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}



































//新手套装
int ask_xiaobai()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/xiaobai"))
	{
		tell_object(ob,"你已经领取过了！\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/xinren_tao");
	//tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/xiaobai",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

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
		tell_object(ob,"你已经领取过的心意了了！\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say 感谢你对的支持。");
	gift = new("/clone/gift/zhenailihe");
	//tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/zhenai",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}



int ask_buchang()
{
	object ob = this_player();
	object gift;
	
	int num,money;

	if (ob->query("zjvip/buchang"))   //笑傲礼包
	{
		tell_object(ob,"你已经领取过老魔开服小礼包了！\n");
		if (! ob->query("born"))
return notify_fail("你还没有出生呢！不能领取礼包\n");
		return 1;
	}
	
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/buchang_gift");
	//tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/buchang",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}
