// menwei

inherit NPC;

void create()
{
	set_name("����", ({ "men wei", "wei"}));
	set("long", 
        "�����������ҵ��������Ա����������ҿ�ν���겻����\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);

        set("combat_exp", 700000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("sword", 500);
        set_skill("blade", 300);    
        set_skill("strike", 300);
	create_family("��������", 10, "�Ҷ�");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
