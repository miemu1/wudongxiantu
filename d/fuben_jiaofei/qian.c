inherit NPC;

string ask_test();

void create()
{
    set_name("Сǧ", ({"qian"}));
    set("long", "Сǧ�����޵е�Ŷ����Ҫ�����Сǧ���֡�\n");
    set("gender", "Ů��");
    set("age",25);
    set("combat_exp", 1);
    set("max_qi", 1000000000);
    set("qi", 100000000);
    set("max_jing", 1000000000);
    set("jing", 1000000000);
    
    set("inquiry", ([
            " ��������ǡ�" : (: ask_test :),
        ]));
    
    setup();
}

string ask_test()
{
	__DIR__"fb_main"->main(this_player());
	return "��ɲ���\n";
}
/*
void init()
{
	command("say �������������������������� \n");
}*/