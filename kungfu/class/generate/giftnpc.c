// person used in quest shen
#include <ansi.h>
inherit CLASS_D("generate") + "/chinese";
void random_move();
void create()
{
	::create();
	set("name",HIG"G"+query("name")+NOR);
	set("gender", "Ů��" );
	set("age", 30 + random(30));
	set("long", "������Я��������������ڸ��ص��������");
	set("attitude", "friendly");
	set("chat_chance", 50);
	set("chat_msg", ({ (: random_move :) }));
	set("scale", 150);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 20);
	set_temp("born_time", time());
	NPC_D->init_npc_skill(this_object(), 1);
	setup();
}
int accept_fight(object ob)
{
	command("say ��û����Ȥ�����������������");
	return 0;
}
int accept_hit(object ob)
{
	message_vision("$N��ɫһ�䣬����һ��ɱ�����ȵ�������һ��" +
		       RANK_D->query_rude(ob) + "�����ɣ���\n", this_object());
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
void random_move()
{
	NPC_D->random_move(this_object());
}
void remove()
{
	if (! environment() || query_temp("die"))
	{
		::remove();
		return;
	}
	if (! living(this_object()))
	{
		message_vision("·�������ˣ��������Բ��ѵ�$N��̾��������$P�����ˡ�\n",this_object());
		return;
	}
	message_vision("$N���˿����ܣ�����ææ�����ˡ�\n",this_object());
	::remove();
}
void die(object killer)
{
	object me,obj,ob;
	int lv;

	me = this_object();

	if (objectp(ob = killer) || objectp(ob = query_last_damage_from()))
	{
		obj = new("/clone/money/gold");
		tell_object(ob,me->query("name")+"��Ȼ�е����ף������ӣ�\n"
			"���͵�һ���䣬"+me->query("name")+"һ���̵��Ѿ������ˣ���ϸһ�������о�Ȼ��Ȼ��Ķ���"+obj->short()+"\n");
//		obj = new("/clone/shizhe/baozhu");
//		tell_object(ob,me->query("name")+"��Ȼ�е�����������\n"
//			"���͵�һ���䣬"+me->query("name")+"һ���̵��Ѿ������ˣ���ϸһ�������о�Ȼ��Ȼ����"+obj->short()+"\n");
		obj->move(ob);

		if(random(4)==1)
		{
			obj = new("/clone/gift/fudai");
			tell_object(ob,"���澹Ȼ��ѹ�š�����������\n������������"+obj->short()+"\n");
			obj->move(ob);
			CHANNEL_D->do_channel(me, "rumor","��˵" + ob->name(1) +"��" + environment()->short() + "ż��" +name() + "�������һЩ�������");
		}

	}
	destruct(me);
}
