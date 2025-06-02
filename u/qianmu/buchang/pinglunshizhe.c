inherit NPC;
inherit F_SAVE;

string ask_shilian();
string ask_danchou();

void create()
{
    set_name("���۽�������", ({"shizhe"}));
    set("long", query("name") + "��ô�ɰ���������ô���Ķ�" + query("name") + "���֡�\n");
    set("gender", "Ů��");
    set("age",17);
    set("combat_exp", 1);
    restore();
    set("create_time", time()/86400 * 86400);
    
    set("inquiry", ([
            " ��ʮ����" : (: ask_shilian :),
            " �����顿" : (: ask_danchou :),
        ]));

    setup();
}

string query_save_file() { return DATA_DIR + "npc/shizhe"; }

string ask_shilian()
{
	object gift, who = this_player();
	string str;
	mapping shilian = __DIR__"shilian.c"->query_map();

	if (query("lingqu/shilian/" + who->query("id")))
	{
		return "���Ѿ���ȡ��Ŷ��\n";
	}

	if (undefinedp(shilian[who->query("id")]))
	{
		return "�㲻����ȡŶ��\n";
	}

	if (!objectp(gift = new("/clone/baiyi/tencard")))
	{
		return "��������ϵ����Ա����\n";
	}

	set("lingqu/shilian/" + who->query("id"), 1);
	save();
	gift->set_amount(1);
	gift->move(who);

	log_file("pinglun/shilian", ctime(time()) + who->name() + "��ȡ��ʮ���鿨Ƭ��\n");
	return "������һ��ʮ���鿨Ƭ��\n";

	return "";
}

string ask_danchou()
{
	object gift, who = this_player();
	string str;
	mapping danchou = __DIR__"danchou.c"->query_map();

	if (query("lingqu/danchou/" + who->query("id")))
	{
		return "���Ѿ���ȡ��Ŷ��\n";
	}

	if (undefinedp(danchou[who->query("id")]))
	{
		return "�㲻����ȡŶ��\n";
	}

	if (!objectp(gift = new("/clone/baiyi/onecard")))
	{
		return "��������ϵ����Ա����\n";
	}

	set("lingqu/danchou/" + who->query("id"), 1);
	save();
	gift->set_amount(1);
	gift->move(who);

	log_file("pinglun/danchou", ctime(time()) + who->name() + "��ȡ�˵��鿨Ƭ��\n");
	return "������һ�ŵ��鿨Ƭ��\n";

	return "";
}

void die()
{
	object ob, me, who;
	
	me = this_object();
	who = me->query_last_damage_from();
	ob = new(base_name(me));
	ob->set("create_time", query("create_time"));
	ob->move(environment(me));
	tell_object(who, ZJOBLONG + query("name") + "���������ħ������ܵ�����ģ�����ɱ�����ģ�\n");
	log_file("kill_qian", ctime(time()) + "   " + who->name() + "\n");
	
	::die();
}

void init()
{
    add_action("disable", ({ "kill", "hit", "fuhuo", "touxi", "fight", "steal"}));
}

int disable(string arg)
{
    object who = this_player();
    
    if (arg != "qian")
        return 0;
    
    tell_object(who, query("name") + "һ�������㣬�㵹�ڵ��϶������á�\n");
    who->start_busy(180);

    return 1;
}

int accept_ansuan(object who)
{
    tell_object(who, "���밵��" + query("name") + "����\n" + query("name") + "���ߣ����밵���ң��Թ���ԭ�ط�վ�ɣ�\n");
    who->start_busy(300);
    return 0;
}

void fight_ob(object ob)
{
	::fight_ob(ob);
    tell_object(ob, query("name") + "һ�������㣬�㵹�ڵ��϶������á�\n");
    ob->start_busy(180);
    
}

int accept_fight(object who)
{
	command("say û��Ȥ��");
	return 0;
}

void receive_damage(string type, int n)
{
	return;
}

void receive_wound(string type, int n)
{
	return;
}