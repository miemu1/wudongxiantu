
inherit NPC;
#include <ansi.h>

string ask_baibao();
int ask_character(string arg);
int ask_fanli();
int ask_xiandan();
int ask_illness();
int ask_kuilei();
int ask_mengzi();
int ask_buchang();
int ask_shimen();
int ask_gift();
int ask_viplv();
int ask_xidian();
int ask_shimen();
int ask_xingai();
int ask_jiuyang();
int ask_huidanglibao();
int ask_DDOS();

string *sk_list = ({
		"qishang-quan",
		"zhuihun-jian",
		"zhuihun-jian",
		"zhuihun-jian",
		"baihua-quan",
		"baihua-quan",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"sougu",
		"sougu",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-shenfa",
		"yunlong-shenfa",
		"hanxing-bada",
		"hanxing-bada",
		"huanyin-zhi",
		"zijinbagua-dao",
		"sanfen-jianshu",
		"ningxue-shenzhao",
		"sanfen-jianshu",
		"huanyin-zhi",
		"zijinbagua-dao",
		"xuanming-zhang",
		"ningxue-shenzhao",
		"xuanming-zhang",
		"shenzhaojing",
});
string *sk_list2 = ({
		"qishang-quan",
		"zhuihun-jian",
		"baihua-quan",
		"hanbing-mianzhang",
		"sougu",
		"yunlong-bian",
		"yunlong-shenfa",
		"hanxing-bada",
		"xuanming-zhang",
		"sanfen-jianshu",
		"huanyin-zhi",
		"ningxue-shenzhao",
		"zijinbagua-dao",
		"shenzhaojing",
		"jiuyang-shengong",
});

void create()
{
		set_name(HIW"ϴ��ʦ"NOR,({  "xidian", "shi" }) );
		set("gender", "����" );
	//	set("race", "��ħ");
		set("age", 30);
		set("long", "����һ�������������µ��ˡ�\n");

		set("str", 999);
		set("dex", 999);
		set("con", 999);
		set("int", 999);
		set("shen_type", 1);
		set("combat_exp", 100);
		set("attitude", "peaceful");

		setup();

		set("inquiry", ([


	        "ϴ��": (: ask_viplv :),
			"��������": (: ask_jiuyang :),
			//"�ص����": (: ask_huidanglibao :),
			//"ʦ��": (: ask_shimen :),
//			"����": (: ask_xingai :),
			//"����ʦ��": (: ask_DDOS :),
		]));

		carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("ask_character","washme");
	add_action("ask_xidian","xidian");
	add_action("do_getvip","getvip");
	add_action("do_getsk","getsk");
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
   if(!me->query("gongxian")>20000)
		tell_object(me,"���ɣ���ʦ�Ź��ײ�����\n");
		return 1;
	
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




int ask_viplv()
{
	int i,lv;
	object me;
	string str;

	me = this_player();
	str = ZJOBLONG"����ϴ��ɣ�"ZJBR"�������Զ������������£�\n";
	str += ZJOBACTS2+ZJMENUF(1,1,10,30);
	
	str += "[ϴ������]["+((me->query("zjvip/xiaobaizuishuai")||me->query("zjvip/reset_att_times"))?"�Ѵ��":"���ϴ�㵤")+"]["
			+((me->query("zjvip/vipgift/vip0")&&!me->query("zjvip/reset_att_times"))?"����ȡ":"δ��ȡ")
			+"]:getvip 5"ZJSEP;
	

	tell_object(me,str+"\n");
}





int do_getvip(string arg)
{
	int i,lv;
	object ob,me;
	string sk,str;

	me = this_player();
	if(!me->query("zjvip/times"))
	{
		tell_object(me,"��û��vip��������ȡvip�ɾͣ�\n");
		return 1;
	}
	lv = me->query("zjvip/level");
	if(!arg)
	{
		tell_object(me,"��Ҫ��ʲô��\n");
		return 1;
	}
	     
		 
		 
		 
		 
		 
	else if(arg=="5")
	{
		if(!me->query("zjvip/xiaobaizuishuai"))
		{
			tell_object(me,"�㻹û�д�ɸóɾͣ�������ȡ������\n");
			return 1;
		}
	 
		ask_xidian();
	}
	else if(arg=="6")
	{
		if(lv<6&&!me->query("zjvip/reset_cha_times"))
		{
			tell_object(me,"�㻹û�д�ɸóɾͣ�������ȡ������\n");
			return 1;
		}
		else if(me->query("zjvip/vipgift/vip6")&&!me->query("zjvip/reset_cha_times"))
		{
			tell_object(me,"���Ѿ���ȡ��vip6�ɾͽ����ˣ�\n");
			return 1;
		}
		ask_character(0);
	}

	return 1;
}
        
		
		
		
int ask_xidian(string arg)
{
	int i,rand,all,tmpstr,tmpcon,tmpdex,tmpint,lv;
	int dstr,dcon,ddex,dint;
	string leipi,*skills,msg, type, cs;
	mapping skl;

	object me = this_player();

	lv = me->query("zjvip/level");
	if(!me->query("zjvip/xiaobaizuishuai"))
	{
		tell_object(me,"�㻹û�д�ɸóɾͣ�������ȡ������\n");
		return 1;
	}
	//else if(me->query("zjvip/xiaobaizuishuai")&&!me->query("zjvip/reset_att_times"))
	//{
	//	tell_object(me,"���Ѿ�ϴ���ˣ�\n");
	//	return 1;
	//}

	all = me->query("str") + me->query("int") + me->query("con") + me->query("dex");
	if(!me->query("gift/lighting"))
	{
		leipi = HIM"����δ�����������츳�¼�������ϴ�㽫�����������츳��"ZJBR;
		all++;
	}else leipi = "";
	
	if (!arg) {
		tell_object(me,INPUTTXT(leipi+"ע�⣺"HIR"ϴ������в�����ѧϰ�����ļ��ܶ���ɾ���������濼�ǡ�"NOR"$br#�������������ķ�����$br#"
						"���ձ��������ԡ����ǡ�����������4����"
						"�ո�ֿ�������ע��ÿ�������ܵ���25�����45��4����֮�ͱ���Ϊ"+all+"��","xidian $txt#")+"\n");
		return 1;
	}
	else if(sscanf(arg, "yes %d %d %d %d",tmpstr,tmpint,tmpcon,tmpdex) == 4)
	{
		if(tmpstr<25||tmpint<25||tmpcon<25||tmpdex<25||tmpstr>45||tmpint>45||tmpcon>45||tmpdex>45||(tmpstr+tmpint+tmpcon+tmpdex)!=all)
		{
			tell_object(me,INPUTTXT(leipi+"ע�⣺"HIR"ϴ������в�����ѧϰ�����ļ��ܶ���ɾ���������濼�ǡ�"NOR"$br#�������������ķ�����$br#"
					"���ձ��������ԡ����ǡ�����������4����"
					"�ո�ֿ�������ע��ÿ�������ܵ���25�����45��4����֮�ͱ���Ϊ"+all+"��","xidian $txt#")+"\n");
			return 1;
		}
		me->set("str",tmpstr);
		me->set("int",tmpint);
		me->set("con",tmpcon);
		me->set("dex",tmpdex);
		if(leipi != "")
			me->add("gift/lighting", 1);

		log_ufile(me,"viplvgift",sprintf("�ɹ�ϴ�㣬Ŀǰ������[%d]������[%d]������[%d]����[%d]��\n",me->query("str"),me->query("int"),me->query("con"),me->query("dex")));
		skl = me->query_skills();
	//	skills = keys(skl);
		for(i=0;i<sizeof(skills);i++)
		{
			if(!SKILL_D(skills[i])->valid_learn(me) && strsrch(skills[i],"-cognize")==-1)
			{
				tell_object(me, to_chinese(skills[i])+"�Ѿ�������ѧϰ�������Զ�ɾ�������д�������ϵ�������ָ���\n");
				log_ufile(me,"viplvgift",me->query_skill(skills[i],1)+"��"+skills[i]+"ϴ����Ѿ�������ѧϰ�������Զ�ɾ����\n");
				me->set("valid_skill/"+skills[i],me->query_skill(skills[i],1));
				me->delete_skill(skills[i]);
			}
		}
		tell_object(me, "ϴ��ɹ���ף����Ϸ��졣\n");
		CHANNEL_D->do_channel(this_object(), "chat", HIR""HIC+me->query("name")+HIG"�ɹ�ϴ�㣡"NOR"");
		if(me->query("zjvip/xiaobaizuishuai"))
			me->delete("zjvip/xiaobaizuishuai");
		else
			me->set("zjvip/xiaobaizuishuai",1);
	}
	else if(sscanf(arg, "%d %d %d %d",tmpstr,tmpint,tmpcon,tmpdex)  == 4)
	{
		msg = ZJOBLONG+"����["+tmpstr+"]������["+tmpint+"]������["+tmpcon+"]����["+tmpdex+"]����ȷ����\n";			
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "ȷ��:xidian yes "+arg;
		msg += ZJSEP"ȡ��:look";
		tell_object(me,msg+"\n");
	}
	else
	{
		tell_object(me,INPUTTXT("�����ʽ���ԣ������������������ķ�����$br#"
						"���ձ��������ԡ����ǡ�����������4����"
						"�ո�ֿ�������ע��ÿ�������ܵ���25�����300��4����֮�ͱ���Ϊ"+all+"��","xidian $txt#")+"\n");
	}
	
	return 1;
}

int ask_huidanglibao()
{
	object ob = this_player();
	object gift;
	int num,money;


	command("nod "+ob->query("id"));
	command("say ����ͷ����㡣");
	gift = new("/clone/gift/huidanglibao");
	tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/huidanglibao",1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}




int ask_xingai()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/xingai"))
	{
		tell_object(ob,"���Ѿ���ȡ�������ˣ�\n");
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
	command("say �����ϸ��㡣");
	gift = new("/clone/gift/xingyi");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/xingai",1);
	log_file("liwu0", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}




int ask_DDOS()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/ʦ��"))
	{
		tell_object(ob,"���Ѿ���ȡ�������ˣ�\n");
		return 1;
	}

	if (ob->query("zjvip/all_pay") <500)
	{
		tell_object(ob,"��Ŀǰ��û���ʸ�\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say �����ϸ��㡣");
	gift = new("/clone/1shimen");
	//tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n");
	ob->set("zjvip/ʦ��",1);
	log_file("libao", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}
