//shushan2 by yushu@SHXY 2000.12
inherit NPC;
int max_tea = 20;
void create()
{
	set_name("�Ŵ�ү", ({"old zhang", "zhang"}));
	set("gender", "����" );
	set("age", 70);
	set("long", "һ���Ͳ�Ĵ�ү�����š�\n");
	set("combat_exp", 10000);
	set("attitude", "peaceful");
	set("title", "����");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
       set("per", 20);
	set("max_qi", 200);
	setup();
        carry_object("/clone/cloth/cloth")->wear();
}