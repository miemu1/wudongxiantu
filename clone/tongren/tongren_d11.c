#include <ansi.h>

inherit ITEM;

int is_tongren() { return 1; }
void create()
{
        set_name(YEL "��Ѩͭ�ˡ���ά������ӪѨ" NOR, ({ "tongren d11", "tongren" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + YEL "����һ����Ѩͭ�ˣ����������һЩ����Ѩλͼ�����Լ���Ѩʹ�÷�����\n" NOR);
                set("value", 10000);
                set("material", "steal");
        }
        set("jingmai_name", "��ά��");
        set("xuewei_name", "��ӪѨ");
        set("chongxue_xiaoguo", "POT:500");
        set("neili_cost", "600");
        setup();
}

