#include <ansi.h>

inherit ITEM;

int is_tongren() { return 1; }
void create()
{
        set_name(YEL "��Ѩͭ�ˡ���̫��������ԫѨ" NOR, ({ "tongren k15", "tongren" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + YEL "����һ����Ѩͭ�ˣ����������һЩ����Ѩλͼ�����Լ���Ѩʹ�÷�����\n" NOR);
                set("value", 10000);
                set("material", "steal");
        }
        set("jingmai_name", "��̫����");
        set("xuewei_name", "��ԫѨ");
        set("chongxue_xiaoguo", "JING:60:_DEX:1");
        set("neili_cost", "1200");
        setup();
}

