// guojing.c ����

#include <ansi.h>

inherit NPC;
int ask_rong();
string sign_up();
void random_move();

void create()
{
        set_name("����", ({"guo jing", "guo", "jing"}));
        set("nickname", HIY"����"NOR);
        set("gender", "����");
        set("age", 41);
        set("long", 
                "�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������\n"
                "�����߹֡�ȫ�������ڵ���������ؤ�����߹��͡�����ͯ����\n"
                "��ͨ���˵�ͽ�ܣ���������书��\n"
                "������һ����ɫ���ۣ���̬���࣬�غ����Ŀ��͸��һ������\n"
                "���˲��ɵò���һ������֮�顣\n");
         set("attitude", "peaceful");

        set("chat_chance", 80);
        set("chat_msg", ({          
                (: random_move :),
        }));
                
        set("str", 40);
        set("int", 20);
        set("con", 38);
        set("dex", 25);

            set("no_get", 1);
            set("no_nuoyi", 1);
            
        set("inquiry", ([
                "�ܲ�ͨ" : "��������ܴ���ˣ������ڿɺã�\n",
                "����ͯ" : "�ܴ��һ��������û��������\n",
                "���߹�" : "ʦ�����˳ԣ�����ϲ���档�����棬����Ϊ���ҳԵġ�\n",
                "��ҩʦ" : "������̩ɽ���ˡ��������ĺ����������ײ���β�ġ�\n",
                "һ�ƴ�ʦ" : "���¶Դ�ʦ�����м���\n",
                "ŷ����" : "����϶����������λʦ����һ���������ˣ������������ݡ�\n",
                "����"   : "�ض����ҵİ��ޣ�������������\n",
                "�ض�"   : "�ض������ض��ˡ�������ô����\n",
                "��ܽ"   : "���Ů�����ֱ��ֲ�������\n",
                "����"   : "��������������Ⱳ���ֶ��򡣵�Ը���ܿ���һ����\n",
                "����²" : "�����ҵ�С���ӡ�\n",
                "���"   : "����ȷʵ�г�Ϣ��\n",
                "����"   : "����������а�ʦ֮�ꡣ\n",
                "�𴦻�" : "������屡���죬������ܡ�\n",
                "�����" : "�����Ҵ�ʦ����\n",
                "���"   : "�����Ҷ�ʦ����\n",
                "������" : "��������ʦ����\n",
                "��ϣ��" : "��������ʦ����\n",
                "�Ű���" : "��������ʦ����\n",
                "ȫ��" : "��������ʦ����\n",
                "��СӨ" : "��������ʦ����\n",
                "ؤ��"   : "ؤ��Ӣ�ۼ������ˣ�����������������ǡ�\n",
                "��ʦ"   : "�����ɹ���Χ��������������������ͽ����\n",
                "����"   : (: sign_up :),
                "ɱ�ɹ�����" : (: sign_up :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({ 
                        (: perform_action, "strike.fei" :),
                        (: perform_action, "strike.hui" :),
                        (: perform_action, "strike.qu" :),
                        (: perform_action, "strike.zhen" :),
                        (: exert_function, "shield" :),
                        (: exert_function, "powerup" :),
                        (: exert_function, "recover" :),                        
        }));
        
        set("qi", 600000);
        set("max_qi", 600000);
        set("jing", 600000);
        set("max_jing", 600000);
        set("neili", 120000);
        set("max_neili", 120000);
        set("jiali", 200);
        
        set("combat_exp", 40000000);
        set("score", 200000);
         
        set_skill("force", 1200);                // �����ڹ�
        set_skill("huntian-qigong", 1200);        // ��������
        set_skill("strike", 1200);                // ����ȭ��
        set_skill("xianglong-zhang", 1200);        // ����ʮ����
        set_skill("dodge", 1200);                // ��������
        set_skill("jinyan-gong", 1200);                // ���㹦
        set_skill("parry", 1200);                // �����м�
        set_skill("feixu-jin", 500);
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "dragon-strike");
        
        prepare_skill("strike", "xianglong-zhang");
        
        setup();
        
        carry_object("/clone/misc/cloth")->wear();
        
        if (clonep()) keep_heart_beat();
}

string sign_up()
{
        object me;
        int win_times;
        
        me = this_player();

        if (is_fighting())
                return HIR "�Բ�ס�ˣ�����������æ�ڶԸ��ɹ����ӡ�\n" NOR;
                
        if (! XYWAR_D->sign_up_status())
                return HIR "�Բ�ס�����ڲ��ܱ�����\n" NOR;
        
        if (! me->query_temp("want_sign_up_xiangyang_war"))
        {
                me->set_temp("want_sign_up_xiangyang_war", 1);
                return HIG "���Ƿ���������μ���������ս�����ȷ����������һ�Ρ�\n" NOR;
        }

        if (XYWAR_D->if_sign_up(me->query("id")))
        {
                return HIC "�������±�������֮�Ŀɼѣ���ĳ�ڴ�л���ˣ�\n" NOR;
        }

        command("nod");
        command("say �úúã��Ҵ�������˰���֮ʿ�����Ὣ�ɹ�����������ԭ��");
        command("haha");

        XYWAR_D->sign_up(me->query("id"));
        XYWAR_D->xywar_message(me->name() + "(" + me->query("id") + ")" HIG "�ѱ���������������ս��Ŀǰ���� " + 
                                     CHINESE_D->chinese_number(XYWAR_D->n_sign_up()) + " ��������ʿ�μӿ����ɹž���\n" NOR);

        tell_object(me, HIG "���Ѿ��ɹ������μӱ��ε���������ս��\n" NOR);
        tell_object(me, HIR "ע�⣬��������ս�������������ߣ������Զ�ȡ�������ʸ�\n" NOR);

        tell_object(me, HIC "\n��������90%�Ѿ�������ɣ���������90%���ʲ�����κ���ʧ��\n" NOR);
        
        XYWAR_D->set_no_die(me);

        // ɾ����ǰ������ִ���־        
        win_times = me->query("xywar/win");
        me->delete("xywar");
        me->set("xywar/win", win_times);
        me->save();

        return "��������������\n";

}


void die()
{

        XYWAR_D->guojing_message(HIR "������ʿ�ǣ���ĳȥҲ����������������������" NOR);
        XYWAR_D->xywar_message("���������ֿ��ɹ����ӣ�����ս������������һ����Ϊ�ֿ��ɹ���������������ĥ��Ĺ��ף�");
        XYWAR_D->guojing_die();
        destruct(this_object());
}

void uncoucious()
{
        die();
}

void init()
{
        object me = this_player();
        object env;
        env = environment(this_object());
        
        if (base_name(env) == "/d/xiangyang/guangchang")
                call_out("do_hello", 3, me);
        
        //����ɱ�ɹű�
        if (me->query("mgbing"))kill_ob(me);

}

void do_hello(object me)
{
        if (! objectp(me))return;
                
        if (environment(me) != environment(this_object()))return; 
        
        if (! XYWAR_D->sign_up_status())return;
        
        tell_object(me, HIG "\n��������˵������λ" + RANK_D->query_respect(me) + 
        "����μ���������ս��Ϊ�����ɹ����Գ�һ������\n"
        "���Ը��μ���������ս�����Ҵ��� " HIR "����" HIG " �������Ϣ�ɣ�\n" NOR); 
}

void heart_beat()
{
        if (XYWAR_D->dest_status() == 1)
        {
                destruct(this_object());
                return;
        }
        
        return ::heart_beat();
}

void random_move()
{
        string route;
        object env;
        string max_route;
        mapping doors;
                
        if (query_temp("dest_now"))
        {
                                
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

        // �����������㳡������ѡ��
        if (base_name(env) == "/d/xiangyang/guangchang" && XYWAR_D->if_guojing_moved())
        {
                max_route = XYWAR_D->max_min_n_soldier("max");
                doors = XYWAR_D->get_doors();
                this_object()->move(doors[max_route]);

                // �����ƶ�����
                set("route", XYWAR_D->re_poision(max_route));
                return;
        }

        // ����·���б��ƶ�
        if (stringp(route) && XYWAR_D->now_status() == 2)command("go " + route);
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("xywar/win") < 6)
        {
                tell_object(ob, HIG "��������˵������������֮�Ĳ��㣬��ĳ�ɲ���óȻ������С�\n" NOR);
                return -1;
        }

        if (ob->query_skill("jiuyin-shengong", 1) < 1)
        {
                tell_object(ob, HIG "��������˵�������������񹦶����ᣬ��������������İ��\n" NOR);
                return -1;
        }
        
        if (ob->query_skill("feixu-jin", 1) < 400)
        {
                tell_object(ob, HIG "��������˵��������Ŀǰ�Է���������Ϊ���������Խ�һ��������\n" NOR);
                return -1;
        }

        return 1;
}
