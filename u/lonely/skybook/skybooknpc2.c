#include <ansi.h>

#define MEMBER_D "/adm/daemons/memberd"
#define MAX_POINT 100
#define TAOZHUANG_D "/adm/daemons/taozhuangd"
#define DB_D "/adm/daemons/dbd"

inherit NPC;

void damage_all();
void check_weapon();


string *force_list = ({
        "jiuyang-shengong",
        "beiming-shengong",
        "jiuyin-shengong",
        "xiantian-gong",
        "hunyuan-yiqi",
        "shennong-xinjing",
        "yijinjing",
        "linji-zhuang",
        "xiuluo-yinshagong",
        "zhanshen-xinjing",
        "bluesea-force",
        "huagong-dafa",
        "never-defeated",
        "surge-force",
        "yijin-duangu",
        "bingxin-jue",
        "hanbing-zhenqi",
        "kuihua-mogong",
        "shenzhaojing",
        "zihui-xinfa",
        "shenghuo-shengong",
        "bahuang-gong",
        "yunv-xinjing",
        "xuanming-shengong",
        "jiuyin-hamagong",
        "emei-jiuyang",
        "shaolin-jiuyang",
        "wudang-jiuyang",
        "kurong-changong",
        "xuedao-dafa",
        "hama-gong",
        "liangyi-shengong",
        "xiaowuxiang",
});

string *dodge_list = ({
        
        "lingbo-weibu",
        "zhuangzi-wu",
        "beidou-xianzong",
        "shexing-lifan",
        "tan-tui",
        "piaoyi-bu",
        "yiwei-dujiang",
        "shaolin-shenfa",
        "ruying-suixingtui",
        "xuanfeng-tui",
        "tiyunzong",
        "sixiang-bufa",
        "zhaixing-gong",
        "beidou-xianzong",
        "feixing-shu",
        });

string *unarmed_list = ({
        "dafumo-quan",
        "taiji-quan",
        "sad-strike",
        "xuangong-quan",
});


// ����������OB���ã���ʼ��BOSS
void init_data(string skybookOBPath, string sGender, string sID,string sName,int nHp,int nDamage,int nDefense,string sSkill,int nSkLevel,string sType, string sNandu)
{
        
                        string skforce, skdodge, skunarmed;
                        string sWeapon;
                        mixed *mFile;
                        string *performs;
                        int i;
                        
                        set("age", 9999);
                        set("gender", sGender);
                        set("skybookOBPath", skybookOBPath);
                        set_name(sName, ({ sID }));
                        set("title", HIY + query("books") + NOR);
                        
                        set_temp("apply/attack", 100000000);
                        set_temp("apply/unarmed_damage", nDamage); 
                        set_temp("apply/damage", nDamage);
                        set_temp("apply/armor", nDefense);
                        
                  set("max_qi", nHp);
                  set("eff_qi", nHp);
                        set("qi", nHp); 
                        
                
                  set_skill("unarmed", nSkLevel);
                  set_skill("finger", nSkLevel);
                  set_skill("claw", nSkLevel);
                  set_skill("strike", nSkLevel);
                  set_skill("hand", nSkLevel);
                  set_skill("cuff", nSkLevel);
                  set_skill("parry", nSkLevel);
                  set_skill("dodge", nSkLevel);
                  set_skill("force", nSkLevel);
                  set_skill("sword", nSkLevel);
                  set_skill("blade", nSkLevel);
                  set_skill("zuoyou-hubo", 2500);
                         
                        
                        // ���ѡȡ�ڹ����Ṧ��ȭ��
                        skforce = force_list[random(sizeof(force_list))];
                        skdodge = dodge_list[random(sizeof(dodge_list))];
                        skunarmed = unarmed_list[random(sizeof(unarmed_list))];
                        
                        set_skill(skforce, nSkLevel);
                        set_skill(skdodge, nSkLevel);
                        set_skill(skunarmed, nSkLevel);
                  set_skill(sType, nSkLevel);
                  set_skill(sSkill, nSkLevel);
                  set_skill("martial-cognize", nSkLevel);
                  
                  map_skill("force", skforce);
                  map_skill("dodge", skdodge);
                  map_skill("unarmed", skunarmed);
                  map_skill("parry", sSkill);
                  map_skill(sType, sSkill);     

                        if (sType == "sword" || sType == "blade" || sType == "whip")
                        {
                
                                        if (sType == "sword")sWeapon = "changjian";
                                        if (sType == "blade")sWeapon = "blade";
                                        if (sType == "whip")sWeapon = "changbian";      
                                        // ����
                                        carry_object("/clone/weapon/" + sWeapon)->wield();
                                        
                                        set("weapon_path", "/clone/weapon/" + sWeapon);
                                        
                                        prepare_skill("unarmed", skunarmed);
                        }
                        else
                        {
                                        prepare_skill(sType, sSkill);
                
                        }
                        
                  // �·�
                  carry_object("/clone/cloth/cloth")->wear();
                        
                        // ��������Ŀ¼ѡȡperform
                        mFile = BACKUP_D->get_dir_by("/kungfu/skill/" + sSkill + "/", -1);
                        
                        for (i = 0; i < sizeof(mFile); i ++)
                        {
                                        if (mFile[i][0] == "perform" && mFile[i][1] == -2) // ����performĿ¼
                                        {
                                                        mFile = BACKUP_D->get_dir_by("/kungfu/skill/" + sSkill + "/perform/", -1);
                                                        break;
                                        }
                        }
                        
                        performs = ({});
                
                        for (i = 0; i < sizeof(mFile); i ++)
                        {
                                        if (mFile[i][1] != -2)
                                                performs += ({ (: perform_action,  sType + "." +  replace_string(mFile[i][0], ".c", "")  :) });
                        }
                        // yun perform
                        set("chat_chance_combat", 120);
                  set("chat_msg_combat", performs + ({ 

                        (: exert_function, "powerup" :), 
                        (: exert_function, "shield" :), 
                        (: exert_function, "recover" :),   
                        (: exert_function, "dispel" :), 
                        (: check_weapon :),

                        }));
                        

                        set("env", environment(this_object()));
                        
                        setup();
}

void create()
{
        set_name("NONE", ({ "SKYBOOKOB" }) );

        set("str", 800);
        set("int", 800);
        set("con", 800);
        set("dex", 800);

        set("shen", 0);

                                set_temp("apply/qy", 70);  // ����
                                set_temp("apply/fy", 70);  // ��Ե      
                        
                                set("scborn/ok", 1);
                        
                        
                          set("max_jing", 1000000000);
                          set("jing", 1000000000);
                          set("eff_jing", 1000000000);
                          set("max_jingli", 1000000000); 
                          set("jingli", 1000000000);  
                        
                          set("neili", 200000000);
                          set("max_neili", 1000000);
                          set("jiali", 50000);
                          set("combat_exp", 2100000000);



        set_skill("martial-cognize", 5000);
        set_skill("literate", 5000);
        set_skill("jingluo-xue", 5000);

                                set("no_nuoyi", 1); // ����Ų��Ӱ��
                                set("can_learn/dugu-jiujian/nothing", 1); //����
                                set("yinyang-shiertian/shier", 12);
                                set("yinyang-shiertian/yinyang", 12);
                                set("yinyang-shiertian/qiankun", 12);



                        set("my_life", 0); // ����Ѫ����10%��ʱ����һ�Σ����øò���Ϊ0

      setup();
}

void heart_beat()
{
                        object ob;
                        int nRan;
                        
                        keep_heart_beat();
                
                        // �������perform yun������
                        if (random(3) == 1)
                        {
                                delete_temp("no_perform");
                                delete_temp("no_exert");
                        }
                        if (random(5) == 1)check_weapon();

                        // ÿ30��ָ���Ѫ
                        if (query("last_full_time") == 0)set("last_full_time", query("create_time"));
                        if (time() - query("last_full_time") >= 30)
                        {
                                        set("last_full_time", time());
                                        
                                        if (query("�Ѷ�") == "������")
                                        {
                                                        nRan = 5 + random(6);
                                        }
                                        else if (query("�Ѷ�") == "������")
                                        {
                                                        nRan = 10 + random(16);
                                        }
                                        else
                                        {
                                                        nRan = 20 + random(11);
                                        }

                                        add("eff_qi", query("max_qi") / 100 * nRan);
                                        if (query("eff_qi") > query("max_qi"))
                                                set("eff_qi", query("max_qi"));
                                        set("qi", query("eff_qi"));
                                        
                                        message_vision(HIG "\nͻȻһ�������֣�$N���ƺ�������������\n", this_object());
                                        
                        }
                        
                        
                        return ::heart_beat();
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

        if (! me->query_temp("weapon") && sizeof(query("weapon_path")))
        {
                ob = new(query("weapon_path"));
                ob->move(me);
                "/cmds/std/wield"->main(me, ob->query("id"));
        }

        if (random(10) == 1)
        {
                me->clear_condition();
        }

        // ��С���ʻָ���Ѫ
        if (random(200) == 1)
        {
                //log_file("qilin", ctime(time()) + " �ɹ��ָ���Ѫ��\n");
                if (me->query("eff_qi") < me->query("max_qi") / 3)me->add("eff_qi", me->query("max_qi") / 5);
                if (me->query("qi") < me->query("max_qi") / 3)me->add("qi", me->query("max_qi") / 5);
        }

        if (me->is_busy())me->interrupt_busy(me); 


                // ������ڵط���������ݻ�
                if (environment(this_object()) != query("env"))
                {
                                destruct(this_object());
                }
                        
        return;
}

void init()
{
        object me;

        me = this_player();
        
        //me->set("env/combatd", 4);
        //if (! wizardp(me))this_object()->kill_ob(me);
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
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("max_qi"));
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("max_jing"));
        me->set("jingli", me->query("max_jingli"));

        me->clear_condition();

        me->interrupt_me(this_object());

        me->delete_temp("no_perform");
        me->delete_temp("no_exert");                            

        set_temp("apply/attack", 10000000);
        set_temp("apply/unarmed_damage", 400000); 
        set_temp("apply/damage", 200000); 
        set_temp("apply/armor", 100000);
        set_temp("apply/qy", 70);  // ����
        set_temp("apply/fy", 70);  // ��Ե              
        me->delete("my_life");

        message_vision(HIG "\n$N" HIG "��̾һ����ȫ��������ʢ����ͻȻ�ָ���ս������\n\n" NOR, me);
        
        return; 
}

int receive_wound(string type, int damage, object who)
{
        object ob, landie;

        object me = this_object();

        if (! who)return 0;
        
        return ::receive_wound(type, damage, who);
        
}

int receive_damage(string type, int damage, object who)
{
        object ob, landie;
        int tzlv;

        object me = this_object();

        if (! who)return 0;

        // ��װ��׷���˺�
        if (objectp(who))
        {
                        tzlv = TAOZHUANG_D->taozhuang_level(who);
                        
                        if (tzlv == 3)// �콾
                        {
                                damage *= 2;
                                this_object()->start_busy(5+random(6));
                                tell_object(HIM "���콾��װ��׷���˺�������æ�ң�\n" NOR);
                        }
                        else if (tzlv == 4)
                        {
                                damage *= 3;
                                start_busy(5+random(6));
                                tell_object(HIM "����˫��װ��׷���˺�������æ�ң�\n" NOR);
                                if (random(10) < 7)
                                {
                                        set_temp("no_perform", 1);
                                        call_out("remove_no_perform", 10);
                                        tell_object(HIC "����˫��װ��׷�ӷ���10�룡\n" NOR);
                                }
                        }
        }

        return ::receive_damage(type, damage, who);
}


void remove_no_perform()
{
        delete_temp("no_perform");
}

void unconcious()
{
         // ��ֱֹ��call_die()
         if (query("qi") > 2000000)
         {
                revive();
                return;
         }

   die(query_last_damage_from());
}

void die(object killer)
{
      object dob;             // �������NPC����                                                                                                                                                          

                        object skybookob;
                        
                             
                        // ��ֱֹ��call_die()
                        if (query("qi") > 2000000)
                        {
                                        revive();
                                        return;
                        }
                
                        // �����δ������������һ��
                        if (query("my_life"))
                        {
                                        new_life();
                                        return;
                        }
                        // ������ڵط������������
                        if (environment(this_object()) != query("env"))
                        {
                                        return;
                        }
                
                  // �ҵ�ɱ����(NPC)���Ǵ����ҵ���
                  if (! objectp(dob = killer))
                    dob = query_last_damage_from();
                        if (! objectp(dob))
                                dob = query_defeated_by();
                                
                        if (! dob)
                        {
                                dob = query("me");
                        }
                

                        // ��ɱ����BOSS
                        if (environment(dob) == query("born_room"))
                        {
                                        if (! objectp(skybookob = find_object(query("skybookOBPath"))))
                                                        skybookob = load_object(query("skybookOBPath"));

                                        // ��ɸ���ͨ��
                                        if (query("nQuest") == dob->query("skybook14/" + query("books") + "/������"))
                                        {       
                                                        int nKilltime, nMintime;
                                                        string sQuest, sZhangjie,sTitle;

                                                        // ��¼�ø������ͨ��ʱ������
                                                        sQuest = dob->query("skybook14/" + query("books") + "/������");
                                                        nMintime = DB_D->query_data("skybook/record/ͨ��ʱ���¼/" + query("books") + "/" + sQuest + "/time");
                                                        nKilltime = time() - query("create_time");
                                                        if (nKilltime < nMintime || nMintime == 0)
                                                        {
                                                                        DB_D->set_data("skybook/record/ͨ��ʱ���¼/" + query("books") + "/" + sQuest + "/time", nKilltime);
                                                                        DB_D->set_data("skybook/record/ͨ��ʱ���¼/" + query("books") + "/" + sQuest + "/id", dob->query("id"));
                                                                        DB_D->set_data("skybook/record/ͨ��ʱ���¼/" + query("books") + "/" + sQuest + "/name", dob->query("name"));

                                                                        sZhangjie = skybookob->get_mSkybook_fuben(sQuest, 0);
                                                                        sTitle = skybookob->get_mSkybook_fuben(sQuest, 1);
                                                                        
                                                                        CHANNEL_D->do_channel(this_object(),"rumor", "��˵" + HIY + dob->query("name")  + "(" + dob->query("id") + ")" HIM "�����ˡ�" + query("books") + "�����顾" + 
                                                                                                       sZhangjie + "��" + sTitle + "�������ͨ�ؼ�¼��" + sprintf("%d", nKilltime) + "�룡\n");
                                                        }
                                                        dob->set("skybook14/" + query("books") + "/������", query("sNextQuest") );
                                                        dob->set("skybook14/" + query("books") + "/��ǰ�½�", query("sNextQuestZhangjie"));
                                                        dob->set("skybook14/" + query("books") + "/��ǰ����", query("sNextQuestTitle"));

                                                        // �������⴦��
                                                        if (query("sNextQuestZhangjie") == "����")
                                                        {
                                                                        skybookob->endskybook(dob);

                                                                        destruct(this_object());
                                                                        return;
                                                        }
                                                        else
                                                        {
                                                                        mapping getmyskills;
                                                                        string *keys_myskills, *get2kskills, ssk;
                                                                        int i;
                                                                        
                                                                        message_vision(HIG + BLINK "\n����ͨ�أ�ʹ��ָ�� " + HIC + "skybook start " + query("books") + HIG " �������� ��\n" NOR, dob, this_object());
                                                        
                                                                        // һ�����������������һ��
                                                                        getmyskills = dob->query_skills();                       
                                                                  if (sizeof(getmyskills) && random(10) < 2)
                                                                  {
                                                                                        keys_myskills = keys(getmyskills);
                                                                                        get2kskills = ({});
                                                                                        for (i = 0; i < sizeof(keys_myskills); i ++)
                                                                                                if (getmyskills[keys_myskills[i]] >= 1500 && ! SKILL_D(keys_myskills[i])->is_fmsk())
                                                                                                                get2kskills += ({keys_myskills[i]});
                                                                
                                                                                        if (sizeof(get2kskills))// ���������Ļ�ø���
                                                                                        {
                                                                                                        ssk = get2kskills[random(sizeof(get2kskills))];
                                                                                                        if (ssk == "martial-cognize" && random(10) < 3)ssk = get2kskills[random(sizeof(get2kskills))]; // ������ѧ�������������ȡһ��
                                                                                                        
                                                                                                        dob->add_skill(ssk,1);
                                                                                                        log_file("0����Ӽ���.log", dob->query("id") + " " + ctime(time()) + " " + ssk + "\n");
                                                                                                        tell_object(dob, HIG "\n��ϲ�㣡����" HIY + CHINESE_D->chinese(ssk) + HIG "�ȼ�����1����\n" NOR);
                                                                                        }
                                                                        }
                                                                        
                                                                        // ����ͨ�ع̶�����
                                                                        GIFT_D->delay_bonus(dob,
                                                                                ([ "exp"      : 200000,
                                                                                   "pot"      : 200000,
                                                                                   "mar"      : 500000,
                                                                                   "prompt"   : "���鸱��ͨ�ؽ���" ]), 999);    
                                                        }
                                        }

                        }
                        destruct(this_object());

                        return ;
}  
