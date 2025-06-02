#include <ansi.h>

inherit SKYBOOKNPC;


void create()
{
        set_name("�ݷ�", ({ "qi fang", "qi", "fang"}));

        set("gender", "Ů��");
        set("age", 18);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 27);
        set("con", 25);
        set("dex", 24);
        
        set("skybook", "lianchengjue");

        set("qi", 500000000);
        set("max_qi", 500000000);
        set("jing", 50000000);  
        set("max_jing", 50000000);
        set("jingli", 50000000);        
        set("max_jingli", 50000000);    
        set("neili", 800000);
        set("max_neili", 800000);
        set("jiali", 20000);

        set("combat_exp", 400000000);
        set("score", 3000);
        

        set_skill("force", 1800);
        set_skill("henshan-xinfa", 1800);
        set_skill("dodge", 1800);
        set_skill("henshan-shenfa", 1800);
        set_skill("cuff", 1800);
        set_skill("henshan-quan", 1800);
        set_skill("sword", 1800);
        set_skill("tangshi-jian", 1800);
        set_skill("strike", 1800);
        set_skill("liuyun-zhang" , 1800);
        set_skill("parry", 1800);
        set_skill("literate", 260);
        set_skill("martial-cognize", 220);

        map_skill("strike", "liuyun-zhang");
        map_skill("sword", "tangshi-jian");
        map_skill("force", "zhenyue-jue");
        map_skill("dodge", "henshan-shenfa");
        map_skill("parry", "tangshi-jian");

        prepare_skill("strike", "liuyun-zhang");
        
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.luo" :),
                (: perform_action, "strike.pai" :),
                (: perform_action, "strike.ying" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/attack", 500000);
        set_temp("apply/damage", 400000);
         set_temp("apply/armor", 2000000);
        set_temp("apply/unarmed_damage", 400000);
        
        create_family("��ɽ֧��", 16, "����");

        setup();

        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        command("xixi");
        command("say ������Ĳˣ�ûͷû�Եģ�����ȥ��ʦ����ͷ�ɣ�");
        
        return;
}

void die(object killer)
{
        if (! objectp(killer))return;
        
        
        if (userp(killer) && environment(killer) == environment(this_object())) 
        {
                tell_object(HIY "�㽫�ݷ����г������䣬����ȥ����ʤ�˰��У�\n" NOR);
                
                command("heng");
                command("say ʦ���۸��ң������������ˣ�");

                return;
        }
        
        revive();
        this_object()->remove_enemy(killer);
        killer->remove_enemy(this_object());
        
        return;
}

void unconcious()
{
         // ��ֱֹ��call_die()
         if (query("qi") > 200000)
         {
                revive();
                return;
         }

        die(query_last_damage_from());
}


int accept_fight(object ob)
{
        if (is_fighting())
        {
                message_vision(CYN "$N" CYN "��$n" CYN "�е������ȱ�\n" NOR,
                               this_object(), ob);
                return -1;
        }

        if (ob->query("skybook14/���Ǿ�/������") != 10)
        {
                command("say ��������û�գ�ʦ���㻹��ȥ��ʦ���д�ɡ�");
                return -1;
        }
        
        message_vision(HIW "$N" HIW "Ц����ʦ�磬���� ����\n" NOR, this_object(), ob);

        competition_with(ob);
        return -1;
}

void win()
{
        object ob;
        if (! objectp(ob = query_competitor()))
                return;

        message_vision(CYN "$N" CYN "���˿�$n" CYN "������Ц����ʦ������ˣ�\n" NOR, this_object(), ob);
        ::win();
}

void lost()
{
        object ob;

        if (! objectp(ob = query_competitor()))
                return;

        if (ob->query("skybook14/���Ǿ�/������") != 10)return;

        ob->set("skybook14/���Ǿ�/����״̬", 1);

        tell_object(ob, HIC "\n������ɣ����� skybook start ���Ǿ� �ɼ�������\n" NOR);

        ::lost();
}
