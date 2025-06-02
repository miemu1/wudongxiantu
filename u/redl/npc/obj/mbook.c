// mbook.c
// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(HIY "�����ʼ�" NOR, ({ "liandan biji", "biji" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����д��С����������С׭��д�š������ʼǡ������֡�\n");
                set("material", "paper");
                set("dynamic_quest", 1);
                set("no_sell", "�������������뿪�㡣\n");
                set("no_put", "�����������ܷ����Ƕ���\n");
                set("no_store", "�����������ܷ����Ƕ���\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set("no_steal", "�������������뿪�Ƕ���\n");
                set("no_beg", "�������������뿪�Ƕ���\n");
                set("base_value", 0);
                set("skill", ([
                        "name": "liandan-shu",
                        "jing_cost": 80,
                        "difficulty": 40,
                        "max_skill": 150,
                        "min_skill": 30,
                ]));

                set("can_make", ([
                        "shujing"  : 50,        // �����絤
                        "dieda"    : 50,        // ����������
                        "jiedu"    : 100,       // ţ�ƽⶾ��
                        "yuzhen"   : 250,       // ����ɢ
                        "yuling"   : 250,       // ����ɢ
                        "yuqing"   : 300,       // ����ɢ
                ]));
        }
        setup();
}

