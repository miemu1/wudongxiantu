#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(WHT "��������ƪ��" NOR, ({  "liandan book", "shu" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", WHT "�����ѱ���������������д�����Ȿ�ռ��"NOR"\n");
                set("material", "paper");
                set("value", 1000);
				set("no_drop", "�������������뿪�㡣\n");
				set("no_put",1);
				set("no_sell",1);
				set("no_save",1);
				set("no_give",1);
				set("nopaimai",1);
              //  set("no_sell", "�٣��޼�֮����Ҳ����");
                set("skill", ([
                        "name" : "liandan-shu",
                        "jing_cost" : 40,
                        "difficulty" : 50,
                        "max_skill" : 500,
                        "min_skill" : 0,
                ]));

                set("can_make", ([
                        "liuhe"    : 80,         // ���Ϸ���ɢ
                        "qingxin"  : 100,        // ���Ķ���ɢ
                        "zhending" : 150,        // ��Ԫ��ɢ
                        "dieda"    : 80,         // ����������
                        "huojin"   : 100,        // �����Ѫ��
                        "tongmai"  : 150,        // ����ͨ����
                        "jiedu"    : 100,        // ţ�ƽⶾ��
			"zaohua"  : 230,		 // �컯��
			"puti-zi"  : 250,		 // ������
			"tianxiang"	:280,		 // ������¶
                ]));
        }
        setup();
}