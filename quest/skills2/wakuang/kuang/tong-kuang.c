//tong-kuang.cͭ��ʯ
// ����lywin 2000/8/27

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"ͭ��ʯ"NOR,({"tong kuang", "kuang"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("no_get",1);
				set("no_give",1);
				set("no_steal",1);
				set("kuang",1);
				set("no_put",1);
				set("power_point",1);
                set("long", "����һ����ص�ͭ��ʯ��"ZJURL("cmds:zhuanhuan tong kuang")ZJSIZE(15)""HIY"����"NOR"��\n");
             }
        setup();
}
