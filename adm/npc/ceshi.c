//����ɽ���ɡ�dhxy-evil 2000.7.5
// modified by vikee
#include <ansi.h>
inherit NPC;
int do_walk();
void create()
{
        set_name("����", ({ "laozhe","lao","zhe" }));
       // set("title", "������͵�");
		//set("title", HIY "����" NOR);
        set("age", 300);
        set("attitude", "peaceful");
        set("str", 100);
        set("per", 20);
		set("long", @LONG
����һ�����������ˣ���˵��үү��үү���Ѿ��������ˡ�
LONG );
       
        set("max_qi", 100000);
        set("max_jing", 100000);
		
set("inquiry", ([
		"ѯ��": "��һ���Ӷ���׷Ѱһ�����⣬���ܻش�������Ը������߶�ı��ꡣ",
		"�ش�": "�����ǡ�������Ϊ������ش��루answer���Ӵ𰸡�����ħ��ʾ����Ҫȥ�ٶ�Ŷ��",
		
	]));
      set("chat_msg", ({
		(: do_walk :),
	}));
        setup();
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        object who = this_player();
        object me = this_object();
        object ob;
		string daan;
		daan = who->query("love",1);
        if ( (arg != ""+daan+""))
		{
			set("wenxingshibai",1);
            return notify_fail("�ţ���Ĵ𰸺��������Ĳ���\n");
		}
        message_vision(CYN"����˵�����Żش�Ĳ����������������ˣ���\n", this_player());
		ob = new("/d/shushan/zhenyaota/obj/fbook");
        ob->move(who);
        command("haha"+ me->query("id"));
        command("great"+ me->query("id"));
       
       
       // destruct(me);ɾ���Լ�
        return 1;
}
int do_walk()
{
	string start_room;
	object room;
	object ob;
	mapping obmap;
	int n;

	if (! environment())
		return 0;

	if (time() - query("check_time") > 900)
	{
		if (! stringp(start_room = query("startroom")) ||
		    ! objectp(room = find_object(start_room)) ||
		    ! mapp(obmap = room->query_temp("objects")) ||
		    member_array(this_object(), values(obmap)) == -1)
		{
			message_vision("$N̾��̾�������ˡ�\n", this_object());
			destruct(this_object());
			return 0;
		}

		set("check_time", time());
	}

	n = 0;
	foreach (ob in all_inventory(environment()))
	{
		if (ob->is_character() ||
		    ob->is_head() ||
		    ob->query("no_get"))
			continue;
		destruct(ob);
		n++;
	}

	if (n == 1)
		message_vision("$Nһ�������ӵ��ϼ���һ��������\n",
			       this_object());
	else
	if (n > 1)
		message_vision("$N�����ڵ��������������˰��죬����һ�Ѷ�����\n",
			       this_object());
			
	random_move();
	return 1;
}


