// This program is a part of NT MudLIB

#include <ansi.h>

inherit BOSS;

void check_weapon();
void check_friend();

void create()
{
        set_name(HIM "��һ��" NOR, ({ "hu yidao"}) );
        set("title", HIR "��������" NOR);
        set("long", HIC "����һ���⺷����ı����󺺣�˫�۾�������\n"
                        "��˵���ĵ���������˫��\n" NOR);

        set("gender", "����");
        set("age", 39);

        set("str", 500);
        set("int", 500);
        set("con", 500);
        set("dex", 500);

        set("shen", 8000000);

        set_temp("apply/attack", 5000);
        set_temp("apply/unarmed_damage", 5000);
        set_temp("apply/damage", 5000);
        set_temp("apply/armor", 60000);
        set_temp("apply/qy", 50);  // ����
        set_temp("apply/fy", 50);  // ��Ե

        set("reborn/times", 1);

        set("max_qi", 21000000);
        set("eff_qi", 21000000);
        set("qi", 21000000);

        set("max_jing", 1000000000);
        set("jing", 1000000000);
        set("eff_jing", 1000000000);
        set("max_jingli", 1000000000);
        set("jingli", 1000000000);

        set("neili", 200000000);
        set("max_neili", 1000000);
        set("jiali", 50000);
        set("combat_exp", 2100000000);

        set_skill("unarmed", 1500);
        set_skill("finger", 1500);
        set_skill("claw", 1500);
        set_skill("strike", 1500);
        set_skill("hand", 1500);
        set_skill("cuff", 1500);
        set_skill("parry", 1500);
        set_skill("dodge", 1500);
        set_skill("force", 1500);
        set_skill("sword", 1500);
        set_skill("blade", 1500);
        set_skill("zuoyou-hubo", 1500);

        set_skill("daojian-guizhen", 1500);
        set_skill("jiuyang-shengong", 1500);
        set_skill("yinyang-shiertian", 1500);
        set_skill("qiankun-danuoyi", 1500);
        set_skill("martial-cognize", 1500);
        set_skill("qiankun-danuoyi", 1500);
        set_skill("lingbo-weibu", 1500);
        set_skill("literate", 1500);
        set_skill("huajia-su", 800);

        //set_skill("jingluo-xue", 1500);

        set("no_nuoyi", 1); // ����Ų��Ӱ��

        map_skill("parry", "qiankun-danuoyi");
        map_skill("force", "yinyang-shiertian");
        map_skill("dodge", "lingbo-weibu");
        map_skill("unarmed", "yinyang-shiertian");
        map_skill("finger", "yinyang-shiertian");
        map_skill("strike", "yinyang-shiertian");
        map_skill("hand", "yinyang-shiertian");
        map_skill("cuff", "yinyang-shiertian");
        map_skill("claw", "yinyang-shiertian");
       // map_skill("sword", "daojian-guizhen");
       // map_skill("blade", "daojian-guizhen");

        prepare_skill("finger", "yinyang-shiertian");
        prepare_skill("unarmed", "yinyang-shiertian");

        // yun perform
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
              //
              (: command("perform sword.ben twice") :),
              (: command("perform sword.ben and sword.tian") :),
              // ����12t
              (: command("perform finger.tian twice") :),
              (: command("perform finger.zhen and finger.jiu") :),

              //(: exert_function, "roar" :),
              (: exert_function, "powerup" :),
              (: exert_function, "shield" :),
              (: exert_function, "recover" :),
              (: exert_function, "dispel" :),
              (: check_weapon :),

        }));

        set("my_life", 1); // ����Ѫ����10%��ʱ����һ�Σ����øò���Ϊ0        

        setup();

        // �·�
        carry_object("/clone/cloth/bupao")->wear();

        // ����
        carry_object("/clone/weapon/anyue-dao")->wield();
}
void init()
{
	
	call_out("findPlayer",5); //Ѱ��
}
//������Ѱ��
void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;
	
	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);
	
	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(5));
}
void heart_beat()
{
        object ob;

        if( !clonep(this_object()) ) return;
        // �������perform yun������
        if (random(3) == 1)
        {
                delete_temp("no_perform");
                delete_temp("no_exert");
        }

        if (random(2) == 1)check_weapon();

        // ���ͬ���״̬
        check_friend();

        return ::heart_beat();
}

void check_friend()
{
        string friend_id;
        object ob, *obs, me, env;
        int i;

        friend_id = "miao renfeng";
        me = this_object();

        if( !(env = environment(me)) ) return;

        ob = present(friend_id, env);
        if (! ob) return;

        me->clean_up_enemy();
        ob->clean_up_enemy();

        // �Һ�ͬ�鲻�������ɱ
        me->remove_enemy(ob);
        me->remove_killer(ob);
        ob->remove_enemy(me);
        ob->remove_killer(me);

        // ���δ��ս���У��鿴ͬ���Ƿ���ս���У�����ڵĻ�����������ͬ��ĵ���
        if (! me->is_fighting() && ob->is_fighting())
        {
                ob->clean_up_enemy();
                obs = ob->query_enemy();
                if (me->is_busy()) me->interrupt_busy(me, 1000);
                if (me->is_busy()) me->interrupt_busy(me);
                if (sizeof(obs))
                {
                        message_vision(HIG "\n$N" HIG "���һ���������֣�С�ģ�һ����Ҳ����\n\n" NOR, me);
                        for(i = 0; i < sizeof(obs); i ++)
                        {
                                me->kill_ob(obs[i]);
                        }
                }
        }

        // ���ͬ���HPС��20%,���ҵ�HP����60%�򱣻��Է�
        if( ob->query("eff_qi" ) <= ob->query("max_qi")/10 &&
            me->query("eff_qi") >= me->query("max_qi")/5*3 )
        {
                if (me->query_temp("guardfor"))return;
                if (me->is_busy())me->interrupt_busy(me, 1000);
                if (me->is_busy())me->interrupt_busy(me);
                command("guard " + friend_id);
        }
}

// �������
void check_weapon()
{
        object me, ob;

        me = this_object();

        // ͬʱ��������
        set("neili", query("max_neili"));

        if (me->is_busy())me->interrupt_busy(me, 1000);

        if (me->is_busy())me->interrupt_me(me);

        if( !me->query_temp("weapon") )
        {
                if( !objectp(ob = present("anyue dao", environment(me))) )
                ob = new("/clone/weapon/anyue-dao");
                ob->move(me);
                "/cmds/std/wield"->main(me, "anyue dao");
        }
        if( !me->query_temp("secondary_weapon") )
        {
                if( !objectp(ob = present("fengshen jian", environment(me))) )
                ob = new("/clone/weapon/fengshen-jian");
                ob->move(me);
                "/cmds/std/wield"->main(me, "fengshen jian");
        }

        if (random(5) == 1)
        {
                me->delete_temp("no_perform");
                me->delete_temp("no_exert");

                me->add_temp("apply/damage", 5000);
                if (random(3) == 1)
                        command("perform sword.ben twice");
                else
                        command("perform sword.ben and sword.tian");
                me->add_temp("apply/damage", -5000);

                if (random(2))
                {
                        me->delete_temp("eff/jiuyin-shengong/xin");
                }
        }

        if (random(10) == 1)
        {
                me->clear_condition();
        }

        // ��С���ʻָ���Ѫ
        if (random(1000) == 1)
        {
                if (query("eff_qi") < query("max_qi") / 3) add("eff_qi", query("max_qi") / 5);
                if (query("qi") < query("max_qi") / 3) add("qi", query("max_qi") / 5);
        }

        if (me->is_busy())me->interrupt_busy(me);

        if (! me->is_fighting() || random(5) == 1)
        {
                command("yun powerup");
        }

        return;
}

int accept_hit(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

void new_life()
{
        object me = this_object();

        // ������Ѫ
        me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("jing",me->query("max_jing"));
        me->set("jingli",me->query("max_jingli"));

        delete_temp("no_perform");
        delete_temp("no_exert");

        me->clear_condition();

        me->interrupt_me(this_object());

        set_temp("apply/attack", 1200000);
        set_temp("apply/unarmed_damage", 150000);
        set_temp("apply/damage", 150000);
        set_temp("apply/armor", 100000);
        set_temp("apply/qy", 70);  // ����
        set_temp("apply/fy", 70);  // ��Ե
        me->delete("my_life");

        message_vision(HIG "\n$N" HIG "���һ����Ŀ���ʱ����ɱ�⣡\n\n" NOR, me);

        return;
}

int receive_damage(string type, int damage, object who)
{
        object ob;

        object me = this_object();

        if( !me->query("my_life"))return ::receive_damage(type,damage,who);

        if( me->query("qi")<me->query("max_qi")/10 )
        {
                new_life(); // ����һ��
                return 0;
        }

        return ::receive_damage(type, damage, who);
}

// �������
void check_life()
{
        object env;

        // ���life<=1������
        if (1)
        {
                message_vision(HIR "\n$N" HIR "��̾һ������ʧ��ɽ��֮�� ����\n\n" NOR, this_object());
                // ��¼
                log_file("dongfang_die", "��һ���� " + ctime(time()) + " ��ɱ����\n");

                destruct(this_object());
        }
}

void die(object killer)
{
        object dob;             // �������NPC����
        int n;                  // ���Խ������˵���Ŀ
        int exp;                // ��Ҫ�Ϸֵ���Ϊ
        int pot;                // ��Ҫ�Ϸֵ�Ǳ��
        int weiwang;            // ��Ҫ�Ϸֵ�����
        int score;              // ��Ҫ�Ϸֵ�����
        object *t;              // ɱ���ҵ��˵Ķ����б�
        object tob;
        object ob;
        int mar;                //  ��Ҫ�Ϸֵ����
        int i;

        // ���影����Ʒ�б�
        // ����  X / �ٷ�֮
        mixed oblist = ([
"clone/armor/daojian/kuangfeng"         : 1,
"clone/armor/daojian/lengyue"           : 1,
"clone/armor/daojian/xingshi"           : 1,
"clone/armor/daojian/xingshi2"          : 1,
        ]);

        object gift_ob, gift_ob2, gift_ob3, gift_ob4,gift_ob5;
        string s_gift, *key_s_gift;
        int gift_point, ran;

        if( objectp(ob = previous_object(0)) && sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
              //  full_self();
                return;
        }

        // �����δ������������һ��
        if (query("my_life"))
        {
                new_life();
                return;
        }

        // �ҵ�ɱ����(NPC)���Ǵ����ҵ���
        if (! objectp(dob = killer))
                dob = query_last_damage_from();

        // ����ҵ�
        if (! objectp(dob))dob = query_defeated_by();

        if (! objectp(dob))
        {
                // ����������麯��
                check_life();
                return;
        }

        t = dob->query_team();

        if (objectp(dob) && environment(dob) == environment(this_object()))
        {
                exp = 100000 + random(40000);
                pot = 100000 + random(40000);
                weiwang = 6000 + random(9000);
                score = 6000 + random(6000);
                mar = 12000 + random(12000);
                n = 0;

                n = sizeof(t);
                if (! n || n < 3)
                {
                       exp /= 5;
                       pot /= 5;
                       weiwang /= 3;
                       score /= 3;
                       mar /= 5;
                }

                if (n >= 3)
                {
                        exp /= n;
                        pot /= n;
                        weiwang /= n;
                        score /= n;
                        mar /= n;
                }

        }

        // 100%����Ʒ
        if (1)
        {

                key_s_gift = keys(oblist);

                // 100%���ٱ�һ��
                if (1)
                {
                        s_gift = key_s_gift[random(sizeof(key_s_gift))];
                        gift_point = oblist[s_gift];
                        gift_ob = new(s_gift);
                        if (objectp(gift_ob))
                        {
                                message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + gift_ob->name() + HIC "�����ڵ��ϡ�\n" NOR, this_object());
                                gift_ob->set("who_get/id", "NONE");
                                gift_ob->set("who_get/time", time()+30);//30���ڶ����ܼ�ȡ
                                gift_ob->move(environment(this_object()));
                        }
                        else // ��¼֮
                        {
                                log_file("gift-none", s_gift + " from " + __FILE__ + "\n");
                        }
                }

                // 30%������׷��һ����Ʒ
                if (random(10) < 3)
                {
                        s_gift = key_s_gift[random(sizeof(key_s_gift))];
                        gift_point = oblist[s_gift];
                        gift_ob2 = new(s_gift);
                        if (objectp(gift_ob2))
                        {
                                message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + gift_ob2->name() + HIC "�����ڵ��ϡ�\n" NOR, this_object());
                                gift_ob2->set("who_get/id", "NONE");
                                gift_ob2->set("who_get/time", time()+10);//30���ڶ����ܼ�ȡ
                                gift_ob2->move(environment(this_object()));
                        }
                        else // ��¼֮
                        {
                                log_file("gift-none", s_gift + " from " + __FILE__ + "\n");
                        }
                }
                // 10%������׷��һ��
                if (random(10) == 1)
                {
                        s_gift = key_s_gift[random(sizeof(key_s_gift))];
                        gift_point = oblist[s_gift];
                        gift_ob3 = new(s_gift);
                        if (objectp(gift_ob3))
                        {
                                message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + gift_ob3->name() + HIC "�����ڵ��ϡ�\n" NOR, this_object());
                                //gift_ob3->set("who_get/id", "NONE");
                                //gift_ob3->set("who_get/time", time() + 30); // 30���ڶ����ܼ�ȡ
                                gift_ob3->move(environment(this_object()));
                        }
                        else // ��¼֮
                        {
                                log_file("gift-none", s_gift + " from " + __FILE__ + "\n");
                        }
                }

                if (random(200) == 1)
                {
                        gift_ob5 = new("clone/vip/tianfu");
                        if (objectp(gift_ob5))
                        {
                                message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + gift_ob5->name() + HIC "�����ڵ��ϡ�\n" NOR, this_object());
                                //gift_ob3->set("who_get/id", "NONE");
                                //gift_ob3->set("who_get/time", time() + 30); // 30���ڶ����ܼ�ȡ
                                gift_ob5->move(environment(this_object()));
                        }
                        else // ��¼֮
                        {
                                log_file("gift-none", s_gift + " from " + __FILE__ + "\n");
                        }
                }

                // 30%�ļ��ʵ�����
                if (random(100) < 30)
                {
                        ran = random(100);
                        if(ran>0 && ran<=30)// �콵��������,�콵�����¹�,�콵�����ѥ, 30% ���һ��
                        {
                                switch(random(3))
                                {
                                        case 0:
                                                gift_ob = new("clone/armor/daojian/xingshi3");
                                        break;

                                        case 1:
                                                gift_ob = new("clone/armor/daojian/lengyue2");
                                        break;

                                        default:
                                                gift_ob = new("clone/armor/daojian/kuangfeng2");
                                        break;
                                }
                                if (objectp(gift_ob))
                                {
                                        message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + gift_ob->name() + HIC "�����ڵ��ϡ�\n" NOR, this_object());
                                        gift_ob->set("who_get/id", "NONE");
                                        gift_ob->set("who_get/time", time()+30);//30���ڶ����ܼ�ȡ
                                        gift_ob->move(environment(this_object()));
                                }
                        }							
                        if(ran>30 && ran<=50)// �콵��������,�콵�����¹�,�콵�����ѥ, 20% ���һ��
                        {
                                switch(random(3))
                                {
                                        case 0:
                                                gift_ob2 = new("clone/armor/daojian/xingshi4");
                                        break;

                                        case 1:
                                                gift_ob2 = new("clone/armor/daojian/lengyue3");
                                        break;

                                        default:
                                                gift_ob2 = new("clone/armor/daojian/kuangfeng3");
                                        break;
                                }	
                                if (objectp(gift_ob2))
                                {
                                        message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + gift_ob2->name() + HIC "�����ڵ��ϡ�\n" NOR, this_object());
                                        gift_ob2->set("who_get/id", "NONE");
                                        gift_ob2->set("who_get/time", time()+30);//30���ڶ����ܼ�ȡ
                                        gift_ob2->move(environment(this_object()));
                                }
                        }								
                        if(ran>50 && ran<=55)// �콵����Ƥ���� 5% ���һ��
                            {
                                gift_ob3 = new("/clone/armor/daojian/renpiyi");

                                if (objectp(gift_ob2))
                                {
                                        message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + gift_ob3->name() + HIC "�����ڵ��ϡ�\n" NOR, this_object());
                                        gift_ob3->set("who_get/id", "NONE");
                                        gift_ob3->set("who_get/time", time()+30);//30���ڶ����ܼ�ȡ
                                        gift_ob3->move(environment(this_object()));
                                }
                            }
                        }
                }
        

        // �������
        check_life();

        return ;
}
