// /clone/board/xuedao_b.c

inherit ITEM;

void create()
{
	set_name("Ѫ���ŵ������԰�",({ "board" }) );
        set("location", "/d/xuedao/shandong2");
	set("board_id", "xuedao_b");
        set("long","���ǹ�Ѫ���ŵ��Ӵ�����Ϣ�õ����԰�\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
