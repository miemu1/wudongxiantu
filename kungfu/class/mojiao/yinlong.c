// This program is a part of NITAN MudLIB

#include <ansi.h>
#include "mojiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
        set_name("����", ({"yin long", "yin", "long"}));
        set("title", "ħ�̳���");
        set("gender", "����");
        set("age", 52);
        set("shen_type", -1);
        set("long", "��ɫ��װ��������ɫ��ߵ��ˣ������Ʈ������ɫ�ĳ�������ˣ�����֪������\n"
                    "һ�����ˣ�һ�����ˡ������й����εġ����˵�����͸�������ʹ�˲���ð������\n");
        set("attitude", "peaceful");

        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 20000);
        set("max_qi", 20000);
        set("jing", 10000);
        set("max_jing", 10000);
        set("neili", 130000);
        set("max_neili", 130000);
        set("jiali", 3000);

        set("combat_exp", 150000000);
        set("score", 0);

        set_skill("force", 280);
        set_skill("moshen-xinfa", 280);
        set_skill("chiyou-kuangzhanjue", 250);
        set_skill("dodge", 280);
        set_skill("moshen-bufa", 280);
        set_skill("jiutian-xiaoyaobu", 250);
        set_skill("strike", 280);
        set_skill("moshen-zhangfa", 280);
        set_skill("yinlong-shou", 280);
        set_skill("cuff", 280);
        set_skill("moshen-quanfa", 280);
        set_skill("sword", 280);
        set_skill("moshen-jianfa", 280);
        set_skill("blade", 280);
        set_skill("moshen-daofa", 280);
        set_skill("longteng-daofa", 280);
        set_skill("parry", 250);
        set_skill("literate", 210);
        set_skill("medical", 500);
        set_skill("mojiao-medical", 500);

        map_skill("force", "chiyou-kuangzhanjue");
        map_skill("dodge", "jiutian-xiaoyaobu");
        map_skill("strike", "yinlong-shou");
        map_skill("cuff", "moshen-quanfa");
        map_skill("sword", "moshen-jianfa");
        map_skill("blade", "longteng-daofa");
        map_skill("parry", "longteng-daofa");

        prepare_skill("strike", "yinlong-shou");
        
        create_family("ħ��", 40, "����");
  
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuang" :), 
                (: exert_function, "recover" :),
        }) );

        set_temp("apply/attack", 280);
        set_temp("apply/damage", 280);
        set_temp("apply/unarmed_damage", 280);
        set_temp("apply/armor", 280);
                        
        set("master_ob", 5);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
        add_money("silver",70);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))  return;

        if ((int)ob->query_skill("moshen-xinfa", 1) < 120) 
        {
                command("say ���̵��ڹ��ķ��㻹û���ã���Ҫ���¿๦���У�");
                return;
        }
        
        command("recruit " + ob->query("id"));
}
/*
int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yinlong-shou/duo",
                           "name"    : "����",
                           "sk1"     : "yinlong-shou",
                           "lv1"     : 200,
                           "dodge"   : 200,
                           "gongxian": 1000,
                           "shen"    : -50000, ]));
                break;

        case "�ھ�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/longteng-daofa/teng",
                           "name"    : "�ھ�",
                           "sk1"     : "longteng-daofa",
                           "lv1"     : 200,
                           "dodge"   : 200,
                           "gongxian": 1000,
                           "shen"    : -50000, ]));
                break;
                
        default:
                return 0;
        }
}
*/