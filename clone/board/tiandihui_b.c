inherit ITEM;

void create()
{
        set_name("��ػ�������԰�", ({ "board" }) );
        set("location", "/d/beijing/qingmu_dating");
        set("board_id", "tiandi_b");
        set("long", "����һ������ػ���ӽ��������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(ITEM);
}

