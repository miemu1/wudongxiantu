// qi.c �ݳ���

#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_DEALER;

int do_answer();

void create()
{
	set_name("�Ʊ���", ({ "tang bingbing", "tang", "bingbing" }) );
	set("title",HIC "���Ű���ר����   ����" NOR);

	set("gender", "����");
	set("age", 48);
	set("str", 100);
	set("long",
		"��������ר����������С���ӣ��洫�İ���ר����ĸ����ˡ�\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("higgling", 50);	
	set_temp("apply/damage", 15);

	set("combat_exp", 800000);
	set("attitude", "friendly");

	set("vendor_goods", ([
                "/d/tangmen/obj/fhshi":100,
                "/d/tangmen/obj/tiejili":100,
                "/d/tangmen/obj/feidao":100,
                "/d/tangmen/obj/qinglianzi":100,
	]));

	setup();
	set_max_encumbrance(100000000);
}

void init()
{
        add_action("do_buy", "buy");
	add_action("do_list", "list");
        add_action("do_drop", "drop");
        add_action("do_look", ({"guankan", "kan"}));
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) 
        {
                case 0:
                        say( HIC"�Ʊ���Ц�����˵������λ" + RANK_D->query_respect(ob)+ "������������\n"NOR);
                        break;
                case 1:
                        say( HIG"�Ʊ������˴��֣�˵������λ" + RANK_D->query_respect(ob)+ "�������ʲô����\n"NOR);
                        break;
        }
}
