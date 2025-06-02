 // ouyangfeng.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "�����ǰ���ɽׯ�����ųơ���������ŷ���档����������\n"
                    "�����⺷����Ȼ�ܵ�������ƭ��ѧϰ�ˡ������澭������\n"
                    "����ħ��һ�ȱ�þ�����ң�����������Ȼ�ָ���������\n"
                    "ʤ������\n");
        set("title", "�������ɽׯ��");
        set("gender", "����");
        set("age", 53);
        set("nickname", HIR "����" NOR);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set("str", 32);
        set("int", 34);
        set("con", 34);
        set("dex", 32);

        set("qi", 260000);
        set("max_qi", 260000);

        set("jing", 260000);
        set("max_jing", 260000);
        set("jingli", 260000); 
        set("max_jingli", 260000); 

        set("neili", 20000); 
        set("max_neili", 20000); 
        set("jiali", 600); 
        set("combat_exp", 40000000);

        set_skill("force", 540);
        set_skill("unarmed", 540);
        set_skill("dodge", 540);
        set_skill("parry", 540);
        set_skill("cuff", 540);
        set_skill("finger", 540);
        set_skill("training", 500);          

        set_skill("jiuyin-hamagong",540); 
        set_skill("baituo-xinfa", 540);          
 
        set_skill("staff", 540);
        //set_skill("training", 340);
        set_skill("poison", 500);

        set_skill("shedu-qiqiao", 540);
        set_skill("hamagong", 540);
        set_skill("baituo-xinfa", 540);
        set_skill("chanchu-bufa", 540);
        set_skill("lingshe-quan", 540);
        set_skill("lingshe-zhangfa", 540);
        set_skill("baibian-daxue", 540);
        set_skill("guzheng-jifa", 520);
        set_skill("xiyu-tiezheng", 520);
        set_skill("wushe-qu", 520);
        set_skill("literate", 580);
        set_skill("medical", 560);
        set_skill("baituo-michuan", 560);
        set_skill("martial-cognize", 520);

        map_skill("dodge", "chanchu-bufa");
        map_skill("force", "jiuyin-hamagong"); 
        map_skill("unarmed", "jiuyin-hamagong"); 
        map_skill("cuff", "lingshe-quan");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("staff", "lingshe-zhangfa");
        map_skill("finger", "shedu-qiqiao");
        map_skill("poison", "shedu-qiqiao");
        map_skill("medical", "baituo-michuan");
        map_skill("guzheng-jifa", "xiyu-tiezheng");


        prepare_skill("unarmed", "jiuyin-hamagong"); 

        create_family("ŷ������", 5, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.qian" :),
                (: perform_action, "staff.bite" :),  
                (: perform_action, "unarmed.puji" :),  
                (: perform_action, "unarmed.zhen" :), 
                (: perform_action, "unarmed.puji" :), 
                (: exert_function, "yijin" :), 
        }));


        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);


        setup();
        carry_object("/d/baituo/obj/lingshezhang")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("d/baituo/obj/tiezheng");
        add_money("silver", 10);
}
void unconcious()
{
        die();
}   
