// zhang.c 张天师

#include <ansi.h>

inherit KNOWER;

int ask_me();

void create()
{
	set_name("陆沉", ({ "zhang tianshi", "zhang" }));
	set("age", 57);
	set("gender", "男性");
	set("long", "这是一位仙风神骨，道貌岸然的法师。\n");
	set("attitude", "peaceful");
	set("str", 28);
	set("int", 35);
	set("con", 38);
	set("dex", 31);

	set("max_qi", 8000);
	set("max_jing", 8000);
	set("max_neili", 8000);

	set_skill("magic", 200);
	set_skill("taoism", 350);

	set("chat_chance_combat", 3);
	set("chat_msg_combat", ({
		"陆沉摇摇铃铛，道：天灵灵，地零零，太上老君还不显灵？\n",
		"陆沉呼呼的吹了几口气。\n",
	}));

	set("inquiry", ([
		"开光" : (: ask_me :),
		"没钱" : "没钱就去赚，跟我说什么。",
		"浸入" : "你要是不行我可以帮你看看(show)浸入需要用什么物品。",
	]));

	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

void init()
{
	add_action("do_show", "show");
	add_action("do_summon", "summon");
}

int ask_me()
{
	command("heihei");
	command("say 我只给神兵利器开光，寻常刀剑莫提！要"
		"你本人的，我可不能帮你做坏事！");
	tell_object(this_player(), GRN "张天师在你耳边悄悄说："
		    "你把要开光的拿出来给我看看(show)！"NOR"\n");
	return 1;
}

int do_summon(string arg)
{
	if (! wizardp(this_player()))
	{
		command("say 你在我面前瞎抓个什么劲？别地试去！");
		return 1;
	}

	return 0;
}

int do_show(string arg)
{
	object money;
	object ob;
	object me;
	int n;

	if (! arg)
		return notify_fail("你要亮出什么东西？\n");

	me = this_player();
	if (! objectp(ob = present(arg, me)))
		return notify_fail("你身上没有这种东西。\n");
		
	/*if(ob->level_now()>1)
		return notify_fail("你的装备有等级了无法绑定！\n");
		*/
	if (ob->query("equipped"))
		return notify_fail("你先解除" + ob->name() + "的装备再说！\n");

	message_vision("$n拿出一" + ob->query("unit") + ob->name() +
		       "对$N说：“拜托拜托...”\n",
		       this_object(), me);

	if (ob->query("money_id"))
	{
		command("say 你亮出钱干什么？想献给观里？那就给我好了。");
		return 1;
	}

	if (! me->query_temp("陆沉", 1))
	{
		command("heihei");
		command("say 这...怎么也的有点意思意思吧？你"
			"说十两黄金怎么样？当然多些我也不反对。");
		return 1;
	}

	if (stringp(ob->query("magic/imbue_ob")))
	{
		command("say 嗯...我看看，应该用" +
			ob->query("magic/imbue_name") +
			CYN "浸入它才能进一步激发它的潜力。" NOR);
		me->delete_temp("陆沉");
		return 1;
	}

	if (mapp(ob->query("magic/imbue_ok")))
	{
		command("say 哦！我看它现在已经不需要在浸入了，"
			"要发挥潜力得用别的法子了。\n");
		return 1;
	}

	if (! ob->is_item_make())
	{
		command("heng");
		command("say 这...这...我看还是算了吧！");
		return 1;
	}

	if (ob->item_owner() != me->query("id"))
	{
		command("kick " + me->query("id"));
		command("say 你以为本山人的仙术是蒙事的啊，这分明不是你的！");
		return 1;
	}

	if (me->query("can_summon/" + ob->query("id")))
	{
		if (ob->weapon_level() > 1)
		{
			command("poor " + me->query("id"));
			command("say 它现在还不到浸入的时候..."
				"你要先圣化它才行啊！");
		} 
		else
		{
			command("kok " + me->query("id"));
			command("say 你和它已经有缘了！我说你的"
				"记性怎么这么差？");
		}
		return 1;
	}

	message("vision", sort_string(HIM + name() + "从口袋中摸出一张黄色的符纸，抽出背后的桃木剑，将那符纸点燃了，扫过" + ob->name() + HIM "，然后用桃木剑穿了，手舞足蹈，口中念念有词：“太上老君急急如律赐令！”
说罢一抖掌中剑，喝道：“疾”！"NOR"\n", 64), environment());
	message_vision("焰光划出一道光华，$N发了发呆，也不知道算是怎么回事。\n",me);
	command("say 行了，行了！你可以走了。");
	me->delete_temp("陆沉");
	me->set("can_summon/" + ob->query("id"), base_name(ob));
	log_file("static/item", sprintf("%s %s sancitfy %s(%s)\n",
			log_time(), log_id(me),
			filter_color(ob->name(1)), ob->query("id")));
	return 1;
}

int accept_object(object who, object ob)
{
	if (! ob->query("money_id"))
	{
		command("say 这玩艺我可没啥兴趣！");
		return 0;
	}

	if (ob->value() < 50000)
	{
		command("say 算是给观里的香火么？那我就收下了！");
		return 1;
	}

	if (ob->value() < 100000)
	{
		command("say 唉！看你也算有点心意，我就替你开一次光吧！");
		who->set_temp("陆沉", 1);
		destruct(ob);
		return 1;
	}

	command("say 好...好...这么照顾本观，我能帮你点什么？");
	who->set_temp("陆沉", 1);
	destruct(ob);
	return 1;
}

void fight_ob(object ob)
{
	::fight_ob(ob);
	message_vision("$N冷笑一声，道：“这年头，什么人都有。”说完伸手一指$n。\n",
		       this_object(), ob);
	ob->unconcious();
}

int accept_fight(object who)
{
	command("say 没兴趣。");
	return 0;
}

int accept_ansuan(object who)
{
	return notify_fail("你刚想暗算，可是眼前一花，看不太清楚。\n");
}

void receive_damage(string type, int n)
{
	return;
}

void receive_wound(string type, int n)
{
	return;
}
