// /clone/board/gaibang_r.c

inherit ITEM;

void create()
{
	set_name("����������ⱨ��", ({ "report" }) );
	set("location", "/d/gaibang/undertre");
	set("board_id", "gaibang_r");
	set("long", "����һ����ؤ����ӽ�����Ϣ�����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}


