#include <ansi.h>
inherit "/maze/necropolis/necropolis_npc";

object m_mazeobj;
object get_mazeobj();
object *players = ({});

void set_players(object *ob) {
        players = ob;
}

void add_player(object ob) {
        if(member_array(ob,players)==-1) {
                players += ({ob});
                message_vision(BLU"$N��$n˵����лл��\n"NOR,this_object(),ob);
        } else
                message_vision(BLU"$N��$n˵�������Ѿ���Ӧ��æ���㲻�ᷴ�ڰɣ�\n"NOR,this_object(),ob);
}

void del_player(object ob) {
        players -= ({ob});
}

object* query_players() {
        players -= ({0});
        return players;
}

void smart_fight();

void create()
{
        set_name("��һ", ({ "ding yi","ding"}) );
        set("gender", "����" );
        //set("title", HIC "���幬"NOR);
        set("age", 80);
        set("str", 50);
        set("con", 120);
        set("dex", 22);
        set("int", 50);
        set("class","shaolin");
        set("long",
        ""
        );
        //set("force_factor", 150);
        set("auto_perform", 2);
        set("max_qi", 8000000);
        set("eff_qi", 8000000);
        set("max_jing", 8500000);
        set("eff_jing",8500000);
        set("neili", 8000000);
        set("max_neili", 4500000);
        set("max_jingli", 500000);
        set("combat_exp", 300000000);

        set_skill("force", 1500);
        set_skill("taiji-shengong", 1500);
        set_skill("yinyun-ziqi", 1500);
        set_skill("dodge", 1500);
        set_skill("tiyunzong", 1500);
        set_skill("cuff", 1500);
        set_skill("taiji-quan", 1500);
        set_skill("strike", 1490);
        set_skill("hand", 1490);
        set_skill("parry", 1500);
        set_skill("sword", 1500);
        set_skill("blade", 1460);
        set_skill("taiji-dao", 1460);
        set_skill("taiji-jian", 1500);
        set_skill("taoism", 1500);
        set_skill("literate", 1500);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        map_skill("blade", "taiji-dao");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight():),
        }) );

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "wudang-zhang");
        set_temp("apply/attack", 3000);
        set_temp("apply/defense", 3000);
        set_temp("apply/armor", 6000);
        set_temp("apply/damage", 1500);
        set_temp("apply/unarmed_damage", 1500);
        set_temp("apply/add_weak", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);
        set("drops", ([
                "RA&RARE50" : 50,
                "RA&RARE50" : 50,
                "RA&RARE50" : 50,
                "RA&RARE40" : 100,
                "RA&RARE40" : 100,
                "RA&RARE40" : 100,
        ]));

        setup();
        carry_object("/clone/weapon/sword");
        carry_object("/clone/cloth/cloth")->wear();
}

int is_undead() {
        return 0;
}

void init()
{
        object ob;
        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer", "answer");
        add_action("do_accept", "accept");
        add_action("do_report", "report");
        //add_action("do_help", "help");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( query_temp("�����׽���") || query_temp("��ʼ˵������") || query_temp("����") )
                return;
        message_vision(CYN "$N����������˵������λ" + RANK_D->query_respect(ob) +
                "��������һ����(answer yes/no)\n" NOR, this_object(), ob);
}

int do_answer(string arg) {
        object ob;
        if(arg=="yes") {
                if(query_temp("in_speech"))
                        return 0;
                if(present("tape",environment()))
                        return 0;
                set_temp("��ʼ˵������",1);
                ob = new(__DIR__"obj/taoist_tape");
                ob->move(environment());
                ob->play_sound_0(this_object(),0);
        } else if(arg=="no") {
                message_vision(BLU"$N˵����˭���������ţ���ӷϻ���\n",this_player());
        } else
                return notify_fail("��Ҫ�ش�ʲô��\n");
        return 1;
}

int do_accept(string arg) {
        object ob,env,*team;
        if(!query_temp("�����׽���"))
                return 0;
        if(query_temp("����"))
                return 0;
        if(arg=="yes") {
                if(present("tape",environment()))
                        return 1;
                delete_temp("�����׽���");
                team = this_player()->query_team();
                if(!team || sizeof(team)==0)
                        team = ({this_player()});
                env = environment(this_player());
                for( int i=0;i<sizeof(team);i++ ) {
                        if( team[i] == this_player() )
                                continue;
                        if( environment(team[i]) != env )
                                team[i] = 0;
                }
                team -= ({0});
                set_players(team);
                ob = new(__DIR__"obj/taoist_tape");
                ob->move(environment());
                ob->play_sound_1(this_object(),0);
        }
        else if(arg=="no") {
                delete_temp("�����׽���");
                delete_temp("��ʼ˵������");
                message_vision(BLU"$N˵����û�ô��������ҿɲ��ɣ�\n",this_player());
        }
        else
                return 0;
        return 1;
}

int do_help(string arg) {
        if(arg!="ding" && arg!="ding yi")
                return 0;
        add_player(this_player());
        return 1;
}

int do_report(string arg) {
        object mazeobj,ob,env,*obs;
        int quest_index,has_enemy;

        if(query_temp("in_speech"))
                        return 0;
        mazeobj = get_mazeobj();
        if(!mazeobj)
                        return 0;

        quest_index=query("quest/quest_index", mazeobj);
        switch(quest_index) {
                        case(1):
                                if( query("quest/killed/����", mazeobj) >= query("quest/to_kill/����", mazeobj) && 
                                         query("quest/killed/��ʬ", mazeobj) >= query("quest/to_kill/��ʬ", mazeobj) && 
                                         query("quest/killed/����", mazeobj) >= query("quest/to_kill/����", mazeobj )
                                         ) {
                                                 //mazeobj->delete("quest/to_kill");
                                                 set_temp("in_speech",1);
                                                 ob = new(__DIR__"obj/taoist_tape");
                                                ob->move(environment());
                                                ob->play_sound_2(this_object(),0);
                                } else
                                                return notify_fail("����δ�������\n");
                                break;
                        case(2):
                                if( query("quest/killed/������ʿ", mazeobj) >= query("quest/to_kill/������ʿ", mazeobj) && 
                                         query("quest/killed/���÷�ʦ", mazeobj) >= query("quest/to_kill/���÷�ʦ", mazeobj) && 
                                         query("quest/killed/Ѫ��ʬ", mazeobj) >= query("quest/to_kill/Ѫ��ʬ", mazeobj) && 
                                         query("quest/killed/ʬɷ", mazeobj) >= query("quest/to_kill/ʬɷ", mazeobj) && 
                                         query("quest/killed/��ڤ֮��", mazeobj) >= query("quest/to_kill/��ڤ֮��", mazeobj) && 
                                         query("quest/killed/��ڤ֮��", mazeobj) >= query("quest/to_kill/��ڤ֮��", mazeobj )
                                         ) {
                                                 //mazeobj->delete("quest/to_kill");
                                                 set_temp("in_speech",1);
                                                 ob = new(__DIR__"obj/taoist_tape");
                                                ob->move(environment());
                                                ob->play_sound_3(this_object(),0);
                                } else
                                                return notify_fail("����δ�������\n");
                                break;
                        case(3):
                                if( query("quest/killed/����", mazeobj) >= query("quest/to_kill/����", mazeobj) && 
                                         query("quest/finded/������", mazeobj) >= query("quest/to_find/������", mazeobj )
                                 ) {
                                                 //mazeobj->delete("quest/to_kill");
                                                 //mazeobj->delete("quest/to_find");
                                                 set_temp("in_speech",1);
                                                 ob = new(__DIR__"obj/taoist_tape");
                                                ob->move(environment());
                                                ob->play_sound_4(this_object(),0);
                                } else
                                                return notify_fail("����δ�������\n");
                                break;
                 case(4):
                                if( query("quest/finded/����", mazeobj) >= query("quest/to_find/����", mazeobj) && 
                                         query("quest/finded/��ڤ֮��", mazeobj) >= query("quest/to_find/��ڤ֮��", mazeobj) && 
                                         query("quest/finded/��ʬѪ", mazeobj) >= query("quest/to_find/��ʬѪ", mazeobj )
                                 ) {
                                                 //mazeobj->delete("quest/to_find");
                                                 set_temp("in_speech",1);
                                                 ob = new(__DIR__"obj/taoist_tape");
                                                ob->move(environment());
                                                ob->play_sound_5(this_object(),this_player(),0);
                                } else
                                                return notify_fail("����δ�������\n");
                                break;
                case(5):
                                if(!query_leader()) {
                                        message_vision(BLU"$N��$n˵�����·�ɡ�\n"NOR,this_object(),this_player());
                                        set_leader(this_player());
                                        return 1;
                                }
                                env = environment(this_object());
                                if( query("short", env) == HIY"���鷨��"NOR){
                                                obs = all_inventory(env);
                                                has_enemy = 0;
                                                foreach(ob in obs) {
                                                        if(ob && ob->is_undead()) {
                                                                has_enemy = 1;
                                                                break;
                                                        }
                                                }
                                                if(has_enemy)
                                                                return 0;
                                                set_leader(0);
                                                set_temp("in_speech",1);
                                                ob = new(__DIR__"obj/taoist_tape");
                                                ob->move(environment());
                                                ob->play_sound_6(this_object(),0);
                                } else
                                                return 0;
                                break;
                case(6):
                                if( query("quest/killed/����", mazeobj) >= query("quest/to_kill/����", mazeobj )
                                 ) {
                                                 delete("quest/to_kill", mazeobj);
                                                 set("last_quester",this_player());
                                                 set_temp("in_speech",1);
                                                 ob = new(__DIR__"obj/taoist_tape");
                                                ob->move(environment());
                                                ob->play_sound_7(this_object(),0);
                                } else
                                                return notify_fail("����δ�������\n");
                                break;

        }
        return 1;
}

void smart_action3()
{
        object target,me,*enemies;
        string msg;
        int damage = 0;
        mixed yourexp,myexp;

        me = this_object();
        if(is_fighting() && !me->is_busy()) {
                enemies = query_enemy();
                if(!enemies || sizeof(enemies)==0)
                        return;

                target = enemies[random(sizeof(enemies))];
                if(target)
                {
                        msg = HIG "$N�����૵��������ģ�����һ�ӣ����о�����ɫ��â����ʱ��Ϊ���ɣ�\n\n";
                        msg += HIC "һ���������$n��\n" NOR;

                        yourexp=query("combat_exp", target);
                        myexp=query("combat_exp", me);
                        if( random(myexp + yourexp)> yourexp )
                        {
                                damage = 10000 + random(10000);
                                damage = damage + random(damage);

                                msg +=  HIR "������͡���һ��������$p����͸��������ϳ�һ�������ĺ���������£�\n"NOR;
                                target->receive_damage("qi", damage, me);
                                target->receive_wound("qi", damage/3, me);
                        } else
                                msg += "������͡���һ��������$p����͸�������������Ϣ��������£�\n";

                        message_vision(msg, me, target);
                        if (damage > 0)
                                COMBAT_D->report_status(target);

                        msg = HIW "\nһ�Ű׹�����$n��\n" NOR;
                        yourexp=query("max_neili", target);
                        myexp=query("max_neili", me);
                        if( random(myexp + yourexp) > yourexp )
                        {
                                damage = 10000 + random(10000);
                                damage = damage + random(damage);

                                msg +=  HIR "������͡���һ�����׹��$p����͸��������ϳ�һ�������ĺ���������£�\n"NOR;
                                target->receive_damage("qi", damage, me);
                                target->receive_wound("qi", damage/3, me);
                        } else
                                msg += "������͡���һ�����׹��$p����͸�������������Ϣ��������£�\n";
                        message_vision(msg, me, target);
                        if (damage > 0)
                                COMBAT_D->report_status(target);

                        msg = HIM "\nһ���Ϲ�����$n��\n" NOR;
                        yourexp = target->query_skill("martial-cognize", 1);
                        myexp = me->query_skill("martial-cognize", 1);
                        if( random(myexp + yourexp) > yourexp )
                        {
                                damage = 20000 + random(20000);
                                damage = damage + random(damage);

                                msg +=  HIR "������͡���һ�����Ϲ��$p����͸��������ϳ�һ���������߲ʹ�������������\n"
                                            "��ת�����ִ�$N����ע��$P�����ڣ�\n" NOR;
                                target->receive_damage("qi", damage, me);
                                target->receive_wound("qi", damage/3, me);
                        } else
                                msg += "������͡���һ�����Ϲ��$p����͸�������������Ϣ��������£�\n";
                        message_vision(msg, me, target);
                        if (damage > 0)
                                COMBAT_D->report_status(target);
                }
        }
        return;
}

void smart_fight() {
        smart_action3();
}

int count_undead(object env) {
                object *obs,ob;
                int count;
                obs = all_inventory(env);
                count = 0;
                foreach(ob in obs) {
                                if(ob && ob->is_undead())
                                        count++;
                        }
                return count;
}


void summon_undead(object env,object mazeobj) {
        object *obs,ob;
        int i,j;
        string file;

        if(!env)
                return;

        if(!mazeobj)
                return;

        if( query("quest/quest_index", mazeobj) != 6 )
                return;

        //if(count_undead(env)>=5)  {
        if(count_undead(env)>=1)  {
                        start_call_out( (:call_other,__FILE__, "summon_undead",env,mazeobj :),20);
                        return;
        }

        /*
        if( query("quest/killed/����", mazeobj) >= query("quest/to_kill/����", mazeobj)){
                        message_vision(BLINK HIC"\n������������գ����鷨�󷢳�ҫ�۵���ʹ�â��\n\n"NOR,this_object());
                        obs = all_inventory(env);
                        foreach(ob in obs) {
                                if(ob->is_undead())
                                        ob->die();
                        }
        }
        */
        //message_vision(HIC"\n�������Ϲ⻪һ����һ���������˳�����\n\n"NOR,this_object());
        tell_room(env,HIC"\n�������Ϲ⻪һ����һ�����鱻���˹�����\n\n"NOR);
        i = random(100);
        if(i<5) {
                j = random(2);
                switch(j) {
                        case(0):
                                file = "/maze/necropolis/npc/skeleton_lich";
                                break;
                        case(1):
                                file = "/maze/necropolis/npc/zombie_lord";
                                break;
                        /*case(2):
                                file = "/maze/necropolis/npc/ghost_devil";
                                break;*/
                }
        } else if (i<25) {
                j = random(2);
                switch(j) {
                        case(0):
                                file = "/maze/necropolis/npc/skeleton_mage";
                                break;
                        case(1):
                                file = "/maze/necropolis/npc/zombie_blood";
                                break;
                /*        case(2):
                                file = "/maze/necropolis/npc/ghost_eye";
                                break;*/
                }

        } else if (i<45) {
                j = random(2);
                switch(j) {
                        case(0):
                                file = "/maze/necropolis/npc/skeleton_fighter";
                                break;
                        case(1):
                                file = "/maze/necropolis/npc/zombie_power";
                                break;
        /*                case(2):
                                file = "/maze/necropolis/npc/ghost_fire";
                                break;*/
                }

        } else {
                j = random(2);
                switch(j) {
                        case(0):
                                file = "/maze/necropolis/npc/skeleton";
                                break;
                        case(1):
                                file = "/maze/necropolis/npc/zombie";
                                break;
                /*        case(2):
                                file = "/maze/necropolis/npc/ghost";
                                break;*/
                }
        }
                ob = new(file);
                set("attitude", "aggressive", ob);
                set("bellicosity", 50000, ob);
                ob->move(env);
                start_call_out( (:call_other,__FILE__, "summon_undead",env,mazeobj :),20);
}

object get_mazeobj() {
        if(!m_mazeobj)
                m_mazeobj = FUBEN_D->query_maze_mainobj(this_object());
        return m_mazeobj;
}

int accept_object(object me, object obj)
{
        object mazeobj;
        int quest_index;
        if(!mazeobj=get_mazeobj())
                        return 0;
        quest_index=query("quest/quest_index", mazeobj);
        switch(quest_index) {
                case(3):
                                if(obj->name()=="������" &&
                                   query("id", obj) == "spirit tower"){
                                                set("quest/finded/������", 1, mazeobj);
                                                command("pat "+query("id", me));
                                                destruct(obj);
                                                return 1;
                                }
                                break;
                 case(4):
                                 if(obj->name()=="����" &&
                                   query("id", obj) == "bone staff"){
                                                set("quest/finded/����", 1, mazeobj);
                                                command("pat "+query("id", me));
                                                destruct(obj);
                                                return 1;
                                }
                                if(obj->name()=="��ڤ֮��" &&
                                   query("id", obj) == "ghost fire"){
                                                set("quest/finded/��ڤ֮��", 1, mazeobj);
                                                command("pat "+query("id", me));
                                                destruct(obj);
                                                return 1;
                                }
                                if(obj->name()=="��ʬѪ" &&
                                   query("id", obj) == "zombie blood"){
                                                set("quest/finded/��ʬѪ", 1, mazeobj);
                                                command("pat "+query("id", me));
                                                destruct(obj);
                                                return 1;
                                }
                                break;
        }
        return 0;
}

void give_reward_necropolis(object *ob,object reward_giver) {
        int ref_pot;
        int ref_exp;
        int ref_mar;
        int gold = 50;
        int score = 500;
        int exp,pot,mar;
        object *team,member;
        string reward_msg,mazedir;

        if(!ob || sizeof(ob)==0 || !reward_giver)
                        return;
        team = ob;
        mazedir = FUBEN_D->query_maze_dir(reward_giver);
        foreach(member in team) {
                        if(!member)
                                continue;
                        //if(!environment(member) || !environment(member)->query("virtual_room"))
                                //continue;
                        if(mazedir!=FUBEN_D->query_maze_dir(member))//����ͬһ��������
                                continue;
                        ref_exp = 80000;
                        ref_pot = 3000;
                        ref_mar = 300;

                        if( query("combat_exp", member)>3000000000){
                                        ref_mar = 200;
                                        ref_pot = 2000;
                                        ref_exp = 40000;
                        }else if( query("combat_exp", member)>2000000000){
                                        ref_mar = 250;
                                        ref_pot = 2500;
                                        ref_exp = 50000;
                        }else if( query("combat_exp", member)>1000000000){
                                        ref_mar = 300;
                                        ref_pot = 3000;
                                        ref_exp = 60000;
                        }
                        exp = ref_exp;
                        pot = ref_pot;
                        mar = ref_mar;

                        /*
                        reward_msg =HIR"Ĺ԰��Σ��������㱻�����ˣ�\n\t\t" +
                        chinese_number(exp) + "��ʵս��Ϊ\n\t\t"+
                        chinese_number(pot) + "��Ǳ��\n\t\t" +
                        chinese_number(mar) + "�����\n\t\t" +
                        chinese_number(score) + "������\n\t\t" +
                        chinese_number(gold) + "���ƽ�\n"NOR;
                        tell_object(member,reward_msg);
                        addn("combat_exp", exp, member);
                        addn("potential", pot, member);
                        addn("experience", mar, member);
                        addn("score", score, member);
                        addn("balance", gold*10000, member);
                        */
                        GIFT_D->bonus(member, ([ "prompt" : HIR "Ĺ԰��Σ�����" NOR,
                                                 "exp" : exp, "pot" : pot, "mar" : mar,
                                                 "score" : score, "gold" : gold ]));

                        set_temp("maze/time", time(), member);
        }
}

void die() {
        object mazeobj,item,ob,killer;
        string dir,userid,quest;
        int quest_index;
        if(!mazeobj=get_mazeobj())
                        return;

        killer = query_last_damage_from();
        if(!killer) return;
        if (objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s"))
        {
                this_object()->full_self();
                return;
        }
        quest_index=query("quest/quest_index", mazeobj);
        if(quest_index == 7) {
                        give_reward_necropolis(query_players(),this_object());
                        dir = base_name(mazeobj);

                        if (sscanf(dir,"/f/%s/%s/maze",quest,userid)==2) {
                                        /*
                                        tell_room(environment(),HIY"����������ʮ�����ʧ��\n"NOR);
                                        SCHEDULE_D->set_event(30, 0, mazeobj, "remove_maze");
                                        */
                                        FUBEN_D->delay_clear_fuben(quest, userid);
                                        ob = new(__DIR__"obj/taoist_tape");
                                        ob->move(environment());
                                        ob->play_sound_8(dir,0);
                        }

                        reset_eval_cost();
                        for (int i = 0; i < 3; i++)
                        {
                                item = new("/clone/tessera/rune2" + random(5));
                                item->move(environment());
                        }

                        for (int i = 0; i < 3; i++)
                        {
                                if (random(2) == 1)
                                        item = new("/clone/goods/sun");
                                else
                                        item = new("/clone/goods/moon");
                                item->move(environment());
                        }

                        if (random(100) < 1)
                        {
                                item = new("/clone/tessera/rune28");
                                item->move(environment());
                        }
                        if (random(100) < 2)
                        {
                                item = new("/clone/tessera/rune27");
                                item->move(environment());
                        }
                        if (random(100) < 5)
                        {
                                item = new("/clone/tessera/rune26");
                                item->move(environment());
                        }
                        if (random(100) < 10)
                        {
                                item = new("/clone/tessera/rune25");
                                item->move(environment());
                        }
                        if (random(100) < 2)
                        {
                                item = new("/clone/goods/resolve-scroll");
                                item->move(environment());
                        }
        }
        return ::die();
}

void unconcious()
{
        object ob;

        if (objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s"))
        {
                this_object()->full_self();
                return;
        }

        return ::unconcious();
}
