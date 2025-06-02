// person used in quest

#include <ansi.h>

inherit NPC;

void random_move();
int  is_stay_in_room()  { return 1; }
void check_time();

void create()
{
        set_name(HIW "�ɹ�ǧ��" NOR, ({"menggu qianfuzhang", "qianfuzhang" }));
        set("gender", "����");
        set("age", 30 + random(20));
        set("long", "����һλ�ɹ�ǧ�򳤣��������������ݣ����а������ȣ���˵����Ӿ�ǰ��һ��������ʦ��");
        set("chat_chance", 70);
        set("chat_msg", ({ (: random_move :) }));
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({ 
                (: command("perform sword.po twice") :),  
                (: command("perform claw.zhua twice") :),  
                (: command("perform claw.quan twice") :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: check_time :),
        }));
        
        set("no_get", 1);

        // �ɹ�ʿ����־
        set("mgbing", 1);
        
        // ���¾Ž�֮����
        set("can_learn/dugu-jiujian/nothing", 1);
        
        set("no_nuoyi", 1);

        set_temp("apply/armor", 3000);
        set_temp("apply/damage",5000);
        set_temp("apply/attack", 100000); // ������

        set("str", 60);
        set("int", 30 + random(14));
        set("dex", 60);
        set("con", 60);

        set("combat_exp", 200000000);

        set("max_qi", 3000000);
        set("eff_qi", 3000000);
        set("qi", 3000000);
        set("max_neili", 90000);
        set("neili", 100000000);
        set("max_jingli", 2000000);
        set("jingli", 2000000);

        set("jiali", 1000);

        set_skill("dodge", 1500);
        set_skill("lingxu-bu", 1500);
        set_skill("force", 1500);
        set_skill("taiji-shengong", 1500);
        set_skill("unarmed", 1500);
        set_skill("sword", 1500);
        set_skill("dugu-jiujian", 1500);
        set_skill("martial-cognize", 1500);
        set_skill("jingluo-xue", 1500);
        set_skill("claw", 1500);
        set_skill("zuoyou-hubo", 1500);
        set_skill("jiuyin-shengong", 1500);

        map_skill("dodge", "jiuyin-shengong");
        map_skill("parry", "dugu-jiujian");
        map_skill("force", "jiuyin-shengong");
        map_skill("sword", "dugu-jiujian");
        map_skill("claw", "jiuyin-shengong");

        prepare_skill("claw", "jiuyin-shengong");

        set_temp("born_time", time());

        set_temp("dest_now", 0); // ���˱�� 0 Ϊ�����˼���ս��

        add_money("gold", 360 + random(100));

        // ���ý�������
        set("gift/level", "ǧ��");
        set("gift/exp", 200000 + random(200001));
        set("gift/pot", 150000 + random(120000));
        set("gift/experience", 46000 + random(47001));

        setup();

        carry_object(__DIR__"obj/menggucloth")->wear(); 
        carry_object("/clone/weapon/changjian")->wield();
        
        if (clonep()) keep_heart_beat();
}

void check_time()
{
        object me = this_object();

        if (! me->is_fighting())return;

        // ͬʱ��������
        set("neili", query("max_neili"));

        if (random(10) == 1)
        {
                me->delete_temp("no_perform");
                me->delete_temp("no_exert");
                me->interrupt_me(me);

                me->add_temp("apply/damage", 20000);
                command("perform sword.po twice");
                me->interrupt_me(me);
                command("perform claw.zhua twice");
                me->add_temp("apply/damage", -20000);

                if (random(2))
                {
                        me->delete_temp("eff/jiuyin-shengong/xin");
                }
        }

        if (me->is_busy())me->interrupt_busy(this_object(),1000); 

        // ��С���ʻָ���Ѫ
        if (random(20) == 1)
        {
                if (me->query("eff_qi") < me->query("max_qi") / 3)me->add("eff_qi", me->query("max_qi") / 5);
                if (me->query("qi") < me->query("max_qi") / 3)me->add("qi", me->query("max_qi") / 5);
        }        
}

int accept_fight(object ob)
{
        command("say �ҿ�û��Ȥ�����棬����ҹ�����");
        return 0;
}

int accept_hit(object ob)
{
        return 0;
}

int accept_ansuan(object ob)
{
        return notify_fail("���˾����Ժøߣ����������֡�\n");
}

int accept_touxi(object ob)
{
        return notify_fail("���˾����Ժøߣ����������֡�\n");
}

void die(object killer)
{
        object dob;             // �������NPC����
        int n;                  // ����ж�Ա��Ŀ
        int exp;                // ��Ҫ�Ϸֵ���Ϊ
        int pot;                // ��Ҫ�Ϸֵ�Ǳ��
        int tihui;              // ��Ҫ�Ϸֵ����
        int weiwang;            // ��Ҫ�Ϸֵ�����
        int score;              // ��Ҫ�Ϸֵ�����

        object *t;              // ɱ���ҵ��˵Ķ����б�
        object tob;
        int i;

        // �ҵ�ɱ����(NPC)���Ǵ����ҵ���
        if (! objectp(dob = killer))
                dob = query_defeated_by();

        if (! dob)
        {
                //XYWAR_D->soldier_die(this_object()->query("route"), 1);
                destruct(this_object());
                return;
        }

        // ս������ʱ���н���
        if (XYWAR_D->now_status() != 2)
        {
                //XYWAR_D->soldier_die(this_object()->query("route"), 1);
                destruct(this_object());
                return;
        }
        
        if (objectp(dob))
        {
                exp = query("gift/exp");
                pot = query("gift/pot");
                tihui = query("gift/experience");

                // ���
                t = dob->query_team();

                if (pointerp(t))n = sizeof(t);

                // ��Ӻ���Ҫ�Ϸ���Ϊ
                if (n > 1)
                {
                       exp /= n;
                       pot /= n;
                       tihui /= n;
                }

                if (exp < 1)exp = 1;
                if (pot < 1)pot = 1;
                if (tihui < 1)tihui = 1;
                                
                if (pointerp(t))
                {                                                
                        /// 999 ������õ����⽱��������������
                        foreach(tob in t)
                        {
                                   if (objectp(tob) && living(tob))
                                   {
                                                     // ����ɱ�б�־����Ϊ���ս�������
                                                     tob->set("xywar/xy_" + sprintf("%d", XYWAR_D->get_ran_num()), pot);

                                                  GIFT_D->delay_bonus(tob,
                                                         ([ "exp"         : exp + ((tob == dob) ? exp : 0),
                                                              "pot"         : pot + ((tob == dob) ? pot : 0),
                                                               "mar"         : tihui + ((tob == dob) ? tihui : 0),
                                                              "prompt"      : "��Ķ������" + name() + "֮��" ]), 999);
                                                                  
                                    }
                        }
                }
                else
                {
                        // ����ɱ�б�־����Ϊ���ս�������
                        dob->set("xywar/xy_" + sprintf("%d", XYWAR_D->get_ran_num()), pot);

                        GIFT_D->delay_bonus(dob,
                            ([ "exp"         : exp,
                               "pot"         : pot,
                               "mar"         : tihui,
                               "prompt"      : "���ڻ���" + name() + "֮��" ]), 999);
                }
        }

        // ��������
        //XYWAR_D->soldier_die(this_object()->query("route"), 1);
        destruct(this_object());

        return;
}

void uncoucious()
{
        die(query_last_damage_from());
}

void random_move()
{
        string dir;
        string route;
        object env;

        if (query_temp("dest_now"))
        {
                //XYWAR_D->soldier_die(this_object()->query("route"), 1);
                destruct(this_object());
                return;
        }

        if (XYWAR_D->dest_status() == 1)
        {
                set_temp("dest_now", 1);
        }

        // �н�·������
        // ��Ҫ������
        route = query("route");

        env = environment(this_object());

        if (! objectp(env))return;
        
        // �����������㳡������������սʧ��
        if (base_name(env) == "/d/xiangyang/guangchang")
        {                        
               XYWAR_D->arrived_center();// ����սʧ��
               return;
        }

        // ����·���б��ƶ�
        if (stringp(route) && XYWAR_D->now_status() == 2)command("go " + route);
}

void init()
{
        object me = this_player();

        if (! living(me) || me->query_temp("apply/invisible"))
                 return;

        // �ɹŲ����໥ս��
        if (me->query("mgbing"))return;                        

        // �ӳ�һ��ʱ�乥��
        // Ϊ������fighting���Ҳ����ʵ
        if (! me->query("env/invisible"))call_out("do_kill", 3 + random(4), me);
        if (playerp(me))me->set("env/combatd",4);
}

void do_kill(object me)
{
        if (! objectp(me))return;
                        
        if (! living(me) || me->query_temp("apply/invisible"))
                 return;

        // ֻ��������EXP��һ�����ϵ����
        if (me->query("combat_exp") < 200000000)return;
        
        // ������ÿ�����󶼹�������������Ϊ�˽�Լϵͳ��Դ�͸�Ϊ��ʵ
        if (me->is_fighting() && random(3) == 1)return;

        // ֻ��ͬʱ����һ����
        if (this_object()->is_fighting())return;

        kill_ob(me);
        me->kill_ob(this_object());
        
}
