#include <ansi.h>

inherit NPC;

string ask_lilian();
string ask_jieshu();
string ask_baotu();
string ask_pay();
string ask_yao();
int ask_gift();

void create()
{
	set_name(HIW"����ʹ��"NOR, ({ "shizhe" }));
	set("nickname", HBCYN"����ʹ��"NOR);
	set("long", "����һλ����һ����ǲ��ʹ�ߣ���������һ������顣\n");
	set("gender", "����");
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

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "taiji" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "cuff.zhen" :),
		(: perform_action, "cuff.zhan" :),
		(: perform_action, "cuff.ji" :)
	}));

	set("inquiry", ([
		"�������" : (: ask_gift :),
		"����" : (: ask_lilian :),
		"����" : (: ask_jieshu :),
		"����" : (: ask_pay :),
		"���ĵ�" : (: ask_yao :),
		"�ر�ͼ" : (: ask_baotu :),
	]));
	setup();
}



void init()
{
	object ob;
	::init();//�̳���һ��
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("zjvip/times") > 0 && !ob->query("lilian/start")) {
		command("hi "+ob->query("id"));
		command("whisper "+ob->query("id")+" "HIC"\n��λ" + RANK_D->query_respect(ob) +"�������Ƕ���һ��ĳ�Ա��\n"+
			"�㻹û����������"HIC""ZJURL("cmds:ask shizhe about ����")+ZJSIZE(20)"�Ǽ�"NOR""HIR"����"HIC"��\n"+
			"�Ͻ���ʼ���"HIR"����"HIC"����ȡ���ļ��影���ɣ�"NOR"");
	}

}


int ask_gift()
{
	object ob = this_player();
	object gift;
	int num,money;
	
	if(ob->query("buchang_lingqu"))
	{
		tell_object(ob, "���Ѿ���ȡ����������ˡ�\n");
		return 1;
	}
	
	gift = new("/clone/gift/buchang");
	//gift->set_amount(num);
	tell_object(ob,HIM"������"+gift->short()+"��"NOR"\n"); 
	ob->set("buchang_lingqu", 1);
	log_file("buchang", sprintf("%s��%s(%s)��ȡ��%s��\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
        
}


string ask_lilian()
{ 
	object me = this_object();
	object ob = this_player();

        if (ob->query("vip/all_pay")>0) {
            ob->add("zjvip/all_pay",ob->query("vip/all_pay"));
            ob->delete("vip/all_pay");
            }

        if (ob->query("zjvip/times") <1) return "�Բ�����ֻ���������˵����飡\n";

        if (ob->query("lilian/start")) return "���Ѿ���¼�����������Ϣ������ȥ�ɡ�\n";

	message_vision(HIG"$N�������²�����$n���˵�ͷ��˵�����ðɣ������Ϊ����ϡ�"NOR"\n",me,ob);

	ob->set("lilian/start",time());

	return "������������ʱ�������ҽ���������\n"; 
}

string ask_jieshu()
{
	  object me = this_object();
	  object ob = this_player();
        int time3, paid,exp,gold;

        time3=time()-(int)ob->query("lilian/start");

        if (ob->query("zjvip/times") <1) return "�Բ�����ֻ���������˵����飡\n";

        if (!ob->query("lilian/start")) return "������û�����������¼��\n";

        paid=ob->query("zjvip/all_pay");

        tell_object(ob,HIC"����ۼ�����ʱ����"+CHINESE_D->chinese_time(time3)+"��"NOR"\n");  

        if (time3>43200) time3=43200;

        tell_object(ob,HIC"�����Ч����ʱ����"+CHINESE_D->chinese_time(time3)+"��"NOR"\n");  
	  message_vision(HIY"$N������$n�ı���������"NOR"\n",me,ob);
        ob->add("balance",time3*2);
        ob->add("combat_exp",time3/4);
        ob->add("potential",time3/28);
        ob->delete("lilian/start");
        tell_object(ob,"�㱻������\n"
                       "������"+time3*2/100+" ����\n"
                       "��Ϊ��"+time3/4+" �㣬\n"
                       "Ǳ�ܣ�"+time3/28+" �㡣"NOR"\n");  


        exp=time3*paid/1000;
        if (exp>time3) exp=time3;
        gold=time3*paid/1000;
        if (gold>time3) gold=time3;

        if (ob->query("id")=="12898983") {
            ob->add("combat_exp", time3*5/4);
            }

        ob->add("balance",gold*2);
        ob->add("combat_exp",exp/4);
        //tell_object(ob,"������Ĺ��׶ȣ����������"+gold*2/100+"��������"+exp/4+"����Ϊ��"NOR"\n"); 

	  return "������Ĺ��׶ȣ����⽱����"+gold*2/100+"��������"+exp/4+"����Ϊ��"NOR"\n";
}

string ask_pay()
{
	object me = this_object();
	object ob = this_player();

	if (ob->query("vip/all_pay")>0) {
		ob->add("zjvip/all_pay",ob->query("vip/all_pay"));
		ob->delete("vip/all_pay");
	}

	if (ob->query("zjvip/times") <1) return "��ֻ���������˵����飡\n";

	return "�㵱ǰ������"+chinese_number(ob->query("zjvip/all_pay")+ob->query("gongxians"))+"�㡣\n";
}

string ask_baotu()
{
	int now,last,nowfix,lastfix;
	mixed *t1,*t2;
	object tu,me = this_player();

	//if (!wizardp(me)) return "�����У����Ժ�������\n";
	if (me->query("zjvip/times") <1) return "�Բ�����ֻ���������˵����飡\n";
	if (me->query("zjvip/times") < 10*24*3600) return "�Բ��𣬻�Աʱ���Ѳ���10�죬������ȡ�ز�ͼ��\n";
	last = me->query("zjvip/last_baotu");
	now = time();
	t1 = localtime(now);
	t2 = localtime(last);
	nowfix = now+(6-t1[6])*86400;
	lastfix = last+(6-t2[6])*86400;
	if(last&&(localtime(nowfix)[7]==localtime(lastfix)[7]))
		return "һ����ֻ����һ�Σ�\n";
	if ((me->query_encumbrance()*100 / me->query_max_encumbrance())>90)
		return "�����ϵĶ���̫���ˣ�\n";
	if ( (time()-me->query("birthday")) < 7*86400 )
		return "�㻹�ǵ�����������ȡ�ر�ͼ�ɣ�\n";

	tu = new("/d/fuben/obj/heifeng1");
	tu->move(me);
	me->set("zjvip/last_baotu",now);
	message_vision("ʹ�߸���$Nһ��" + tu->query("name") + "��\n",me);
	log_file("vip_tu",ctime(time())+"��"+me->query("name")+"�ڶ���ʹ��������ȡһ�Ųر�ͼ��\n");
	return "����Ǻö���������������һ��ȥ̽��һ�°ɡ�\n";
}

string ask_yao()
{
	object me = this_object();
	object ob = this_player();
        object yao;

	if (ob->query("zjvip/times") <1) return "�Բ�����ֻ���������˵����飡\n";

        if ( (time()-ob->query_temp("last_huxindan"))<1800 ) {
		    command("say ��λ" + RANK_D->query_respect(ob) + "���㲻�Ǹո�������������ĵ�����ô����Ҫ�ˣ�");
                ob->unconcious();
                return "�����ִ�";
            }

        if (  present("huxin dan", ob) )
                return RANK_D->query_respect(ob) + "�����ϲ����Ѿ����������ĵ�������ô����Ҫ�ˣ� ����̰�����ᣡ";

        if (objectp(present("huxin dan", environment(ob))))
                        return "������һ���������ĵ��������ǰ����ȴû�кú���ϧ...\n";

        if ((ob->query_encumbrance()*100 / ob->query_max_encumbrance())>90)
                return "�����ϵĶ���̫���ˣ�\n";

        yao = new("/clone/shizhe/huxindan9");
        yao->set_amount(99);
        yao->move(ob);
        ob->set_temp("last_huxindan",time());
        message_vision("$N����$nһЩ" + yao->query("name") + "��\n",me ,ob);
	return "����Ǻö�����ϣ���������߽�������������\n";
}
