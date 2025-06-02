#include <ansi.h>
inherit BOSS;

void create()
{
        set_name(HIM"������"NOR, ({"zeidao wang", "wang", "boss"}) );
        set("title", HIC "���ְ���" NOR);
        set("gender", "����" );
        set("age", random(30)+20);
        set("long", "����ɭ�ֵ��������죬����һ���������գ����׶����º���ʮ��֮����\n");
        set("attitude", "aggressive");
        set("class", "lvlin");
        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("max_qi", 5000000);
        set("eff_qi", 5000000);
        set("qi", 50000000);
        set("max_jing", 2100000);
        set("eff_jing", 2100000);
        set("jing", 21000000);
        set("neili", 5000000);
        set("max_neili", 500000);
        set("jingli", 100000);
        set("max_jingli", 100000);
        set("no_suck",1);
        set("jiali", 200);
        set("shen", 0);
        set("end_boss", 1);
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 30);
        set("combat_exp", 100000000);
        set_skill("force", 2000);
        set_skill("unarmed", 2000);
        set_skill("dodge", 2000);
        set_skill("parry", 2000);
        set_skill("blade", 2000);
        set_skill("douzhuan-xingyi", 2000);
        set_skill("guiyuan-tunafa", 2000);
        set_skill("tie-zhang", 1500+random(1500));
        set_skill("wuming-jianfa", 1500+random(1500));
        set_skill("wuhu-duanmendao", 1500+random(1500));
        set_skill("shaolin-shenfa", 2000);
        set_skill("martial-cognize", 2000);
        map_skill("force", "guiyuan-tunafa");
        map_skill("unarmed","tie-zhang");
        map_skill("parry", "wuhu-duanmendao");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("dodge", "shaolin-shenfa");
        create_family("���ֱ�����", 3, "����");

        set("auto_perform", 1);
        set("clear_fuben", 1); 
        set("drops", ([
                "RA&RANDOM30" : 50,
                "RA&RANDOM30" : 50,
                "RA&RANDOM30" : 50,
                "RA&RANDOM20" : 100,
                "RA&RANDOM20" : 100,
                "RA&RANDOM20" : 100,
                "FI&/clone/goods/sun" : 30,
                "FI&/clone/goods/moon" : 30,
                "FI&/clone/goods/enchant-scroll" : 30,
        ]));
        set("rewards", ([
                "exp"  : 8000,
                "pot"  : 3000,
                "mar"  : 300,
        ]));
        /*
        set_temp("apply/attack", 2000+random(1000));
        set_temp("apply/damage",2000+random(1000));
        set_temp("apply/unarmed_damage",2000+random(1000));
        set_temp("apply/armor", 2000+random(1000));
        set_temp("apply/add_weak", 50);
        set_temp("apply/add_busy",15);
        set_temp("apply/reduce_busy", 30);
        */
        set_temp("apply/reduce_damage", 50);
        setup();

        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/weapon/blade")->wield();

        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", random(300));
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
