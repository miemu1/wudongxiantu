#include <ansi.h>

inherit ITEM;

int is_tongren() { return 1; }
void create()
{
        set_name(YEL "冲穴铜人·任外脉·涌泉穴" NOR, ({ "tongren h15", "tongren" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", NOR + YEL "这是一个冲穴铜人，上面绘制了一些经络穴位图案，以及冲穴使用方法。\n" NOR);
                set("value", 10000);
                set("material", "steal");
        }
        set("jingmai_name", "任外脉");
        set("xuewei_name", "涌泉穴");
        set("chongxue_xiaoguo", "ATK:20:_INT:1");
        set("neili_cost", "9000");
        setup();
}

