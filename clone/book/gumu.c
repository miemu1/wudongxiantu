// wudang.c

#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(HIG "��Ů�ľ�" NOR, ({ "yunv xinjing", "xinjing" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ƶ��鼮��������С׭��"
                            "д�š���Ů�ľ��������֡�\n",

                );
                set("material", "paper");
                set("skill", ([
                        "name": "yunv-xinjing",
                        "jing_cost": 60,
                        "difficulty": 40,
                        "max_skill": 60,
                ]));

                set("can_make", ([
                        "jinmisan" : 80,        // ����ɢ
                ]));
        }
        setup();
}


