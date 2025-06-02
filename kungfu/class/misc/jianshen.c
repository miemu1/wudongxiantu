#include <ansi.h>
inherit NPC;

void create()
{
       // set_name(HIY "����" NOR, ({ "jianshen" }) );

        set("gender", "����");
        set("age", 35);

        // yun perform
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({ 
              // �����ɾ�
              (: command("perform sword.duanshui") :), 
              (: command("perform sword.jueming") :),
              (: command("perform sword.wanjian") :), 

              (: exert_function, "powerup" :), 
              (: exert_function, "shield" :), 
              (: exert_function, "recover" :),
              (: exert_function, "dispel" :),
        }));

        //setup();

}


void init_npc(object me)
{
        object env, ob;
        
        mapping map_status, hp_status, my;
        string *mname;
        int i, temp;
        int percent;

        ob = this_object();
        env = environment(me);

        // ���ó���ʱ��
        ob->set("start_time", time());
        // ���ó����ص�
        ob->set("start_place", env);
        // ���ù���
        ob->set("owner",me->query("id"));
		ob->set_leader(me);

        set_name(HIB+me->name()+HIB"�Ľ���"NOR,({me->query("id")+"jianshen"}));
        set("long", HIM "��˵���ɷ�������������һ���̶�\n"
                        "����Դ�����ٻ�����\n" NOR);

        // ���ðٷֱ�
        if (me->query_skill("xianfeng-spells") >= 3000)
        {
                percent = 120;
        }
        else if (me->query_skill("xianfeng-spells") >= 2500)
        {
                percent = 110;
        }       
        else if (me->query_skill("xianfeng-spells") >= 2000)
        {
                percent = 100;
        }
        else if (me->query_skill("xianfeng-spells") >= 1500)
        {
                percent = 98;
        }
        else if (me->query_skill("xianfeng-spells") >= 1000)
        {
                percent = 96;
        }
        else if (me->query_skill("xianfeng-spells") >= 950)
        {
                percent = 94;
        }
        else if (me->query_skill("xianfeng-spells") >= 900)
        {
                percent = 92;
        }
        else if (me->query_skill("xianfeng-spells") >= 800)
        {
                percent = 90;
        }
        else if (me->query_skill("xianfeng-spells") >= 600)
        {
                percent = 88;
        }
        else if (me->query_skill("xianfeng-spells") >= 300)
        {
                percent = 86;
        }
        else if (me->query_skill("xianfeng-spells") >= 200)
        {
                percent = 84;
        }
        else
        {
                percent = 82;
        }
        
        // ��������
        percent -= 20;
        
        // ���ü���     
        if (mapp(map_status = me->query_skill_map()))
        {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                {
                       // ���û�������
                       ob->set_skill(mname[i], me->query_skill(mname[i], 1) * percent / 100); 
                       // ���ü�������
                       ob->set_skill(map_status[mname[i]], me->query_skill(map_status[mname[i]], 1) * percent / 100);
                       // ��������
                       ob->map_skill(mname[i], map_status[mname[i]]);
                }
        }

        hp_status = me->query_entire_dbase();
        my = ob->query_entire_dbase();

        my["str"] = hp_status["str"] * percent / 200;
        my["int"] = hp_status["int"] * percent / 200;
        my["con"] = hp_status["con"] * percent / 300;
        my["dex"] = hp_status["dex"] * percent / 200;

        my["max_qi"]     = hp_status["max_qi"] / 10000  * percent + 100;
        my["eff_qi"]     = hp_status["eff_qi"] / 10000  * percent + 100;
        my["qi"]         = hp_status["qi"] / 10000  * percent + 100;
        my["max_jing"]   = hp_status["max_jing"] / 1000  * percent;
        my["eff_jing"]   = hp_status["eff_jing"] / 1000  * percent;
        my["jing"]       = hp_status["jing"] / 1000  * percent;
        my["jingli"]     = hp_status["jingli"] / 1000 * percent;
        my["max_jing"]   = hp_status["max_jing"] / 1000  * percent;
        my["max_jingli"] = hp_status["max_jingli"] / 1000  * percent;
        my["max_neili"]  = hp_status["max_neili"] / 5000  * percent;
        my["neili"]      = hp_status["neili"] / 3500  * percent;
        my["jiali"]      = 0;
        my["combat_exp"] = hp_status["combat_exp"] / 500  * percent;

        set_temp("apply/attack",me->query_temp("apply/attack")/2);
        set_temp("apply/damage",me->query_temp("apply/damage")/300*percent);

        ob->reset_action();

        ::setup();

        // �·�
        carry_object("/d/shushan/obj/baipao")->wear();
        // ����
        carry_object("/d/shushan/obj/qixing")->wield();
}

void heart_beat()
{
        object ob, env, owner, obtar;
        object *obs;
        
        keep_heart_beat();
        
        // ÿ3���������1��
        if (time() - query("last_check_heart_beat") >= 6)
        {
                set("last_check_heart_beat", time());
                
                // ������ڳ������䳬��1������ʧ
                env = environment(this_object());
                if (! objectp(env) || env != query("start_place"))
                {
                        if (query("no_in_place") > 0)
                        {
                                // ��ʧ
                                message_vision(HIG "$N" HIG "����׹����֣������Ŵ��۵Ĺ�â��$N" HIG 
                                                   "˲�仯Ϊ���У�\n" NOR, this_object());
                                destruct(this_object());
                                return;
                        }
                        else
                        {
                                add("no_in_place", 1);
                        }
                }
                // �������ʱ������ʧ
                if (time() - query("start_time") > 5*60)
                {
                        message_vision(HIG "$N" HIG "����׹����֣������Ŵ��۵Ĺ�â��$N" HIG 
                                        "˲�仯Ϊ���У�\n" NOR, this_object()); 
                        destruct(this_object());
                        return;
                }
                
                // ���μ��OWNER����������ʧ
                owner = find_player(query("owner"));
                if (! objectp(owner))
                {
                        add("no_find_owner", 1);
                        if (query("no_find_ower") >= 3)
                        {
                                message_vision(HIG "$N" HIG "����׹����֣������Ŵ��۵Ĺ�â��$N" HIG 
                                                "˲�仯Ϊ���У�\n" NOR, this_object()); 
                                destruct(this_object());
                                return;                         
                        }
                }
                else // �������OWNER������Ŀ��
                {
                        if (owner->is_fighting() && ! this_object()->is_fighting())
                        {
                                obs = owner->query_enemy();
                                if (sizeof(obs))
                                {
                                        obtar = obs[random(sizeof(obs))];
                                        message_combatd(HIR "\n$N" HIR "��$n" HIR "������������\n\n" NOR, this_object(), obtar); 
                                        this_object()->kill_ob(obtar);
                                }
                        }
                }
        }
        return ::heart_beat();
}

void init()
{

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

void unconcious()
{
        die();
}

void die(object killer)
{
        message_vision(HIG "$N" HIG "����׹����֣������Ŵ��۵Ĺ�â��$N" HIG 
                                     "˲�仯Ϊ���У�\n" NOR, this_object());
        destruct(this_object());
        return;
}
