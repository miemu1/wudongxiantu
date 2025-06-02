#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��å��", ({ "rabbit" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", 
"һֻ��β�͵�Ұ�ã�β��һ��һ�̵ġ�\n");
        set("max_qi", 100000);
        set("env/wimpy", 99);
        set("maze_get",1);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) ); 
        set("death_msg",YEL"\n��å������һ�գ��ȶ�һ�ţ�ֱͦͦ���ɵ��ϡ������� \n"NOR);
        set("self_go_msg",1);
        set("arrive_msg","��å�ñı����������˹�����");
        set("leave_msg","��å��һ���Ӵ�û�ˡ�");

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
		say( "��å��һ�����ӵ�˵����\n"
			"��ʲô������������ɫ���б���Ū���ҡ�\n");
		break;
	case 1:
		say( "��å�����ε�˵����\n"
			"�����ڽ���������ȴû�й����ҵĴ�˵����\n");
		break;
	case 2:
		say( "��å�����յ�˵����\n"
			"���ִ����ң�����������а���ף��ٺ١���\n");
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
