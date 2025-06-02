inherit NPC;

void xuemo_pfm();

void create()
{
	set_name("Ѫħ", ({ "wuzheng daozu", "daozu" }));
	set("long", "���档\n");
	set("gender", "����");
	set("age", 100);
	set("shen_type", 1);
	set("shen", 500000);
	set("str", 31);
	set("int", 39);
	set("con", 40);
	set("dex", 32);
	
	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: xuemo_pfm :),
	}));
        
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void xuemo_pfm()
{
    object who = select_opponent();
    tell_object(who, "Ѫħ����һ���ֺ�������˺ҧ��\n");
    if (random(2))
    {
        tell_object(who, "�㱻Ѫħҧ���ˣ��˿ڿ�ʼ��ԡ�\n");
        who->start_busy(3);
    	who->affect_by("xuedu",
    		       ([ "level" : 100,
    			  "id"    : query("id"),
    			  "duration" : 100,]));
    }
    else
    {
        tell_object(who, "�����Ա�һ�㣬Ѫħ���˸��ա�\n");
    }
}