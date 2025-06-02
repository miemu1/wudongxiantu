#include <ansi.h>

inherit BOSS;

void create()
{
        set_name(HIG"ɳĮ����"NOR, ({"shamo zeidao", "qiang dao", "zeidao"}) );
        set("title", HIY "��������" NOR);
        set("gender", "����" );
        set("age", random(30)+20);
        set("long", "�����޾���Į��ǿ����ռ�ŶԵ�����Ϥ�����޾���Į�����͹�������\n");
        set("attitude", "aggressive");
        set("class", "lvlin");
        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("max_qi", 50000);
        set("max_jing", 50000);
        set("neili", 150000);
        set("max_neili", 50000);
        set("no_suck",1);
        set("jiali", 150);
        set("shen", 0);

        set_temp("apply/attack",  10);
        set_temp("apply/defense", 20);
        set("combat_exp", 500000);
        set_skill("force", 150);
        set_skill("unarmed", 150);
        set_skill("blade", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("jiuyin-baiguzhao", 150);
        set_skill("wuhu-duanmendao", 150);
        set_skill("taiji-shengong", 150);
        set_skill("tiyunzong", 150);
        map_skill("force", "taiji-shengong");
        map_skill("unarmed","jiuyin-baiguzhao");
        map_skill("parry", "jiuyin-baiguzhao");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("dodge", "tiyunzong");
        create_family("���ֱ�����", 3, "����");

        set("auto_perform", 1);
        set("auto_exert", 1);
        set("drops", ([
                "RA&RANDOM20" : 15,
                "RA&RANDOM10" : 20,
        ]));
        set("rewards", ([
                "exp"  : 60,
                "pot"  : 20,
                "mar"  : 3,
        ]));
        setup();

        if( random (10) > 5 )
                carry_object("/clone/weapon/blade")->wield();
        else
                carry_object("/clone/weapon/gangjian")->wield();

        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", random(30));
}

int accept_fight(object ob)
{
        command("say �ҿ�û��Ȥ�����棬����ҹ�����");
        return 0;
}

int accept_hit(object ob)
{
        message_vision(HIW "$N" HIW "��ɫһ�䣬����һ��ɱ����ŭ"
                       "�ȵ�����һ��" + RANK_D->query_rude(ob) +
                       "�����ɣ�\n" NOR, this_object());

        NPC_D->copy_from_me(this_object(), ob, 50, 1);
        kill_ob(ob);
        return 1;
}

int accept_kill(object ob)
{
        if (! living(this_object()))
                return 1;

        return accept_hit(ob);
}

int accept_ansuan(object ob)
{
        return notify_fail("���˾����Ժøߣ����������֡�\n");
}

int accept_touxi(object ob)
{
        return notify_fail("���˾����Ժøߣ����������֡�\n");
}
