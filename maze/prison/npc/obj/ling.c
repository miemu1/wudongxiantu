#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(RED "�ع�ͨ����" NOR, ({ "tongxing ling", "ling" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����Ʒ��̫���ܹܽ���������ǵĳ������ơ�\n");
                set("value", 200);
                set("maze_item", 1);
        }
        setup();
}

