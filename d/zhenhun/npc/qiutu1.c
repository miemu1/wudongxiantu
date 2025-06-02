// tufei.c

inherit NPC;
#include <ansi.h>

//�ɱ�����Ʒ�б�
string *random_ob = ({
    "/clone/vip/putao",
	 "/clone/vip/dan_chongmai1",
});

void create()
{	int lvl,q,j;
	lvl = 100 + random(116);
	q = 2000 + random(2001);
	j = 1000;
	set_name(HIG"�Ļ�"NOR, ({ "qiu tu"}) );
	set("gender", "����");
	set("age", 45);
	set("long", "���ǲ��������ꡣ\n");

	set("combat_exp", 1000000+random(3000000));

	set("attitude", "peaceful");
	set("str", 35);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("qi",q );
	set("max_qi", q);
	set("jing", j);
	set("max_jing", j);
	set("neili", 1500);
	set("max_neili", 1500);
	
	set_skill("force", lvl);
	set_skill("taiji-shengong", lvl);
    set_skill("parry", lvl);
    set_skill("dodge", lvl);
    set_skill("tiyunzong", lvl);
    set_skill("sword", lvl);
    set_skill("taiji-jian", lvl);
    set_skill("hand", lvl);
    set_skill("paiyun-shou", lvl);
    set_skill("unarmed", lvl);
    set_skill("taiji-quan", lvl);

    map_skill("parry", "taiji-jian");
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("sword", "taiji-jian");
    map_skill("hand", "paiyun-shou");
    map_skill("unarmed", "taiji-quan");

    prepare_skill("hand", "paiyun-shou");
    prepare_skill("unarmed", "taiji-quan");

    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
            (: exert_function, "powerup" :),
            (: perform_action, "sword.lian" :),
            (: perform_action, "sword.chan" :),
            (: perform_action, "sword.sui" :),
            (: perform_action, "unarmed.zhen" :),
            (: exert_function, "recover" :),
                     }) );
		
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 5);
}

int accept_fight(object me)
{
	command("say �����ⱻ������ô�ã������ڼ���һ�������ˣ�\n");
	kill_ob(me);
	return 1;
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//�����Ʒ
	object ob;
	
	if (random(21) == 1)
	{
		new(id)->move(this_object());
	}
	::die();
}