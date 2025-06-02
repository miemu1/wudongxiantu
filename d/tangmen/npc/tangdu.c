// tangdu

inherit NPC;

int give_job();
int give_duyao();

void create()
{
	set_name("�ƶ�", ({ "tang du", "tang", "du"}));
	set("long", 
"�ƶ�xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx��\n");
	set("gender", "����");
        set("age", 25);
        set("class", "tangmen");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 25);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 8000);
        set("max_jingli", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("shen", 2000);
        set("combat_exp", 100000);
        set("level", 8);
        set("score", 7000);

        set_skill("force", 80);
        set_skill("throwing", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("literate", 80);
        set_skill("hand", 80);
        set_skill("sword", 80);
        set_skill("boyun-suowu", 80);
        set_skill("biyun-xinfa", 80);
        set_skill("qiulin-shiye", 80);
        set_skill("wuzhan-mei", 80);
        set_skill("tangmen-throwing", 80);
        set_skill("tangmen-poison", 80);
        set_skill("tangmen-medical", 80);        
        
        map_skill("force", "biyun-xinfa");
        map_skill("throwing", "tangmen-throwing");
        map_skill("dodge", "qiulin-shiye");
        map_skill("parry", "boyun-suowu");
        map_skill("sword", "wuzhan-mei");        
        map_skill("hand", "boyun-suowu");
        
        prepare_skill("hand", "boyun-suowu");

        
        create_family("��������", 3, "����");

	set("inquiry", ([
		"job" : ( : give_job  : ),
		"����": ( : give_job  : ),
		"duyao": ( : give_duyao : ),
		"��ҩ": ( : give_duyao : ),
	]));

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        	(: exert_function, "recover" :),  
        	(: exert_function, "powerup" :),  
        	// ( : command("wield all") : ),
        	(: perform_action, "throwing.san" :),          	
        }) );	
        
        set_temp("apply/damage", 100);  
        set_temp("apply/unarmed_damage", 100);  
        set_temp("apply/armor", 200);  

        setup();
        carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/tangmen/obj/jili"));  
        carry_object("/d/tangmen/obj/feidao");
}

int give_job()
{
	object me, du;
	string msg, targ;
	int coun;

	string *tar = ({
		"","���","��Ы��","��Ҷ��","����","����","ǧ�궾��",
//		"Ы��","Ы�ӿ�","Ы��β","���߶�","���ߵ�","����Ƥ","���߶�","���ߵ�","����Ƥ","���߶�","���ߵ�","����Ƥ",
	});

	me = this_player();
	du = this_object();

	if( !environment() || base_name(environment()) != query("startroom") )
	{
		say("�ƶ�˵��:��������û��������ɻ���һ��ƶ�����˵�ɣ���\n");
		return 0;
	}

	if ( !(int)me->query_temp("tangmen/du") )
		command("say ������û�л��ܸ���ɣ�����˭˵�ģ���");
	else
	{
		if ( (int)me->query_temp("duyao") )
		{
	                command("say ���㻹û����ɸղŸ���������أ���");
			return 1;
		}
		coun = 1 + random(sizeof(tar));
		if ( coun == sizeof(tar) )
			coun = ( sizeof(tar) - 1 );
		targ = tar[coun];
		printf("%d/%d\n",coun,sizeof(tar));
		say("�ƶ�˵��:����������ȱһζ�����ȥ������һֻ" + targ + "���ɣ���\n");
		me->set_temp("duyao",coun);
	}
	return 1;
}

int give_duyao()
{
        object me = this_player();
        object ob;
        
        if ( (string)me->query ("family/family_name") != "��������")
	{
        	command("say �㲻�����������ˣ����޷����㶾ҩ��\n");
                return 1;
        } else
        {
                command("say �˶�ҩ���о޶�������֮��ֻ�������ܽ⣬ǧ��Ҫע�ⲻҪ�Լ��ж��ˣ�\n");
                ob = new("/d/tangmen/obj/duyao");
                ob->move(this_object());
                command("give tangmen qidu to " + me->query("id"));
                return 1;
        }
                

}

int accept_object(object who, object ob)
{
	command("say Ҫ���ҵ��ˣ��ͷŵ�������ȥ�ɣ����Ҹ�ʲô?");
	write("�ƶ�����������������һֻī��ɫ�ĳ��ӣ��ٺټ�Ц�˼�����\n");
	return 0;
}
