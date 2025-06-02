// Written by Lonely@IsMUD.net (05/21/2009)

#include <ansi.h>
inherit "inherit/char/boss";

void sp_attack();
void create()
{
        set_name(HIB "��ʼ�ʽ�ʬ" NOR, ({ "qin shihuang", "king" }));
        set("long", HIB "������һλͳһ���������ߣ�����ֻ�ǽ�ʬһ����\n" NOR);
        set("title", HIY "�ʵ�" NOR);
        set("attitude", "aggressive");
        set("str", 120);
        set("con", 120);
        set("dex", 120);
        set("int", 120);

        set("max_qi", 80000000);
        set("max_jing", 40000000);
        set("neili", 25000000);
        set("max_neili", 25000000);
        set("max_jingli", 50000000);
        set("jingli", 50000000);
        set("jiali", 40000);
        set("level", 70);
        set("combat_exp", 2000000000);
		
				set_skill("force", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: sp_attack :),
        }));

        set("death_msg", HIY "\n$Nɢ���һ�����ͷ��\n\n" NOR);

        set_skill("force", 3500);
        set_skill("zixia-shengong", 3500);
        set_skill("huashan-neigong", 3480);
        set_skill("dodge", 3500);
        set_skill("feiyan-huixiang", 3500);
        set_skill("huashan-shenfa", 3500);
        set_skill("parry", 3520);
        set_skill("sword", 3520);
        set_skill("lonely-sword", 3520);
        set_skill("blade", 3500);
        set_skill("fanliangyi-dao", 3500);
        set_skill("strike", 3480);
        set_skill("hunyuan-zhang", 3480);
        set_skill("cuff", 3480);
        set_skill("poyu-quan", 3480);
        set_skill("literate", 3480);
        set_skill("martial-cognize", 3420);

        /*
        map_skill("cuff", "poyu-quan");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "dugu-jiujian");
        map_skill("blade", "fanliangyi-dao");
        map_skill("sword", "dugu-jiujian");
        map_skill("strike", "hunyuan-zhang");

        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");
        */

        set("bonus", 150000);
        set_temp("apply/attack", 50000+random(30000));
        set_temp("apply/damage",50000+random(30000));
        set_temp("apply/unarmed_damage",50000+random(30000));
        set_temp("apply/armor", 50000+random(30000));
        set_temp("apply/add_xuruo", 90);
        set_temp("apply/reduce_damage", 90);
        set_temp("apply/reduce_busy", 36);
        set_temp("apply/add_busy", 50);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object me;

        ::init();
        if (! interactive(me = this_player()) ||
            this_object()->is_fighting())
                return;

        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

void sp_attack()
{
        object *enemies, enemy, ob;
        object *obs;
        string msg;
        int i;

        enemies = query_enemy();
        if( !enemies || sizeof(enemies) == 0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        obs = filter_array(all_inventory(environment(this_object())), (: $1->query("id") == "skeleton fighter" :) );
        if( sizeof(obs) < 7 && !random(5) ) {
                msg = HIY"$Nչ�����еĺ�ɫᦲ�����ʱ������ţ������������ٻ�������������ʿ��\n"
                         "��Щ������ǰ���ػ���ߵĻ�����������Ȼ�������ߣ���Х����$n������\n"NOR;
                message_vision(append_color(msg, HIY),this_object(),enemy);
                for( i=0;i<3;i++ ) {
                        ob = new(__DIR__"skeleton");
                        ob->set_from_me(enemy);
                        ob->move(environment(enemy));
                        ob->kill_ob(enemy);
                }
                return;
        }
        if( !enemy->is_busy() && sizeof(ob) > 3 && !random(5) ) {
                msg = HIY"$N�������е���ɫʯӡ��ֻ����ʯӡ�ɵ����У����һ��������⣬��$n�������ڡ�\n"
                         "$nֻ��������·�һ����ɽѹס����֫�������ã�����������ʮ�ּ��ѣ�ֻ����\n"
                         "�����ؿ���������Ц��һ�����߽���\n" NOR;
                message_vision(append_color(msg, HIY),this_object(),enemy);
                enemy->start_busy(5);
                return;
        }
        /*
        �ػʽ�ʬ�ù����£��е�ʮ�ֲ��ͷ������ǰѺ�ͼ����������һ�ԣ�����ߵĽ�����
        �γ�һ����������ı�������Ȼ�ڹ�������ǧ�����£���ѱ�����Ȼ��ɼ��ˣ�����
        ��ƥ��������������Ȼ�����������Ͽ�������׭�֣�¹¬��
        */
        switch( random(5) ){
                case 4: msg = HIY "$N"HIY"��һ�ӣ�һ����⻯��һ���������$n"HIY"���������\n"NOR; break;
                case 3: msg = HIW "$N"HIW"�ſ���ڣ�һ��������Ѹ�Ͷ�����$n"HIW"ֻ���Լ���Ѫ���ͣ������ش���\n"NOR; break;
                case 2: msg = HIR "$N"HIR"˫�Ʋ�����һ�޴�Ļ�������$n"HIR"��$n"HIR"���յ����������\n"NOR; break;
                case 1: msg = MAG "$N"MAG"һ�����У������³���ɳ������Х���Ǽ�����Х���������ɳ�絶���罣��Խ��Խ��... Խ��Խ��...\n"
                                  "$n"MAG"ȫ���ʱǧ���ٿף���Ѫֱӿ������\n"NOR;break;
                default: msg= HIG "$N"HIG"��һ��أ�ֻ��$n"HIG"�űߵĵ��Ͽ������������ٽ���������$n"HIG"��$n"HIG"��ʱ����������ͷ���ۻ���\n"NOR; break;
        }
        message_vision(msg,this_object(),enemy);
        enemy->receive_damage("qi",50000+random(50000),this_object());
        COMBAT_D->report_status(enemy);
        if( !enemy->is_busy() )
                enemy->start_busy(2);
        return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        int reduce;

        damage = 10000 + random(10000);
        reduce = (int)ob->query_temp("apply/reduce_fire");
        damage -= damage * reduce / 100;
        if( damage < 0 ) damage = 0;
        ob->receive_damage("qi", damage, me);
        ob->receive_wound("qi", damage, me);
        me->set("neili", me->query("max_neili"));
        return HIY "$N" HIY "ȫ������ҫ�۵Ľ�⣬��ʱ��$n"
               HIY "ȫ���������ʡ�\n" NOR;
}
