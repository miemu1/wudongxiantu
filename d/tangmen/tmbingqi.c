//tmbingqi.c

#include "/d/tangmen/npc/job1.h";

void create()
{
        set("short", "������");
        set("long",
"�������ſ��ı����̣����İ���һ��չ��̨��̨������వ��������\n"
"��Щ������Щ�Ź֣�����һ��������ʿ���õġ�������ר��Ϊ���ŵ�����\n"
"���ģ������Ǹ���ͨ�İ������������ŵ�����˵��һλ���ŵ�������ͷ��\n"
"���Ӵ��������Ŀ��ˡ�\n"
);
        set("exits", ([
                "west" : __DIR__"ndajie",
        ]));
        set("objects", ([
                __DIR__"npc/dizi2": 1,
        ]));
        set("no_clean_up", 1);
        set("no_fight", 1);
        setup();
        
}

