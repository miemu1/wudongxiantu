// person used in quest

#include <ansi.h>

inherit NPC;

#define GO_CMD                   "/cmds/std/go"

void random_move();
int  is_stay_in_room()  { return 1; }

void create()
{
        set_name(HIR "�ɹ�����" NOR, ({"menggu tieqi", "tieqi" }));
        set("gender", "����");
        set("age", 20 + random(20));
        set("long", "����һλ�ɹ���������ǳɼ�˼����ľ�����������͵ľ��ӣ�");
        set("chat_chance", 120);
        set("chat_msg", ({ (: random_move :) }));
        set("no_get", 1);

        // �ɹ�ʿ����־
        set("mgbing", 1);

        set_temp("apply/armor", 400);
        set_temp("apply/damage", 600);
                set_temp("apply/attack", 100000); // ������

                set("str", 40);
                set("int", 10 + random(14));
                set("dex", 10);
                set("con", 15);

                set("combat_exp", 3000000);

                set("max_qi", 6000);
                set("eff_qi", 6000);
                set("qi", 6000);
                set("max_neili",6000);
                set("neili", 6000);
                set("max_jingli", 6000);
                set("jingli", 6000);
                
                set_skill("dodge", 50);
                set_skill("force", 30);
                set_skill("unarmed", 30);
                set_skill("blade", 200);
                
        set_temp("born_time", time());

        set_temp("dest_now", 0); // ���˱�� 0 Ϊ�����˼���ս��

        add_money("gold", 1 + random(2));

        // ���ý�������
                set("gift/level", "���");
                set("gift/exp", 1800 + random(1801));
                set("gift/pot", 1800 + random(1201));
                set("gift/experience", 800 + random(601));

                setup();

                carry_object(__DIR__"obj/menggucloth")->wear(); 
                carry_object("/clone/weapon/gangdao")->wield();
                        if (clonep()) keep_heart_beat();
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
                if (! query("no_total"))
                        XYWAR_D->soldier_die(this_object()->query("route"), 0);
                
                destruct(this_object());
                return;
        }

        // ս������ʱ���н���
        if (XYWAR_D->now_status() != 2)
        {
                if (! query("no_total"))
                        XYWAR_D->soldier_die(this_object()->query("route"), 0);
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
        if (! query("no_total"))
                XYWAR_D->soldier_die(this_object()->query("route"), 0);
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
                if (! query("no_total"))
                        XYWAR_D->soldier_die(this_object()->query("route"), 0);
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
                if (! me->query("env/invisible"))call_out("do_kill", 1 + random(4), me);
        if (playerp(me))me->set("env/combatd",4);
}

void do_kill(object me)
{
        if (! objectp(me))return;
                        
        if (! living(me) || me->query_temp("apply/invisible"))
                 return;

        // ������ÿ�����󶼹�������������Ϊ�˽�Լϵͳ��Դ�͸�Ϊ��ʵ
        if (me->is_fighting() && random(3) == 1)return;

        // ֻ��ͬʱ����һ����
        if (this_object()->is_fighting())return;

        kill_ob(me);
        me->kill_ob(this_object());
}
