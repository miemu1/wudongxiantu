// /clone/board/towiz_b.c

inherit ITEM;

void create()
{
	set_name("���������԰�", ({ "board" }) );
	set("location", "/d/wizard/guest_room");
	set("board_id", "towiz_b");
	set("long", "����һ������Һ���ʦ���������԰塣\n" );
	setup();
	set("capacity", 1000);
}

int do_post(string arg)
{
        object me;

        me = this_player();
        if (wiz_level(me) < 1 &&
            me->query("combat_exp", 1) < 10000 &&
            me->query("age") < 18)
                return notify_fail("�����ڻ�û���ʸ����������ԡ�\n");

        return ::do_post(arg);
}

int do_discard(string arg)
{
        if (wiz_level(this_player()) < 1)
                return notify_fail("�㲻��ɾ�����������κ����ԡ�\n");

        return ::do_discard(arg);
}
