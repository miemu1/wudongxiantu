#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name("ʮ��ľż", ({ "18 muou", "18", "muou" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__); 
        else {
                set("unit", "��");
                set("long", NOR + YEL "
����һ��Сľ�У����е����޻�������������ľż�������ϲ
�ò�������ʹ�����ᣬ�������ŭ����ȺͿ��ף�����һ��ͬ��
ľż�������Ų�ͩ�ͣ��������ߣ�ȴ��Ѩ��λ�á����ľż��
�����ɣ���Ŀ��������������һ�ŷǳ��������ѧ��\n" NOR);
                set("value", 200);
                set("material", "paper");
                set("skill", ([
                        "name":         "luohan-fumogong",
                        "exp_required": 1000,
                        "jing_cost":    20,
                        "difficulty":   20,
                        "max_skill":    20,
                ]));
        }
}