// advance_unarmed.c

inherit ITEM;

void create()
{
        set_name("�����ݸ�Ŀ��", ({ "bencao gangmu", "book" }));
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"������д�������ݸ�Ŀ������һ��ҽѧ�İٿ�ȫ�顣\n");
                set("value", 2000);
				set("no_drop", "�������������뿪�㡣\n");
				set("no_put",1);
				set("no_sell",1);
				set("no_save",1);
				set("no_give",1);
				set("nopaimai",1);
                set("material", "paper");
                set("skill", ([
                        "name":         "medical",
                        "exp_required": 1000,
                        "jing_cost":    30,
                        "difficulty":   25,
                        "max_skill":    500,
                ]));
        }
}

