#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(WHT "「七七炼丹术」" NOR, ({  "qiqi book", "shu" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", WHT "丹仙七七把毕生的炼丹术技术写在了这本日记里。"NOR"\n");
                set("material", "paper");
                set("value", 1000);
              //  set("no_sell", "嘿，无价之宝你也丢？");
                set("skill", ([
                        "name" : "liandan-shu",
                        "jing_cost" : 40,
                        "difficulty" : 50,
                        "max_skill" : 300,
                        "min_skill" : 50,
                ]));

                set("can_make", ([
			"puti-zi"  : 250,	 //菩提子
		//	"wg"	:300
                ]));
        }
        setup();
}