// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����ѩ", ({"fu hongxue", "fu", "hongxue"}));
        set("gender", "����");
        set("age", 26);
        set("shen_type", -1);
        set("long", "һ�����ͨ��װ�������˺��Ѱ����ʹ��������ĸ���ѩ��ϵ��һ��\n");
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
        set_skill("cuff", 280);
        set_skill("moshen-quanfa", 280);
        set_skill("sword", 280);
        set_skill("moshen-jianfa", 280);
        set_skill("blade", 280);
        set_skill("moshen-daofa", 280);
        set_skill("mingyue-blade", 280);
        set_skill("parry", 250);
        set_skill("literate", 210);
        set_skill("medical", 200);
        set_skill("mojiao-medical", 200);

        map_skill("force", "chiyou-kuangzhanjue");
        map_skill("dodge", "jiutian-xiaoyaobu");
        map_skill("strike", "moshen-zhangfa");
        map_skill("cuff", "moshen-quanfa");
        map_skill("sword", "moshen-jianfa");
        map_skill("blade", "mingyue-blade");
        map_skill("parry", "mingyue-blade");

        prepare_skill("strike", "moshen-zhangfa");
        
        create_family("ħ��", 40, "����");
  
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({
                (: perform_action, "blade.zhan" :), 
                (: perform_action, "blade.tianya" :),                 
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
        command("say �Ҳ���ͽ���㻹���������˰ɣ�");
}


int recognize_apprentice(object ob, string skill)
{
        if (ob->query_skill(skill, 1) >= 180)
        {
                command("say ���ˣ��Ҿͽ��㵽����ɣ��书����"
                        "Ҫ���Լ����о����ǣ�");
                return -1;
        }
                
        if (ob->query_temp("can_learn/fuhongxue/mingyue-blade") &&
            skill == "blade")
                return 1;

        if (ob->query_temp("can_learn/fuhongxue/mingyue-blade") &&
            skill == "mingyue-blade")
                return 1;             

        if (skill == "mingyue-blade")
        {
                if (ob->query("family/family_name") != "ħ��")
                {
                        command("say ���������ԨԴ����ΪʲôҪ�����书��");
                        return -1;
                } 
                                               
                message_vision("$N���˿�$n�����ͷ�����������µ�Ҳû��ʲô��ѧ�ġ�\n",
                               this_object(), ob);
                ob->set_temp("can_learn/fuhongxue/mingyue-blade", 1);
                return 1;
        }

        command("say ��ֻ����һ���������µ�����ɲ�ҪΪ���ҡ�");
        return -1;
}
