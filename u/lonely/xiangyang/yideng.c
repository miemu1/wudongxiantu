#include <ansi.h>

inherit NPC;

void create()
{
            set_name("һ�ƴ�ʦ", ({ "yideng dashi", "yideng", "dashi" }));
            set("long", @LONG
һ�ƴ�ʦ�˽������˳ơ���а�������ϵ۱�ؤ����
���ϵ۶λ�ү������ƾ�Ŷ��ϡ�һ��ָ����������
�֣�������֡���ȴ������ʱ��һ�α��������Ϊ
ɮ��֮��󳹴��򣬳�Ϊһλ�õ���ɮ��
LONG );
            set("title", "�������λ�ʵ�");
            set("nickname", HIY "�ϵ�" NOR);
            set("gender", "����");
            set("age", 71);
        set("shen_type", 1);
            set("attitude", "friendly");

            set("str", 33);
            set("int", 35);
            set("con", 38);
            set("dex", 33);

            set("qi", 206500);
            set("max_qi", 206500);
            set("jing", 206500);
            set("max_jing", 206500);
            set("neili", 80000);
            set("max_neili", 80000);
            set("jiali", 200);
            set("combat_exp", 40000000);
            set("score", 500000);

        set_skill("force", 540);
        set_skill("xiantian-gong", 540);
        set_skill("duanshi-xinfa", 520);
        set_skill("kurong-changong", 520);
        set_skill("dodge", 520);
        set_skill("tiannan-bu", 520);
        set_skill("cuff", 500);
        set_skill("jinyu-quan", 500);
        set_skill("strike", 500);
        set_skill("wuluo-zhang", 500);
        set_skill("sword", 500);
        set_skill("staff", 500);
        set_skill("duanjia-jian", 500);
        set_skill("finger", 540);
        set_skill("qiantian-zhi", 540);
        set_skill("sun-finger", 540);
        set_skill("parry", 500);
        set_skill("jingluo-xue", 500);
        set_skill("buddhism", 540);
        set_skill("literate", 500);
        set_skill("sanscrit", 500);
        set_skill("martial-cognize", 520);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "tiannan-bu");
        map_skill("finger", "sun-finger");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("parry", "sun-finger");
        map_skill("sword", "duanjia-jian");
        map_skill("staff", "sun-finger");

        prepare_skill("finger", "sun-finger");

        create_family("���ϻ���", 11, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.die" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 300);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 400);

            setup();
            carry_object("/clone/cloth/seng-cloth")->wear();
}
void unconcious()
{
        die();
}   
