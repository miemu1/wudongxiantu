// /clone/board/kedian_b.c

inherit ITEM;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/city/kedian");
	set("board_id", "kedian_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 1000);
	replace_program(ITEM);
}

int do_discard(string arg)
{
        if (wiz_level(this_player()) < 1)
                return notify_fail("�㲻��ɾ�����������κ����ԡ�\n");

        return ::do_discard(arg);
}
