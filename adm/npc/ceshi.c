//【蜀山剑派】dhxy-evil 2000.7.5
// modified by vikee
#include <ansi.h>
inherit NPC;
int do_walk();
void create()
{
        set_name("老者", ({ "laozhe","lao","zhe" }));
       // set("title", "好象很猛的");
		//set("title", HIY "剑客" NOR);
        set("age", 300);
        set("attitude", "peaceful");
        set("str", 100);
        set("per", 20);
		set("long", @LONG
这是一个年迈的老人，据说你爷爷的爷爷就已经见过他了。
LONG );
       
        set("max_qi", 100000);
        set("max_jing", 100000);
		
set("inquiry", ([
		"询问": "我一辈子都在追寻一个问题，你能回答我吗？我愿意给出高额的报酬。",
		"回答": "问题是“世间情为何物”，回答请（answer）接答案。（老魔提示，不要去百度哦）",
		
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
            return notify_fail("嗯？你的答案和我期望的不对\n");
		}
        message_vision(CYN"老人说：“嗯回答的不错，这个礼物就送你了！”\n", this_player());
		ob = new("/d/shushan/zhenyaota/obj/fbook");
        ob->move(who);
        command("haha"+ me->query("id"));
        command("great"+ me->query("id"));
       
       
       // destruct(me);删除自己
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
			message_vision("$N叹了叹气，走了。\n", this_object());
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
		message_vision("$N一弯腰，从地上捡起一样东西。\n",
			       this_object());
	else
	if (n > 1)
		message_vision("$N弯腰在地上摸摸索索找了半天，捡起一堆东西。\n",
			       this_object());
			
	random_move();
	return 1;
}


