#include <room.h>
#include <huodong.h>
inherit ROOM;
#define OUTROOM "/d/huashan/jzroad7"

string *jjrooms = ({
			__DIR__"center",
			__DIR__"west",
			__DIR__"east",
			__DIR__"north",
			__DIR__"south",
		});

static object *total = ({ });

private void init_player(object me);
private void message_competition(string msg);
private void auto_check();
private void give_bouns(object me);
private void kickout_players();
private void restore_status(object me);
int check_out(object me);

void create()
{
	set("short", "��ɽ֮��");
	set("long", "�����ǻ�ɽ֮�ۣ�Ҳ������Ⱥ��������������ľ���֮�ء�");
	set("exits", ([
		"south" : OUTROOM,
	]));
	set("no_fight",1);
	set("no_fly",1);
	set("objects",([
	]));
	set("action_list",([
		"��ɽ�۽�":"jjsign",
	]));
	setup();
}

void init()
{
	add_action("jjsign","jjsign");
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("�۽�-jjsign"))
	{
		tell_object(me,"���뿪�˻�ɽ֮�ۣ������Զ�ȡ����\n");
		me->delete_temp("�۽�-jjsign");
	}
	return ::valid_leave(me, dir);
}

int jjsign()
{
	int now = time();
	object me = this_player();

/*
	if(!wizardp(me))
		return notify_fail("���ܻ�ɽ�۽��ݲ����š�\n");
*/
	if(localtime(now)[6]!=LUNJIAN_DAY||localtime(now)[2]!=LUNJIAN_HOUR||localtime(now)[1]>LUNJIAN_PRE)
		return notify_fail(ZJOBLONG"����ʱ�䣺ÿ����"+LUNJIAN_HOUR+":00-"+LUNJIAN_HOUR+":10��\n");
/*
	if(!me->query("family/family_name")||FAMILY_D->query_family_leader(me->query("family/family_name"))!=me->query("id"))
		return notify_fail("��ɽ�۽�ֻ�и���������ϯ���Ӳ��ܲ��룡\n");

	if (me->query("age")<18 || me->query("combat_exp",1)<200000)
		return notify_fail("�������С�����ǰѹ������������ɡ�\n");
*/
	me->set_temp("�۽�-jjsign",1);
	tell_object(me,"�����ɹ������ڴ��Ժ�"+LUNJIAN_HOUR+"��10���Զ����뾺�����С�\n");
	set_heart_beat(1);
	return 1;
}

private void auto_check()
{
	object ob;
	string msg;
	string room;
	object *lost;
	int i,pot,exp;

	lost = ({ });
	for (i = 0; i < sizeof(total); i++)
	{
		if (! objectp(total[i]))
			continue;
		room = base_name(environment(total[i]));
		if (member_array(room,jjrooms)==-1)
		{
			// not in pk room
			restore_status(total[i]);
			total[i] = 0;
			continue;
		}
		if (total[i]->query("qi") < 1 || total[i]->query("jing") < 1)
			lost += ({ total[i] });
	}

	// kickout the players who lost competition
	foreach (ob in lost)
		check_out(ob);

	total -= ({ 0 });

	if (sizeof(total) < 1)
	{
		msg = "��˵��ɽ�۽����������������ӵ��ӣ�����һ���˶�û������";
	} else
	if (sizeof(total) == 1)
	{
		// change the daemon's state
		msg = "��˵��ɽ�۽�Բ��������" + total[0]->name(1) + "��á��������𡿵ĳƺţ�";
		FAMILY_D->set_lunjian_leader(total[0]->query("id"));
		give_bouns(total[0]);
	} else
		return;

	set_heart_beat(0);
	delete("pre_start");
	delete("start");
	message_competition(msg);
}

private void init_player(object me)
{
	tell_object(me, HIY "����ǰ��Ȼһ��..."NOR"\n");
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
	me->set_override("die", (: call_other, __FILE__, "check_out" :));
	me->set_override("quit", (: call_other, __FILE__, "check_quit" :));
	me->set_temp("backup/killer", me->query_killer());
	me->set_temp("backup/want", me->query_want());
	me->set_temp("in_pkd", 1);
	me->delete_temp("�۽�-jjsign");

	me->set("backup/condition", me->query_condition());
	me->clear_condition();
}

private void kickout_players()
{
	object ob;
	string room;
	mapping my;

	if (! arrayp(total))
		return;

	foreach (ob in total)
	{
		if (! objectp(ob))
			continue;
		room = base_name(environment(ob));
		if (member_array(room,jjrooms)==-1)
			// not in pk room
			continue;

		my = ob->query_entire_dbase();
		my["eff_qi"] = my["max_qi"];
		my["eff_jing"] = my["max_jing"];
		my["qi"] = 1;
		my["jing"] = 1;

		tell_object(ob, HIC "���λ�ɽ�۽��������㱻�ͳ��������أ���"NOR"\n");

		restore_status(ob);
		ob->move(this_object());
		message("vision", "ֻ��" + ob->name() + "�㬵����˳�����\n",	environment(ob), ({ ob }));
		if (! living(ob))
			ob->revive();
	}

	total = ({ });
}

private void message_competition(string msg)
{
	CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

private void give_bouns(object me)
{
	int exp;
	int pot;
	string msg;
	object ob;

	restore_status(me);
	tell_object(me, "�������ˬ����...\n");
	me->move(this_object());
	message("vision", me->name() + "���������˹�����һ����Ц��\n",environment(me), ({ me }));

	// bouns
	tell_object(me, HIY"��ϲ�����ˡ��������𡿳ƺţ������ÿ����������ȡһ�ν���"NOR"��\n");
}

private void restore_status(object me)
{
	mapping my;
	mapping cnd;
	string *ks;
	int i;

	me->delete_temp("�۽�-jisign");
	me->delete_temp("in_pkd");
	me->delete_override("unconcious");
	me->delete_override("die");
	me->delete_override("quit");
	me->remove_all_enemy(1);
	me->remove_all_killer();
	me->clear_condition();
	me->receive_damage("qi", 0);
	me->apply_killer(me->query_temp("backup/killer"));
	me->apply_want(me->query_temp("backup/want"));

	cnd = me->query("backup/condition");
	me->delete("backup/condition");
	me->delete_temp("block_msg/all");
	if (! mapp(cnd)) return;
	ks = keys(cnd);
	for (i = 0; i < sizeof(ks); i++)
		me->apply_condition(ks[i], cnd[ks[i]]);

	my = me->query_entire_dbase();
	if (my["qi"] < 1)       my["qi"] = 1;
	if (my["eff_qi"] < 1)   my["eff_qi"] = 1;
	if (my["jing"] < 1)     my["jing"] = 1;
	if (my["eff_jing"] < 1) my["eff_jing"] = 1;
}

void heart_beat()
{
	int i,now = time();
	object room,*inv;

	room = this_object();

	if(!query("pre_start")&&localtime(now)[1]==LUNJIAN_PRE)
	{
		set("pre_start",1);
		tell_room(this_object(),"1���Ӻ󽫽��뾺������������׼��������\n");
	}
	else if(!query("start")&&localtime(now)[1]==(LUNJIAN_PRE+1))
	{
		set("start",1);
		inv = filter_array(all_inventory(this_object()), (: playerp($1)&&$1->query_temp("�۽�-jjsign") :));
		if(sizeof(inv)<LUNJIAN_USER_MIN)
		{
			tell_room(this_object(),"������������"+LUNJIAN_USER_MIN+"�ˣ����λδ�ܳɹ����С�����\n");
			delete("pre_start");
			delete("start");
			set_heart_beat(0);
			return;
		}
		total = inv;
		for(i=0;i<sizeof(inv);i++)
		{
			init_player(inv[i]);
			inv[i]->move(jjrooms[random(sizeof(jjrooms))]);
			tell_object(inv[i], HIY "�㶨��һ�����ŷ����Լ�����" + environment(inv[i])->short() + HIY "��\n");
		}
	}
	else if(localtime(now)[1]>LUNJIAN_PRE)
	{
		auto_check();
	}
	else if(localtime(now)[1]>(LUNJIAN_PRE+LUNJIAN_TIME))
	{
		message_competition("��˵���λ�ɽ�۽���Ӣ���ƾ����У�δ�ܾ�����������");
		delete("pre_start");
		delete("start");
		kickout_players();
		set_heart_beat(0);
	}
}

int check_quit(object me)
{
	message_competition("��˵" + me->name(1) + "�������ӣ��ӻ�ɽ�۽������������ˡ�");
	restore_status(me);
	if (arrayp(total))
		total -= ({ me });

	tell_object(me, "���ӳ��˾�������\n");

	me->move(this_object());
	message("vision", "ֻ��" + me->name() + "������ŵ����˳�����\n",environment(me), ({ me }));
	return 1;
}

int check_out(object me)
{
	object ob;
	mapping my;
	string msg;
	string room;
	int score;

	room = base_name(environment(me));
	if (member_array(room,jjrooms)==-1)
	{
		// not in pk room
		total -= ({ me });
		return 0;
	}

	my = me->query_entire_dbase();
	my["eff_qi"] = my["max_qi"];
	my["eff_jing"] = my["max_jing"];
	my["qi"] = 1;
	my["jing"] = 1;

	tell_object(me, HIR "\n�������ǰһ��ģ��...�������ˣ�"NOR"\n");
	if (ob = me->query_last_damage_from())
	{
		msg = "��˵" + me->name(1) + "�ڻ�ɽ�۽��в���" + ob->name(1) + "�Ķ��֣���������̭��";
	} else
		msg = "��˵" + me->name(1) + "�ڻ�ɽ�۽����������ѣ��������ޡ��Ѿ�������̭��";
	message_competition(msg);

	restore_status(me);
	total -= ({ me });
	me->move(this_object());
	message("vision", "һ����Ӱٿ�Ĵ��˳������漴���ǡ�ž����һ�����ͼ�" + me->name() +"ˤ���˵��ϣ�һ��������������ӡ�\n", environment(me), ({ me }));
	tell_object(me, "�������У�����ñ������������������ص�ˤ���˵��ϡ�\n");
	if (! living(me))
		me->revive();
	return 1;
}
