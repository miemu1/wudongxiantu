#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(WHT "��������������" NOR, ({  "qiqi book", "shu" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", WHT "�������߰ѱ���������������д�����Ȿ�ռ��"NOR"\n");
                set("material", "paper");
                set("value", 1000);
              //  set("no_sell", "�٣��޼�֮����Ҳ����");
                set("skill", ([
                        "name" : "liandan-shu",
                        "jing_cost" : 40,
                        "difficulty" : 50,
                        "max_skill" : 300,
                        "min_skill" : 50,
                ]));

                set("can_make", ([
			"puti-zi"  : 250,	 //������
		//	"wg"	:300
                ]));
        }
        setup();
}