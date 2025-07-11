#include <ansi.h>
inherit NPC;

void create()
{
        set_name("流氓兔", ({ "rabbit" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", 
"一只白尾巴的野兔，尾巴一翘一翘的。\n");
        set("max_qi", 100000);
        set("env/wimpy", 99);
        set("maze_get",1);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) ); 
        set("death_msg",YEL"\n流氓兔两眼一闭，腿儿一蹬，直挺挺的躺地上。。。。 \n"NOR);
        set("self_go_msg",1);
        set("arrive_msg","流氓兔蹦蹦跳跳地跑了过来。");
        set("leave_msg","流氓兔一下子窜没了。");

        set_skill("dodge", 1000+random(500)); 

        set("maze_item",1);
        setup();
} 

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
	case 0:
		say( "流氓兔一脸鄙视的说道：\n"
			"看什么看，瞧你那损色，有本事弄死我。\n");
		break;
	case 1:
		say( "流氓兔无奈的说道：\n"
			"我身在江湖，江湖却没有关于我的传说……\n");
		break;
	case 2:
		say( "流氓兔阴险地说道：\n"
			"有种打死我，打死我送你邪神套，嘿嘿……\n");
		break;
	}
}


int is_undead() {
	return 1;
}

int is_zombie() {
	return 1;
}
void die()
{
	object me,ob,jmem,item;
	mapping team;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = ob->query_temp("last_damage_from");

        rand = random(1000);
	if(rand >= 100)
	{
		item = new("/clone/money/gold");
		if(item)
		{
			item->set_amount(1);
			item->move(environment(ob));
		}
	}

        else if(rand < 100)
	{
		item = new("/clone/box/y1-box");
		if(item)
		{
			item->move(environment(ob));
		}
    }

	destruct(ob);
}
