// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name(NOR YEL "����" NOR, ({"jin zhu", "jin", "zhu" }));
                set("long", "����ֻ�����ŵ����������ʹ��������Ҫȥ����ɽ�ʴ�������ˡ�\n");
                set("unit", "ֻ");
                set("value", 10000000);
                set("base_value", 10000000);
                set("base_unit", "ֻ");
                set("base_weight", 1000000);
                set("is jin zhu", 1);
        setup();
}

