#include <ansi.h>
inherit "inherit/char/boss";

void random_move();
void do_swing();
void set_from_me(object me);
void create()
{
        string *names = ({ "��ͭ����" });

        ::create();
        set_name( names[random(sizeof(names))], ({ "mammoth bronze"}));
        set("long", @LONG
����һ����˯�ڻ�����ͭ�����ޡ�����������࣬��֫��Ϊ��׳�����������Ұڶ���
�첿����һ����������������ͬ�����䵶����Ϊ�������ڶ��������������£�������
����Ȼ�ٻ�������������������������������⣬�ټ���ëƤ��ǹ���룬������
�絶�У��˵��Ǽ��ѶԸ���
LONG);
        set("title", HIR"������" NOR);

        set("str", 150);
        set("con", 150);
        set("dex", 150);
        set("int", 150);
        set("max_qi", 2500000);
        set("max_jing", 1500000);
        set("neili", 2500000);
        set("max_neili", 2500000);
        set("max_jingli", 500000);
        set("attitude", "killer");
        set("auto_perfrom", 1);
				set_skill("force", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);

        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: do_swing :),
        }) );

        set("combat_exp", 100000000);
        set("death_msg",YEL"\n$Nɢ���һ����ͭ��\n\n"NOR);

        set("bonus", 20000);
        set_temp("apply/attack", 20000);
        set_temp("apply/parry", 20000);
        set_temp("apply/damage", 20000);
        set_temp("apply/unarmed_damage", 20000);
        set_temp("apply/armor", 20000);
        setup();
}

void init()
{
        object me;

        ::init();
        if( !interactive(me = this_player()) ||
            this_object()->is_fighting())
                return;

        set_from_me(me);
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

void set_from_me(object me)
{
        mapping my;

        NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me));
        my = query_entire_dbase();
        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];
        set("jiali", query_skill("force") / 2);
}

void do_swing()
{
        object *enemies,enemy;
        string msg;

        enemies = query_enemy();
        if( !enemies || sizeof(enemies)==0 )
                return;

        msg = BLU"$N��һ�ţ������������ĺ��ĵ�ҩ��,����һ�£�һ����ɫ��ζ�ı�����Է�Ʈȥ��\n"NOR;
        message_vision(msg,this_object());
        foreach( enemy in enemies ) {
                msg = HIY"$nһʱ���⣬�Ѿ�����$N�İ��㣡\n"NOR;
                message_vision(msg,this_object(), enemy);
                enemy->affect_by("poison",
                                  ([ "level" : 1500,
                                     "id"    : this_object()->query("id"),
                                     "duration" : 200 ]));
                tell_object(enemy, HIG "��������ͭ��������ĺ��Ķ���\n");
                enemy->receive_damage("qi",10000+random(10000),this_object());
                COMBAT_D->report_status(enemy);
                if( !enemy->is_busy() )
                        enemy->start_busy(2);
        }
}

int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place, my_birth_place;
        object env;
        string userid,mazeobj;
        int x,y;

        if( !mapp(exits = environment()->query("exits")) ) return 0;

        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        env = environment(this_object());
        to_go_place = env->query("exits/"+direction);
        //my_birth_place = file_name(this_object());

        //ccommand("say "+to_go_place);
        if( sscanf(to_go_place,"/f/mausoleum/%s/%s/%d/%d",userid,mazeobj,x,y)!=4 )
                return 1;
        command("go " + direction);
        add_temp("random_move", 1);
        return 1;
}
