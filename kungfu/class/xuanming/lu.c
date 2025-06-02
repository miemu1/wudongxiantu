

// shilling 97.2

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "xuanming.h"

void create()
{
        set_name("¹�ȿ�", ({ "luzhang ke", "luzhang", "ke" }));
        set("gender", "����");
        set("shen_type", -1);
        set("age", 52);
        set("str", 30);
        set("con", 38);
        set("int", 20);
        set("dex", 26);
        set("max_qi", 5400);
        set("max_jing", 2400);
        set("qi", 5400);
        set("jing", 2400);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 220);
        set("combat_exp", 2200000);

        set_skill("force", 260);
        set_skill("xuanming-shengong", 260);
        set_skill("dodge", 240);
        set_skill("strike", 260);
        set_skill("lingxu-bu", 260);
        set_skill("hexing-bifa", 260);
        set_skill("strike", 260);
        set_skill("feihua-zhang", 260);
        set_skill("xuanming-zhang", 260);
        set_skill("cuff", 260);
        set_skill("piaofeng-quan", 260);
        set_skill("parry", 240);
        set_skill("claw", 240);
        set_skill("dulong-shenzhua", 240);
        set_skill("sword", 220);
        set_skill("martial-cognize", 200);
        
        map_skill("staff",  "lutou-zhang");
        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "xuanming-shengong");
        map_skill("dodge",  "liuying-bu");
        map_skill("parry",  "xuanming-zhang");
        map_skill("cuff",  "piaofeng-quan");
        map_skill("claw", "dulong-shenzhua");

        prepare_skill("strike", "xuanming-zhang");

        create_family("��ڤ��", 2, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.zhe" :),
                (: perform_action, "strike.lang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "���޼�"    :   "�ߣ���С���Ŵλ��Ҵ��£��ҷ�ɱ�������ɣ�\n",
                "����"      :   "��Ѿͷ��ƶ�ˣ��������壬�����ֵ�Ϊ������������\n",
                "�������"  :   "�����Ҷ�ʦ���������ʲô��\n",
                "�ױ���"    :   "������ʦ�ܣ����Ǵ�С����ʦ��ѧ�գ���ͬ���㡣\n",
        ]));

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);
        setup();

        carry_object("/clone/cloth/baipao")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if(ob->query("shen")<-20000 )
        {
                command("say �ߣ�������һ��������Ȼ�������Ҿ�������");
                return;
        }

        if (ob->query_skill("minggu-xinfa", 1) < 120)
        {
                command("say ��ڤ���ķ�����㣬���Ǹ���ʦ�ܶ���ϰ��ϰ�ɣ�");
                return ;
        }

        if (ob->query_skill("strike", 1) < 120)
        {
                command("say ������Ʒ���Ϊ���������Ժ����ѧϰ����ڤ�Ⱦ�ѧ��ڤ���ƣ�");
                return ;
        }

        command("nod");
        command("say �ã��ã������Ҿ�����Ϊ���ӡ�");
        command("recruit "+ob->query("id"));
}

