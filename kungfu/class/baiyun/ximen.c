// dongfang.c
//Updated by y111

#include <ansi.h>


inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

string ask_book();
mixed ask_pfm();

void create()
{
	set_name(RED"���Ŵ�ѩ"NOR, ({ "ye gucheng", "ye","gucheng" }) );
    set("nickname", HIY "���ƿ���" NOR);
    set("gender", "����");
    set("shen_type", 1);
    set("age", 33);
    set("long",
        "�����ǰ��Ƴǿ��䡣
\n");
    set("attitude", "peaceful");

    set("per", 21+random(100));
    set("str", 21+random(100));
    set("int", 30+random(100));
    set("con", 26+random(100));
    set("dex", 30+random(100));
	//�Զ�PFM
	set("auto_perform", 1);

    set("inquiry", ([
        "ҹ�³�"   : "�Ǻ� \n",
        "���Ƴ�" : "���ƹ³�\n",
    ]));


    set("qi", 2000000);
    set("max_qi", 200000);
    set("jing", 1000000);
    set("max_jing", 1000000);
    set("neili", 420000);
    set("max_neili", 420000);
    set("jiali", 4000);

    set("combat_exp", 2200000);
    set("score", 0);

        set_skill("force", 2000);
        set_skill("unarmed", 2000);
        set_skill("sword", 50);
        set_skill("parry", 2000);
        set_skill("dodge", 2000);
        set_skill("throwing", 2000);
	
        set_skill("doomforce", 2000);
        set_skill("doomstrike", 2000);
        set_skill("doomsteps", 2000);
		set_skill("doomsword", 2000);
	    set_skill("chuixue-jian",2000);

        map_skill("force", "doomforce");//��ѩ��
        map_skill("unarmed", "doomstrike");//��������
        map_skill("sword", "doomsword");//���촵ѩ��
        map_skill("dodge", "doomsteps");//��ѩ����
    create_family("���Ƴ�", 1, "����");
	
	  set("inquiry", ([
                "��ʦ"        : "��������",
                //"�������"    : (: ask_skill1 :),
        ]));

    set("master_ob",5);
    
	setup();
     carry_object("/clone/weapon/gangjian")->wield();
   
    carry_object("/d/heimuya/obj/yuxiao");
}

 
void attempt_apprentice(object me)
{
        string purename, name, new_name;

       


	

        if ((int)me->query("shen") < 10000)
        {
                command("heng");
                command("say ���ǹ�ɽ���Ƴ��������ʽ����£�Ҳ���ύ����������������֮�ˡ�");
                return;
        }

	
        if ((int)me->query("shen") < -1000)
        {
                command("heng");
                command("say �Ұ��Ƴ��������ʽ����£�������ύ��������֮�ˡ�");
                return;
        }

        command("say �ðɣ���Ȼ���������䣬�Ҿ������㡣");
        command("recruit " + me->query("id"));
}