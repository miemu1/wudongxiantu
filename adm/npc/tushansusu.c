// bao.c ������
inherit F_CLEAN_UP;
#include <ansi.h>


inherit NPC;
int ask_baowu();
int ask_gushi();



void create()
{
	object book;

	set_name(HIR"Ϳɽ����"NOR, ({"tu shan", "susu"}));
	set("gender", "Ů��");
	set("age", 12);
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 50000001);
	set("int", 30000006);
	set("con", 50000002);
	set("dex", 200000009);

	set("qi", 100000000);
	set("max_qi", 1000000);
	set("jing", 310000);
	set("max_jing", 310000);
	set("neili", 650000);
	set("max_neili", 650000);
	set("jiali", 50000);

	set("combat_exp", 20);

	set_skill("force", 1);
	set_skill("dodge", 100);
	set_skill("parry", 1);
	set_skill("unarmed", 1000);
	set_skill("literate", 1000);

	set("title", "������");

	set("inquiry", ([
		"����" : (: ask_baowu :),		
	]));

	set_temp("apply/attack", 900000);
	set_temp("apply/dodge", 8000000);
	set_temp("apply/parry", 8000000);
	set_temp("apply/unarmed_damage", 900000);
	set_temp("apply/damage", 300000);
set("chat_msg", ({
	HIR"���մ����������쳾���������Ե��!��\n",NOR
	HIR"����ί���Ͱ͵�˵���³���粻֪��ȥ����?��\n",NOR
    }));
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("show_baowu","chabw");
}



int ask_baowu()
{
	string str,*items,wen,arg;
	object me,liwu;
	me = this_player();
     liwu = new("/clone/gift/meigui");
	if(me->query("wenqin")==1)
	{
		 write(HIR"���ն�ݺݵ�˵�������ǲ��õ�Ŷ��\n"NOR);
	return notify_fail(HIR"�����ǲ��õ�Ŷ��\n"NOR);
	}
	
	write(INPUTTXT(HIR"��ϲ��˭��"NOR, "call me->set(love,$txt#)") + "\n");
  
  
   me->set("wenqin",1);
   write(HIR"���մ���������ף���������ճɾ��������С������͸�����\n"NOR);
   write(HIR"���յ��ͷ�����С������͸�����\n"NOR);
	liwu->move(me);
	return 0;
}



