
#include <ansi.h>

inherit ITEM;

void setup()
{

        set("no_clean_up", 1);
        set("no_roar", 1);
        set("no_flyto", 1);    // ���������MISS������Ѿ���horse.c������
        set("no_rideto", 1);   // ���������MISS������Ѿ���horse.c������
        set("no_obsend", 1);
        set("no_paimai", 1);
        set("skybook14", 1);

        ::setup();
        set_heart_beat(60);

}

void create()
{
        set_name(HIG "��ɽ֮��" NOR, ({ "huashan zhidian" }));
        set_weight(200000);
        set_max_encumbrance(20000000000);

        if (clonep())
        {
                set_default_object(__FILE__);
        }
        else
        {
                set("value", 1);
                set("long",
                "�����ǻ�ɽ֮�ߣ�ƽʱ�ƺ��������˵�����������������������ɽ���������\n"
                "���ߴ��ţ��ƺ���Ϊ��տ���ɽ����Ψһ�����ɡ�\n");
                set("unit", "��");
                set("material", "air");
                set("no_rideto", 1);
                set("no_flyto", 1); 
                set("exits", ([ "out" : "/d/city/wumiao" ]));
             
                set("no_get", "!@#$!@#%%^@!^\n");
        }
        setup();
}

void heart_beat()
{
        // 1Сʱ������ø���
        if (time() - query("create_time") > 1 * 3600)
                destruct(this_object());
}

int valid_leave(object me, string arg)
{
        return 1;
}
