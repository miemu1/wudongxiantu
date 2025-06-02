// tangyao

inherit NPC;

int give_job();
int give_yao();

void create()
{
	set_name("��ҩ", ({ "tang yao", "tang", "yao"}));
        set("long",
"���Ŷ������ӣ������ŵ�λ�ĸߡ�\n");
	set("gender", "����");
	set("age", 55);
        set("class", "tangmen");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 28);
        set("max_qi", 8000);
        set("max_jingli", 1500);
        set("max_douzhi", 500);
        set("douzhi", 500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("yanli",200);
        set("jiali", 100);
        set("combat_exp", 800000);
        set("level", 15);
        set("shen",3000);
        set("score", 7000);

        set_skill("force", 180);
        set_skill("throwing", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("literate", 180);
        set_skill("hand", 180);
        set_skill("sword", 180);
        set_skill("boyun-suowu", 180);
        set_skill("biyun-xinfa", 180);
        set_skill("qiulin-shiye", 180);
        set_skill("wuzhan-mei", 180);
        set_skill("tangmen-throwing", 180);
        set_skill("tangmen-poison", 180);
        set_skill("tangmen-medical", 180);        
        
        map_skill("force", "biyun-xinfa");
        map_skill("throwing", "tangmen-throwing");
        map_skill("dodge", "qiulin-shiye");
        map_skill("parry", "wuzhan-mei");
        map_skill("sword", "wuzhan-mei");
        map_skill("hand", "boyun-suowu");
        
        prepare_skill("hand", "boyun-suowu");
        
	create_family("��������", 2, "����");

	set("inquiry", ([
		"job" : ( : give_job  : ),
		"����": ( : give_job  : ),
		"ɢ������": ( : give_yao : ),
	]));

        set_temp("apply/damage", 100);  
        set_temp("apply/unarmed_damage", 100);  
        set_temp("apply/armor", 200);          

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/tangmen/obj/feidao")->wield();
        carry_object("/d/tangmen/obj/fhshi")->wield();
        carry_object("/d/tangmen/obj/tiejili")->wield();
        carry_object("/d/tangmen/obj/feidao")->wield();
        carry_object("/d/tangmen/obj/fhshi")->wield();
        carry_object("/d/tangmen/obj/tiejili")->wield();
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
        set_temp("handing", carry_object("/d/tangmen/obj/jili"));   
}

int give_job()
{
	object me;

	me = this_player();

	if( !environment() || base_name(environment()) != query("startroom") )
	{
		say("��ҩ˵��:��������û��������ɻ���һ���ҩ����˵�ɣ���\n");
		return 0;
	}

	if ( !(int)me->query_temp("tangmen/yao") )
		command("say ������û�л��ܸ���ɣ�����˭˵�ģ���");
	else
	{
		if ( (int)me->query_temp("yao") )
		{
	                command("say ���㻹û����ɸղŸ���������أ���");
			return 1;
		}
		write("��ҩ˵��:����������ȱһζ��ҩ����ȥҩ�Ը�����(zhao)һ���ҩ(yao)���ɣ���\n");
		me->set_temp("yao",1);
	}
	return 1;
}

int give_yao()
{
        object me = this_player();
        object ob;
        
        if ( (string)me->query ("family/family_name") != "��������")
	{
        	command("say �㲻�����������ˣ����޷�����ɢ�����꣡\n");
                return 1;
        } else
        {
                command("say ��ɢ���������������������涾ʹ�õĻ�������û�ж��֣�\n");
                ob = new("/kungfu/class/tangmen/obj/san");
                ob->move(this_object());
                command("give sanhua tianyu to " + me->query("id"));
                return 1;
        }
                
}

int accept_object(object who, object ob)
{
	command("say Ҫ���ҵ��ˣ��ͷŵ�������ȥ�ɣ����Ҹ�ʲô?");
	write("��ҩ������ҡ��ҡͷ��Ȼ����С������ķ�Ū��һ�����ɫ��ҩ�ݡ�\n");
	return 0;
}
