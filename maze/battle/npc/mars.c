// niutou.c

#include <ansi.h>
#define BATTLEFIELD2_D     "/adm/daemons/battlefieldd2.c"

inherit NPC;

void create()
{
        set_name("ս��", ({ "zhan shen", "mars", "zhan", "shen" }) );
        set("title", HIY "����" NOR);
        set("gender", "����");
        set("age", 58);
        set("long", @LONG
������ս��ɱ¾��ɥʧ�����ĵ�սʿ�����������ͳɵ�ս��
LONG );
        set("combat_exp", 1000000000);
        set("shen_type", 0);
        set("attitude", "heroism");
        set("max_neili", 3000000);
        set("neili", 3000000);
        set("max_jing", 3000000);
        set("jing", 3000000);
        set("max_qi", 40000000);
        set("qi", 40000000);
        set("jingli", 30000000);
        set("max_jingli", 30000000);
        set("jiali", 30000);

        set("str", 800);
        set("int", 300);
        set("con", 800);
        set("dex", 800);

        set_skill("unarmed", 2500);
        set_skill("sword", 2500);
        set_skill("parry", 2500);
        set_skill("dodge", 2500);
        set_skill("force", 2500);

        set_temp("apply/attack", 2500);
        set_temp("apply/unarmed_damage", 2500);
        set_temp("apply/armor", 5000);

        setup();
}

void init()
{
        object ob, me;

        me = this_player();
        ob = this_object();

        ::init();
        if( interactive(me) && visible(me) &&
            !is_fighting()) {
                kill_ob(me);
        }
}

void fight_ob(object ob)
{
        if (is_fighting(ob))
                return;

        message_vision(HIR "$N" HIR "ŭ��һ����������"
                       "�׹��¶��\n" NOR, this_object(), ob);

        ::fight_ob(ob);
        if( !is_killing(ob->query("id")) )
                kill_ob(ob);
}

int accept_fight(object ob)
{
        message_vision("$Nһ���У���Ȼ����������\n",
                       this_object(), ob);
        kill_ob(ob);
        return -1;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        ob->receive_wound("qi", 20000 + random(20000), me);
        me->set("neili",me->query("max_neili"));
        return HIR "$N" HIR "��������һ�ɻ��棬��ʱ�Ƶ�$n"
               HIR "�˺󼸲����ƺ�һ����\n" NOR;
}

varargs void die(object killer)
{
        object me;
        int i;

        me = this_object();

        if( !killer ) killer = me->query_last_damage_from();
        if( objectp(killer) )
        {
                BATTLEFIELD2_D->add_killnpc_score(killer, 1);
        }

        ::die(killer);
}

