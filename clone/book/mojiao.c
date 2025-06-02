// mojiao.c

#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(HIG "ħ��ҽ��" NOR, ({ "mojiao medical", "medical" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ƶ��鼮�������ù�׭��"
                            "д�š�ħ��ҽ���������֡�\n",

                );
                set("material", "paper");
                set("skill", ([
                        "name": "mojiao-medical",
                        "jing_cost": 60,
                        "difficulty": 40,
                        "max_skill": 160,
                        "min_skill": 30,
                ]));

                set("can_make", ([
                        "tianmo" : 280,           // ��ħʥѪ��
                ]));
        }
        setup();
}
