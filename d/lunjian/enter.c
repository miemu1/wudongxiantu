#include <room.h>
inherit ROOM;
#define OUTROOM "/d/fuben/qianchipu/qianchipu"

#define LUNJIAN_DAY			0
#define LUNJIAN_HOUR		21
#define LUNJIAN_PRE			10
#define LUNJIAN_TURN		7
#define LUNJIAN_USER_MIN	5

string *total = ({});
int turn = 0;
mapping allusers = ([]);

private void init_player(object me);
private void message_competition(string msg);
private void auto_check();
private void restore_status(object me);
int check_win(object me);
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
		"�ƺŽ���":"lunjiangift",
		"��ȯ�һ�":"ljshop",
		"�۽����뽱":"ljsign"
	]));
	setup();
}

void init()
{
	add_action("ljshop","ljshop");
	add_action("jjsign","jjsign");
	add_action("ljsign","ljsign");
	add_action("lunjiangift","lunjiangift");
}

int ljshop(string arg)
{
	string *list,str,file,price;
	int i,yuanbao,value;
	object me,ob;
	int amount;
	mapping goods,times;

	me = this_player();
	goods = ([
		"/clone/lunjian/dan_chongmai4":3,
		"/clone/lunjian/putao":10,
		"/clone/lunjian/wujueling":100,
		"/clone/lunjian/bookbadao":150,
		"/clone/lunjian/wujuetieling":100,
		"/clone/lunjian/xyj":100,
		"/clone/lunjian/book_tianfuxian":5,
		"/clone/lunjian/caomindan":50,
		"/clone/lunjian/da-xidian":50,
	]);
	times = ([
		"/clone/lunjian/wujueling":1,
	]);
	list = keys(goods);
	if (! arg)
	{
		str = ZJOBLONG"��Ŀǰ��"+me->query("lunjian/pot")+"�۽���ȯ����ѡ������һ��ĵ��ߣ�\n"ZJOBACTS2+ZJMENUF(4,4,8,32);
		for(i=0;i<sizeof(list);i++)
		{
			file = list[i];
			if(!goods[file]||file_size(file+".c")<0) continue;
			yuanbao = goods[file];
			price = yuanbao+"��ȯ";
			str += sprintf("%s"ZJBR"%s:ljshop look %s"ZJSEP,file->query("name"),price,file);
		}
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"�һ��б���û��������ߣ���"NOR"\n");

		yuanbao = goods[file];
		price = yuanbao+"��ȯ";
		str = ZJOBLONG+"��"+file->query("name")+"�������۸�"+price+NOR+ZJBR"һһһһһһһһһһһһһһһһһһһһһһһ"ZJBR;
		if(times[file])
			str += HIR"����Ʒÿ������޶һ�"+times[file]+"��"NOR ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "�һ�:ljshop buy "+file+"\n";
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"�һ��б���û��������ߣ���"NOR"\n");

		yuanbao = goods[file];

		if(times[file])
		{
			if(me->query("lunjian/duihuan/"+file->query("id")) >= times[file])
				return notify_fail(HIM"����Ʒÿ�����ֻ�ܶһ�"+times[file]+"�Σ���"NOR"\n");
			me->add("lunjian/duihuan/"+file->query("id"),1);
		}
		if(me->query("lunjian/pot") < yuanbao)
			return notify_fail(HIM"��Ķһ���ȯ���㣬��μӲμ��۽���ѣ���"NOR"\n");
		me->add("lunjian/pot",-yuanbao);
		ob = new(file);
		log_ufile(me,"pay/lunjian", "�һ���"+ob->short()+"��\n");
		tell_object(me,"��ɹ��һ�����"+ob->short()+"��"NOR"\n");
		ob->move(me);
		return 1;
	}
	else
		return notify_fail(HIM"�����ʲô����"NOR"\n");

	return 1;
}

int valid_leave(object me, string dir)
{
	if(allusers[me->query("id")])
	{
		tell_object(me,"���뿪�˻�ɽ֮�ۣ������һ�ֱ������ڳ��Ļ��㽫ʧȥһ�ν������ᡣ\n");
	}
	return ::valid_leave(me, dir);
}
int ljsign(){
  int now = time();
  object me;
  me = this_player();
  if(me->query("ljsign"))
    return notify_fail("���Ѿ���ȡ���۽����뽱�ˣ�\n");

  if(localtime(now)[6]!=LUNJIAN_DAY)
   return notify_fail("����������۽������ӣ�\n");

  if(me->query("pre_start1"))
    return notify_fail("�����û�в�����\n");

    me->add("jifeng",500);
    me->set("ljsign",1);
    tell_object(me,"����ȡ���۽����뽱����ȯ500\n");

}
int lunjiangift()
{
	object me;
	string str;
	
	me = this_player();
	str = FAMILY_D->bouns_lunjian_leader(me);
	tell_object(me,str);
	return 1;
}

int jjsign()
{
	int now = time();
	object me = this_player();

	if(localtime(now)[6]!=LUNJIAN_DAY
	||localtime(now)[2]!=LUNJIAN_HOUR
	||localtime(now)[1]>LUNJIAN_PRE)
		return notify_fail(ZJOBLONG"����ʱ�䣺"+LUNJIAN_HOUR+":00-"+LUNJIAN_HOUR+":10��\n");

	if (me->query("combat_exp")<200000)
		return notify_fail("����Ϊ��ǳ�����ǰѹ������������ɡ�\n");

	if (allusers[me->query("id")])
		return notify_fail("���Ѿ��������ˣ�Ŀǰ����������"+sizeof(allusers)+"��\n");

	allusers[me->query("id")]=1;
	tell_object(me,"�����ɹ������ڴ��Ժ�"+LUNJIAN_HOUR+"��10���Զ����뾺�����С�\n");
	me->delete("ljsign");
	me->set("pre_start1",1);
	set_heart_beat(1);
	return 1;
}

int sort_total(string user1,string user2)
{
	return (int)allusers[user2]-(int)allusers[user1];
}

private void auto_check()
{
	object tmp1,tmp2,*inv,*rooms,ob;
	string name,msg;
	string *us,room;
	int i;

	rooms = children("/d/lunjian/jingji");
	if(!sizeof(rooms))
	{
		total = sort_array(keys(allusers),(: sort_total :));
		us = filter_array(total, (: find_player($1)&&present(find_player($1),$(this_object())) :));
		if(sizeof(us)<1 || turn >= LUNJIAN_TURN)
		{
			if(allusers[total[0]]<2)
			{
				msg = "��˵��ɽ�۽����������ӵ��ӣ�δ�ܾ������������𡿣�";
				message_competition(msg);
			}
			else
			{
				if(ob = find_player(total[0]))
					name = ob->query("name");
				else
					name = TOP_D->get_name(total[0]);
				msg = "��ɽ�۽�Բ��������" + name + "����100����㣬��á�����ͨ���ĳƺţ�";
				FAMILY_D->set_lunjian_leader("����ͨ",total[0]);
				message_competition(msg);
                tell_object(ob,"��ϲ�����۽���һ���õ���100����㣬5000��ʯ����\n");
                ob->add("yuanbao",5000);
                ob->add("tianji1",100);
				if(sizeof(total)>1)
				{
					if(ob = find_player(total[1]))
						name = ob->query("name");
					else
						name = TOP_D->get_name(total[1]);
					msg = name + "����40����㣬��á���а���ĳƺţ�";
					FAMILY_D->set_lunjian_leader("��а",total[1]);
					message_competition(msg);
				tell_object(ob,"��ϲ�����۽��ڶ����õ���40����㣬2000��ʯ����\n");
                ob->add("yuanbao",2000);
                ob->add("tianji1",40);
				}

				if(sizeof(total)>2)
				{
					if(ob = find_player(total[2]))
						name = ob->query("name");
					else
						name = TOP_D->get_name(total[2]);
					msg = name + "����20����㣬��á��������ĳƺţ�";
					FAMILY_D->set_lunjian_leader("����",total[2]);
					message_competition(msg);
					tell_object(ob,"��ϲ�����۽��������õ���20����㣬1000��ʯ����\n");
                     ob->add("yuanbao",1000);
                ob->add("tianji1",20);

				}

				if(sizeof(total)>3)
				{
					if(ob = find_player(total[3]))
						name = ob->query("name");
					else
						name = TOP_D->get_name(total[3]);
					msg = name + "����20����㣬��á��ϵۡ��ĳƺţ�";
					FAMILY_D->set_lunjian_leader("�ϵ�",total[3]);
					message_competition(msg);
					tell_object(ob,"��ϲ�����۽����ģ��õ���20����㣬1000��ʯ����\n");
                    ob->add("yuanbao",1000);
                ob->add("tianji1",20);

				}

				if(sizeof(total)>4)
				{
					if(ob = find_player(total[4]))
						name = ob->query("name");
					else
						name = TOP_D->get_name(total[4]);
					msg = name + "����20����㣬��á���ؤ���ĳƺţ�";
					FAMILY_D->set_lunjian_leader("��ؤ",total[4]);
					message_competition(msg);
					tell_object(ob,"��ϲ�����۽����壬�õ���20����㣬1000��ʯ����\n");
                    ob->add("yuanbao",1000);
                ob->add("tianji1",20);

				}

				set_heart_beat(0);
				delete("pre_start");
				delete("start");
			}
			allusers = ([]);
			turn = 0;
			return;
		}
		while(sizeof(us)>1)
		{
			tmp1 = find_player(us[0]);
			us -= ({ tmp1->query("id") });
			tmp2 = find_player(us[0]);
			us -= ({ tmp2->query("id") });
			init_player(tmp1);
			init_player(tmp2);
			room = new("/d/lunjian/jingji");
			tmp1->move(room);
			tmp2->move(room);
			tmp1->kill_ob(tmp2);
			tmp2->kill_ob(tmp1);
		}
		if(sizeof(us))
		{
			ob = find_player(us[0]);
			ob->add("lunjian/pot",1);
			allusers[us[0]] += 1;
			tell_object(ob,"���ڱ��־����������ֿգ��Զ���������ȴ���һ��ƥ�䡣\n");
			log_ufile(ob,"lunjian","�ֿս�������ȯ����1��\n");
		}
		turn++;
		return;
	}
	for (i = 0; i < sizeof(rooms); i++)
	{
		inv = filter_array(all_inventory(rooms[i]),(: playerp($1) :));
		if(!sizeof(inv))
			destruct(rooms[i]);
		else if(sizeof(inv)==1)
		{
			allusers[inv[0]->query("id")]++;
			inv[0]->add("lunjian/pot",1);
			log_ufile(inv[0],"lunjian","ʤ����������ȯ����1��\n");
			check_win(inv[0]);
		}
	}
}

private void init_player(object me)
{
	tell_object(me, HIY "�������˻�ɽ�۽��ı��䳡..."NOR"\n");
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
	me->set_override("die", (: call_other, __FILE__, "check_out" :));
	me->set_override("quit", (: call_other, __FILE__, "check_quit" :));
	me->set_temp("backup/killer", me->query_killer());
	me->set_temp("backup/want", me->query_want());
	me->set_temp("in_pkd", 1);

	me->set("backup/condition", me->query_condition());
	me->clear_condition();
}

private void message_competition(string msg)
{
	CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

private void restore_status(object me)
{
	mapping my;
	mapping cnd;
	string *ks;
	int i;

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
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];
}

void heart_beat()
{
	int i,now = time();
	object tmp1,tmp2,room,*inv;
	string msg;

	room = this_object();

	if(!query("pre_start")&&localtime(now)[1]==LUNJIAN_PRE)
	{
		set("pre_start",1);
		tell_room(this_object(),"1���Ӻ󽫽��뾺������������׼��������\n");
	}
	else if(!query("start")&&localtime(now)[1]==(LUNJIAN_PRE+1))
	{
		set("start",1);
		inv = filter_array(all_inventory(this_object()), (: playerp($1)&&$(allusers)[$1->query("id")] :));
		if(sizeof(inv)<LUNJIAN_USER_MIN)
		{
			msg = "��˵���λ�ɽ�۽���������̫�٣��δ�ܳɹ����У�";
			message_competition(msg);
			delete("pre_start");
			delete("start");
			set_heart_beat(0);
			return;
		}
		while(sizeof(inv)>1)
		{
			tmp1 = inv[random(sizeof(inv))];
			inv -= ({ tmp1 });
			tmp2 = inv[random(sizeof(inv))];
			inv -= ({ tmp2 });
			init_player(tmp1);
			init_player(tmp2);
			room = new("/d/lunjian/jingji");
			tmp1->move(room);
			tmp2->move(room);
			tmp1->kill_ob(tmp2);
			tmp2->kill_ob(tmp1);
		}
		if(sizeof(inv))
		{
			allusers[inv[0]->query("id")] += 1;
			tell_object(inv[0],"���ڱ��־����������ֿգ��Զ���������ȴ���һ��ƥ�䡣\n");
		}
	}
	else if(localtime(now)[1]>LUNJIAN_PRE)
	{
		auto_check();
	}
}

int check_quit(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);

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

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	tell_object(me, HIR "\n�������ǰһ��ģ��...�������ˣ�"NOR"\n");

	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);
	me->move(this_object());
	message("vision", "һ����Ӱٿ�Ĵ��˳������漴���ǡ�ž����һ�����ͼ�" + me->name() +"ˤ���˵��ϣ�һ��������������ӡ�\n", environment(me), ({ me }));
	tell_object(me, "�������У�����ñ������������������ص�ˤ���˵��ϡ�\n");
	me->delete("pre_start1");
	if (! living(me))
		me->revive();
	return 1;
}

int check_win(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	tell_object(me, HIR "\n���ڱ����۽��л�ʤ������"NOR"\n");

	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);
	me->move(this_object());
    me->delete("pre_start1");
	return 1;
}
