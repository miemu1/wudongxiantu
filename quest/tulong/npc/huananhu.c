// huananhu.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("华南虎", ({ "huanan hu", "tiger","hu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", @LONG
一只矫健轻快的猛虎，雄伟极了。


    ("`-''-/").___..--''"`-.
     `@_ @ )   `-.  (  *  ).`-.__.`)
     (_Y_.)'  ._   )  `._ `. ``-..-'
      _..`--'_..-_/  /--'_.' ,'
    (il),-''  (li),'  ((!.-'


LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "虎头", "虎身", "前爪", "后抓", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 3330000);
        set("neili",3800);
        set("jiali",3100);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 300);
        set_temp("apply/armor", 100);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "老虎在浚巡，吓得你大气都不敢出。\n",
                "老虎仰天长啸，声震山谷，黄叶纷坠。\n",
        }) );
}

void init()
{	
	object ob; 

	ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query_dex()<20 && !this_object()->query_temp("owner"))
	{
		message_vision( "只见发起一阵狂风。
只听得乱树背後扑地一声响，跳出一只吊睛白额大虫来。
那大虫又饿，又渴，把两只爪在地上略按一按，和身望你一扑，从半空里撺将下来。\n",ob);
		message_vision("$N这一下没有躲开，为虎所伤晕了过去。\n\n",ob);
		ob->receive_wound("qi",20);
		ob->start_busy(2);
		this_object()->kill_ob(ob);
	}
}

