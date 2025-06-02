inherit NPC;

void create()
{
	set_name("�㾫", ({"yu jing"}));
	set("long", "����һֻ�㾫��\n");
	set("combat_exp", 100000);

	setup();
}

void die()
{
	object who;
	string id = query("player_id");
	object gift;
    
    if (!id || !(who = find_player(id)))
    {
        ::die();
    }
    
	if (random(10) == 3)
	{
		if (objectp(gift = new(__DIR__"obj/shuiyu")))
		{
			gift->move(who);
			tell_object(who, "������һ��ˮ��\n");
		}
		else
		{
			tell_object(who, "��ɱ�㾫���ˮ���������ϵ����Ա����\n");
		}
	}
	else
	{
		if (objectp(gift = new(__DIR__"obj/shuiyu_suipian")))
		{
			gift->move(who);
			tell_object(who, "������һ��ˮ����Ƭ��\n");
		}
		else
		{
			tell_object(who, "��ɱ�㾫���ˮ����Ƭ��������ϵ����Ա����\n");
		}
	}

	::die();
}