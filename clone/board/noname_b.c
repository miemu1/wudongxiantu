inherit ITEM;

void create()
{
	set_name("�������԰�", ({ "board" }) );
	set("location", "/d/wizard/noname_room");
	set("board_id", "noname_b");
	set("private_board", 1);
	set("long", "˵�ɣ�������ʦû��֪������˵�����ݡ�\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}



