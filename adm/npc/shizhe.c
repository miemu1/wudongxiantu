#include <ansi.h>

inherit NPC;

string ask_lilian();
string ask_jieshu();
string ask_baotu();
string ask_pay();
int ask_job();
string ask_yao();
int ask_gift1();
int ask_gift();
int ask_xflb();
int ask_quanfu();
int ask_jiaofei();


void create()
{
	set_name(HIW"疯无夜"NOR, ( { "shizhe" }));
	set("nickname", HBCYN"巫师分身"NOR);
	set("long", "这是具巫师的分身。\n");
	set("gender", "男性");
	set("age", 999);
	set("per", 999);
	set("str", 999);
	set("int", 999);
	set("con", 999);
	set("dex", 999);
	set("qi",999999);
	set("jingli",999999);
	set("max_qi", 999999);
	set("max_jing", 999999);
	set("eff_jingli", 999999);
	set("jiali", 9999);
	set("combat_exp", 9000000);
	set("shen", 25000);

	set("action_list",([
//		"点券兑换":"ljshop",
	]));

	set("inquiry", ([
//		"节日礼包" : (: ask_gift1 :),
//		"国庆礼物" : (: ask_gift :),
//		"双黄月饼": (: ask_job :),
		"历练" : (: ask_lilian :),
		"结束" : (: ask_jieshu :),
		"领取护心" : (: ask_yao :),
		"领取藏宝" : (: ask_baotu :),
		"新人礼包" : (: ask_xflb :),
//		"礼包" : (: ask_quanfu :),
		"剿匪奖励" : (: ask_jiaofei :),
	]));
	setup();
}

int ask_jiaofei()
{
	object ob = this_player();
	object gift;
	int num,money;
	
	if (ob->query("tufeijf") < 1)
	{
		tell_object(ob,"你的土匪点券不够，不能领取！\n");
		return 1;
	}

	ob->add("tufeijf",-1);
	ob->add("tianji1",1);
	ob->add("yuanbao",1000);
	tell_object(ob,"你获得土匪奖励天机点1点和灵石1千！\n");
	return 1;
}

int ask_job()
{
	object ob,me = this_player();
	object xique;

	ob = present("shuang huang",me);
	if (!ob)
	{
		command("say 中秋快到了，我给百姓准备的双黄月饼不足了，如果你有的话赶紧给我吧，我会给你奖励哦！");
		return 1;
	}

	command("nod "+me->query("id"));
	command("say 真是谢谢你了，祝你中秋节快乐！");
	tell_object(me,HIY"你的中秋活动点券增加"+ob->query_amount()+NOR"。\n");
	me->add("zhongqiu/pot",ob->query_amount());
	destruct(ob);

	return 1;
}

void init()
{
	object ob;
	::init();//继承上一级
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
	add_action("ljshop","ljshop");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("zjvip/times") > 0 && !ob->query("lilian/start"))
	{
		command("hi "+ob->query("id"));
		command("whisper "+ob->query("id")+" "HIC"\n这位" + RANK_D->query_respect(ob) +"你是我们东方一族的成员，\n"+
		        "你还没有在我这里"HIC""ZJURL("cmds:ask shizhe about 历练")+ZJSIZE(20)"登记"NOR""HIR"历练"HIC"，\n"+
		        "赶紧开始你的"HIR"历练"HIC"，领取丰厚的家族奖励吧！"NOR"");
	}

}

int ljshop(string arg)
{
	string *list,str,file,price;
	int amount,i,yuanbao,value;
	object me,ob;
	mapping goods;

	me = this_player();
	goods = ([
	             "/clone/shizhe/putao":70,
	             "/clone/shizhe/dan_chongmai1":30,
	         ]);
	list = keys(goods);
	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("zhongqiu/pot")+"中秋点券，请选择您想兑换的道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,32);
		for(i=0; i<sizeof(list); i++)
		{
			file = list[i];
			if(!goods[file]||file_size(file+".c")<0) continue;
			yuanbao = goods[file];
			price = yuanbao+"点券";
			str += sprintf("%s"ZJBR"%s:ljshop look %s"ZJSEP,file->query("name"),price,file);
		}
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];
		price = yuanbao+"点券";
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "兑换:ljshop buy "+file+"\n";
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file+".c")<0||!goods[file])
				return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

			write(INPUTTXT("你想兑换多少个"+file->query("name")+"？"ZJBR"请确认你的背包空间足够。","ljshop buy $txt# "+file)+"\n");
			return 1;
		}

		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		if(!file->query_amount())
			amount = 1;
		yuanbao = goods[file];

		if(amount<1 || amount>300)
			return notify_fail(HIM"不能兑换那么多！！"NOR"\n");
		if(me->query("zhongqiu/pot") < yuanbao*amount)
			return notify_fail(HIM"你的兑换点券不足，多参加参加中秋活动把！！"NOR"\n");
		me->add("zhongqiu/pot",-yuanbao*amount);
		ob = new(file);
		if(ob->query_amount())
			ob->set_amount(amount);
		log_ufile(me,"pay/zhongqiu", "兑换了"+ob->short()+"。\n");
		tell_object(me,"你成功兑换到了"+ob->short()+"。"NOR"\n");
		ob->move(me);
		return 1;
	}
	else
		return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}

//int ask_gift1()
//{
	
//	return 1;
//}

int ask_xflb()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/kaihuang_gift"))
	{
		tell_object(ob,"你已经领取过新人礼包了，不能重复领取！\n");
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
	gift = new("/clone/gift/xflb");
	tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/kaihuang_gift",1);
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

string ask_lilian()
{
	object me = this_object();
	object ob = this_player();

	if (ob->query("vip/all_pay")>0)
	{
		ob->add("zjvip/all_pay",ob->query("vip/all_pay"));
		ob->delete("vip/all_pay");
	}

	if (ob->query("zjvip/times") <1) return "对不起，我只处理东方族人的事情！\n";

	if (ob->query("lilian/start")) return "我已经记录了你的历练信息，放心去吧。\n";

	message_vision(HIG"$N翻开记事簿，对$n点了点头，说道：好吧，我这就为你记上。"NOR"\n",me,ob);

	ob->set("lilian/start",time());

	return "别忘了在六个时辰内找我结束历练。\n";
}

string ask_jieshu()
{
	object me = this_object();
	object ob = this_player();
	int time3, paid,exp,gold;

	time3=time()-(int)ob->query("lilian/start");

	if (ob->query("zjvip/times") <1) return "对不起，我只处理东方族人的事情！\n";

	if (!ob->query("lilian/start")) return "我这里没有你的历练记录。\n";

	paid=ob->query("zjvip/all_pay");

	tell_object(ob,HIC"你的累计历练时间是"+CHINESE_D->chinese_time(time3)+"。"NOR"\n");

	if (time3>43200) time3=43200;

	tell_object(ob,HIC"你的有效历练时间是"+CHINESE_D->chinese_time(time3)+"。"NOR"\n");
	message_vision(HIY"$N结束了$n的本次历练！"NOR"\n",me,ob);
	ob->add("balance",time3*5);
	ob->add("combat_exp",time3/1);
	ob->add("potential",time3/1);
	ob->delete("lilian/start");
	tell_object(ob,"你被奖励了\n"
	            "白银："+time3*2/100+" 两，\n"
	            "修为："+time3/1+" 点，\n"
	            "潜能："+time3/1+" 点。"NOR"\n");


	exp=time3*paid/1500;
	if (exp>time3) exp=time3;
	gold=time3*paid/1500;
	if (gold>time3) gold=time3;

	if (ob->query("id")=="12898983")
	{
		ob->add("combat_exp", time3*5/4);
	}

	ob->add("balance",gold*2);
	ob->add("combat_exp",exp/4);
	//tell_object(ob,"根据你的贡献度，你额外获得了"+gold*2/100+"两白银和"+exp/4+"点修为。"NOR"\n");

	return "根据你的贡献度，额外奖励你"+gold*2/100+"两白银和"+exp/8+"点修为。"NOR"\n";
}

string ask_baotu()
{
	int now,last,nowfix,lastfix;
	mixed *t1,*t2;
	object tu,me = this_player();

	//if (!wizardp(me)) return "测试中，请稍后再来！\n";
	if (me->query("zjvip/times") <1) return "对不起，我只处理东方族人的事情！\n";
	if (me->query("zjvip/times") < 7*24*3600) return "对不起，会员时长已不足10天，不能领取藏波图！\n";
	last = me->query("zjvip/last_baotu");
	now = time();
	t1 = localtime(now);
	t2 = localtime(last);
	nowfix = now+(6-t1[6])*86400;
	lastfix = last+(6-t2[6])*86400;
	if(last&&(localtime(nowfix)[7]==localtime(lastfix)[7]))
		return "一周内只能领一次！\n";
	if ((me->query_encumbrance()*100 / me->query_max_encumbrance())>90)
		return "你身上的东西太多了！\n";
	if ( (time()-me->query("birthday")) < 7*86400 )
		return "你还是等下周再来领取藏宝图吧！\n";

	tu = new("/d/fuben/obj/heifeng1");
	tu->move(me);
	me->set("zjvip/last_baotu",now);
	message_vision("使者给了$N一张" + tu->query("name") + "。\n",me);
	log_file("vip_tu",ctime(time())+"："+me->query("name")+"在东方使者那里领取一张藏宝图。\n");
	return "这可是好东西，你抽空找朋友一起去探索一下吧。\n";
}

string ask_yao()
{
	object me = this_object();
	object ob = this_player();
	object yao;

	if (ob->query("zjvip/times") <1) return "对不起，我只处理东方族人的事情！\n";

	if ( (time()-ob->query_temp("last_huxindan"))<1800 )
	{
		command("say 这位" + RANK_D->query_respect(ob) + "，你不是刚刚来领过天王护心丹吗，怎么又来要了？");
		ob->unconcious();
		return "真是讨打！";
	}

	if (  present("huxin dan", ob) )
		return RANK_D->query_respect(ob) + "你身上不是已经有天王护心丹了吗，怎么又来要了？ 真是贪得无厌！";

	if (objectp(present("huxin dan", environment(ob))))
		return "曾经有一颗天王护心丹落你的眼前，你却没有好好珍惜...\n";

	if ((ob->query_encumbrance()*100 / ob->query_max_encumbrance())>90)
		return "你身上的东西太多了！\n";

	yao = new("/clone/shizhe/huxindan9");
	yao->set_amount(99);
	yao->move(ob);
	ob->set_temp("last_huxindan",time());
	message_vision("$N给了$n一些" + yao->query("name") + "。\n",me ,ob);
	return "这可是好东西，希望对你行走江湖有所帮助。\n";
}






int ask_quanfu()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/quanfu_gift"))
	{
		tell_object(ob,"你已经领取过剑寒霜礼包了，不能重复领取！\n");
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
	gift = new("/clone/gift/quanfu");
	tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/quanfu_gift",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}
