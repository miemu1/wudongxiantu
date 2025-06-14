inherit NPC;

void create()
{
        string *names = ({"小棕熊","小黑熊","小白熊"}); 
        set_name( names[random(sizeof(names))], ({ "baby bear","bear"}));
        set("vendetta_mark","bear");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        set("long", "这是一只可爱的小熊。\n");
      
        set("str", 50);
        set("dex", 20);
        set("con", 50);
        set("max_qi", 200);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 3000);
        set("combat_exp", 1000000);

        set("attitude", "peaceful");
        set("chat_chance", 2);
        set("chat_msg", ({
                "小熊拱了拱你的脚。\n"
        }) ); 
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 

        set_temp("apply/attack", 30);
        set_temp("apply/armor", 30);
        set_temp("apply/unarmed_damage", 20);
        setup();
		carry_object("/clone/food/kaoya")->set_amount(1);
        carry_object(__DIR__"obj/bear_skin");
} 
