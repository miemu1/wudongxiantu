// /clone/board/riyue_b.c

inherit ITEM;

void create()
{
	set_name("������̽��ڼ��°�", ({ "board" }) );
	set("location", "/d/heimuya/chengdedian");
	set("board_id", "riyue_b");
	set("long", "����һ��ר��������̽�����ʹ�õ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

