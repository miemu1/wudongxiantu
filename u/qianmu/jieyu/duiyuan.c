inherit NPC;

void create()
{
	set_name("�ٱ�", ({ "guan bing" }));
	set("long", "���ǳ�͢�Ĺٱ���\n");
	set("gander", "����");
	set("combat_exp", 100000);

	setup();
}

void die()
{
	object mem = this_object()->query("mem");

	mem->npc_die();
	::die();
}