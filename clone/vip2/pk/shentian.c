#include <ansi.h>

inherit ITEM;

int is_reform_ob() { return 1; }
void create()
{
        set_name(HIW "����֮��" NOR, ({"yong heng", "zhi", "lian"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "�ɼ����ϡ�\n"
                            "��˵����֮������ؼ����İ���������\n"
                              "��˵��ӵ��ǿ���������\n" NOR);
                set("unit", "��");
                set("yuanbao", 2000);
				set("value", 8000000);
                set("item_origin", 1);
                set("element", "water");
                set("material_attrib", "zhi lian");
                set("material_name", HIW "����֮��" NOR);
                set("can_make", "all");
                set("power_point", 1000);
        }
}
