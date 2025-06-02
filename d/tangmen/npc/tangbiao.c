// tangbiao

inherit NPC;

int give_job();
int give_anqi();

void create()
{
	set_name("����", ({ "tang biao", "tang", "biao"}));
	set("long", 
"���������еľ����ڷ����������á�\n");	
	set("gender", "����");
        set("gender", "����");
        set("age", 32);
        set("class", "tangmen");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 26);
        set("con", 26);
        set("dex", 27);
        set("max_qi", 8000);
        set("max_jingli", 2500);
        set("max_douzhi", 600);
        set("douzhi", 600);
        set("neili", 4500);
        set("max_neili", 4500);
        set("yanli", 200);
        set("jiali", 120);
        set("combat_exp", 900000);
        set("level", 15);
        set("score", 8000);

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
        
        set_temp("apply/damage", 100);  
        set_temp("apply/unarmed_damage", 100);  
        set_temp("apply/armor", 200);  
        
	create_family("��������", 2, "����");

	set("inquiry", ([
		"job" : ( : give_job  : ),
		"����": ( : give_job  : ),
		"anqi": ( : give_anqi : ),
		"����": ( : give_anqi : ),
	]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/tangmen/obj/jili"));  
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
}

int give_job()
{
	object me, biao;
	string msg, targ;
	int coun;

	string *tar = ({
		"","����ʯ",
	});

	me = this_player();
	biao = this_object();

	if( !environment() || base_name(environment()) != query("startroom") )
	{
		say("����˵��:��������û��������ɻ���һ����ڷ���˵�ɣ���\n");
		return 0;
	}

	if ( !(int)me->query_temp("tangmen/biao") )
		command("say ������û�л��ܸ���ɣ�����˭˵�ģ���");
	else
	{
		if ( (int)me->query_temp("biao") )
		{
	                command("say ���㻹û����ɸղŸ���������أ���");
			return 1;
		}
		coun = 1 + random(sizeof(tar));
		if ( coun == sizeof(tar) )
			coun = ( sizeof(tar) - 1 );
		targ = tar[coun];
		printf("%d/%d\n",coun,sizeof(tar));
		say("����˵��:���������Ϻõ�" + targ + "�����ˣ���ȥ��ɽ������һЩ���ɣ���\n");
		me->set_temp("biao",coun);
	}
	return 1;
}

int give_anqi()
{
        object me = this_player();
        object ob;
        
        if ( (string)me->query ("family/family_name") != "��������")
	{
        	command("say �㲻�����������ˣ����޷��������Ӹ��ڣ�\n");
                return 1;
        } else
        {
                command("say �����Ӹ������������������涾ʹ�õĻ���Ч�����ã�\n");
                ob = new("/kungfu/class/tangmen/obj/biao");
                ob->move(this_object());
                command("give qizi gangbiao to " + me->query("id"));
                return 1;
        }
                
}

int accept_object(object who, object ob)
{
	command("say Ҫ���ҵ��ˣ��ͷŵ�������ȥ�ɣ����Ҹ�ʲô?");
	write("���ڳ����㲻�ͷ��Ļ��˻��֣�����ͷ�����о�����ͼ�ס�\n");
	return 0;
}
